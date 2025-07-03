/**
 * @brief 树
 * @attention：
 * 树的基本概念
 * 1. 树：树是由 n(n>=0) 个结点组成的有限集合。树是一个非线性数据结构。
 * 2. 特点：
 * * * 树的每个结点有零个或多个子结点。
 * * * 树的每个结点有且只有一个父结点。
 * * * 树的第一个结点称为根结点。
 * * * 树的结点数为 n 的树称为 n 叉树。
 * * * * 树的深度：树中结点的最大层数称为树的深度。
 * * * * * 树的高度：树中结点的最大层数称为树的高度。
 * * * * * 树的度：树中结点的最大子结点数称为树的度。
 * * * * * 叶子结点：没有子结点的结点称为叶子结点。
 *
 */
/**
 * @brief 树的遍历
 * @attention：
 * 树的遍历是指按照一定的顺序访问树中的每一个结点。
 * 树的遍历有三种基本方式：
 * 1. 先序遍历：先访问根结点，再访问左子树，最后访问右子树。
 * 2. 中序遍历：先访问左子树，再访问根结点，最后访问右子树。
 * 3. 后序遍历：先访问左子树，再访问右子树，最后访问根结点。
 * 4. 层序遍历：从上到下，从左到右访问树中的每一个结点。
 */
/***********************静态实现***********************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/********************************* 数据结构定义 *********************************/
/**
 * @brief 线索二叉树结点定义
 */
typedef struct ThreadNode
{
    int data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag; // 左、右线索标志  // 0表示孩子，1表示线索
} ThreadNode, *ThreadTree;

/********************************* 函数声明 *********************************/
bool InsertRoot(ThreadTree *tree, int data);
bool InsertChild(ThreadTree parent, char direction, int data);
void CreateInThread(ThreadTree T);
void CreatePreThread(ThreadTree T);
void CreatePostThread(ThreadTree T);
void Inorder(ThreadNode *T);
void RevInorder(ThreadNode *T);
void PreInorder(ThreadNode *T);
void PostRevInorder(ThreadNode *T);
void InitialTree(ThreadTree &root);

/********************************* 函数实现 *********************************/
// 插入根节点
bool InsertRoot(ThreadTree *tree, int data)
{
    if (*tree != NULL)
    {
        printf("根节点已存在。\n");
        return false;
    }
    ThreadTree newNode = (ThreadTree)malloc(sizeof(ThreadNode));
    if (!newNode)
    {
        printf("内存分配失败。\n");
        return false;
    }
    newNode->data = data;
    newNode->lchild = newNode->rchild = NULL;
    newNode->ltag = newNode->rtag = 0;
    *tree = newNode;
    return true;
}

// 插入新节点到指定父节点的左或右
bool InsertChild(ThreadTree parent, char direction, int data)
{
    if (!parent)
    {
        printf("父节点不存在。\n");
        return false;
    }
    if ((direction == 'L' || direction == 'l') && parent->lchild != NULL)
    {
        printf("左孩子已存在。\n");
        return false;
    }
    if ((direction == 'R' || direction == 'r') && parent->rchild != NULL)
    {
        printf("右孩子已存在。\n");
        return false;
    }
    ThreadTree newNode = (ThreadTree)malloc(sizeof(ThreadNode));
    if (!newNode)
    {
        printf("内存分配失败。\n");
        return false;
    }
    newNode->data = data;
    newNode->lchild = newNode->rchild = NULL;
    newNode->ltag = newNode->rtag = 0;
    if (direction == 'L' || direction == 'l')
    {
        parent->lchild = newNode;
        parent->ltag = 0;
    }
    else if (direction == 'R' || direction == 'r')
    {
        parent->rchild = newNode;
        parent->rtag = 0;
    }
    else
    {
        printf("方向参数错误。\n");
        return false;
    }
    return true;
}

/********************************* 线索化函数 *********************************/
// 全局变量pre, 指向当前访问的结点的前驱
ThreadNode *pre = NULL; // 全局前驱指针

void visit(ThreadNode *q)
{
    if (q->lchild == NULL)
    { // 左子树为空，建立前驱线索
        q->lchild = pre;
        q->ltag = 1;
    }

    if (pre != NULL && pre->rchild == NULL)
    {
        pre->rchild = q; // 建立前驱结点的后继线索
        pre->rtag = 1;
    }

    pre = q;
    printf("%d ", q->data);
}

/////////////////////////////////////////////////

// 中序遍历线索化
void InThread(ThreadTree T)
{
    if (T != NULL)
    {
        InThread(T->lchild); // 中序遍历左子树
        visit(T);            // 访问根节点
        InThread(T->rchild); // 中序遍历右子树
    }
}
// 中序线索化二叉树T
void CreateInThread(ThreadTree T)
{
    pre = NULL; // pre初始为NULL
    if (T != NULL)
    {                // 非空二叉树才能进行线索化
        InThread(T); // 中序线索化二叉树
        if (pre->rchild == NULL)
            pre->rtag = 1; // 处理遍历的最后一个结点
    }
}

// 先序遍历线索化
void PreThread(ThreadTree T)
{
    if (T != NULL)
    {
        visit(T);
        if (T->ltag == 0) // lchild不是前驱线索
            PreThread(T->lchild);
        if (T->rtag == 0) // rchild不是前驱线索
            PreThread(T->rchild);
    }
}
// 先序线索化二叉树T
void CreatePreThread(ThreadTree T)
{
    pre = NULL; // pre初始为NULL
    if (T != NULL)
    {                 // 非空二叉树才能进行线索化
        PreThread(T); // 先序线索化二叉树
        if (pre->rchild == NULL)
            pre->rtag = 1; // 处理遍历的最后一个结点
    }
}

// 后序遍历线索化
void PostThread(ThreadTree T)
{
    if (T != NULL)
    {
        PostThread(T->lchild);
        PostThread(T->rchild);
        visit(T); // 访问根节点
    }
}
// 后序线索化二叉树T
void CreatePostThread(ThreadTree T)
{
    pre = NULL; // pre初始为NULL
    if (T != NULL)
    {                  // 非空二叉树才能进行线索化
        PostThread(T); // 后序线索化二叉树
        if (pre->rchild == NULL)
            pre->rtag = 1; // 处理遍历的最后一个结点
    }
}

//////////////////////////////////////////////////////////
// 线索二叉树中找前驱、后继
/*
若 p->rtag == 1, 则 next = p->rchild;
若 p->ltag == 1, 则 last = p->lchild;
*/

// 中序二叉树 后继 节点
// 中序二叉树：若 p->rtag == 0, 则 p 必有右孩子, 则 next = p的右子树中最左下结点;
// 1. 找到以P为根的子树中，第一个被中序遍历的结点
ThreadNode *Firstnode(ThreadNode *p)
{
    // 循环找到最左下的结点（不一定是叶结点）
    while (p->ltag == 0)
        p = p->lchild;
    return p;
}
// 2. 在中序线索二叉树中找到结点p的后继结点
ThreadNode *Nextnode(ThreadNode *p)
{
    // 右子树最左下结点
    if (p->rtag == 0)
        return Firstnode(p->rchild);
    else
        return p->rchild; // rtag==1，直接返回后继线索
}
// 3. 对中序线索二叉树进行中序遍历
void Inorder(ThreadNode *T)
{ // T为根节点指针
    for (ThreadNode *p = Firstnode(T); p != NULL; p = Nextnode(p))
        printf("%d ", p->data);;
}

// 中序二叉树 前驱 节点
// 中序二叉树：若 p->ltag == 0, 则 p 必有左孩子, 则 last = p的左子树中最右下结点;
// 1. 找到以P为根的子树中，第一个被中序遍历的结点
ThreadNode *Lastnode(ThreadNode *p)
{
    // 循环找到最左下的结点（不一定是叶结点）
    while (p->rtag == 0)
        p = p->rchild;
    return p;
}
// 2. 在中序线索二叉树中找到结点p的后继结点
ThreadNode *Prenode(ThreadNode *p)
{
    // 右子树最左下结点
    if (p->ltag == 0)
        return Lastnode(p->lchild);
    else
        return p->lchild; // rtag==1，直接返回后继线索
}
// 3. 对中序线索二叉树进行中序遍历
void RevInorder(ThreadNode *T)
{ // T为根节点指针
    for (ThreadNode *p = Lastnode(T); p != NULL; p = Prenode(p))
        printf("%d ", p->data);;
}

// 先序二叉树  后继 节点
// 2. 在先序线索二叉树中找到结点p的后继结点
ThreadNode *PreNextnode(ThreadNode *p)
{
    // 有左孩子，即为左节点，无左孩子，即为右节点
    if (p->rtag == 0)
        return p->ltag==0 ? p->lchild : p->rchild ;
    else
        return p->rchild; // rtag==1，直接返回后继线索
}
// 3. 对先序线索二叉树进行中序遍历
void PreInorder(ThreadNode *T)
{ // T为根节点指针
    for (ThreadNode *p = T; p != NULL; p = PreNextnode(p))
        printf("%d ", p->data);;
}

// 先序二叉树无法找 前驱 节点

// 后序二叉树  前驱 节点
// 2. 在后序线索二叉树中找到结点p的前驱结点
ThreadNode *PostPrenode(ThreadNode *p)
{
    // 有右孩子，即为右节点，无右孩子，即为左节点
    if (p->ltag == 0)
        return p->rtag==0 ? p->rchild : p->lchild ;
    else
        return p->lchild; // ltag==1，直接返回后继线索
}
// 3. 对后序线索二叉树进行中序遍历
void PostRevInorder(ThreadNode *T)
{ // T为根节点指针
    for (ThreadNode *p = T; p != NULL; p = PostPrenode(p))
        printf("%d ", p->data);;
}

// 后序二叉树无法找 后继 节点

// 初始化树
void InitialTree(ThreadTree &root)
{
    root = NULL;
    InsertRoot(&root, 10);
    InsertChild(root, 'L', 5);
    InsertChild(root, 'R', 20);
    InsertChild(root->lchild, 'L', 3);
    InsertChild(root->lchild, 'R', 7);
    InsertChild(root->lchild->rchild, 'R', 11);
    InsertChild(root->lchild->lchild, 'L', 4);
    InsertChild(root->lchild->rchild, 'L', 12);
}


int main()
{
    ThreadTree root = NULL;

    // 构建测试二叉树
    InitialTree(root);
    /*
            10
           /  \
          5    20
         / \
        3   7
       /   /  \
      4   12   11
    */

    printf("\n创建中序二叉树：\n");
    CreateInThread(root); // 创建中序线索二叉树  // 4 3 5 12 7 11 10 20
    printf("\n中序二叉树找后继节点：\n");
    Inorder(root);
    printf("\n中序二叉树找前驱节点：\n");
    RevInorder(root);
    printf("\n\n");

    // 构建测试二叉树
    InitialTree(root);
    printf("\n创建先序二叉树：\n");
    CreatePreThread(root); // 创建先序线索二叉树  // 10 5 3 4 7 12 11 20
    printf("\n先序二叉树找后继节点：\n");
    PreInorder(root);
    printf("\n\n");

    InitialTree(root);
    printf("\n创建后序二叉树：\n");
    CreatePostThread(root); // 创建后序线索二叉树  // 4 3 12 11 7 5 20 10
    printf("\n后序二叉树找前驱节点：\n");
    PostRevInorder(root);
    printf("\n\n");

    return 0;
}

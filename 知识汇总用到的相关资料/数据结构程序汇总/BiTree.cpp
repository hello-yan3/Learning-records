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
 * @brief 二叉树节点结构体
 */
typedef struct BiTNode
{
    int data;               // 数据域
    struct BiTNode *lchild; // 左孩子指针
    struct BiTNode *rchild; // 右孩子指针
} BiTNode, *BiTree;         // 二叉树的类型定义

/**
 * @brief 栈结构体（用于非递归遍历）
 */
typedef struct
{
    BiTree *data; /**< 存储节点指针的数组 */
    int top;      /**< 栈顶指针 */
    int capacity; /**< 栈容量 */
} Stack;

/**
 * @brief 队列结构体（用于层序遍历）
 */
typedef struct
{
    BiTree *data; /**< 存储节点指针的数组 */
    int front;    /**< 队头指针 */
    int rear;     /**< 队尾指针 */
    int capacity; /**< 队列容量 */
    int size;     /**< 当前元素个数 */
} Queue;

/********************************* 函数声明 *********************************/
bool InsertRoot(BiTree *tree, int data);
bool InsertChild(BiTree parent, char direction, int data);
void PreOrderTraverse(BiTree T);
void InOrderTraverse(BiTree T);
void PostOrderTraverse(BiTree T);
void PreOrderNonRecursive(BiTree T);
void InOrderNonRecursive(BiTree T);
void LevelOrder(BiTree T);
void StackInit(Stack *s, int capacity);
int StackIsEmpty(const Stack *s);
void StackPush(Stack *s, BiTree node);
BiTree StackPop(Stack *s);
BiTree StackTop(const Stack *s);
void QueueInit(Queue *q, int capacity);
int QueueIsEmpty(const Queue *q);
void QueueEnqueue(Queue *q, BiTree node);
BiTree QueueDequeue(Queue *q);

/********************************* 函数实现 *********************************/
/********************************* 栈与队列的初始化与基本操作 *********************************/
/**
 * @brief 初始化栈
 * @param s 指向栈的指针
 * @param capacity 栈的容量
 */
void StackInit(Stack *s, int capacity)
{
    s->data = (BiTree *)malloc(capacity * sizeof(BiTree));
    s->top = -1;
    s->capacity = capacity;
}

/**
 * @brief 判断栈是否为空
 * @param s 栈指针
 * @return 如果栈为空返回1，否则返回0
 */
int StackIsEmpty(const Stack *s)
{
    return s->top == -1;
}

/**
 * @brief 入栈
 * @param s 栈指针
 * @param node 要入栈的节点
 */
void StackPush(Stack *s, BiTree node)
{
    if (s->top + 1 == s->capacity)
    {
        printf("栈溢出\n");
        return;
    }
    s->data[++s->top] = node;
}

/**
 * @brief 出栈
 * @param s 栈指针
 * @return 出栈的节点
 */
BiTree StackPop(Stack *s)
{
    if (StackIsEmpty(s))
    {
        return NULL;
    }
    return s->data[s->top--];
}

/**
 * @brief 获取栈顶元素
 * @param s 栈指针
 * @return 栈顶节点
 */
BiTree StackTop(const Stack *s)
{
    if (StackIsEmpty(s))
    {
        return NULL;
    }
    return s->data[s->top];
}

//////////////////////////

/**
 * @brief 初始化队列
 * @param q 队列指针
 * @param capacity 队列容量
 */
void QueueInit(Queue *q, int capacity)
{
    q->data = (BiTree *)malloc(capacity * sizeof(BiTree));
    q->front = 0;
    q->rear = 0;
    q->capacity = capacity;
    q->size = 0;
}

/**
 * @brief 判断队列是否为空
 * @param q 队列指针
 * @return 如果队列为空返回1，否则返回0
 */
int QueueIsEmpty(const Queue *q)
{
    return q->size == 0;
}

/**
 * @brief 入队
 * @param q 队列指针
 * @param node 要入队的节点
 */
void QueueEnqueue(Queue *q, BiTree node)
{
    if (q->size == q->capacity)
    {
        printf("队列已满\n");
        return;
    }
    q->data[q->rear] = node;
    q->rear = (q->rear + 1) % q->capacity;
    q->size++;
}

/**
 * @brief 出队
 * @param q 队列指针
 * @return 出队的节点
 */
BiTree QueueDequeue(Queue *q)
{
    if (QueueIsEmpty(q))
    {
        return NULL;
    }
    BiTree node = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return node;
}

////////////////////////////////////////

/**
 * 插入根节点
 * @param tree 指向二叉树根节点的指针的指针
 * @param data 要插入的数据
 * @return 成功返回 true，失败返回 false
 */
bool InsertRoot(BiTree *tree, int data)
{
    if (*tree != NULL)
    {
        printf("根节点已存在。\n");
        return false;
    }

    BiTree newNode = (BiTree)malloc(sizeof(BiTNode));
    if (!newNode)
    {
        printf("内存分配失败。\n");
        return false;
    }

    newNode->data = data;
    newNode->lchild = newNode->rchild = NULL;
    *tree = newNode;

    return true;
}

/**
 * 插入新节点到指定父节点的左或右
 * @param parent 父节点
 * @param direction 插入方向 ('L'/'R')
 * @param data 要插入的数据
 * @return 成功返回 true，失败返回 false
 */
bool InsertChild(BiTree parent, char direction, int data)
{
    if (!parent)
    {
        printf("父节点不存在。\n");
        return false;
    }

    // 检查是否已有子节点
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

    BiTree newNode = (BiTree)malloc(sizeof(BiTNode));
    if (!newNode)
    {
        printf("内存分配失败。\n");
        return false;
    }

    newNode->data = data;
    newNode->lchild = newNode->rchild = NULL;

    if (direction == 'L' || direction == 'l')
    {
        parent->lchild = newNode;
    }
    else if (direction == 'R' || direction == 'r')
    {
        parent->rchild = newNode;
    }
    else
    {
        printf("方向参数错误。\n");
        return false;
    }

    return true;
}

/**
 * 先序遍历（递归）
 * 遍历顺序：根节点 -> 左子树 -> 右子树
 * @param T 二叉树根节点
 */
void PreOrderTraverse(BiTree T)
{
    if (T == NULL)
        return;
    printf("%d ", T->data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}

/**
 * 中序遍历（递归）
 * 遍历顺序：左子树 -> 根节点 -> 右子树
 * @param T 二叉树根节点
 */
void InOrderTraverse(BiTree T)
{
    if (T == NULL)
        return;
    InOrderTraverse(T->lchild); // 遍历左子树
    printf("%d ", T->data);     // 访问根节点
    InOrderTraverse(T->rchild); // 遍历右子树
}

/**
 * 后序遍历（递归）
 * 遍历顺序：左子树 -> 右子树 -> 根节点
 * @param T 二叉树根节点
 */
void PostOrderTraverse(BiTree T)
{
    if (T == NULL)
        return;
    PostOrderTraverse(T->lchild); // 遍历左子树
    PostOrderTraverse(T->rchild); // 遍历右子树
    printf("%d ", T->data);       // 访问根节点
}

/**
 * @brief 先序遍历（非递归）
 * @param T 二叉树根节点
 */
void PreOrderNonRecursive(BiTree T)
{
    Stack s;
    StackInit(&s, 100); // 初始化栈

    while (T || !StackIsEmpty(&s)) // 如果 T!=NULL 或者 栈不为空
    {
        while (T) // 如果 T!=NULL，遍历左子树
        {
            printf("%d ", T->data); // 访问节点
            StackPush(&s, T);       // 将节点压入栈
            T = T->lchild;          // 移动到左子节点
        }
        if (!StackIsEmpty(&s)) // 如果栈不为空
        {
            T = StackPop(&s); // 弹出栈顶元素
            T = T->rchild;    // 移动到右子节点
        }
    }

    free(s.data);
}

/**
 * @brief 中序遍历（非递归）
 * @param T 二叉树根节点
 */
void InOrderNonRecursive(BiTree T)
{
    Stack s;
    StackInit(&s, 100);

    while (T || !StackIsEmpty(&s))  // 如果 T!=NULL 或者 栈不为空
    {
        while (T)        // 如果 T!=NULL，遍历左子树
        {
            StackPush(&s, T);        // 将节点压入栈
            T = T->lchild;           // 移动到左子节点
        }
        if (!StackIsEmpty(&s))       // 如果栈不为空
        {
            T = StackPop(&s);        // 弹出栈顶元素
            printf("%d ", T->data);  // 访问节点
            T = T->rchild;           // 移动到左子节点
        }
    }

    free(s.data);
}

/**
 * @brief 层序遍历（使用队列）
 * @param T 二叉树根节点
 */
void LevelOrder(BiTree T)
{
    Queue q;
    QueueInit(&q, 100);

    if (T != NULL)
    {
        QueueEnqueue(&q, T);
    }

    while (!QueueIsEmpty(&q))
    {
        BiTree node = QueueDequeue(&q);
        printf("%d ", node->data);

        if (node->lchild != NULL)
        {
            QueueEnqueue(&q, node->lchild);
        }
        if (node->rchild != NULL)
        {
            QueueEnqueue(&q, node->rchild);
        }
    }

    free(q.data);
}

int main()
{
    BiTree root = NULL;

    // 构建测试二叉树
    InsertRoot(&root, 10);
    InsertChild(root, 'L', 5);
    InsertChild(root, 'R', 20);
    InsertChild(root->lchild, 'L', 3);
    InsertChild(root->lchild, 'R', 7);
    InsertChild(root->lchild->rchild, 'R', 11);
    InsertChild(root->lchild->lchild, 'L', 4);
    InsertChild(root->lchild->rchild, 'L', 12);

    /*
            10
           /  \
          5    20
         / \
        3   7
       /   /  \
      4   12   11
    */

    // 先序遍历测试
    printf("\n先序遍历结果：\n");
    PreOrderTraverse(root); // 10 5 3 4 7 12 11 20
    printf("\n");

    // 中序遍历测试
    printf("\n中序遍历结果：\n");
    InOrderTraverse(root); // 4 3 5 12 7 11 10 20
    printf("\n");

    // 后序遍历测试
    printf("\n后序遍历结果：\n");
    PostOrderTraverse(root); // 4 3 12 11 7 5 20 10
    printf("\n");

    printf("\n非递归先序遍历:\n");
    PreOrderNonRecursive(root); // 10 5 3 4 7 12 11 20
    printf("\n");

    printf("\n非递归中序遍历:\n");
    InOrderNonRecursive(root); // 4 3 5 12 7 11 10 20
    printf("\n");

    printf("\n层序遍历:\n");
    LevelOrder(root); // 10 5 20 3 7 4 12 11
    printf("\n");

    // 清理内存（可选）
    // 可以添加 DestroyBiTree 函数，此处略

    return 0;
}

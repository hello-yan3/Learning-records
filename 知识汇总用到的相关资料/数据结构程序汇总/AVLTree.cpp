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
#include <string.h>

/**
 * @file avl_tree.c
 * @brief 平衡二叉树（AVL Tree）的C语言实现
 */

/**
 * @brief 平衡二叉树节点结构体
 */
typedef struct AVLNode
{
    int key;                         /**< 节点存储的键值 */
    int balance;                     /**< 平衡因子：左子树高度 - 右子树高度 */
    struct AVLNode *lchild, *rchild; /**< 左右子节点 */
} AVLNode, *AVLTree;

/**
 * @brief 在AVL树中查找指定关键字的节点
 *
 * @param T AVL树的根节点
 * @param key 要查找的关键字
 * @return AVLNode* 查找到的节点指针，若未找到返回NULL
 */
AVLNode *AVL_Search(AVLTree T, int key)
{
    while (T != NULL && key != T->key)
    {
        if (key < T->key)
        {
            // 关键字小于当前节点，往左子树找
            T = T->lchild;
        }
        else
        {
            // 关键字大于当前节点，往右子树找
            T = T->rchild;
        }
    }
    return T;
}

/**
 * @brief LL旋转（右单旋转）
 *
 * 当某节点A的左孩子B的左子树插入导致失衡时，执行LL旋转
 * 旋转后，B成为新的根节点，A成为B的右孩子
 *
 * @param root 不平衡的节点A
 * @return AVLTree 新的根节点B
 */
AVLTree ll_rotate(AVLTree root)
{
    AVLTree new_root = root->lchild;
    // 将new_root的右子树转移到root的左子树
    root->lchild = new_root->rchild;
    // 将root作为new_root的右孩子
    new_root->rchild = root;

    // 更新平衡因子：LL旋转后，A和B的平衡因子均为0
    root->balance = 0;
    new_root->balance = 0;

    return new_root;
}

/**
 * @brief RR旋转（左单旋转）
 *
 * 当某节点A的右孩子B的右子树插入导致失衡时，执行RR旋转
 * 旋转后，B成为新的根节点，A成为B的左孩子
 *
 * @param root 不平衡的节点A
 * @return AVLTree 新的根节点B
 */
AVLTree rr_rotate(AVLTree root)
{
    AVLTree new_root = root->rchild;
    // 将new_root的左子树转移到root的右子树
    root->rchild = new_root->lchild;
    // 将root作为new_root的左孩子
    new_root->lchild = root;

    // 更新平衡因子：RR旋转后，A和B的平衡因子均为0
    root->balance = 0;
    new_root->balance = 0;

    return new_root;
}

/**
 * @brief LR旋转（先左后右双旋转）
 *
 * 当某节点A的左孩子B的右子树插入导致失衡时，执行LR旋转
 * 首先对B进行RR旋转，然后对A进行LL旋转
 *
 * @param root 不平衡的节点A
 * @return AVLTree 新的根节点C（原B的右孩子）
 */
AVLTree lr_rotate(AVLTree root)
{
    // 先对左孩子B进行RR旋转
    root->lchild = rr_rotate(root->lchild);
    // 再对根节点A进行LL旋转
    return ll_rotate(root);
}

/**
 * @brief RL旋转（先右后左双旋转）
 *
 * 当某节点A的右孩子B的左子树插入导致失衡时，执行RL旋转
 * 首先对B进行LL旋转，然后对A进行RR旋转
 *
 * @param root 不平衡的节点A
 * @return AVLTree 新的根节点C（原B的左孩子）
 */
AVLTree rl_rotate(AVLTree root)
{
    // 先对右孩子B进行LL旋转
    root->rchild = ll_rotate(root->rchild);
    // 再对根节点A进行RR旋转
    return rr_rotate(root);
}

/**
 * @brief 插入一个新的节点到AVL树中
 *
 * @param root AVL树的根指针的指针
 * @param key 要插入的关键字
 * @return int 成功插入返回1，已存在返回0
 */
int AVL_Insert(AVLTree *root, int key)
{
    // 基本情况：找到插入位置
    if (*root == NULL)
    {
        // 创建新节点并初始化
        *root = (AVLNode *)malloc(sizeof(AVLNode));
        (*root)->key = key;
        (*root)->balance = 0; // 新节点的平衡因子为0（叶子节点）
        (*root)->lchild = (*root)->rchild = NULL;
        return 1; // 插入成功
    }

    // 若键值已存在，返回失败
    if (key == (*root)->key)
    {
        return 0;
    }

    int taller; // 记录子树高度是否增加

    if (key < (*root)->key)
    {
        // 向左子树插入
        taller = AVL_Insert(&(*root)->lchild, key);
        if (!taller)
            return 0; // 插入失败或高度未增加
        // 更新平衡因子：左子树增高，balance增加1
        (*root)->balance += 1;
    }
    else
    {
        // 向右子树插入
        taller = AVL_Insert(&(*root)->rchild, key);
        if (!taller)
            return 0; // 插入失败或高度未增加
        // 更新平衡因子：右子树增高，balance减少1
        (*root)->balance -= 1;
    }

    // 检查当前节点是否失衡
    if ((*root)->balance == 2)
    {
        // 左边失衡（balance=2）
        if ((*root)->lchild->balance == 1)
        {
            // LL情况：左孩子的左子树导致失衡
            *root = ll_rotate(*root);
        }
        else if ((*root)->lchild->balance == -1)
        {
            // LR情况：左孩子的右子树导致失衡
            *root = lr_rotate(*root);
        }
    }
    else if ((*root)->balance == -2)
    {
        // 右边失衡（balance=-2）
        if ((*root)->rchild->balance == -1)
        {
            // RR情况：右孩子的右子树导致失衡
            *root = rr_rotate(*root);
        }
        else if ((*root)->rchild->balance == 1)
        {
            // RL情况：右孩子的左子树导致失衡
            *root = rl_rotate(*root);
        }
    }

    // 判断当前子树高度是否增加
    // 如果当前节点平衡因子变为0，说明其父节点高度不会变化
    return ((*root)->balance == 0) ? 0 : 1;
}

/**
 * @brief 删除AVL树中的指定节点
 *
 * @param root AVL树的根指针的指针
 * @param key 要删除的关键字
 * @return int 删除成功返回1，未找到返回0
 */
int AVL_Delete(AVLTree *root, int key)
{
    if (*root == NULL)
    {
        return 0; // 未找到节点
    }

    int shorter; // 记录子树高度是否降低

    if (key < (*root)->key)
    {
        // 从左子树删除
        shorter = AVL_Delete(&(*root)->lchild, key);
        if (!shorter)
            return 0; // 删除失败或高度未降低
        // 更新平衡因子：左子树降低，balance减少1
        (*root)->balance -= 1;
    }
    else if (key > (*root)->key)
    {
        // 从右子树删除
        shorter = AVL_Delete(&(*root)->rchild, key);
        if (!shorter)
            return 0; // 删除失败或高度未降低
        // 更新平衡因子：右子树降低，balance增加1
        (*root)->balance += 1;
    }
    else
    {
        // 找到要删除的节点
        if ((*root)->lchild && (*root)->rchild)
        {
            // 情况3：有两个子节点，寻找中序后继节点
            AVLTree successor = (*root)->rchild;
            while (successor->lchild)
            {
                successor = successor->lchild; // 找到右子树的最左节点
            }
            // 替换值
            (*root)->key = successor->key;
            // 递归删除后继节点
            shorter = AVL_Delete(&(*root)->rchild, successor->key);
            if (!shorter)
                return 0;
            // 更新右子树降低的平衡因子
            (*root)->balance += 1;
        }
        else
        {
            // 情况1和2：无子节点或仅有一个子节点
            AVLTree to_delete = *root;
            if ((*root)->lchild == NULL)
            {
                *root = (*root)->rchild; // 仅有右子树
            }
            else if ((*root)->rchild == NULL)
            {
                *root = (*root)->lchild; // 仅有左子树
            }
            free(to_delete); // 释放内存
            return 1;        // 树的高度降低
        }
    }

    // 检查平衡因子并调整
    if ((*root)->balance == 2 || (*root)->balance == -2)
    {
        // 重新平衡
        if ((*root)->balance == 2)
        {
            // 左侧不平衡
            if ((*root)->lchild->balance >= 0)
            {
                *root = ll_rotate(*root); // LL
            }
            else
            {
                *root = lr_rotate(*root); // LR
            }
        }
        else
        {
            // 右侧不平衡
            if ((*root)->rchild->balance <= 0)
            {
                *root = rr_rotate(*root); // RR
            }
            else
            {
                *root = rl_rotate(*root); // RL
            }
        }
    }

    // 判断是否继续向上传递高度变化
    // 如果当前节点平衡因子为0，说明父节点高度会降低
    return ((*root)->balance == 0) ? 1 : 0;
}

/**
 * @brief 主函数：测试AVL树的插入和删除功能
 */
int main()
{
    AVLTree root = NULL;
    int keys[] = {10, 20, 30, 45, 50, 25, 35, 40, 37, 28, 32, 39}; // 测试数据
    int n = sizeof(keys) / sizeof(keys[0]);

    // 插入测试
    for (int i = 0; i < n; i++)
    {
        AVL_Insert(&root, keys[i]);
        printf("Inserted %d\n", keys[i]);
    }

    // 查找测试
    int search_key = 30;
    AVLNode *node = AVL_Search(root, search_key);
    if (node)
    {
        printf("Found key %d\n", search_key);
    }
    else
    {
        printf("Key %d not found\n", search_key);
    }

    // 删除测试
    int delete_key = 28;
    if (AVL_Delete(&root, delete_key))
    {
        printf("Deleted key %d\n", delete_key);
    }
    else
    {
        printf("Failed to delete key %d\n", delete_key);
    }

    // 删除测试
    delete_key = 35;
    if (AVL_Delete(&root, delete_key))
    {
        printf("Deleted key %d\n", delete_key);
    }
    else
    {
        printf("Failed to delete key %d\n", delete_key);
    }

    return 0;
}

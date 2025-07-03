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
 * @file rb_tree.c
 * @brief 红黑树（Red-Black Tree）的C语言实现
 */

/**
 * @brief 红黑树节点颜色枚举
 */
typedef enum
{
    RED,   /**< 0 - 红色节点 */
    BLACK, /**< 1 - 黑色节点 */
} Color;

/**
 * @brief 红黑树节点结构体
 */
struct RBNode
{
    int key;               /**< 节点存储的键值 */
    struct RBNode *parent; /**< 父节点指针 */
    struct RBNode *lChild; /**< 左孩子指针 */
    struct RBNode *rChild; /**< 右孩子指针 */
    Color color;           /**< 节点颜色（RED/BALCK） */
};
typedef struct RBNode *RBTree;

/**
 * @brief 在红黑树中查找指定关键字的节点
 *
 * @param root 红黑树的根节点
 * @param key 要查找的关键字
 * @return RBNode* 查找到的节点指针，若未找到返回NULL
 */
RBNode *RB_Search(RBTree root, int key)
{
    while (root != NULL && key != root->key)
    {
        if (key < root->key)
        {
            // 关键字小于当前节点，往左子树找
            root = root->lChild;
        }
        else
        {
            // 关键字大于当前节点，往右子树找
            root = root->rChild;
        }
    }
    return root;
}

/**
 * @brief 红黑树的左单旋转
 *
 * 当某个节点x的右孩子y为红色且需要左旋时调用
 * 旋转后，y成为新的父节点，x成为y的左孩子
 *
 * @param root 红黑树的根节点
 * @param x 需要左旋的节点
 * @return RBTree 新的根节点
 */
RBTree left_rotate(RBTree root, RBNode *x)
{
    RBNode *y = x->rChild; // 获取x的右孩子y
    x->rChild = y->lChild; // 将y的左子树挂到x的右子树上

    // 如果y的左子树非空，设置其父节点为x
    if (y->lChild != NULL)
    {
        y->lChild->parent = x;
    }

    y->parent = x->parent; // 设置y的父节点为x的父节点

    // 如果x是根节点，更新根为y
    if (x->parent == NULL)
    {
        root = y;
    }
    // 如果x是左孩子，设置父节点的左孩子为y
    else if (x == x->parent->lChild)
    {
        x->parent->lChild = y;
    }
    // 如果x是右孩子，设置父节点的右孩子为y
    else
    {
        x->parent->rChild = y;
    }

    y->lChild = x; // 将x设置为y的左孩子
    x->parent = y; // 设置x的父节点为y

    return root;
}

/**
 * @brief 红黑树的右单旋转
 *
 * 当某个节点x的左孩子y为红色且需要右旋时调用
 * 旋转后，y成为新的父节点，x成为y的右孩子
 *
 * @param root 红黑树的根节点
 * @param x 需要右旋的节点
 * @return RBTree 新的根节点
 */
RBTree right_rotate(RBTree root, RBNode *x)
{
    RBNode *y = x->lChild; // 获取x的左孩子y
    x->lChild = y->rChild; // 将y的右子树挂到x的左子树上

    // 如果y的右子树非空，设置其父节点为x
    if (y->rChild != NULL)
    {
        y->rChild->parent = x;
    }

    y->parent = x->parent; // 设置y的父节点为x的父节点

    // 如果x是根节点，更新根为y
    if (x->parent == NULL)
    {
        root = y;
    }
    // 如果x是左孩子，设置父节点的左孩子为y
    else if (x == x->parent->lChild)
    {
        x->parent->lChild = y;
    }
    // 如果x是右孩子，设置父节点的右孩子为y
    else
    {
        x->parent->rChild = y;
    }

    y->rChild = x; // 将x设置为y的右孩子
    x->parent = y; // 设置x的父节点为y

    return root;
}

/**
 * @brief 插入新节点后的红黑树调整函数
 *
 * @param root 红黑树的根节点
 * @param z 新插入的节点
 * @return RBTree 调整后的红黑树根节点
 */
RBTree rb_insert_fixup(RBTree root, RBNode *z)
{
    // 当前节点z的父节点是红色时才需要调整
    while (z->parent != NULL && z->parent->color == RED)
    {
        RBNode *grandparent = z->parent->parent; // 获取祖父节点

        // 父节点是祖父的左孩子
        if (z->parent == grandparent->lChild)
        {
            RBNode *uncle = grandparent->rChild; // 获取叔叔节点

            // 情况1：叔叔是红色
            if (uncle != NULL && uncle->color == RED)
            {
                z->parent->color = BLACK; // 父节点变黑
                uncle->color = BLACK;     // 叔叔节点变黑
                grandparent->color = RED; // 祖父节点变红
                z = grandparent;          // 将祖父作为新节点继续向上调整
            }
            // 情况2和3：叔叔是黑色
            else
            {
                // 情况2：z是父节点的右孩子（LR型）
                if (z == z->parent->rChild)
                {
                    z = z->parent;               // 以父节点作为新z
                    root = left_rotate(root, z); // 对z进行左单旋转
                }

                // 情况3：z是父节点的左孩子（LL型）
                z->parent->color = BLACK;               // 父节点变黑
                grandparent->color = RED;               // 祖父节点变红
                root = right_rotate(root, grandparent); // 对祖父进行右单旋转
            }
        }
        // 父节点是祖父的右孩子
        else
        {
            RBNode *uncle = grandparent->lChild; // 获取叔叔节点

            // 情况1：叔叔是红色
            if (uncle != NULL && uncle->color == RED)
            {
                z->parent->color = BLACK; // 父节点变黑
                uncle->color = BLACK;     // 叔叔节点变黑
                grandparent->color = RED; // 祖父节点变红
                z = grandparent;          // 将祖父作为新节点继续向上调整
            }
            // 情况2和3：叔叔是黑色
            else
            {
                // 情况2：z是父节点的左孩子（RL型）
                if (z == z->parent->lChild)
                {
                    z = z->parent;                // 以父节点作为新z
                    root = right_rotate(root, z); // 对z进行右单旋转
                }

                // 情况3：z是父节点的右孩子（RR型）
                z->parent->color = BLACK;              // 父节点变黑
                grandparent->color = RED;              // 祖父节点变红
                root = left_rotate(root, grandparent); // 对祖父进行左单旋转
            }
        }
    }

    // 确保根节点始终是黑色
    root->color = BLACK;
    return root;
}

/**
 * @brief 向红黑树中插入一个新节点
 *
 * @param root 红黑树的根节点指针的指针
 * @param key 要插入的关键字
 * @return int 成功插入返回1，已存在返回0
 */
int RB_Insert(RBTree *root, int key)
{
    // 创建新节点并初始化
    RBNode *z = (RBNode *)malloc(sizeof(RBNode));
    if (!z)
    {
        return 0; // 内存分配失败
    }

    z->key = key;
    z->color = RED; // 新节点默认是红色
    z->lChild = z->rChild = z->parent = NULL;

    // 如果树为空，新节点成为根节点
    if (*root == NULL)
    {
        z->color = BLACK; // 根节点必须是黑色
        *root = z;
        return 1;
    }

    // 查找插入位置
    RBNode *y = NULL;      // y保存待插入位置的父节点
    RBNode *x = *root;     // x用于遍历

    while (x != NULL)
    {
        y = x; // 保存父节点
        if (key < x->key)
        {
            x = x->lChild;
        }
        else if (key > x->key)
        {
            x = x->rChild;
        }
        else
        {
            // 键已存在，插入失败
            free(z);
            return 0;
        }
    }

    // 设置父节点并插入到合适位置
    z->parent = y;
    if (key < y->key)
    {
        y->lChild = z;
    }
    else
    {
        y->rChild = z;
    }

    // 调整红黑树性质
    *root = rb_insert_fixup(*root, z);
    return 1;
}

/**
 * @brief 检查红黑树的每个红色节点是否有两个黑色子节点
 *
 * @param node 当前检查的节点
 * @return int 检查通过返回1，否则返回0
 */
int check_red_nodes(RBNode *node)
{
    if (node == NULL)
    {
        return 1; // 空节点视为黑色，不影响条件
    }

    // 检查当前节点是否为红色
    if (node->color == RED)
    {
        // 红色节点不能有红色子节点
        if ((node->lChild && node->lChild->color == RED) ||
            (node->rChild && node->rChild->color == RED))
        {
            return 0; // 存在连续红色节点，违反规则
        }
    }

    // 递归检查左右子树
    return check_red_nodes(node->lChild) && check_red_nodes(node->rChild);
}

/**
 * @brief 检查红黑树的黑高一致性
 *
 * @param node 当前检查的节点
 * @param black_height 存储当前路径的黑高
 * @return int 检查通过返回1，否则返回0
 */
int check_black_height(RBNode *node, int *black_height)
{
    if (node == NULL)
    {
        *black_height = 0; // 空节点黑高为0
        return 1;
    }

    int left_bh, right_bh;

    // 递归检查左右子树
    if (!check_black_height(node->lChild, &left_bh) ||
        !check_black_height(node->rChild, &right_bh))
    {
        return 0; // 子树检查失败
    }

    // 检查左右子树黑高是否一致
    if (left_bh != right_bh)
    {
        return 0; // 黑高不一致，违反规则
    }

    // 计算当前节点的黑高
    *black_height = left_bh + (node->color == BLACK ? 1 : 0);
    return 1;
}

/**
 * @brief 检查红黑树的所有基本性质
 *
 * @param root 红黑树的根节点
 * @return int 是否是红黑树（1是，0否）
 */
int is_rb_tree(RBTree root)
{
    if (root == NULL)
    {
        return 1; // 空树是有效的红黑树
    }

    // 检查根节点是否为黑色
    if (root->color != BLACK)
    {
        printf("根节点不是黑色\n");
        return 0;
    }

    // 检查是否存在连续红色节点
    if (!check_red_nodes(root))
    {
        printf("存在连续红色节点\n");
        return 0;
    }

    // 检查所有路径的黑高是否一致
    int black_height;
    if (!check_black_height(root, &black_height))
    {
        printf("黑高不一致\n");
        return 0;
    }

    return 1; // 所有检查通过，是红黑树
}

/**
 * @brief 主函数：测试红黑树的插入和性质验证
 */
int main()
{
    RBTree root = NULL;
    int keys[] = {10, 20, 30, 45, 50, 25, 35, 40, 37, 28, 32, 39}; // 测试数据
    int n = sizeof(keys) / sizeof(keys[0]);

    // 插入测试
    for (int i = 0; i < n; i++)
    {
        RB_Insert(&root, keys[i]);
        printf("插入 %d 后，", keys[i]);

        if (is_rb_tree(root))
        {
            printf("树是有效的红黑树\n");
        }
        else
        {
            printf("树不是有效的红黑树\n");
        }
    }

    // 查找测试
    int search_key = 30;
    RBNode *node = RB_Search(root, search_key);
    if (node)
    {
        printf("找到键值 %d\n", search_key);
    }
    else
    {
        printf("未找到键值 %d\n", search_key);
    }

    return 0;
}
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

#define MAX_TREE_SIZE 100 // 树中最多结点数

/**
 * @file tree.c
 * @brief 实现树结构的三种存储表示方法及其转换和遍历
 */

// ==================== 数据结构定义 ====================

/**
 * @brief 双亲表示法节点结构体
 */
typedef struct
{
    char data;  ///< 节点数据
    int parent; ///< 父节点索引
} PTNode;

/**
 * @brief 双亲表示法树结构体
 */
typedef struct
{
    PTNode nodes[MAX_TREE_SIZE]; ///< 节点数组
    int n;                       ///< 当前节点数
} PTree;

////////////////////////////////////
/**
 * @brief 孩子表示法链表节点结构体
 */
struct CTNode
{
    int child;           ///< 孩子节点在数组中的索引
    struct CTNode *next; ///< 下一个孩子节点指针
};

/**
 * @brief 孩子表示法节点结构体
 */
typedef struct
{
    char data;                 ///< 节点数据
    struct CTNode *firstChild; ///< 第一个孩子节点指针
} CTBox;

/**
 * @brief 孩子表示法树结构体
 */
typedef struct
{
    CTBox nodes[MAX_TREE_SIZE]; ///< 节点数组
    int n;                      ///< 当前节点数
    int r;                      ///< 根节点位置索引
} CTree;

////////////////////////////////////
/**
 * @brief 孩子兄弟表示法节点结构体（二叉链表）
 */
typedef struct ChildSiblingNode
{
    char data;                             ///< 节点数据
    struct ChildSiblingNode *first_child;  ///< 第一个孩子节点
    struct ChildSiblingNode *next_sibling; ///< 下一个兄弟节点
} ChildSiblingNode;

////////////////////////////////////
/**
 * @brief 队列结构（用于层次遍历）
 */
typedef struct QueueNode
{
    void *data;             ///< 队列元素
    struct QueueNode *next; ///< 下一个节点
} QueueNode;

typedef struct
{
    QueueNode *front; ///< 队列头
    QueueNode *rear;  ///< 队列尾
} Queue;

// ==================== 函数声明 ====================

// ==================== 函数实现 ====================

// ------------------- 双亲表示法 -------------------
/**
 * @brief 初始化双亲树
 * @param tree 指向双亲树的指针
 */
void init_parent_tree(PTree *tree)
{
    tree->n = 0;
}

/**
 * @brief 向双亲树中添加节点
 * @param tree 指向双亲树的指针
 * @param data 节点数据
 * @param parent_index 父节点索引
 * @return 成功返回1，超过最大容量返回0
 */
int add_parent_node(PTree *tree, char data, int parent_index)
{
    if (tree->n >= MAX_TREE_SIZE)
    {
        return 0; // 超过最大容量
    }
    tree->nodes[tree->n].data = data;
    tree->nodes[tree->n].parent = parent_index;
    tree->n++;
    return 1;
}

// ------------------- 孩子表示法 -------------------
/**
 * @brief 初始化孩子树
 * @param tree 指向孩子树的指针
 */
void init_child_tree(CTree *tree)
{
    tree->n = 0;
    tree->r = -1;
}

/**
 * @brief 向孩子树中添加节点
 * @param tree 指向孩子树的指针
 * @param data 节点数据
 * @param parent_index 父节点索引
 * @return 成功返回1，超过最大容量或父节点无效返回0
 */
int add_child_node(CTree *tree, char data, int parent_index)
{
    if (tree->n >= MAX_TREE_SIZE)
    {
        return 0; // 超过最大容量
    }

    // 添加新节点
    tree->nodes[tree->n].data = data;
    tree->nodes[tree->n].firstChild = NULL;

    // 如果是根节点
    if (parent_index == -1)
    {
        tree->r = tree->n;
    }
    // 如果有父节点
    else if (parent_index >= 0 && parent_index < tree->n)
    {
        // 创建新的孩子节点
        struct CTNode *new_node = (struct CTNode *)malloc(sizeof(struct CTNode));
        new_node->child = tree->n;
        new_node->next = NULL;

        // 找到父节点链表的末尾
        struct CTNode *current = tree->nodes[parent_index].firstChild;
        if (current == NULL)
        {
            // 父节点没有孩子
            tree->nodes[parent_index].firstChild = new_node;
        }
        else
        {
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = new_node;
        }
    }
    else
    {
        return 0; // 无效的父节点索引
    }

    tree->n++;
    return 1;
}

// ------------------- 孩子兄弟表示法 -------------------
/**
 * @brief 创建孩子兄弟表示法节点
 * @param data 节点数据
 * @return 新节点指针
 */
ChildSiblingNode *create_child_sibling_node(char data)
{
    ChildSiblingNode *node = (ChildSiblingNode *)malloc(sizeof(ChildSiblingNode));
    node->data = data;
    node->first_child = NULL;
    node->next_sibling = NULL;
    return node;
}

/**
 * @brief 释放孩子兄弟表示法树的全部内存
 * @param root 树的根节点
 */
void free_child_sibling_tree(ChildSiblingNode *root)
{
    if (!root)
        return;
    // 递归释放子节点和兄弟节点
    free_child_sibling_tree(root->first_child);
    free_child_sibling_tree(root->next_sibling);
    free(root);
}

// ------------------- 队列操作 -------------------
/**
 * @brief 将元素加入队列
 * @param q 指向队列的指针
 * @param data 待加入的数据
 */
void enqueue(Queue *q, void *data)
{
    QueueNode *new_node = (QueueNode *)malloc(sizeof(QueueNode));
    new_node->data = data;
    new_node->next = NULL;

    if (!q->rear)
    {
        q->front = q->rear = new_node;
    }
    else
    {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

/**
 * @brief 从队列取出元素
 * @param q 指向队列的指针
 * @return 队列首部元素
 */
void *dequeue(Queue *q)
{
    if (!q->front)
        return NULL;

    QueueNode *temp = q->front;
    void *data = temp->data;

    q->front = q->front->next;
    if (!q->front)
        q->rear = NULL;

    free(temp);
    return data;
}

/**
 * @brief 判断队列是否为空
 * @param q 指向队列的指针
 * @return 队列为空返回1，否则返回0
 */
int is_empty(Queue *q)
{
    return q->front == NULL;
}

// ------------------- 遍历函数 -------------------
/**
 * @brief 先根遍历孩子兄弟表示法树
 * @param root 树的根节点
 * @param result 遍历结果存储数组
 * @param index 遍历结果当前索引指针
 */
void pre_order_child_sibling(ChildSiblingNode *root, char *result, int *index)
{
    if (!root)
        return;

    result[(*index)++] = root->data;
    pre_order_child_sibling(root->first_child, result, index);
    pre_order_child_sibling(root->next_sibling, result, index);
}

/**
 * @brief 后根遍历孩子兄弟表示法树
 * @param root 树的根节点
 * @param result 遍历结果存储数组
 * @param index 遍历结果当前索引指针
 */
void post_order_child_sibling(ChildSiblingNode *root, char *result, int *index)
{
    if (!root)
        return;

    post_order_child_sibling(root->first_child, result, index);
    result[(*index)++] = root->data;
    post_order_child_sibling(root->next_sibling, result, index);
}

/**
 * @brief 层次遍历孩子兄弟表示法树
 * @param root 树的根节点
 * @param result 遍历结果存储数组
 * @param index 遍历结果当前索引指针
 */
void level_order_child_sibling(ChildSiblingNode *root, char *result, int *index)
{
    if (!root)
        return;

    Queue queue = {NULL, NULL};
    enqueue(&queue, root);

    // 层次遍历主循环
    while (!is_empty(&queue))
    {
        ChildSiblingNode *node = (ChildSiblingNode *)dequeue(&queue);
        result[(*index)++] = node->data;

        // 将当前节点的所有子节点加入队列
        ChildSiblingNode *child = node->first_child;
        while (child)
        {
            enqueue(&queue, child);
            child = child->next_sibling;
        }
    }
}

/**
 * @brief 初始化创建一棵树
 * 树结构：
 *         A
 *      /  |   \
 *     B   C    D
 *    / \  |    / | \
 *   E   F G   H  I  J
 *  /
 * K
 */
// ------------------- 孩子兄弟表示法节点结构体测试函数 -------------------
/**
 * @brief 测试函数：创建树、转换结构、执行遍历
 */
void test_CStree()
{
    // 创建孩子兄弟树
    ChildSiblingNode *root = create_child_sibling_node('A');
    root->first_child = create_child_sibling_node('B');
    root->first_child->next_sibling = create_child_sibling_node('C');
    root->first_child->next_sibling->next_sibling = create_child_sibling_node('D');
    root->first_child->first_child = create_child_sibling_node('E');
    root->first_child->first_child->next_sibling = create_child_sibling_node('F');
    root->first_child->next_sibling->first_child = create_child_sibling_node('G');
    root->first_child->next_sibling->next_sibling->first_child = create_child_sibling_node('H');
    root->first_child->next_sibling->next_sibling->first_child->next_sibling = create_child_sibling_node('I');
    root->first_child->next_sibling->next_sibling->first_child->next_sibling->next_sibling = create_child_sibling_node('J');
    root->first_child->first_child->first_child = create_child_sibling_node('K');

    /*
    // 构造一棵树：
    //         A
    //      /  |  \
    //     B   C    D
    //    / \  |  / | \
    //   E   F G H  I  J
    //  /
    // K
    */

    // 先根遍历
    char pre_result[20] = {0};
    int index = 0;
    pre_order_child_sibling(root, pre_result, &index);          // ABEKFCGDHIJ
    printf("Pre-order (Child-Sibling): %s\n", pre_result);

    // 后根遍历
    index = 0;
    char post_result[20] = {0};
    post_order_child_sibling(root, post_result, &index);
    printf("Post-order (Child-Sibling): %s\n", post_result);    // KEFBGCHIJDA

    // 层次遍历
    index = 0;
    char level_result[20] = {0};
    level_order_child_sibling(root, level_result, &index);
    printf("Level-order (Child-Sibling): %s\n", level_result);  // ABCDEFGHIJK

    // 释放内存
    free_child_sibling_tree(root);

    return;
}

/**
 * @brief 测试函数：双亲表示法树
 */
PTree createSamplePTree()
{
    /*
    树的节点数: 11
    节点列表:
    索引 | 数据 | 父节点
    0   |   A  |   -1
    1   |   B  |    0
    2   |   C  |    0
    3   |   D  |    0
    4   |   E  |    1
    5   |   F  |    1
    6   |   G  |    2
    7   |   H  |    3
    8   |   I  |    3
    9   |   J  |    3
    10  |   K  |    4
    */

    PTree tree;
    tree.n = 0; // 目前0个节点

    // 初始化根节点A
    tree.nodes[tree.n].data = 'A';
    tree.nodes[tree.n].parent = -1;
    tree.n++; // n=1

    // 第一层子节点
    tree.nodes[tree.n].data = 'B';
    tree.nodes[tree.n].parent = 0; // 父节点为A
    tree.n++;                      // n=2

    tree.nodes[tree.n].data = 'C';
    tree.nodes[tree.n].parent = 0; // 父节点为A
    tree.n++;                      // n=3

    tree.nodes[tree.n].data = 'D';
    tree.nodes[tree.n].parent = 0; // 父节点为A
    tree.n++;                      // n=4

    // 第二层子节点
    tree.nodes[tree.n].data = 'E';
    tree.nodes[tree.n].parent = 1; // 父节点为B、
    tree.n++;                      // n=5

    tree.nodes[tree.n].data = 'F';
    tree.nodes[tree.n].parent = 1; // 父节点为B
    tree.n++;                      // n=6

    tree.nodes[tree.n].data = 'G';
    tree.nodes[tree.n].parent = 2; // 父节点为C
    tree.n++;                      // n=7

    tree.nodes[tree.n].data = 'H';
    tree.nodes[tree.n].parent = 3; // 父节点为D
    tree.n++;                      // n=8

    tree.nodes[tree.n].data = 'I';
    tree.nodes[tree.n].parent = 3; // 父节点为D
    tree.n++;                      // n=9

    tree.nodes[tree.n].data = 'J';
    tree.nodes[tree.n].parent = 3; // 父节点为D
    tree.n++;                      // n=10

    // 第三层子节点
    tree.nodes[tree.n].data = 'K';
    tree.nodes[tree.n].parent = 4; // 父节点为E
    tree.n++;                      // n=11

    return tree;
}

void test_Ptree()
{
    PTree tree = createSamplePTree();

    printf("树的节点数: %d\n", tree.n);
    printf("节点列表:\n");
    printf("索引 | 数据 | 父节点\n");
    for (int i = 0; i < tree.n; i++)
    {
        printf("  %d  |   %c  |   %d\n", i, tree.nodes[i].data, tree.nodes[i].parent);
    }
}
// ------------------- 孩子表示法树测试函数 -------------------
CTree createSampleCTree()
{
    /*
    树的节点数: 11
    根节点索引: 0
    节点列表:
    节点 A 的孩子: 1(B) 2(C) 3(D)
    节点 B 的孩子: 4(E) 5(F)
    节点 C 的孩子: 6(G)
    节点 D 的孩子: 7(H) 8(I) 9(J)
    节点 E 的孩子: 10(K)
    节点 F 的孩子: 无
    节点 G 的孩子: 无
    节点 H 的孩子: 无
    节点 I 的孩子: 无
    节点 J 的孩子: 无
    节点 K 的孩子: 无
    */

    CTree tree;
    tree.n = 11;
    tree.r = 0;

    // 初始化节点的数据data以及firstChild
    // 初始化节点数据                // 初始化所有 firstChild 为 NULL
    tree.nodes[0].data = 'A';       tree.nodes[0].firstChild = NULL;
    tree.nodes[1].data = 'B';       tree.nodes[1].firstChild = NULL;
    tree.nodes[2].data = 'C';       tree.nodes[2].firstChild = NULL;
    tree.nodes[3].data = 'D';       tree.nodes[3].firstChild = NULL;
    tree.nodes[4].data = 'E';       tree.nodes[4].firstChild = NULL;
    tree.nodes[5].data = 'F';       tree.nodes[5].firstChild = NULL;
    tree.nodes[6].data = 'G';       tree.nodes[6].firstChild = NULL;
    tree.nodes[7].data = 'H';       tree.nodes[7].firstChild = NULL;
    tree.nodes[8].data = 'I';       tree.nodes[8].firstChild = NULL;
    tree.nodes[9].data = 'J';       tree.nodes[9].firstChild = NULL;
    tree.nodes[10].data = 'K';      tree.nodes[10].firstChild = NULL;

    // 创建 A 的孩子链表 (B -> C -> D)
    struct CTNode *b = (struct CTNode *)malloc(sizeof(struct CTNode));
    struct CTNode *c = (struct CTNode *)malloc(sizeof(struct CTNode));
    struct CTNode *d = (struct CTNode *)malloc(sizeof(struct CTNode));
    b->child = 1;   
    b->next = c;
    c->child = 2;
    c->next = d;
    d->child = 3;
    d->next = NULL;
    tree.nodes[0].firstChild = b;

    // 创建 B 的孩子链表 (E -> F)
    struct CTNode *e = (struct CTNode *)malloc(sizeof(struct CTNode));
    struct CTNode *f = (struct CTNode *)malloc(sizeof(struct CTNode));
    e->child = 4;
    e->next = f;
    f->child = 5;
    f->next = NULL;
    tree.nodes[1].firstChild = e;

    // 创建 C 的孩子链表 (G)
    struct CTNode *g = (struct CTNode *)malloc(sizeof(struct CTNode));
    g->child = 6;
    g->next = NULL;
    tree.nodes[2].firstChild = g;

    // 创建 D 的孩子链表 (H -> I -> J)
    struct CTNode *h = (struct CTNode *)malloc(sizeof(struct CTNode));
    struct CTNode *i_node = (struct CTNode *)malloc(sizeof(struct CTNode));
    struct CTNode *j = (struct CTNode *)malloc(sizeof(struct CTNode));
    h->child = 7;
    h->next = i_node;
    i_node->child = 8;
    i_node->next = j;
    j->child = 9;
    j->next = NULL;
    tree.nodes[3].firstChild = h;

    // 创建 E 的孩子链表 (K)
    struct CTNode *k = (struct CTNode *)malloc(sizeof(struct CTNode));
    k->child = 10;
    k->next = NULL;
    tree.nodes[4].firstChild = k;

    return tree;
}

int test_Ctree()
{
    CTree tree = createSampleCTree();

    printf("树的节点数: %d\n", tree.n);
    printf("根节点索引: %d\n", tree.r);

    printf("节点列表:\n");
    for (int i = 0; i < tree.n; i++)
    {
        printf("节点 %c 的孩子: ", tree.nodes[i].data);
        struct CTNode *child = tree.nodes[i].firstChild;

        if (child == NULL)
        {
            printf("无\n");
        }
        else
        {
            while (child != NULL)
            {
                printf("%d(%c) ", child->child, tree.nodes[child->child].data);
                child = child->next;
            }
            printf("\n");
        }
    }

    return 0;
}

// ------------------- 主函数 -------------------

/**
 * @brief 程序入口
 * @return 0 表示成功退出
 */
int main()
{
    test_CStree();

    test_Ptree();

    test_Ctree();

    return 0;
}
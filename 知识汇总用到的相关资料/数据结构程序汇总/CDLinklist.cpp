/**
 * @brief 线性表
 * @attention：
 * 线性表的基本概念
 * 1. 线性表：是具有相同数据类型的 n 个数据元素的有限序列。
 * 2. 特点：
 * * 存在惟一的第一个元素。
 * * 存在惟一的最后一个元素。
 * * 除第一个元素之外，每个元素均只有一个直接前驱。
 * * 除最后一个元素之外，每个元素均只有一个直接后继。
 * 3. 线性表的存储结构：
 * * 顺序存储结构：顺序表
 * * 链式存储结构：链表
 */
/**
 * @brief 链表——循环双链表
 * @attention：
 * 循环单链表的基本概念
 * 循环链表是另一种形式的链式存储结构。它的特点是表中最后一个结点的指针域指向头结点，整个链表形成一个环。
 */
/***********************双链表***********************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct DNode
{                               // 定义双链表结点类型
    int data;                   // 数据域
    struct DNode *prior, *next; // 前驱和后继指针
} DNode, *DLinklist;

bool InitDList(DLinklist &L);                  // 初始化双链表
DLinklist List_TailInsert(DLinklist &L);       // 尾插法建立双链表
DLinklist List_HeadInsert(DLinklist &L);       // 头插法建立双链表
DNode *GetElem(DLinklist L, int i);            // 按位查找：查找在双链表L中第i个位置的结点(与单链表相同)
DNode *LocateElem(DLinklist L, int x);         // 按值查找：查找x在L中的位置(与单链表相同)
bool InsertDNodeNextDNode(DNode *p, DNode *s); // 将结点s插入到结点p之后
bool InsertNextDNode(DNode *p, int e);         // 指定节点后p后插入e
bool InsertPriorNode(DNode *p, int e);         // 指定节点p前插入e
bool ListInsert(DLinklist &L, int i, int e);   // 按位序插入，在第i个位置插插入元素e
bool DeleteNode(DNode *p, int &e);             // 删除单个节点
bool ListDelete(DLinklist &L, int i, int &e);  // 删除第i个结点并将其所保存的数据存入e
bool isEmpty(DLinklist L);                     // 判断双链表是否为空
int GetLength(DLinklist &L);                   // 获得链表长度(与单链表相同)
void PrintList(DLinklist &L);                  // 输出链表
void clear(DLinklist &L);                      // 清空链表
void InversePrint(DLinklist &L);               // 逆向遍历链表

// 初始化双链表
bool InitDList(DLinklist &L)
{
    L = (DNode *)malloc(sizeof(DNode));
    if (L == NULL)
        return false;
    L->prior = L; // 头结点的prior指针暂时指向L
    L->next = L;  // 头结点之后暂时还没有结点，指向L
    return true;
}

// 尾插法建立双链表
DLinklist List_TailInsert(DLinklist &L)
{
    InitDList(L); // 初始化

    DNode *s, *r = L;

    int x;
    scanf("%d", &x);
    while (x != 9999)
    {
        // 初始：  [L]L[L]
        // 初始：  [L]rL[s]   [r]s[L]   ……
        s = (DNode *)malloc(sizeof(DNode));
        s->data = x;
        s->next = L;
        s->prior = r;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    L->prior = r;
    return L;
}

// 头插法建立双链表
DLinklist List_HeadInsert(DLinklist &L)
{
    InitDList(L); // 初始化

    int x;
    scanf("%d", &x); // 输入要插入的结点的值
    DNode *s;

    while (x != 9999)
    {
        // 初始：  [L]L[L]
        // 初始：  [L]L[s1]  [L]s1(x1)[L]   ……
        // 初始：  [L]L[s2]  [s2]s1(x1)[L]   [L]s2(x2)[s1]
        // 整理：  [L]L[s2]  [L]s2(x2)[s1]  [s2]s1(x1)[L]  ……
        // 插入过程中保存头结点不变；
        s = (DNode *)malloc(sizeof(DNode));
        s->data = x;
        if (L->next == NULL)
        {
            s->next = L;
            s->prior = L;
            L->next = s;
            L->prior = s;
        }
        else
        {
            s->next = L->next;
            L->next->prior = s;
            s->prior = L;
            L->next = s;
        }
        scanf("%d", &x);
    }

    return L;
}

// 按位查找：查找在双链表L中第i个位置的结点(与单链表相同)
DNode *GetElem(DLinklist L, int i)
{
    if (i == 0)
        return L;
    if (i < 1)
        return NULL;

    int j = 1;
    DNode *p = L->next;

    while (p!= L  && j < i)
    {
        p = p->next;
        j++;
    }
    return p; // 如果i大于表长，p=NULL,直接返回p即可
}

// 按值查找：查找x在L中的位置(与单链表相同)
DNode *LocateElem(DLinklist L, int x)
{
    DNode *p = L->next;
    while (p != NULL && p->data != x)
    {
        p = p->next;
    }
    return p;
}

// 将结点s插入到结点p之后
bool InsertDNodeNextDNode(DNode *p, DNode *s)
{
    if (p == NULL || s == NULL)
        return false;

    // p[后]
    // p[s] [p]s[后] [s]后
    s->next = p->next;
    // 循环链表不会产生空指针问题
    p->next->prior = s;
    s->prior = p;
    p->next = s;
    return true;
}

// 指定节点后p后插入e
bool InsertNextDNode(DNode *p, int e)
{
    if (p == NULL)
        return false;

    DNode *s = (DNode *)malloc(sizeof(DNode));
    s->data = e;
    return InsertDNodeNextDNode(p, s);
}

// 指定节点p前插入e
bool InsertPriorNode(DNode *p, int e)
{
    if (p == NULL)
        return false;

    DNode *s = (DNode *)malloc(sizeof(DNode));
    s->data = e;

    // 前插可以直接转换位后插
    // A B(p后插) C D   ==   A B C(p前插) D
    return InsertDNodeNextDNode(p->prior, s);
}

// 按位序插入，在第i个位置插插入元素e
bool ListInsert(DLinklist &L, int i, int e)
{
    if (i < 1)
        return false;

    // 找到第i-1个元素
    DNode *p = GetElem(L, i - 1);

    // 按位序插入的函数中可以直接调用后插操作
    return InsertNextDNode(p, e);
}

// 删除单个节点
bool DeleteNode(DNode *p, int &e)
{
    if (p == NULL)
        return false;

    // 初始:  前[p]   [前]p[后]  [p]后[后后]
    // 删除p: 前[后]   [前]p[后]  [前]后[后后]

    e = p->data; // 用e返回元素的值
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p); // 释放结点的存储空间

    return true;
}

// 删除第i个结点并将其所保存的数据存入e
bool ListDelete(DLinklist &L, int i, int &e)
{
    if (i < 1)
        return false;

    // // 找到第i-1个元素
    // DNode *p = GetElem(L, i - 1);

    // // 初始: 前[p]   [前]p[后]  [p]后[后后]
    // // 删除q:  前[p]   [前]p[后后]  ~[p]后q[后后]~  [p]后后
    // DNode *q = p->next;
    // e = q->data;
    // p->next = q->next;  // 1
    // q->next->prior = p; // 2
    // free(q);

    // return true;

    DNode *p = GetElem(L, i);
    return DeleteNode(p, e);
}

// 判断双链表是否为空
bool isEmpty(DLinklist L)
{
    return (L->next == L);
}

// 获得链表长度(与单链表相同)
int GetLength(DLinklist &L)
{
    int len = 0; // 统计表长
    DNode *p = L;
    while (p->next != L)
    {
        p = p->next;
        len++;
    }
    return len;
}

// 输出链表
void PrintList(DLinklist &L)
{
    DNode *p = L->next;
    printf("地址%p内存为首节点,无数据,下一个地址为%p\n", L, L->next);

    while (p != L)
    {
        // printf("%d\n", p->data);
        printf("地址%p内存放数据为%d,下一个地址为%p\n", p, p->data, p->next);
        p = p->next;
    }
}

// 清空链表
void clear(DLinklist &L)
{
    DNode *p = L->next;
    while (p != L)
    {
        DNode *q = p;
        p = p->next;
        free(q);
    }
    L->next = L;
}

// 逆向遍历链表
void InversePrint(DLinklist &L)
{
    DNode *p = GetElem(L, GetLength(L));
    DNode *s = p;
    while (p->prior != s)
    {
        // printf("%d\n", p->data);
        printf("地址%p内存放数据为%d,上一个地址为%p\n", p, p->data, p->prior);
        p = p->prior;
    }
    printf("地址%p内存为首节点,无数据，上一个地址为%p\n", p, p->prior);
}

int main()
{
    DLinklist L; // 创建一个顺序表
    DNode *Lp;
    int length, e; // 定义链表长度
    InitDList(L);  // 初始化顺序表

    // 头插法建立链表(输入9999停止)
    // listHeadInsert(L);

    // 尾插法建立链表(输入9999停止)
    // 1 2 3 4 5 6 7 9999
    List_TailInsert(L);

    // 输出链表相关信息
    PrintList(L);
    length = GetLength(L);
    printf("链表长度为：%d\n\n", length);

    // 判断表是否为空
    printf("链表为空? %d | (0)假 (1)真 \n\n", isEmpty(L));

    // 按位序插入使用头插
    ListInsert(L, 3, 100);

    // 输出链表相关信息
    PrintList(L);
    length = GetLength(L);
    printf("链表长度为：%d\n\n", length);

    // 查找指定位序3的结点并返回
    Lp = GetElem(L, 3);
    printf("该位置处 节点地址为:%p, 其值为%d\n\n", Lp, Lp->data);

    // 指定节点后p后插入e
    InsertNextDNode(Lp, 20);

    // 输出链表相关信息
    PrintList(L);
    length = GetLength(L);
    printf("链表长度为：%d\n\n", length);

    // 按值查找元素
    Lp = LocateElem(L, 5);
    printf("该位置处 节点地址为:%p, 其值为%d\n\n", Lp, Lp->data);

    // 指定节点p前插入e
    InsertPriorNode(Lp, 25);

    // 输出链表相关信息
    PrintList(L);
    length = GetLength(L);
    printf("链表长度为：%d\n\n", length);

    // 按位序删除
    int delData;
    if (ListDelete(L, 2, delData))
    {
        printf("删除的数据为: %d\n\n", delData);
    }
    else
    {
        printf("删除错误!\n\n");
    }

    // 输出链表相关信息
    PrintList(L);
    length = GetLength(L);
    printf("链表长度为：%d\n\n", length);

    // 删除单个节点
    DeleteNode(Lp, delData);
    printf("删除的数据为: %d\n\n", delData);

    // 输出链表相关信息
    PrintList(L);
    printf("\n逆向遍历链表\n");
    InversePrint(L);
    length = GetLength(L);
    printf("链表长度为：%d\n\n", length);

    // 清空链表
    clear(L);
    printf("链表为空? %d | (0)假 (1)真 \n\n", isEmpty(L));

    return 0;
}

/*

1 2 3 4 5 6 7 9999
地址0000016F2EEB5CA0内存为首节点,无数据,下一个地址为0000016F2EEB5EE0
地址0000016F2EEB5EE0内存放数据为1,下一个地址为0000016F2EEB5F30
地址0000016F2EEB5F30内存放数据为2,下一个地址为0000016F2EEB5F80
地址0000016F2EEB5F80内存放数据为3,下一个地址为0000016F2EEBC4A0
地址0000016F2EEBC4A0内存放数据为4,下一个地址为0000016F2EEBC4F0
地址0000016F2EEBC4F0内存放数据为5,下一个地址为0000016F2EEBC540
地址0000016F2EEBC540内存放数据为6,下一个地址为0000016F2EEBC590
地址0000016F2EEBC590内存放数据为7,下一个地址为0000016F2EEB5CA0
链表长度为：7

链表为空? 0 | (0)假 (1)真

地址0000016F2EEB5CA0内存为首节点,无数据,下一个地址为0000016F2EEB5EE0
地址0000016F2EEB5EE0内存放数据为1,下一个地址为0000016F2EEB5F30
地址0000016F2EEB5F30内存放数据为2,下一个地址为0000016F2EEBD610
地址0000016F2EEBD610内存放数据为100,下一个地址为0000016F2EEB5F80
地址0000016F2EEB5F80内存放数据为3,下一个地址为0000016F2EEBC4A0
地址0000016F2EEBC4A0内存放数据为4,下一个地址为0000016F2EEBC4F0
地址0000016F2EEBC4F0内存放数据为5,下一个地址为0000016F2EEBC540
地址0000016F2EEBC540内存放数据为6,下一个地址为0000016F2EEBC590
地址0000016F2EEBC590内存放数据为7,下一个地址为0000016F2EEB5CA0
链表长度为：8

该位置处 节点地址为:0000016F2EEBD610, 其值为100

地址0000016F2EEB5CA0内存为首节点,无数据,下一个地址为0000016F2EEB5EE0
地址0000016F2EEB5EE0内存放数据为1,下一个地址为0000016F2EEB5F30
地址0000016F2EEB5F30内存放数据为2,下一个地址为0000016F2EEBD610
地址0000016F2EEBD610内存放数据为100,下一个地址为0000016F2EEBD660
地址0000016F2EEBD660内存放数据为20,下一个地址为0000016F2EEB5F80
地址0000016F2EEB5F80内存放数据为3,下一个地址为0000016F2EEBC4A0
地址0000016F2EEBC4A0内存放数据为4,下一个地址为0000016F2EEBC4F0
地址0000016F2EEBC4F0内存放数据为5,下一个地址为0000016F2EEBC540
地址0000016F2EEBC540内存放数据为6,下一个地址为0000016F2EEBC590
地址0000016F2EEBC590内存放数据为7,下一个地址为0000016F2EEB5CA0
链表长度为：9

该位置处 节点地址为:0000016F2EEBC4F0, 其值为5

地址0000016F2EEB5CA0内存为首节点,无数据,下一个地址为0000016F2EEB5EE0
地址0000016F2EEB5EE0内存放数据为1,下一个地址为0000016F2EEB5F30
地址0000016F2EEB5F30内存放数据为2,下一个地址为0000016F2EEBD610
地址0000016F2EEBD610内存放数据为100,下一个地址为0000016F2EEBD660
地址0000016F2EEBD660内存放数据为20,下一个地址为0000016F2EEB5F80
地址0000016F2EEB5F80内存放数据为3,下一个地址为0000016F2EEBC4A0
地址0000016F2EEBC4A0内存放数据为4,下一个地址为0000016F2EEBD6B0
地址0000016F2EEBD6B0内存放数据为25,下一个地址为0000016F2EEBC4F0
地址0000016F2EEBC4F0内存放数据为5,下一个地址为0000016F2EEBC540
地址0000016F2EEBC540内存放数据为6,下一个地址为0000016F2EEBC590
地址0000016F2EEBC590内存放数据为7,下一个地址为0000016F2EEB5CA0
链表长度为：10

删除的数据为: 2

地址0000016F2EEB5CA0内存为首节点,无数据,下一个地址为0000016F2EEB5EE0
地址0000016F2EEB5EE0内存放数据为1,下一个地址为0000016F2EEBD610
地址0000016F2EEBD610内存放数据为100,下一个地址为0000016F2EEBD660
地址0000016F2EEBD660内存放数据为20,下一个地址为0000016F2EEB5F80
地址0000016F2EEB5F80内存放数据为3,下一个地址为0000016F2EEBC4A0
地址0000016F2EEBC4A0内存放数据为4,下一个地址为0000016F2EEBD6B0
地址0000016F2EEBD6B0内存放数据为25,下一个地址为0000016F2EEBC4F0
地址0000016F2EEBC4F0内存放数据为5,下一个地址为0000016F2EEBC540
地址0000016F2EEBC540内存放数据为6,下一个地址为0000016F2EEBC590
地址0000016F2EEBC590内存放数据为7,下一个地址为0000016F2EEB5CA0
链表长度为：9

删除的数据为: 5

地址0000016F2EEB5CA0内存为首节点,无数据,下一个地址为0000016F2EEB5EE0
地址0000016F2EEB5EE0内存放数据为1,下一个地址为0000016F2EEBD610
地址0000016F2EEBD610内存放数据为100,下一个地址为0000016F2EEBD660
地址0000016F2EEBD660内存放数据为20,下一个地址为0000016F2EEB5F80
地址0000016F2EEB5F80内存放数据为3,下一个地址为0000016F2EEBC4A0
地址0000016F2EEBC4A0内存放数据为4,下一个地址为0000016F2EEBD6B0
地址0000016F2EEBD6B0内存放数据为25,下一个地址为0000016F2EEBC540
地址0000016F2EEBC540内存放数据为6,下一个地址为0000016F2EEBC590
地址0000016F2EEBC590内存放数据为7,下一个地址为0000016F2EEB5CA0

逆向遍历链表
地址0000016F2EEBC590内存放数据为7,上一个地址为0000016F2EEBC540
地址0000016F2EEBC540内存放数据为6,上一个地址为0000016F2EEBD6B0
地址0000016F2EEBD6B0内存放数据为25,上一个地址为0000016F2EEBC4A0
地址0000016F2EEBC4A0内存放数据为4,上一个地址为0000016F2EEB5F80
地址0000016F2EEB5F80内存放数据为3,上一个地址为0000016F2EEBD660
地址0000016F2EEBD660内存放数据为20,上一个地址为0000016F2EEBD610
地址0000016F2EEBD610内存放数据为100,上一个地址为0000016F2EEB5EE0
地址0000016F2EEB5EE0内存放数据为1,上一个地址为0000016F2EEB5CA0
地址0000016F2EEB5CA0内存为首节点,无数据，上一个地址为0000016F2EEBC590
链表长度为：8

链表为空? 1 | (0)假 (1)真

*/
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
 * @brief 链表——循环单链表
 * @attention：
 * 循环单链表的基本概念
 * 循环链表是另一种形式的链式存储结构。它的特点是表中最后一个结点的指针域指向头结点，整个链表形成一个环。
 */
/***********************带头结点***********************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct LNode // 定义单链表结点类型
{
    int data;           // 每个节点存放一个数据元素
    struct LNode *next; // 指针指向下一个节点
} LNode, *LinkList;

bool InitList(LinkList &L);                  // 初始化链表
LinkList List_TailInsert(LinkList &L);       // 使用尾插法建立单链表L
LinkList List_HeadInsert(LinkList &L);       // 使用头插法建立单链表L
LNode *GetElem(LinkList L, int i);           // 查找指定位序i的结点并返回
LNode *LocateElem(LinkList L, int data);     // 按值查找元素
bool InsertNextNode(LNode *p, int e);        // 指定节点后p后插入e
bool InsertPriorNode(LNode *p, int e);       // 指定节点p前插入e
bool ListInsert(LinkList &L, int i, int e);  // 按位序插入，在第i个位置插插入元素e
bool DeleteNode(LNode *p, int &e);           // 删除单个节点
bool ListDelete(LinkList &L, int i, int &e); // 删除第i个结点并将其所保存的数据存入e
bool isEmpty(LinkList L);                    // 判断链表是否为空
int GetLength(LinkList &L);                  // 获得链表长度
void PrintfList(LinkList &L);                // 输出链表
void clear(LinkList &L);                     // 清空链表
LNode *Inverse(LNode *L);                    // 将链表L中的数据逆置并返回

// 初始化链表
bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode)); // 分配一个头结点
    if (L == NULL)                      // 内存不足，分配失败
        return false;
    L->next = L; // 最后一个结点的next指针指向头结点
    // 初始化结束后，链表: &1[NULL| ]
    return true;
}

// 使用尾插法建立单链表L
LinkList List_TailInsert(LinkList &L)
{
    int x;                               // 设ElemType为整型int
    L = (LinkList)malloc(sizeof(LNode)); // 建立头结点(初始化空表)
    LNode *s, *r = L;                    // r为表尾指针  L/r[NULL| ]

    scanf("%d", &x); // 输入要插入的结点的值
    while (x != 9999)
    { // 输入9999表示结束
        // 初始：L/r[NULL| ]
        // 插入：L/r[s| ] s[ |x]
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        // 插入：L[s| ] s/r[ |x]
        r = s; // r指针指向新的表尾结点
        scanf("%d", &x);
    }
    // 插入：L[s| ] s/r[NULL|x]
    r->next = L; // 尾结点指针置L

    return L;
}

// 使用头插法建立单链表L
LinkList List_HeadInsert(LinkList &L)
{ // 逆向建立单链表
    LNode *s;
    int x;
    L = (LinkList)malloc(sizeof(LNode)); // 建立头结点
    L->next = L;                         // 初始为空链表,这步很关键

    scanf("%d", &x); // 输入要插入的结点的值
    while (x != 9999)
    { // 输入9999表结束
        // 初始：L[NULL| ]
        // 插入：L[s1| ] s1[NULL|x1]
        // 插入：L[s2| ] s2[s1|x2] s1[NULL|x1]
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        // 将新结点插入表中，L为头指针
        scanf("%d", &x);
    }
    return L;
}

// 查找指定位序i的结点并返回
LNode *GetElem(LinkList L, int i)
{
    if (i < 0)
        return NULL;
    if (i == 0)
        return L;

    LNode *p;    // p指向扫描到的节点
    int j = 1;   // 当前p指向的是第几个结点
    p = L->next; // L指向头结点，头结点是第0个节点

    // &0[&1] &1[&2] &2[&3] &3[&4] &4[NULL]
    // IN 2
    // 循环找到第 i-1 个节点
    while (p != L && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}

// 按值查找元素
LNode *LocateElem(LinkList L, int data)
{
    LNode *p = L->next;
    while (p != L && p->data != data)
    {
        p = p->next;
    }
    return p;
}

// 指定节点后p后插入e
bool InsertNextNode(LNode *p, int e)
{
    if (p == NULL)
        return false;

    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL) // 内存分配失败
        return false;

    // 初始:  | 前[P|] | p[后|*p] | 后[后后|]
    // 插入s: | 前[P|] | p[s|*p]  | s[后|e] | 后[后后|]
    s->data = e; // s节点保存数据元素e
    s->next = p->next;
    p->next = s; // 节点s连接在p后
    return true;
}

// 指定节点p前插入e
// 在指定结点p后插入一个结点s，并交换两个结点所保存的数据，从而变相实现指定结点的前插操作。
bool InsertPriorNode(LNode *p, int e)
{
    if (p == NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL) // 内存分配失败
        return false;

    // 初始:  | 前[P|] | p[后|*p] | 后[后后|]
    // 插入s: | 前[P|] | s[后|*p] | 后[后后|]
    s->data = p->data;
    s->next = p->next;
    // 插入p: | 前[P|] | p[s|e] | s[后|*p] | 后[后后|]
    p->next = s;
    p->data = e;
    return true;
}

// 按位序插入，在第i个位置插插入元素e
bool ListInsert(LinkList &L, int i, int e)
{
    if (i < 1)
        return false;

    // 找到第i-1个元素
    LNode *p = GetElem(L, i - 1);

    // LNode *p; // 指针p指向当前扫描到的结点

    // int j = 0; // 当前p指向的是第几个结点
    // p = L;	   // L指向头结点，头结点是第0个节点

    // // 循环找到第 i-1 个节点
    // while (p != NULL && j < i - 1)
    // {
    // 	// 如果i>lengh，p最后会等于NULL
    // 	p = p->next;
    // 	j++;
    // }

    // 按位序插入的函数中可以直接调用后插操作
    return InsertNextNode(p, e);

    // // p值为NULL说明i值不合法
    // if (p == NULL)
    // 	return false;

    // 初始:  | 前[p|] | p[后|*p] | 后[后后|]
    // 插入s: | 前[p|] | p[s|*p]  | s[后|e] | 后[后后|]
    // // 在第i-1个结点后插入新结点
    // LNode *s = (LNode *)malloc(sizeof(LNode));
    // // 将结点s连到p后
    // s->data = e;
    // s->next = p->next;
    // p->next = s;

    // return true; // 插入成功
}

// 删除单个节点
// 将指定结点p的后继结点q删除，并使结点p保存结点q存储的数据，从而变相实现删除指定结点的操作。但是如果指定结点p没有后继结点，这么做会报错。
// 因此如果要删除的结点p是最后一个结点，只能从表头开始依次寻找p的前驱，
bool DeleteNode(LNode *p, int &e)
{
    if (p == NULL)
        return false;

    // 初始:  | 前[p|] | p[q|e] | q[后|*q]
    // 删除q: | 前[p|] | p[后|*q]	  ~~q[后|*q]

    // 如果p是最后一个结点，则q指向NULL，继续执行就会报错
    LNode *q = p->next;      // 令q指向*p的后继结点
    e = p->data;             // 用e返回元素的值
    p->data = p->next->data; // 让p和后继结点交换数据域 (q = p->next)
    p->next = q->next;       // 将*q结点从链中"断开”
    free(q);                 // 释放结点的存储空间
    return true;
}

// 删除第i个结点并将其所保存的数据存入e
bool ListDelete(LinkList &L, int i, int &e)
{
    if (i < 1)
        return false;

    // LNode *p;  // 指针p指向当前扫描到的结点
    // int j = 0; // 当前p指向的是第几个结点
    // p = L;	   // L指向头结点，头结点是第0个结点

    // // 循环找到第i-1个结点
    // while (p != NULL && j < i - 1)
    // {
    // 	// 如果i>length，p和p的后继结点会等于NULL
    // 	p = p->next;
    // 	j++;
    // }
    // if (p == NULL)
    // 	return false;
    // if (p->next == NULL)
    // 	return false;

    // 找到第i-1个元素
    LNode *p = GetElem(L, i - 1);

    // 初始:  | 前[p|] | p[q|*p] | q[后|e]
    // 删除q: | 前[p|] | p[后|*p]	   ~~q[后|e]
    // 和上面主要区别在于：一个删除p节点，一个删除q节点，删除方法相同，就是删除值不同
    LNode *q = p->next; // 令q指向被删除结点
    e = q->data;        // 用e返回元素的值
    p->next = q->next;  // 将*q结点从链中"断开”
    free(q);            // 释放结点的存储空间
    return true;
}

// 判断链表是否为空
bool isEmpty(LinkList L)
{
    // if (L->next == L)
    // {
    //     return true;
    // }
    // else{
    //     return false;
    // }
    return (L->next == L);
}

// 获得链表长度
int GetLength(LinkList &L)
{
    int len = 0; // 统计表长
    LNode *p = L;

    while (p->next != L)
    {
        p = p->next;
        len++;
    }
    return len;
}

// 输出链表
void PrintfList(LinkList &L)
{
    LNode *p;    // p指向扫描到的节点
    p = L->next; // L指向头结点，头结点是第0个节点
    printf("地址%p内存为首节点,无数据,下一个地址为%p\n", L, L->next);

    while (p != L)
    {
        // printf("%d\n", p->data);
        printf("地址%p内存放数据为%d,下一个地址为%p\n", p, p->data, p->next);
        p = p->next;
    }
}

// 清空链表
void clear(LinkList &L)
{
    LNode *p = L->next;
    while (p != L)
    {
        LNode *q = p;
        p = p->next;
        free(q);
    }
    L->next = L;
}

// 将链表L中的数据逆置并返回
// https://blog.csdn.net/qq_42322103/article/details/82668765
LNode *Inverse(LNode *L)
{
    LNode *p, *q;

    // 初始: L[A] A[B] B[C] C[D] D[E]
    // 修改：L[NULL] pA[B] B[C] C[D] D[E]
    p = L->next; // p指针指向第一个结点
    L->next = L; // 头结点置空

    // 原始：L[NULL] pA[B] B[C] C[D] D[E]
    // 修改：L[NULL] qpA[B] B[C] C[D] D[E]
    // 修改：L[NULL] qA[B] pB[C] C[D] D[E]
    // 修改：L[A] qA[NULL] pB[C] C[D] D[E]

    q = p;
    p = p->next;
    q->next = L->next;
    L->next = q;

    // 原始：L[A] qA[NULL] pB[C] C[D] D[E]
    // 修改：L[A] A[NULL] qB[C] pC[D] D[E]
    // 修改：L[B] A[NULL] qB[A] pC[D] D[E]
    // 整理：L[B] qB[A] A[NULL] pC[D] D[E]

    // …… ……

    // 依次判断p结点中的数据并采用头插法插到L链表中
    while (p != L)
    {
        q = p;
        p = p->next;
        q->next = L->next;
        L->next = q;
    }
    return L;
}

int main()
{
    LinkList L; // 创建一个顺序表
    LNode *Lp;
    int length, e; // 定义链表长度
    InitList(L);   // 初始化顺序表

    // 头插法建立链表(输入9999停止)
    // listHeadInsert(L);

    // 尾插法建立链表(输入9999停止)
    // 1 2 3 4 5 6 7 9999
    List_TailInsert(L);

    // 输出链表相关信息
    PrintfList(L);
    length = GetLength(L);
    printf("链表长度为：%d\n\n", length);

    // 判断表是否为空
    printf("链表为空? %d | (0)假 (1)真 \n\n", isEmpty(L));

    // 按位序插入使用头插
    ListInsert(L, 3, 100);

    // 输出链表相关信息
    PrintfList(L);
    length = GetLength(L);
    printf("链表长度为：%d\n\n", length);

    // 查找指定位序3的结点并返回
    Lp = GetElem(L, 3);
    printf("该位置处 节点地址为:%p, 其值为%d\n\n", Lp, Lp->data);

    // 指定节点后p后插入e
    InsertNextNode(Lp, 20);

    // 输出链表相关信息
    PrintfList(L);
    length = GetLength(L);
    printf("链表长度为：%d\n\n", length);

    // 按值查找元素
    Lp = LocateElem(L, 5);
    printf("该位置处 节点地址为:%p, 其值为%d\n\n", Lp, Lp->data);

    // 指定节点p前插入e
    InsertPriorNode(Lp, 25);

    // 输出链表相关信息
    PrintfList(L);
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
    PrintfList(L);
    length = GetLength(L);
    printf("链表长度为：%d\n\n", length);

    // 删除单个节点
    DeleteNode(Lp, delData);
    printf("删除的数据为: %d\n\n", delData);

    // 输出链表相关信息
    PrintfList(L);
    length = GetLength(L);
    printf("链表长度为：%d\n\n", length);

    // 将链表L中的数据逆置并返回
    Inverse(L);

    // 输出链表相关信息
    PrintfList(L);
    length = GetLength(L);
    printf("链表长度为：%d\n\n", length);

    // 清空链表
    clear(L);
    printf("链表为空? %d | (0)假 (1)真 \n\n", isEmpty(L));

    return 0;
}

/*

1 2 3 4 5 6 7 9999
地址000002CE6D24A710内存为首节点,无数据,下一个地址为000002CE6D245CA0
地址000002CE6D245CA0内存放数据为1,下一个地址为000002CE6D245EE0
地址000002CE6D245EE0内存放数据为2,下一个地址为000002CE6D245F20
地址000002CE6D245F20内存放数据为3,下一个地址为000002CE6D245F60
地址000002CE6D245F60内存放数据为4,下一个地址为000002CE6D245FA0
地址000002CE6D245FA0内存放数据为5,下一个地址为000002CE6D24C4A0
地址000002CE6D24C4A0内存放数据为6,下一个地址为000002CE6D24C4E0
地址000002CE6D24C4E0内存放数据为7,下一个地址为000002CE6D24A710
链表长度为：7

链表为空? 0 | (0)假 (1)真

地址000002CE6D24A710内存为首节点,无数据,下一个地址为000002CE6D245CA0
地址000002CE6D245CA0内存放数据为1,下一个地址为000002CE6D245EE0
地址000002CE6D245EE0内存放数据为2,下一个地址为000002CE6D24D550
地址000002CE6D24D550内存放数据为100,下一个地址为000002CE6D245F20
地址000002CE6D245F20内存放数据为3,下一个地址为000002CE6D245F60
地址000002CE6D245F60内存放数据为4,下一个地址为000002CE6D245FA0
地址000002CE6D245FA0内存放数据为5,下一个地址为000002CE6D24C4A0
地址000002CE6D24C4A0内存放数据为6,下一个地址为000002CE6D24C4E0
地址000002CE6D24C4E0内存放数据为7,下一个地址为000002CE6D24A710
链表长度为：8

该位置处 节点地址为:000002CE6D24D550, 其值为100

地址000002CE6D24A710内存为首节点,无数据,下一个地址为000002CE6D245CA0
地址000002CE6D245CA0内存放数据为1,下一个地址为000002CE6D245EE0
地址000002CE6D245EE0内存放数据为2,下一个地址为000002CE6D24D550
地址000002CE6D24D550内存放数据为100,下一个地址为000002CE6D24D590
地址000002CE6D24D590内存放数据为20,下一个地址为000002CE6D245F20
地址000002CE6D245F20内存放数据为3,下一个地址为000002CE6D245F60
地址000002CE6D245F60内存放数据为4,下一个地址为000002CE6D245FA0
地址000002CE6D245FA0内存放数据为5,下一个地址为000002CE6D24C4A0
地址000002CE6D24C4A0内存放数据为6,下一个地址为000002CE6D24C4E0
地址000002CE6D24C4E0内存放数据为7,下一个地址为000002CE6D24A710
链表长度为：9

该位置处 节点地址为:000002CE6D245FA0, 其值为5

地址000002CE6D24A710内存为首节点,无数据,下一个地址为000002CE6D245CA0
地址000002CE6D245CA0内存放数据为1,下一个地址为000002CE6D245EE0
地址000002CE6D245EE0内存放数据为2,下一个地址为000002CE6D24D550
地址000002CE6D24D550内存放数据为100,下一个地址为000002CE6D24D590
地址000002CE6D24D590内存放数据为20,下一个地址为000002CE6D245F20
地址000002CE6D245F20内存放数据为3,下一个地址为000002CE6D245F60
地址000002CE6D245F60内存放数据为4,下一个地址为000002CE6D245FA0
地址000002CE6D245FA0内存放数据为25,下一个地址为000002CE6D24D5D0
地址000002CE6D24D5D0内存放数据为5,下一个地址为000002CE6D24C4A0
地址000002CE6D24C4A0内存放数据为6,下一个地址为000002CE6D24C4E0
地址000002CE6D24C4E0内存放数据为7,下一个地址为000002CE6D24A710
链表长度为：10

删除的数据为: 2

地址000002CE6D24A710内存为首节点,无数据,下一个地址为000002CE6D245CA0
地址000002CE6D245CA0内存放数据为1,下一个地址为000002CE6D24D550
地址000002CE6D24D550内存放数据为100,下一个地址为000002CE6D24D590
地址000002CE6D24D590内存放数据为20,下一个地址为000002CE6D245F20
地址000002CE6D245F20内存放数据为3,下一个地址为000002CE6D245F60
地址000002CE6D245F60内存放数据为4,下一个地址为000002CE6D245FA0
地址000002CE6D245FA0内存放数据为25,下一个地址为000002CE6D24D5D0
地址000002CE6D24D5D0内存放数据为5,下一个地址为000002CE6D24C4A0
地址000002CE6D24C4A0内存放数据为6,下一个地址为000002CE6D24C4E0
地址000002CE6D24C4E0内存放数据为7,下一个地址为000002CE6D24A710
链表长度为：9

删除的数据为: 25

地址000002CE6D24A710内存为首节点,无数据,下一个地址为000002CE6D245CA0
地址000002CE6D245CA0内存放数据为1,下一个地址为000002CE6D24D550
地址000002CE6D24D550内存放数据为100,下一个地址为000002CE6D24D590
地址000002CE6D24D590内存放数据为20,下一个地址为000002CE6D245F20
地址000002CE6D245F20内存放数据为3,下一个地址为000002CE6D245F60
地址000002CE6D245F60内存放数据为4,下一个地址为000002CE6D245FA0
地址000002CE6D245FA0内存放数据为5,下一个地址为000002CE6D24C4A0
地址000002CE6D24C4A0内存放数据为6,下一个地址为000002CE6D24C4E0
地址000002CE6D24C4E0内存放数据为7,下一个地址为000002CE6D24A710
链表长度为：8

地址000002CE6D24A710内存为首节点,无数据,下一个地址为000002CE6D24C4E0
地址000002CE6D24C4E0内存放数据为7,下一个地址为000002CE6D24C4A0
地址000002CE6D24C4A0内存放数据为6,下一个地址为000002CE6D245FA0
地址000002CE6D245FA0内存放数据为5,下一个地址为000002CE6D245F60
地址000002CE6D245F60内存放数据为4,下一个地址为000002CE6D245F20
地址000002CE6D245F20内存放数据为3,下一个地址为000002CE6D24D590
地址000002CE6D24D590内存放数据为20,下一个地址为000002CE6D24D550
地址000002CE6D24D550内存放数据为100,下一个地址为000002CE6D245CA0
地址000002CE6D245CA0内存放数据为1,下一个地址为000002CE6D24A710
链表长度为：8

链表为空? 1 | (0)假 (1)真

*/
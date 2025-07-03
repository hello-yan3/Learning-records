/**
 * @brief 队列
 * @attention：
 * 队列的基本概念
 * 队列是操作受限的线性表：只允许在一端进行插入 (入队)，另一端进行删除 (出队)。
 * 队头：允许删除的一端。
 * 队尾：允许插入的一端。
 * 空队列：不含任何元素的空表。
 * 特点：先进先出（先入队的元素先出队）、FIFO（First In First Out）。
 */
/**
 * @brief 链队列(不带头结点)
 * @attention：
 * 链队列(不带头结点)
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 链式队列结点
typedef struct LinkNode
{
    int data;
    struct LinkNode *next;
} LinkNode;

// 链式队列
typedef struct
{
    // 头指针和尾指针
    LinkNode *front, *rear;
} LinkQueue;

void InitQueue(LinkQueue &Q);
void EnQueue(LinkQueue &Q, int x);
bool DeQueue(LinkQueue &Q, int &x);
bool GetHead(LinkQueue Q, int &x);
bool isEmpty(LinkQueue Q);

// 初始化队列
void InitQueue(LinkQueue &Q)
{
    // 不带头结点的链队列初始化，头指针和尾指针都指向NULL
    Q.front = NULL;
    Q.rear = NULL;
}

// 新元素入队
void EnQueue(LinkQueue &Q, int x)
{
    LinkNode *p = (LinkNode *)malloc(sizeof(LinkNode));

    p->data = x;
    p->next = NULL;

    // 第一个元素入队时需要特别处理
    if (Q.front == NULL)
    {
        Q.front = p; // 在空队列中插入第一个元素
        Q.rear = p;  // 修改队头队尾指针
    }
    else
    {
        Q.rear->next = p; // 新节点插入到rear结点之后
        Q.rear = p;       // 修改rear指针
    }
}

// 队头元素出队
bool DeQueue(LinkQueue &Q, int &x)
{
    if (Q.front == NULL)
        return false; // 空队

    LinkNode *p = Q.front; // s指向此次出队的结点
    x = p->data;           // 用变量x返回队头元素
    Q.front = p->next;     // 修改front指针

    // 正常情况下，表头操作不会影响表尾数据
    // 但是如果是最后一个节点出队，free(p)之后，Q.rear将=NULL (Q.front = s->next = NULL)
    // 为避免此情况，需要修改Q.rear值为实际值(此时Q.rear为队头)
    if (Q.rear == p) // 此次是最后一个结点出队
    {
        Q.front = NULL; // front指向 NULL
        Q.rear = NULL;  // rear指向 NULL
    }

    free(p);
    return true;
}

// 获取队头元素
bool GetHead(LinkQueue Q, int &x)
{
    if (Q.front == Q.rear)
        return false; // 空队
    x = Q.front->data;
    return true;
}

// 判断队列是否为空
bool isEmpty(LinkQueue Q)
{
    // if (Q.front == NULL)
    //     return true;
    // else
    //     return false;
    return !(Q.front == NULL);
}

int main()
{
    LinkQueue Q; // 声明一个队列
    int x;
    InitQueue(Q);

    EnQueue(Q, 0);
    EnQueue(Q, 1);
    EnQueue(Q, 2);
    EnQueue(Q, 3);
    EnQueue(Q, 4);

    printf("队列是否空?%d:  0 空, 1非空\n", (isEmpty(Q) == true));

    GetHead(Q, x);
    printf("队头元素为：%d\n", x);

    DeQueue(Q, x);
    printf("出队元素为：%d\n", x);

    GetHead(Q, x);
    printf("此时队头元素为：%d\n", x);

    return 0;
}
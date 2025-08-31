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
 * @brief 顺序队列
 * @attention：
 * 顺序队列
 */
/***********************顺序栈***********************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxSize 10 // 定义栈中元素的最大个数

typedef struct
{
    int data[MaxSize]; // 静态数组存放栈中元素
    int front, rear;   // 队头指针和队尾指针
} SqQueue;
/*
循环队列不能使用Q.rear == Q.front作为判空的条件，因为当队列已满时也符合该条件，会与判空发生冲突！
解决方法一：牺牲一个单元来区分队空和队满，即将(Q.rear+1)%MaxSize == Q.front作为判断队列是否已满的条件。（主流方法）
解决方法二：设置 size 变量记录队列长度。
*/

void InitQueue(SqQueue &Q);       // 初始化队列
bool EnQueue(SqQueue &Q, int x);  // 新元素进队列(循环队列)
bool DeQueue(SqQueue &Q, int &x); // 出队列(循环队列)
bool GetHead(SqQueue Q, int &x);  // 获取队头元素并存入x
bool isEmpty(SqQueue Q);          // 判断栈是否为空

// 初始化队列
void InitQueue(SqQueue &Q)
{
    // 初始化时，队头、队尾指针指向0
    // 队尾指针指向的是即将插入数据的数组下标
    // 队头指针指向的是队头元素的数组下标
    Q.rear = Q.front = 0;
}

// 新元素进队列(循环队列)
bool EnQueue(SqQueue &Q, int x)
{
    // 如果队列已满直接返回
    if ((Q.rear + 1) % MaxSize == Q.front) // 牺牲一个单元区分队空和队满
        return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}

// 出队列(循环队列)
bool DeQueue(SqQueue &Q, int &x)
{
    // 如果队列为空直接返回
    if (Q.rear == Q.front)
        return false;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}

// 获取队头元素并存入x
bool GetHead(SqQueue Q, int &x)
{
    // 如果队列为空直接返回
    if (Q.rear == Q.front)
        return false;
    x = Q.data[Q.front];
    return true;
}

// 判断栈是否为空
bool isEmpty(SqQueue Q)
{
    // if (Q.rear == Q.front)
    //     return true;
    // else
    //     return false;
    return !(Q.rear == Q.front);
}

int main()
{
    SqQueue Q; // 声明一个顺序队列(分配空间)
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

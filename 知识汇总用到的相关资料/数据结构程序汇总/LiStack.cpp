/**
 * @brief 栈
 * @attention：
 * 栈的基本概念
 * 栈是特殊的线性表：只允许在一端进行插入或删除操作，其逻辑结构与普通线性表相同。
 * 栈顶：允许进行插入和删除的一端 （最上面的为栈顶元素）。
 * 栈底：不允许进行插入和删除的一端 （最下面的为栈底元素）。
 * 空栈：不含任何元素的空表。
 * 特点：后进先出（后进栈的元素先出栈）、LIFO（Last In First Out）。
 * 缺点：栈的大小不可变，解决方法：共享栈。
 */
/**
 * @brief 链栈(带头结点)
 * @attention：
 * 链栈实际上就是一个只能采用头插法插入或删除数据的链表;
 * 本程序为带头结点链栈，
 * 不带头结点链栈见：
 * https://blog.csdn.net/Xulidanga/article/details/108895669
 * https://blog.csdn.net/Sdjzu_Nxy/article/details/129263174
 */
/***********************链栈(带头结点)***********************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Linknode
{
    int data;              // 数据域
    struct Linknode *next; // 指针域
} Linknode, *LiStack;

void InitStack(LiStack &S);     // 初始化栈
void Push(LiStack &S, int x);   // 新元素进栈
bool Pop(LiStack &S, int &x);   // 出栈
bool GetTop(LiStack S, int &x); // 读栈顶元素
bool isEmpty(LiStack S);        // 判断栈是否为空

// 初始化栈
void InitStack(LiStack &S)
{
    S = (Linknode *)malloc(sizeof(Linknode));
    S->next = NULL;
}

// 新元素进栈
void Push(LiStack &S, int x)
{
    Linknode *s = (Linknode *)malloc(sizeof(Linknode)); // 创建存储新元素的结点
    s->data = x;
    s->next = S->next;
    S->next = s;
}

// 出栈
bool Pop(LiStack &S, int &x)
{
    if (S->next == NULL) // 栈空不出栈
        return false;

    Linknode *s;
    s = S->next;
    x = s->data;
    S = S->next->next;
    free(s);

    return true;
}

// 读栈顶元素
bool GetTop(LiStack S, int &x)
{
    if (S->next == NULL) // 栈空不出栈
        return false;

    x = S->next->data;

    return true;
}

// 判断栈是否为空
bool isEmpty(LiStack S)
{
    // if (S->next == NULL)
    //     return true;
    // else
    //     return false;
    return (S->next == NULL);
}

int main()
{
    LiStack S; // 声明一个链栈(分配空间)
    int x;
    InitStack(S);

    Push(S, 0);
    Push(S, 1);
    Push(S, 2);
    Push(S, 3);
    Push(S, 4);

    printf("栈是否空?%d:  0 空, 1非空\n", (isEmpty(S) == true));

    GetTop(S, x);
    printf("栈顶元素为：%d\n", x);

    Pop(S, x);
    printf("出栈元素为：%d\n", x);

    GetTop(S, x);
    printf("此时栈顶元素为：%d\n", x);

    return 0;
}

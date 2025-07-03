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
 * @brief 顺序栈
 * @attention：
 * 顺序栈
 */
/***********************顺序栈***********************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxSize 10 // 定义栈中元素的最大个数

typedef struct
{
    int data[MaxSize]; // 静态数组存放栈中元素
    int top;           // 栈顶元素
} SqStack;

void InitStack(SqStack &S);     // 初始化栈
bool Push(SqStack &S, int x);   // 新元素进栈
bool Pop(SqStack &S, int &x);   // 出栈
bool GetTop(SqStack S, int &x); // 读栈顶元素
bool isEmpty(SqStack S);     // 判断栈是否为空

// 初始化栈
void InitStack(SqStack &S)
{
    S.top = -1; // 初始化栈顶指针
}

// 新元素进栈
bool Push(SqStack &S, int x)
{ // 判断栈是否已满
    if (S.top == MaxSize - 1)
        return false;
    // S.top = S.top + 1; // 指针先加1
    // S.data[S.top] = x; // 新元素入栈
    S.data[++S.top] = x;
    return true;
}

// 出栈
bool Pop(SqStack &S, int &x)
{ // 判断栈是否为空
    if (S.top == -1)
        return false;
    // x = S.data[S.top]; // 先出栈
    // S.top = S.top - 1; // 栈顶指针减1
    x = S.data[S.top--];
    return true;
}

// 读栈顶元素
bool GetTop(SqStack S, int &x)
{
    if (S.top == -1)
        return false;
    x = S.data[S.top];
    return true;
}

// 判断栈是否为空
bool isEmpty(SqStack S)
{
    // if (S.top == -1)
    //     return true;
    // else
    //     return false;
    return !(S.top == -1);
}

// // 括号匹配实例(教程)
// bool bracketCheck(char str[], int length) 
// {
//     SqStack S;
//     InitStack(S);//初始化一个栈
//     for (int i=0; i<length; i++)
//     {
//         if (str[i]=='(' || str[i]=='[' || str[i]=='{' )
//         {
//             Push(S, str[i]);   //扫描到左括号，入栈
//         }
//         else 
//         {
//             if (isEmpty(S))//扫描到右括号，且当前栈空
//                 return false;//匹配失败
//             char topElem;
//             Pop(S,topElem) ;  //栈顶元素出栈
//             if(str[i]==')'&& topElem!='(' )
//                 return false;
//             if(str[i]==']' && topElem!='[')
//                 return false;
//             if(str[i]=='}' && topElem!='{')
//                 return false;
//         }
//     }
//     return isEmpty(S);//检索完全部括号后，栈空说明匹配成
// }

// 括号匹配实例(自己程序适用)
bool bracketCheck(char str[], int length) 
{
    SqStack S;
    InitStack(S);//初始化一个栈
    for (int i=0; i<length; i++)
    {
        if (str[i]=='(' || str[i]=='[' || str[i]=='{' )
        {
            Push(S, (int)str[i]);   //扫描到左括号，入栈
        }
        else 
        {
            if (!isEmpty(S))//扫描到右括号，且当前栈空
                return false;//匹配失败
            int topElem;
            Pop(S,topElem) ;  //栈顶元素出栈
            if(str[i]==')'&& (char)topElem!='(' )
                return false;
            if(str[i]==']' && (char)topElem!='[')
                return false;
            if(str[i]=='}' && (char)topElem!='{')
                return false;
        }
    }
    return !isEmpty(S);//检索完全部括号后，栈空说明匹配成
}

// bool mybracketCheck(char str[])
// {
//     SqStack S;
//     InitStack(S);//初始化一个栈
//     for(unsigned char i=0 ; str[i]!='\0' ; i++)
//     {
//         if( (str[i]=='{') || (str[i]=='[') || (str[i]=='(')  )
//         {
//             Push(S, (int)str[i]);   //扫描到左括号，入栈
//         }
//         else if( (str[i]=='}') || (str[i]==']') || (str[i]==')') )
//         {
//             int top;
//             if( !Pop(S,top) )   //栈顶元素出栈
//                 return false;
//             switch(str[i])
//             {
//             case '}' :
//                 if((char)top!='{')  return false;
//                 break;
//             case ']' :
//                 if((char)top!='[')  return false;
//                 break;
//             case ')' :
//                 if((char)top!='(')  return false;
//                 break;
//             }
//         }
//         else 
//             return false;
//     }
//     return !isEmpty(S);//检索完全部括号后，栈空说明匹配成
// } 


int main()
{
    SqStack S; // 声明一个顺序栈(分配空间)
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

    bool ret = bracketCheck("{[(())()]}", 10);
    printf("括号是否匹配?%d:  0 不匹配, 1匹配\n", (ret == true));

    return 0;
}

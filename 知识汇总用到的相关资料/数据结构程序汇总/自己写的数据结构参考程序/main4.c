#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

void show(int *arr, int len)
{
    for(int i=0; i<len; i++)
    {
        printf("%d \t",arr[i]);
    }
    printf("\n");
}

void maopao(int *arr, int len)
{
    for(int i=0; i<len; i++)
    {
        for(int j=0; j<len-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
        show(arr, len);
    }
}

void xvanze(int *arr, int len)
{
    for(int i=0; i<len; i++)
    {
        int min = i;
        for(int j=i; j<len; j++)
        {   
            if(arr[min]>arr[j])
                min = j;
        }
        int temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;

        show(arr, len);
    }
}

void charu(int *arr, int len)
{
    for(int i=1; i<len; i++)
    {
        int temp = arr[i];
        int j;
        for(j=i-1; j>=0 ; j--)
        {
            if(arr[j]>temp)
                arr[j+1]=arr[j];
            else
                break;
        }
        arr[j+1] = temp;

        show(arr, len);
    }
}

void xier(int *arr, int len)
{
    int increase = len;

    while(increase>1)
    {
        increase = increase/2;
        for(int k=0; k<increase; k++)
        {
            for(int i=k+increase; i<len; i+=increase)
            {
                int temp = arr[i];
                int j;
                for(j=i-increase; j>=0 ; j-=increase)
                {
                    if(arr[j]>temp)
                        arr[j+increase]=arr[j];
                    else
                        break;
                }
                arr[j+increase] = temp;

                show(arr, len);
            }
        }
    }
}

int chazhao(int *arr, int len, int num)
{
    int low=0, high=len, mid=len/2; 
    while(low<=high)
    {
        mid = (low+high)/2;
        // printf("arr[mid]=%d\n", arr[mid]);
        if(arr[mid] ==  num)
            return mid;
        else if(arr[mid]<num)
            low = mid+1;
        else if(arr[mid]>num)
            high = mid-1;
    }
    return -1;
}


void guibin(int *arr, int start, int end)
{
    int *temp = (int*)malloc( 10*sizeof(int) );
    for(int i=start ; i<=end ; i++)
    {
        temp[i]=arr[i];
    }
    int i=start , j=(start+end)/2+1 , k=start; 
    while(1)
    {
        if( temp[i]<=temp[j] )
        {
            arr[k] = temp[i];
            i++;
        }
        else 
        {
            arr[k] = temp[j];
            j++;
        }
        k++;
        if(i>(start+end)/2)
            break;
        if(j>end)
            break;
    }
    while(j<=end)               arr[k++]=temp[j++];
    while(i<=(start+end)/2)     arr[k++]=temp[i++];

    free(temp);
}

void guibinpaixv(int *arr, int start, int end)
{
    if(start >= end)
        return;

    guibinpaixv(arr, start , (start+end)/2 );
    guibinpaixv(arr, (start+end)/2+1 , end );

    guibin(arr, start, end);

    show(arr+start, end-start+1);
}


int kuaisu(int *arr, int start, int end)
{
    int zhou=start, temp = arr[zhou];
    int low=start,high=end;

    while( low<high )
    {   
        while((arr[high] >= temp)&&(low<high)) high--;
        if(low<high)   {arr[low] = arr[high];    low++;}
        // show(arr+start, end-start+1);  
        while((arr[low] <= temp)&&(low<high)) low++;
        if(low<high)   {arr[high] = arr[low];     high--;}
        // show(arr+start, end-start+1);  
    }

    arr[low] = temp;
    zhou = low;
    return zhou;
}

void kuaisupaixv1(int *arr, int start, int end)
{
    if(start >= end)
        return;

    int zhou = kuaisu(arr, start, end);  
    show(arr+start, end-start+1);  

    kuaisupaixv1(arr, start, zhou-1);  
    kuaisupaixv1(arr, zhou+1, end);
}


int main()
{
    int arr1[10] = {3, 5, 1, -7, 4, 9, -6, 8, 10, 4};
    int arr2[10] = {3, -8, 10, 0, 4, -2, -6, 7, 0, 2};
    int arr3[10] = {7, 3, 8, -7, 9, -9, 2, -8, 10, 0};

    // int ret = chazhao(arr1, 10, 7);

    // maopao(arr1, 10);    printf("\n\n");
    // maopao(arr2, 10);    printf("\n\n");
    // maopao(arr3, 10);    printf("\n\n");

    // xvanze(arr1, 10);    printf("\n\n");
    // xvanze(arr2, 10);    printf("\n\n");
    // xvanze(arr3, 10);    printf("\n\n");

    // charu(arr1, 10);    printf("\n\n");
    // charu(arr2, 10);    printf("\n\n");
    // charu(arr3, 10);    printf("\n\n");

    // xier(arr1, 10);    printf("\n\n");
    // xier(arr2, 10);    printf("\n\n");
    // xier(arr3, 10);    printf("\n\n");

    // guibinpaixv(arr1, 0, 9);    printf("\n\n");
    // guibinpaixv(arr2, 0, 9);    printf("\n\n");
    // guibinpaixv(arr3, 0, 9);    printf("\n\n");

    // int ret = kuaisu(arr1, 0, 9);

    kuaisupaixv1(arr1, 0, 9);    printf("\n\n");
    kuaisupaixv1(arr2, 0, 9);    printf("\n\n");
    kuaisupaixv1(arr3, 0, 9);    printf("\n\n");

    return 0;
}


































// #include <stdio.h>
// #include <stdlib.h>
// #include <stdint.h>
// #include <string.h>

// // n=10 10*jiechen9
// // jiechen9 = 9*8
// // ……
// int jiecheng(int n)   // 阶乘
// {
//     if(n==1)
//         return 1;

//     return n*jiecheng(n-1);
// }

// int feibonaxie(int n)
// {
//     if(n==1||n==2)
//         return 1;

//     return feibonaxie(n-1)+feibonaxie(n-2);
// }

// int mystrstr(const char *str, char *s)
// {
//     int str_length1 = strlen(str);
//     int str_length2 = strlen(s);
//     for(int i =0;  i<=(str_length1 - str_length2);  i++)
//     {
//         int temp = i;
//         for(int j=0; s[j] != '\0' ;)
//         {
//             if( str[temp]==s[j] )
//             {
//                 temp++;
//                 j++;
//             }
//             else break;
//             if(s[j] == '\0')
//                 return i;
//         }
//     }
//     return -1;
// }

// // 求KMP
// // 传入 abcde，传出0
// // 传入 aba，传出1(a a)
// // 传入 abab，传出(ab ab)
// // ……
// int getnext(char* s)
// {
//     int Slength = strlen(s);
//     int i=0,j=0;
//     int cc = 0;
//     int len=0;
//     for( cc=1; cc<Slength ; cc++ )
//     {
//         int temp1 =0,temp2 = Slength-cc;
//         for(; temp1<cc ;)
//         {
//             if( s[temp1] == s[temp2] )
//             {
//                 temp1++;
//                 temp2++;
//             }
//             else break;
//         }
//         if(temp1>=cc)
//             len = cc;
//     }
//     return len;
// }

// int main()
// {
//     // ① 字符串函数测试
//     char str1[50] = "Magical Girl Lacie";
//     char str2[50] = {0};

//     strcpy(str2, str1);
//     memset(str2, 0, 50);

//     memcpy(str2, str1, 10);

//     strcat(str1, str2);

//     int ret;
//     ret = strlen(str1);
//     ret = strlen(str2);

//     strcpy(str1, str2);  

//     ret = strcmp(str1, str2);  

//     memset(str1, 0, 50);
//     strcpy(str1, "Magical Girl Lacie");    

//     memset(str2, 0, 50);
//     strcpy(str2, " Girl ");    

//     char* s = strstr(str1, str2);

//     int len = (int)(s - str1);
//     char c = str1[len];

//     itoa(100, str2, 10);

//     ret = atol(str2); 

//     long int retret;
//     retret = jiecheng(15);

//     ret = feibonaxie(15);

//     ret = mystrstr("gooloogooglegoloe","google");

//     ret = getnext("a");
//     ret = getnext("aa");
//     ret = getnext("aaa");
//     ret = getnext("ab");
//     ret = getnext("abc");
//     ret = getnext("abab");

//     return 0;
// }

// // // 测试例程，主要是写顺序表，链表，栈/队列……等等。熟悉下语法。


// // /*-------------------------顺序表-------------------------------*/
// // #define SeqMaxSize 10
// // // 顺序表
// // typedef struct
// // {
// //     int data[SeqMaxSize];   // 声明动态分配数组的指针
// //     int length;  // 顺序表的当前长度
// // } SeqList;
// // // 明确一下，length是当前长度，长度0，无数据；长度1，有1个数据……等等！
// // // 插入按照位序i来，如在0处插入，1处插入

// // // 在i插入e
// // int ListInsert(SeqList *L, int i, int e)
// // {
// //     // 最大10，长度 0 1 2 ……  9；长度1 代表0有数据 长度9 8有数据  长度10 代表9满！！
// //     if(SeqMaxSize<=L->length)  
// //         return 0;
// //     // 插入位序  只能0和9插入
// //     // 不是 长度2 1有数据  2无数据
// //     // 此时在2插 可以 3插 不行
// //     if(i<0||i>L->length)
// //         return 0;

// //     int temp;
// //     // 长度，比如长度1  0有数据  1无数据   在1写数据
// //     // 长度  8   7有数据  8 无数据    在8写数据
// //     // 比如长度 8 在7写数据  
// //     // 8数据 = 7
// //     for(temp=L->length ; temp>i ; temp-- )
// //     {
// //         L->data[temp] = L->data[temp-1];
// //     }
// //     L->data[i] = e;
// //     L->length++;
// //     return 1;
// // }
// // /*-------------------------顺序表-------------------------------*/


// // /*-------------------------链表-------------------------------*/    
// // struct LNode // 定义单链表结点类型
// // {
// //     int data;           // 每个节点存放一个数据元素
// //     struct LNode *next; // 指针指向下一个节点
// // };

// // typedef struct LNode LNode;
// // typedef struct LNode *LinkList;

// // struct LNode2 // 定义单链表结点类型
// // {
// //     int data;           // 每个节点存放一个数据元素
// //     struct LNode2 *next; // 指针指向下一个节点
// //     struct LNode2 *prior; // 指针指向下一个节点
// // };
// // typedef struct LNode2 LNode2;
// // typedef struct LNode2 *LinkList2;

// // int Inverse(LinkList L)
// // {
// //     if(L==NULL && L->next == NULL)
// //         return 0;

// //     LNode* L1;
// //     L1 = L->next;

// //     LNode* temp;

// //     while(L1->next != NULL)
// //     {
// //         temp = L1->next;
// //         L1->next = L1->next->next;
// //         temp->next = L->next;
// //         L->next = temp;
// //     }
// //     return 1;
// // }

// // int InsertNextDNode(LNode2 *p, int e)
// // {
// //     if(p==NULL)
// //         return 0;
// //     if(p->next == NULL)
// //     {
// //         p->next = (LNode2*)calloc(1, sizeof(LNode2));
// //         p->next->data = e;
// //         p->next->prior = p;
// //         p->next->next = NULL;
// //         return 1;
// //     }

// //     LNode2* ll2 = (LNode2*)calloc(1, sizeof(LNode2));
// //     ll2->data = e;
// //     ll2->next = p->next;
// //     p->next = ll2;
// //     ll2->prior = p;
// //     ll2->next->prior = ll2;
// //     return 1;

// // }
// // /*-------------------------链表-------------------------------*/    


// // /*-------------------------顺序队列-------------------------------*/    
// // #define MaxSizeQueue 10 // 定义栈中元素的最大个数
// // typedef struct
// // {
// //     int data[MaxSizeQueue]; // 静态数组存放栈中元素
// //     int front, rear;   // 队头指针和队尾指针
// // } SqQueue;

// // // 新元素进队列(循环队列)
// // int EnQueue(SqQueue *Q, int x)
// // {   
// //     if( (Q->front)%MaxSizeQueue == (Q->rear+1)%MaxSizeQueue )
// //         return 0;
// //     Q->data[Q->rear] = x;
// //     Q->rear = (Q->rear+1)%MaxSizeQueue;
// //     return 1;
// // }

// // // 出队列(循环队列)
// // int DeQueue(SqQueue *Q, int *x)
// // {
// //     if( (Q->front)%MaxSizeQueue == (Q->rear)%MaxSizeQueue )
// //         return 0;
// //     *x = Q->data[Q->front] ;
// //     Q->front = (Q->front+1)%MaxSizeQueue;
// //     return 1;
// // }




// // int main()
// // {
// //     /*-------------------------顺序表-------------------------------*/    
// //     SeqList S;
// //     S.length = 0;
// //     int ret = 1;
// //     ret = ListInsert(&S, 0, 1);
// //     ret = ListInsert(&S, 1, 2);
// //     ret = ListInsert(&S, 2, 3);
// //     ret = ListInsert(&S, 3, 4);
// //     ret = ListInsert(&S, 2, 5);
// //     ret = ListInsert(&S, 2, 6);
// //     ret = ListInsert(&S, 6, 7);
// //     ret = ListInsert(&S, 7, 8);
// //     ret = ListInsert(&S, 8, 9);
// //     ret = ListInsert(&S, 2, 10);
// //     ret = ListInsert(&S, 1, 11);
// //     /*-------------------------顺序表-------------------------------*/
// //     LinkList L = (LinkList)calloc(1, sizeof(LNode));
// //     LNode* temp = L;
// //     temp->next = (LNode*)calloc(1, sizeof(LNode));
// //     temp = temp->next;
// //     temp->data = 1;
// //     temp->next = (LNode*)calloc(1, sizeof(LNode));
// //     temp = temp->next;
// //     temp->data = 2;
// //     temp->next = (LNode*)calloc(1, sizeof(LNode));
// //     temp = temp->next;
// //     temp->data = 3;
// //     temp->next = (LNode*)calloc(1, sizeof(LNode));
// //     temp = temp->next;
// //     temp->data = 4;
// //     temp->next = (LNode*)calloc(1, sizeof(LNode));
// //     temp = temp->next;
// //     temp->data = 5;
// //     temp->next = (LNode*)calloc(1, sizeof(LNode));
// //     temp = temp->next;
// //     temp->data = 6;
// //     temp->next = NULL;

// //     Inverse(L);

// //     temp = L->next;
// //     L->next = L->next->next;
// //     free(temp);

// //     LinkList2 L2 = (LinkList2)calloc(1, sizeof(LNode2));
// //     LNode2* temp2 = L2;
// //     temp2->prior = NULL;
// //     temp2->next = (LNode2*)calloc(1, sizeof(LNode2));
// //     temp2->next->prior = temp2;
// //     temp2 = temp2->next;
// //     temp2->data = 1;
// //     temp2->next = (LNode2*)calloc(1, sizeof(LNode2));
// //     temp2->next->prior = temp2;    
// //     temp2 = temp2->next;
// //     temp2->data = 2;
// //     temp2->next = NULL;
    
// //     InsertNextDNode(temp2,10);
// //     InsertNextDNode(temp2,20);

// //     /*-------------------------链表-------------------------------*/  

// //     /*-------------------------顺序队列-------------------------------*/    
// //     SqQueue quq;
// //     quq.front = 0;
// //     quq.rear = 0;

// //     ret = EnQueue(&quq, 1);
// //     ret = EnQueue(&quq, 2);
// //     ret = EnQueue(&quq, 3);
// //     ret = EnQueue(&quq, 4);
// //     ret = EnQueue(&quq, 5);
// //     ret = EnQueue(&quq, 6);
// //     ret = EnQueue(&quq, 7);
// //     ret = EnQueue(&quq, 8);
// //     ret = EnQueue(&quq, 9);
// //     ret = EnQueue(&quq, 10);
// //     ret = EnQueue(&quq, 11);

// //     int x;
// //     ret = DeQueue(&quq, &x);
// //     ret = DeQueue(&quq, &x);
// //     ret = DeQueue(&quq, &x);
// //     ret = DeQueue(&quq, &x);
// //     ret = DeQueue(&quq, &x);
// //     ret = DeQueue(&quq, &x);
// //     ret = DeQueue(&quq, &x);
// //     ret = DeQueue(&quq, &x);
// //     ret = DeQueue(&quq, &x);
// //     ret = DeQueue(&quq, &x);
// //     ret = DeQueue(&quq, &x);   
    
// //     /*-------------------------顺序队列-------------------------------*/  

// //     return 0;
// // }

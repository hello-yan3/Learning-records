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
 * @brief 顺序表
 * @attention：
 * 顺序表的基本概念
 * 1. 顺序表：用顺序存储的方式实现线性表。顺序存储，将逻辑上相邻的元素存储在相邻的物理位置上。
 * 2. 特点：
 * * 随机访问，即可以在 O(1) 时间内找到第 i 个元素。
 * * 存储密度高，每个节点只存储数据元素。
 * * 拓展容量不方便（即使使用动态分配的方式实现，拓展长度的时间复杂度也比较高，因为需要把数据复制到新的区域）。
 * * 插入删除操作不方便，需移动大量元素：O(n)
 */
/***********************动态实现***********************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define InitSize 5 // 默认的最大长度

/** 
 * @note
 * 顺序表(静态)结构体:
 * 1. 静态数组(动态指针);
 * 2. 数组最大长度(动态);
 * 3. 数组当前长度;
 * @note
 * ！操作核心！：
 * 1. 更改顺序表内容;
 * 2. 更改顺序表长度(注意长度从1开始计算);
 * 3. 若销毁顺序表，注意释放占用内存空间;
 * @note
 * 注意！
 * 后面发现，插入/删除元素，容易搞混，理论位置/实际位置(从1开始)
 * 所以自己写程序，放纵一些，
 * 元素temp_i直接=i-1；length = L.length-1得了……(相当于顺序表从0开始)
 * 传入/传出记着+-1！
 * @note
 * 需要执行判断：
 * 元素序号过小(<1)/过大(>顺序表长度) 或是 顺序表已满
 */
typedef struct
{
    int *data;   // 声明动态分配数组的指针
    int MaxSize; // 顺序表的最大容量
    int length;  // 顺序表的当前长度
} SeqList;

void InitList(SeqList &L);                  // 初始化顺序表
void DestroyList(SeqList &L);               // 销毁表，释放其占用的内存空间
bool ListInsert(SeqList &L, int i, int e);  // 在表 L 的第 i 个位置插入指定元素 e 。
bool ListDelete(SeqList &L, int i, int &e); // 删除表 L 中第 i 个位置的元素，并用 e 返回删除元素的值。
int GetElem(SeqList L, int i);              // 按位查找
int LocateElem(SeqList L, int e);           // 按值查找
int GetLength(SeqList &L);                  // 求表长
void PrintList(SeqList &L);                 // 打印表
void ClearList(SeqList &L);                 // 清空顺序表
bool isEmpty(SeqList &L);                   // 判断是否为空

/**
 * @brief 
 * 初始化顺序表
 * @param 传入参数：
 * 1. 顺序表(引用)
 * @note 判断
 * 无
 * @note 操作
 * 0. 顺序表分频一段内存空间(动态);
 * 1. 顺序表每个元素清零(可选);
 * 2. 顺序表长度 = 0; 顺序表最大长度 = 初始化长度;
 */
void InitList(SeqList &L)
{
    // 用malloc函数申请一片连续的存储空间
    L.data = (int *)malloc(InitSize * sizeof(int));
    L.length = 0;
    L.MaxSize = InitSize;
}

/**
 * @brief 
 * 销毁表顺序表
 * @param
 * 传入参数：
 * 1. 顺序表(引用)
 * @note 判断
 * 顺序表长度 = 0，表面已经被销毁
 * @note 操作
 * 0. 顺序表长度 = 0;
 * 1. 释放顺序表占用内存空间(动态);
 */
void DestroyList(SeqList &L)
{
    if (L.length == 0)
    {
        return; // 顺序表已经被销毁，直接返回
    }

    free(L.data); // 释放顺序表所占用的内存空间

    L.length = 0;
}


/**
 * @brief 
 * 增加动态数组的长度
 * @param
 * 传入参数：
 * 1. 顺序表(引用) 2. 新顺序表长度
 * @note 判断
 * 无
 * @note 操作
 * 0. 临时指针指向旧的顺序表;
 * 1. 动态分频新顺序表内存空间;
 * 2. 旧顺序表值赋给新顺序表;
 * 3. 顺序表长度设为新的长度
 * 4. 释放原顺序表内存空间
 */
void IncreaseSize(SeqList &L, int len)
{
    int *p = L.data;

    L.data = (int *)malloc((L.MaxSize + len) * sizeof(int));
    for (int i = 0; i < L.length; i++)
        L.data[i] = p[i]; // 将数据复制到新区域

    // 使用 realloc() 函数实现
    // L.data = (int *)realloc(L.data ,(L.MaxSize + len) * sizeof(int));
    // 注意使用 realloc() 不能 free(p);

    L.MaxSize = L.MaxSize + len; // 顺序表最大长度增加len
    free(p);                     // 释放原来的内存空间
}

/**
 * @brief 
 * 在顺序表i位置插入e
 * @note 执行判断：
 * 1. 顺序表长度过小/过大 或是 顺序表已满
 * @note 操作：
 * 1. 从length → i，元素后移 (j=length-1;   data[j+1] = data[j])
 * 2. 插入新元素
 * 
 * 3. 长度重新设定
 */
bool ListInsert(SeqList &L, int i, int e)
{
    if (i < 1 || i > L.length + 1) // 判断i的范围是否有效
        return false;
    if (L.length >= L.MaxSize) // 判断存储空间是否已满
        return false;

    for (int j = L.length; j >= i; j--) // 将第i个元素之后的元素后移
        L.data[j] = L.data[j - 1];
    L.data[i - 1] = e; // 在位置i处放入e
    L.length++;        // 长度+1
    return true;
}

// 删除顺序表i位置的数据并存入e
bool ListDelete(SeqList &L, int i, int &e)
{
    if (i < 1 || i > L.length) // 判断i的范围是否有效
        return false;

    e = L.data[i - 1];                 // 将被删除的元素赋值给e
    for (int j = i; j < L.length; j++) // 将第i个位置后的元素前移
        L.data[j - 1] = L.data[j];
    L.length--;
    return true;
}

// 按位查找
int GetElem(SeqList L, int i)
{
    return L.data[i - 1];
}

// 按值查找
int LocateElem(SeqList L, int e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
        {
            return i + 1; // 数组下标为i的元素值等于e，返回其位序i+1 //退出循环，说明查找失败
        }
    }
    return 0;
}

// 获取表长
int GetLength(SeqList &L)
{
    return L.length;
}

// 输出顺序表
void PrintList(SeqList &L)
{
    printf("\n");
    for (int i = 0; i < L.length; i++)
    {
        printf("%d:%d\t", i + 1, L.data[i]);
    }
    printf("\n");
}

// 清空顺序表
void ClearList(SeqList &L)
{
    for (int i = 0; i < L.length; i++)
    {
        L.data[i] = NULL;
    }
    L.length = 0;
}

// 判断是否为空
bool isEmpty(SeqList &L)
{
    return L.length == 0 ? true : false;
}

/* 测试 */
int main()
{
    SeqList L; // 声明一个顺序表
    int i;

    InitList(L); // 初始化顺序表

    // 插入测试
    ListInsert(L, 1, 1);
    ListInsert(L, 2, 2);
    ListInsert(L, 3, 3);
    ListInsert(L, 4, 4);
    ListInsert(L, 1, 1);
    ListInsert(L, 2, 2);

    // 判断表是否为空
    // 链表是否为空? 0 | 0(否) 1(是) 
    printf("链表是否为空? %d | 0(否) 1(是) \n", isEmpty(L));

    // 输出
    // 1:1     2:2     3:1     4:2     5:3     6:4
    PrintList(L);

    // 删除测试
    int e = -1;
    bool flag = ListDelete(L, 1, e);
    if (flag)
    {
        // 删除元素为: 1
        printf("删除元素为: %d\n", e);
    }
    else
    {
        printf("位序不合法，删除失败!\n");
    }

    // 输出
    // 1:2     2:1     3:2     4:3     5:4
    PrintList(L);

    // 按位查找测试
    // 该位置处的值为: 2
    printf("该位置处的值为: %d\n", GetElem(L, 3));

    // 按值查找测试
    // 该元素的位置为: 2
    printf("该元素的位置为: %d\n", LocateElem(L, 1));

    // 按值查找测试
    // 该元素的位置为: 0     (表示没有找到元素)
    printf("该元素的位置为: %d\n", LocateElem(L, 5));

    // 输出
    // 1:2     2:1     3:2     4:3     5:4
    PrintList(L);

    // 输出表长
    // 链表的长度为:  5
    printf("链表的长度为:  %d\n", GetLength(L));

    // 清空表
    ClearList(L);

    // 无输出
    PrintList(L);

    // 判断表是否为空
    // The list is empty? 1.
    printf("链表是否为空? %d | 0(否) 1(是) \n", isEmpty(L));
    return 0;
}
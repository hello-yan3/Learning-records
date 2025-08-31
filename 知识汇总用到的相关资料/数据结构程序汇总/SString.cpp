/**
 * @brief 串
 * @attention：
 * 串的基本概念
 * 串：即字符串（String）是由零个或多个字符组成的有限序列。
 * 串的长度：中字符的个数n，n = 0 时的串称为空串。
 * 子串：串中任意个连续的字符组成的子序列。
 * 主串：包含子串的串。
 * 字符在主串中的位置：字符在串中的序号。
 * 子串在主串中的位置：子串的第一个字符在主串中的位置 。
 */
/**
 * @brief 串
 * @attention：
 * 串
 */
/***********************串***********************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXLEN 255

typedef struct
{
    char ch[MAXLEN];
    int length;
} SString;

bool InitSString(SString &S);                              // 串的初始化
bool StrAssign(SString &S, char c);                        // 赋值操作
int StrLength(SString S);                                  // 求串的长度
bool SubString(SString &Sub, SString S, int pos, int len); // 求主串S由位序pos开始len长度的子串存入到串Sub中
int StrCompare(SString S, SString T);                      // 比较S与T的大小。若S>T，则返回值大于0；若S=T，则返回值等于0；若S<T，则返回值小于0
int Index(SString S, SString T);                           // 定位串T在串S中的位置，若无法定位则返回0
int Index_Simple(SString S, SString T);                    // 在主串S中找到与模式串T相同的子串并返回其位序，否则返回0
int Index_KPM(SString S, SString T);                       // KPM算法，求主串S中模式串T的位序，没有则返回0
void getNext(SString T, int next[]);                       // 获取模式串T的next[]数组
void ShowString(SString S);                                // 输出串

// 串的初始化
bool InitSString(SString &S)
{
    S.length = 0;
    return true;
}

// 求串的长度
int StrLength(SString S)
{
    return S.length;
}

// 串赋值
bool StrAssign(SString &S, char c)
{
    if (S.length + 1 == MAXLEN)
    {
        return false;
    }
    S.ch[S.length + 1] = c;
    S.length++;
    return true;
}

// 求主串S由位序pos开始len长度的子串存入到串Sub中
bool SubString(SString &Sub, SString S, int pos, int len)
{
    if (pos + len - 1 > S.length)
        return false;

    for (int i = pos; i < pos + len; i++)
        Sub.ch[i - pos + 1] = S.ch[i];

    Sub.length = len;
    return true;
}

// 比较S与T的大小。若S>T，则返回值大于0；若S=T，则返回值等于0；若S<T，则返回值小于0
int StrCompare(SString S, SString T)
{
    for (int i = 1; i <= S.length && i <= T.length; i++)
    {
        if (S.ch[i] != T.ch[i])
            return S.ch[i] - T.ch[i];
    }
    // 扫描过的所有字符都相同，则长度长的串更大
    return S.length - T.length;
}

// 定位串T在串S中的位置，若无法定位则返回0
int Index(SString S, SString T)
{
    // 获得串S/T长度，分别为n/m
    int i = 1, n = StrLength(S), m = StrLength(T);
    SString sub; // 用于暂存数据

    // 当 i>n-m 时，S中不可能存在子串T，返回0
    while (i <= n - m + 1)
    {
        // 求主串S由位序i开始m长度的子串存入到串sub中
        SubString(sub, S, i, m);
        // 比较S与T的大小，若相等，返回0
        if (StrCompare(sub, T) != 0)
            ++i;
        else
            return i;
    }
    return 0;
}

// 在主串S中找到与模式串T相同的子串并返回其位序，否则返回0
int Index_Simple(SString S, SString T)
{
    // i/j分别用于串S/T匹配计数(S.ch[i++] == T.ch[j++]，表示串字符相同)
    // k用于S串寻找定位，k由串首遍历到串尾
    int k = 1;
    int i = k, j = 1;
    while (i <= S.length && j <= T.length)
    {
        if (S.ch[i] == T.ch[j])
        {
            ++i;
            ++j;
        }
        else
        {
            k++;
            i = k;
            j = 1;
        }
    }
    if (j > T.length)
        return k;
    else
        return 0;
}

// KPM算法，求主串S中模式串T的位序，没有则返回0
int Index_KPM(SString S, SString T)
{
    int i = 1, j = 1;
    int next[T.length + 1];
    getNext(T, next);
    while (i <= S.length && j <= T.length)
    {
        if (j == 0 || S.ch[i] == T.ch[j])
        {
            ++i;
            ++j;
        }
        else
            j = next[j];
    }
    if (j > T.length)
        return i - T.length;
    else
        return 0;
}

// 获取模式串T的next[]数组
void getNext(SString T, int next[])
{
    int i = 1, j = 0;
    next[1] = 0;
    while (i < T.length)
    {
        if (j == 0 || T.ch[1] == T.ch[j])
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else
            j = next[j];
    }
}

// 输出串
void ShowString(SString S)
{
    for (int i = 1; i <= S.length; i++)
    {
        printf("%c", S.ch[i]);
    }
    printf("\n");
}

int main()
{
    SString S, T;
    int pos = 0;
    InitSString(S);

    for (int i = 0; i < 10; i++)
    {
        StrAssign(S, (char)('a' + i));
    }

    printf("此时的字符串S为");
    ShowString(S);

    printf("字符串S长度为: %d\n", StrLength(S));

    printf("求S位序为3，长度为4的子串");
    SubString(T, S, 3, 4);
    ShowString(T);

    pos = Index(S, T);
    printf("子串T的位置为%d\n", pos);

    pos = Index_Simple(S, T);
    printf("子串T的位置为%d\n", pos);
    
    pos = Index_KPM(S, T);
    printf("子串T的位置为%d\n", pos);

    return 0;
}
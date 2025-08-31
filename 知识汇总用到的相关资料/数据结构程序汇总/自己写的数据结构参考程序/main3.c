#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// n=10 10*jiechen9
// jiechen9 = 9*8
// ……
int jiecheng(int n)   // 阶乘
{
    if(n==1)
        return 1;

    return n*jiecheng(n-1);
}

int feibonaxie(int n)
{
    if(n==1||n==2)
        return 1;

    return feibonaxie(n-1)+feibonaxie(n-2);
}

int mystrstr(const char *str, char *s)
{
    int str_length1 = strlen(str);
    int str_length2 = strlen(s);
    for(int i =0;  i<=(str_length1 - str_length2);  i++)
    {
        int temp = i;
        for(int j=0; s[j] != '\0' ;)
        {
            if( str[temp]==s[j] )
            {
                temp++;
                j++;
            }
            else break;
            if(s[j] == '\0')
                return i;
        }
    }
    return -1;
}

// 求KMP
// 传入 abcde，传出0
// 传入 aba，传出1(a a)
// 传入 abab，传出(ab ab)
// ……
int getnext(char* s)
{
    int Slength = strlen(s);
    int i=0,j=0;
    int cc = 0;
    int len=0;
    for( cc=1; cc<Slength ; cc++ )
    {
        int temp1 =0,temp2 = Slength-cc;
        for(; temp1<cc ;)
        {
            if( s[temp1] == s[temp2] )
            {
                temp1++;
                temp2++;
            }
            else break;
        }
        if(temp1>=cc)
            len = cc;
    }
    return len;
}

int main()
{
    // ① 字符串函数测试
    char str1[50] = "Magical Girl Lacie";
    char str2[50] = {0};

    strcpy(str2, str1);
    memset(str2, 0, 50);

    memcpy(str2, str1, 10);

    strcat(str1, str2);

    int ret;
    ret = strlen(str1);
    ret = strlen(str2);

    strcpy(str1, str2);  

    ret = strcmp(str1, str2);  

    memset(str1, 0, 50);
    strcpy(str1, "Magical Girl Lacie");    

    memset(str2, 0, 50);
    strcpy(str2, " Girl ");    

    char* s = strstr(str1, str2);

    int len = (int)(s - str1);
    char c = str1[len];

    itoa(100, str2, 10);

    ret = atol(str2); 

    long int retret;
    retret = jiecheng(15);

    ret = feibonaxie(15);

    ret = mystrstr("gooloogooglegoloe","google");

    ret = getnext("a");
    ret = getnext("aa");
    ret = getnext("aaa");
    ret = getnext("ab");
    ret = getnext("abc");
    ret = getnext("abab");

    return 0;
}


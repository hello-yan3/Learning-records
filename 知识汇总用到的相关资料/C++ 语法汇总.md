# 目录
[TOC]



## 主体参照：[C++ 教程 | 菜鸟教程](https://www.runoob.com/cplusplus/cpp-tutorial.html) 这里对该教程做一定的完善与汇总

## 一、C++ 基础语法

### 0. [C语言语法知识点](.\C语言 语法汇总)

C++ 是 C 的一个超集，事实上，**任何合法的 C 程序都是合法的 C++ 程序**。
**部分语法将在C语言语法汇总中记录，本文档中主要记录C与C++区别；**

二者主要区别 (自己写的，面试可能问)：

> 思想上：C++是面向对象的语言，C语言是面向过程的结构化编程语言
>
> 语法上：
>
> 1）C++支持面向对象编程，支持类与对象；
> 2）C++支持STL容器，包括顺序式容器、关联式容器等等；
> 3）C++支持范式编程，比如函数模版、支持命名空间、且输入输出方法与C不同，支持函数传参默认值、函数重载、引用传递等等内容，此外动态内存分配方法也与C不同；

**[关于 C++ 中的 extern "C"](https://zhuanlan.zhihu.com/p/123269132)**： 

```C++
//incvxworks.h
#ifndef __INCvxWorksh
#define __INCvxWorksh

#ifdef __cplusplus
extern "C" {
#endif

	/*...*/

#ifdef __cplusplus
}
#endif

#endif /* __INCvxWorksh */
```

`__cplusplus` 宏，是用来识别编译器的。当前代码编译时，若将代码作为 `C++` 进行编译，则定义了 `__cplusplus` 宏。

被 `extern "C" ` 修饰的变量和函数是**按照 C 语言方式**编译和连接的。



### 1. [C++ 简介](https://www.runoob.com/cplusplus/cpp-intro.html)

包括C++的历史，特性，迭代及标准化等等；



### 2. [C++ 环境设置](https://www.runoob.com/cplusplus/cpp-environment-setup.html)

直接看[VSCode 配置C/C++，单文件多文件](https://www.bilibili.com/video/BV1YL411L7Sg?p=6)
文档参考：[VSCode安装配置讲解文档](.\知识汇总用到的相关资料\VSCode安装配置讲解文档.md)

更多C++开发环境，可以参考[C++环境设置](https://www.runoob.com/cplusplus/cpp-environment-setup.html)



### 3. [C++ 最基本格式](https://www.runoob.com/cplusplus/cpp-tutorial.html)

```C++
#include <iostream>
using namespace std;

int main()
{
    cout << "Hello, world!" << endl;
    return 0;
}
```

**注：** `main` 函数的返回值返回给主调进程，一般约定返回 0 值时代表程序运行无错误，其它值均为错误；
`void main` 可以不写`return`或者是 `return;`，在**检查不**是很**严格**的**编译器**(VC,  VS)中，`void main` 是**允许**的。在**检查严格**的**编译器**下(gcc,  g++)， 要求 `main` 函数的返回值**必须为 `int` 型**。
现在已很少使用 `void main`;

**注：**在C语言中，`int main(void)` 指的是此函数的参数为空，不能传入参数；`int main()`表示 是否接受参数保持沉默；在C++中，`int main(void)` 和`int main()`相同，表示不能传入参数。

**注：**`#include <iostream.h>`为VC6.0标准，现**已淘汰**；

**补充1：**[**评论笔记1**](https://www.runoob.com/cplusplus/cpp-tutorial.html)讲解`\n`和`endl`区别；
"\n" 表示内容为一个回车符的字符串；std::endl 输出一个换行符，并立即刷新缓冲区。
例如：`std::cout << std::endl;`相当于`std::cout << '\n' << std::flush;`

**补充2：**[**评论笔记2，3**](https://www.runoob.com/cprogramming/c-program-structure.html)给出了**DOS 窗口自动关闭**的两种解决方法：
**解决方法1：**

> 加入头文件 `#include <stdlib.h>` 
> 在 **`return 0;`** 前加入 **`system("pause");`** 语句

**更多解决方法：**详见**[评论笔记3](https://www.runoob.com/cplusplus/cpp-environment-setup.html)**



### 4. [C++ 基本语法](https://www.runoob.com/cplusplus/cpp-basic-syntax.html)

基本等同于**[C语言](.\C语言 语法汇总)**。



### 5. [C++ 命名空间](https://www.runoob.com/cplusplus/cpp-namespaces.html)

#### 5.1 命名空间含义及作用

作为附加信息来**区分不同库中相同名称**的函数、类、变量；
例：a写 xyz() 的函数，标准库中也有 xyz() 的函数；编译器需要通过命名空间进行区别；

#### 5.2 命名空间定义及使用

命名空间定义：使用关键字 **`namespace`**；
命名空间变量的使用：在前面加上命名空间的名称；

```c++
/* 命名空间的定义 */
namespace name {
   /* 代码声明  */
}

/* 命名空间的使用 */
name::code;  // code 可以是变量或函数

/**************** 实例 ****************/
#include <iostream>
using namespace std;
 
// 第一个命名空间
namespace first_space{
   void func(){
      cout << "Inside first_space" << endl;
   }
}
// 第二个命名空间
namespace second_space{
   void func(){
      cout << "Inside second_space" << endl;
   }
}

int main ()
{
   first_space::func();       // 调用第一个命名空间中的函数
   second_space::func();      // 调用第二个命名空间中的函数
 
   return 0;
}
```

实例：**[定义命名空间 小节](https://www.runoob.com/cplusplus/cpp-namespaces.html)**

#### 5.3 通过using指令使用命名空间

使用 `using namespace `指令，之后的程序将使用**指定的命名空间**中的名称，
如：`using namespace std;`，后续代码将使用 **std** 中的名称。

`using` 指令也可以用来**指定命名空间中的特定项目**，
如：`using std::cout;`，后续使用` cout `时就可以不用加上命名空间名称作为前缀，但是 **std 命名空间**中的**其他项目**仍然需要加上命名空间名称作为前缀，如：`using std::cout;`，此时的输出语句：`cout << "std::endl is used with std!" << std::endl;`

实际开发**尽量不要使用** `using namespace std;`等**直接引入整个命名空间**，建议使用：`std::cout << "Hello World" << std::endl;`等直接由命名空间组合起来的全称

#### 5.4 [命名空间的作用域及嵌套](https://www.runoob.com/cplusplus/cpp-namespaces.html)
详见 **[不连续的命名空间、嵌套的命名空间、命名空间及全局变量局部变量优先级(评论笔记1、2)](https://www.runoob.com/cplusplus/cpp-namespaces.html)**



### 6. [C++ 数据类型](https://www.runoob.com/cplusplus/cpp-data-types.html)

#### 6.1 基本数据类型

**基本数据类型：**

| 类型                | 关键字 |
| :------------------ | :----- |
| 布尔型**（仅C++）** | bool   |
| 字符型              | char   |
| 整型                | int    |
| 浮点型              | float  |
| 双浮点型            | double |
| 无类型              | void   |

**类型修饰符：**

signed、unsigned；short、long；

**数据大小：**

| 类型               | 位                          | 范围                                                         |
| :----------------- | :-------------------------- | :----------------------------------------------------------- |
| bool               | 1 个字节                    | 0 到 1                                                       |
| char               | 1 个字节                    | -128 到 127 或者 0 到 255                                    |
| unsigned char      | 1 个字节                    | 0 到 255                                                     |
| signed char        | 1 个字节                    | -128 到 127                                                  |
| int                | 2 (32位) 或 4 (64位) 字节   | -32,768 到 32,767 或 -2,147,483,648 到 2,147,483,647         |
| unsigned int       | 2 (32位) 或 4 (64位) 字节   | 0 到 65,535 或 0 到 4,294,967,295                            |
| signed int         | 2 (32位) 或 4 (64位) 字节   | -32,768 到 32,767 或 -2,147,483,648 到 2,147,483,647         |
| short int          | 1 (32位) 或 2 (64位) 字节   | -128 到 127 或 -32768 到 32767                               |
| unsigned short int | 1 (32位) 或 2 (64位) 字节   | 0 到 255 或 0 到 65,535                                      |
| signed short int   | 1 (32位) 或 2 (64位) 字节   | -128 到 127 或 -32768 到 32767                               |
| long int           | 4 (32位) 或 8 (64位) 字节   | -2,147,483,648 到 2,147,483,647 或<br />-9,223,372,036,854,775,808 到 9,223,372,036,854,775,807 |
| signed long int    | 4 (32位) 或 8 (64位) 字节   | -2,147,483,648 到 2,147,483,647 或<br />-9,223,372,036,854,775,808 到 9,223,372,036,854,775,807 |
| unsigned long int  | 4 (32位) 或 8 (64位) 字节   | 0 到 4,294,967,295 或 0 到 18,446,744,073,709,551,615        |
| float              | 4 个字节                    | 单精度型占4个字节（32位）内存空间，<br />1位符号，8位指数，23位小数；± 3.4e ± 38 (6 位小数) |
| double             | 8 个字节                    | 双精度型占8 个字节（64位）内存空间，<br />1位符号，11位指数，52位小数；± 1.7e ± 308 (15位小数) |
| long double        | 16 个字节                   | 长双精度型 16 个字节（128位）内存空间，± 1.2e ± 4932 (19 位小数) |
| wchar_t            | 2 (32位) 或 4 (64位) 个字节 | 1 个记录宽字符的数据类型；`typedef int wchar_t;`<br />-2,147,483,648 到 2,147,483,647 |
| size_t             | 4 (32位) 或 8 (64位) 个字节 | 1 个记录大小的数据类型；`typedef unsigned long int size_t;`<br />0 到 18,446,744,073,709,551,615 |
| ptrdiff_t          |                             | 1 个记录两个指针之间的距离的数据类型；                       |

关于wchar_t、size_t、ptrdiff_t详见**[评论笔记5](https://www.runoob.com/cplusplus/cpp-data-types.html)**

这里简单解释`wchar_t`宽字符，因为`char`仅 256 bytes，支持字符极为有限，所以引入了宽字符 `wchar_t`；中文**汉字使用宽字符 `wchar_t`记录**。详见**[评论笔记12](https://www.runoob.com/cplusplus/cpp-strings.html)**

```C++
cout << u8"utf-8 字符串" << endl;   //控制台字符类型为UTF-8时，正常输出，输出乱码：utf-8 瀛楃涓?
wcout << L"Unicode 字符串" << endl; //控制台字符类型为Unicode时，正常输出，输出：Unicode 字符串
```

#### 6.2 typedef 声明

可以使用 **`typedef`** 为一个已有的类型取一个新的名字，详见 **[C语言语法介绍 18章节](.\C语言 语法汇总)**
**typedef 与 #define 对比**
[**正文+评论笔记1、2**](https://www.runoob.com/cprogramming/c-typedef.html)、**[评论笔记7](https://www.runoob.com/cplusplus/cpp-data-types.html)**

使用`using`达到`typedef`效果，详见**[评论笔记11](https://www.runoob.com/cplusplus/cpp-data-types.html)**

#### 6.3 enum枚举类型

详见 **[C语言语法介绍 19章节](.\C语言 语法汇总)**

#### 6.4 数据基本类型的转换

基本等同于**[C语言](.\C语言 语法汇总)**。



### 7. [C++ 变量](https://www.runoob.com/cprogramming/c-variables.html)

#### 7.1 变量定义

基本等同于**[C语言](.\C语言 语法汇总)**。

**注意：**C++支持两种初始化方式：拷贝初始化：**int a = 5;**   直接初始化：**int a(5);** 

**注意：**C++ 中关键字更多：**[C++ 的关键字（保留字）完整介绍](https://www.runoob.com/w3cnote/cpp-keyword-intro.html)**。

#### 7.2 [C++ 变量作用域](https://www.runoob.com/cplusplus/cpp-variable-scope.html)

基本等同于C语言，详见：**[C语言语法介绍 12.5 static 存储类](.\C语言 语法汇总)**。

**注意：**C语言，在函数内，优先使用局部变量值；在C++，可以通过**`::`**访问全局变量。

```C++
int a = 200;//定义一个全局变量

int main()
{
    int a = 30;
    cout <<"a = "<<a << endl;        // a=30
    cout <<"::a = "<<::a << endl;    // a=200
    
    return 0;
}
```

#### 7.3 [C++ 变量修饰符类型](https://www.runoob.com/cplusplus/cpp-modifier-types.html)

基本等同于C语言，详见：**[C语言语法介绍 8.1、10.4等](.\C语言 语法汇总)**。



### 8. [C++ 常量](https://www.runoob.com/cplusplus/cpp-constants-literals.html)

基本等同于C语言，详见**[C语言 8.1 节](.\C语言 语法汇总)**。

此外，C++中增加的一些常量类型：
**bool常量**：`true` 值代表真，`false` 值代表假；
数值上：`true`表示`1`，`false`表示`0`。
强制类型转化时，`0`转化为`false`，`非0`转化为`true`；
但是在C++中，`1==true`，返回值为`true`，`非1==true`，返回值为`false`；

其他内容详见**[C语言 9 节、6.3节、17.6节等等](.\C语言 语法汇总)**。



### 9. C++ 头文件及[输入输出流](https://www.runoob.com/cplusplus/cpp-basic-input-output.html)
#### 9.1 C++ 头文件

**注意：**  **C++中标准头文件不带后缀 .h ，使用前缀 c 进行标记**
`#include <iostream.h>`**必须写为**`#include <iostream>`
`#include <stdio.h>`应该写为`#include <cstdio>`
`#include <math.h>`应该写为`#include <cmath>`、`#include <string.h>`应该写为`#include <cstring>`  ……

这些是**继承的c的头文件**，用来**区分c++自己的头文件**；
C++中可以使用`#include <math.h>`来直接使用c的头文件，但是不赞成使用该方法，建议使用`#include <cmath>`

#### 9.2 C++ 输入输出流

C++ 提供了两种类型的输入输出：
① C 风格输入输出[**详见C语言 7节输入输出**](.\C语言 语法汇总)，这里不做阐述；
② C++引入的 \<iostream> 输入输出；

| 头文件     | 函数和描述                                                   |
| :--------- | :----------------------------------------------------------- |
| \<iostream> | 该文件定义了 **cin、cout、cerr** 和 **clog** 对象，分别对应于标准输入流、标准输出流、非缓冲标准错误流和缓冲标准错误流。 |
| \<iomanip>  | 该文件通过所谓的参数化的流操纵器（比如 **setw** 和 **setprecision**），来声明对执行标准化 I/O 有用的服务。 |
| \<fstream>  | 该文件为用户控制的文件处理声明服务。我们将在文件和流的相关章节讨论它的细节。 |

**注意：**上述头文件所定义的对象，均在 **std** 命名空间内，需要`using namespace std;`（或者使用：std::cout，std::setw()等等）；

```C++
#include <iostream>

// 标准输入流（cin）
int main( )
{
    char name[50];
    short age;
    std::cin >> name >> age;    // 遇“空格”、“Tab”、“回车”都结束
    // cin 是与流提取运算符 >> 结合使用的；
    // >> 运算符被重载来输入内置类型（整型、浮点型、double 型、字符串和指针）的数据项
    // 流插入运算符 >> 在一个语句中可以多次使用；
    
    /******* 字符串的输入 *******/
    // 此外，可通过 cin.get()、 cin.getline(); 等等实现输入；（ 类似 C语言 getchar()函数 ）
    // cin.getline() 是在输入一段字符完成后开始读取数据（注意，是输入完成后，以Enter为结束标志）
    char ch, X[20];
    cin.getline(X,20);          // 以cin.getline形式输入, 可以接收空格
                                // cin.getline(接受字符串到X,接受个数20,结束字符) ,结束字符默认'\0'
    cin.get(ch);                // 或者ch=cin.get(); 只能获取一个字符
    cin.get(X,20);              // 类似getline。可以输入多个单词，中间空格隔开

    // 以下函数需包含 #include<string>
    // 上述函数属于istream流，以下函数属于string流
    #include<string>
    string str;
    getline(cin,str);           // 和cin.getline()类似，可以接收空格
    
    gets(str);                  // 和cin.get()类似，可以接收空格
    ch=getchar();               // 接受一个字符，类似cin.get(ch);
}
```
**更多字符串输入方法详见[评论笔记10](https://www.runoob.com/cplusplus/cpp-strings.html)**

```C++
#include <iostream>

// 标准输出流(cout)
int main
{
    char str[] = "Hello C++";
    srd::cout << "Value of str is : " << str << std::endl;
    // cout 是与流插入运算符 << 结合使用的；
    // << 运算符被重载来输出内置类型（整型、浮点型、double 型、字符串和指针）的数据项
    // 流插入运算符 << 在一个语句中可以多次使用；
    // endl 用于在行末添加一个换行符，并立即刷新缓冲区。
    return 0;   // 下面省略return 0;
}

// 标准错误流（cerr）
int main()
{
    char str[] = "Unable to read...";
    std::cerr << "Error message: " << str << std::endl;
}

// 标准日志流（clog）
int main()
{
    char str[] = "Unable to read...";
    std::clog << "Error message: " << str << std::endl;
}
```

**cout、cerr 和 clog 区别：**

> **首先解释缓冲区概念：**缓冲区的目的，就是减少刷屏的次数——比如，程序输出一篇文章。不带缓冲，就会每写一个字母，就输出一个字母，然后刷屏。有了缓冲，将会看到若干句子“同时”就出现在了屏幕上（由内存翻新到显存，然后刷新屏幕）。
>
> 1、cout为标准输出，经过缓冲后输出，默认情况下是显示器，并且可以重新定向；
>
> 2、cerr为标准错误，不经过缓冲而直接输出，一般用于迅速输出出错信息。它不被缓冲，错误消息可以直接发送到显示器，而无需等到缓冲区或者新的换行符时。
>
> 3、clog为标准日志，经过缓冲后输出。
>
> 4、"\n" 表示内容为一个回车符的字符串；std::endl 输出一个换行符，并立即刷新缓冲区。
>       例如：std::cout << std::endl;    相当于std::cout << '\n' << std::flush;
>       当向cout流插入一个endl，无论缓冲区状态，立即输出流中所有数据，然后插入一个换行符。

#### 9.3 C++ 的[格式化输出](https://www.jianshu.com/p/f0022d8aee98)

| 操纵运算子        | 作用                              |
| ----------------- | --------------------------------- |
| hex               | 设置 16 进制输出                  |
| dec               | 设置 10 进制输出                  |
| oct               | 设置 8 进制输出                   |
| setfill( 'x' )    | 设填充字符为x                     |
| setprecision( n ) | 设显示有效数字为 n 位（四舍五入） |
| setw( n )         | 设域宽为n个字符 (保证输出宽度为n) |
| setbase(n)        | 设输出结果为n进制                 |

注意以上操作运算子**只作用于紧随其后的部分**；以上操作算子均定义在 **std 命名空间** 内。

```C++
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // setw(int n): 通俗地讲就是预设宽度。
    cout << setw( 3 ) << 1 << setw( 3 ) << 10 << setw( 3 ) << 100 << setw( 3 ) << 1000 << endl; 
    // std::cout  << std::setw( 3 ) << 1 << std::setw( 3 ) << 10 << std::endl; 
    // 输出："  1 101001000"
    
    // setfill(char c): 就是在预设宽度中如果已存在没用完的宽度大小，则用设置的字符c填充。
    cout << setfill('x') << setw(5) << 255 << endl;
    // std::cout << std::setfill('x') << std::setw(5) << 255 << std::endl;
    // 输出："xx255"
    
    // setbase(int n): 将数字转换为 n 进制。
    cout << setbase(8) << 0xFF << setbase(10) << 0xFF << setbase(16) << 0xFF << endl; 
    // std::cout << std::setbase(16) << 0xFF << std::endl;
    cout << oct << 0xFF << dec << 0xFF << hex << 0xFF <<endl; 
    // std::cout << std::oct << 0xFF << std::dec << 0xFF << std::hex << 0xFF << std::endl; 
    // 输出："377255ff"
    
    return 0;
}
```

也可以使用 **cout.setf**  达到同样效果：

| 操纵运算子         | 作用                     |
| ------------------ | ------------------------ |
| cout.precision(n); | 等同于 setprecision( n ) |
| cout.width(n);     | 等同于 setw( n )         |
| cout.fill('x');    | 等同于 setfill( 'x' )    |

```C++
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	cout.precision(5);       // 设置除小数点外有五位有效数字
    cout.width(10);          // 设置显示域宽10 
    cout<<123.56789<<endl;   // 输出："    123.57"
	
    return 0;
}
```

`setprecision(long f) `表示**保留几位有效数字**，常与下面格式控制结合使用。


| 操纵运算子                   | 作用                                                         |
| ---------------------------- | ------------------------------------------------------------ |
| setiosflags(ios::fixed)      | 固定的浮点显示<br />与 setprecision() 搭配表示**保留小数点后几位小数** |
| setiosflags(ios::scientific) | 指数表示<br />与 setprecision() 搭配表示**保留小数点后几位小数** |
| setiosflags(ios::left)       | 左对齐                                                       |
| setiosflags(ios::right)      | 右对齐                                                       |
| setiosflags(ios::skipws)     | 忽略前导空白                                                 |
| setiosflags(ios::uppercase)  | 16进制数大写输出                                             |
| setiosflags(ios::lowercase)  | 16进制数小写输出                                             |
| setiosflags(ios::showpoint)  | 强制显示小数点                                               |
| setiosflags(ios::showpos)    | 强制显示符号                                                 |

使用` resetflags(long f)`清除之前语句中所使用的`setiosflags`设定的格式

```C++
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	cout << 12345.0 << endl;   //输出"12345"
    cout << 12.3450 << endl;   //输出"12.345"
	cout << setprecision(3) << 12.3450 << endl;   //输出"12.3"   
    cout << setiosflags(ios::fixed) << setprecision(2) << 1.2345 << endl;   //输出"1.23"
    cout << resetiosflags(ios::fixed);    // 需要用resetiosflags()函数清除前面的输出格式
    cout << setiosflags(ios::scientific) << setprecision(2) << 12345.0 << endl;     //输出"1.23e+004"
    // cout << setiosflags(ios::scientific) << setprecision(4) << 12345.0 << endl;  //输出"1.2345e+004"
    return 0;
}
```

**[更多见评论笔记1](https://www.runoob.com/cplusplus/cpp-basic-input-output.html)**

#### 9.4 字符串的输入输出

**字符串的输入，详见9.2节及[评论笔记10](https://www.runoob.com/cplusplus/cpp-strings.html)**

**补充：**`cout << R"(原始\t字\n符串)" << endl;`   // 原始字符串内的字符不进行转义



### 10. [C++ 存储类](https://www.runoob.com/cplusplus/cpp-storage-classes.html)

基本等同于C语言，详见**[C语言 12 节 C存储类](.\C语言 语法汇总)**。

| C++存储类            | 作用                                                         |
| -------------------- | ------------------------------------------------------------ |
| auto                 | 与 C 语言中 **auto** 作用相同；<br />声明变量时根据初始化表达式自动推断该变量的类型、声明函数时函数返回值的占位符<br />很少使用，C++17 中已删除这一用法。 |
| register             | 与 C 语言中 **register** 作用相同；                          |
| static               | 与 C 语言中 **static** 作用相同；<br />详见**[C语言 12.5 static 存储类](.\C语言 语法汇总)**；<br />当 static 用在**类数据成员**上时，会导致仅有一个该成员的副本被类的所有对象共享。 |
| extern               | 与 C 语言中 **extern** 作用相同；<br />详见**[C语言 12.4 extern 存储类](.\C语言 语法汇总)**； |
| mutable              | **mutable** 说明符仅适用于类的对象，它允许对象的成员替代常量。也就是说，mutable 成员可以通过 const 成员函数修改。 |
| thread_local (C++11) | 使用 **thread_local** 说明符声明的变量仅可在它在其上创建的线程上访问。 |



### 11. [C++ 运算符](https://www.runoob.com/cplusplus/cpp-operators.html)

基本等同于C语言，详见**[C语言 11 节 C运算符](.\C语言 语法汇总)**。

**补充：**由于C++增加`bool`运算符，所以在C中，关系运算符、逻辑运算符返回值为`1`或`0`；而在C++中，逻辑运算符返回值为`true`或`false`；
**补充：**在C中，运算符优先级：`括号运算符 []()` ；`成员运算符. ->`；
&nbsp;          但是在C++中，运算符优先级：`括号运算符 []()` ； **`域运算符::`**；  `成员运算符. ->`



### 12. [C++ 判断](https://www.runoob.com/cplusplus/cpp-decision.html)

基本等同于C语言，详见**[C语言 13 节 C判断](.\C语言 语法汇总)**。

**注意：**

```C++
int val = 2;
if(val==true){         // 不会进入if
  cout<<"val==true"<<endl;
}
if(val){               // 会进入if
  cout<<"val"<<endl;
}
```



### 13. [C++ 循环](https://www.runoob.com/cplusplus/cpp-loops.html)

基本等同于C语言，详见**[C语言 14 节 C循环](.\C语言 语法汇总)**。

**注意：**C++11 中，支持**循环遍历** (C语言不支持) ；

```C++
int my_array[5] = {1, 2, 3, 4, 5};

for (int x : my_array)
{
    x *= 2;
    cout << x << endl;  
}
// 循环5次，输出结果：2,4,6,8,10； 此时：my_array[5] = {1, 2, 3, 4, 5};

// 每个数组元素乘于 2
for (int &x : my_array)
{
    x *= 2;
    cout << x << endl;  
}
// 循环5次，输出结果：2,4,6,8,10； 此时：my_array[5] = {2, 4, 6, 8, 10};
```



### 14. [C++ 函数](https://www.runoob.com/cplusplus/cpp-functions.html)

#### 14.1 函数的基本内容

C++函数的基本内容**（定义、声明、调用）**与C类似，[**详见C语言15节**](.\C语言 语法汇总)

#### 14.2 函数参数传递的形式

注意：在C中仅有**值传递**、**指针传递**，在C++中额外增加**引用传递**；
本文仅介绍**引用传递**，值传递、指针传递[**详见C语言15节**](.\C语言 语法汇总)

| 调用类型                                                     | 描述                                                         |
| :----------------------------------------------------------- | :----------------------------------------------------------- |
| **[传值调用 ](https://www.runoob.com/cplusplus/cpp-function-call-by-value.html)** | 该方法把参数的实际值赋值给函数的形式参数。在这种情况下，修改函数内的形式参数对实际参数没有影响。 |
| **[指针调用 ](https://www.runoob.com/cplusplus/cpp-function-call-by-pointer.html)** | 该方法把参数的地址赋值给形式参数。在函数内，该地址用于访问调用中要用到的实际参数。这意味着，修改形式参数会影响实际参数。 |
| **[引用调用 ](https://www.runoob.com/cplusplus/cpp-function-call-by-reference.html)** | 该方法把参数的引用赋值给形式参数。在函数内，该引用用于访问调用中要用到的实际参数。这意味着，修改形式参数会影响实际参数。 |

举例： 

```C
void swap(int x, int y)       // 值传递
{
   int temp;
   temp = x; /* 保存 x 的值 */
   x = y;    /* 把 y 赋值给 x */
   y = temp; /* 把 temp 赋值给 y */
}
swap(a, b);                   // a，b值不会交换

void swap(int *x, int *y)     // 指针传递
{
   int temp;
   temp = *x;    /* 保存地址 x 的值 */
   *x = *y;      /* 把 y 赋值给 x */
   *y = temp;    /* 把 temp 赋值给 y */
}
swap(a, b);                   // a，b值交换

void swap(int &x, int &y)     // 指针传递
{
   int temp;
   temp = x;    /* 保存 x 的值 */
   x = y;       /* 把 y 赋值给 x */
   y = temp;    /* 把 temp 赋值给 y */
}
swap(a, b);                   // a，b值交换
```

**注意：**使用引用传参，仅可传递变量，不可传递常量。
**如：**定义`double sum(double& a1, double& a2);`函数，函数使用只能：`sum(a1,a2);` 不能`sum(3,5);`

#### 14.3 函数参数的默认值

当定义一个函数，您可以为参数列表中**后边的每一个参数**指定默认值。当调用函数时，如果实际参数的值留空，则使用这个默认值。

```C++
int sum(int a, int b=20);
 
int main ()
{
   result = sum(100, 200);    // 300
   result = sum(100);         // 120
}

int sum(int a, int b)  // 注意仅在函数声明中，定义默认参数即可
{
  int result;
  result = a + b;
  return result;
}
```

#### 14.4 **[函数重载](https://www.runoob.com/cplusplus/cpp-overloading.html)** 
C++ 允许在同一作用域中的某个**函数**和**运算符**指定多个定义，分别称为**函数重载**和**运算符重载**。运算符重载见 **二、类与对象 11节**。

重载声明是指一个与之前已经在该作用域内声明过的函数或方法**具有相同名称的声明**，但是它们的**参数列表和定义（实现）不相同**。
如：`int f(int a, float b);`
		`int f(int a, float b, int c);`
**注：**不可定义**仅函数返回值不同**的函数

当您调用一个**重载函数**或**重载运算符**时，编译器通过把您所使用的参数类型与定义中的参数类型进行比较，决定选用最合适的定义。选择最合适的重载函数或重载运算符的过程，称为**重载决策**。

```C++
#include <iostream>
using namespace std;

void print(int i) {
   cout << "整数为: " << i << endl;
}
 
void print(double  f) {
   cout << "浮点数为: " << f << endl;
}

void print(const char *c) {
   cout << "字符串为: " << c << endl;
}

int main(void)
{
   // 输出整数
   print(5);            // 整数为: 5
   // 输出浮点数
   print(500.263);      // 浮点数为: 500.263
   // 输出字符串
   print("Hello C++");  // 字符串为: Hello C++
 
   return 0;
}
```

#### 14.5 匿名函数（又称Lambda 函数，C++11支持）

**函数格式：**`[capture](parameters) mutable ->return-type{statement}`

**其中：**

-  **[capture]**：捕捉列表。捕捉列表总是出现在 lambda 表达式的开始处。事实上，[] 是 lambda 引出符。编译器根据该引出符判断接下来的代码是否是 lambda 函数。捕捉列表能够捕捉上下文中的变量供 lambda 函数使用。
-  **(parameters)**：参数列表。与普通函数的参数列表一致。如果不需要参数传递，则可以连同括号 () 一起省略。
-  **mutable**：mutable 修饰符。默认情况下，lambda 函数总是一个 const 函数，mutable 可以取消其常量性。在使用该修饰符时，参数列表不可省略（即使参数为空）。
-  **->return_type**：返回类型。用追踪返回类型形式声明函数的返回类型。出于方便，不需要返回值的时候也可以连同符号 -> 一起省略。此外，在返回类型明确的情况下，也可以省略该部分，让编译器对返回类型进行推导。
-  **{statement}**：函数体。内容与普通函数一样，不过除了可以使用参数之外，还可以使用所有捕获的变量。

在 lambda 函数的定义式中，**参数列表**和**返回类型**都是**可选部分**，而**捕捉列表**和**函数体**都**可能为空**，C++ 中最简单的 lambda 函数只需要声明为：`[]{};`

**捕捉列表：**

| 捕捉列表 | 功能                                                         |
| -------- | ------------------------------------------------------------ |
| []       | 默认不捕获任何变量<br />（不使用任何函数对象参数）           |
| [=]      | 默认以值捕获所有变量<br />（函数体内可以使用Lambda所在作用范围内所有可见的局部变量，并且是**值传递方式**） |
| [&]      | 默认以引用捕获所有变量<br />（函数体内可以使用Lambda所在作用范围内所有可见的局部变量，并且是**引用传递方式**） |
| [x]      | 仅以值捕获x，其它变量不捕获                                  |
| [&x]     | 仅以引用捕获x，其它变量不捕获                                |
| [=, &x]  | 默认以值捕获所有变量，但是x是例外，通过引用捕获              |
| [&, x]   | 默认以引用捕获所有变量，但是x是例外，通过值捕获              |
| [this]   | 通过引用捕获当前对象（其实是复制指针）<br />（函数体内可以使用Lambda所在类中的成员变量） |
| [*this]  | 通过传值方式捕获当前对象                                     |

**示例：**

```C++
#include <iostream>
using namespace std;

int main()
{
	// 定义简单的lambda表达式
	auto basicLambda = [] { cout << "Hello, world!" << endl; };
	basicLambda();     // 输出：Hello, world!

    // 声明函数同时调用
    [] { cout << "Hello, world!!!" << endl; } ();   // 输出：Hello, world!!!
    
	// 指明返回类型
	auto add = [](int a, int b) -> int { return a + b; };

	// 自动推断返回类型
	auto multiply = [](int a, int b) { return a * b; };
	int sum = add(2, 5);   // 输出：7
	int product = multiply(2, 5);  // 输出：10

	return 0;   // 下面省略 return 0;
}
    
// 1、什么也不捕获，或者是故意不用 Lambda 函数外部的变量
int main()
{
    int i = 1024;
    auto func = [=]{  // [=] 表明将外部的所有变量拷贝一份到该Lambda函数内部
        cout << i;
    };
    func();    // 输出：1024
}

// 2、引用捕获
int main()
{
    int i = 1024;
    cout << &i << endl;        // 输出：0x71275ff65c
    auto fun1 = [&]{
        cout << &i << endl;    
    };
    fun1();                    // 输出：0x71275ff65c
}

// 3、复制并引用捕获
int main()
{
    int i = 1024, j = 2048;
 
    cout << "i:" << &i << endl;     // i:0xb8c77ffadc
    cout << "j:" << &j << endl;     // j:0xb8c77ffad8
 
    auto fun1 = [=, &i]{ // 默认拷贝外部所有变量，但引用变量 i
        cout << "i:" << &i << endl;    // i:0xb8c77ffadc
        cout << "j:" << &j << endl;    // j:0xb8c77ffacc
    };
    fun1();
}

// 4、指定引用或复制
int main()
{
    int i = 1024, j = 2048;
 
    cout << "outside i value:" << i << " addr:" << &i << endl;
    // outside i value:1024 addr:0x6fcfbff808
    auto fun1 = [i]{
        cout << "inside  i value:" << i << " addr:" << &i << endl;
        // cout << j << endl; // j 未捕获
    }; 
    fun1();   // inside  i value:1024 addr:0x6fcfbff804
}

// 5、捕获this指针
class test
{
public:
    void hello() {
        cout << "test hello!n";
    };
    void lambda() {
        auto fun = [this]{ // 捕获了 this 指针
            this->hello(); // 这里 this 调用的就是 class test 的对象了
        };
        fun();
    }
};
 
int main()
{
    test t;
    t.lambda();    // 输出：test hello!n
}

// 6、mutable运用
int main()
{
    int x = 10;
    
    auto add_x = [x](int a) mutable { x *= 2; return a + x; };  // 复制捕捉x
    cout << add_x(10) << endl;  // 输出：30
}
```

[**更多见教程及评论笔记1、2、3、4、5、6、10**](https://www.runoob.com/cplusplus/cpp-functions.html)

#### 14.6 [函数模板](https://www.runoob.com/cplusplus/cpp-templates.html)

模板是泛型编程的基础，泛型编程即以一种独立于任何特定类型的方式编写代码。
如 **向量**，我们可以定义许多不同类型的向量，比如 **vector \<int>** 或 **vector \<string>**。

模板函数定义的一般形式如下所示：

```C++
template <typename type> ret-type func-name(parameter list) { /* 函数的主体 */  }
// typename 改为 class 也可；
// 如：template <class type> ret-type func-name(parameter list) { /* 函数的主体 */  }
```

实例：

```C++
#include <iostream>
using namespace std;
template <typename T1>
void Swap(T1& a, T1& b)  // 引用传参
{
    T1 t = a;
    a = b;
    b = t;
}
template <typename T2>
T2 &Max (T2& a, T2& b)   // inline T2 const& Max (T2 const& a, T2 const& b)  // 原文这样定义函数
{   // 引用传参，返回值引用
    return a < b ? b:a; 
} 
int main()
{
    int a = 2;
    int b = 3;
    cout <<"a = " << a << ";  b = " << b <<endl;
    Swap(a,b);
    cout <<"a = " << a << ";  b = " << b <<endl;
    float c = 0.02;
    float d = 0.03;
    cout <<"c = " << c << ";  d = " << d <<endl;
    Swap(c,d);
    cout <<"c = " << c << ";  d = " << d <<endl;
    
    int i = 39;
    int j = 20;
    cout << "Max(i, j): " << Max(i, j) << endl; 
 
    double f1 = 13.5; 
    double f2 = 20.7; 
    cout << "Max(f1, f2): " << Max(f1, f2) << endl; 
    
    string s1 = "Hello"; 
    string s2 = "World"; 
    cout << "Max(s1, s2): " << Max(s1, s2) << endl; 
    return 0;
}
```

更多讲解见[**评论笔记**](https://www.runoob.com/cplusplus/cpp-templates.html)



### 15. [C++ 数组](https://www.runoob.com/cplusplus/cpp-arrays.html)

基本等同于C语言，详见**[C语言 16 节 C数组](.\C语言 语法汇总)**。

#### 15.1 [vector(向量) 标准库](https://www.w3cschool.cn/cpp/cpp-i6da2pq0.html)

Array 是固定大小的，不能额外增加元素。当我们想定义不固定大小的字符时，可以使用 vector(向量) 标准库。

**1 、基本操作**

> (1)头文件`#include<vector>`.
> (2)创建vector对象，`vector<int> vec`;
> (3)尾部插入数字：`vec.push_back(a)`;
> (4)使用下标访问元素，`cout<<vec[0]<<endl`;记住下标是从0开始的。
> (5)使用迭代器访问元素.
>
> ```C++
> vector<int>::iterator it;
> for(it=vec.begin();it!=vec.end();it++)
>  cout<<*it<<endl;
> ```
> (6)插入元素：`vec.insert(vec.begin()+i,a)`; 在第i+1个元素前面插入a;
> (7)删除元素：`vec.erase(vec.begin()+2)` ; 删除第2+1个元素
> `vec.erase(vec.begin()+i,vec.end()+j)`; 删除区间[ i,j-1] 区间从0开始
> (8)向量大小: `vec.size()`;
> (9)清空: `vec.clear()`;
>
> 特别提示：这里有 begin() 与 end() 函数、front() 与 back() 的差别

**实例：**

```C++
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;
 
int main() {
    vector<int>obj;  //创建一个向量存储容器 int
    
    for(int i=0; i<10; i++)     // push_back(elem)在数组最后添加数据 
    {
        obj.push_back(i);
        cout<<obj[i]<<",";    // 0,1,2,3,4,5,6,7,8,9
    }
    cout<<endl;
    
    for(int i=0; i<5; i++)  //去掉数组最后一个数据 
    {
        obj.pop_back();     
    }
 
    for(int i=0; i<obj.size(); i++)  //size()容器中实际数据个数 
    {
        cout<<obj[i]<<",";    // 0,1,2,3,4,
    }
    cout<<endl;
    
    obj.clear();   //清除容器中所有数据
    cout << obj.size() << endl;   // 0
    cout<<endl;
    
    vector<int>obj(5);  //创建一个向量存储容器 int，大小为5
    for(int i=0; i<obj.size(); i++)  //size()容器中实际数据个数 
    {
        cout<<obj[i]<<",";    // 0,0,0,0,0,
    }
    cout<<endl;
    
    vector< vector<int> > obj; // 定义二维动态数组
    vector< vector<int> > obj(5); // 定义5行二维动态数组
    vector< vector<int> > obj(5, vector<int>(6)); // 定义二维动态数组5行6列 
    
    return 0;
}
```

更多内容见：**<u>21节 21.4 小节</u>、[C++ vector 容器浅析](https://www.runoob.com/w3cnote/cpp-vector-container-analysis.html)、[C++ vector使用方法](https://www.w3cschool.cn/cpp/cpp-i6da2pq0.html)**



### 16. [C++ 字符串](https://www.runoob.com/cplusplus/cpp-strings.html)

C++ 提供了以下两种类型的字符串表示形式：

- C 风格字符串，[**详见C语言16.4节**](.\C语言 语法汇总)，需要**`include <cstring>`**；

&nbsp;            **补充：**在C中，输出字符串时，通过`%s`、`%p`确认输出 字符串、字符串地址，
&nbsp;            在C++中，若要输出字符串地址，需要使用`&`取地址符号；或是强制转换为其他类型指针；
&nbsp;            如：`cout << name << &name << (void *)name;`，依次输出整个字符串、字符串地址、字符串地址。

- C++ 引入的 string 类 类型，需要**`include <string>`**；
  PS：C/C++中**不存在字符串变量**；string 是一个**有关字符串的 类**；  字符串使用 **string** 声明之后，才具有了下面的各种运算。

C++ 标准库提供了 **string 类** 类型，支持上述所有的操作，另外还增加了其他更多的功能。[**(详见评论笔记1)**](https://www.runoob.com/cplusplus/cpp-strings.html)

| string操作符             | 等效函数                                    |
| ------------------------ | ------------------------------------------- |
| **str1 = str2;**         | 字符串赋值，等效于**strcpy(str1, str2);**   |
| **str1  =  str1 + str2** | 字符串相连接，等效于**strcat(str1, str2);** |
| **str1.size();**         | 求字符串大小                                |
| **str1.append()**        | 在字符串的末尾添加字符                      |
| **str1.find()**          | 在字符串中查找字符串                        |
| **str1.insert()**        | 插入字符                                    |
| **str1.length()**        | 返回字符串的长度，等效于**strlen(str1);**   |
| **str1.replace()**       | 替换字符串                                  |
| **str1.substr()**        | 返回某个子字符串                            |

**例：**

```C++
#include <iostream>
#include <string>      // 注意不是<cstring>
 
using namespace std;
 
int main ()
{
    string str1 = "runoob";     
    string str2 = "google";     
    // 也可以使用如下方法声明定义字符串。
    // string str1("runoob");
    // string str2("google");
    
    // 连接 str1 和 str2
    str1 = str1 + str2;
    cout << "str1 + str2 : " << str1 << endl;      // str1 + str2 : runoobgoogle
 
    // 复制 str1 到 str2
    str2 = str1;     
    cout << "str2 : " << str2 << endl;             // str2 : runoobgoogle
    
    // 连接后，str1 的总长度
    cout << "str1.size() :  " << str1.size() << endl;          // str1.size() :  12
    cout << "str1.length() :  " << str1.length() <<  endl;     // str1.length() :  12
    
    // 字符串的末尾添加字符
    str1.append("C++");
    cout << "str1.append(\"C++\") :  " << str1 <<  endl;   // str1.append("C++") :  runoobgoogleC++
   
    // 删除字符串元素
    int pos = str1.find("C++");  // 查找"C++"在字符串中的位置
    cout << "pos : " << pos << endl;          // pos : 12
    str1.replace(pos, 3, "");    // 从位置pos开始，之后的3个字符替换为空，即删除
    cout << "str1 : " << str1 << endl;        // str1 : runoobgoogle

    //找子串
    int first = str1.find_first_of("o");   //从头开始寻找字符'o'的位置
    int last = str1.find_last_of("o");     //从尾开始寻找字符'o'的位置
    cout << "first : " << first << " ;   last : " << last << endl;    // first : 3 ;   last : 8
    cout << "substr : " << str1.substr(first+1, last-first-1)<<endl;  // substr : obgo

    return 0;
}
```

更多字符串函数用法见**[评论笔记1、7、8、9、14](https://www.runoob.com/cplusplus/cpp-strings.html)**

此外，注意字符串字面值与标准库string不是同一种类型，详见**[评论笔记2](https://www.runoob.com/cplusplus/cpp-strings.html)**

```C++
string s("hello");
cout<<s.size()<<endl;        //OK
cout<<"hello".size()<<endl;  //ERROR
cout<<s+"world"<<endl;       //OK
cout<<"hello"+"world"<<endl; //ERROR
// 原因为："hello"本质上是一个地址，只不过显示格式为字符串。
// 只有使用 string 声明后，字符串才具有以上操作式。
```

此外，注意strlen、size()求字符串长度 和 sizeof() 求字符数组大小 的区别**[ (见评论笔记2、3)](https://www.runoob.com/cplusplus/cpp-strings.html)**；

```C++
cout<<strlen("123")<<endl;   //返回 3
cout<<sizeof("123")<<endl;   //返回 4
string s = "123";
cout<<s.size()<<endl;        //返回 3
```



### 17. [C++ 指针](https://www.runoob.com/cplusplus/cpp-pointers.html)

基本等同于C语言，详见**[C语言 17 节 C指针](.\C语言 语法汇总)**。

补充：C++11，不提倡使用**NULL**代表空指针，建议使用**nullptr**表示。



### 18. [C++ 引用](https://www.runoob.com/cplusplus/cpp-references.html)

引用变量是一个别名，也就是说，它是某个已存在变量的另一个名字。一旦把引用初始化为某个变量，就可以使用该引用名称或变量名称来指向变量。**在C中没有引用；**

#### 18.1 引用的创建

```C++
int i = 17;
int &r = i;
// 之后对r的任何操作与对i的操作相同
cout << "Value of i : " << i << endl;     // Value of i : 17
cout << "Value of r : " << r  << endl;    // Value of r : 17
cout << "Addr of i: " << &i << endl;      // Addr of i: 0x7f4b1ff9b4
cout << "Addr of r: " << &r << endl;      // Addr of r: 0x7f4b1ff9b4

// 数组的引用一定要表明数组的大小
int a[] = { 1,2,3,4 };
int(&r)[4] = a;
```

**注意：**引用必须在声明时将其初始化

引用实际作用类似`const`指针，以下两种表达方法类似。

```C++
int rats = 10;
int &rodents = rats;

int rats = 10;
int * const pr = &rats;
```

#### 18.2 引用在函数传参中的应用

通常用于**[函数参数列表](https://www.runoob.com/cplusplus/passing-parameters-by-references.html)**和**[函数返回值](https://www.runoob.com/cplusplus/returning-values-by-reference.html)**。引用用于 函数参数列表 ，详见 14.2 函数参数传递。

引用用于 **函数返回值**：

```C++
int &changevalue()
{
    static int a_return =-29;     // 
    return a_return;
}

int main()
{
    int &a_return=changevalue();     // int &a_return = changevalue()函数中的a_return
    a_return =20;  // 修改a_return，a_return是changevalue()中的a_return引用，changevalue()中的a_return也同时修改
    cout<<changevalue()<<endl;       // 输出 changevalue()函数中的a_return
    system("pause");
    return 0;
}
```

**注意：**返回一个引用时，要注意被引用的对象不能超出作用域，**类似返回数组、指针**。
所以返回一个对**局部变量的引用**是不合法的，但是，可以返回一个对**静态变量的引用**。

```C++
int& func() {
   int q;
   //! return q; // 在编译时发生错误
   static int x;
   return x;     // 安全，x 在函数作用域外依然是有效的
}
```

更多示例详见**[教程正文示例及评论笔记4](https://www.runoob.com/cplusplus/returning-values-by-reference.html)**



### 19. [C++ 结构体](https://www.runoob.com/cplusplus/cpp-data-structures.html)

与C语言结构体基本相同，[**详见C语言20节**](.\C语言 语法汇总)

**区别：**

```C++
/****** C 定义及使用结构体 ******/
struct SIMPLE
{
    int a;
    char b;
    double c;
};
struct SIMPLE t1, t2[20], *t3;

typedef struct Simple    // 此处Simple可省略可换成其他，常省略不加
{
    int a;
    char b;
    double c; 
} SIMPLE;
SIMPLE t1, t2[20], *t3;

/****** C++定义及使用结构体 ******/
struct SIMPLE    
{
    int a;
    char b;
    double c; 
} ;
SIMPLE t1, t2[20], *t3;   // 定义变量时可省略struct
```

**[更多内容见评论笔记](https://www.runoob.com/cplusplus/cpp-data-structures.html)**

#### 19.2. struct 高级用法

见 **二、类与对象 12. struct 高级用法**



### 20. [C++ 动态内存](https://www.runoob.com/cplusplus/cpp-dynamic-memory.html)

C++支持 C语言 动态内存分配方法，详见**[C语言 22节](.\C语言 语法汇总)**。以下对C++的动态内存分配方法进行讲解。

C++ 程序中的内存分为两个部分：

- **栈：**在函数内部声明的所有变量都将占用栈内存。
- **堆：**这是程序中未使用的内存，在程序运行时可用于动态分配内存。

很多时候，您无法提前预知需要多少内存来存储某个定义变量中的特定信息，所需内存的大小需要在运行时才能确定。

在 C++ 中，您可以使用特殊的运算符为给定类型的变量在运行时分配堆内的内存，这会返回所分配的空间地址。这种运算符即 **new** 运算符。如果您不再需要动态分配的内存空间，可以使用 **delete** 运算符，删除之前由 **new** 运算符分配的内存。

在 C语言 中，可以使用 **malloc()** 函数 进行动态内存分配，但不建议在 C++ 中使用。
**new** 与 **malloc()** 函数相比，其主要的优点是，**new** **不只是分配了内存，它还创建了对象。**

>**new 和 malloc 内部的实现方式区别：**
>
>new 的功能是在堆区新建一个对象，并返回该对象的指针。
>所谓的**【新建对象】**的意思就是，将调用该类的构造函数，因为如果不构造的话，就不能称之为一个对象。
>而 malloc 只是机械的分配一块内存，如果用 malloc 在堆区创建一个对象的话，是不会调用构造函数的。
>严格说来用 malloc 不能算是新建了一个对象，只能说是分配了一块与该类对象匹配的内存而已，然后强行把它解释为【这是一个对象】，按这个逻辑来，也不存在构造函数什么事。
>同样的，用 delete 去释放一个堆区的对象，会调用该对象的析构函数。
>用 free 去释放一个堆区的对象，不会调用该对象的析构函数。

#### **20.1 动态内存分配方法讲解：**

**[讲解1](https://blog.csdn.net/baidu_41388533/article/details/106560988)**

```C++
// 1. 动态内存分配 实例讲解
double* pvalue  = NULL; // 初始化为 null 的指针
pvalue  = new double;   // 为变量请求内存

if( !pvalue )    // if( pvalue==NULL )  
{   // 自由存储区已被用完，可能无法成功分配内存，建议检查 new 运算符是否返回 NULL 指针
   cout << "Error: out of memory." <<endl;
   exit(1);   // 退出程序
}

*pvalue = 29494.99;     // 在分配的地址存储值
cout << "Value of pvalue : " << *pvalue << endl;    // Value of pvalue : 29495
delete pvalue;        // 释放 pvalue 所指向的内存

int a = 20;   
pvalue = &a;       // 正确，说明pvalue变量本身并没有被销毁。销毁的是它指向的变量

// 2. 数组的动态内存分配
int* pvalue  = NULL;    // 初始化为 null 的指针
pvalue  = new int[10];  // 为变量请求内存

for( int i=0; i<10; i++ )      pvalue[i] = i*i ;
for( int i=0; i<10; i++ )      cout << pvalue[i] <<endl;

delete [] pvalue;        // 删除 pvalue 所指向的数组

// 二维数组
int **array
// 假定数组第一维长度为 m， 第二维长度为 n
// 动态分配空间
array = new int *[m];
for( int i=0; i<m; i++ )
{
    array[i] = new int [n]  ;
}
//释放
for( int i=0; i<m; i++ )
{
    delete [] array[i];
}
delete [] array;
```
#### 20.2 **对象**的动态内存分配

**[new和delete知识总结](https://blog.csdn.net/qq_44443986/article/details/114800593)**
new去申请对象会**先申请对象的空间**并**调用对象的构造函数**完成对象的初始化；delete会先去**完成对象的资源清理(析构函数)**，再将对象**所占的空间释放掉**。

```C++
// 对象的动态内存分配 例1
class Box
{
   public:
      Box() { 
         cout << "调用构造函数！" <<endl; 
      }
      ~Box() { 
         cout << "调用析构函数！" <<endl; 
      }
};
 
int main( )
{
   Box* myBoxArray = new Box[4];   // 为 包含四个 Box 对象的数组分配内存
 
   delete [] myBoxArray;   // 删除数组，注意加 []
   return 0;
}

// 对象的动态内存分配 例2
class Box
{
   public:
      Box() { }
      Box(int *b) { a=b;}
      ~Box() { }
      int *a;
};
 
int main( )
{
   int *p;
   Box* myBoxArray1 = new Box;      
   Box* myBoxArray2 = new Box(p);   
   delete myBoxArray1;  // new的对象注意删除
   delete myBoxArray2;  // new的对象注意删除

   return 0;
}

// 对象的动态内存分配 例3
class A
{
public:
	A(int a = 1, int b = 2, int c = 3)
	:_a(a) ,_b(b) ,_c(c)       { }

private:
	int _a;
	int _b;
	int _c;
};

void test()
{
	//使用传入的值
	A* pa1 = new A(10, 20, 30);
	delete pa1;
	//使用缺省参数
	A* pa2 = new A;
	delete pa2;
	//全部使用缺省参数
	A* arr = new A[10];
	delete[] arr;
}
```

#### **20.3 动态内存分配 及 内存泄露 问题**

**[讲解1](https://zhuanlan.zhihu.com/p/479535048)、[讲解2](https://zhuanlan.zhihu.com/p/336659625)、[讲解3](https://blog.csdn.net/weixin_44718794/article/details/107071169)**

**一个基本原则：**注意所有 `new` 的对象 都需要 `delete`。

1）内存泄露定义：

>**定义1：**由于疏忽或错误造成程序未能释放已经不再使用的内存。
>内存泄漏并非指内存在物理上的消失，而是应用程序分配某段内存后，由于设计错误，导致在释放该段内存之前就失去了对该段内存的控制，从而造成了内存的浪费。
>
>**定义2：**在堆上分配的内存，如果不再使用了，就应该及时释放，以便后面其他地方可以重用。而在 C 语言中，内存管理器不会自动回收不再使用的内存。如果忘了释放不再使用的内存，这些内存就不能被重用了，这就造成了内存泄漏。

2）内存泄露后果：

>* 一两处内存泄漏通常并不致于让程序崩溃，也不会带来逻辑上的错误，而且在进程退出时，系统会自动释放所有与该进程相关的内存（共享内存除外），所以内存泄漏的后果相对来说还是比较温和的。
>* 但是，量变会导致质变，一旦内存泄漏过多以致耗尽内存，后续内存分配将会失败，程序就可能因此而崩溃。
>  （程序消耗了大量的内存，导致其他程序无法正常使用  &  程序运行后，随着时间占用了更多的内存，最后无内存可用而崩溃）
>

3）如何寻找内存泄露点：

>1. 根据原理，我们可以先review自己的代码，**利用"查找"功能，查询`new`与`delete`，看看内存的申请与释放是不是成对释放的**，这使你迅速发现一些逻辑较为简单的内存泄露情况。
>2. 如果依旧发生内存泄露，可以通过记录申请与释放的对象数目是否一致来判断。在类中追加一个静态变量 `static int count;`在构造函数中执行`count++;`在析构函数中执行`count--;`，通过在程序结束前将所有类析构，之后输出静态变量，看count的值是否为0，如果为0,则问题并非出现在该处，如果不为0，则是该类型对象没有完全释放。
>3. 检查类中申请的空间是否完全释放，尤其是存在继承父类的情况，看看子类中是否调用了父类的析构函数，有可能会因为子类析构时没有是否父类中申请的内存空间。
>4. 对于函数中申请的临时空间，认真检查，是否存在提前跳出函数的地方没有释放内存。

4）STL 的智能指针：

#### 20.4 Qt中new之后需不需要delete的问题

**[讲解1](https://blog.csdn.net/y24283648/article/details/86303096)、[讲解2](https://zhuanlan.zhihu.com/p/476682300)、[讲解3](https://www.cnblogs.com/liushui-sky/p/5852014.html)、[讲解4](https://blog.csdn.net/weixin_42542969/article/details/88868794)、[讲解5](https://blog.csdn.net/Aidam_Bo/article/details/85698862)**

QT的父子对象机制是在 QWidget和QOject中实现的。当我们使用父对象来创建一个对象的时候 ，父对象会把这个对象添加到自己的子对象列表中。当这个**父对象被删除**的时候，它会遍历它的**子对象类表并且删除每一个子对象**，然后子对象们自己再删除它们自己的子对象，这样递归调用直到所有对象都被删除。

这种父子对象机制会在很大程度上简化我们的内存管理工作，减少内存泄露的风险。我们需要**显试删除**（就是用delete删除）的对象是那些使用**new创建的并且没有父对象的对象**（切记是new的才要delete，**通过成员函数获得的对象，没有特殊说明的，千万不要随便delete**）。如果我们在删除一个对象的父对象之前删除它，QT会自动地从它的父对象的子对象列表中移除它的。

```C++
#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QLabel *label =new QLabel("hello",&w);
    //这里使用new之后不需要执行delete，因为label的父类是w，而w是在栈中创建，在程序关闭的时候会自动释放，所以作为w的子类内存也被释放。

    QLabel *label1 =new QLabel("world");
    //这个是需要执行delete label1，否则会造成内存泄漏，因为label没有父类，所以不会为label释放内存
    w.show();
    a.exec();
    delete label1;
    label1=NULL;
    return 0;
}


class MainWindow : public QMainWindow
{
	Q_OBJECT
pravite: 
    QSerialPort *serialport = NULL; //串口指针
}
MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	serialport = new QSerialPort(this);    //new的时候指定了 mainwindow这个父对象 不用手动释放
	serialport = new QSerialPort;   //不指定父对象 则需要自己使用完delete
}
//析构函数
MainWindow::~MainWindow
{ //保险起见 可以进行判断
	if（serialport）
	{
		delete serialport;
		serialport = NULL;//清理后赋空值 看个人习惯
	}
}
```

**更多内容参考 二、C++ 类与对象 10.2 多态 内容**



### 21. C++ STL 容器

**[讲解1](https://zhuanlan.zhihu.com/p/564057584)、[讲解2](http://c.biancheng.net/stl)、[讲解3](https://www.jianshu.com/p/497843e403b4)、[讲解4](https://www.cnblogs.com/fusiwei/p/11823234.html)、[讲解5](https://zhuanlan.zhihu.com/p/130905242)**

##### 21.0 C++ string 也是容器，详见16节字符串

#### 21.1 顺序性容器

顺序性容器 就是将一组具有相同类型的元素以严格的线性形式组织起来

| 容器         | 简介说明                                                     |
| ------------ | ------------------------------------------------------------ |
| vector       | 可变大小数组。相当于数组，可动态构建，支持随机访问，无头插和尾插，仅支持insert插入，除尾部外的元素删除比较麻烦。但使用最为广泛 |
| deque        | 双端队列。支持头插、删，尾插、删，随机访问较vector容器来说慢,但对于首尾的数据操作比较方便 |
| list         | 双向循环链表。使用起来很高效，对于任意位置的插入和删除都很快，在操作过后，以后指针、迭代器、引用都不会失效 |
| forward_list | 单向链表。只支持单向访问，在链表的任何位置进行插入/删除操作都非常快 |
| array        | 固定数组。vector的底层即为array数组，它保存了一个以严格顺序排列的特定数量的元素 |

一般大多数的题目都可以使用vector容器，除非有特定需求使用其他容器更加合理方便；

如果需要在一串数字的头尾进行操作，偏向deque，对于较中间的元素操作，不推荐 ；

对于中间的元素插入或删除，可采用forward_list（单向链表）或list（双向链表），不需要移动元素，只需改变相关结点的指针域即可；

#### 21.2 关联式容器

关联式容器则大不一样，此类容器在存储元素值的同时，还会为各元素额外再配备一个值（又称为“键”，其本质也是一个 C++ 基础数据类型或自定义类型的元素），它的功能是在使用关联式容器的过程中，如果已知目标元素的键的值，则直接通过该键就可以找到目标元素，而无需再通过遍历整个容器的方式。

也就是说，使用关联式容器存储的元素，都是一个一个的“键值对”（ <key,value> ），这是和序列式容器最大的不同。除此之外，序列式容器中存储的元素默认都是未经过排序的，而使用关联式容器存储的元素，默认会根据各元素的键值的大小做升序排序。

| 关联式容器名称 | 特点                                                         |
| -------------- | ------------------------------------------------------------ |
| map            | 定义在 <map> 头文件中，使用该容器存储的数据，其各个元素的键必须是唯一的（即不能重复），该容器会根据各元素键的大小，默认进行升序排序（调用 std::less<T>）。 |
| set            | 定义在 <set> 头文件中，使用该容器存储的数据，各个元素键和值完全相同，且各个元素的值不能重复（保证了各元素键的唯一性）。该容器会自动根据各个元素的键（其实也就是元素值）的大小进行升序排序（调用 std::less<T>）。 |
| multimap       | 定义在 <map> 头文件中，和 map 容器唯一的不同在于，multimap 容器中存储元素的键可以重复。 |
| multiset       | 定义在 <set> 头文件中，和 set 容器唯一的不同在于，multiset 容器中存储元素的值可以重复（一旦值重复，则意味着键也是重复的）。 |

如果只负责查找内容，具体到某个单位，使用场景比如对手机游戏的个人的计分的存储，可以使用set或mutliset

如果需要同时放入容器的数据不止一个，并且是不同类型，比如一个为整型int,一个为string字符串型，就可以考虑使用map或mutlimap

#### 21.3 容器适配器

容器适配器是一个封装了序列容器的一个类模板，它在一般的序列容器的基础上提供了一些不同的功能。之所以称为容器适配器，是因为它是适配容器来提供其它不一样的功能。通过对应的容器和成员函数来实现我们需要的功能。

| 容器           | 简介说明                                                     |
| -------------- | ------------------------------------------------------------ |
| stack          | 堆栈。其原理是先进后出（FILO），其底层容器可以是任何标准的容器适配器，默认为deque双端队列 |
| queue          | 队列。其原理是先进先出（FIFO），只有队头和队尾可以被访问，故不可有遍历行为，默认也为deque双端队列 |
| pirority_queue | 优先队列。它的第一个元素总是它所包含的元素中优先级最高的，就像数据结构里的堆，会默认形成大堆，还可以使用仿函数来控制生成大根堆还是生成小根堆，若没定义，默认使用vector容器 |

对于 stack 堆栈，在我们日常生活中类似于坐地铁、电梯；
对于 deque 队列，在我们日常生活中类似于排队打饭；
对于 pirority_queue，因为其本质是堆，可以考虑解决一些贪心问题；

#### 21.4 [顺序性容器 详解](http://c.biancheng.net/stl/sequence_container/)

##### 0）迭代器

**[讲解1](http://c.biancheng.net/view/6675.html)、[讲解2](https://www.cnblogs.com/hdk1993/p/4419779.html)、[讲解3](https://zhuanlan.zhihu.com/p/226014048)**

无论是序列容器还是关联容器，最常做的操作无疑是遍历容器中存储的元素，而实现此操作，多数情况会选用“迭代器（iterator）”来实现。

| 迭代器定义方式 | 具体格式                                   |
| -------------- | ------------------------------------------ |
| 正向迭代器     | 容器类名::iterator 迭代器名;               |
| 常量正向迭代器 | 容器类名::const_iterator 迭代器名;         |
| 反向迭代器     | 容器类名::reverse_iterator 迭代器名;       |
| 常量反向迭代器 | 容器类名::const_reverse_iterator 迭代器名; |

一般使用 容器类名::iterator 迭代器名 迭代器，iterator 返回为 对应容器类型的迭代器类型

| 容器                               | 对应的迭代器类型 |
| ---------------------------------- | ---------------- |
| array                              | 随机访问迭代器   |
| vector                             | 随机访问迭代器   |
| deque                              | 随机访问迭代器   |
| list                               | 双向迭代器       |
| set / multiset                     | 双向迭代器       |
| map / multimap                     | 双向迭代器       |
| forward_list                       | 前向迭代器       |
| unordered_map / unordered_multimap | 前向迭代器       |
| unordered_set / unordered_multiset | 前向迭代器       |
| stack                              | 不支持迭代器     |
| queue                              | 不支持迭代器     |

迭代器支持：

- 通过**begin**和**end**可以取得容器的首元素与尾元素**迭代器** （带r版本返回反向迭代器，带c版本返回const迭代器）
  PS：需要注意的是，由于计算机区间**“前闭后开”**的结构，begin()函数返回的指针指向的的确是集合的**第一个元素的迭代器**。但end()返回的指针却指向了集合**最后一个元素后面一个元素的迭代器**。
- \*iter 使用解引用符返回迭代器iter所指向元素的**引用**
- iter->member 解引用iter并获得该元素名为men的成员的**引用**
- ++iter iter指向容器中下一个元素
- --iter iter指向容器中上一个元素
- iter1 == iter2，iter1 != iter2 判断2个迭代器是否相等


```C++
/* vector 容器：随机迭代器 */
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v{1,2,3,4,5,6,7,8,9,10}; //v被初始化成有10个元素
    cout << "第一种遍历方法：" << endl;
    //size返回元素个数
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] <<" "; //像普通数组一样使用vector容器
    //创建一个正向迭代器，当然，vector也支持其他 3 种定义迭代器的方式

    cout << endl << "第二种遍历方法：" << endl;
    vector<int>::iterator it;
    //用 != 比较两个迭代器
    for (it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";

    cout << endl << "第三种遍历方法：" << endl;
    for (it = v.begin(); it < v.end(); ++it) //用 < 比较两个迭代器
        cout << *it << " ";

    cout << endl << "第四种遍历方法：" << endl;
    it = v.begin();
    while (it < v.end()) { //间隔一个输出
        cout << *it << " ";
        it += 2; // 随机访问迭代器支持 "+= 整数"  的操作
    }
    
    vector<int>::iterator rit;
    for (rit = v.end(); rit != v.begin(); --rit)
        cout << *rit << " ";   // -1414812757 10 9 8 7 6 5 4 3 2
    for (rit = v.end()-1; rit >= v.begin(); --rit)
        cout << *rit << " ";   // 10 9 8 7 6 5 4 3 2 1
}

/* list 容器：双向迭代器 */
#include <list>
#include <iostream>
using namespace std;
int main()
{
    list<int> l{1,2,3,4,5,6,7,8,9,10}; //v被初始化成有10个元素
    /* 不合法，list无法遍历访问 */
    /*
    cout << "第一种遍历方法：" << endl;
    //size返回元素个数
    for (int i = 0; i < v.size(); ++i)
        cout << l[i] <<" "; //像普通数组一样使用vector容器
    //创建一个正向迭代器，当然，vector也支持其他 3 种定义迭代器的方式
	*/
    
    cout << endl << "第二种遍历方法：" << endl;
    vector<int>::iterator it;
    //用 != 比较两个迭代器
    for (it = l.begin(); it != l.end(); ++it)
        cout << *it << " ";

    /* 不合法，list为双向链表，不支持 <  */
    /*
    cout << endl << "第三种遍历方法：" << endl;
    for (it = l.begin(); it < l.end(); ++it) //用 < 比较两个迭代器
        cout << *it << " ";
	*/
    
    /* 不合法，list为双向链表，不支持 +=  */
    /*
    cout << endl << "第四种遍历方法：" << endl;
    it = l.begin();
    while (it < l.end()) { //间隔一个输出
        cout << *it << " ";
        it += 2; // 随机访问迭代器支持 "+= 整数"  的操作
    }
    */
}
```

##### **1） vector（向量）**

对于vector容器，它的数据结构与数组非常类似，但是他们之间的不同之处是数组是静态空间，一旦配置了就不能更改，vector却可以进行动态分配，随着元素的插入和删除，内部的空间也会灵活变动，就和C语言中的malloc和C++中的new是一个道理，不用害怕空间不足而一开始就定义一个很大的数组，节省了内存空间。
<img src="https://pic2.zhimg.com/v2-b5573d13519584d0a9068b13a4d03f4d_r.jpg" alt="img" style="zoom:85%;" />
**基本操作**

> (1)头文件`#include<vector>`.
> (2)创建vector对象，`vector<int> vec`;
> (3)尾部插入数字：`vec.push_back(a)`;  尾部删除数字：`vec.pop_back(a)`
> (4)使用下标访问元素，`cout<<vec[0]<<endl`;记住下标是从0开始的。也可以`cout<<vec.at(0)<<endl`
> (5)使用迭代器访问元素.
>
> ```C++
> vector<int>::iterator it;
> for(it=vec.begin();it!=vec.end();it++)
>  cout<<*it<<endl;
> ```
> (6)插入元素：`vec.insert(vec.begin()+i,a)`; 在第i+1个元素前面插入a;
> (7)删除元素：`vec.erase(vec.begin()+2)` ; 删除第2+1个元素
> `vec.erase(vec.begin()+i,vec.end()+j)`; 删除区间[ i,j-1] 区间从0开始
> (8)向量大小: `vec.size()`;
> (9)清空: `vec.clear()`;
>
> 特别提示：这里有 begin() 与 end() 函数、front() 与 back() 的差别

```C++
#include <vector>  // 引用头文件
using namespace std;   // 注意需要引入标准命名空间

void PrintVector(vector<int>&v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << ' ';
	}
    // iterator 迭代器，相当于指针
	cout << endl;
}

/**
1）构造函数
常见的构造方式有四种，一般我们会前两种就可以：
*/
//1.默认构造，无参构造
vector<int> v0{1,2,3,4,5,6,7,8,9,10}; //v被初始化成有10个元素
PrintVector(v0);   // 1,2,3,4,5,6,7,8,9,10

vector<int> v1;	
for (int i = 0; i < 10; ++i)
{
    v1.push_back(i);
}
PrintVector(v1);   // 0 1 2 3 4 5 6 7 8 9 

//2.利用区间方式构造
vector<int> v2(v1.begin(), v1.end());
PrintVector(v2);   // 0 1 2 3 4 5 6 7 8 9 

//3.n个element方式构造
vector<int> v3(10, 100);	//10个100
PrintVector(v3);   // 100 100 100 100 100 100 100 100 100 100

//4.拷贝构造
vector<int> v4(v3);	
PrintVector(v4);   // 100 100 100 100 100 100 100 100 100 100

/**
2）赋值操作
赋值的话可以使用assign()函数，也可以使用其他方式 
assign()，将区间[first,last)的元素赋值到当前的vector容器中，或者赋n个值为x的元素到vector容器中
*/
//1.直接赋值
vector<int> v2;
v2 = v1;  // 0 1 2 3 4 5 6 7 8 9 

//2.assign赋值
vector<int> v3;
v3.assign(v1.begin(), v1.end());  // 0 1 2 3 4 5 6 7 8 9 

//3.n个element赋值
vector<int> v4;
v4.assign(10, 100);     // 100 100 100 100 100 100 100 100 100 100

//4.数据交换
v4.swap(v3);
PrintVector(v4);   // 0 1 2 3 4 5 6 7 8 9 

/**
3）插入和删除
插入主要是使用push_back()，也可使用insert()；删除操作主要是pop_back()，也可使用erase()
*/
vector<int> v;
//尾插
v.push_back(10);
v.push_back(20);
v.push_back(30);
v.push_back(40);
v.push_back(50);
PrintVector(v);   // 10 20 30 40 50

//尾删
v.pop_back();
PrintVector(v);   // 10 20 30 40

//插入 - 提供迭代器
v.insert(v.begin(), 100);
PrintVector(v);   // 100 10 20 30 40

//重载
v.insert(v.begin()+1, 2, 50);
PrintVector(v);   // 100 50 50 10 20 30 40

// 插入
v.insert(v.begin()+3, 1);
PrintVector(v);   // 100 50 50 1 10 20 30 40

// 插入
// v.insert(v.end()+2, 2);
// PrintVector(v);   // ERROR

//删除 - 提供迭代器
v.erase(v.begin());  
PrintVector(v);   // 50 50 1 10 20 30 40

// 删除
vector<int>::iterator it = v.begin();
it+=2; // 迭代器往后偏移一个位置
v.erase(it);
PrintVector(v); // 50 50 10 20 30 40

//重载
v.erase(v.begin(), v.end());		//相当于清空操作
PrintVector(v);   // (空)

v.clear();		//清空容器中所有元素
PrintVector(v);   // (空)

/**
4）容量和大小：
对于容量用的是capacity()，对于大小是size()，当然你也可以用resize()来改变其大小，不够在此之前都需用empty()这个函数来判断一下容器是否为空；
size是指容器当前拥有元素的个数，而capacity是指容器在必须分配新的存储空间之前可以存放的元素总数。
*/
vector<int> v;

for (int i = 0; i < 10; ++i)
{
    v.push_back(i); 
}
PrintVector(v);  // 0 1 2 3 4 5 6 7 8 9 

if (v.empty())
{
    cout << "vector容器为空" << endl;  
}
else
{
    cout << "vector容器不为空" << endl;   // vector容器不为空
    cout << "vector容器的容量为：" << v.capacity() << endl;  // vector容器的容量为：16
    cout << "vector容器的大小为：" << v.size()<< endl;  // vector容器的大小为：10
}

//重新指定大小 - 变大
// v.resize(15);          //重载  // 0 1 2 3 4 5 6 7 8 9 0 0 0 0 0
v.resize(15,10);		//重载  // 0 1 2 3 4 5 6 7 8 9 10 10 10 10 10
PrintVector(v);  

//重新指定大小 - 变小
v.resize(5);
PrintVector(v);		//超过部分将会删除  // 0 1 2 3 4

/*5）其他
例如at()返回元素，front()返回首元素，back()返回尾元素，clear()清空容器等等
*/
vector<int> v;
for (int i = 0; i < 5; ++i)
{
    v.push_back(i);
}  // 0 1 2 3 4

//通过[]方式访问
for (int i = 0; i < v.size(); ++i)
{
    cout << v[i] << " ";
}  // 0 1 2 3 4
cout << endl;  

//通过at访问
for (int i = 0; i < v.size(); ++i)
{
    cout << v.at(i)<< " ";
}  // 0 1 2 3 4
cout << endl;

cout << "第一个元素为：" << v.front() << endl;   // 第一个元素为：0
cout << "最后一个元素为：" << v.back() << endl;  // 最后一个元素为：4
```

##### 2）**deque（双端队列）**

deque容器为双端队列，可以对其两段的数据进行操作，因为它没有capacity属性，因此不会像vector那样”旧空间不足而重新配置一块更大空间，然后复制元素，再释放旧空间”，因此，deque没有必须要提供所谓的空间保留(reserve)功能。

deque 容器中存储元素并不能保证所有元素都存储到连续的内存空间中。<img src="https://pic2.zhimg.com/v2-4b0bef4aeb1a0483c28c7584e8f98395_r.jpg" alt="img" style="zoom:85%;" />

```C++
#include <deque>  // 引用头文件
using namespace std;   // 注意需要引入标准命名空间

/* 基本操作与上述类似 */
/* 基本操作与上述类似 */
/* 基本操作与上述类似 */
void PrintDeque(deque<int>&d)
{
	for (deque<int>::iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << ' ';
	}
    // iterator 迭代器，相当于指针
	cout << endl;
}

/**
1）构造函数
基本同vector
*/
deque<int> d0{1,2,3,4,5,6,7,8,9,10}; //d被初始化成有10个元素
PrintDeque(d0);        // 1 2 3 4 5 6 7 8 9 10

deque<int> d1;
for (int i = 0; i < 10; ++i)
{
    d1.push_back(i);   // 0 1 2 3 4 5 6 7 8 9 
}

deque<int> d2(d1);     // 0 1 2 3 4 5 6 7 8 9 

deque<int> d3(10, 100);  // 100 100 100 100 100 100 100 100 100 100

deque<int> d4;
d4 = d3;  // 100 100 100 100 100 100 100 100 100 100

/**
2）赋值操作
*/
deque<int> d1;

for (int i = 0; i < 10; ++i)
{
    d1.push_back(i);  // 0 1 2 3 4 5 6 7 8 9 
}

deque<int> d2;
d2 = d1; // 0 1 2 3 4 5 6 7 8 9 

deque<int> d3; // 0 1 2 3 4 5 6 7 8 9 
d3.assign(d1.begin(), d1.end());//将[beg, end)区间中的数据拷贝赋值给本身

deque<int> d4;
d4.assign(10, 100);  // 100 100 100 100 100 100 100 100 100 100

d4.swap(d3);
PrintVector(d4);   // 0 1 2 3 4 5 6 7 8 9 
/**
3）容量和大小：
deque容器无capacity()函数。
*/
if (d1.empty())
{
    cout << "deque容器为空" << endl;
}
else
{
    cout << "deque容器不为空" << endl;
    cout << "deque容器的大小为：" << d1.size() << endl;
    //deque容器无capacity - 容量
}

//改变大小
//d1.resize(15);
d1.resize(15,1);
PrintDeque(d1);  // 0 1 2 3 4 5 6 7 8 9 1 1 1 1 1

d1.resize(5);
PrintDeque(d1);  // 0 1 2 3 4

/**
4）插入和删除
对于双端队列来说，插入和删除时一个亮眼的地方，因为首尾均可操作，有头插push_front()，头删pop_front()，尾插push_back()，尾删pop_back()，以及inset()插入和erase()删除
*/
//首尾操作
deque<int> d;

d.push_back(10);
d.push_back(20);		//尾插

d.push_front(100);
d.push_front(200);		//头插

PrintDeque(d);	//200 100 10 20

d.pop_back();	//尾删
d.pop_front();	//头删
PrintDeque(d);	//100 10

d.insert(d.end(), 200);
PrintDeque(d);  //100 10 200

d.insert(d.begin(), 2, 900);
//900 900 100 10 200
PrintDeque(d);

deque<int>::iterator it = d.begin();
it++; // 迭代器往后偏移一个位置
d.erase(it);
PrintDeque(d); // 900 100 10 200

d.erase(d.begin(), d.end());
PrintDeque(d); // (空)

d.clear();
PrintDeque(d); // (空)
```

##### 3）list（列表[双向循环链表]）

**该容器的底层是以双向链表的形式实现的。这意味着，list 容器中的元素可以分散存储在内存空间里，而不是必须存储在一整块连续的内存空间中。**

list 容器中各个元素的前后顺序是靠[指针](http://c.biancheng.net/c/80/)来维系的，每个元素都配备了 2 个指针，分别指向它的前一个元素和后一个元素。其中第一个元素的前向指针总为 null，因为它前面没有元素；同样，尾部元素的后向指针也总为 null。

基于这样的存储结构，list 容器具有一些其它容器（array、vector 和 deque）所不具备的优势，即它可以在序列已知的任何位置快速插入或删除元素（时间复杂度为`O(1)`）。并且在 list 容器中移动元素，也比其它容器的效率高。

使用 list 容器的缺点是，它不能像 array 和 vector 那样，通过位置直接访问元素。举个例子，如果要访问 list 容器中的第 6 个元素，它不支持`容器对象名[6]`这种语法格式，正确的做法是从容器中第一个元素或最后一个元素开始遍历容器，直到找到该位置。

list容器不能随机访问元素，也就是迭代器只能只能++,不能一次性跳转；<img src="https://pic2.zhimg.com/80/v2-5221ebbe7de761d9c3d012c9cd190f79_720w.webp" alt="img" style="zoom:75%;" />

> 1）构造函数
> list(beg,end);//构造函数将[beg, end)区间中的元素拷贝给本身。
> list(n,elem);//构造函数将n个elem拷贝给本身。
>
> 2）赋值操作
>
> assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。
> assign(n, elem);//将n个elem拷贝赋值给本身。
> swap(lst);//使用之后实现将lst与本身的元素互换。
>
> 3）插入和删除操作
>
> push_back(elem);//在容器尾部加入一个元素
> pop_back();//删除容器中最后一个元素
> push_front(elem);//在容器开头插入一个元素
> pop_front();//从容器开头移除第一个元素
> insert(pos,elem);//在pos位置插elem元素的拷贝，返回新数据的位置。
> insert(pos,n,elem);//在pos位置插入n个elem数据，无返回值。
> insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值。
> clear();//移除容器的所有数据
> erase(beg,end);//删除[beg,end)区间的数据，返回下一个数据的位置。
> erase(pos);//删除pos位置的数据，返回下一个数据的位置。
> remove(elem);//删除容器中所有与elem值匹配的元素。

```C++
#include <list>
using namespace std;   // 注意需要引入标准命名空间

/* 基本操作与上述类似 */
/* 基本操作与上述类似 */
/* 基本操作与上述类似 */
void PrintList(list<int> &l)
{
	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << ' ';
	}
	// iterator 迭代器，相当于指针
	cout << endl;
}

list<int> l1{1,2,3,4,5,6,7,8,9,10};
PrintList(l1);
list<int> l2(3, 100); // 100 100 100

l1.push_back(50);  //在容器尾部加入一个元素
PrintList(l1);     // 0 1 2 3 4 5 6 7 8 9 
l1.pop_back();     //删除容器中最后一个元素
PrintList(l1);     // 0 1 2 3 4 5 6 7 8 9 50
l1.push_front(-10);//在容器开头插入一个元素
PrintList(l1);     // -10 0 1 2 3 4 5 6 7 8 9
l1.pop_front();    //从容器开头移除第一个元素
PrintList(l1);     // 0 1 2 3 4 5 6 7 8 9 
list<int>::iterator it;//定义一个迭代器指针
it=l1.begin();    
it++;   // 注意！这里it 只有最基础的 ++ 操作，详细原因见：C++迭代器详解
l1.insert(it,20);  //在pos位置插elem元素的拷贝，返回新数据的位置。
PrintList(l1);     // 0 20 1 2 3 4 5 6 7 8 9  // 注意 list 顺序与未插入时相同
it++;             
l1.insert(it,3,10);//在pos位置插入n个elem数据，无返回值。
PrintList(l1);     // 0 20 1 10 10 10 2 3 4 5 6 7 8 9  // 注意 list 顺序始终与未插入时相同
it++;             
l1.insert(it,l2.begin(),l2.end());//在pos位置插入[beg,end)区间的数据，无返回值。
PrintList(l1);     // 0 20 1 10 10 10 2 100 100 100 3 4 5 6 7 8 9  // 注意 list 顺序始终与未插入时相同
l1.erase(it);      
PrintList(l1);     // 0 20 1 10 10 10 2 100 100 100 4 5 6 7 8 9    // 注意 list 顺序始终与未插入时相同
l1.remove(100);    //删除容器中所有与elem值匹配的元素。
PrintList(l1);     // 0 20 1 10 10 10 2 4 5 6 7 8 9
l1.clear();        //移除容器的所有数据
PrintList(l1);     // (空)
```

##### 4）forword_list（单向链表）

对于forword_list单向链表，虽然它具有和 list 容器相同的特性，擅长在序列的任何位置进行插入元素或删除元素的操作，但对于访问存储的元素，没有其它容器（如 array、vector）的效率高，以及由于单链表没有双向链表那样灵活，因此相比 list 容器，单链表只能从前向后遍历，而不支持反向遍历

>#include <forward_list>
>3）常用API操作
>
>begin()		//返回一个前向迭代器，其指向容器中第一个元素的位置。	
>end()		//返回一个前向迭代器，其指向容器中最后一个元素之后的位置。
>assign()	//用新元素替换容器中原有内容。
>push_front()	//在容器头部插入一个元素。
>pop_front()		//删除容器头部的一个元素。
>swap()			//交换两个容器中的元素，必须保证这两个容器中存储的元素类型是相同的。
>remove(val)		//删除容器中所有等于 val 的元素
>sort()			//通过更改容器中元素的位置，将它们进行排序。

##### **5）array（数组）**

array是C++11中新增的容器，它与其他容器不同的是，它的大小是固定的，无法动态扩展或收缩，只允许访问或者替换存储的元素。

>#include <array>
>
>array<\*int\*, 5> a = {1, 2, 3, 4, 5};
>for (\*auto\* i : a)
>{
>  cout << "value is " << i << endl;
>}

#### 21.5 [关联式容器](http://c.biancheng.net/view/7166.html)

##### 0）pair用法

关联式容器存储的是“键值对”形式的数据，比如：`<"C语言教程", "http://c.biancheng.net/c/">`，其中第一个元素作为键（key），第二个元素作为值（value）。

考虑到“键值对”并不是普通类型数据，C++ STL标准库提供了 pair 类模板，其专门用来将 2 个普通元素 first 和 second（可以是 C++ 基本数据类型、结构体、类自定的类型）创建成一个新元素`<first, second>`。

```C++
#include <utility>      // pair
// 调用构造函数 1，也就是默认构造函数
pair <string, double> pair1;
// 调用第 2 种构造函数
pair <string, string> pair2("STL教程","http://c.biancheng.net/stl/");  
// 调用拷贝构造函数
pair <string, string> pair3(pair2);
//调用移动构造函数
pair <string, string> pair4(make_pair("C++教程", "http://c.biancheng.net/cplus/"));
// 调用第 5 种构造函数
pair <string, string> pair5(string("Python教程"), string("http://c.biancheng.net/python/"));  

cout << "pair1: " << pair1.first << " " << pair1.second << endl;
cout << "pair2: "<< pair2.first << " " << pair2.second << endl;
cout << "pair3: " << pair3.first << " " << pair3.second << endl;
cout << "pair4: " << pair4.first << " " << pair4.second << endl;
cout << "pair5: " << pair5.first << " " << pair5.second << endl;
```

##### 1）map容器

```C++
#include <map>
#include <iostream>
#include <string>
using namespace std;   // 注意需要引入标准命名空间

/************** 容器的创建 **************/
map<string, int>myMap;  // 创建空容器
map<string, int>myMap{ {"C语言教程",10},{"STL教程",20} };  // 创建时初始化
map<string, int>myMap{make_pair("C语言教程",10),make_pair("STL教程",20)};  // 使用pair初始化
map<string, int>newMap(myMap);  // 利用先前已创建好的 map 容器，再创建一个新的 map 容器

//创建空 map 容器，默认根据个键值对中键的值，对键值对做降序排序
map<string, string, greater<string>>myMap;

//调用 emplace() 方法，直接向 myMap 容器中指定位置构造新键值对
//insert()，插入新键值对
myMap.emplace("C语言教程","http://c.biancheng.net/c/");
myMap.insert(pair<string, string>("Python教程", "http://c.biancheng.net/Python/"));
myMap.insert(make_pair("Python教程", "http://c.biancheng.net/Python new/"));  //这样写也可
// 注意无法插入重复元素，所以上述重复写法无效，不会修改键值，"Python教程" 仍然对应 "http://c.biancheng.net/Python new/"

// [] 运算符确实有“为 map 容器添加新键值对”的功能，但前提是要保证新添加键值对的键和当前 map 容器中已存储的键值对的键都不一样。
myMap["STL教程"]="http://c.biancheng.net/java/";
myMap["STL教程"] = "http://c.biancheng.net/stl/";    
// 由于键值相同，代码的作用就变成了修改该键对应的值，而不再是为 map 容器添加新键值对。

//输出当前 myMap 容器存储键值对的个数
cout << "myMap size==" << myMap.size() << endl;  // myMap size==3

/************** 键值的访问 **************/
//判断当前 myMap 容器是否为空
if (!myMap.empty()) {
    //借助 myMap 容器迭代器，将该容器的键值对逐个输出
    for (auto i = myMap.begin(); i != myMap.end(); ++i) {
        cout << i->first << " " << i->second << endl;
    }
}  
/*
STL教程 http://c.biancheng.net/stl/
Python教程 http://c.biancheng.net/Python/
C语言教程 http://c.biancheng.net/c/
*/

// 直接使用[]访问键值
string cValue = myMap["C语言教程"];
cout << cValue << endl;  // http://c.biancheng.net/c/

// 使用find访问键值
// 注意该方法返回的是一个迭代器
map< std::string, std::string >::iterator myIter = myMap.find("C语言教程");
cout << myIter->first << " " << myIter->second << endl;
// C语言教程 http://c.biancheng.net/c/

myMap.erase("C语言教程");   // 删除 C语言教程
```

##### 2）multimap 容器

multimap 容器 支持 map 的所有操作，此外，multimap 容器 可存储多个具有相同键的键值对。

```C++
#include <iostream>
#include <map>  //map
using namespace std;   

//创建并初始化 multimap 容器
multimap<char, int>mymultimap{ {'a',10},{'b',20},{'b',15}, {'c',30} };
//输出 mymultimap 容器存储键值对的数量
cout << mymultimap.size() << endl;     // 4
//输出 mymultimap 容器中存储键为 'b' 的键值对的数量
cout << mymultimap.count('b') << endl; // 2

for (auto iter = mymultimap.begin(); iter != mymultimap.end(); ++iter) {
    cout << iter->first << " " << iter->second << endl;
}
/*
a 10
b 20
b 15
c 30
*/

// 注意 multimap 容器 不支持 []，at()，运算符
```

##### 3）set容器

使用 set 容器存储的各个键值对，**要求键 key 和值 value 必须相等**。


```C++
{<'a', 1>, <'b', 2>, <'c', 3>}        // 不合法
{<'a', 'a'>, <'b', 'b'>, <'c', 'c'>}  // 合法
```

基于 set 容器的这种特性，当使用 set 容器存储键值对时，只需要为其提供各键值对中的 value 值（也就是 key 的值）即可。仍以存储上面第 2 组键值对为例，只需要为 set 容器提供 {'a','b','c'} ，该容器即可成功将它们存储起来。

```C++
#include <iostream>
#include <set>
#include <string>
using namespace std;

//创建时就初始化
std::set<std::string> myset2{"http://c.biancheng.net/java/",
                            "http://c.biancheng.net/stl/",
                            "http://c.biancheng.net/python/"};
//创建空set容器
set<string> myset;
//空set容器不存储任何元素
cout << "1、myset size = " << myset.size() << endl;   // 1、myset size = 0
//向myset容器中插入新元素
myset.insert("http://c.biancheng.net/java/");
myset.insert("http://c.biancheng.net/stl/");
myset.insert("http://c.biancheng.net/python/");
cout << "2、myset size = " << myset.size() << endl;   // 2、myset size = 3
//利用双向迭代器，遍历myset
for (auto iter = myset.begin(); iter != myset.end(); ++iter) {
    cout << *iter << endl;
/*
http://c.biancheng.net/java/
http://c.biancheng.net/python/
http://c.biancheng.net/stl/
*/
}
```

##### 4）multiset容器

multiset 容器可以存储多个值相同的元素，其余特性与 set 类似


#### 21.6 容器适配器 详解

##### 1）stack（堆栈）

stack为堆栈，上文提到过，其内部元素都是需要先进后出（FILO）的，也就是说只有栈顶的元素top才可以被访问到<img src="https://pic3.zhimg.com/80/v2-778f957d4f631fcccad0c52afe239ed6_720w.webp" alt="img" style="zoom:70%;" />

```C++
#include <stack>
using namespace std;

stack<int> s;

s.push(10);
s.push(20);
s.push(30);
s.push(40);		//入栈

cout<<"栈的大小\t栈顶元素" << endl;
while (!s.empty())
{
    cout <<  s.size() <<"\t\t" << s.top() << endl;
    s.pop();	//出栈
}

cout << "出栈后的大小为：" << s.size() << endl;

/*
栈的大小        栈顶元素
4               40
3               30
2               20
1               10
出栈后的大小为：0
*/
```

##### 2）**queue（队列）**

queue为队列，它和stack堆栈的正好相反，栈是先进后出，而队列则是先进先出(FIFO)。
<img src="https://pic2.zhimg.com/v2-179efac7476f0e2f09bd41789a074e9d_r.jpg" alt="img" style="zoom:70%;" />

```c++
#include <queue>
using namespace std;

queue<int> q;

q.push(10);
q.push(20);
q.push(30);
q.push(40);		//入栈

cout << "队列大小\t队头元素\t队尾元素" << endl;
while (!q.empty())
{
    cout <<  q.size() <<"\t\t" << q.front() << "\t\t" << q.back() << endl;
    q.pop();	//出栈
}

cout << "出栈后的大小为：" << q.size() << endl;
/*
队列大小        队头元素        队尾元素
4               10              40
3               20              40
2               30              40
1               40              40
出栈后的大小为：0
*/

```

##### **3） pirority_queue（优先队列）**

可以自定义中数据的优先级, 让优先级高的排在队列前面,优先出队

> #include <queue>
>
> priority_queue<Type, Container, Functional>
> Type 就是数据类型; Container 就是容器类型; Functional 就是比较的方式;
>
> greater呈上升，less呈下降，自然对应的就是升序队列和降序队列

```C++
//升序队列（小顶堆）- 优先输出最小的
priority_queue <int,vector<int>,greater<int> > q;
//降序队列（大顶堆）- 优先输出最大的[默认]
priority_queue <int,vector<int>,less<int> >q;

priority_queue<int,vector<int>,greater<int>> q;

q.push(9);
q.push(2);
q.push(7);
q.push(3);
q.push(-8);
q.push(1);

while (!q.empty())
{
    cout << q.top() << " ";
    q.pop();
}
cout<<endl;   // -8 1 2 3 7 9
```

**[C++中STL用法超详细总结](https://blog.csdn.net/u010183728/article/details/81913729)**



### 22. [C++ 预处理器](https://www.runoob.com/cplusplus/cpp-preprocessor.html)

基本等同于C语言，详见**[C语言 6 节 C预处理](.\C语言 语法汇总)**。



### 23. [C++ 数字](https://www.runoob.com/cplusplus/cpp-numbers.html)

C++需要引用库 **\<cmath>、\<cstdlib>** ，此外基本等同于C语言，详见**[C语言 25.4 节 C标准库 math.h、25.1节 随机数](.\C语言 语法汇总)**。



### 24. [C++ 时间](https://www.runoob.com/cplusplus/cpp-date-time.html)

C++需要引用库 **\<ctime>** ，此外基本等同于C语言，详见**[C语言 25.5 节 C标准库 time.h](.\C语言 语法汇总)**。



### 25. C++ 其他

**[C++ 文件和流](https://www.runoob.com/cplusplus/cpp-files-streams.html)**
**[C++ 异常处理](https://www.runoob.com/cplusplus/cpp-exceptions-handling.html)**

注意：C语言也有这两部分，不过差别较大。

#### 25.1 **[C++ STL 教程](https://www.runoob.com/cplusplus/cpp-stl-tutorial.html)**

> STL(标准模板库)，是目前C++内置支持的library。它的底层利用了C++类模板和函数模板的机制，由三大部分组成：容器、算法和迭代器。
>
> 目前STL有六大组件：
> - 容器 container
> - 算法 algorthm
> - 迭代器 iterator
> - 仿函数 function object
> - 适配器 adaptor
> - 空间配置器 allocator





## 二、C++ 类与对象

### 1. [C++ 类与对象基础知识](https://www.runoob.com/cplusplus/cpp-classes-objects.html)

**1.1 类的定义**
类定义是以关键字 class 开头，后跟类的名称。类的主体是包含在一对花括号中。类定义后必须跟着一个分号或一个声明列表。
<img src="https://www.runoob.com/wp-content/uploads/2015/05/cpp-classes-objects-2020-12-10-11.png" alt="img" style="zoom:80%;" />

**1.2 对象的定义**

```C++
class Box
{
   public:
      double length;   // 盒子的长度
      double breadth;  // 盒子的宽度
      double height;   // 盒子的高度
};    // 定义Box类

Box Box1, Box2;          // 声明 Box1,Box2 对象 ，其类型为 Box
```

**1.3 类 数据成员访问**
类的对象的**公共数据成员**可以使用直接成员访问运算符 **`.`** 来访问：
<img src="https://www.runoob.com/wp-content/uploads/2015/05/cpp-classes-objects-2020-12-10-11-2.png" alt="img" style="zoom:90%;" />
注意：私有的成员和受保护的成员不能使用直接成员访问运算符 **`.`** 来直接访问
例：

```C++
#include <iostream>
using namespace std;
 
class Line {
   public:
      double length;   // 长度
      // 成员函数声明
      double get(void);
      void set( double len );
};
// 成员函数定义
double Line::get(void) {
    return length;
}
void Line::set( double len ) {
    length = len;
}

int main() {
   Line Line1;        // 声明 Line1，类型为 Line 
   Line1.length = 6.0;       // Line1的成员数据length为6
   cout << "Line1 的长度：" << Line1.length <<endl;  // 输出 Line1的成员数据length
   Line1.set(16.0);          // 调用Line1的成员函数set()
   cout << "Line1 的长度：" << Line1.get() <<endl;   // 调用Line1的成员函数get()
   return 0;
}
```
**补充知识点：** `::` 在 C++ 中的作用，详见**[评论笔记10](https://www.runoob.com/cplusplus/cpp-tutorial.html)**
**1.5 面相对象编程常见概念解析**
<img src="https://www.runoob.com/wp-content/uploads/2013/12/oopxxx.png" alt="img" style="zoom:90%;" />



### 2. [C++ 类成员函数](https://www.runoob.com/cplusplus/cpp-class-member-functions.html)

**类的成员函数**是指那些把定义和原型写在类定义内部的函数，就像类定义中的其他变量一样。类成员函数是类的一个成员，它可以操作类的任意对象，可以访问对象中的所有成员。

如定义的类 **Box** ，`double getVolume(void);`，  `void set( double len, double bre, double hei );`  等，即为类成员函数。

**类成员函数定义方法：**
① 直接**在类内部定义**，如：`void setVolume( double len, double bre, double hei )`等，不推荐使用。
② 单独使用**范围解析运算符 ::** 来定义；如：`double getVolume(void);`等；
建议使用第二种成员函数定义方法。示例如下

**类成员函数调用**，是在对象上使用点运算符（**.**），示例如下。

**补充：**在**类定义中定义的成员函数**把函数声明为**内联**的，即便没有使用 inline 标识符。
如：`void setVolume( double len, double bre, double hei )`等；
&nbsp;           在类外定义的成员函数，只有使用 `inline`声明，才为内联函数 。如：`inline void Box::setHeight( double hei )`；
内联函数参考**[C语言 15.7.3 节 ](.\C语言 语法汇总)**。

**补充：**  **::** 叫作用域区分符，指明一个函数属于哪个类或一个数据属于哪个类。
&nbsp;             **::** 可以不跟类名，表示全局数据或全局函数。

```C++
#include <iostream>
using namespace std;
 
class Box
{
   public: 
      double length;   // 长度
      double breadth;  // 宽度
      double height;   // 高度
   	  double valume;   // 体积

      // 成员函数声明
      void setVolume( double len, double bre, double hei )
      {   // 成员函数在类内部定义
          length = len;
  		  breadth = bre;
 	      height = hei;
      }
      void setVol(double valume);
      double getVolume(void);
};
// 成员函数使用范围解析运算符 ::来定义，包括构造函数，推荐使用此方法。
inline void Box::setVol(double val)   // inline 作用为：声明为内联函数 
{
    valume = val;
}
double Box::getVolume()               // 不使用inline，函数为普通类成员函数
{
    valume = length * breadth * height;
    return valume;
}

int main()
{
   Box Box1;    // 声明 Box1
   double volume = 0.0;     // 用于存储体积
   // box1 详述
   Box1.setVolume(16.0, 8.0, 12.0); 
   volume = Box1.getVolume(); 
   cout << "Box1 的体积：" << volume <<endl;   // Box1 的体积：1536
   return 0;
}
```



### 3. [C++ 类访问修饰符](https://www.runoob.com/cplusplus/cpp-class-access-modifiers.html)

关键字 **`public、private、protected`** 称为访问修饰符。

一个类可以有多个 public、protected 或 private 标记区域。每个标记区域在下一个标记区域开始之前或者在遇到类主体结束右括号之前都是有效的。成员和类的**默认访问修饰符** (即类里面不写是什么类型) 是 **private**。

| 访问修饰符 | 类外部是否可访问 | 友元函数是否可访问 | 派生类（即子类）是否可访问 |
| ---------- | ---------------- | ------------------ | -------------------------- |
| public     | 是               | 是                 | 是                         |
| protected  | 否               | 是                 | 是                         |
| private    | 否               | 是                 | 否                         |

一般会在私有区域定义数据，在公有区域定义相关的函数，以便在类的外部也可以调用这些函数；

```C++
class Box
{     // 默认访问修饰符为private
      double length1;   
      double breadth1;  
      double height1;  
   	  double valume1;   
      double getVolume1(void){}
      void setVolume1( double len, double bre, double hei ){}
   public: 
      double length2;   
      double breadth2;  
      double height2;  
   	  double valume2;   
      double getVolume2(void){}
      void setVolume2( double len, double bre, double hei ){}
};

int main()
{
   Box Box1;    // 声明 Box1
   Box1.length2 = 5.0   // 正确，public变量可以在类外部使用 
   Box1.length1 = 5.0   // ERROR，private变量不可在类外部使用 
   Box1.getVolume2()    // 正确，public变量可以在类外部使用 
   Box1.getVolume1()    // ERROR，private变量不可在类外部使用 
   return 0;
}
```



### 4. [C++ 类构造函数 & 析构函数](https://www.runoob.com/cplusplus/cpp-constructor-destructor.html)

类的**构造函数**是类的一种特殊的成员函数，它会在每次创建类的新对象时执行，
如：`Box()`、`Box( double len, double bre, double hei )`；
如果用户不定义构造函数，则编译器会自行定义一个；
一个类可以有多个构造函数。
构造函数允许使用**初始化列表**来初始化字段，详见例程。

类的**析构函数**是类的一种特殊的成员函数，它会在每次删除所创建的对象时执行。
它不会返回任何值，也不能带有任何参数。
一个类只能有一个析构函数。

**构造函数及其他相关知识点如下：**

```C++
/************ 构造函数基础知识 ************/
#include <iostream>
using namespace std;
 
class Box
{
   private:
      double length;   // 长度
      double breadth;  // 宽度
      double height;   // 高度   
   public: 
      Box();  // 构造函数1
      Box( double len, double bre, double hei );  // 构造函数2
      // 成员函数声明
      double getVolume(void);
      ~Box();  // 析构函数
};
// 成员函数使用范围解析运算符 ::来定义，包括构造函数，推荐使用此方法。
Box::Box()   // 构造函数1
{
    cout << "调用构造函数1" << endl;
}
Box::Box( double len, double bre, double hei )  // 构造函数2 (可以有多个构造函数)
{
    length = len;
  	breadth = bre;
 	height = hei;
    cout << "调用构造函数2" << endl;
}
double Box::getVolume()
{
    return length * breadth * height;
}
Box::~Box(void)
{
    cout << "调用析构函数" << endl;
}

int main( )
{
   Box Box1;   // 定义对象时，将会输出：调用构造函数1
   Box Box2(10.0, 20.0, 15.0);   // 定义对象时，将会输出：调用构造函数2
   Box Box3(); // 会弹出警告，empty parentheses were disambiguated as a function declaration ，对象创建失败
               // 这里声明了一个函数，没有传入的参数，返回值为类类型
               // 因此，即使构造函数参数为空，如：Box()，定义的对象后也不可加()
   double volume = 0.0;     // 用于存储体积

   volume = Box2.getVolume(); 
   cout << "Box2 的体积：" << volume <<endl;   // Box2 的体积：3000
    
   return 0;   // 程序运行结束，释放内存，调用析构函数，将会输出2次：调用析构函数
}

/************ 使用初始化列表来初始化字段 ************/
Box::Box( double len, double bre, double hei ): length(len), breadth(bre), height(hei)
{
    cout << "Object is being created" << endl;
}
// 上面的语法等同于如下语法：
Box::Box( double len, double bre, double hei )
{
    length = len;
    breadth = bre;
    height = hei;
    cout << "Object is being created" << endl;
}
// 注意：如果成员变量的初始化依赖其他成员变量，如length(len), breadth(length), height(breadth)
// 则此时顺序要和前面变量声明 double length;…… double height; 顺序保持相同。
// 因为编译器按照 变量声明 double length;…… double height; 顺序，进行变量初始化，
// 而不是按照length(len), breadth(length), height(breadth) 顺序。
// 示例：
int a;   int b;
Student1(int i):b(i),a(b){ }    
// 先进行 a(b), 在进行 b(i); 此时a初始化异常
Student1(int i):a(i),b(a){ } 
// 先进行 a(i), 在进行 b(a); 初始化正常

/************ 使用初始化列表来初始化字段实例 ************/
#include <iostream>
using namespace std;

class Cpoint
{
private:
    int xp, yp;
public:
    // Cpoint() {}
    Cpoint(int x, int y) :xp(x), yp(y)   {}
    void show()
    {
        cout << "xp = " << xp << " ; yp = " << yp <<endl;
    }
};
class CRect
{
private:
    Cpoint mpt1, mpt2;
public:
    CRect(int x1, int x2) : mpt1(x1, x2), mpt2(x2, x1) {  }
    // /* 如果不使用此方法，则需要 */
    // CRect(int x1, int x2)
    // {
    //     Cpoint temp1(x1, x2),temp2(x2, x1);
    //     mpt1 = temp1;
    //     mpt2 = temp2;
    // }
    // 注意使用此方法，必须首先在 Cpoint 中定义 构造函数：`Cpoint() {}`，如注释内容，否则会报错
    // /* 不可行，报错 */
    // CRect(int x1, int x2)
    // {
    //     mpt1(x1, x2);
    //     mpt2(x2, x1);
    // }
    void show()
    {
        cout << "mpt1.show():  " ;
        mpt1.show();
        cout << "mpt2.show():  " ;
        mpt2.show();
    }
};
int main()
{
    CRect p(10,20);
    p.show();
    return 0;
}
/* 输出：
mpt1.show():  xp = 10 ; yp = 20
mpt2.show():  xp = 20 ; yp = 10
*/

/************ 默认构造函数 ************/
class Line
{  // 如果用户不定义构造函数，则此时编译器会自行定义一个构造函数，格式如下：
   public:
      Line(){}   // 这是构造函数
      ~Line(){}  // 这是析构函数
};

/************ 类对象初始化的时候加括号与不加括号区别 ************/
// 栈上
// warning C4930 : “A a(void)” : 未调用原型函数(是否是有意用变量定义的 ? )
A a();  // 这里声明了一个函数，没有传入的参数，返回值为类类型
A b;    // 默认调用“对象名()”这个构造函数构造对象

// 堆上,加括号不加括号无差别，都调用默认的构造函数
A *d = new A();
A *e = new A;

// 对于内置类型而言,加括号是进行了初始化，不加是未进行初始化
int *f = new int();
int *g = new int;

cout << *f << endl;   // 0
cout << *g << endl;   // 随机值-1163005939

/************ explicit 关键字作用 ************/
// explicit 可以阻止隐式转换的发生，具体应用如下：
class Test1
{
    int num;
public:
    Test1(int n) :num(n) {}  // 普通构造函数
};
class Test2
{
    int num;
public:
    explicit Test2(int n) :num(n) {}  // explicit(显式)构造函数
};
int main()
{
    Test1 t1=12;  // 隐式调用其构造函数,成功
    Test2 t2=12;  // 编译错误,不能隐式调用其构造函数
    Test2 t2(12); // 显式调用成功
    return 0;
}
```

##### 补充：匿名对象

**[C++匿名对象1](https://zhuanlan.zhihu.com/p/55728882)、[C++匿名对象2](https://blog.csdn.net/u014583317/article/details/108705360)**

**产生匿名对象的三种情况：**
1）以值的方式给函数传参；
&nbsp;     Cat(); —> 生成了一个匿名对象，执行完Cat( )代码后，此匿名对象就此消失。这就是匿名对象的生命周期。
&nbsp;     Cat cc = Cat(); —>首先生成了一个匿名对象，然后将此匿名对象变为了cc对象，其生命周期就变成了cc对象的生命周期。

2）类型转换；

3）函数需要返回一个对象时；return temp;

```C++
#include <iostream>
using namespace std;

class A
{
private:
	int i;
public:
	A()
	{
		cout << "调用构造函数1" << endl;
	}
	A(int s)
	{
		i = s;
		cout << "调用构造函数2" << endl;
	}
	void myshow()
	{
		cout << i << endl;
	}
    ~A()
    {
        cout<<"调用析构函数"<<endl;
    }
};

int main()
{
    // 正常创建对象方法
    A zc1;           // 创建zc1对象，
    A zc2(5);        // 创建zc2对象，
    
    // 以下对象创建用到了匿名对象
    A(10);           // A(10)为匿名对象
	A(10).myshow();  // A(10)为匿名对象
                     // 执行完此行代码，因为外部没有接此匿名对象的变量，此匿名又被析构了
    A b = A(11);     // 当匿名对象有等待初始化的对象接的时候，只调用一次构造和析构函数
    				 // A(11)匿名对象变为实例对象
	A a = 12;        // 此处发生隐身转换，相当于 A a = A(12); 此处的A(12)就是一个匿名对象

	A c;	         // 调用一次构造函数
	c = A(13);       // 此处为赋值，此处的匿名对象会调用一次构造函数
	return 0;
}

/* 输出：
调用构造函数1
调用构造函数2
调用构造函数2
调用析构函数
调用构造函数2
10
调用析构函数
调用构造函数2
调用构造函数2
调用构造函数1
调用构造函数2
调用析构函数
调用析构函数
调用析构函数
调用析构函数
调用析构函数
调用析构函数
*/
```



### 5. [C++ 拷贝构造函数](https://www.runoob.com/cplusplus/cpp-copy-constructor.html)

**拷贝构造函数**是一种特殊的构造函数，它在创建对象时，是使用同一类中之前创建的对象来初始化新创建的对象。
拷贝构造函数通常用于：

- 通过使用另一个同类型的对象来初始化新创建的对象。
- 复制对象把它作为参数传递给函数。
- 复制对象，并从函数返回这个对象。

拷贝构造函数的最常见形式如下：`classname (const classname &obj) { /*构造函数的主体*/ }`
`&` 在这里表示引用；**因为只有定义 拷贝构造函数 之后，类 才可以赋值**；所以拷贝构造函数必须使用引用传递；`const` 限定不对传入参数进行修改。

拷贝构造函数示例如下：

```C++
/************ 拷贝构造函数实例 ************/
#include <iostream>
using namespace std;
 
class Box
{
   public: 
   	  double valume;   // 体积
      Box(double val);  // 构造函数1
      Box( const Box &obj);      // 拷贝构造函数，使用&表示引用传参
      ~Box();  // 析构函数
};
Box::Box(double val)   // 构造函数1
{
    valume = val;
    cout << "调用构造函数1" << endl;
}
Box::Box( const Box &obj)  // 拷贝构造函数，使用&表示引用传参
{
    valume = obj.valume;
    cout << "调用拷贝构造函数" << endl;
}
Box::~Box(void)
{
    cout << "调用析构函数" << endl;
}
void display(Box obj)   // 全局函数，传入的是对象
{
   cout << "valume 大小 : " << obj.valume <<endl;
}  // 因为valume 是 public 变量，所以可以直接使用，否则必须声明为友元函数。

int main()
{
   Box Box1(100.0);  // 调用构造函数1
   Box Box2(Box1);   // 调用拷贝构造函数创建对象，也可写为：Box2 = Box1; ，输出：调用拷贝构造函数
   display(Box2);    
   // 函数传参，创建临时obj变量，调用拷贝构造函数；
   // 函数结束，需要销毁临时obj变量，调用析构函数；
   return 0;   // 调用两次析构函数
}

// 输出结果
/*
调用构造函数1
调用拷贝构造函数 
调用拷贝构造函数 
valume 大小 : 100
调用析构函数
调用析构函数
调用析构函数
*/
```

**注意：**只包含类 类型成员或内置类型（但不是指针类型）成员的类，无须显式地定义拷贝构造函数也可以拷贝；系统会调用**默认的拷贝构造函数**，它能够完成成员的**一一复制**。
&nbsp;          有的类有一个数据成员是**指针**，或者是有成员表示在构造函数中分配的其他资源 **(动态内存分配)**，这两种情况下都**必须定义**拷贝构造函数。

**原因为：**如果对象的数据成员是指针，使用默认拷贝构造函数，两个指针对象实际上指向的是同一块内存空间。当对象快结束时，会调用两次析构函数，而导致指针悬挂现象，产生错误。因此必须定义拷贝构造函数。

示例如下：

```C++
/************ 拷贝构造函数指针实例 ************/
#include <iostream>
using namespace std;
 
class Line
{
   int *ptr;
   
   public:
      int getLength( void );
      Line( int len );             // 简单的构造函数
      Line( const Line &obj);      // 拷贝构造函数
      ~Line();                     // 析构函数
};
// 成员函数定义，包括构造函数
Line::Line(int len)
{
    cout << "调用构造函数" << endl;
    // 为指针分配内存
    ptr = new int;
    *ptr = len;
}
Line::Line(const Line &obj)
{
    cout << "调用拷贝构造函数并为指针 ptr 分配内存" << endl;
    ptr = new int;
    *ptr = *obj.ptr; // 拷贝值
}
Line::~Line(void)
{
    cout << "释放内存" << endl;
    delete ptr;
}
int Line::getLength( void )
{
    return *ptr;
}
// 全局函数，传入的是对象
void display(Line obj)  
{
   cout << "line 大小 : " << obj.getLength() <<endl;
   //  cout << "line 大小 : " << obj.*ptr <<endl;   ERROR，因为 ptr 是私有成员
} 
Line newline(double len)  
{
    Line temp_line(len);
    return temp_line;
}
//
// Line &newline(double len)   // 返回值需要为引用，否则无法实现变量创建，具体原因未知
// {
//     static Line temp_line(len);
//     return temp_line;
// }
// 使用该方法定义函数，
// 之后main函数，line1 = newline(8);，
// 此时display(line1); line 大小 : 8
//
int main()
{
   Line line1(10);  // 调用构造函数
   Line line2 = line1;   // 也可写为：Line Line2(Line1);   // 调用拷贝构造函数并为指针 ptr 分配内存
   display(line1);      // 一个对象以值传递的方式传入函数体
   // 函数传参，创建临时obj变量，调用拷贝构造函数并为指针 ptr 分配内存
   // 函数结束，需要销毁临时obj变量，调用析构函数,释放内存
   display(line2);
   // 函数传参，创建临时obj变量，调用拷贝构造函数并为指针 ptr 分配内存
   // 函数结束，需要销毁临时obj变量，调用析构函数,释放内存
   line1 = newline(8);  // 一个对象以值传递的方式从函数返回
   display(line1);      // 这里ERROR，系统并未调用拷贝构造函数，而是简单的指针传值，原因未知。
   return 0;   //  调用两次析构函数释放内存
}

// 输出结果
/*
调用构造函数
调用拷贝构造函数并为指针 ptr 分配内存
调用拷贝构造函数并为指针 ptr 分配内存
line 大小 : 10
释放内存
调用拷贝构造函数并为指针 ptr 分配内存
line 大小 : 10
释放内存
调用构造函数
释放内存
调用拷贝构造函数并为指针 ptr 分配内存
line 大小 : -1163005939
释放内存
释放内存
释放内存
*/
```

#### 5.1 **类对象**作为 函数参数 传参方法：
**`classname obj `** 表示**值传递**，类似函数**值传递**，注意在函数内部修改形参值，函数外部对象实参值不会被修改； 
**`classname &obj `** 表示**引用传递**，类似函数**引用传递**，在函数内部修改形参值，函数外部对象实参值也会被修改； 
**`const classname obj `** 表示**常量值传递**，传入的 对象 不可进行任何修改； 
**`const classname &obj`** 表示**常值引用传参**，传入的 对象 不可进行任何修改； 此时使用引用，由于不新建对象，节省内存。

在使用值传递时，
一般 类 内部成员函数，使用**`const classname &obj`**  值传递；
其他需要用到类的函数 (如：友元函数)，使用**`classname obj `** 值传递即可；使用**`const`**会发生错误。



### 6. [C++ 友元函数](https://www.runoob.com/cplusplus/cpp-friend-functions.html)

类的友元函数是**定义在类外部**，但**有权访问类的所有私有（private）成员和保护（protected）成员**。尽管友元函数的原型有在类的定义中出现过，但是友元函数并不是成员函数。
因为友元函数**没有this指针**，要访问类的成员时，需要对象做参数；
友元可以是一个函数，该函数被称为友元函数；友元也可以是一个类，该类被称为友元类，在这种情况下，整个类及其所有成员都是友元。
如果要声明函数为一个类的友元，需要在类定义中该函数原型前使用关键字 **friend**；

示例如下：

```C++
/************ 友元函数 ************/
#include <iostream>
using namespace std;
 
class Line
{
   double len;
public:
   Line( double line );
   void setLine( double line );
   double getLine(); 
   friend void display1( Line line );   // 声明友元函数
};
// 成员函数定义
Line::Line( double line )
{
    len = line;
}
void Line::setLine( double line )
{
    len = line;
}
double Line::getLine()
{
    cout << "Length of box : " << len <<endl;
    return len;
}
// 请注意：display1() 不是任何类的成员函数
void display1( Line line )
{
    /* 因为 display1() 是 Box 的友元，它可以直接访问该类的任何成员 */
    cout << "Length of box : " << line.len <<endl;
}
void display2( Line line )   // 普通函数
{
    line.getLine();   //  box.getLine(); 为 公有成员
    // cout << "Length of box : " << box.len <<endl;  ERROR 因为 box.len 为私有成员
}

// 程序的主函数
int main()
{
   Line line1(10.0);
   // 使用友元函数输出宽度
   display1( line1 );   // Length of box : 10
   // 使用普通函数输出宽度  
   display2( line1 );   // Length of box : 10
   return 0;
}


/************ 友元类 ************/
#include <iostream>
using namespace std;

class Box
{
    double width;
public:
    friend void printWidth(Box box);
    friend class BigBox;
    void setWidth(double wid)  {width = wid;}
};
class BigBox
{
public :
    void Print(int width, Box &box)   // & 在这里表示引用
    {
        box.setWidth(width);   // 公有成员可直接访问
        // BigBox是Box的友元类，它可以直接访问Box类的私有成员
        cout << "Width of box : " << box.width << endl;
    }
};

// 请注意：printWidth() 不是任何类的成员函数
void printWidth(Box box)
{
    /* 因为 printWidth() 是 Box 的友元，它可以直接访问该类的任何成员 */
    cout << "Width of box : " << box.width << endl;
}

// 程序的主函数
int main()
{
    Box box;
    BigBox big;
    // 使用成员函数设置宽度
    box.setWidth(10.0);
    // 使用友元函数输出宽度
    printWidth(box);     // Width of box : 10
    // 使用友元类中的方法设置宽度
    big.Print(20, box);  // Width of box : 20
    return 0;
}
```



### 7. [C++ 中 this 指针](https://www.runoob.com/cplusplus/cpp-this-pointer.html)

在 C++ 中，每一个对象都能通过 **this** 指针来访问自己的地址。**this** 指针是所有成员函数的隐含参数。因此，在成员函数内部，它可以用来指向调用对象。
因为 **this** 的目的总是指向“这个”对象，所以 **this** 是一个常量指针。

友元函数没有 **this** 指针，因为友元不是类的成员。只有成员函数才有 **this** 指针。

```C++
#include <iostream>
using namespace std;
 
class Box
{
   public:
      double length;     // Length of a box
      Box(){ length=0; }
	  Box* get_address() {return this;}           // 得到this的地址
	  double get_len()   {return this->length;}   // 返回指针指向的类的值
};    // 注意指针成员的域运算符为：->
 
int main(void)
{
   Box box1, box2;  
   // Box* 定义指针p接受对象box的get_address()成员函数的返回值，并打印
   Box* p = box1.get_address();  
   cout << p << endl;       // 输出：0xc11cbff7e8
   p = &box1;  
   cout << p << endl;       // 输出：0xc11cbff7e8
   p = box2.get_address();
   cout << p << endl;       // 输出：0xc11cbff7e0
   double len = box1.get_len();
   cout << len << endl;     // 输出：0
   return 0;
}
```

### 8. [C++ 指向类的指针](https://www.runoob.com/cplusplus/cpp-pointer-to-class.html)

指向 C++ 类的指针与指向结构的指针类似；
注意：定义指向类的指针，不调用 **构造函数** 创建变量；
注意：访问指向类的指针的成员，需要使用成员访问运算符 **`->`**。

```C++
#include <iostream>
using namespace std;

class Box
{
   private:
      double length;     // Length of a box
      double breadth;    // Breadth of a box
      double height;     // Height of a box
   public:
      Box(double l=2.0, double b=2.0, double h=2.0);
      double Volume();
};
Box::Box(double l, double b, double h)
{
     cout <<"Constructor called." << endl;
     length = l;
     breadth = b;
     height = h;
}
double Box::Volume()
{
     return length * breadth * height;
}

int main(void)
{
   Box Box1(3.3, 1.2, 1.5);    // 输出：Constructor called.
   Box Box2(8.5, 6.0, 2.0);    // 输出：Constructor called.
   Box *ptrBox;                // 注意定义指针变量，不创建结构体。

   // 保存第一个对象的地址
   ptrBox = &Box1;
   // 现在尝试使用成员访问运算符来访问成员
   cout << "Volume of Box1: " << ptrBox->Volume() << endl;   // Volume of Box1: 5.94

   // 保存第二个对象的地址
   ptrBox = &Box2;
   // 现在尝试使用成员访问运算符来访问成员
   cout << "Volume of Box2: " << ptrBox->Volume() << endl;   // Volume of Box1: 102
    
   // 使用动态内存分配方法，在堆区创建一指针变量
   Box *ptr1 = new Box();   
   Box *ptr2 = new Box(2.0, 4.0, 5.0);  
   // 注意此方法定义指针，创建也够提，输出：Constructor called.
    
   // 现在尝试使用成员访问运算符来访问成员
   cout << "Volume of Box1: " << ptr1->Volume() << endl;   // Volume of Box1: 8
   delete ptr1, ptr2;
   
   return 0;
}
```

**注意：**动态内存分配 + 堆区创建变量，该方法使用更多。



### 9. [C++ 类的静态成员](https://www.runoob.com/cplusplus/cpp-static-members.html)和[const成员](https://www.runoob.com/w3cnote/cpp-static-const.html)

#### **9.1 静态成员**

可以使用 **static** 关键字来把类成员声明为静态成员。
当声明类的成员为静态时，这意味着无论创建多少个类的对象，静态成员都只有一个副本。
静态成员变量是先于类的对象而存在，在类的所有对象中是共享的。
静态成员的定义不能放置在类的定义中，但是可以在类的外部通过使用范围解析运算符 **::** 来重新定义静态变量从而对它进行初始化
静态成员变量在类中仅仅是声明，没有定义，需要要在类的外面定义，否则就会报错；

```C++
#include <iostream>
using namespace std;
 
class Box
{
   private:
      double length;     // 长度
      double breadth;    // 宽度
      double height;     // 高度
   public:
      static int objectCount;   // 定义静态成员
      // 构造函数定义
      Box(double l=2.0, double b=2.0, double h=2.0);
      double Volume();
};
// 定义成员函数
Box::Box(double l, double b, double h)
{
     cout <<"Constructor called." << endl;
     length = l;
     breadth = b;
     height = h;
     // 每次创建对象时增加 1
     objectCount++;
}
double Box::Volume()
{
     return length * breadth * height;
}    
// 初始化类 Box 的静态成员，其实是定义并初始化的过程
int Box::objectCount = 0;
//也可这样 定义却不初始化，静态变量默认为0
//int Box::objectCount;
 
int main(void)
{
   Box Box1(3.3, 1.2, 1.5);    // 声明 box1
   Box Box2(8.5, 6.0, 2.0);    // 声明 box2
 
   // 输出对象的总数
   cout << "Total objects: " << Box::objectCount << endl;   // 通过类名直接使用静态成员
   return 0;
}

/*输出：
Constructor called.
Constructor called.
Total objects: 2
*/
```

#### **9.2 静态成员函数**

如果把函数成员声明为静态的，就可以把函数与类的任何特定对象独立开来。
静态成员函数先于类的对象而存在，即使**在类对象不存在的情况下也能被调用**，静态函数只要使用类名加范围解析运算符 **::** 就可以访问。
静态成员函数**只能访问静态成员数据、其他静态成员函数和类外部的其他函数**。
静态成员函数有一个类范围，他们**不能访问类的 this 指针**。
可以使用静态成员函数来判断类的某些对象是否已被创建。

```C++
#include <iostream>
using namespace std;
 
class Box
{
   private:
      double length;     // 长度
      double breadth;    // 宽度
      double height;     // 高度
   public:
      static int objectCount;
      // 构造函数定义
      Box(double l=2.0, double b=2.0, double h=2.0);
      double Volume();
      static int getCount();
};
// 定义成员函数
Box::Box(double l, double b, double h)
{
     cout <<"Constructor called." << endl;
     length = l;
     breadth = b;
     height = h;
     // 每次创建对象时增加 1
     objectCount++;
}
double Box::Volume()
{
     return length * breadth * height;
}    

int Box::getCount()     // 注意：静态成员函数在类外定义时，不能加 static
{
     return objectCount;
}
// 初始化类 Box 的静态成员
int Box::objectCount = 0;
 
int main(void)
{
   // 在创建对象之前输出对象的总数
   cout << "Inital Stage Count: " << Box::getCount() << endl;
 
   Box Box1(3.3, 1.2, 1.5);    // 声明 box1
   Box Box2(8.5, 6.0, 2.0);    // 声明 box2
 
   // 在创建对象之后输出对象的总数
   cout << "Final Stage Count: " << Box::getCount() << endl;     // 通过类名访问静态成员函数
   // cout << "Final Stage Count: " << Box2.getCount() << endl;  // 通过对象名访问静态成员函数方法也可
   return 0;
}

/* 输出：
Inital Stage Count: 0
Constructor called.
Constructor called.
Final Stage Count: 2
*/
```

#### **9.3 [const成员和引用成员](https://www.runoob.com/w3cnote/cpp-static-const.html)**

**const** 成员变量不能在类定义处初始化，只能通过**构造函数初始化列表**进行，并且必须有构造函数。
**const** 数据成员 只在某个对象生存期内是常量，而对于整个类而言却是可变的。
类可以创建多个对象，不同的对象其 **const** 数据成员的值可以不同。所以不能在类的声明中初始化 **const** 数据成员。
**const** 数据成员的初始化只能在类的构造函数的初始化列表中进行。要想建立在整个类中都恒定的常量，应该用类中的枚举常量来实现，或者**static cosnt**。

**引用成员**和**const成员**性质很类似，均只能使用**初始化列表来初始化字段**；
**注意 引用成员，传入变量 应 引用传入；**

```C++
#include <iostream>
using namespace std;

class Test{
private:
    const int con;  //只能在构造函数初始化列表中初始化
    static int sta; //在类的实现文件中定义并初始化
    const static double con_sta;     //与 static const double con_sta;相同。
    // const static double con_sta = 20.0;  // ERROR!
    const static int con_sta2 = 30;  // 正确！只有const static int成员可以直接赋值！
public:
    Test(int i = 0);
    static void print(); //静态成员函数
    static void print(const Test &t ); //静态成员函数，通过对象形式使用非静态成员
    void show();
};
 
int Test::sta=0;  // static成员变量不能在构造函数初始化列表中初始化，因为它不属于某个对象。
const double Test::con_sta=20.0; // 注意：给静态成员变量赋值时，不需要加static修饰符，但要加cosnt。
Test::Test(int i):con(i)  {   // 注意：只能使用：con(i)这种赋值方法
    // con = i;   // ERROR，常量不能赋值，只能使用 构造函数的初始化列表
    // 注意引用型成员同理，不能赋值，只能使用 构造函数的初始化列表
    sta++;    // 静态数据成员++
}
void Test::print(){
    cout<<"static = "<< sta <<endl;
    cout<<"const static2 = "   << con_sta2 <<endl;
    // cout<<"const = "   << con <<endl;   // ERROR 静态成员函数不可以访问自身其他成员
}
void Test::print(const Test &t ) {  //静态成员函数，通过对象形式使用非静态成员
    cout<<"static = "<< sta <<endl;
    cout<<"const static = "   << con_sta <<endl;
    cout<<"const = "   << t.con <<endl;   // 通过对象形式使用非静态成员
}
void Test::show(){
    cout<<"static = "<< sta <<endl;
    cout<<"const static = "   << con_sta <<endl;
    cout<<"const = "   << con <<endl;  
}

class test2
{
public:
    Test & t;
    test2(Test &i):t(i)    // 注意：只能使用：t(i)这种赋值方法
    {
        cout << "test2" <<endl;
        t.show();
    }
};

int main(){
    Test a(5);
    Test::print(); // 通过类访问静态成员函数
    a.print();     // 通过对象访问静态成员函数
    
    Test b;
    b.print();     // 通过对象访问静态成员函数
    b.show();      // 通过对象访问静态成员函数
    
    Test c(15);
    Test::print(c); // 通过类访问静态成员函数
    c.print(c);     // 通过对象访问静态成员函数
    
    test2 d(c);
    d.t.show();
    return 0;
}
/* 输出：
static = 1
const static2 = 30
static = 1
const static2 = 30
static = 2
const static2 = 30
static = 2
const static = 20
const = 0
static = 3
const static = 20
const = 15
static = 3
const static = 20
const = 15
test2
static = 3
const static = 20
const = 15
static = 3
const static = 20
const = 15
*/
```

**总结：**

- 常量变量：必须通过构造函数参数列表进行初始化。
- 引用变量：必须通过构造函数参数列表进行初始化。
- 普通静态变量：要在类外通过"::"初始化。
- 静态整型常量：可以直接在定义的时候初始化。
- 静态非整型常量：不能直接在定义的时候初始化。要在类外通过"::"初始化。

参照**[评论笔记3、10](https://www.runoob.com/cplusplus/cpp-storage-classes.html)、[评论笔记4](https://www.runoob.com/cplusplus/cpp-static-members.html)**

#### 9.4 [mutable 的用法](https://blog.csdn.net/AAA123524457/article/details/80967330)

**mutable**的中文意思是“可变的，易变的”，跟**constant**（既C++中的**const**）是反义词；
被**mutable**修饰的变量，将永远处于可变的状态，即使在一个**const**函数中。

```C++
class Test
{
public:
    mutable int m_Times;
    int _Times;
    void CountConst() const;   // 声明为const函数，内部变量均不可修改
    void Count();              // 普通函数无限制
};
void Test::CountConst() const  // 声明为const函数，内部变量均不可修改
{
    cout << "CountConst()" << endl;
    m_Times++;     // 正确，因为mutable变量，永远处于可修改状态
    // _Times++;    // ERROR
    // int a = 5; a++ ;   // 正确，定义的局部变量可修改。
}
void Test::Count()  // 普通函数无限制，内部变量均可修改
{
    cout << "Count()" << endl;
    m_Times++;
    _Times++;
}
```



### 10. [C++ 继承](https://www.runoob.com/cplusplus/cpp-inheritance.html)与[多态](https://www.runoob.com/cplusplus/cpp-polymorphism.html)

#### 10.1 继承

继承代表了 **is a** 关系。例如，哺乳动物是动物，狗是哺乳动物，因此，狗是动物，等等。
继承允许我们依据另一个类来定义一个类，这使得创建和维护一个应用程序变得更容易。
当创建一个类时，您不需要重新编写新的数据成员和成员函数，只需指定新建的类继承了一个已有的类的成员即可。这个已有的类称为**基类**，新建的类称为**派生类**。
<img src="https://www.runoob.com/wp-content/uploads/2015/05/cpp-inheritance-2020-12-15-1.png" alt="img" style="zoom:75%;" />

一个类可以派生自多个类，这意味着，它可以从多个基类继承数据和函数。
定义一个派生类，我们使用一个类派生列表来指定基类。类派生列表以一个或多个基类命名，
其形式：`class <派生类名>:<继承方式1><基类名1>, <继承方式2><基类名2>,……`；
继承方式 是 **public、protected** 或 **private** 其中的一个，如果继承时不声明继承方式，则默认为 **private**。

示例如下：

```C++
/******** 基础示例 ********/
#include <iostream>
using namespace std;

// 基类
class Shape
{
protected:
    int width;
    int height;
public:
void setWidth(int w)
    {
        width = w;
    }
};
// 派生类
class Rectangle : public Shape
{
public:
    void setHeight(int h)
    {
        height = h;   // 派生类可以修改基类成员
    }
    int getArea()
    {
        return (width * height); // 派生类可以使用基类成员
    }
};

int main(void)
{
    Rectangle Rect;
    Rect.setWidth(5);     // 派生类可以使用基类成员函数
    Rect.setHeight(7);
    
    // 输出对象的面积
    cout << "Total area: " << Rect.getArea() << endl;
    // 输出：Total area: 35
    return 0;
}
```

**类的继承方式如下：**

| **继承方式**  | **基类的public成员** | **基类的protected成员** | **基类的private成员** | **继承引起的访问控制关系变化概括**   |
| ------------- | -------------------- | ----------------------- | --------------------- | ------------------------------------ |
| public继承    | 仍为public成员       | 仍为protected成员       | 不可见                | 基类的非私有成员在子类的访问属性不变 |
| protected继承 | 变为protected成员    | 变为protected成员       | 不可见                | 基类的非私有成员都为子类的保护成员   |
| private继承   | 变为private成员      | 变为private成员         | 不可见                | 基类的非私有成员都为子类的私有成员   |

几乎不使用 **protected** 或 **private** 继承，通常使用 **public** 继承；

一个派生类继承了所有的基类方法，但下列情况除外：

- 基类的构造函数、析构函数和拷贝构造函数。
- 基类的重载运算符。
- 基类的友元函数。

**注意：**虽然不能够在子类的成员函数体中调用基类的构造函数来为成员变量进行初始化，但是可以把基类的构造函数放在子类构造函数的初始化列表上，以此实现调用基类的构造函数来为子类从基类继承的成员变量初始化。

```C++
#include <iostream>
using namespace std;

class Cpoint1
{
protected:
    int xp, yp;
public:
    Cpoint1() :xp(0), yp(0) {}   // 注意point1 和 point2 区别
    Cpoint1(int x, int y) :xp(x), yp(y) {}
    void show()
    {
        cout << "xp = " << xp << " ; yp = " << yp <<endl;
    }
};
class Cpoint2
{
protected:
    int xp, yp;
public:
    Cpoint2(int x, int y) :xp(x), yp(y) {}
    void show()
    {
        cout << "xp = " << xp << " ; yp = " << yp <<endl;
    }
};
class CRect1 : public Cpoint1
{
public:
    CRect1(int x1, int x2) : Cpoint1(x1, x2) {  }       // 作用为：使用变量x1、x2初始化基类成员
	// /* 等价于 */
    // CRect1(int x1, int x2)
    // {  
	// 	xp = x1;
	// 	yp = x2;
    // }
    // /* 不能使用下面方法，否则无法正确定义变量 */
    // CRect1(int x1, int x2)
    // {  
	// 	Cpoint1(x1, x2);   // 此时会调用 Cpoint() :xp(0), yp(0) {}  初始化变量
    // }
    void showr(){ show(); }
};
class CRect2 : public Cpoint2
{
public:
    CRect2(int x1, int x2) : Cpoint2(x1, x2) {  }   // 作用为：使用变量x1、x2初始化基类成员
	// /* 不能使用下面声明方法，会报错 */
    // CRect2(int x1, int x2)
    // {  
	// 	xp = x1;
	// 	yp = x2;
    // }
    // /* 不能使用下面声明方法，会报错 */
    // CRect2(int x1, int x2)
    // {  
	// 	Cpoint(x1, x2);   
    // }
    void showr(){ show(); }
};
class CRect3 : public Cpoint1
{
private:
    Cpoint1 c1, c2;
public:
    CRect3(int x1, int x2) : c1(x1,x2), c2(x2,x1){  }
    // /* 等价于 */
    // CRect3(int x1, int x2)
    // {
    //     Cpoint1 temp1(x1, x2), temp2(x2, x1);
    //     c1 = temp1;
    //     c2 = temp2;
    // }
    // /* 不能使用下面声明方法，会报错 */
    // CRect3(int x1, int x2)
    // {  
	// 	c1(x1,x2);
	// 	c2(x2,x1);
    // }
    void showr()
    {
        cout << "c1.show():  " ;
        c1.show();
        cout << "c2.show():  " ;
        c2.show();
    } 
}; 
class CRect4 : public Cpoint2
{
private:
    Cpoint2 c1, c2;
public:
    CRect4(int x1, int x2) : c1(x1,x2), c2(x2,x1), Cpoint2(x1, x2){  }  // 只能这样写
    // CRect4(int x1, int x2) : c1(x1,x2), c2(x2,x1){  }  // 不可用，会报错
    void showr()
    {
        cout << "c1.show():  " ;
        c1.show();
        cout << "c2.show():  " ;
        c2.show();
    } 
}; 
    
int main()
{
    CRect1 p1(10,20);
    p1.showr();   // 输出：xp = 10 ; yp = 10 
    p1.show();    // 输出：xp = 10 ; yp = 10
    
    CRect2 p2(10,20);
    p2.showr();   // 输出：xp = 10 ; yp = 10 
    p2.show();    // 输出：xp = 10 ; yp = 10
    
    CRect3 p3(10,20);
    p3.showr();   // 输出：c1.show():  xp = 10 ; yp = 20 '\n' c2.show():  xp = 20 ; yp = 10
    p3.show();    // 输出：xp = 0 ; yp = 0
    
    CRect4 p4(10,20);
    p4.showr();   // 输出：c1.show():  xp = 10 ; yp = 20 '\n' c2.show():  xp = 20 ; yp = 10
    p4.show();    // 输出：xp = 10 ; yp = 10
    return 0;
}
/*
各种方法输出结果如下：
很奇怪，没有弄懂。
*/
```

此外，派生类在继承基类的成员变量时，会单独开辟一块内存保存基类的成员变量，因此派生类自己的成员变量即使和基类的成员变量重名，但是也不会引起冲突。示例如下。

```C++
#include <iostream>
using namespace std;

// 基类
class A
{
private:
    int n;
public:
    A() { n = 0; };
    ~A(){};
    int getA() { return n; };
    void setA(int t) { n = t; };
};

// 派生类
class B : public A
{
private:
    int n;
public:
    B() { n = 0; };
    ~B(){};
    int getB() { return n; };
    void setB(int t) { n = t; };
};

int main()
{
    B b;
    b.setA(10); // 设置基类的成员变量n

    cout << "A::n " << b.getA() << endl;   // A::n 10
    cout << "B::n " << b.getB() << endl;   // B::n 0
    b.setB(9); // 设置派生类的成员变量n
    cout << "A::n " << b.getA() << endl;   // A::n 10
    cout << "B::n " << b.getB() << endl;   // B::n 9
    return 0;
}
```

如果不希望类被继承，可以在定义类时在类名后加`final `关键字，格式：`class Class_name final { ... };`

#### 10.2 多态

##### 1）补充：类指针

**[类指针](https://blog.csdn.net/qq_42564908/article/details/108519000)、[C++中栈和堆上建立对象的区别](https://www.cnblogs.com/xiaoxiaoqiang001/p/5557704.html)、[C++ 类对象与类指针(静态和动态多态)\_静态指针和动态指针](https://blog.csdn.net/Chroniccandy/article/details/108739547)**

**指针可以实现多态，直接用对象不行。**

为什么需要使用 `new`动态内存分配？

```C++
#include<iostream>
#include<string>
using namespace std;

/* 创建student类 */
class  student
{
public:
    string name;
    int age;
    void sayhello();
};
void student::sayhello()
{
    cout<<"my name is: "+this->name+" I am: "<<this->age;
    cout<<"\n";
}

/* setname函数，返回值为student类，用到了拷贝构造函数 */
student setname(string name)
{
    student stu;
    stu.age=12;
    stu.name=name;
    return stu;
}
/* setname函数，返回值为指向student类指针 */
/* 程序运行结束，此时栈中数据销毁，指针变为野指针 */
student* setname(string name)
{
    student stu;
    stu.age=12;
    stu.name=name;
    return &stu;
}
/* setname函数，返回值为指向student类指针 */
/* 程序运行结束，堆中数据不会被销毁 */
student* setname(string name)
{
    student* stu= new student();
    stu->age=12;
    stu->name=name;
    return  stu;
}

int main()
{
    student stu=setname("jim");
    stu.sayhello(); // 正确，用到了拷贝构造函数，占用较大内存

    student* p=setname("tom");
    p->sayhello();  // ERROR，野指针
    
    student* p=setname("tom");
    p->sayhello();  // 正确，堆中数据不会销毁。传递变量为指针，节省内存空间；
    delete p;       // 变量需要手动删除
    
    return 0;
}
```

类指针是一个**指向内存中存放类对象的内存地址 的值**(也就是知道了所有类对象的地址)，那么这个指针可以**指向多个不同的对象**，这就是多态。

比如当类是有虚函数的基类时,`Func`是类的一个虚函数,则调用`Func`时：
**类对象**：调用的是他本类中自己的`Func`函数
**类指针**：调用的是分配给他空间时的那个类的`Func`函数

例如 : `Animal`是`Dog`的基类
`Animal* dog= new Dog;`
此时类指针dog调用的Func函数便是分配给他空间的Dog类中的Func函数 (Func需是虚函数才会调用成功)

**类指针的好处：**
第一 : 实现多态
第二 : 在函数调用传入类对象时,如果传入的是类对象的指针参数,此时不管你的对象或结构参数多么庞大,你用指针,传过去的就是**4个字节**,如果用固定的类对象示例进行传递参数,参数 传递占用的资源就太大了。

##### 2）[多态 教程 (新)](http://c.biancheng.net/view/2294.html)

```C++
#include <iostream>
using namespace std;
//基类People
class People{
public:
    People(char *name, int age);
    void display();
    // virtual void display();  //声明为虚函数
protected:
    char *m_name;
    int m_age;
};
People::People(char *name, int age): m_name(name), m_age(age){}
void People::display(){
    cout<<m_name<<"今年"<<m_age<<"岁了，是个无业游民。"<<endl;
}
//派生类Teacher
class Teacher: public People{
public:
    Teacher(char *name, int age, int salary);
    void display();
private:
    int m_salary;
};
Teacher::Teacher(char *name, int age, int salary): People(name, age), m_salary(salary){}
void Teacher::display(){
    cout<<m_name<<"今年"<<m_age<<"岁了，是一名教师，每月有"<<m_salary<<"元的收入。"<<endl;
}
int main(){
    People *p = new People("王志刚", 23);
    p -> display();
    delete p;  // 记着释放动态内存
    p = new Teacher("赵宏佳", 45, 8200);
    p -> display();
    delete p;  // 记着释放动态内存
    return 0;
}
/*
使用：void display();
输出：
王志刚今年23岁了，是个无业游民。
赵宏佳今年45岁了，是个无业游民。
*/
/*
使用：virtual void display();  //声明为虚函数
输出：
王志刚今年23岁了，是个无业游民。
赵宏佳今年45岁了，是一名教师，每月有8200元的收入。
*/
```

有了虚函数，基类指针指向基类对象时就使用基类的成员（包括成员函数和成员变量），指向派生类对象时就使用派生类的成员。换句话说，基类指针可以按照基类的方式来做事，也可以按照派生类的方式来做事，它有多种形态，或者说有多种表现方式，我们将这种现象称为**多态（Polymorphism）**。

C++提供多态的目的是：可以**通过基类指针对所有派生类**（包括直接派生和间接派生）的成员变量和成员函数**进行“全方位”的访问**，尤其是成员函数。如果没有多态，我们只能访问成员变量。

**多态实例如下：**如果不使用多态，很容易造成混乱。

```C++
#include <iostream>
using namespace std;

//军队
class Troops{
public:
    virtual void fight(){ cout<<"Strike back!"<<endl; }
};

//陆军
class Army: public Troops{
public:
    void fight(){ cout<<"--Army is fighting!"<<endl; }
};
//99A主战坦克
class _99A: public Army{
public:
    void fight(){ cout<<"----99A(Tank) is fighting!"<<endl; }
};
//武直10武装直升机
class WZ_10: public Army{
public:
    void fight(){ cout<<"----WZ-10(Helicopter) is fighting!"<<endl; }
};
//长剑10巡航导弹
class CJ_10: public Army{
public:
    void fight(){ cout<<"----CJ-10(Missile) is fighting!"<<endl; }
};

//空军
class AirForce: public Troops{
public:
    void fight(){ cout<<"--AirForce is fighting!"<<endl; }
};
//J-20隐形歼击机
class J_20: public AirForce{
public:
    void fight(){ cout<<"----J-20(Fighter Plane) is fighting!"<<endl; }
};
//CH5无人机
class CH_5: public AirForce{
public:
    void fight(){ cout<<"----CH-5(UAV) is fighting!"<<endl; }
};
//轰6K轰炸机
class H_6K: public AirForce{
public:
    void fight(){ cout<<"----H-6K(Bomber) is fighting!"<<endl; }
};

int main(){
    Troops *p = new Troops;
    p ->fight();
    //陆军
    p = new Army;
    p ->fight();
    p = new _99A;
    p -> fight();
    p = new WZ_10;
    p -> fight();
    p = new CJ_10;
    p -> fight();
    //空军
    p = new AirForce;
    p -> fight();
    p = new J_20;
    p -> fight();
    p = new CH_5;
    p -> fight();
    p = new H_6K;
    p -> fight();

    return 0;
}
/*
运行结果：
Strike back!
--Army is fighting!
----99A(Tank) is fighting!
----WZ-10(Helicopter) is fighting!
----CJ-10(Missile) is fighting!
--AirForce is fighting!
----J-20(Fighter Plane) is fighting!
----CH-5(UAV) is fighting!
----H-6K(Bomber) is fighting!
*/
```

##### **3）多态旧教程 (讲的不是很清晰)：**可作为补充知识点

**多态：引例：**正常情况下同名函数可以使用 域运算符**`::`**确定函数；

```C++
#include <iostream>
using namespace std;

class Shape
{
public:
    void show()   
    {
        cout << "基类" << endl;
    }
};
class Rectangle : public Shape
{
public:
    void show()  
    {
        cout << "派生类" << endl;
    }
};
// 程序的主函数
int main()
{
    Rectangle test;
    test.show();              // 派生类
    test.Shape::show();       // 基类
    test.Rectangle::show();   // 派生类
    
    Rectangle *ptest = &test;
    ptest->show();              // 派生类
    ptest->Shape::show();       // 基类
    ptest->Rectangle::show();   // 派生类
    
    Shape *pptest = &test;
    pptest->show();              // 基类
    pptest->Shape::show();       // 基类
    pptest->Rectangle::show();   // ERROR，报错

    return 0;
}
```

**疑问：**如何使上面的`pptest`指针可以访问`Rectangle::show()`呢？
**答案：**使用虚函数！

```C++
#include <iostream>
using namespace std;

class Shape
{
public:
    virtual void show()   // 声明 show() 为虚函数
    {
        cout << "基类" << endl;
    }
};
class Rectangle : public Shape
{
public:
    void show()   
    {
        cout << "派生类" << endl;
    }
};
// 程序的主函数
int main()
{
    Rectangle test;
    test.show();              // 派生类
    test.Shape::show();       // 基类
    test.Rectangle::show();   // 派生类
    
    Rectangle *ptest = &test;
    ptest->show();              // 派生类
    ptest->Shape::show();       // 基类
    ptest->Rectangle::show();   // 派生类
    
    Shape *pptest = &test;
    pptest->show();              // 派生类
    pptest->Shape::show();       // 基类
    pptest->Rectangle::show();   // ERROR，报错

    return 0;
}
```

此时观察到，`Shape`型的指针变量 `*pptest`，指向`Rectangle`型变量`test`地址；
若不使用虚函数，则指针变量 `*pptest`调用`Shape`类内部的函数，
若声明为虚函数，则指针变量 `*pptest`调用`Rectangle`类内部的函数；

下面内容为**官方讲解**，看的不是很懂：

**多态**按字面的意思就是多种形态。当类之间存在层次结构，并且类之间是通过继承关联时，就会用到多态。C++多态意味着调用成员函数时，会根据调用函数的对象的类型来执行不同的函数；

形成多态必须具备三个条件：

1、必须存在继承关系；
2、继承关系必须有同名虚函数（**其中虚函数是在基类中使用关键字Virtual声明的函数，在派生类中重新定义基类中定义的虚函数时，会告诉编译器不要静态链接到该函数**）；
3、存在基类类型的指针或者引用，通过该指针或引用调用虚函数；

**示例如下：**

```C++
/********* 高级例子 *********/
#include <iostream>
using namespace std;

class Shape
{
protected:
    int width, height;
public:
    Shape(int a = 0, int b = 0)
    {
        width = a;
        height = b;
    }
    virtual int area()   // 声明 area() 为虚函数
    {
        cout << "Parent class area :" << 0 <<endl;
        return 0;
    }
};
class Rectangle : public Shape
{
public:
    Rectangle(int a = 0, int b = 0) : Shape(a, b) {}
    int area()
    {
        cout << "Rectangle class area :" << width * height << endl;
        return (width * height);
    }
};
class Triangle : public Shape
{
public:
    Triangle(int a = 0, int b = 0) : Shape(a, b) {}
    int area()
    {
        cout << "Triangle class area :" << width * height / 2 << endl;
        return (width * height / 2);
    }
};
// 程序的主函数
int main()
{
    Shape *shape;
    Rectangle rec(10, 7);
    Triangle tri(10, 5);
    
    // 存储矩形的地址
    shape = &rec;
    // 调用矩形的求面积函数 area
    shape->area();

    // 存储三角形的地址
    shape = &tri;
    // 调用三角形的求面积函数 area
    shape->area();

    return 0;
}
/*输出：
Rectangle class area :70
Triangle class area :25
*/
// 如果去掉 virtual int area() 前的 virtual，则此时输出为：
/*输出：
Parent class area :0
Parent class area :0
*/
```

**虚函数**作用为：当基类与继承类存在同名函数时，通过虚函数，确保程序使用继承类函数；
有了多态，您可以有多个不同的类，都带有同一个名称但具有不同实现的函数，函数的参数甚至可以是相同的。

**更详细的解释：**

>调用函数 area() 被编译器设置为基类中的版本，这就是所谓的**静态多态**，或**静态链接** - 函数调用在程序执行前就准备好了。有时候这也被称为**早绑定**，因为 area() 函数在程序编译期间就已经设置好了。
>
>**虚函数** 是在基类中使用关键字 **virtual** 声明的函数。在派生类中重新定义基类中定义的虚函数时，会告诉编译器不要静态链接到该函数。我们想要的是在程序中任意点可以根据所调用的对象类型来选择调用的函数，这种操作被称为**动态链接**，或**后期绑定**。

**纯虚函数：**在基类中定义虚函数，以便在派生类中重新定义该函数更好地适用于对象，但是在基类中又不能对虚函数给出有意义的实现。此时：上面的`virtual int area() {}`可以改写为：`	virtual int area() = 0;`

**注意：**虚函数可以不实现定义，但不能不定义，即不能：`	virtual int area();`，
&nbsp;          否则其类是抽象类，无法实例化（不能用该类定义对象）。详见[**评论笔记4**](https://www.runoob.com/cplusplus/cpp-polymorphism.html)

**更多虚函数知识讲解详见[评论笔记](https://www.runoob.com/cplusplus/cpp-polymorphism.html)：**

>1、纯虚函数声明如下： virtual void funtion1()=0; 纯虚函数一定没有定义，纯虚函数用来规范派生类的行为，即接口。包含纯虚函数的类是抽象类，抽象类不能定义实例，但可以声明指向实现该抽象类的具体类的指针或引用。
>2、虚函数声明如下：virtual ReturnType FunctionName(Parameter) 虚函数必须实现，如果不实现，编译器将报错，错误提示为：
>3、对于虚函数来说，父类和子类都有各自的版本。由多态方式调用的时候动态绑定。
>4、实现了纯虚函数的子类，该纯虚函数在子类中就变成了虚函数，子类的子类即孙子类可以覆盖该虚函数，由多态方式调用的时候动态绑定。
>5、虚函数是C++中用于实现多态(polymorphism)的机制。核心理念就是通过基类访问派生类定义的函数。
>6、在有动态分配堆上内存的时候，析构函数必须是虚函数，但没有必要是纯虚的。
>7、友元不是成员函数，只有成员函数才可以是虚拟的，因此友元不能是虚拟函数。但可以通过让友元函数调用虚拟成员函数来解决友元的虚拟问题。
>8、析构函数应当是虚函数，将调用相应对象类型的析构函数，因此，如果指针指向的是子类对象，将调用子类的析构函数，然后自动调用基类的析构函数。

**补充：**注意观察上面多态定义及使用方法；正常情况下同名函数可以使用 域运算符**`::`**确定函数；
**示例如下：**

```C++
#include <iostream>
using namespace std;

class Shape
{
public:
    void show()   // 声明 area() 为虚函数
    {
        cout << "基类" << endl;
    }
};
class Rectangle : public Shape
{
public:
    void show()   // 声明 area() 为虚函数
    {
        cout << "派生类" << endl;
    }
};
// 程序的主函数
int main()
{
    Rectangle test;
    test.show();              // 派生类
    test.Shape::show();       // 基类
    test.Rectangle::show();   // 派生类
    
    Rectangle *ptest = &test;
    ptest->show();              // 派生类
    ptest->Shape::show();       // 基类
    ptest->Rectangle::show();   // 派生类
    
    Shape *pptest = &test;
    pptest->show();              // 基类
    pptest->Shape::show();       // 基类
    pptest->Rectangle::show();   // ERROR
    
    return 0;
}
```

#### 3）补充知识点：关于基类 派生类之间的 转换

**参考：[static_cast用法1](https://blog.csdn.net/zhouwei1221q/article/details/44978361)、[static_cast用法2](https://www.cnblogs.com/QG-whz/p/4509710.html)**

**static_cast是一个强制类型转换操作符。**编译器隐式执行的任何类型转换都可以由static_cast显式完成；
用法：static_cast < type-id > ( expression )

```C++
/******** 1. 基本类型转换 ********/
#include <iostream>
using namespace std;
 
int main()
{
	char a = 'c';   // a = c
	int b = static_cast<int>(a);     // b = 99
	char c = static_cast<char>(b);   // c = a
    
	char* pa = &a;        // char* pa = c
	int* pb = (int*)pa;   // int* pb = 003F00060
	// int *pb = static_cast<int*>(pa);  // char* → int* error
	// pa = static_cast<char*>(pb);      // int* → char* error
	char *pc = (char*)pb; // char* → char* pc = c
	// char *pc = static_cast<char*>(pb); // int* → char* error
	// static_cast可以把任何类型的表达式转换成void类型。
    void *pd = static_cast<void*>(pa);    // char* → void* pd = 003F00060
    // void类型可以转换为任何类型
	int *pe = static_cast<int*>(pd);      // void* → int* pe = 003F00060
	char *pf = static_cast<char*>(pd);    // void* → char* pf = c

	return 0;
}

/******** 2. 类层次结构中基类与子类指针或引用之间的转换 ********/
/******** 例1 ********/
#include <iostream>
using namespace std;

// ANIMAL  type = "ANIMAL"
class ANIMAL
{
private:
	string _type;

public:
	ANIMAL() : _type("ANIMAL"){};
	virtual void OutPuttype() { cout << "ANIMAL" << endl; };
};
// DOG type = "DOG" , name = "大黄"
class DOG : public ANIMAL
{
private:
	string _name;
	string _type;

public:
	DOG() : _name("大黄"), _type("DOG"){};
	void OutPutname() { cout << _name << endl; };
	void OutPuttype() { cout << _type << endl; };
};

int main()
{
    // 派生类指针指向派生类对象，派生类指针转为基类指针（上行转化安全）
	DOG *dog2 = new DOG;
	ANIMAL *ani2 = static_cast<ANIMAL *>(dog2);
	ani2->OutPuttype();    // 正确，基类指针可以访问派生类成员，结果输出为DOG
    // ani2->OutPutname(); // 错误，ANIMAL没有OutPutname成员函数
    // 上述语句类似于ANIMAL *ani2 = new DOG;
    
    // DOG *dog2 = new ANIMAL;   // 错误，派生类指针无法指向基类对象
    
	// 基类指针指向基类对象，基类指针转为派生类指针（下行转化危险）
	ANIMAL *ani1 = new ANIMAL;
	DOG *dog1 = static_cast<DOG *>(ani1);
	dog1->OutPuttype();    // 输出错误，结果输出为ANIMAL
    // dog1->OutPutname(); // 错误，在ANIMAL类型指针不能调用方法OutPutType()；在运行时出现错误（但是不做提醒）
    
	// 基类指针指向派生类对象，基类指针转为派生类指针（下行转化危险）
	ANIMAL *ani3 = new DOG;
	DOG *dog3 = static_cast<DOG *>(ani3);
    dog3->OutPuttype(); // 正确，结果输出为DOG
    dog3->OutPutname(); // 正确，结果输出为大黄
    
    
    /************ 关于static_cast和dynamic_cast区别见：下一小节************/
    // 派生类指针指向派生类对象，派生类指针转为基类指针（上行转化安全）
	DOG *dog2 = new DOG;
	ANIMAL *ani2 = dynamic_cast<ANIMAL *>(dog2);
	ani2->OutPuttype();    // 正确，基类指针可以访问派生类成员，结果输出为DOG
    // ani2->OutPutname(); // 错误，ANIMAL没有OutPutname成员函数
    
    // DOG *dog2 = new ANIMAL;   // 错误，派生类指针无法指向基类对象
    
    // 基类指针指向基类对象，基类指针转为派生类指针（下行转化危险）
	ANIMAL *ani1 = new ANIMAL;
	DOG *dog1 = dynamic_cast<DOG *>(ani1);
	dog1->OutPuttype();    // 错误，且做提醒
    // dog1->OutPutname(); // 错误，且做提醒
    
	// 基类指针指向派生类对象，基类指针转为派生类指针（下行转化危险）
	ANIMAL *ani3 = new DOG;
	DOG *dog3 = dynamic_cast<DOG *>(ani3);
    dog3->OutPuttype(); // 正确，结果输出为DOG
	dog3->OutPutname(); // 正确，结果输出为大黄

	return 0;
}

/******** 例2 ********/
// 上行转换：子类指针或引用转换成基类表示——安全
// 下行转换：基类指针或引用转换成子类表示——危险（没有动态类型检查）
// 注意从下向上的转换是安全的，从上向下的转换不一定安全。
class A  { };
class B:public A  { };
class C:public A  { };
class D  { };
A objA;
B objB;
A* pObjA = new A();
B* pObjB = new B();
C* pObjC = new C();
D* pObjD = new D();
 
// 类对象的强制转换
objA = static_cast<A&>(objB);     // 转换为基类引用    
objA = static_cast<A>(objB);      // 转换为基类
objB = static_cast<B>(objA);      // error 不能进行转换  
 
// 类对象指针的强制转换
pObjA = pObjB;                    // right 基类指针指向子类对象
// pObjB = pObjA;                 // error 子类指针指向基类对象
pObjA = static_cast<A*>(pObjB);   // right 子类指针转换为基类，上行转换安全
pObjB = static_cast<B*>(pObjA);   // right 基类指针转换为子类，下行转换危险
// pObjC = static_cast<C*>(pObjB);   // error 继承于统一类的派生指针之间转换 
// pObjD = static_cast<D*>(pObjC);   // error 两个无关联之间转换
```

**[c++ dynamic_cast 和 static_cast 的区别](https://www.cnblogs.com/Hwangzhiyoung/p/8640847.html)**

dynamic_cast：动态转换，static_cast：静态转换

上行转换：子类指针或引用转换成基类表示——安全
下行转换：基类指针或引用转换成子类表示——危险

1）在类层次间进行上行转换时，dynamic_cast 和 static_cast 的效果是一样的。
2）在类层次间进行下行转换时，dynamic_cast 具有类型检查的功能，比static_cast 更安全。

一般 static_cast 执行速度比 dynamic_cast 稍快些。

```C++
#include<iostream>
using namespace std;

// class B->b = 1
class B{
public:
    B():b(1){}
    virtual void foo(){};
    int b;
};
// class D->d = 2，class D->b = 1
class D:public B{
public:
    D():d(2){}
    int d;
};

void func(B *pb){
    // B基类转化为D派生类，下行转换不安全
    D *pd1 = static_cast<D *>(pb);//语句1
    cout<<pd1->b<<endl;
    cout<<pd1->d<<endl;

    D *pd2 = dynamic_cast<D *>(pb);//语句2
    cout<<pd2->b<<endl;
    cout<<pd2->d<<endl;
}

int main(){
    /* 下行转换，不安全 */
    
    B* pb = new D; 
    func(pb);
    /* 1 2 1 2 */

    B* pb = new B;
    func(pb);
    /* 1 0 ERROR */
    /* 
    那么pd1将是一个指向B对象的指针，对它进行D类型的操作将是不安全的（如访问d），输出d的值时，将会是一个垃圾值（此次输出是0），延后了错误的发现；
	而pd2将是一个空指针，对空指针进行操作，将会发生异常，从而能够更早地发现错误。
    */
    return 0;
}
```

**此外：C语言强制转换语法尽量不要在C++中使用，使用C++中类型转换两个关键字。**




### 11. [C++ 重载运算符](https://www.runoob.com/cplusplus/cpp-overloading.html)

函数重载，见 一、C++基础语法：14.4 函数重载

**运算符重载：**
重载的运算符是带有特殊名称的函数，函数名是由**关键字 operator 和其后要重载的运算符符号**构成的。其余特性与其他函数一样。
**注意：**运算符重载虽常见于 类 使用，但其并不局限于 类，普通函数也可以进行运算符重载。


下面是可重载的运算符列表：

| 运算符类型     | 运算符名称                                                   |
| -------------- | ------------------------------------------------------------ |
| 双目算术运算符 | + (加)，-(减)，*(乘)，/(除)，% (取模)                        |
| 关系运算符     | ==(等于)，!= (不等于)，< (小于)，> (大于)，<=(小于等于)，>=(大于等于) |
| 逻辑运算符     | \|\|(逻辑或)，&&(逻辑与)，!(逻辑非)                          |
| 单目运算符     | + (正)，-(负)，*(指针)，&(取地址)                            |
| 自增自减运算符 | ++(自增)，--(自减)                                           |
| 位运算符       | \| (按位或)，& (按位与)，~(按位取反)，^(按位异或),，<< (左移)，>>(右移) |
| 赋值运算符     | =, +=, -=, *=, /= , % = , &=, \|=, ^=, <<=, >>=              |
| 空间申请与释放 | new, delete, new[ ] , delete[]                               |
| 其他运算符     | **\()**(函数调用)，**->**(成员访问)，**,**(逗号)，**\[]**(下标) |

PS：`>>`和`<<`位运算符 正是通过重载，才具有了**输入输出**功能。

下面是不可重载的运算符列表：
**`.`**成员访问运算符、**`.*`**, **`->*`**：成员指针访问运算符、**`::`**域运算符、**`sizeof`**长度运算符、**`?:`**条件运算符、**`#`**预处理符号

以下仅展示部分重载实例，**[更多 C++ 重载运算符实例见](https://www.runoob.com/cplusplus/cpp-overloading.html)**


```C++
/* 运算符重载综合示例 */
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class Complex // 复数类
{
private:
    double i; // i 实部
    double j; // j 虚部
public:
    Complex(double a = 0, double b = 0);   // 所需的构造函数
    Complex( const Complex &obj);          // 拷贝构造函数，使用&表示引用传参
    void setvalue(double a, double b);
    void display();            // 显示复数
    /**** 单目运算符 ****/
    Complex operator-();       // 重载负运算符 (-Complex)
    Complex operator++();      // 重载前缀自增 (++Complex)
    Complex operator++(int);   // 重载后缀自增，参数需要加int。 (Complex++)
    // int 在 括号内是为了向编译器说明这是一个后缀形式，而不是表示整数。可换为 double 等其他类型声明
    /**** 双目运算符 ****/
    Complex operator+(const Complex& a);   
    // 重载加运算符 (Complex1+Complex2)， & 在这里表示引用，测试发现不使用引用也可以达到效果
    // friend Complex operator+(const Complex& a, const Complex& b);  // 使用友元实现 + 效果
    // & 在这里表示引用，测试发现不使用引用也可以达到效果
    Complex operator+(const double b);  // 重载+号，用于 对象与数相加
    friend Complex operator+(const double b, Complex obj);    // 友元函数，用于 数与对象相加
    bool operator<(const Complex& a);      // 重载逻辑运算符 (Complex1<Complex2)
    void operator=(const Complex& obj);    // 重载赋值运算符 (Complex1=Complex2)，类似构造函数
    Complex operator+=(const Complex& a);  // 重载赋值运算符 (Complex1+=Complex2)

};
Complex::Complex(double a, double b)
{
    i = a;
    j = b;
}
Complex::Complex(const Complex &obj)  // 拷贝构造函数，使用&表示引用传参
{
    i = obj.i;
    j = obj.j;
}
void Complex::setvalue(double a, double b)
{
    i = a;
    j = b;
}
void Complex::display()      // 显示复数
{
    cout << setiosflags(ios::showpos);
    cout << i << j << 'i' << endl;
}
Complex Complex::operator-()  // 重载负运算符（ - ）
{   
    /* 传入参数为，运算符对其操作的变量，返回值为对象 */
    i = -i;  // 变量成员i取相反数
    j = -j;  // 变量成员j取相反数
    return Complex(i, j);  // 返回使用相反数声明的对象
    // return *this;  // this指针 所指向空间的值，这样写也可，建议使用此写法
}
Complex Complex::operator ++() 
{
    /* 传入参数为，运算符对其操作的变量，返回值为 this指针 所指向空间的值 */
    i = i+1;  // 变量成员i+1
    j = j+1;  // 变量成员j+1
    return *this;  // this指针 所指向空间的值
    // return Complex(i, j);  // 返回使用加一后的对象，这样写也可
    // /* 或者另一种类似的写法 */
    // Complex temp;
    // temp.i = i+1;
    // temp.j = j+1;
    // return temp;
}
Complex Complex::operator ++(int) 
{
    /* 传入参数为，运算符对其操作的变量，返回值为 临时创建的变量 temp */
    Complex temp =*this;   // 临时变量 = this指针 所指向空间的值
    // Complex temp(i,j);  // 直接定义临时变量也可
    ++*this;               // 使用重载的++()操作符
    return temp;           // 返回变量 temp
    // /* 不使用 this 指针创建变量 */
    // Complex temp;
    // temp.i = i;
    // temp.j = j;
    // i = i+1;  // 变量成员i+1
    // j = j+1;  // 变量成员j+1
    // return temp;
}
Complex Complex::operator+(const Complex& a)
{
    /* 传入参数为，运算符对其操作的变量（左值+右值，左值为自身对象，右值为()中引用定义的对象变量），
       返回值为 临时创建的变量 temp */
    Complex temp;    // 定义临时变量
    temp.i = this->i + a.i;   // 临时变量的i = this指针所指向对象的i + 传入变量a的i
    // temp.i = i + a.i;      // 临时变量的i = 变量成员i + 传入变量a的i， 测试发现不使用 this 指针也可以
    temp.j = this->j + a.j;   // 临时变量的j = this指针所指向对象的j + 传入变量a的j
    // temp.j = j + a.j;      // 临时变量的j = 变量成员j + 传入变量a的j， 测试发现不使用 this 指针也可以
    return temp;    // 返回临时变量
}
// /* 使用友元实现 + 效果 */
// Complex operator+(const Complex& a, const Complex& b)
// {
//     Complex temp;
//     temp.i = a.i + b.i;
//     temp.j = a.j + b.j;
//     return temp;
// }
//
Complex Complex::operator+(const double b)    //重载+号用于  对象与数相加
{
    /* 传入参数为，运算符对其操作的变量（左值+常数，左值为自身对象，右值为常数），
       返回值为 临时创建的变量 temp */
    Complex temp;
    temp.i = i +b;
    temp.j = j;
    return temp;
} 
Complex operator+(const double b, Complex obj) 
{   // 友元函数调用第二个重载+的成员函数，相当于 obj.operator+(b); 
    // 注意不能 const Complex& obj 
    // 因为上面定义的操作符+ ，是 obj + double ，而不是 const obj + double
    return obj+b;
}
bool Complex::operator<(const Complex& a)
{
    /* 传入参数为，运算符对其操作的变量（左值<右值，左值为自身对象，右值为()中引用定义的对象变量），
       返回值为 true或false */
    double length1,length2;
    length1 = sqrt(i*i+j*j);
    length2 = sqrt(a.i*a.i+a.j*a.j);
    if(length1 < length2)    return true;
    else return false;
}
void Complex::operator=( const Complex &obj)  // = 运算符重载，类似拷贝构造函数
{
    i = obj.i;
    j = obj.j;
}
Complex Complex::operator+=(const Complex& a)
{  
    /* 传入参数为，运算符对其操作的变量（左值+右值，左值为自身对象，右值为()中引用定义的对象变量），
       返回值为 this指针所指向的值 */
    i = i + a.i;   // 临时变量的i = this指针所指向对象的i + 传入变量a的i
    j = j + a.j;   // 临时变量的j = this指针所指向对象的j + 传入变量a的j
    return *this;    // 返回临时变量
    // return Complex(i,j);   // 返回相加后构造的对象，这样写也可
    // /* 另一种写法 */
    // Complex temp;    // 定义临时变量
    // temp.i = i + a.i;
    // temp.j = j + a.j;
    // return temp;
}
/*
补充：运算符重载
第一个默认参数，为运算符对其操作的变量。
之后的参数，为()括号内变量。
返回值自定义。

如：a = b + c;
第一个默认参数，为b
之后的参数，为()括号内变量，为c
返回值，需要赋值给a

由于是类内部重载，所以所有成员都可以直接访问。
*/
int main()
{
    Complex D1(11.5, 10.5), D2(-5, 11), D3;
	
    D1.display();   // +11.5+10.5i
    -D1;            // 取相反数
    D1.display();   // -11.5-10.5i
	
    D3 = D1++;
    D1.display();   // -10.5-9.5i
    D3.display();   // -11.5-10.5i
    
    D3 = ++D1;
    D1.display();   // -9.5-8.5i
    D3.display();   // -9.5-8.5i
 
    D3 = D1 + D2;
    D1.display();   // -9.5-8.5i
	D3.display();   // -14.5+2.5i
    
    D3 = D3 + 1 ;
    D3.display();   // -13.5+2.5i
    D3 = -3 + D3 ;
    D3.display();   // -16.5+2.5i
    
    if( D2 < D1 )   cout << "D2 is less than D1 " << endl;    // D2 is less than D1
    else            cout << "D1 is less than D2 " << endl;
    
    D3 += D2;
    D3.display();   // -21.5+13.5i
    return 0;
}
```



### 12. C++ struct 高级用法

C++ 中的 struct 对 C 中的 struct 进行了扩充，它已经不再只是一个包含不同数据类型的数据结构。
**struct 具有所有的class类 功能！** ( struct 能包含成员函数，struct 能继承，struct 能实现多态…… )

struct 和 class **核心区别**：**默认的继承访问权限**。struct 是 public 的，class 是 private 的。
如：`struct A{};  class B:A{};  /* private继承 */  struct C:B{};  /* public继承 */ `

struct 和 class 其他区别：class 关键字还可用于定义模板参数，就像 typename ，struct 不可。

struct 支持 C中所有 struct 特性；如：`struct A a={'p',7,3.1415926};`；
但是如果在 struct 中加入构造函数，则无法使用该定义方法。
如果定义简单的 class 类，将其成员类型改为 public ，也可使用该定义方法。 

**补充：因为对象可以直接赋值(拷贝构造函数) (相应的，C++中，结构体也可以)**



### 13. C++ 类与对象其他知识点

#### 13.1 做项目中用到且不知道如何分类的知识点

#### 13.2 其他

[C++ 数据抽象](https://www.runoob.com/cplusplus/cpp-data-abstraction.html)
[C++ 数据封装](https://www.runoob.com/cplusplus/cpp-data-encapsulation.html)
[C++ 接口（抽象类）](https://www.runoob.com/cplusplus/cpp-interfaces.html)

……
……
……

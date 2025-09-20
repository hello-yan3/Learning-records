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

| 类型                   | 位                        | 范围                                                         |
| :--------------------- | :------------------------ | :----------------------------------------------------------- |
| bool                   | 1 个字节                  | 0 到 1                                                       |
| char                   | 1 个字节                  | -128 到 127 或者 0 到 255                                    |
| unsigned char          | 1 个字节                  | 0 到 255                                                     |
| signed char            | 1 个字节                  | -128 到 127                                                  |
| short int              | 2 字节                    | -32,768 到 32,767                                            |
| unsigned short int     | 2 字节                    | 0 到 65,535                                                  |
| signed short int       | 2 字节                    | -32,768 到 32,767                                            |
| int                    | 2 (16位) 或 4 (32位) 字节 | -32,768 到 32,767 或 -2,147,483,648 到 2,147,483,647         |
| unsigned int           | 2 (16位) 或 4 (32位) 字节 | 0 到 65,535 或 0 到 4,294,967,295                            |
| signed int             | 2 (16位) 或 4 (32位) 字节 | -32,768 到 32,767 或 -2,147,483,648 到 2,147,483,647         |
| long int               | 4 (32位) 或 8 (64位) 字节 | -2,147,483,648 到 2,147,483,647  或<br />-9,223,372,036,854,775,808 到 9,223,372,036,854,775,807 |
| unsigned long int      | 4 (32位) 或 8 (64位) 字节 | 0 到 4,294,967,295  或<br />0 到 18,446,744,073,709,551,615  |
| signed long int        | 4 (32位) 或 8 (64位) 字节 | -2,147,483,648 到 2,147,483,647  或<br />-9,223,372,036,854,775,808 到 9,223,372,036,854,775,807 |
| long long int          | 8 字节                    | -9,223,372,036,854,775,808 到 9,223,372,036,854,775,807      |
| unsigned long long int | 8 字节                    | 0 到 18,446,744,073,709,551,615                              |
| signed long long int   | 8 字节                    | -9,223,372,036,854,775,808 到 9,223,372,036,854,775,807      |
| float                  | 4 个字节                  | 单精度型占4个字节（32位）内存空间，<br />1位符号，8位指数，23位小数；± 1.2E-38 到 3.4e ± 38 (精度 6 位小数) |
| double                 | 8 个字节                  | 双精度型占8 个字节（64位）内存空间，<br />1位符号，11位指数，52位小数；± 2.3E-308 到 1.7e ± 308 (精度 15位小数) |
| long double            | 16 个字节                 | 长双精度型 16 个字节（128位）内存空间，<br />± 3.4E-4932 到 1.2e ± 4932 (精度 19 位小数) |
| wchar_t                | 2 (32位) 或 4 (64位) 字节 | 1 个记录宽字符的数据类型；`typedef int wchar_t;`             |
| size_t                 | 4 (32位) 或 8 (64位) 字节 | 1 个记录大小的数据类型；`typedef unsigned long int size_t;`  |
| ptrdiff_t              |                           | 1 个记录两个指针之间的距离的数据类型；                       |

关于wchar_t、size_t、ptrdiff_t详见**[评论笔记5](https://www.runoob.com/cplusplus/cpp-data-types.html)**

这里简单解释`wchar_t`宽字符，因为`char`仅 256 bytes，支持字符极为有限，所以引入了宽字符 `wchar_t`；中文**汉字使用宽字符 `wchar_t`记录**。详见**[评论笔记12](https://www.runoob.com/cplusplus/cpp-strings.html)**

```C++
cout << u8"utf-8 字符串" << endl;   //控制台字符类型为UTF-8时，正常输出，输出乱码：utf-8 瀛楃涓?
wcout << L"Unicode 字符串" << endl; //控制台字符类型为Unicode时，正常输出，输出：Unicode 字符串
```

#### 6.2 typedef 别名/using 别名

可以使用 **`typedef`** 为一个已有的类型取一个新的名字，详见 **[C语言语法介绍 18章节](.\C语言 语法汇总)**
**typedef 与 #define 对比**
[**正文+评论笔记1、2**](https://www.runoob.com/cprogramming/c-typedef.html)、**[评论笔记7](https://www.runoob.com/cplusplus/cpp-data-types.html)**

使用`using`达到`typedef`效果（详见**[评论笔记11](https://www.runoob.com/cplusplus/cpp-data-types.html)**）：
```C++
// 给int起别名Int
typedef int Int;
using Int = int;     // using可读性更高

// 指向返回 void，有一个 int 参数的函数的函数指针
typedef void(*f1)(int);
using f1 = void(*)(int);     // using可读性更高

// using 在模板环境中使用
using myMap = QMap<int, bool>;
using Mapit = map<std::string, std::string, greater<string>>::iterator;    
```

#### 6.3 enum枚举类型

基本用法详见 **[C语言语法介绍 19章节](.\C语言 语法汇总)**

C++中引入：**限定作用域枚举类型**，主要用于解决：作用域污染、隐式类型转换等问题；

```C++
enum class EXEC_RSLT {
    OK = 0,
    ERROR_UNKNOWN,
    ERROR_SIGNAL_DATA_WAITTING,
};

// 正确用法：必须通过 EXEC_RSLT:: 访问
EXEC_RSLT result = EXEC_RSLT::OK;

// 错误用法：直接写 OK 会编译失败（因为 OK 仅在 EXEC_RSLT 作用域内可见）
// EXEC_RSLT result = OK;  // 编译报错

// 错误：无隐式转换为 int
// if (result == 0) { ... }  // 编译报错

// 正确：显式转换为 int
if (static_cast<int>(result) == 0) { ... }  // 合法
```

#### 6.4 数据基本类型的转换

**参考：[static_cast用法1](https://blog.csdn.net/zhouwei1221q/article/details/44978361)、[static_cast用法2](https://www.cnblogs.com/QG-whz/p/4509710.html)**：

**C语言强制转换语法尽量不要在C++中使用，使用C++中类型转换三个关键字。**基本用法：`static_cast < type-id > ( expression )`

| 转换类型           | 适用场景                         | 安全性             | 检查时机 |
| ------------------ | -------------------------------- | ------------------ | -------- |
| `static_cast`      | 基本类型、非多态类的上下转换     | 依赖开发者判断     | 编译期   |
| `dynamic_cast`     | 多态类的向下转换（需虚函数）     | 安全（运行时检查） | 运行期   |
| `reinterpret_cast` | 不相关类型、底层二进制数据重解释 | 极不安全           | 编译期   |

**1） `static_cast`（静态转换）**
用于基本数据类型、具有继承关系的类之间的转换，编译器隐式执行的任何类型转换，`void*` 与其他指针转换，以及非多态类型的转换。

**2）`dynamic_cast`（动态转换）**
仅用于**多态类**（含虚函数的类）之间的向下转换或交叉转换，提供运行时类型检查。

**3）`reinterpret_cast`（重新解释转换）**
最 “强制” 的转换，直接重新解释底层二进制数据，忽略类型安全性。用于**完全不相关的类型之间的转换**，如指针与整数互转、不同类型指针互转。

```C++
/******** 1. 基本类型转换 ********/
#include <iostream>
using namespace std;
 
int main()
{
	char a = 'c';   // a = 'c'
	int b = static_cast<int>(a);     // b = 99    // 基本数据类型转换
	char c = static_cast<char>(b);   // c = 'c'   // 基本数据类型转换
    
	char* pa = &a;        // char* pa = &'c' = 003F00060
	int* pb = (int*)pa;   // int* pb = 003F00060    // C语言风格，不推荐使用
	// int *pb = static_cast<int*>(pa);  // char* → int* error
	// pa = static_cast<char*>(pb);      // int* → char* error
	int *pb = reinterpret_cast<int*>(pa);  // char* → int*    // 不同类型指针互转
	pa = reinterpret_cast<char*>(pb);      // int* → char*    // 不同类型指针互转
    
	char *pc = (char*)pb; // char* → char* pc = c
	// char *pc = static_cast<char*>(pb); // int* → char* error
	char *pc = reinterpret_cast<char*>(pb);      // int* → char*     
    
	// static_cast可以把任何类型的表达式转换成void类型。
    void *pd = static_cast<void*>(pa);    // char* → void* pd = 003F00060
    // void类型可以转换为任何类型
	int *pe = static_cast<int*>(pd);      // void* → int* pe = 003F00060
	char *pf = static_cast<char*>(pd);    // void* → char* pf = c

    int a = 0x12345678;
    int* ptr = &a;  
    long long addr = reinterpret_cast<long long>(ptr); // 指针→整数（存储地址）  // 不相关类型转换
    
	return 0;
}
```



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

**补充**：C++中引入，`constexpr`型常量，与`const`区别如下：

- `const` 变量的值**可以在运行时确定**（例如 `const int x = get_value();`，只要 `get_value()` 在运行时返回一个值即可）。
- `constexpr` 变量的值**必须在编译时确定**（例如 `constexpr int x = 5 + 3;`，编译时可直接计算为 8）。

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

**补充**：若要输出：`//`等特殊字符，一种方法是：使用转义字符`\`，比如输出`//`，加入转义字符后为`\/\/`，此方法C语言/C++均可，
**补充：**C11新增方法：使用原始字符串，语法为 `R"(字符串内容)"`，其中的字符会被原样解析，无需转义，如：`cout << R"(//原始\t字\n符串)" << endl;`   // 字符串内的字符不进行转义



### 10. [C++ 存储类](https://www.runoob.com/cplusplus/cpp-storage-classes.html)

基本等同于C语言，详见**[C语言 12 节 C存储类](.\C语言 语法汇总)**。

| C++存储类            | 作用                                                         |
| -------------------- | ------------------------------------------------------------ |
| auto                 | C++ 中的 `auto` 和 C 语言中的 `auto` 作用 **完全不同**；<br />声明变量时根据初始化表达式自动推断该变量的类型、声明函数时函数返回值的占位符<br />尤其适合复杂类型（如 STL 容器的迭代器） |
| register             | 与 C 语言中 **register** 作用相同；                          |
| static               | 与 C 语言中 **static** 作用相同；<br />详见**[C语言 12.5 static 存储类](.\C语言 语法汇总)**；<br />当 static 用在**类数据成员**上时，会导致仅有一个该成员的副本被类的所有对象共享。详见 二、9 小节 |
| extern               | 与 C 语言中 **extern** 作用相同；<br />详见**[C语言 12.4 extern 存储类](.\C语言 语法汇总)**； |
| mutable              | **mutable** 说明符仅适用于类的对象，它允许对象的成员替代常量。也就是说，mutable 成员可以通过 const 成员函数修改。 |
| thread_local (C++11) | 使用 **thread_local** 说明符声明的变量仅可在它在其上创建的线程上访问。 |

**C++中的 `auto`用法**：

```C++
// 1. 基本用法：推导初始化变量的类型
auto num = 42;         // 推导为 int
auto pi = 3.1415;      // 推导为 double
auto str = "hello";    // 推导为 const char*
auto vec = std::vector<int>{1, 2, 3};  // 推导为 std::vector<int>

// 2. 常用功能1：简化复杂类型的声明
// 传统写法：类型冗长
std::vector<std::map<std::string, int>>::iterator it = container.begin();
// auto 写法：自动推导类型
auto it = container.begin();  // 编译器自动推导出 it 的类型

// auto 写法：自动推导类型
std::vector<std::string> fruits = {"apple", "banana", "orange"};
auto fruits = {"apple", "banana", "orange"};  // 编译器自动推导出 fruits 的类型
// auto 写法：自动推导类型
for (auto& fruit : fruits) {  // auto 推导为 std::string&
    std::cout << fruit << " ";
}

// 2. 常用功能2：处理 lambda 表达式类型
auto add = [](int a, int b) { return a + b; };  // 正确，auto 推导 lambda 类型
// 错误：无法显式写出 lambda 的类型
// some_type add = [](int a, int b) { return a + b; };
```

**C++ `auto` 使用注意事项**：


```C++
// 1. auto 变量必须初始化，否则编译器无法推导类型（编译错误）。
auto x;  // 错误：未初始化，无法推导类型

// 2. auto 推导时会忽略顶层 const 和引用，如需保留，需显式添加：
const int a = 10;
auto b = a;       // b 推导为 int（顶层 const 被忽略）
const auto c = a; // c 推导为 const int（显式保留 const）

int d = 20;
int& e = d;
auto f = e;       // f 推导为 int（引用被忽略，f 是 d 的副本）
auto& g = e;      // g 推导为 int&（显式保留引用）

// 3. C++11中，auto 不能用于函数参数、数组类型的声明，C++20 引入的 “缩写函数模板”：允许用 auto 作为形参；谨慎使用
// 正确示例（C++20 及以上）
void func(auto x) {  // 等价于 template <typename T> void func(T x)
    cout << x << endl;
}
```



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

**本质：**一种可以直接在 主程序/其他函数 中定义的函数，用起来方便快捷；

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

**人话解释**：一个函数，支持传入多种不同的数据类型；

模板函数定义的一般形式如下所示：

```C++
template <typename type> 
ret-type func-name(parameter list) { /* 函数的主体 */  }
// typename 改为 class 也可；
// 如：template <class type> 
// ret-type func-name(parameter list) { /* 函数的主体 */  }
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
    static int a_return =-29;  
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

**总体来看，引用用法与指针相似，对于二级引用，用法参考C语言二级指针！**



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
double* pvalue  = nullptr; // 初始化为 nullptr 的指针
pvalue  = new double;   // 为变量请求内存

if( !pvalue )    // if( pvalue==nullptr )  
{   // 自由存储区已被用完，可能无法成功分配内存，建议检查 new 运算符是否返回 nullptr 指针
   cout << "Error: out of memory." <<endl;
   exit(1);   // 退出程序
}

*pvalue = 29494.99;     // 在分配的地址存储值
cout << "Value of pvalue : " << *pvalue << endl;    // Value of pvalue : 29495
delete pvalue;        // 释放 pvalue 所指向的内存

int a = 20;   
pvalue = &a;       // 正确，说明pvalue变量本身并没有被销毁。销毁的是它指向的变量

// C++中，支持创建变量时直接初始化
double* pvalue2  = new double(5.0);  // 初始化 double指针，值为5.0
/*
等价于：
double* pvalue2  = new double;
*pvalue2 = 5.0;
*/

// 2. 数组的动态内存分配
int* pvalue  = nullptr;    // 初始化为 nullptr 的指针
pvalue  = new int[10];  // 分配一个包含10个int元素的一维数组
// 数组元素默认不初始化，若需初始化可加 ()：
int* arr2 = new int[5]();       // 所有元素初始化为0
int* arr3 = new int[5]{1,2,3};  // C++11及以上：前3个元素初始化，其余为0

for( int i=0; i<10; i++ )      pvalue[i] = i*i ;
for( int i=0; i<10; i++ )      cout << pvalue[i] <<endl;

delete[] pvalue;        // 注意必须加 []，表示释放的是数组
pvalue = nullptr;  // 建议置空，避免野指针

// 3. 二维数组
// 二维数组的动态分配有两种常见方式：“数组的数组”（连续内存）和 “指针数组”（非连续内存）
// 方式 1：数组的数组（连续内存，推荐）
// 1. 分配：3行4列的二维int数组
int rows = 3, cols = 4;
int(*matrix)[4] = new int[rows][4];  // cols必须是常量（编译期确定）

// 2. 使用：通过 matrix[i][j] 访问
for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
        matrix[i][j] = i * cols + j;  // 赋值示例
    }
}

// 3. 释放：直接用 delete[]
delete[] matrix;
matrix = nullptr;

// 方式 2：指针数组（非连续内存，支持动态行列数）
// 先分配一个 “指针数组”（存储每行的地址），再为每行分配内存（每行内存不连续）。
// 1. 分配：rows行cols列（行列数均可动态指定）
int rows = 3, cols = 4;
int**matrix = new int*[rows];  // 第一步：分配指针数组（存储3个int*）
for (int i = 0; i < rows; i++) {
    matrix[i] = new int[cols];  // 第二步：为每行分配cols个int
}

// 2. 使用：同样通过 matrix[i][j] 访问
matrix[0][0] = 1;
matrix[1][2] = 5;

// 3. 释放：先释放每行，再释放指针数组（顺序不可反）
for (int i = 0; i < rows; i++) {
    delete[] matrix[i];  // 释放第i行
}
delete[] matrix;        // 释放指针数组
matrix = nullptr;

// 4. 现代 C++ 推荐方案：实际开发中，建议使用 std::vector（动态数组容器）替代手动 new/delete，无需手动管理内存，更安全：
#include <vector>
// 二维vector（自动管理内存）
std::vector<std::vector<int>> matrix(3, std::vector<int>(4)); // 3行4列
```
#### **20.2 动态内存分配 及 内存泄露 问题**

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



### 21. C++ STL 容器

**[讲解1](https://zhuanlan.zhihu.com/p/564057584)、[讲解2](http://c.biancheng.net/stl)、[讲解3](https://www.jianshu.com/p/497843e403b4)、[讲解4](https://www.cnblogs.com/fusiwei/p/11823234.html)、[讲解5](https://zhuanlan.zhihu.com/p/130905242)**

**本部分需要了解学习：数据结构！**

##### 21.0 C++ string 也是容器，详见16节字符串

#### 21.1 顺序性容器

顺序性容器 就是将一组具有相同类型的元素以严格的线性形式组织起来

| 容器         | 简介说明                                                     |
| ------------ | ------------------------------------------------------------ |
| vector       | 可变大小数组。相当于数组，可动态构建，支持随机访问，无头插和尾插，仅支持insert插入，除尾部外的元素删除比较麻烦。但使用最为广泛 |
| deque        | 双端队列。支持头插、删，尾插、删，随机访问较vector容器来说慢,但对于首尾的数据操作比较方便 |
| list         | 双向循环链表。使用起来很高效，对于任意位置的插入和删除都很快，在操作过后，以后指针、迭代器、引用都不会失效 |
| forward_list | 单向链表。只支持单向访问，在链表的任何位置进行插入/for (it = v.begin(); it != v.end(); ++it)删除操作都非常快 |
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
    // 另一种写法：for (aito it = v.begin(); it != v.end(); ++it)，以下循环均可用auto
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
    list<int>::iterator it;
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

##### **1）vector（向量）**

对于vector容器，它的数据结构与数组非常类似，但是他们之间的不同之处是数组是静态空间，一旦配置了就不能更改，vector却可以进行动态分配，随着元素的插入和删除，内部的空间也会灵活变动，就和C语言中的malloc和C++中的new是一个道理，不用害怕空间不足而一开始就定义一个很大的数组，节省了内存空间。
<img src="https://pic2.zhimg.com/v2-b5573d13519584d0a9068b13a4d03f4d_r.jpg" alt="img" style="zoom:85%;" />
**基本操作**

> (1)头文件`#include<vector>`.
> (2)创建vector对象，`vector<int> vec`;void PrintVector(vector<int>&v) { for (vector<int>::iterator it = v.begin(); it != v.end(); it++) { 	cout << *it << ' '; }    // iterator 迭代器，相当于指针 cout << endl; }
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
#include <iostream>
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
PrintVector(v3);   // 100 100 100 100 100 100 100 100 

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
#include <iostream>
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
PrintVector(d3);   // 100 100 100 100 100 100 100 100 100 100

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
//d1.resize(15);   // 0 1 2 3 4 5 6 7 8 9 0 0 0 0 0
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
#include <iostream>
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

// 容器创建
list<int> l1{1,2,3,4,5,6,7,8,9,10};
PrintList(l1);
list<int> l2(3, 100); // 100 100 100

// 插入删除
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
#include <iostream>
#include <utility>      // pair
using namespace std;   // 注意需要引入标准命名空间

// 容器支持任何元素
pair <string, double> pair01;
pair <int, double> pair02;

// 调用构造函数 1，也就是默认构造函数
pair <string, string> pair1;
// 调用第 2 种构造函数
pair <string, string> pair2("STL教程","http://c.biancheng.net/stl/");  
// 调用拷贝构造函数
pair <string, string> pair3(pair2);
//调用移动构造函数
pair <string, string> pair4(make_pair("C++教程", "http://c.biancheng.net/cplus/"));
// 调用第 5 种构造函数
pair <string, string> pair5(string("Python教程"), string("http://c.biancheng.net/python/"));  

cout << "pair1: " << pair1.first << " " << pair1.second << endl;
cout << "pair2: " << pair2.first << " " << pair2.second << endl;
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

// 输出容器内部的值（键值的访问）
// 更推荐方法：template <typename T1>  void PrintMap(T1& myMap)
void PrintMap(map<string, string>& myMap)
{
if (!myMap.empty()) {
        //借助 myMap 容器迭代器，将该容器的键值对逐个输出
    	//推荐使用auto类型自动输出：
    	//for (auto i = myMap.begin(); i != myMap.end(); ++i) {
        for (map< std::string, std::string >::iterator i = myMap.begin(); i != myMap.end(); ++i) {
            cout << i->first << " " << i->second << endl;
        }
    }  
}

/************** 容器的创建 **************/
map<string, int>myMap;  // 创建空容器
map<string, int>myMap{ {"C语言教程",10},{"STL教程",20} };  // 创建时初始化
map<string, int>myMap{make_pair("C语言教程",10),make_pair("STL教程",20)};  // 使用pair初始化
map<string, int>newMap(myMap);  // 利用先前已创建好的 map 容器，再创建一个新的 map 容器

//创建空 map 容器，默认根据个键值对中键的值，对键值对做降序排序
map<string, string, greater<string>>myMap;
//创建空 map 容器，不进行排序处理
map<string, string>myMap;  

//调用 emplace() 方法，直接向 myMap 容器中指定位置构造新键值对
//调用 insert() 方法，需要先创建一个 std::pair<Key, Value> 对象，再将对象插入新键值对
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
#include <iostream>
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
#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

q.push(10);
q.push(20);
q.push(30);
q.push(40);		//入队列

cout << "队列大小\t队头元素\t队尾元素" << endl;
while (!q.empty())
{
    cout <<  q.size() <<"\t\t" << q.front() << "\t\t" << q.back() << endl;
    q.pop();	//出队列
}

cout << "出队列后的大小为：" << q.size() << endl;
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
#include <iostream>
#include <queue>
using namespace std;

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

#### 21.7 C++ 中的哈希查找示例

```C++
#include <iostream>
#include <unordered_map> // 哈希表容器
using namespace std;

int main() {
    // 创建哈希表（键为int，值为string）
    unordered_map<int, string> hashTable;

    // 插入数据（构建哈希表）
    hashTable[1001] = "张三";
    hashTable[1002] = "李四";
    hashTable[1003] = "王五";

    // 哈希查找：通过键1002查找
    int targetKey = 1002;
    // find()方法内部通过哈希函数定位，平均O(1)时间
    auto it = hashTable.find(targetKey);

    if (it != hashTable.end()) {
        cout << "找到：" << it->second << endl; // 输出：找到：李四
    } else {
        cout << "未找到" << endl;
    }

    return 0;
}
```

### 22. [C++多线程](https://www.runoob.com/cplusplus/cpp-multithreading.html)

#### 22.1 背景介绍：为什么你需要学习多线程？

**1.1 什么是多线程？**

- **单线程程序**：想象你只有一个厨师在厨房里工作。他必须按顺序完成所有任务：洗菜 → 切菜 → 炒菜 → 上菜。如果洗菜花了 10 分钟，其他任务只能干等。
- **多线程程序**：现在有 4 个厨师（线程）共享同一个厨房（进程内存空间）。洗菜的厨师可以和切菜的厨师同时工作，大大缩短总时间。
- **技术定义**：多线程是**同一进程内多个独立执行流并发运行**的编程模型。每个线程有独立的栈（局部变量），但共享堆内存（全局/静态变量）。

**1.2 多线程 vs 单线程核心区别**

| 特性         | 单线程                     | 多线程                          |
|--------------|----------------------------|---------------------------------|
| 执行方式     | 顺序执行                   | 并发执行（逻辑上同时运行）      |
| 资源利用     | 仅用一个 CPU 核心          | 可利用多核 CPU 并行计算         |
| 响应性       | 长任务会卡住整个程序       | 后台任务不影响 UI 响应          |
| 复杂度       | 简单（无同步问题）         | 复杂（需处理数据竞争、死锁等）  |
| 内存开销     | 低                         | 较高（每个线程需独立栈空间）    |


**1.3 为什么需要多线程？3 个核心场景**

1. **提升性能**
   现代 CPU 都是多核（如 4 核、8 核）。单线程只能用 1 个核心，多线程可让所有核心同时工作。
   *例如：视频渲染时，每个线程处理一帧画面，速度提升近 N 倍（N=核心数）。*
2. **改善用户体验**
   避免程序“卡死”。
   *例如：GUI 程序中，主线程处理用户点击，后台线程下载文件。下载慢时 UI 仍能响应。*

1. **模拟并发场景**
   *例如：服务器同时处理多个客户端请求，每个请求一个线程。*

**1.4 多线程的挑战（提前预警）**

- **竞态条件（Race Condition）**：多个线程同时修改共享数据，结果依赖执行顺序（如两个线程同时 `i++`，可能丢掉一次修改）。
- **死锁（Deadlock）**：线程 A 锁住资源 X 等待 Y，线程 B 锁住 Y 等待 X，互相僵持。
- **解决方案**：使用**同步机制**（互斥锁、条件变量等）—— 这正是本教程的重点！

> 💡 **关键认知**：多线程不是“银弹”。如果任务无法并行化（如必须严格顺序执行），多线程反而增加开销。优先考虑 `std::async` 或任务队列等高级抽象。 

#### **22.2 多线程 API 速查表（C++11 标准库）**

以下是最常用的 **5 个核心组件**（附简明说明），完整代码示例见第三部分。

| API 类型     | 常用函数/类                        | 作用说明                                      | 使用场景             |
| ------------ | ---------------------------------- | --------------------------------------------- | -------------------- |
| **线程管理** | `std::thread t(func, args...)`     | 创建新线程执行函数 `func`                     | 启动后台任务         |
|              | `t.join()`                         | 阻塞主线程，等待 `t` 结束                     | 确保线程完成后再继续 |
|              | `t.detach()`                       | 分离线程（不再等待，生命周期由系统管理）      | 独立运行的守护线程   |
| **互斥锁**   | `std::mutex m`                     | 基本互斥锁                                    | 保护共享数据         |
|              | `m.lock() / m.unlock()`            | 手动加锁/解锁（易出错，**推荐用 RAII 封装**） | —                    |
|              | `std::lock_guard<mutex> lock(m)`   | RAII 锁：构造时加锁，析构时自动解锁           | 安全保护代码块       |
| **条件变量** | `std::condition_variable cv`       | 线程间通信：等待某个条件成立                  | 生产者-消费者模型    |
|              | `cv.wait(lock, predicate)`         | 阻塞线程，直到 `predicate` 为 true            | —                    |
|              | `cv.notify_one() / notify_all()`   | 唤醒等待的线程                                | —                    |
| **异步操作** | `std::async(func, args...)`        | 启动异步任务，返回 `std::future`              | 简单并行计算         |
|              | `future.get()`                     | 获取异步结果（阻塞直到结果就绪）              | —                    |
| **线程控制** | `std::this_thread::sleep_for(...)` | 线程休眠（避免忙等待）                        | 定时任务/限流        |
|              | `std::this_thread::yield()`        | 主动让出 CPU 时间片                           | 高优先级任务让步     |

> ✅ **最佳实践**：  
> - 优先用 `std::lock_guard` 代替手动 `lock/unlock`（防死锁）  
> - 避免 `detach()`（难管理），多用 `join()`  
> - 共享数据必须加锁！无例外！

#### 22.3 基础示例1：多线程功能演示

```C++
#include <iostream>
#include <thread>
#include <chrono>  // 用于模拟耗时操作

// 烧水 烧水
void boilWater() {
    std::cout << "开始烧水...\n";
    std::this_thread::sleep_for(std::chrono::seconds(5));  // 模拟烧水需要5秒
    std::cout << "水烧开了！\n";
}

// 🔪 切菜
void chopVegetables() {
    std::cout << "开始切菜...\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));  // 模拟切菜需要3秒
    std::cout << "菜切好了！\n";
}

// 🔥 炒菜
void cookDish() {
    std::cout << "开始炒菜...\n";
    std::this_thread::sleep_for(std::chrono::seconds(4));  // 模拟炒菜需要4秒
    std::cout << "菜炒好了！\n";
}

int main() {
    // 单线程方式（一步步做）
    // 总耗时 = 5 + 3 + 4 = 12秒
    std::cout << "=== 单线程做饭 ===\n";
    auto start = std::chrono::high_resolution_clock::now();
    
    boilWater();    // 先等水烧开才能做别的
    chopVegetables();// 再切菜
    cookDish();     // 最后炒菜
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> singleThreadTime = end - start;
    std::cout << "单线程总耗时: " << singleThreadTime.count() << "秒\n\n";


    // 多线程方式（同时做）
    // 总耗时 = 5 + 4 = 9秒（因为烧水的同时可以切菜，最后一起炒菜）
    std::cout << "=== 多线程做饭 ===\n";
    start = std::chrono::high_resolution_clock::now();
    
    std::thread t1(boilWater);    // 线程1负责烧水
    std::thread t2(chopVegetables);// 线程2负责切菜（和烧水同时进行）
    
    t1.join();  // 等待水烧开
    t2.join();  // 确保菜也切好了
    cookDish(); // 水和菜都准备好了再炒菜
    
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> multiThreadTime = end - start;
    std::cout << "多线程总耗时: " << multiThreadTime.count() << "秒\n";

    return 0;
}

/*
输出：
=== 单线程做饭 ===
开始烧水...
水烧开了！
开始切菜...
菜切好了！
开始炒菜...
菜炒好了！
单线程总耗时: 12.0278秒

=== 多线程做饭 ===
开始烧水...
开始切菜...
菜切好了！
水烧开了！
开始炒菜...
菜炒好了！
多线程总耗时: 9.05323秒
*/
```

#### 22.4 基础示例2：创建线程并等待（理解 `std::thread` 基础）

```cpp
#include <iostream>
#include <thread>
#include <chrono>

// 线程函数：打印消息并休眠
void thread_task(int id) {
    std::cout << "线程 " << id << " 开始工作..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1)); // 休眠1秒（模拟工作）
    std::cout << "线程 " << id << " 完成工作!" << std::endl;
}

int main() {
    std::cout << "主线程启动" << std::endl;

    // 创建3个线程，每个线程执行 thread_task 函数（传入不同ID）
    std::thread t1(thread_task, 1);
    std::thread t2(thread_task, 2);
    std::thread t3(thread_task, 3);

    // 主线程继续执行（不等待子线程）
    std::cout << "主线程继续执行其他任务..." << std::endl;

    // 等待所有子线程结束（关键！否则主线程退出会导致子线程被强制终止）
    t1.join();
    t2.join();
    t3.join();

    std::cout << "所有线程已结束，程序退出" << std::endl;
    return 0;
}
```

**这段程序用到了什么？**
- **核心 API**：`std::thread`（创建线程）、`join()`（等待线程结束）
- **关键机制**：
  - 线程通过函数指针启动（可传参）
  - `sleep_for` 模拟耗时操作（避免 CPU 空转）
  - **必须调用 `join()`**：否则主线程结束时，子线程会被强制终止（导致未定义行为）

**为什么重要？**

- 这是多线程的**最简模型**：创建 → 工作 → 等待结束。
- 注意：`detach()` 未使用——分离线程后无法 `join()`，易导致资源泄漏。

> ✨ **运行效果**：  
> 主线程启动 → 打印"继续执行" → 3 个子线程并行工作 → 所有线程结束。  
> *注意：子线程的打印顺序可能随机（并发执行的不确定性）！*

#### 示例3：共享数据与互斥锁（解决竞态条件）

```C++
#include <iostream>
#include <thread>
#include <mutex>

int shared_counter = 0; // 全局共享变量（所有线程可见）
std::mutex mtx;         // 互斥锁（保护 shared_counter）

// 线程函数：对共享变量累加 1000 次
void increment_counter(int id) {
    for (int i = 0; i < 1000; ++i) {
        mtx.lock(); // 手动加锁（不推荐，仅作演示）
        ++shared_counter;
        mtx.unlock(); // 手动解锁
    }
    std::cout << "线程 " << id << " 完成累加" << std::endl;
}

int main() {
    const int num_threads = 10;
    std::thread threads[num_threads];

    // 创建10个线程并发修改 shared_counter
    for (int i = 0; i < num_threads; ++i) {
        threads[i] = std::thread(increment_counter, i);
    }

    // 等待所有线程结束
    for (auto& t : threads) {
        t.join();
    }

    // 预期结果：1000 * 10 = 10000
    std::cout << "最终计数器值: " << shared_counter << " (预期: 10000)" << std::endl;
    return 0;
}
```

**这段程序用到了什么？**
- **核心问题**：竞态条件（Race Condition
  *若不加锁*：10 个线程同时 `++shared_counter`，由于 `++` 非原子操作（读 → 改 → 写），结果会远小于 10000（如 7000）。
> ⚠️ **实验建议**：  
> 注释掉 `mtx.lock()` 和 `mtx.unlock()`，运行多次观察结果变化——这就是竞态条件的典型表现！

- **核心 API**：`std::mutex`（`lock()`/`unlock()`）

- **关键机制**：
  
  - 锁保护**临界区**（`++shared_counter` 这段代码）
  - 任意时刻只有一个线程能进入临界区

**为什么重要？**

- 这是多线程**最常见陷阱**：共享数据不加锁 → 结果错误且难以调试。
- 但注意：**手动 `lock/unlock` 易出错**（如忘记解锁或异常导致死锁）。下一例用 RAII 优化。

**RAII 锁管理（`std::lock_guard` 安全实践）**

```C++
#include <iostream>
#include <thread>
#include <mutex>

int shared_counter = 0;
std::mutex mtx;

void safe_increment(int id) {
    for (int i = 0; i < 1000; ++i) {
        // 使用 lock_guard 自动管理锁（RAII）
        std::lock_guard<std::mutex> lock(mtx); // 构造时自动加锁
        ++shared_counter; // 临界区（无需手动解锁！）
        // lock 超出作用域时自动调用析构函数解锁
    }
    std::cout << "线程 " << id << " 完成累加" << std::endl;
}

int main() {
    std::thread t1(safe_increment, 1);
    std::thread t2(safe_increment, 2);
    
    t1.join();
    t2.join();
    
    std::cout << "最终计数器值: " << shared_counter << " (预期: 2000)" << std::endl;
    return 0;
}
```

**这段程序用到了什么？**

- **核心 API**：`std::lock_guard`（RAII 锁封装）

- 关键机制：

  - **RAII 原则**（Resource Acquisition Is Initialization）：
    锁的生命周期绑定到 `lock_guard` 对象。
    → 构造函数加锁 → 作用域结束自动解锁（即使发生异常！）
  - 无需手动调用 `lock/unlock`，彻底避免死锁风险

- 对比示例 2：
  - 手动管理锁：易漏解锁（尤其在 `return` 或异常时）
  - `lock_guard`：编译器保证锁安全释放
- **黄金规则**：永远用 RAII 锁（`lock_guard`/`unique_lock`），永不手动 `lock/unlock`！

> ✨ **优势**：
> 即使 `++shared_counter` 中抛出异常，`lock_guard` 析构函数仍会解锁，避免死锁。 

#### 示例 4：生产者-消费者模型（条件变量 `std::condition_variable`）

```cpp
#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>

// 共享资源（所有线程可见）
std::queue<int> data_queue;           // 数据队列（生产者放数据，消费者取数据）
std::mutex queue_mutex;               // 互斥锁：保护data_queue的访问
std::condition_variable data_cond;    // 条件变量：用于线程间通信
bool finished = false;                // 标志：生产者是否结束

// 生产者函数：生成数据放入队列
void producer(int id) {
    for (int i = 0; i < 5; ++i) {  // 每个生产者生产5个数据
        // 模拟生产耗时（100ms）
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        
        // 生成数据（id=0生产0-4, id=1生产10-14）
        int value = id * 10 + i;
        
        // === 关键步骤1：加锁保护共享队列 ===
        {
            // 创建lock_guard自动加锁（RAII）
            std::lock_guard<std::mutex> lock(queue_mutex);
            // 此时其他线程无法访问data_queue
            
            // 将数据放入队列
            data_queue.push(value);
            std::cout << "[时间点A] 生产者 " << id 
                      << " 生成: " << value 
                      << " (队列大小=" << data_queue.size() << ")" 
                      << std::endl;
            // lock_guard析构时自动解锁
        } // 锁在这里自动释放！其他线程可访问队列
        
        // === 关键步骤2：通知消费者 ===
        data_cond.notify_one(); // 唤醒一个等待的消费者
        // 注意：这里不持有锁，避免唤醒后立即阻塞
    }
}

// 消费者函数：从队列取出数据
void consumer(int id) {
    while (true) { // 消费者持续工作
        // === 关键步骤1：获取锁（unique_lock支持条件变量） ===
        std::unique_lock<std::mutex> lock(queue_mutex);
        // 此时其他线程无法访问data_queue
        
        // === 关键步骤2：等待条件满足 ===
        // 条件：队列非空 OR 生产者已结束
        data_cond.wait(lock, [] { 
            return !data_queue.empty() || finished; 
        });
        // wait() 会：1. 检查条件 2. 条件不满足时释放锁并休眠
        // 当被唤醒时：1. 重新获取锁 2. 再次检查条件
        
        // === 关键步骤3：检查结束条件 ===
        if (finished && data_queue.empty()) {
            // 所有生产者结束且队列为空 → 退出
            std::cout << "[时间点E] 消费者 " << id 
                      << " 退出（队列空且生产结束）" 
                      << std::endl;
            return; // 退出消费者线程
        }
        
        // === 关键步骤4：处理数据 ===
        int value = data_queue.front(); // 获取队首数据
        data_queue.pop();               // 从队列移除
        // 注意：此时仍持有锁，但为提高并发性，提前解锁
        lock.unlock(); // 手动释放锁（unique_lock支持）
        
        // 模拟数据处理（50ms）
        std::cout << "[时间点D] 消费者 " << id 
                  << " 处理: " << value 
                  << " (队列大小=" << data_queue.size() << ")" 
                  << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

int main() {
    // === 阶段1：启动线程 ===
    std::thread producers[2]; // 2个生产者
    std::thread consumers[3]; // 3个消费者
    
    // 启动生产者（id=0和1）
    for (int i = 0; i < 2; ++i) {
        producers[i] = std::thread(producer, i);
    }
    
    // 启动消费者（id=0,1,2）
    for (int i = 0; i < 3; ++i) {
        consumers[i] = std::thread(consumer, i);
    }
    
    // === 阶段2：等待生产者结束 ===
    for (auto& t : producers) {
        t.join(); // 阻塞直到生产者完成
    }
    // 此时所有生产者已完成5次生产（共10个数据）
    
    // === 阶段3：设置结束标志 ===
    {
        std::lock_guard<std::mutex> lock(queue_mutex);
        finished = true; // 标记生产结束
    } // 自动解锁
    
    // === 阶段4：唤醒所有消费者 ===
    data_cond.notify_all(); // 通知所有等待的消费者
    
    // === 阶段5：等待消费者结束 ===
    for (auto& t : consumers) {
        t.join(); // 等待所有消费者处理完剩余数据
    }
    
    std::cout << "所有任务完成!" << std::endl;
    return 0;
}

/*
生产者 1 生成: 10
生产者 0 生成: 0
消费者 0 处理: 10
消费者 1 处理: 0
生产者 1 生成: 11
生产者 0 生成: 1
消费者 消费者 20 处理:  处理: 111

生产者 0 生成: 2
生产者 1 生成: 12
消费者 消费者 1 处理: 2
0 处理: 12
生产者 0 生成: 3
消费者 生产者 12 生成:  处理: 133

消费者 1 处理: 13
生产者 1 生成: 14
消费者 生产者 00 处理:  生成: 144

消费者 1 处理: 4
所有任务完成!
*/
```

**执行时序详解（时间线分析）：**

假设系统调度顺序如下（实际可能不同，但逻辑保证正确）：

| 时间点         | 事件               | 关键状态                            | 说明                          |
| -------------- | ------------------ | ----------------------------------- | ----------------------------- |
| **T0**         | 主线程启动         | `data_queue=[]`<br>`finished=false` | 初始状态                      |
| **T1**         | 生产者0开始        | `sleep(100ms)`                      | 生成第一个数据需100ms         |
| **T2**         | 生产者1开始        | `sleep(100ms)`                      | 两个生产者同时启动            |
| **T3**         | 消费者0开始        | `wait()` 阻塞                       | 队列空，消费者0休眠           |
| **T4**         | 消费者1开始        | `wait()` 阻塞                       | 队列空，消费者1休眠           |
| **T5**         | 消费者2开始        | `wait()` 阻塞                       | 队列空，消费者2休眠           |
| **T100ms**     | 生产者0唤醒        | `value=0`                           | 生产者0生成第一个数据         |
| **T100ms+**    | 生产者0加锁        | `queue_mutex` 锁定                  | 其他线程无法访问队列          |
| **T100ms++**   | 生产者0操作队列    | `data_queue=[0]`                    | 将0放入队列                   |
| **T100ms+++**  | 生产者0解锁        | `queue_mutex` 释放                  | **关键**：解锁后立即通知      |
| **T100ms****   | 生产者0通知        | `notify_one()`                      | 唤醒一个消费者（假设消费者0） |
| **T100ms+1μs** | 消费者0唤醒        | 尝试获取锁                          | 被唤醒但需重新获取锁          |
| **T100ms+2μs** | 消费者0获取锁      | `queue_mutex` 锁定                  | 消费者0获得锁                 |
| **T100ms+3μs** | 消费者0检查条件    | `!empty()=true`                     | 队列非空，条件满足            |
| **T100ms+4μs** | 消费者0取数据      | `value=0`<br>`data_queue=[]`        | 取出数据0                     |
| **T100ms+5μs** | 消费者0解锁        | `queue_mutex` 释放                  | **关键**：提前解锁            |
| **T100ms+6μs** | 消费者0处理数据    | `sleep(50ms)`                       | 处理数据（不占锁）            |
| **T150ms**     | 消费者0唤醒        | 继续循环                            | 处理完成，进入下一轮          |
| **T150ms+**    | 消费者0再次等待    | `wait()` 阻塞                       | 队列空，再次休眠              |
| **T200ms**     | 生产者0生成1       | 同T100ms流程                        | 生产者0生成第二个数据         |
| **T200ms+**    | 生产者0通知        | 唤醒消费者1                         | 假设唤醒消费者1               |
| **T200ms++**   | 消费者1处理1       | 处理数据1                           | 消费者1处理数据               |
| **T250ms**     | 消费者1处理完      | 继续循环                            | 消费者1进入下一轮             |
| **T300ms**     | 生产者1生成10      | 同T100ms流程                        | 生产者1生成第一个数据         |
| **T300ms+**    | 生产者1通知        | 唤醒消费者2                         | 假设唤醒消费者2               |
| **T300ms++**   | 消费者2处理10      | 处理数据10                          | 消费者2处理数据               |
| **...**        | ...                | ...                                 | 持续生产消费                  |
| **T500ms**     | 所有生产者结束     | `finished=false`                    | 生产者0/1各生产5个数据        |
| **T500ms+**    | 主线程设置结束标志 | `finished=true`                     | 在锁保护下设置                |
| **T500ms++**   | 主线程广播通知     | `notify_all()`                      | 唤醒所有消费者                |
| **T500ms+++**  | 消费者0/1/2唤醒    | 检查条件                            | 队列可能还有数据              |
| **T500ms+**    | 消费者处理剩余数据 | 逐个处理                            | 消费者处理完剩余数据          |
| **T500ms+**    | 当队列空时         | `if(finished && empty)`             | 满足退出条件                  |
| **T500ms+**    | 消费者退出         | `return`                            | 消费者线程结束                |
| **T550ms**     | 所有消费者结束     | `data_queue=[]`                     | 队列最终为空                  |
| **T550ms+**    | 主线程继续         | 打印完成消息                        | 程序结束                      |

**这段程序用到了什么？**

- **核心 API**：  
  - `std::condition_variable`（条件变量）  
  - `std::unique_lock`（支持条件变量的锁）  
  - `wait()` / `notify_one()` / `notify_all()`
- **关键机制**：
  - **生产者-消费者模型**：  
    生产者生成数据 → 消费者处理数据（解耦生产/消费速度）
  - **条件变量作用**：  
    - 消费者在队列空时 `wait()`（释放锁并休眠）  
    - 生产者 `notify_one()` 唤醒一个消费者  
    - `wait()` 的 predicate 检查避免虚假唤醒

**为什么重要？**

- 这是**线程同步的高级模式**，解决“忙等待”问题（示例 3 中线程会空转占用 CPU）。
- `unique_lock` 比 `lock_guard` 更灵活：  
  - 可手动 `unlock()`（如处理数据时不占锁）  
  - 支持条件变量（`lock_guard` 不支持）
- **核心思想**：条件变量用于**事件通知**，而非保护数据（数据仍需互斥锁保护）。

**关键机制深度解析：**

1. 为什么消费者需要 `while(true)` + 条件检查？
```cpp
data_cond.wait(lock, []{ 
    return !data_queue.empty() || finished; 
});
```
- **虚假唤醒问题**：操作系统可能在没有 `notify` 时唤醒线程
- **多消费者竞争**：多个消费者被唤醒，但只有一个能取到数据
- **解决方案**：每次唤醒都重新检查条件
  - 如果队列空且生产未结束 → 继续等待
  - 如果队列空但生产结束 → 退出

2. 为什么消费者要提前解锁？
```cpp
int value = data_queue.front();
data_queue.pop();
lock.unlock(); // 提前解锁

// 处理数据（不占锁）
std::cout << "消费者 " << id << " 处理: " << value << std::endl;
```
- **性能关键**：处理数据（打印/计算）不需要访问队列
- **提高并发**：解锁后其他消费者/生产者可立即操作队列
- **对比**：如果处理数据时不解锁，其他线程会阻塞等待

3. 为什么用 `unique_lock` 而不是 `lock_guard`？
```cpp
std::unique_lock<std::mutex> lock(queue_mutex);
data_cond.wait(lock, predicate);
```
- **条件变量要求**：`wait()` 需要能**临时释放锁**
- `lock_guard`：构造时加锁，析构时解锁（**不能临时释放**）
- `unique_lock`：支持手动 `lock()`/`unlock()`（**满足条件变量需求**）

4. 结束流程为什么需要 `notify_all`？
```cpp
// 生产者结束后
{
    std::lock_guard<std::mutex> lock(queue_mutex);
    finished = true;
}
data_cond.notify_all(); // 关键！
```
- **多消费者场景**：可能有多个消费者在等待
- **单次 `notify_one` 不够**：只能唤醒一个消费者
- **安全退出**：需要通知**所有**消费者检查 `finished` 标志

5. 为什么需要 `finished` 标志？
```cpp
if (finished && data_queue.empty()) {
    break; // 退出消费者
}
```
- **解决"饿死"问题**：消费者可能永远等待新数据
- **生产结束信号**：告诉消费者"不再有新数据了"
- **无此标志的后果**：消费者在队列空时会永久阻塞

🌟 模型核心思想总结

1. **解耦生产/消费速度**  
   - 生产者快 → 队列堆积数据  
   - 消费者快 → 消费者等待  
   - 通过队列缓冲，双方独立工作

2. **条件变量的双重作用**  
   - **事件通知**：`notify` 告知"有数据"或"生产结束"  
   - **条件检查**：`wait` 确保"只有条件满足才继续"

3. **锁的精细控制**  
   - 仅在**访问共享数据**时加锁（队列操作）  
   - **处理数据时不占锁**（提高并发性）

4. **安全退出机制**  
   - `finished` 标志 + `notify_all` → 避免消费者永久等待

> ✅ **终极理解**： 
> 生产者-消费者模型本质是**用空间换时间**——通过队列这个"缓冲区"，让生产者和消费者解耦，最大化利用CPU资源。条件变量和互斥锁是保证这个缓冲区安全访问的"交通规则"。

#### 示例 5：异步任务与结果获取（`std::async` 和 `std::future`）

```C++
#include <iostream>
#include <future>
#include <chrono>
#include <thread>

// 耗时计算：模拟复杂任务
int heavy_computation(int input) {
    std::this_thread::sleep_for(std::chrono::seconds(2)); // 模拟2秒计算
    return input * input;
}

int main() {
    // 启动异步任务（自动选择策略：可能新线程或延迟执行）
    std::future<int> result = std::async(heavy_computation, 10);
    
    // 主线程做其他事（不阻塞）
    std::cout << "主线程：正在执行其他任务..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    
    // 尝试获取结果（若未完成则阻塞）
    std::cout << "等待计算结果..." << std::endl;
    int value = result.get(); // 阻塞直到结果就绪
    
    std::cout << "计算结果: " << value << std::endl;
    return 0;
}
```

**这段程序用到了什么？**

- **核心 API**：  
  - `std::async(func, args...)` → 返回 `std::future`  
  - `future.get()` → 获取异步结果（阻塞）
- **关键机制**：
  - **异步操作抽象**：无需手动管理线程，专注任务逻辑
  - `future` 封装结果：  
    - `get()` 阻塞直到结果就绪  
    - 可检查状态（`wait_for`/`wait_until`）
  - 默认策略：`std::launch::async | std::launch::deferred`  
    （可能新线程，也可能延迟到 `get()` 时执行）

**为什么重要？**

- **简化并行编程**：适合简单任务（如单次计算、I/O 操作）。
- 对比 `std::thread`：  
  - `thread` 更底层（需手动同步）  
  - `async` 高层抽象（自动处理线程生命周期）
- **何时用**：  
  - 需要结果 → 用 `async` + `future`  
  - 仅需后台执行 → 用 `thread`

> ⚠️ **注意**： 
> `future.get()` 只能调用一次！多次调用会抛出异常。 
> 需多次获取结果？用 `std::shared_future`。

**使用 `std::thread` 能否实现与示例5相同的效果？**
可以，但是需要设置全局共享变量，之后使用互斥锁确保线程安全地传递结果，因此较为复杂，示例如下：

```C++
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

// 共享数据结构：存储计算结果和状态
struct ComputationResult {
    int value = 0;            // 计算结果
    bool ready = false;       // 结果是否就绪
    std::mutex mtx;           // 保护共享数据的互斥锁
    std::condition_variable cv; // 用于通知结果就绪
};

// 耗时计算函数（修改为通过共享结构返回结果）
void heavy_computation(int input, ComputationResult& result) {
    std::this_thread::sleep_for(std::chrono::seconds(2)); // 模拟2秒计算
    {
        std::lock_guard<std::mutex> lock(result.mtx);
        result.value = input * input;
        result.ready = true;
    }
    result.cv.notify_one(); // 通知结果就绪
}

int main() {
    ComputationResult result; // 创建共享结果结构
    
    // 使用thread启动计算任务
    std::thread worker(heavy_computation, 10, std::ref(result));
    
    // 主线程做其他事
    std::cout << "主线程：正在执行其他任务..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    
    // 等待并获取结果
    std::cout << "等待计算结果..." << std::endl;
    {
        std::unique_lock<std::mutex> lock(result.mtx);
        // 等待结果就绪
        result.cv.wait(lock, [&]{ return result.ready; });
        std::cout << "计算结果: " << result.value << std::endl;
    }
    
    worker.join(); // 等待工作线程结束
    return 0;
}
```



### 23. [C++ 预处理器](https://www.runoob.com/cplusplus/cpp-preprocessor.html)

基本等同于C语言，详见**[C语言 6 节 C预处理](.\C语言 语法汇总)**。



### 24. [C++ 数字](https://www.runoob.com/cplusplus/cpp-numbers.html)

C++需要引用库 **\<cmath>、\<cstdlib>** ，此外基本等同于C语言，详见**[C语言 25.4 节 C标准库 math.h、25.1节 随机数](.\C语言 语法汇总)**。



### 25. [C++ 时间](https://www.runoob.com/cplusplus/cpp-date-time.html)

C++需要引用库 **\<ctime>** ，此外基本等同于C语言，详见**[C语言 25.5 节 C标准库 time.h](.\C语言 语法汇总)**。



### 26. C++ 其他

**[C++ 文件和流](https://www.runoob.com/cplusplus/cpp-files-streams.html)**
**[C++ 异常处理](https://www.runoob.com/cplusplus/cpp-exceptions-handling.html)**

注意：C语言也有这两部分，不过差别较大。

**异常处理：**

在 C++ 中，`try{} catch{}` 是用于异常处理的机制，用于捕获和处理程序运行时可能出现的错误或异常情况，避免程序直接崩溃。
其基本结构如下：

```c++
try {
    // 可能会抛出异常的代码块
    // 例如：除以零、数组越界、内存分配失败等操作
}
catch (异常类型1 参数名) {
    // 当 try 块中抛出异常类型1的异常时，执行这里的处理代码
}
catch (异常类型2 参数名) {
    // 当 try 块中抛出异常类型2的异常时，执行这里的处理代码
}
// 可以有多个 catch 块，捕获不同类型的异常
catch (...) {
    // 捕获所有未被前面 catch 块处理的异常（通配符）
}
```

**工作流程**：

1. 程序执行 `try` 块中的代码。
2. 如果在 `try` 块中发生异常（通过 `throw` 语句主动抛出，或某些标准库函数自动抛出），程序会立即跳出 `try` 块，寻找匹配的 `catch` 块。
3. 找到匹配的 `catch` 块后，执行其中的异常处理代码。
4. 如果没有找到匹配的 `catch` 块，程序会终止运行。

**示例：**

```C++
#include <iostream>
using namespace std;

int main() {
    try {
        int a = 10;
        int b = 0;
        
        if (b == 0) {
            throw "除数不能为零"; // 抛出异常
        }
        
        int result = a / b;
        cout << "结果: " << result << endl;
    }
    catch (const char* msg) { // 捕获字符串类型的异常
        cout << "捕获到异常: " << msg << endl;
    }
    
    return 0;
}
```

在这个例子中，当 `b` 为 0 时，我们主动抛出一个字符串异常，随后被 `catch` 块捕获并处理，程序不会崩溃，而是输出异常信息后继续执行。

`try{} catch{}` 机制让错误处理代码与正常业务代码分离，使程序更健壮、可读性更好。C++ 标准库也定义了一些异常类型（如 `std::out_of_range`、`std::bad_alloc` 等），可以直接使用。



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
② 单独使用**范围解析运算符 ::** 来定义；如：`double Box:: getVolume(void);`等；
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

**补充：**类中成员何时定义？
Q：以第一个 `class Box`为例，`      double length; double breadth; double height;  `是在什么时候定义的？
A：刚定义好这个class，就会定义；也就是说，刚进入构造函数之后，就会定义；更准确的说，就是初始化列表进行定义；
      如`Box(hei):height(hei){}`，首先定义length，初始化列表没有赋值，就只定义不赋值，`double length;`；
      之后定义breadth，初始化列表没有赋值，就只定义不赋值，`double breadth;`；
      最后定义height，初始化列表赋值，此时定义并赋值，`double height = hei;`；
      如果没有显式写出初始化列表，此时先定义后赋值，这也就是为什么，`Student1(int i):a(i),b(a)`这里，初始化会异常；

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
    A zc1;           // 创建zc1对象，输出：调用构造函数1
    A zc2(5);        // 创建zc2对象，输出：调用构造函数2
    
    // 以下对象创建用到了匿名对象，
    // 执行完以下代码，因为外部没有接此匿名对象的变量，此匿名又被析构了
    A(10);           // A(10)为匿名对象，输出：调用构造函数2    调用析构函数
	A(10).myshow();  // A(10)为匿名对象，输出：调用构造函数2  10  调用析构函数

    // 当匿名对象有等待初始化的对象接的时候，只调用一次构造和析构函数，A(11)匿名对象变为实例对象
    A b = A(11);     // 输出：调用构造函数2
    // 此处发生隐身转换，相当于 A a = A(12); 此处的A(12)就是一个匿名对象
	A a = 12;        // 输出：调用构造函数2

	A c;	         // 调用一次构造函数，输出：调用构造函数1
	c = A(13);       // 此处为赋值，此处的匿名对象会调用一次构造函数，输出：调用构造函数2  调用析构函数

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

##### 补充：显式控制特殊成员函数

在 C++ 中，函数后面加上 `= default` 或 `= delete` 是用于显式控制**特殊成员函数**，如：
```C++
~Box() = default;
Box(const Box &) = delete;
```
**1\. `= default`**：让编译器生成默认版本
当你在特殊成员函数后加 `= default`，表示「我希望编译器按照默认规则为我生成这个函数」。

如：`~Box() = default;`，让编译器为 `Box` 类生成默认的析构函数。

当手动定义了某些特殊成员函数（比如自定义了构造函数），编译器可能不会自动生成其他默认版本。用 `= default` 可以显式要求编译器生成，既保证了默认行为，又比自己手写更简洁、更高效（编译器生成的版本通常更优）。

**2\. `= delete`**：禁止编译器生成该函数
当你在函数后加 `= delete`，表示「我禁止这个函数被使用」，编译器会删除该函数的默认生成版本。

如：`Box(const Box &) = delete;`，禁止 `Box ` 类的**拷贝构造函数**被使用。

主要功能为：防止某些你不希望发生的操作（比如禁止拷贝、禁止赋值）。



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
      Box(const Box &obj);      // 拷贝构造函数，使用&表示引用传参
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
   // 函数传参，创建临时obj变量，输出：调用拷贝构造函数；
   // 输出：valume 大小 : 100
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
#include <iostream>
using namespace std;

class IntWrapper {
private:
    int* ptr;  // 指针成员（指向int）

public:
    // 1. 构造函数
    IntWrapper() : ptr(nullptr) { cout << "调用构造函数1" << endl; }  // 无参构造：初始化为nullptr
    IntWrapper(int value) : ptr(new int(value)) { cout << "调用构造函数2" << endl; }  // 带参构造：分配并初始化
    //IntWrapper(int value) { ptr = new int(value); }    // 和上面写法等价
   
    // 2. 拷贝构造函数（深拷贝）
    IntWrapper(const IntWrapper& other) {
        cout << "调用拷贝构造函数2" << endl;
        if (other.ptr != nullptr) {
            ptr = new int;
            *ptr = *(other.ptr);
        } else {
            ptr = nullptr;
        }
    }

    // 3. 拷贝赋值运算符（深拷贝 + 自赋值检查）
    // 这里注意，使用=赋值，默认为浅拷贝，系统不会调用定义的拷贝构造函数，而是调用默认的拷贝构造函数，此时两片内存指向同一块区域，程序出错
    IntWrapper& operator=(const IntWrapper& other) {
        cout << "调用赋值运算符" << endl;
        if (this == &other) return *this;  // 自赋值检查

        delete ptr;  // 释放旧资源

        if (other.ptr != nullptr) {
            ptr = new int;
            *ptr = *(other.ptr);
        } else {
            ptr = nullptr;
        }
        return *this;
    }

    // 4. 析构函数：释放资源
    ~IntWrapper() {
        cout << "调用析构函数" << endl;
        delete ptr;
        ptr = nullptr;
    }

    // 辅助：获取值
    int getValue() const {
        return ptr ? *ptr : 0;  // 若ptr为空，返回0
    }
};

int main() {
    IntWrapper a(42);               // 使用带参构造函数，调用构造函数2
    IntWrapper b = a;               // 使用拷贝构造函数，调用拷贝构造函数2
    IntWrapper c;                   // 使用无参构造函数，调用构造函数1
    c = a;                          // 使用拷贝赋值运算符，调用赋值运算符
    IntWrapper d = IntWrapper(100); // 右值，调用构造函数2

    cout << "a: " << a.getValue() << endl; // 输出a的值
    cout << "b: " << b.getValue() << endl; // 输出b的值
    cout << "c: " << c.getValue() << endl; // 输出c的值
    cout << "d: " << d.getValue() << endl; // 输出d的值

    return 0;
}

/*
调用构造函数2
调用拷贝构造函数2
调用构造函数1
调用赋值运算符
调用构造函数2
a: 42
b: 42
c: 42
d: 100
调用析构函数
调用析构函数
调用析构函数
调用析构函数
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

#### 5.2 补充：右值引用 与 移动构造函数：

用于将一个对象的资源（如动态内存、文件句柄等）“转移” 给另一个对象，而不是 “拷贝” 资源，从而提高性能（尤其是处理大对象时）
它的核心思想是：对于即将被销毁的临时对象（右值），直接 “抢走” 它的资源，避免无意义的拷贝。

> 右值 = **临时对象**（比如函数返回值、字面量、强制转换结果）
> 左值 = 有名字的变量（比如 `int a = 1;` 中的 `a`） 
> 使用 **`std::move()` **强制转换左值为右值：

**1\. 右值引用：**

```C++
#include <vector>
#include <string>

// 形参为右值引用
void printMessage(std::string &&message) {
    // 可以直接使用 message，此时操作的是原右值的资源
    std::cout << message << std::endl;
}

int main() {
    std::string str = "普通左值";
    
    // 正确：传递右值（临时对象）
    printMessage(std::string("临时对象"));  // 临时对象是右值
    printMessage("字符串字面量");            // 字面量是右值
    
    // 错误：不能直接传递左值（有名字的变量）
    // printMessage(str);  // 编译报错：无法将左值绑定到右值引用
    
    // 正确：通过 std::move() 将左值强制转换为右值引用
    printMessage(std::move(str));  // 此时 str 的资源会被“移动”，之后尽量不再使用 str
    
    /*******************************************************************************/
    
    std::vector<std::string> vec;

    std::string bigStr = "这是一个很长很长很长的字符串，包含1000个字符...";
    // 假设这个字符串很大，有1KB内存

    // ❌ 拷贝：会复制整个字符串内容 → 慢
    vec.push_back(bigStr);

    // ✅ 移动：直接“偷走” bigStr 的内存 → 快！
    vec.push_back(std::move(bigStr)); // 👈 bigStr 现在变为空字符串！
    vec.push_back("这是一个很长很长很长的字符串，包含1000个字符..."); // 直接传递右值字符串

    std::cout << "bigStr 长度: " << bigStr.size() << std::endl; // 输出：0
    std::cout << "vec[0] 长度: " << vec[0].size() << std::endl; // 输出：1000

    return 0;
}
```

**性能比较：**

- `void printMessage(const string&)`：不拷贝，但**不能修改**，也不能“偷资源”
- `void printMessage(string message)`：**总是拷贝**，大字符串时性能差
-  `void printMessage(string&& message)`：**零拷贝 + 可移动**，性能最优，语义清晰

**2\. 移动构造函数：**

```C++
#include <iostream>
#include <cstring>

// 一个简单的字符串类（管理动态内存）
class MyString {
public:
    char* str; // 存储字符串的动态内存

public:
    // 普通构造函数：分配内存并初始化
    MyString(const char* s) {
        str = new char[strlen(s) + 1]; // 分配内存
        strcpy(str, s);
        std::cout << "创建字符串: " << str << "（分配了新内存）\n";
    }

    // 拷贝构造函数：深拷贝（复制内容）
    MyString(const MyString& other) {
        str = new char[strlen(other.str) + 1]; // 新分配一块内存
        strcpy(str, other.str); // 复制内容
        std::cout << "拷贝字符串: " << str << "（复制了内容）\n";
    }

    // 移动构造函数：转移资源（不复制内容）
    MyString(MyString&& other) {
        str = other.str; // 直接"抢"走对方的内存
        other.str = nullptr; // 原对象的指针置空（避免被销毁）
        std::cout << "移动字符串（直接拿走了资源）\n";
    }
    
    // 👇 拷贝赋值：深拷贝整个 vector（慢）
    MyString& operator=(const MyString& other) {
		    // 第一步：释放当前内存（避免泄漏）
    		delete[] str;	

				// 第二步：分配新内存并复制内容
        str = new char[strlen(other.str) + 1]; // 分配内存
        strcpy(str, other.str);

        std::cout << "拷贝赋值\n";
        return *this;
    }

    // 👇 移动赋值：偷走 vector 内部的堆内存（快！）
    MyString& operator=(MyString&& other) noexcept {
      // 释放自己当前持有的内存（避免泄漏）
      delete[] str;
  
      // 接管 other 的资源
      str = other.str;
      other.str = nullptr; // 👈 置空，防止 other 析构时重复释放
      
      std::cout << "移动赋值\n";
      return *this;
    }

    // 析构函数：释放内存
    ~MyString() {
        if (str != nullptr) {
            std::cout << "销毁字符串: " << str << "（释放了内存）\n";
            delete[] str;
        } else {
            std::cout << "销毁空字符串（没有内存需要释放）\n";
        }
    }

    // 打印字符串内容
    void print() const {
        if (str != nullptr) {
            std::cout << "内容: " << str << "\n";
        } else {
            std::cout << "内容: （空）\n";
        }
    }
};

// 返回一个临时字符串对象（会被移动）
MyString createTempString() {
    MyString temp("我是临时字符串"); // 创建临时对象
    return temp; // 返回临时对象（会触发移动构造）
}

int main() {
    {
    // 场景1：拷贝构造（复制内容）
    std::cout << "=== 拷贝构造示例 ===\n";
    MyString s1("原始字符串");
    MyString s2 = s1; // 用s1拷贝构造s2（复制内容）
    s1.print(); // s1仍然有效
    s2.print(); // s2是复制的新内容
    }
    
    {
    // 场景2：移动构造（转移资源）
    std::cout << "\n=== 移动构造示例 ===\n";
    MyString s3 = createTempString(); // 接收临时对象（触发移动构造）
    s3.print(); // s3拿到了临时对象的资源
    }
    
    {
    // 场景3：强制移动一个左值
    std::cout << "\n=== 强制移动示例 ===\n";
    MyString s4("要被移动的字符串");
    MyString s5 = std::move(s4); // 强制移动s4到s5
    s4.print(); // s4变成空的（资源已被移走）
    s5.print(); // s5拿到了s4的资源
    }
    
    {
    std::cout << "\n=== 拷贝赋值示例 ===\n";
    MyString s6("要被赋值的字符串");
    MyString s7("原始字符串");
    s7 = s6; // 拷贝赋值
    s6.print();
    s7.print();
    }
    
    
    {
    std::cout << "\n=== 移动赋值示例 ===\n";
    MyString s8("要被移动的字符串");
    MyString s9("原始字符串");
    s9 = std::move(s8); // 移动赋值
    s8.print(); // 空
    s9.print();
    }
    
    return 0;
}

/*
=== 拷贝构造示例 ===
创建字符串: 原始字符串（分配了新内存）
拷贝字符串: 原始字符串（复制了内容）
内容: 原始字符串
内容: 原始字符串
销毁字符串: 原始字符串（释放了内存）
销毁字符串: 原始字符串（释放了内存）

=== 移动构造示例 ===
创建字符串: 我是临时字符串（分配了新内存）
内容: 我是临时字符串
销毁字符串: 我是临时字符串（释放了内存）

=== 强制移动示例 ===
创建字符串: 要被移动的字符串（分配了新内存）
移动字符串（直接拿走了资源）
内容: （空）
内容: 要被移动的字符串
销毁字符串: 要被移动的字符串（释放了内存）
销毁空字符串（没有内存需要释放）

=== 拷贝赋值示例 ===
创建字符串: 要被赋值的字符串（分配了新内存）
创建字符串: 原始字符串（分配了新内存）
拷贝赋值
内容: 要被赋值的字符串
内容: 要被赋值的字符串
销毁字符串: 要被赋值的字符串（释放了内存）
销毁字符串: 要被赋值的字符串（释放了内存）

=== 移动赋值示例 ===
创建字符串: 要被移动的字符串（分配了新内存）
创建字符串: 原始字符串（分配了新内存）
移动赋值
内容: （空）
内容: 要被移动的字符串
销毁字符串: 要被移动的字符串（释放了内存）
销毁空字符串（没有内存需要释放）
*/
```



### 6. [C++ 中 this 指针](https://www.runoob.com/cplusplus/cpp-this-pointer.html)

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



### 7. [C++ 指向类的指针](https://www.runoob.com/cplusplus/cpp-pointer-to-class.html)

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
   // 注意此方法定义指针，创建结构体，输出：Constructor called.
    
   // 现在尝试使用成员访问运算符来访问成员
   cout << "Volume of Box1: " << ptr1->Volume() << endl;   // Volume of Box1: 8
   delete ptr1, ptr2;
   
   return 0;
}
```

**注意：** **动态内存分配 + 堆区创建变量**，该方法使用更多。

#### 7.1 **对象**的动态内存分配

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
	A(int a = 1, int b = 2, int c = 3):_a(a) ,_b(b) ,_c(c)       { }

private:
	int _a;
	int _b;
	int _c;
};

int main( )
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
    
    return 0;
}
```

**使用 `new` 动态内存分配的优势**

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
    cout<<"my name is: " + this->name + " I am: " << this->age << endl;
}

/* setname函数，返回值为student类，用到了拷贝构造函数 */
student setname1(string name)
{
    student stu;
    stu.age=12;
    stu.name=name;
    return stu;
}
/* setname函数，返回值为指向student类指针 */
/* 程序运行结束，此时栈中数据销毁，指针变为野指针 */
student* setname2(string name)
{
    student stu;
    stu.age=12;
    stu.name=name;
    return &stu;
}
/* setname函数，返回值为指向student类指针 */
/* 程序运行结束，堆中数据不会被销毁 */
student* setname3(string name)
{
    student* stu= new student();
    stu->age=12;
    stu->name=name;
    return  stu;
}

int main()
{
    student stu=setname1("jim");
    stu.sayhello(); // 正确，用到了拷贝构造函数，占用较大内存

    student* p=setname2("tom");
    p->sayhello();  // ERROR，野指针
    
    student* p=setname3("tom");
    p->sayhello();  // 正确，堆中数据不会销毁。传递变量为指针，节省内存空间；
    delete p;       // 变量需要手动删除
    
    return 0;
}
```

更多请参考：**[类指针](https://blog.csdn.net/qq_42564908/article/details/108519000)、[C++中栈和堆上建立对象的区别](https://www.cnblogs.com/xiaoxiaoqiang001/p/5557704.html)、[C++ 类对象与类指针(静态和动态多态)\_静态指针和动态指针](https://blog.csdn.net/Chroniccandy/article/details/108739547)**

#### 7.2 Qt中new之后需不需要delete的问题

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
    label1=nullptr;
    return 0;
}


class MainWindow : public QMainWindow
{
	Q_OBJECT
pravite: 
    QSerialPort *serialport = nullptr; //串口指针
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
		serialport = nullptr;//清理后赋空值 看个人习惯
	}
}
```

**更多内容参考 二、C++ 类与对象 10.1集成 / 10.2 多态 内容**



### 8. [C++ 友元函数](https://www.runoob.com/cplusplus/cpp-friend-functions.html)

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



### 9. [C++ 类的静态成员](https://www.runoob.com/cplusplus/cpp-static-members.html)和[const成员](https://www.runoob.com/w3cnote/cpp-static-const.html)

#### **9.1 静态成员**

可以使用 **static** 关键字来把类成员声明为**静态成员**。
当声明类的成员为静态时，这意味着无论创建多少个类的对象，**静态成员**都**只有一个副本**。
静态成员变量是先于类的对象而存在，在类的所有对象中是共享的。
静态成员的定义**不能放置**在**类的定义**中，但是可以**在类的外部**通过使用范围解析运算符 **::** 来重新**定义**静态变量从而对它进行初始化
静态成员变量在类中仅仅是声明，没有定义，需要要在**类的外面定义**，否则就会报错；
此外，静态成员变量的定义必须放在**类外部的全局作用域**，不能放在 main() 或其他**函数内部**。

**补充：**C++17 及以上支持 **`inline` 静态成员**，则无需在类外重复定义：

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
    
      // C++17 起支持类内初始化+定义
      inline static double x = 10.0; 
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
   cout << "Final Stage Count: " << Box2.getCount() << endl;     // 通过对象名访问静态成员函数方法也可
   return 0;
}

/* 输出：
Inital Stage Count: 0
Constructor called.
Constructor called.
Final Stage Count: 2
Final Stage Count: 2
*/
```

**项目中用到的一种典型用法：**

```C++
class ConfigManager
{  
public:
    static ConfigManager& instance()  // 静态成员函数
    {	
        static ConfigManager singleton; // 局部静态实例，仅初始化一次
        return singleton;
    }         
    someMethod(){}
}

// 后续使用
ConfigManager::instance().someMethod();
```

**核心特点：** 
**唯一性：**通过`static ConfigManager singleton;`创建的是局部静态变量，在第一次调用`instance()`时初始化，之后调用不会重新创建，确保全局只有一个实例。
**全局访问：**通过`ConfigManager::instance()`可以在程序任何地方获取这个唯一实例，例如：  `MsgProxy::instance().someMethod();` // 调用单例对象的方法  

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
    int &ref;          //只能在构造函数初始化列表中初始化，此外初始化时必须指向一个变量，而不能是常数，且创建对象时必须初始化
    const int con;     //只能在构造函数初始化列表中初始化，且创建对象时必须初始化
    static int sta;    //在类的外部定义并初始化
    const static double con_sta;     // 在类的外部定义并初始化，初始化后为常值；与 static const double con_sta; 相同
    // const static double con_sta = 20.0;  // ERROR!
    const static int con_sta2 = 30;  // 正确！只有const static int成员可以直接赋值！但不推荐这种用法！
    const static inline double con_sta3; // 正确，inline静态成员可以类内部定义，C++17以上支持   
public:
    Test(int &a , int b);
    static void print();    //静态成员函数
    static void print(const Test &t );    //静态成员函数，通过对象形式使用非静态成员
    void show();
};
 
int Test::sta=0;    // static成员变量不能在构造函数初始化列表中初始化，因为它不属于某个对象。
const double Test::con_sta=20.0;   // 注意：给静态成员变量赋值时，不需要加static修饰符，但要加cosnt。
Test::Test(int &a, int b):ref(a), con(b)  {   // 注意：只能使用：ref(a), con(b)这种赋值方法
    // con = b;   // ERROR，常量不能赋值，只能使用 构造函数的初始化列表，引用型成员同理
    sta++;    // 静态数据成员++  
}
void Test::print(){
    sta++;    // 静态数据成员++  
    cout<<"static = "<< sta <<endl;
    cout<<"const static = "   << con_sta <<endl;
    // cout<<"reference = "<< ref <<endl;  // ERROR 静态成员函数不可以访问自身其他成员
    // cout<<"const = "   << con <<endl;   // ERROR 静态成员函数不可以访问自身其他成员
    cout << endl;
}
void Test::print(const Test &t ) {  //静态成员函数，通过对象形式使用非静态成员
    sta++;    // 静态数据成员++  
    cout<<"static = "<< sta <<endl;
    cout<<"const static = "   << con_sta <<endl;
    cout<<"reference = "<< t.ref <<endl;  // 
    cout<<"const = "   << t.con <<endl;   // 通过对象形式使用非静态成员
    cout << endl;
}
void Test::show(){
    sta++;    // 静态数据成员++  
    cout<<"static = "<< sta <<endl;
    cout<<"const static = "   << con_sta <<endl;
    cout<<"reference = "   << ref <<endl;
    cout<<"const = "   << con <<endl;  
    cout << endl;
}

int main(){
    int ref = 10;
    int con = 5;

    Test a(ref, con);
    Test::print();    // 通过类访问静态成员函数
    Test::print(a);   // 通过类访问静态成员函数
    a.print();        // 通过对象访问静态成员函数
    a.print(a);       // 通过对象访问静态成员函数    
    a.show();         // 通过对象访问非静态成员函数

    ref = 20;
    a.show();     // 通过对象访问静态成员函数

    return 0;
}

/* 输出：
static = 2
const static = 20

static = 3
const static = 20
reference = 10
const = 5

static = 4
const static = 20

static = 5
const static = 20
reference = 10
const = 5

static = 6
const static = 20
reference = 10
const = 5

static = 7
const static = 20
reference = 20
const = 5
*/
```

**总结：**

- 常量变量：必须通过构造函数参数列表进行初始化。
- 引用变量：必须通过构造函数参数列表进行初始化。
- 普通静态变量：要在类外通过"::"初始化。
- 静态整型常量：可以直接在定义的时候初始化。
- 静态非整型常量：不能直接在定义的时候初始化。要在类外通过"::"初始化。

参照**[评论笔记3、10](https://www.runoob.com/cplusplus/cpp-storage-classes.html)、[评论笔记4](https://www.runoob.com/cplusplus/cpp-static-members.html)**

#### 9.4 [mutable 的用法](https://blog.csdn.net/AAA123524457/article/details/80967330)与const成员函数

**1\. const成员函数：**

在 C++ 类的成员函数后加 `const`（如 `int getValue() const`），表示这个函数是**常量成员函数**（const member function）。它的核心作用是**限制函数对类成员变量的修改**，确保函数不会改变对象的状态。

**2\. mutable作用：**

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

// 注意：const成员函数不能调用类的非 const 成员函数；本质：const成员函数不能对类成员进行修改
class MyClass {
private:
    int* ptr;
public:
    void setValue(int x) {  // 非 const 函数（可能修改对象）
        *ptr = x;
    }
    
    int getValue() const {
        setValue(10);  // 编译报错：const 函数不能调用非 const 函数
        return *ptr;
    }
};
```



### 10. [C++ 继承](https://www.runoob.com/cplusplus/cpp-inheritance.html)

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
    Shape() { cout<<"Shape 构造函数被调用"<<endl; }
    void setWidth(int w)
    {
        width = w;
    }
};

// 派生类
class Rectangle : public Shape
{
public:
    Rectangle() { cout<<"Rectangle 构造函数被调用"<<endl; }
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
    /*
    输出：
    Shape 构造函数被调用
    Rectangle 构造函数被调用
    即： 先调用基类构造函数，再调用派生类构造函数
    */
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

// 注意point1 和 point2 区别
class Cpoint1
{
public:
    int xp, yp;
    Cpoint1() :xp(0), yp(0) {  cout<<"Cpoint1构造函数1被调用"<<endl;  }   
    Cpoint1(int x, int y) :xp(x), yp(y) {  cout<<"Cpoint1构造函数2被调用"<<endl;  }  
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
    Cpoint2(int x, int y) :xp(x), yp(y) {  cout<<"Cpoint2构造函数被调用"<<endl;  }   
    void show()
    {
        cout << "xp = " << xp << " ; yp = " << yp <<endl;
    }
};


class CRect11 : public Cpoint1
{
public:
    CRect11(int x1, int x2) : Cpoint1(x1, x2) {  }    // 调用Cpoint1的构造函数2，作用为：使用变量x1、x2初始化基类成员
    void showr(){ show(); }
};
class CRect12 : public Cpoint1
{
public:
	// 此方法等价于：
    // CRect12(int x1, int x2) : Cpoint1(x1, x2) {  }    // 调用Cpoint1的构造函数2，作用为：使用变量x1、x2初始化基类成员
    // 先调用Cpoint1的构造函数1，之后再进行赋值操作
    CRect12(int x1, int x2)    
    {  
		xp = x1;
		yp = x2;
    }
    void showr(){ show(); }
};
class CRect13 : public Cpoint1
{
public:
	// 调用Cpoint1的构造函数1，之后，在函数中构造匿名对象Cpoint1，构造/析构，并没有完成x1/x2的初始化
    CRect13(int x1, int x2)    
    {  
		Cpoint1(x1, x2);   // 此时会调用 Cpoint() :xp(0), yp(0) {}  初始化变量
    }
    void showr(){ show(); }
};

class CRect2 : public Cpoint2
{
public:
    // 调用Cpoint2的构造函数
    CRect2(int x1, int x2) : Cpoint2(x1, x2) {  }   // 作用为：使用变量x1、x2初始化基类成员
    // 以下的声明方法都不可以使用，因为没有定义：Cpoint(){};这种空构造函数！只能调用Cpoint(int x, int y)这种构造函数，因此必须提前赋值！
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

class CRect31 : public Cpoint1
{
private:
    Cpoint1 c1, c2;
public:
    // 先调用Cpoint1的构造函数1，初始化基类；在调用成员c1、c2的构造函数2，使用变量x1、x2初始化成员
    CRect31(int x1, int x2) : c1(x1,x2), c2(x2,x1){  }
    void showr()
    {
        cout << "c1.show():  " ;
        c1.show();
        cout << "c2.show():  " ;
        c2.show();
    } 
}; 

class CRect32 : public Cpoint1
{
private:
    Cpoint1 c1, c2;
public:
	// 此方法等价于：
    // CRect32(int x1, int x2) : c1(x1,x2), c2(x2,x1){  }
    // 先调用Cpoint1的构造函数1，初始化基类；在调用成员c1、c2的构造函数2，通过匿名对象的方式，使用变量x1、x2初始化成员
    CRect32(int x1, int x2)
    {
        c1 = Cpoint1(x1, x2);
        c2 = Cpoint1(x2, x1);
        // 等价于
        // Cpoint1 temp1(x1, x2), temp2(x2, x1);
        // c1 = temp1;
        // c2 = temp2;
    }
    void showr()
    {
        cout << "c1.show():  " ;
        c1.show();
        cout << "c2.show():  " ;
        c2.show();
    } 
}; 

class CRect33 : public Cpoint1
{
private:
    Cpoint1 c1, c2;
public:
    CRect33(int x1, int x2)
    {
        // 先调用Cpoint1的构造函数1，初始化基类；在调用成员c1、c2的构造函数1，之后再进行赋值操作
        // 注意，该方法，只能 xp/yp 是 public 的时候，才可以使用
        c1.xp = x1; c1.yp = x2;
        c2.xp = x2; c2.yp = x1;
    }
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
    // 调用Cpoint2的构造函数
    CRect4(int x1, int x2) : Cpoint2(x1, x2), c1(x1,x2), c2(x2,x1) {  }  
    // 其他方法都不可用，因为没有定义：Cpoint(){};这种空构造函数！只能调用Cpoint(int x, int y)这种构造函数，因此必须提前赋值！
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
    CRect11 p11(10,20);    // Cpoint1构造函数2被调用
    p11.showr();           // xp = 10 ; yp = 20

    CRect12 p12(10,20);    // Cpoint1构造函数1被调用
    p12.showr();           // xp = 10 ; yp = 20    

    CRect13 p13(10,20);    // Cpoint1构造函数1被调用，Cpoint1构造函数2被调用
    p13.showr();           // xp = 0 ; yp = 0

    CRect2 p2(10,20);      // Cpoint2构造函数被调用
    p2.showr();            // xp = 10 ; yp = 20

    CRect31 p31(10,20);    // Cpoint1构造函数1被调用，Cpoint1构造函数2被调用，Cpoint1构造函数2被调用
    p31.showr();           // c1.show():  xp = 10 ; yp = 20，c2.show():  xp = 20 ; yp = 10
                            
    CRect32 p32(10,20);    // Cpoint1构造函数1被调用，Cpoint1构造函数1被调用，Cpoint1构造函数1被调用，Cpoint1构造函数2被调用，Cpoint1构造函数2被调用
    p32.showr();           // c1.show():  xp = 10 ; yp = 20，c2.show():  xp = 20 ; yp = 10

    CRect33 p33(10,20);    // Cpoint1构造函数1被调用，Cpoint1构造函数1被调用，Cpoint1构造函数1被调用
    p33.showr();           // c1.show():  xp = 10 ; yp = 20，c2.show():  xp = 20 ; yp = 10

    CRect4 p4(10,20);      // Cpoint2构造函数被调用，Cpoint2构造函数被调用，Cpoint2构造函数被调用
    p4.showr();            // c1.show():  xp = 10 ; yp = 20，c2.show():  xp = 20 ; yp = 10

    return 0;
}
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

**补充：多重继承：**C++ 支持一个类同时继承多个类，以复用多个父类的功能。

```C++
class A { public: void func() {} };
class B { public: void func() {} };
class C : public A, public B {   // 一个类同时继承两个父类
    void test() {
        // 注意多重继承可能带来的的命名冲突问题
        A::func();  // 明确调用 A 的 func
        B::func();  // 明确调用 B 的 func
    }
};
```



### 11. C++[多态](https://www.runoob.com/cplusplus/cpp-polymorphism.html) / [教程(新)](http://c.biancheng.net/view/2294.html)

**1）类指针 和 类对象 区别：**

类指针是一个**指向内存中存放类对象的内存地址 的值**(也就是知道了所有类对象的地址)，那么这个指针可以**指向多个不同的对象**，这就是多态。

比如当类是有虚函数的基类时,`Func`是类的一个虚函数,则调用`Func`时：
**类对象**：调用的是他本类中自己的`Func`函数
**类指针**：调用的是分配给他空间时的那个类的`Func`函数

例如 : `Animal`是`Dog`的基类
`Animal* dog= new Dog;`
此时类指针dog调用的Func函数便是分配给他空间的Dog类中的Func函数 (Func需是虚函数才会调用成功)

**2）多态：**

通过虚函数，基类指针指向基类对象时就使用基类的成员（包括成员函数和成员变量），指向派生类对象时就使用派生类的成员。换句话说，基类指针可以按照基类的方式来做事，也可以按照派生类的方式来做事，它有多种形态，或者说有多种表现方式，我们将这种现象称为**多态（Polymorphism）**。

C++提供多态的目的是：可以**通过基类指针对所有派生类**（包括直接派生和间接派生）的成员变量和成员函数**进行“全方位”的访问**，尤其是成员函数。如果没有多态，我们只能访问成员变量。

**多态实例1：**如果不使用多态，很容易造成混乱。

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
    // 注意！此程序未delete对象！造成内存泄漏，注意此问题
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

**多态实例2：**参考：

```C++
#include <iostream>
using namespace std;

//基类People
class People1{
public:
    People1(char *name, int age): m_name(name), m_age(age){}
    void display() {  cout<<m_name<<"今年"<<m_age<<"岁了，是个无业游民。"<<endl;  }
protected:
    char *m_name;
    int m_age;
};

class People2{
public:
    People2(char *name, int age): m_name(name), m_age(age){}
    virtual void display() {  cout<<m_name<<"今年"<<m_age<<"岁了，是个无业游民。"<<endl;  }   // 虚函数
protected:
    char *m_name;
    int m_age;
};

//派生类Teacher
class Teacher1: public People1{
public:
    Teacher1(char *name, int age, int salary): People1(name, age), m_salary(salary){}
    void display() {  cout<<m_name<<"今年"<<m_age<<"岁了，是一名教师，每月有"<<m_salary<<"元的收入。"<<endl;  }
private:
    int m_salary;
};

class Teacher2: public People2{
public:
    Teacher2(char *name, int age, int salary): People2(name, age), m_salary(salary){}
    void display() {  cout<<m_name<<"今年"<<m_age<<"岁了，是一名教师，每月有"<<m_salary<<"元的收入。"<<endl;  }
private:
    int m_salary;
};

int main(){
    // 正常情况下同名函数可以使用 域运算符 :: 确定函数；
    // 直接定义结构体
    Teacher1 t1("王志刚", 23, 5000);
    t1.display();                 // 王志刚今年23岁了，是一名教师，每月有5000元的收入。
    t1.People1::display();        // 王志刚今年23岁了，是个无业游民。
    t1.Teacher1::display();       // 王志刚今年23岁了，是一名教师，每月有5000元的收入。
    cout<<endl;

    Teacher2 t2("王志刚", 23, 5000);  
    t2.display();                 // 王志刚今年23岁了，是一名教师，每月有5000元的收入。
    t2.People2::display();        // 王志刚今年23岁了，是个无业游民。
    t2.Teacher2::display();       // 王志刚今年23岁了，是一名教师，每月有5000元的收入。
    cout<<endl;

    // 定义结构体指针
    Teacher1 *p1 = new Teacher1("王志刚", 23, 5000);
    Teacher2 *p2 = new Teacher2("王志刚", 23, 5000);

    p1->display();                 // 王志刚今年23岁了，是一名教师，每月有5000元的收入。
    p1->People1::display();        // 王志刚今年23岁了，是个无业游民。
    p1->Teacher1::display();       // 王志刚今年23岁了，是一名教师，每月有5000元的收入。
    cout<<endl; 

    p2->display();                 // 王志刚今年23岁了，是一名教师，每月有5000元的收入。
    p2->People2::display();        // 王志刚今年23岁了，是个无业游民。
    p2->Teacher2::display();       // 王志刚今年23岁了，是一名教师，每月有5000元的收入。
    cout<<endl;

    // 使用 多态：
    People1 *pp1 = p1;
    People2 *pp2 = p2;

    // 非虚函数，调用的是基类的display() 
    pp1->display();      // 王志刚今年23岁了，是个无业游民。
    // 虚函数，调用的是派生类的display
    pp2->display();      // 王志刚今年23岁了，是一名教师，每月有5000元的收入。
    // pp1->Teacher1::display();    // 错误，基类指针不能调用派生类的成员函数
    // pp2->Teacher2::display();    // 错误，基类指针不能调用派生类的成员函数
    cout<<endl;

    delete p1;
    delete p2;  

    return 0;
}
```

**虚函数**作用为：当基类与继承类存在同名函数时，通过虚函数，确保程序使用继承类函数；
有了多态，您可以有多个不同的类，都带有同一个名称但具有不同实现的函数，函数的参数甚至可以是相同的。

**纯虚函数：**在基类中定义虚函数，以便在派生类中重新定义该函数更好地适用于对象，但是在基类中又不能对虚函数给出有意义的实现。此时：上面的`virtual int area() {}`可以改写为：`	virtual int area() = 0;`，二者等价；

**注意：**虚函数可以不实现定义，但不能不定义，即不能：`	virtual int area();`，
&nbsp;          否则其类是抽象类，无法实例化（不能用该类定义对象）。详见[**评论笔记4**](https://www.runoob.com/cplusplus/cpp-polymorphism.html)

**补充**：`override`关键字；显式声明派生类中的成员函数是重写（覆盖）基类中的虚函数，让编译器帮助检查 “重写” 是否正确；
            如果不匹配（如函数名拼写错误、参数类型 / 个数不同、返回值不符等），编译器会直接报错，避免运行时逻辑错误。

```C++
class Base {
public:
    // 基类中的虚函数
    virtual void func(int x) {
        cout << "Base::func(int)" << endl;
    }
};

class Derived : public Base {
public:
    // 派生类重写基类的func函数，显式加上override
    void func(int x) override {  // 正确：与基类虚函数签名完全匹配
        cout << "Derived::func(int)" << endl;
    }
};
```

**更多虚函数知识讲解详见[评论笔记](https://www.runoob.com/cplusplus/cpp-polymorphism.html)：**

>1、纯虚函数声明如下： virtual void funtion1()=0; 纯虚函数一定没有定义，纯虚函数用来规范派生类的行为，即接口。包含纯虚函数的类是抽象类，抽象类不能定义实例，但可以声明指向实现该抽象类的具体类的指针或引用。
>2、虚函数声明如下：virtual ReturnType FunctionName(Parameter) 虚函数必须实现，如果不实现，编译器将报错，错误提示为：
>3、对于虚函数来说，父类和子类都有各自的版本。由多态方式调用的时候动态绑定。
>4、实现了纯虚函数的子类，该纯虚函数在子类中就变成了虚函数，子类的子类即孙子类可以覆盖该虚函数，由多态方式调用的时候动态绑定。
>5、虚函数是C++中用于实现多态(polymorphism)的机制。核心理念就是通过基类访问派生类定义的函数。
>6、在有动态分配堆上内存的时候，析构函数必须是虚函数，但没有必要是纯虚的。
>7、友元不是成员函数，只有成员函数才可以是虚拟的，因此友元不能是虚拟函数。但可以通过让友元函数调用虚拟成员函数来解决友元的虚拟问题。
>8、析构函数应当是虚函数，将调用相应对象类型的析构函数，因此，如果指针指向的是子类对象，将调用子类的析构函数，然后自动调用基类的析构函数。

#### 补充知识点：关于基类 派生类之间的 转换

```C++
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

struct 和 class 其他区别：class 关键字还可用于定义模板参数，就像 typename ，struct 不可。

struct 支持 C中所有 struct 特性；如：`struct A a={'p',7,3.1415926};`；
但是如果在 struct 中加入构造函数，则无法使用该定义方法。
如果定义简单的 class 类，将其成员类型改为 public ，也可使用该定义方法。 

**补充：因为对象可以直接赋值(拷贝构造函数) (相应的，C++中，结构体也可以)**

示例如下：
```C++
struct AxisStatus
{
    double position;
    bool isReady;
    AxisStatus()    // 构造函数，通过此方法，实现结构体变量的默认初始值
    {
        position = 0.0;
        isReady = false;
    }
};

struct A{};  
class  B:A{};  /* private继承 */  
struct C:B{};  /* public继承 */ 
```



### 13. C++ 类与对象其他知识点

#### 13.1 做项目中用到且不知道如何分类的知识点

#### 13.2 其他

[C++ 数据抽象](https://www.runoob.com/cplusplus/cpp-data-abstraction.html)
[C++ 数据封装](https://www.runoob.com/cplusplus/cpp-data-encapsulation.html)
[C++ 接口（抽象类）](https://www.runoob.com/cplusplus/cpp-interfaces.html)

……
……
……





## 三、面向对象的程序设计思维

下面我将提供四个**完整可运行**的实例，每个实例都同时用C（面向过程）和C++（面向对象）实现。每个例子都聚焦核心差异：**过程驱动 vs 对象交互**，并包含详细注释说明思维差异。

---

#### 例子1：交通信号灯控制系统（嵌入式场景）
> **核心差异**：C直接操作硬件寄存器 vs C++通过对象状态自动触发行为

**C语言实现（面向过程）**

```c
// traffic_light_c.c
#include <stdio.h>
#include <unistd.h> // 用于sleep

// 硬件寄存器模拟（全局状态）
#define RED_LED    0x01
#define YELLOW_LED 0x02
#define GREEN_LED  0x04
unsigned char PORTB = 0x00; // 模拟GPIO端口

// 信号灯状态
typedef enum { RED, YELLOW, GREEN } LightState;
LightState current_state = RED;

// 操作硬件的函数
void set_red()    { PORTB = RED_LED;    printf("RED ON\n"); }
void set_yellow() { PORTB = YELLOW_LED; printf("YELLOW ON\n"); }
void set_green()  { PORTB = GREEN_LED;  printf("GREEN ON\n"); }

// 状态机（过程驱动）
void traffic_light_fsm() {
    switch(current_state) {
        case RED:
            set_red();
            sleep(5); // 模拟5秒延时
            current_state = GREEN;
            break;
        case GREEN:
            set_green();
            sleep(5);
            current_state = YELLOW;
            break;
        case YELLOW:
            set_yellow();
            sleep(2);
            current_state = RED;
            break;
    }
}

int main() {
    printf("Traffic Light System (C)\n");
    while(1) {
        traffic_light_fsm(); // 顺序执行状态机
    }
    return 0;
}
```
**输出**：

```
Traffic Light System (C)
RED ON
GREEN ON
YELLOW ON
RED ON
...
```

**C++实现（面向对象）**

```cpp
// traffic_light_cpp.cpp
#include <iostream>
#include <thread>
#include <chrono>

// 硬件抽象层（对象封装状态）
class TrafficLight {
private:
    enum State { RED, YELLOW, GREEN } state;
    // 硬件寄存器模拟（对象私有状态）
    unsigned char port = 0x00; 

    // 内部状态转换（对象自主行为）
    void transition() {
        using namespace std::chrono_literals;
        switch(state) {
            case RED:
                set_red();
                std::this_thread::sleep_for(5s);
                state = GREEN;
                break;
            case GREEN:
                set_green();
                std::this_thread::sleep_for(5s);
                state = YELLOW;
                break;
            case YELLOW:
                set_yellow();
                std::this_thread::sleep_for(2s);
                state = RED;
                break;
        }
    }

public:
    TrafficLight() : state(RED) {} // 初始状态

    // 对象启动自身行为（消息触发）
    void start() {
        while(true) {
            transition(); // 对象自主执行状态转换
        }
    }

private:
    // 硬件操作（封装在对象内部）
    void set_red()    { port = 0x01; std::cout << "RED ON\n"; }
    void set_yellow() { port = 0x02; std::cout << "YELLOW ON\n"; }
    void set_green()  { port = 0x04; std::cout << "GREEN ON\n"; }
};

int main() {
    std::cout << "Traffic Light System (C++)\n";
    TrafficLight light;
    light.start(); // 发送"start"消息给对象
    return 0;
}
```
**输出**：

```bash
Traffic Light System (C++)
RED ON
GREEN ON
YELLOW ON
...
```
**关键差异分析**：
| 维度         | C实现                               | C++实现                              | 为什么C++"不可捉摸"？                         |
| ------------ | ----------------------------------- | ------------------------------------ | --------------------------------------------- |
| **状态存储** | 全局变量`current_state`             | 对象私有成员`state`                  | 无法直接访问状态，必须通过对象方法            |
| **控制流**   | `main`循环调用`traffic_light_fsm()` | `light.start()`启动后对象自主运行    | `main`中只有1行代码，后续行为"消失"在对象内部 |
| **硬件操作** | 全局函数直接操作`PORTB`             | 封装在对象内部的私有方法             | 硬件细节被隐藏，无法从`main`预测操作          |
| **扩展性**   | 新增状态需修改全局状态机            | 继承`TrafficLight`覆盖`transition()` | 运行时行为由对象类型决定（多态）              |

> 💡 **调试视角**：  
> - C：在`traffic_light_fsm()`设断点，单步跟踪状态切换  
> - C++：在`transition()`设断点，但需先找到`TrafficLight`对象实例（调试器需切换到对象上下文）

---

#### 例子2：温度监控系统（传感器+报警）
> **核心差异**：C用全局函数传递数据 vs C++通过对象注册监听实现自动响应

**C语言实现（面向过程）**

```c
// temperature_c.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 全局数据（过程式典型问题）
float current_temp = 0.0;
int alarm_threshold = 30;

// 传感器模拟
float read_temperature() {
    return 25.0 + (rand() % 15); // 25-40°C随机值
}

// 报警系统（被动调用）
void check_alarm() {
    if (current_temp > alarm_threshold) {
        printf("ALARM! Temperature %.1f°C > %d°C\n", 
               current_temp, alarm_threshold);
    }
}

int main() {
    srand(time(NULL));
    printf("Temperature Monitor (C)\n");
    
    while(1) {
        current_temp = read_temperature(); // 步骤1：读取数据
        printf("Current: %.1f°C\n", current_temp);
        
        check_alarm(); // 步骤2：显式调用检查（过程顺序固定）
        
        sleep(2); // 2秒采样间隔
    }
    return 0;
}
```

**C++实现（面向对象）**

```cpp
// temperature_cpp.cpp
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>

// 报警监听器接口（对象交互契约）
class TemperatureListener {
public:
    virtual void on_temperature_high(float temp) = 0;
    virtual ~TemperatureListener() = default;
};

// 温度传感器（主动发布事件）
class TemperatureSensor {
private:
    float current_temp;
    int alarm_threshold;
    std::vector<TemperatureListener*> listeners; // 对象关系网络

public:
    TemperatureSensor(int threshold = 30) 
        : alarm_threshold(threshold) {}

    // 注册监听器（建立对象连接）
    void add_listener(TemperatureListener* listener) {
        listeners.push_back(listener);
    }

    // 传感器自主运行（对象驱动）
    void start_monitoring() {
        while(true) {
            current_temp = 25.0 + (std::rand() % 15);
            std::cout << "Current: " << current_temp << "°C\n";
            
            // 自动触发事件（隐式控制流）
            if (current_temp > alarm_threshold) {
                for (auto* listener : listeners) {
                    listener->on_temperature_high(current_temp);
                }
            }
            std::this_thread::sleep_for(2s);
        }
    }
};

// 具体报警器（对象实现接口）
class AlarmSystem : public TemperatureListener {
public:
    void on_temperature_high(float temp) override {
        std::cout << "ALARM! Temperature " << temp 
                  << "°C > threshold\n";
    }
};

int main() {
    std::srand(std::time(nullptr));
    std::cout << "Temperature Monitor (C++)\n";
    
    TemperatureSensor sensor(30);
    AlarmSystem alarm;
    
    // 建立对象关系（关键！）
    sensor.add_listener(&alarm); 
    
    sensor.start_monitoring(); // 启动传感器对象
    return 0;
}
```
**关键差异分析**：
| 维度       | C实现                         | C++实现                         | 为什么C++"不可捉摸"？                             |
| ---------- | ----------------------------- | ------------------------------- | ------------------------------------------------- |
| **数据流** | `main`显式传递`current_temp`  | 传感器自动通知监听器            | `main`中无报警逻辑，行为在对象连接时隐式定义      |
| **扩展性** | 新增报警器需修改`check_alarm` | 新建类实现`TemperatureListener` | 运行时行为取决于注册了哪些监听器                  |
| **耦合度** | 传感器和报警器硬编码耦合      | 通过接口解耦                    | 无法从`sensor.start_monitoring()`直接看到谁被调用 |
| **控制权** | `main`控制整个流程            | 传感器对象控制流程              | `main`只负责建立对象关系，不控制执行路径          |

> 💡 **调试视角**：  
> - C：在`check_alarm()`检查`current_temp`值  
> - C++：需在`on_temperature_high`设断点，但**不知道有哪些监听器**（除非查看`listeners`容器）

---

#### 例子3：银行交易系统（多对象协作）
> **核心差异**：C用全局函数操作账户 vs C++对象间直接消息传递

**C语言实现（面向过程）**

```c
// bank_c.c
#include <stdio.h>
#include <string.h>

// 账户数据结构（被动数据）
typedef struct {
    char name[50];
    float balance;
} Account;

// 过程式操作函数
void deposit(Account* acc, float amount) {
    acc->balance += amount;
    printf("Deposited $%.2f to %s. New balance: $%.2f\n",
           amount, acc->name, acc->balance);
}

void withdraw(Account* acc, float amount) {
    if (acc->balance >= amount) {
        acc->balance -= amount;
        printf("Withdrew $%.2f from %s. New balance: $%.2f\n",
               amount, acc->name, acc->balance);
    } else {
        printf("ERROR: Insufficient funds for %s\n", acc->name);
    }
}

// 转账需要全局函数（过程式典型）
void transfer(Account* from, Account* to, float amount) {
    printf("Processing transfer...\n");
    withdraw(from, amount); // 步骤1：从源账户扣款
    deposit(to, amount);    // 步骤2：向目标账户存款
}

int main() {
    Account alice = {"Alice", 1000.0};
    Account bob = {"Bob", 500.0};

    printf("Bank System (C)\n");
    transfer(&alice, &bob, 200.0);
    withdraw(&bob, 100.0);
    return 0;
}
```
**输出**：
```
Bank System (C)
Processing transfer...
Withdrew $200.00 from Alice. New balance: $800.00
Deposited $200.00 to Bob. New balance: $700.00
Withdrew $100.00 from Bob. New balance: $600.00
```

**C++实现（面向对象）**

```cpp
// bank_cpp.cpp
#include <iostream>
#include <string>

class Account {
private:
    std::string name;
    float balance;

public:
    Account(const std::string& n, float b) 
        : name(n), balance(b) {}

    // 对象自主行为（封装业务规则）
    void deposit(float amount) {
        balance += amount;
        std::cout << "Deposited $" << amount << " to " << name 
                  << ". New balance: $" << balance << "\n";
    }

    bool withdraw(float amount) {
        if (balance >= amount) {
            balance -= amount;
            std::cout << "Withdrew $" << amount << " from " << name 
                      << ". New balance: $" << balance << "\n";
            return true;
        }
        std::cout << "ERROR: Insufficient funds for " << name << "\n";
        return false;
    }

    // 关键：对象直接交互（消息传递）
    void transfer_to(Account& target, float amount) {
        std::cout << "Processing transfer...\n";
        if (withdraw(amount)) { // 源账户自主扣款
            target.deposit(amount); // 目标账户自主收款
        }
    }

    // 辅助方法（封装数据访问）
    std::string get_name() const { return name; }
};

int main() {
    std::cout << "Bank System (C++)\n";
    Account alice("Alice", 1000.0);
    Account bob("Bob", 500.0);

    alice.transfer_to(bob, 200.0); // Alice对象发起转账
    bob.withdraw(100.0);
    return 0;
}
```
**关键差异分析**：
| 维度         | C实现                      | C++实现                            | 为什么C++"不可捉摸"？                                 |
| ------------ | -------------------------- | ---------------------------------- | ----------------------------------------------------- |
| **转账逻辑** | 全局函数`transfer`控制流程 | `alice`对象主动调用`bob.deposit`   | 无法从`main`看出转账内部逻辑（隐藏在`transfer_to`中） |
| **数据访问** | 直接操作`acc->balance`     | 通过方法访问（`withdraw`内部）     | 余额修改路径分散在多个方法中                          |
| **错误处理** | 全局函数返回错误码         | 对象自主决定（`withdraw`返回bool） | 错误处理逻辑分散在对象内部                            |
| **扩展性**   | 新增功能需修改全局函数     | 继承`Account`覆盖`withdraw`等      | 运行时行为由对象类型决定（如VIP账户）                 |

> 💡 **调试视角**：  
> - C：在`transfer`函数内查看`from`/`to`指针  
> - C++：需在`Account::withdraw`和`Account::deposit`设断点，但**无法直接看到调用链**（`alice.transfer_to` → `alice.withdraw` → `bob.deposit`）

---

#### 为什么C++程序"难以捉摸"？——通过例子总结

1. **控制流隐形化**  
   - C：`main`中清晰看到`transfer → withdraw → deposit`  
   - C++：`alice.transfer_to(bob)`隐藏了内部消息传递链（可能触发`withdraw`→`deposit`→`log_transaction`）

2. **状态分散化**  
   
   - C：所有账户状态在`main`可见（`alice.balance`, `bob.balance`）  
   - C++：余额封装在对象内部，必须通过方法访问（甚至可能被多线程修改）
   
3. **行为多态化**  
   ```cpp
   // 如果Account是基类
   Account* vip = new VIPAccount("VIP", 10000.0);
   vip->withdraw(500); // 实际执行VIPAccount::withdraw()
   ```
   编译时无法确定调用哪个`withdraw`，必须运行时通过虚表解析。

4. **关系网络化**  
   - C：数据通过指针传递（`transfer(&alice, &bob)`）  
   - C++：对象间建立长期关系（`sensor.add_listener(&alarm)`），后续行为由关系网触发

---

#### 如何驯服C++的"不可捉摸"？——实战技巧
1. **绘制对象关系图**（用Draw.io/Mermaid）
   ```mermaid
   classDiagram
       class TrafficLight {
           -State state
           +start()
           -transition()
       }
       class TemperatureSensor {
           -vector~Listener~ listeners
           +add_listener()
           +start_monitoring()
       }
       class AlarmSystem {
           +on_temperature_high()
       }
       TemperatureSensor "1" *-- "0..*" TemperatureListener : notifies >
       AlarmSystem ..|> TemperatureListener
   ```

2. **调试时聚焦"消息流"而非"语句流"**
   - 在关键方法入口加日志：
     ```cpp
     void Account::transfer_to(Account& target, float amount) {
         std::cout << "[MSG] " << name << " ->transfer_to-> " << target.get_name() << "\n";
         // ...
     }
     ```

3. **用"契约编程"替代过程跟踪**
   - 不关心`withdraw`内部实现，只关心：
     - **前提**：`amount > 0`
     - **保证**：成功时余额减少，失败时余额不变
     - **副作用**：打印交易记录

4. **分层理解系统**
   | 层级       | 问题             | C语言关注点          | C++关注点                    |
   | ---------- | ---------------- | -------------------- | ---------------------------- |
   | **业务层** | "转账是否成功？" | 检查`transfer`返回值 | 检查`alice.withdraw()`返回值 |
   | **对象层** | "谁在处理转账？" | 全局`transfer`函数   | `Account`对象的方法          |
   | **数据层** | "余额如何存储？" | 直接访问`balance`    | 通过`get_balance()`          |

#### 例子4：复杂游戏战斗系统

**C++实现（面向对象）**

```C++
// game_battle_cpp.cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

/**
 * 1. 基类设计：所有角色的共同接口
 *  - 使用纯虚函数强制派生类实现关键行为
 *  - 封装状态（health, attackPower）和行为（attack, takeDamage）
 */
class Character {
protected:
    std::string name;
    int health;
    int maxHealth;
    int attackPower;

public:
    // 构造函数初始化共同属性
    Character(const std::string& n, int h, int ap) 
        : name(n), health(h), maxHealth(h), attackPower(ap) {}

    // 1.1 多态核心：虚析构函数确保正确释放派生类
    virtual ~Character() = default;

    // 1.2 多态核心：纯虚函数定义攻击行为接口
    virtual void attack(Character& target) = 0;

    // 1.3 通用行为（非虚，但可被派生类调用）
    void takeDamage(int damage) {
        health -= damage;
        std::cout << name << " takes " << damage << " damage. ";
        if (health <= 0) {
            health = 0;
            std::cout << name << " is defeated!\n";
        } else {
            std::cout << name << " has " << health << " health left.\n";
        }
    }

    // 1.4 状态查询
    bool isAlive() const { return health > 0; }
    const std::string& getName() const { return name; }
    int getHealth() const { return health; }
    int getMaxHealth() const { return maxHealth; }
};

/**
 * 2. 派生类实现：不同角色的特化行为
 *  - 通过重写基类虚函数实现多态
 *  - 添加角色特有状态和行为
 */
class Warrior : public Character {
private:
    int rage; // 战士特有资源

public:
    Warrior(const std::string& n) 
        : Character(n, 150, 25), rage(0) {}

    // 2.1 重写攻击行为（多态实现）
    void attack(Character& target) override {
        // 战士特殊机制：暴怒状态增强攻击
        int actualDamage = attackPower;
        if (rage >= 50) {
            actualDamage = static_cast<int>(attackPower * 1.5);
            rage = 0;
            std::cout << name << " unleashes a FURY ATTACK!\n";
        } else {
            rage += 10;
            std::cout << name << " builds rage (" << rage << "/50)\n";
        }
        std::cout << name << " slashes " << target.getName() 
                  << " for " << actualDamage << " damage!\n";
        target.takeDamage(actualDamage);
    }

    // 2.2 战士特有方法（不参与多态）
    int getRage() const { return rage; }
};

class Mage : public Character {
private:
    int mana; // 法师特有资源

public:
    Mage(const std::string& n) 
        : Character(n, 100, 30), mana(100) {}

    void attack(Character& target) override {
        if (mana >= 40) {
            // 法师特殊攻击：高伤害但消耗法力
            std::cout << name << " casts FIREBALL on " << target.getName() << "!\n";
            target.takeDamage(attackPower * 2);
            mana -= 40;
        } else {
            // 法力不足时使用普通攻击
            std::cout << name << " is low on mana, casts a weak spell.\n";
            target.takeDamage(attackPower / 2);
            mana += 10; // 恢复少量法力
        }
        std::cout << name << " has " << mana << " mana left.\n";
    }
};

class Archer : public Character {
private:
    bool hasAdvantage; // 弓手特有状态

public:
    Archer(const std::string& n) 
        : Character(n, 120, 20), hasAdvantage(false) {}

    void attack(Character& target) override {
        // 弓手特殊机制：优势状态（例如在高处）
        int damage = hasAdvantage ? attackPower * 2 : attackPower;
        std::cout << name << (hasAdvantage ? " (from high ground)" : "") 
                  << " shoots " << target.getName() 
                  << " for " << damage << " damage!\n";
        target.takeDamage(damage);
        // 每次攻击后优势状态消失
        hasAdvantage = false;
    }

    // 弓手特有方法：获取优势
    void gainAdvantage() {
        hasAdvantage = true;
        std::cout << name << " gains tactical advantage!\n";
    }
};

/**
 * 3. 观察者模式：战斗事件通知
 *  - BattleObserver定义事件接口
 *  - BattleManager实现具体观察者
 */
class BattleObserver {
public:
    virtual void onCharacterDeath(const Character& character) = 0;
    virtual ~BattleObserver() = default;
};

class BattleManager : public BattleObserver {
private:
    std::vector<Character*> participants;
    std::vector<BattleObserver*> observers;

public:
    // 3.1 管理战斗参与者
    void addParticipant(Character* character) {
        participants.push_back(character);
    }

    // 3.2 实现观察者接口
    void onCharacterDeath(const Character& character) override {
        std::cout << "\n*** BATTLE ALERT: " << character.getName() 
                  << " has been defeated! ***\n";
        
        // 3.3 特殊逻辑：弓手死亡时给其他弓手优势
        if (dynamic_cast<const Archer*>(&character)) {
            for (auto* participant : participants) {
                if (auto* archer = dynamic_cast<Archer*>(participant)) {
                    if (archer->isAlive()) {
                        archer->gainAdvantage();
                    }
                }
            }
        }
    }

    // 3.4 注册其他观察者（扩展点）
    void addObserver(BattleObserver* observer) {
        observers.push_back(observer);
    }

    // 3.5 通知所有观察者
    void notifyDeath(const Character& character) {
        for (auto* obs : observers) {
            obs->onCharacterDeath(character);
        }
        // 本类也是观察者，直接处理
        onCharacterDeath(character);
    }

    // 3.6 战斗主循环：对象间交互的核心
    void startBattle() {
        std::cout << "\n===== BATTLE STARTED =====\n";
        
        // 3.7 随机顺序攻击，直到只剩一个存活
        while (true) {
            int aliveCount = 0;
            Character* lastAlive = nullptr;
            
            // 检查存活角色
            for (auto* character : participants) {
                if (character->isAlive()) {
                    aliveCount++;
                    lastAlive = character;
                }
            }
            
            if (aliveCount <= 1) break;
            
            // 随机选择攻击者和目标
            Character* attacker = nullptr;
            Character* target = nullptr;
            
            do {
                attacker = participants[rand() % participants.size()];
            } while (!attacker->isAlive());
            
            do {
                target = participants[rand() % participants.size()];
            } while (target == attacker || !target->isAlive());
            
            std::cout << "\n--- " << attacker->getName() << "'s turn ---";
            
            // 3.8 关键：多态调用！实际行为由对象类型决定
            attacker->attack(*target);
            
            // 3.9 检查死亡并通知
            if (!target->isAlive()) {
                notifyDeath(*target);
            }
        }
        
        // 宣布胜利者
        for (auto* character : participants) {
            if (character->isAlive()) {
                std::cout << "\n===== " << character->getName() 
                          << " is VICTORIOUS! =====\n";
                return;
            }
        }
        std::cout << "\n===== BATTLE ENDED IN A DRAW =====\n";
    }
};

/**
 * 4. 辅助类：UI显示（展示对象如何协作）
 */
class HealthBar {
public:
    static void display(const Character& character) {
        int barWidth = 30;
        float healthRatio = static_cast<float>(character.getHealth()) / character.getMaxHealth();
        int filled = static_cast<int>(barWidth * healthRatio);
        
        std::cout << character.getName() << ": [";
        for (int i = 0; i < barWidth; ++i) {
            std::cout << (i < filled ? "=" : " ");
        }
        std::cout << "] " << character.getHealth() 
                  << "/" << character.getMaxHealth() << "\n";
    }
};

/**
 * 5. 主程序：对象生态的建立
 */
int main() {
    std::srand(static_cast<unsigned int>(time(nullptr)));
    std::cout << "=== RPG BATTLE SIMULATION (C++) ===\n";
    
    // 5.1 创建角色对象（对象生态初始化）
    Warrior warrior("Conan");
    Mage mage("Gandalf");
    Archer archer1("Legolas");
    Archer archer2("Hawkeye");
    
    // 5.2 创建战斗管理系统
    BattleManager battleManager;
    
    // 5.3 建立对象关系
    battleManager.addParticipant(&warrior);
    battleManager.addParticipant(&mage);
    battleManager.addParticipant(&archer1);
    battleManager.addParticipant(&archer2);
    
    // 5.4 显示初始状态
    std::cout << "\nInitial Health Status:\n";
    HealthBar::display(warrior);
    HealthBar::display(mage);
    HealthBar::display(archer1);
    HealthBar::display(archer2);
    
    // 5.5 启动战斗（触发对象交互）
    battleManager.startBattle();
    
    // 5.6 显示最终状态
    std::cout << "\nFinal Health Status:\n";
    HealthBar::display(warrior);
    HealthBar::display(mage);
    HealthBar::display(archer1);
    HealthBar::display(archer2);
    
    return 0;
}
```

**C语言实现：**

```C
// game_battle_c.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* 1. 模拟面向对象基础结构 */

// 1.1 类型枚举：模拟RTTI（运行时类型信息）
typedef enum {
    CHARACTER_TYPE,
    WARRIOR_TYPE,
    MAGE_TYPE,
    ARCHER_TYPE
} CharacterType;

// 1.2 函数指针类型定义：模拟虚函数表
typedef struct Character Character;
typedef void (*AttackFunc)(Character*, Character*);
typedef void (*TakeDamageFunc)(Character*, int);
typedef int (*IsAliveFunc)(const Character*);

// 1.3 基类结构体：包含虚函数表指针和公共数据
struct Character {
    CharacterType type;       // 类型标识（模拟RTTI）
    char name[50];            // 角色名称
    int health;               // 当前生命值
    int maxHealth;            // 最大生命值
    int attackPower;          // 攻击力
    
    // 虚函数表指针
    AttackFunc attack;
    TakeDamageFunc takeDamage;
    IsAliveFunc isAlive;
};

/* 2. 派生类结构体：扩展基类 */

// 2.1 战士特有数据
typedef struct {
    Character base;  // 基类部分（必须是第一个成员）
    int rage;        // 战士特有属性
} Warrior;

// 2.2 法师特有数据
typedef struct {
    Character base;
    int mana;
} Mage;

// 2.3 弓手特有数据
typedef struct {
    Character base;
    int hasAdvantage;
} Archer;

/* 3. 模拟多态：实现各类型的方法 */

// 3.1 基类通用方法实现
void character_takeDamage(Character* this, int damage) {
    this->health -= damage;
    printf("%s takes %d damage. ", this->name, damage);
    if (this->health <= 0) {
        this->health = 0;
        printf("%s is defeated!\n", this->name);
    } else {
        printf("%s has %d health left.\n", this->name, this->health);
    }
}

int character_isAlive(const Character* this) {
    return this->health > 0;
}

// 3.2 战士方法实现
void warrior_attack(Character* attackerBase, Character* targetBase) {
    Warrior* this = (Warrior*)attackerBase;
    int actualDamage = this->base.attackPower;
    
    if (this->rage >= 50) {
        actualDamage = (int)(this->base.attackPower * 1.5);
        this->rage = 0;
        printf("%s unleashes a FURY ATTACK!\n", this->base.name);
    } else {
        this->rage += 10;
        printf("%s builds rage (%d/50)\n", this->base.name, this->rage);
    }
    
    printf("%s slashes %s for %d damage!\n", 
           this->base.name, targetBase->name, actualDamage);
    targetBase->takeDamage(targetBase, actualDamage);
}

// 3.3 法师方法实现
void mage_attack(Character* attackerBase, Character* targetBase) {
    Mage* this = (Mage*)attackerBase;
    
    if (this->mana >= 40) {
        printf("%s casts FIREBALL on %s!\n", 
               this->base.name, targetBase->name);
        targetBase->takeDamage(targetBase, this->base.attackPower * 2);
        this->mana -= 40;
    } else {
        printf("%s is low on mana, casts a weak spell.\n", this->base.name);
        targetBase->takeDamage(targetBase, this->base.attackPower / 2);
        this->mana += 10;
    }
    printf("%s has %d mana left.\n", this->base.name, this->mana);
}

// 3.4 弓手方法实现
void archer_attack(Character* attackerBase, Character* targetBase) {
    Archer* this = (Archer*)attackerBase;
    int damage = this->hasAdvantage ? this->base.attackPower * 2 : this->base.attackPower;
    
    printf("%s%s shoots %s for %d damage!\n", 
           this->base.name, 
           this->hasAdvantage ? " (from high ground)" : "",
           targetBase->name, 
           damage);
    
    targetBase->takeDamage(targetBase, damage);
    this->hasAdvantage = 0; // 消耗优势
}

// 3.5 弓手特有方法（非多态）
void archer_gainAdvantage(Archer* this) {
    this->hasAdvantage = 1;
    printf("%s gains tactical advantage!\n", this->base.name);
}

/* 4. 模拟构造函数：初始化对象 */

void character_init(Character* this, CharacterType type, 
                   const char* name, int health, int attackPower) {
    this->type = type;
    strncpy(this->name, name, 49);
    this->name[49] = '\0';
    this->health = health;
    this->maxHealth = health;
    this->attackPower = attackPower;
    
    // 设置基类方法
    this->takeDamage = character_takeDamage;
    this->isAlive = character_isAlive;
    // attack将由派生类设置
}

Warrior* warrior_new(const char* name) {
    Warrior* this = (Warrior*)malloc(sizeof(Warrior));
    if (!this) return NULL;
    
    // 初始化基类部分
    character_init(&this->base, WARRIOR_TYPE, name, 150, 25);
    this->rage = 0;
    
    // 设置战士特有方法
    this->base.attack = warrior_attack;
    
    return this;
}

Mage* mage_new(const char* name) {
    Mage* this = (Mage*)malloc(sizeof(Mage));
    if (!this) return NULL;
    
    character_init(&this->base, MAGE_TYPE, name, 100, 30);
    this->mana = 100;
    
    this->base.attack = mage_attack;
    
    return this;
}

Archer* archer_new(const char* name) {
    Archer* this = (Archer*)malloc(sizeof(Archer));
    if (!this) return NULL;
    
    character_init(&this->base, ARCHER_TYPE, name, 120, 20);
    this->hasAdvantage = 0;
    
    this->base.attack = archer_attack;
    
    return this;
}

/* 5. 模拟观察者模式 */

// 5.1 观察者接口（函数指针）
typedef void (*OnCharacterDeathFunc)(void*, const Character*);

typedef struct {
    void* observer;  // 指向具体观察者
    OnCharacterDeathFunc onDeath;
} BattleObserver;

// 5.2 战斗管理器结构
typedef struct {
    Character** participants;
    int participantCount;
    int participantCapacity;
    
    BattleObserver* observers;
    int observerCount;
    int observerCapacity;
} BattleManager;

// 5.3 战斗管理器方法
BattleManager* battle_manager_new() {
    BattleManager* this = (BattleManager*)malloc(sizeof(BattleManager));
    if (!this) return NULL;
    
    this->participantCount = 0;
    this->participantCapacity = 4;
    this->participants = (Character**)malloc(sizeof(Character*) * this->participantCapacity);
    
    this->observerCount = 0;
    this->observerCapacity = 2;
    this->observers = (BattleObserver*)malloc(sizeof(BattleObserver) * this->observerCapacity);
    
    return this;
}

void battle_manager_free(BattleManager* this) {
    free(this->participants);
    free(this->observers);
    free(this);
}

void battle_manager_addParticipant(BattleManager* this, Character* character) {
    if (this->participantCount >= this->participantCapacity) {
        this->participantCapacity *= 2;
        this->participants = (Character**)realloc(this->participants, 
            sizeof(Character*) * this->participantCapacity);
    }
    this->participants[this->participantCount++] = character;
}

void battle_manager_addObserver(BattleManager* this, void* observer, OnCharacterDeathFunc onDeath) {
    if (this->observerCount >= this->observerCapacity) {
        this->observerCapacity *= 2;
        this->observers = (BattleObserver*)realloc(this->observers, 
            sizeof(BattleObserver) * this->observerCapacity);
    }
    this->observers[this->observerCount].observer = observer;
    this->observers[this->observerCount].onDeath = onDeath;
    this->observerCount++;
}

// 5.4 战斗管理器核心：角色死亡通知
void battle_manager_notifyDeath(BattleManager* this, const Character* character) {
    printf("\n*** BATTLE ALERT: %s has been defeated! ***\n", character->name);
    
    // 特殊逻辑：弓手死亡时给其他弓手优势
    if (character->type == ARCHER_TYPE) {
        for (int i = 0; i < this->participantCount; i++) {
            Character* participant = this->participants[i];
            if (participant->type == ARCHER_TYPE && participant->isAlive(participant)) {
                archer_gainAdvantage((Archer*)participant);
            }
        }
    }
    
    // 通知所有观察者
    for (int i = 0; i < this->observerCount; i++) {
        this->observers[i].onDeath(this->observers[i].observer, character);
    }
}

// 5.5 战斗主循环
void battle_manager_startBattle(BattleManager* this) {
    printf("\n===== BATTLE STARTED =====\n");
    
    while (1) {
        int aliveCount = 0;
        Character* lastAlive = NULL;
        
        // 检查存活角色
        for (int i = 0; i < this->participantCount; i++) {
            if (this->participants[i]->isAlive(this->participants[i])) {
                aliveCount++;
                lastAlive = this->participants[i];
            }
        }
        
        if (aliveCount <= 1) break;
        
        // 随机选择攻击者和目标
        Character *attacker = NULL, *target = NULL;
        
        do {
            int idx = rand() % this->participantCount;
            attacker = this->participants[idx];
        } while (!attacker->isAlive(attacker));
        
        do {
            int idx = rand() % this->participantCount;
            target = this->participants[idx];
        } while (target == attacker || !target->isAlive(target));
        
        printf("\n--- %s's turn ---", attacker->name);
        
        // 关键：手动分发多态调用！
        attacker->attack(attacker, target);
        
        // 检查死亡并通知
        if (!target->isAlive(target)) {
            battle_manager_notifyDeath(this, target);
        }
    }
    
    // 宣布胜利者
    for (int i = 0; i < this->participantCount; i++) {
        if (this->participants[i]->isAlive(this->participants[i])) {
            printf("\n===== %s is VICTORIOUS! =====\n", this->participants[i]->name);
            return;
        }
    }
    printf("\n===== BATTLE ENDED IN A DRAW =====\n");
}

/* 6. 辅助函数：模拟HealthBar类 */

void health_bar_display(const Character* character) {
    int barWidth = 30;
    float healthRatio = (float)character->health / character->maxHealth;
    int filled = (int)(barWidth * healthRatio);
    
    printf("%s: [", character->name);
    for (int i = 0; i < barWidth; ++i) {
        printf("%c", i < filled ? '=' : ' ');
    }
    printf("] %d/%d\n", character->health, character->maxHealth);
}

/* 7. 主程序：模拟对象生态 */

int main() {
    srand((unsigned int)time(NULL));
    printf("=== RPG BATTLE SIMULATION (C) ===\n");
    
    // 7.1 创建角色（手动初始化）
    Warrior* warrior = warrior_new("Conan");
    Mage* mage = mage_new("Gandalf");
    Archer* archer1 = archer_new("Legolas");
    Archer* archer2 = archer_new("Hawkeye");
    
    // 7.2 创建战斗管理器
    BattleManager* battleManager = battle_manager_new();
    
    // 7.3 建立关系
    battle_manager_addParticipant(battleManager, &warrior->base);
    battle_manager_addParticipant(battleManager, &mage->base);
    battleManager_addParticipant(battleManager, &archer1->base);
    battleManager_addParticipant(battleManager, &archer2->base);
    
    // 7.4 显示初始状态
    printf("\nInitial Health Status:\n");
    health_bar_display(&warrior->base);
    health_bar_display(&mage->base);
    health_bar_display(&archer1->base);
    health_bar_display(&archer2->base);
    
    // 7.5 启动战斗
    battle_manager_startBattle(battleManager);
    
    // 7.6 显示最终状态
    printf("\nFinal Health Status:\n");
    health_bar_display(&warrior->base);
    health_bar_display(&mage->base);
    health_bar_display(&archer1->base);
    health_bar_display(&archer2->base);
    
    // 7.7 清理资源
    free(warrior);
    free(mage);
    free(archer1);
    free(archer2);
    battle_manager_free(battleManager);
    
    return 0;
}
```

#### 两种实现的深度对比分析

**1\. 继承与多态的实现方式**

| 特性         | C++实现                                                      | C实现                                    | 为什么C++更清晰                              |
| ------------ | ------------------------------------------------------------ | ---------------------------------------- | -------------------------------------------- |
| **基类定义** | `class Character { virtual void attack() = 0; }`             | 手动定义函数指针表和类型标识             | C++编译器自动管理虚表，无需手动设置          |
| **派生类**   | `class Warrior : public Character { void attack() override; }` | 扩展结构体并手动设置函数指针             | C++自动继承基类方法，只需重写需要改变的部分  |
| **多态调用** | `attacker->attack(*target);`                                 | `attacker->attack(attacker, target);`    | C++隐藏了this指针传递，语法更自然            |
| **类型检查** | `dynamic_cast<Archer*>()`                                    | 手动比较`character->type == ARCHER_TYPE` | C++提供安全的类型转换，C需要手动管理类型标识 |

**关键差异**：  
在C++中，多态是**语言级特性**，编译器自动处理虚函数表；在C中，必须**手动模拟**整个机制，包括：
- 定义函数指针表
- 手动初始化每个对象的函数指针
- 显式传递`this`指针
- 手动管理类型标识

**2\. 对象间交互的复杂度**

| 场景                 | C++实现                                                | C实现                                                | 代码量对比                              |
| -------------------- | ------------------------------------------------------ | ---------------------------------------------------- | --------------------------------------- |
| **弓手死亡触发优势** | `if (dynamic_cast<const Archer*>(&character)) { ... }` | `if (character->type == ARCHER_TYPE) { ... }`        | C++: 5行 vs C: 10+行                    |
| **角色互相攻击**     | `attacker->attack(*target);`                           | `attacker->attack(attacker, target);`                | C++: 1行 vs C: 1行（但需理解this传递）  |
| **观察者通知**       | `notifyDeath(*target);`                                | `battle_manager_notifyDeath(battleManager, target);` | C++: 1行 vs C: 1行（但C需要传递管理器） |

**关键差异**：  
C++中对象交互是**自然的语法**（`obj1.method(obj2)`），而C中必须**显式传递所有上下文**（`method(obj1, obj2, manager)`）。随着系统复杂度增加，C实现中需要传递的上下文参数会急剧膨胀。

 **3\. 扩展性与维护难度**

假设我们要添加新角色`Necromancer`：

C++实现：
```cpp
class Necromancer : public Character {
public:
    Necromancer(const std::string& n) 
        : Character(n, 90, 20) {}
    
    void attack(Character& target) override {
        std::cout << name << " drains life from " << target.getName() << "!\n";
        int damage = attackPower;
        target.takeDamage(damage);
        // 吸取生命值
        health = std::min(maxHealth, health + damage / 2);
    }
};
```

C实现：
```c
typedef struct {
    Character base;
    // Necromancer特有属性
} Necromancer;

void necromancer_attack(Character* attackerBase, Character* targetBase) {
    // 实现攻击逻辑
}

Necromancer* necromancer_new(const char* name) {
    Necromancer* this = (Necromancer*)malloc(sizeof(Necromancer));
    character_init(&this->base, NECROMANCER_TYPE, name, 90, 20);
    this->base.attack = necromancer_attack;
    return this;
}
```

**关键差异**：  

- C++：只需定义新类，自动融入现有系统
- C：必须：
  1. 添加新类型枚举值
  2. 定义新结构体
  3. 实现所有方法
  4. 手动设置函数指针
  5. 可能需要修改类型检查逻辑（如`battle_manager_notifyDeath`中的弓手特殊处理）

**4\. 调试体验对比**

**C++调试**：
- 可以直接在`Character::attack`设置断点，GDB会自动停在实际调用的派生类方法
- 对象状态清晰可见（`this`指针自动解析为正确类型）
- 多态调用栈清晰显示实际执行路径

**C调试**：
- 需要在每个具体实现（`warrior_attack`, `mage_attack`）设置断点
- 调试器无法自动识别对象类型，需手动检查`type`字段
- 函数指针调用在调用栈中显示为`((func*)(...))()`，难以阅读

---

#### 为什么C++程序"不可捉摸"？——通过此例的总结

1. **多态隐藏了执行路径**  
   - C++：`attacker->attack(*target)` 可能执行4种不同方法（战士/法师/弓手/新角色）
   - C：`attacker->attack(attacker, target)` 虽然也是函数指针，但必须手动设置，路径更明显

2. **对象关系网取代了过程流**  
   - C++：`BattleManager`持有`Character*`数组，但不直接操作它们——只是触发交互
   - C：`BattleManager`必须显式管理所有对象和函数指针关系

3. **状态分散在对象内部**  
   - C++：`rage`、`mana`、`hasAdvantage`封装在各自对象中，无法直接访问
   - C：虽然也封装，但必须通过结构体成员访问，暴露了实现细节

4. **扩展点无处不在**  
   - C++：任何`Character`派生类都可以加入战斗，无需修改`BattleManager`
   - C：添加新角色需要修改多处类型检查代码

---

#### 如何理解C++的"不可捉摸"？——实用建议

1. **关注接口而非实现**  
   - 不要问"attack()具体做了什么"，而要问"attack()保证了什么"
   - 例如：`attack()`保证会调用`target.takeDamage()`，但具体伤害值由角色类型决定

2. **绘制对象关系图**  
   ```
   [Warrior] -->|is-a| [Character]
   [Mage] -->|is-a| [Character]
   [Archer] -->|is-a| [Character]
   [BattleManager] -->|manages| [Character*]
   [BattleManager] -->|notifies| [BattleObserver]
   ```

3. **使用调试技巧**  
   - 在基类虚函数设置断点（GDB会停在实际派生类实现）
   - 使用`print *this`查看当前对象完整状态
   - 在关键方法添加日志：`std::cout << "[DEBUG] " << __PRETTY_FUNCTION__ << "\n";`

4. **理解多态的"运行时绑定"**  
   
   - 编译时：`attacker->attack()` 知道是`Character::attack`接口
   - 运行时：通过虚表找到实际`Warrior::attack`或`Mage::attack`
   
5. **接受"设计时确定，运行时选择"**  
   - 设计时：确定`Character`必须有`attack`方法
   - 运行时：根据对象实际类型选择具体实现
   - 这不是混乱，而是**将变化局部化**的设计智慧


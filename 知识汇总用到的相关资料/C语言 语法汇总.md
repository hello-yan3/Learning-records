# 目录
[TOC]



## 主体参照：[C 语言教程 | 菜鸟教程](https://www.runoob.com/cprogramming/c-tutorial.html) 这里对该教程做一定的完善与汇总

### 1. [C 简介](https://www.runoob.com/cprogramming/c-intro.html)
包括C的历史，优势，迭代等等；



### 2. [C环境设置](https://www.runoob.com/cprogramming/c-environment-setup.html)
直接看[VSCode 配置C/C++，单文件多文件](https://www.bilibili.com/video/BV1YL411L7Sg?p=6)
文档参考：[VSCode安装配置讲解文档](.\知识汇总用到的相关资料\VSCode安装配置讲解文档.md)

一些为什么使用GCC，等等，可以参考下[C环境设置](https://www.runoob.com/cprogramming/c-environment-setup.html)

**补充：**gcc 进行 c 语言编译分为四个步骤：

> 1. **预处理**，生成预编译文件（.i 文件）：预处理阶段主要处理源代码中**的宏定义、条件编译和包含文件**。预处理器会替换宏定义、处理条件编译指令（如、等）并将包含的头文件插入到源代码中。预处理后的输出是一个扩展后的源代码文件，通常具有（C语言）或（C++）扩展名。
>    `gcc –E hello.c –o hello.i`
> 2. 编译，生成汇编代码（.s 文件）：编译阶段将预处理后的源代码文件**转换为汇编代码**。**编译器会检查源代码的语法**、语义是否正确，**进行各种优化**，并将源代码转换为目标平台的汇编指令。编译后的输出是一个汇编代码文件，通常具有扩展名。
>     `gcc –S hello.i –o hello.s`
> 3. 汇编，生成目标文件（.o 文件）：汇编阶段**将汇编代码文件转换为目标代码（机器码）**。汇编器会将汇编指令翻译为目标平台的机器指令，并生成一个目标文件。目标文件包含了程序的机器码、符号信息和其他元数据。汇编后的输出是一个目标文件，通常具有（Linux）或（Windows）扩展名。
>     `gcc –c hello.s –o hello.o`
> 4. 链接，生成可执行文件：**链接阶段将一个或多个目标文件和库文件组合成一个可执行文件或库文件**。链接器会解析符号引用，将它们与正确的地址和实现关联，并处理程序中使用的库函数。链接器还负责组织程序的内存布局，如代码段、数据段等。链接后的输出是一个可执行文件，通常具有无扩展名（Linux）或（Windows）扩展名。
>     `gcc hello.o –o hello`



### 3. [C最基本格式](https://www.runoob.com/cprogramming/c-tutorial.html)

```C
#include <stdio.h>
 
int main()
{
    /* 我的第一个 C 程序 */
    printf("Hello, World! \n");
 
    return 0;
}
```

**注：** `main` 函数的返回值返回给主调进程，一般约定返回 0 值时代表程序运行无错误，其它值均为错误；
`void main` 可以不写`return`或者是 `return;`，在**检查不**是很**严格**的**编译器**(VC,  VS)中，`void main` 是**允许**的。在**检查严格**的**编译器**下(gcc,  g++)， 要求 `main` 函数的返回值**必须为 `int` 型**。
现在已很少使用 `void main`;

**注：**`int main(void)` 指的是此函数的参数为空，不能传入参数；`int main()`表示 是否接受参数保持沉默；

**补充1：**[**评论笔记2，3**](https://www.runoob.com/cprogramming/c-program-structure.html)给出了**DOS 窗口自动关闭**的两种解决方法：
**解决方法1：**

> 加入头文件 `#include <stdlib.h>` 
> 在 **`return 0;`** 前加入 **`system("pause");`** 语句

**解决方法2：**详见**[评论笔记2，3](https://www.runoob.com/cprogramming/c-program-structure.html)**

**补充2：**  `int main(int argc, char *argv[]) {}`
参照：**[C 命令行参数](https://www.runoob.com/cprogramming/c-command-line-arguments.html)**，**[评论笔记1](https://www.runoob.com/cprogramming/c-tutorial.html)**，[**评论笔记3**](https://www.runoob.com/cprogramming/c-functions.html)
命令行参数是使用 main() 函数参数来处理的，其中，**argc** 是指传入参数的个数，**argv[]** 是一个字符串数组， 下标从 **0** 开始，第一个存放的是可执行程序的文件名字，然后依次存放传入的参数；



### 4. [C 基本语法](https://www.runoob.com/cprogramming/c-basic-syntax.html)

#### 4.1 C 的语句组成

#### 4.2 C 的`;` 
表明一个逻辑实体的结束

#### 4.3 C 的注释
```C
// 单行注释
/*多行注释*/
```

**注：不能在注释内嵌套注释，注释也不能出现在字符串或字符值中**



### 5. [C 头文件](https://www.runoob.com/cprogramming/c-header-files.html)

头文件是扩展名为 **.h** 的文件，引用头文件相当于复制头文件的内容，
建议把**所有的常量、宏、系统全局变量和函数原型**写在头文件中，在需要的时候随时引用这些头文件。

#### 5.1 引用头文件的语法

`#include <file>`  ：引用系统头文件，找不到时报错；
`#include "file"`  ：引用用户头文件，找不到时进入系统头文件中寻找，还找不到报错；

#### 5.2 只引用一次头文件 (防止重复引用头文件)

```C
#ifndef HEADER_FILE
#define HEADER_FILE

#endif
```

#### 5.3 有条件引用 (防止重复引用头文件)

从多个不同的头文件中选择一个引用到程序方法

```c
 #define SYSTEM_H "system_1.h"
 ...
 #include SYSTEM_H
```

#### 5.4 多个 .h 文件和多个 .c 文件处理方法 （评论笔记1）

用一个 **`global.h`** 的头文件来包括所有的 **`.h`** 文件



### 6. [C 预处理器](https://www.runoob.com/cprogramming/c-preprocessors.html)

#### 6.1 预处理器

C 预处理器是一个**文本替换工具**，它会指示**编译器在实际编译之前完成所需的预处理**

| 指令     | 描述                                                        |
| :------- | :---------------------------------------------------------- |
| #define  | 定义宏                                                      |
| #include | 包含一个源代码文件                                          |
| #undef   | 取消已定义的宏                                              |
| #ifdef   | 如果宏已经定义，则返回真                                    |
| #ifndef  | 如果宏没有定义，则返回真                                    |
| #if      | 如果给定条件为真，则编译下面代码                            |
| #else    | #if 的替代方案                                              |
| #elif    | 如果前面的 #if 给定条件不为真，当前条件为真，则编译下面代码 |
| #endif   | 结束一个 #if……#else 条件编译块                              |
| #error   | 当遇到标准错误时，输出错误消息                              |
| #pragma  | 使用标准化方法，向编译器发布特殊的命令到编译器中            |


#### 6.2 预定义宏

| 宏              | 描述                                                         |
| :-------------- | :----------------------------------------------------------- |
| \_\_DATE\_\_    | <stdio.h>、当前日期，一个以 "month/day/year " 格式表示的字符常量。如：Feb 28 2011 |
| \_\_TIME\_\_    | <stdio.h>、当前时间，一个以 "hour:minute:second" 格式表示的字符常量。如：18:52:48 |
| \_\_FILE\_\_    | <stdio.h>、这会包含当前文件名，一个字符串常量。如：test.cpp  |
| \_\_LINE\_\_    | <stdio.h>、这会包含当前行号，一个十进制常量。如：15          |
| \_\_STDC\_\_    | <stdio.h>、当编译器以 ANSI 标准编译时，则定义为 1。          |
| \_\_INT_MAX\_\_ | <limits.h>、0x7FFFFFFF、2^31-1 ，即 2147483647               |
| _\_INT_MIN\_\_  | <limits.h>、0x8000000、-2^31 ，即 -2147483648                |

使用方法为直接输出：  `print("%s、%d",__DATE__,__LINE__)`;



### 6.3 [`#define` 的多种使用方法](https://www.runoob.com/cprogramming/c-preprocessors.html)
参照：**[define用法完全集锦](.\define用法完全集锦.doc)、[C/C++ 预处理器](https://www.runoob.com/cplusplus/cpp-preprocessor.html)**

`#define`的作用是在**预编译时进行字符替换**，如`#define A B`，预编译时会将程序中所有出现A的地方替换为B；注意`#define`**作用域为全局**，不受定义域限制，在函数内定义的宏可以在函数外使用；不使用时可以用**`#undef`**使之前的宏定义失效。

#### 6.3.1 `#define`的运算符号

1\) **宏延续运算符 `\`**    如果宏太长，一个单行容纳不下，则使用宏延续运算符 `\` ，注意`\`后不可加任何东西，包括空格
2\) 字符串常量化运算符 `#`    把一个宏的参数转换为字符串常量时，则使用字符串常量化运算符

```C
#define STR( x )   #x
printf( STR(HELLO WORLD) );      // 等价于：printf( "HELLO WORLD" );

#define  message_for(a, b)  \
	printf(#a " and " #b ": We love you!\n")    
message_for(Carole, Debra);      // 等价于：printf("Carole" " and " "Debra" ": We love you!\n");
```

3\) 标记粘贴运算符 `##`    合并两个参数，将两个独立的标记被合并为一个标记

```c
#define concat(a, b)    a ## b
int xy = 100;
printf( "%d\n", concat(x, y));   // 等价于：printf( "%d\n", xy );

#define tokenpaster(n) printf ("token" #n " = %d", token##n)
int token34 = 40;
tokenpaster(34);  // 等价于 printf ("token34 = %d", token34);  输出： token34 = 40

#define TYPE(class,num) class##num
int class105 = 100;
printf("%d", TYPE(class, 105));    // 等价于 printf ("%d", class105); 
```

4\) `defined()` 运算符   确定一个标识符是否已经使用 `#define` 定义过

```c
#if !defined (MESSAGE)
   #define MESSAGE "You wish!"
#endif
```

#### 6.3.2 `#define`的参数化

参照：**[define用法完全集锦](.\知识汇总用到的相关资料\define用法完全集锦.doc)**

如何使用 `#define` 实现一些简单函数 ，详见：[**评论笔记15**](https://www.runoob.com/cprogramming/c-functions.html)
如：`#define  square(x)  ((x) * (x))`  ;  `#define MAX(x,y) ((x) > (y) ? (x) : (y))` ；
        `#define SWAP1(x,y) {x=x+y;y=x-y;x=x-y;}`  ;  `#define  ARR_SIZE(a)  (sizeof(a) / sizeof(a[0]))`
**注意：参数括号很重要，省略括号会导致运算错误**
**详见：[C预处理 评论笔记1](https://www.runoob.com/cprogramming/c-preprocessors.html)、[C常量 评论笔记4、9](https://www.runoob.com/cprogramming/c-constants.html)**



### 7. [C 输入&输出](https://www.runoob.com/cprogramming/c-input-output.html)
**标准输入输出文件：**标准输入：`stdin`；  标准输出：`stdout`；

#### 7.1 scanf() 和 printf() 函数
**输入：**
`int scanf(const char *format, ...)` ：从标准输入流 **stdin** 读取输入，并根据提供的 **format** 来浏览输入，返回值为接收到的输入变量个数；

输入格式`%d` 按照空格、tab 键、回车键分隔，如果使用 `,` 来分隔输入的` %d` 相应的输入时也需要添加` ,`，注意使用`,`紧跟数字后面不能有空格；
如：`int a, b, c;       scanf("%d,%d,%d", &a, &b, &c);`，输入：`1,2,3` 
        `int a, b, c;       scanf("%d %d %d", &a, &b, &c);`，输入：`1 2 3` 
	PS：`scanf("%d%d%d", &a, &b, &c);`和`scanf("%d %d %d", &a, &b, &c);`一样，都是使用`空格`区分，不能使用`,`逗号；

在用 `%c` 输入时，空格和"转义字符"均作为有效字符，所以什么都不能加
如：`char a, b, c;      scanf("%c %c %c", &a, &b, &c);`，输入：`abc` 

输入字符串，`%s`，注意遇到“空格”、“Tab”、“回车”都算结束；注意输出不需要取地址`&`；
如：`char str[100];     scanf("%s", str);  `

**注意：**如果需要将`空格`也作为字符串输入，使用`gets(str);`函数；

实例见正文，**评论笔记4、7**，**[C 库函数 – scanf() | 菜鸟教程 (runoob.com)](https://www.runoob.com/cprogramming/c-function-scanf.html)**

**输出：**
`int printf(const char *format, ...) `：把输出写入到标准输出流 **stdout** ，并根据提供的 **format** 产生输出；
返回值是接收到值的变量个数，详见**评论笔记7**，**[C 库函数 – printf() | 菜鸟教程 (runoob.com)](https://www.runoob.com/cprogramming/c-function-printf.html)**

**补充：sprintf() 函数**，sprintf函数打印到字符串中；
注意`buffer`需要定义够大，以防止内存溢出，`printf()`的占位符`sprintf()`均可使用。
`int sprintf(char *buffer, const char *format, ...);`

```C
char buffer[50];
int num = 123;
const char *str = "Hello";
// 使用sprintf将整数和字符串组合
sprintf(buffer, "%s, the number is %d", str, num);
printf("%s\n", buffer);			// Hello, the number is 123
```

#### 7.2 输入输出的占位符：
先占住一个固定的位置，之后再往里面添加内容的符号；
格式占位符(%)是在C/C++语言中格式输入/输出函数，如 scanf、printf 等函数中使用。其意义就是起到格式占位的意思，表示在该位置有输入或者输出。

- **%d, %i** 代表有符号整数型

- **%ld** long   有符号型

- **%lld** long long   有符号型

- **%f** 浮点   **%f** float 默认是 6 位小数输出；可以在 %f 中控制；详见**评论笔记5**
&nbsp;           例如：`%.2f`：输出两位小数，`%m.nf`：输出的数据占 m 列，n位小数，不足左补0，`%-m.nf`，与`%m.nf`类似，不足右补0；

- **%lf** 浮点   对应于`double`类型
  
- **%s** 字符串   注意输出不加 `&` 取地址符号
&nbsp; 	 	 `%m.ns`：输出的字符串占 m 列，仅输出前n位；

- **%c** char   详见**评论笔记4**

- **%p** 指针   输出的是地址值

- **%u** 无符号十进制整数，默认都是有符号

- **%lu** long   无符号型

- **%llu** long long   无符号型

- **%e** 科学计数

- **%g** 小数或科学计数

- **%o** 八进制整数  以 **0** 开头的数字，注意不会输出 0

- **%x** 十六进制整数  以 **0x** 开头的数字，注意不会输出0x
     注：%x：输出小写字母，如：0xff，%X：输出大写字母，如：0XFF
     &nbsp;       %02X：02表示不足2位，前面补0输出；如果超过2位，则实际输出；%03x，04x同理；

- **%%** %字符

  二进制的输出没有占位符
  
  更多输入输出占位符见：**[C 库函数 – scanf()](https://www.runoob.com/cprogramming/c-function-scanf.html)** , **[C 库函数 – printf()](https://www.runoob.com/cprogramming/c-function-printf.html)**
  
- 补充：C语言没有直接输出二进制方法，一般通过数组+循环得到
  ```C
  void print_binary(int num) {
      for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
          printf("%d", (num >> i) & 1);
      }
      printf("\n");
  }
  // 但是可以直接使用 0b××××  输入二进制数字
  ```

  

#### 7.3 getchar() & putchar() 函数
`int getchar(void)` 函数从屏幕读取下一个可用的字符，并把它返回为一个整数
`int putchar(int c)` 函数把字符输出到屏幕上，并返回相同的字符

#### 7.4 gets() & puts() 函数 | fgets() & fputs() 函数
`char *gets(char *s)` 函数从 **`stdin`** 读取一行到 **`s`** 所指向的缓冲区，直到一个终止符或 EOF。
`int puts(const char *s)` 函数把字符串 **`s`** 和一个尾随的换行符写入到 **`stdout`**。
使用gets() & puts() 函数 会产生警告，建议使用fgets() & fputs() 函数。 

`char *fgets(char *s, int n, stdin)` **`s`**需提前声明数组大小维度**`n=sizeof(s)`**，函数从 **`stdin`** 读取一行到 **`s`** 所指向的缓冲区，直到一个终止符或 EOF。
`int fputs(const char *s, stdout)` **`s`**需提前声明数组大小，函数把字符串 **`s`** 和一个尾随的换行符写入到 **`stdout`**。

注意：linux 不支持 gets 与 puts, 需要用 fgets 和 fputs；详见[**评论笔记1、2、9**](https://www.runoob.com/cprogramming/c-input-output.html)

```C
// 使用 gets 读取输入
printf("Using gets: ");
gets(buffer1);
printf("You entered: %s\n", buffer1);

// 使用 fgets 读取输入
printf("Using fgets: ");
fgets(buffer2, sizeof(buffer2), stdin);
printf("You entered: %s\n", buffer2);
```



### 8. [C的数据类型](https://www.runoob.com/cprogramming/c-data-types.html)

### 8.1. [数据基本类型](https://www.runoob.com/cprogramming/c-data-types.html)

#### 8.1.1 基本类型——整数类型

| 类型                   | 存储大小                  | 值范围                                                  |
| :--------------------- | :------------------------ | :------------------------------------------------------ |
| char                   | 1 字节                    | -128 到 127 或 0 到 255                                 |
| unsigned char          | 1 字节                    | 0 到 255                                                |
| signed char            | 1 字节                    | -128 到 127                                             |
| unsigned short int     | 2 字节                    | 0 到 65,535                                             |
| signed short int       | 2 字节                    | -32,768 到 32,767                                       |
| short int              | 2 字节                    | -32,768 到 32,767                                       |
| int                    | 2 (16位) 或 4 (32位) 字节 | -32,768 到 32,767 或 -2,147,483,648 到 2,147,483,647    |
| unsigned int           | 2 (16位) 或 4 (32位) 字节 | 0 到 65,535 或 0 到 4,294,967,295                       |
| signed int             | 2 (16位) 或 4 (32位) 字节 | -32,768 到 32,767 或 -2,147,483,648 到 2,147,483,647    |
| long int               | 4 字节                    | -2,147,483,648 到 2,147,483,647                         |
| unsigned long int      | 4 字节                    | 0 到 4,294,967,295                                      |
| signed long int        | 4 字节                    | -2,147,483,648 到 2,147,483,647                         |
| long long int          | 8 字节                    | -9,223,372,036,854,775,808 到 9,223,372,036,854,775,807 |
| unsigned long long int | 8 字节                    | 0 到 18,446,744,073,709,551,615                         |
| signed long long int   | 8 字节                    | -9,223,372,036,854,775,808 到 9,223,372,036,854,775,807 |

**注：**允许使用速记符号来声明**无符号短整数**或**无符号长整数**；即可以不写`int`，只写单词 `unsigned`、`short` 或 `long`；

使用 **`sizeof`** 运算符，表达式 **`sizeof(type)`** 得到对象或类型的存储字节大小， **`sizeof`** 返回值为**`size_t`**类型，**`size_t`** 近似于**无符号整型**；如果是**WIN32**系统，**`size_t`与`uint32_t`相同**；如果是**WIN64**系统，**`size_t`与`uint64_t`**相同；
详见：[**评论笔记1、2、7**](https://www.runoob.com/cprogramming/c-fun-pointer-callback.html)

**补充：**考虑到不同平台差异；常使用：`int_8`，`int_16`，`int_32`，`int_64`，`uint_8`，`uint_16`，`uint_32`，`uint_64`等作为代替。
注意使用前需要引用`#include<stdint.h>`头文件

#### 8.1.2 基本类型——浮点类型

| 类型                                                         | 存储大小 | 值范围                 | 精度      |
| :----------------------------------------------------------- | :------- | :--------------------- | :-------- |
| **[float](https://blog.csdn.net/albertsh/article/details/92385277)** | 4 字节   | 1.2E-38 到 3.4E+38     | 6 位小数  |
| double                                                       | 8 字节   | 2.3E-308 到 1.7E+308   | 15 位小数 |
| long double                                                  | 16 字节  | 3.4E-4932 到 1.1E+4932 | 19 位小数 |

#### 8.1.3 基本类型——数据格式  ([评论笔记1](https://www.runoob.com/cprogramming/c-data-types.html)，[C 常量](https://www.runoob.com/cprogramming/c-constants.html))

**整数 前缀**
1\. 默认为10进制 ，10 ，20；
2\. 以0开头为8进制，045，021；
3\. 以0b (0B) 开头为2进制，0b11101101；
4\. 以0x (0X) 开头为16进制，0x21458adf；
**整数 后缀**
1\. 后缀u (U)表示无符号整数（unsigned）；
2\. 后缀l (L) 表示长整数（long）；
3\. 后缀L和U可大写可小写，U 和 L 的顺序任意；

**浮点数 表示方法**
小数形式：包含整数部分、小数部分，如：`3.1415`
指数形式：包含小数点、指数部分，指数部分使用e (E) 引入，如：`3.1415e5`
**浮点数 后缀**
单精度常量：2.3f ；
双精度常量：2.3，默认为双精度；
其他见： [**评论笔记7**](https://www.runoob.com/cprogramming/c-constants.html)

**字符型常量**
用英文单引号括起来
普通字符，如：`'a'`、`'b'` 、`'*'`
转义字符：

| 转义序列   | 含义                                                         |
| :--------- | :----------------------------------------------------------- |
| \\         | \ 字符                                                       |
| \'         | ' 字符                                                       |
| \"         | " 字符                                                       |
| \?         | ? 字符                                                       |
| \a         | 警报铃声                                                     |
| \b         | 退格键                                                       |
| \f         | 换页符                                                       |
| \n         | 换行符                                                       |
| \r         | 回车                                                         |
| \t         | 水平制表符                                                   |
| \v         | 垂直制表符                                                   |
| \ooo       | 一到三位的八进制数   [**评论笔记2**](https://www.runoob.com/cprogramming/c-constants.html) |
| \xhh . . . | 一个或多个数字的十六进制数   [**评论笔记2**](https://www.runoob.com/cprogramming/c-constants.html) |

**注：**字符'0' 和数字 0 不同，字符使用[**ASCLL码**](http://c.biancheng.net/c/ascii/)表示，
**如：**字符'0'，代表数字48；字符'空格'，代表数字32；字符'回车'，代表数字13；字符'\0'，代表数字0（'\0'字符表示什么都没有）；
**强制转换时 (char → int)：**字符'0'，强制转换为数字 48；字符 ' '，强制转换为 数字32；等等

**字符串常量**
用英文的双引号引起来 可以保存多个字符："abc"。
字符串换行使用：`\`，注意字符串换行，`\`后**不能有空格**，且下一行前**不能有空格或者Tab键，否则会被视为字符串一并输出；**

#### 8.1.4 [数据基本类型的转换](https://www.runoob.com/cprogramming/c-type-casting.html)、[数据类型评论笔记2](https://www.runoob.com/cprogramming/c-data-types.html)

**1\. 显示转换 (强制转换)**
**强制类型转换运算符**：`(type_name) (expression)` ，expression表达式括号可以不要；
如：

```c
int sum = 17, count = 5;
mean = (double) sum / count;                 // 等价于(double) (sum)
printf("Value of mean : %f\n", mean );       // 输出：Value of mean : 3.400000

int int_num = 5;
float float_num = 3.14;

// 强制将浮点数转换为整数
int_num = (int)float_num;        // int_num = 3
// 强制将整数转换为浮点数
float_num = (float)int_num;      // float_num = 3.000000

/* 浮点数原码转换(转换后保证原码不变) */
float f = 3.14;
int *ptr = (int *)&f;
int num = *ptr;         // num = 1078523331
```
**注意：**强制类型转换运算符的优先级**大于**加减乘除；

**2\. 隐示转换**
C 语言中如果一个表达式中含有不同类型的常量和变量，在计算时，会将它们自动转换为同一种类型；
**自动转换顺序：**
![数据优先级](https://www.runoob.com/wp-content/uploads/2014/09/img1.png)
**自动转换规则：**

> 1、若参与运算量的类型不同，则先转换成同一类型，然后进行运算。
> 2、转换按数据长度增加的方向进行，以保证精度不降低。如int型和long型运算时，先把int量转成long型后再进行运算。   a、若两种类型的字节数不同，转换成字节数高的类型   b、若两种类型的字节数相同，且一种有符号，一种无符号，则转换成无符号类型
> 3、所有的浮点运算都是以双精度进行的，即使仅含float单精度量运算的表达式，也要先转换成double型，再作运算。
> 4、char型和short型参与运算时，必须先转换成int型。
> 5、在赋值运算中，赋值号两边量的数据类型不同时，赋值号右边量的类型将转换为左边量的类型。如果右边量的数据类型长度比左边长时，将丢失一部分数据，这样会降低精度:

**实例：**

```C
int i = -5;
unsigned int ii = 1;
printf("%d\n",i>ii);     //输出1，非常有趣的结果 原因是int型的i转换为unsigned int型
// cout<<(i>ii)<<endl;   //输出1，非常有趣的结果 原因是int型的i转换为unsigned int型
int i = -5;
unsigned short ii = 1;
printf("%d\n",i>ii);     //输出0 比较时short和unsigned short都提升为int型
// cout<<(i>ii)<<endl;   //输出0 比较时short和unsigned short都提升为int型
```

补充：`unsighed` 和 `sighed` 的相互转换，采用`N±2^n`计算方法。`n `取决于数据类型，`N `为无符号数的数值
举例：unsighed short a = 50000;  short(50000) = 50000 - 2^16 = -15536; 
&nbsp;          short a = -15536;  unsighed short(-15536) = -15536 + 2^16 = 50000;
&nbsp;          50000 和 -15536 的二级制源代码相同，均为 11000011 01010000 ；详细原理见**12.1.2 补码**

举例：[**评论笔记2**](https://www.runoob.com/cprogramming/c-data-types.html)、[**评论笔记1**](https://www.runoob.com/cplusplus/cpp-variable-types.html)



#### 8.2 void 类型 

void 类型指定没有可用的值，包括：函数返回为空、函数参数为空、指针指向 void；

#### 8.3 其他类型
包括：**枚举类型，指针类型，数组类型，结构类型，共用类型，函数类型；**后面对每种类型详述；



### 9. [C 常量](https://www.runoob.com/cprogramming/c-constants.html)

**常量**就像是常规的变量，只不过常量的值在定义后不能进行修改。

#### 9.1 整数常量、浮点常量、字符常量、字符串常量 见 8.1.3 基本类型——数据格式

#### 9.2 定义常量 （评论笔记1、3、8）

1\. **`#define`** 预处理器：预编译时进行字符替换；如：`#define var 5`，后续的 `var` 在系统编译时，均替换为 5；详见6.3节；
2\. **`const`** 关键字：改变一个变量的存储类，把该变量所占的内存变为只读；如：`const int var = 5;`  其性质除不可修改外，其余均与变量相同；

PS：`int const var = 5;`也合法，但很少用。

**#define 与 const 区别**
**[评论笔记1、3、8](https://www.runoob.com/cprogramming/c-constants.html)、[评论笔记2](https://www.runoob.com/cplusplus/cpp-constants-literals.html)**

**补充：** **[`const`的其他用法](http://c.biancheng.net/view/2041.html)**



### 10. [C 变量](https://www.runoob.com/cprogramming/c-variables.html)

**变量**包括：char、int、float、double；枚举、指针、数组、结构、共用体等等；

#### 10.1 C变量定义方法：

变量定义：`type variable_list;`
变量定义时被初始化：`type variable_list = value;`

变量命名注意事项：[**评论笔记3——标识符命名规则**](https://www.runoob.com/cprogramming/c-basic-syntax.html)
标识符规则：

> 1\. 标识符由字母(26字母+$标识符)、数字、下划线组成，并且首字母不能是数字。
> 2\. 不能把C的关键字作为用户的标识符，例如：if、for、while等，[**32个关键字详见正文及评论笔记3**](https://www.runoob.com/cprogramming/c-basic-syntax.html)。（注：标识符不能和C语言的关键字相同，也不能和用户自定义的函数或C语言库函数同名）
> 3\. 标识符长度是由机器上的编译系统决定的（C89标准 标识符长度 8字符；C99标准 内部标识符长度 63字符、外部标识符长度 31字符；现在编译器支持的标识符长度还要更长。）
> 4\. 标识符对大小写敏感，即严格区分大小写。**一般对变量名用小写，符号常量命名用大写**。（注：C语言中字母是区分大小写的，因此score、Score、SCORE分别代表三个不同的标识符）
> 5\. **标识符命名应做到"见名知意"**，例如，长度（外语：length），求和、总计（外语：sum），圆周率（外语：pi）

**注意：C89 要求变量必须定义在开头，但 C99 支持随处定义变量**

#### 10.2 C变量声明方法：

参照 `extern` 使用方法

#### 10.3 C 中的左值（Lvalues）和右值（Rvalues）

1\. **左值（lvalue）：**指向内存位置的表达式被称为左值（lvalue）表达式。左值可以出现在赋值号的左边或右边。
2\. **右值（rvalue）：**术语右值（rvalue）指的是存储在内存中某些地址的数值。右值只能出现在赋值号的右边。

更多见：[**评论笔记2、4**](https://www.runoob.com/cprogramming/c-variables.html)

#### 10.4 C中的变量类型限定符

| 限定符               | 含义                                                         |
| :------------------- | :----------------------------------------------------------- |
| **const**            | **const** 类型的对象在程序执行期间不能被修改改变。           |
| **volatile**         | 对于一般的变量编译器会对变量进行优化，将内存中的变量值放在寄存器中以加快读写效率。<br />修饰符 **volatile** 用于表示一个变量可能会被多个线程或外部事件（如硬件中断）以不可预测的方式访问和修改。    关键字的作用是提醒编译器**不要对该变量进行任何优化**，确保每次**访问该变量时都从内存中读取**，每次修改该变量时都将数据写回内存。<br />**关键字的主要作用：**<br />* 防止编译器优化：避免编译器将变量值存储在寄存器中而不是内存中，避免编译器对多次访问变量的代码进行优化 <br />* 确保内存访问顺序：确保在多线程或中断环境下，变量的访问顺序与代码中的顺序一致<br />* 用于内存映射硬件寄存器：在嵌入式系统开发中，关键字常用于表示内存映射的硬件寄存器。由于硬件寄存器的值可能在任何时候发生变化（例如，由硬件事件触发），使用关键字可以确保编译器生成正确的访问代码。<br />更多方法见**[C/C++ 中 volatile 关键字详解 ](https://www.runoob.com/w3cnote/c-volatile-keyword.html)**<br /><br />**更新(简单说法)：**volatile定义变量，一般为全局变量；三个使用场景：硬件寄存器访问、多线程共享变量、中断服务程序（ISR）中的变量(典型:中断标志位`interrupt_flag`)； |
| **restrict**         | 由 **restrict** 修饰的指针是唯一一种访问它所指向的对象的方式。只有 C99 增加了新的类型限定符 restrict。 |
| **explicit (仅C++)** | 阻止不应该允许的经过转换构造函数进行的隐式转换的发生         |

#### 10.5 大小端存储

大小端是指在多字节的数据类型（例如整型、浮点型等）在内存中的存储方式。**大端指高位字节存储在低地址**，低位字节存储在高地址；**小端**则相反，**低位字节存储在低地址**，高位字节存储在高地址。
嵌入式领域 (STM32) 小端应用较多，windows,linux,高大上的嵌入式CPU大多是大端模式；
整型int`0x12345678`，转换为char，小端：0x78，大端：0x12

```C
// 代码判断大小端
#include <stdio.h>

int main()
{
    unsigned int x = 0x12345678;
    char *c = (char*) &x;
    if (*c == 0x78)
        printf("小端存储\n");
    else
        printf("大端存储\n");
    return 0;
}

// 大小端转化
void swap_endian(int *p)
{
    char *p1 = (char*)p;
    char *p2 = p1 + sizeof(int) - 1;
    char tmp;
    while (p2 > p1) 
    {
        tmp = *p1;
        *p1++ = *p2;
        *p2-- = tmp;
    }
}
```



### 11. [C 运算符](https://www.runoob.com/cprogramming/c-operators.html)

#### 11.1 算数运算符

假设 A = 10；B = 21;

| 运算符 | 描述                             | 实例                                                         |
| :----- | :------------------------------- | :----------------------------------------------------------- |
| +      | 把两个操作数相加                 | A + B 将得到 31                                              |
| -      | 从第一个操作数中减去第二个操作数 | A - B 将得到 -11                                             |
| *      | 把两个操作数相乘                 | A * B 将得到 210                                             |
| /      | 分子除以分母                     | B , A 均为 int，B / A 将得到 2<br />B , A 为 float，B / A 将得到 2.1 |
| %      | 取模运算符，整除后的余数         | B % A 将得到 1                                               |
| ++     | 自增运算符，整数值增加 1         | A++ 将得到 11                                                |
| --     | 自减运算符，整数值减少 1         | A-- 将得到 9                                                 |

**注意：**
**1. a++ 与 ++a 的区别：**

```C
c = a++;     // 先赋值：c = a；后运算：a=a+1；
c = ++a;     // 先运算：a=a+1；后赋值：c = a；
```
**2. `%` 注意事项**
2.1 `%` 仅适用于整数相除
2.2 `%` 结果正负仅与左边相关，与右边无关；见**评论笔记3**

#### 11.2 关系运算符

假设 A = 10；B = 21;

| 运算符 | 描述                                                         | 实例            |
| :----- | :----------------------------------------------------------- | :-------------- |
| ==     | 检查两个操作数的值是否相等，如果相等则条件为真。             | (A == B) 为假。 |
| !=     | 检查两个操作数的值是否相等，如果不相等则条件为真。           | (A != B) 为真。 |
| >      | 检查左操作数的值是否大于右操作数的值，如果是则条件为真。     | (A > B) 为假。  |
| <      | 检查左操作数的值是否小于右操作数的值，如果是则条件为真。     | (A < B) 为真。  |
| >=     | 检查左操作数的值是否大于或等于右操作数的值，如果是则条件为真。 | (A >= B) 为假。 |
| <=     | 检查左操作数的值是否小于或等于右操作数的值，如果是则条件为真。 | (A <= B) 为真。 |

#### 11.3 逻辑运算符

假设 A = 1；B = 0;

| 运算符 | 描述                                                         | 实例              |
| :----- | :----------------------------------------------------------- | :---------------- |
| &&     | 称为逻辑与运算符。如果两个操作数都非零，则条件为真。         | (A && B) 为假。   |
| \|\|   | 称为逻辑或运算符。如果两个操作数中有任意一个非零，则条件为真。 | (A \|\| B) 为真。 |
| !      | 称为逻辑非运算符。用来逆转操作数的逻辑状态。如果条件为真则逻辑非运算符将使其为假。 | !(A && B) 为真。  |

**注意：** 假设 `左值A`、`右值B` 为表达式；
&nbsp;          `&&`运算符，只要`左值A`表达式结果为假，立即返回 0，不进行`右值B`表达式运算；
同理，`||`运算符，只要`左值A`表达式结果为真，立即返回1，不进行`右值B`表达式运算；

#### 11.4 位运算符

位运算符作用于位，并逐位执行操作。
假设A = 60 (0011 1100B);  B = 13 (0000 1101B);

| 运算符 | 描述                                                         | 实例                                                         |
| :----- | :----------------------------------------------------------- | :----------------------------------------------------------- |
| &      | 按位与操作，按二进制位进行"与"运算。<br />运算规则：`0&0=0;  0&1=0;  1&0=0;  1&1=1;` | (A & B) 将得到 12，即为 0000 1100                            |
| \|     | 按位或运算符，按二进制位进行"或"运算。<br />运算规则：`0|0=0;  0|1=1;  1|0=1;  1|1=1;` | (A \| B) 将得到 61，即为 0011 1101                           |
| ^      | 异或运算符，按二进制位进行"异或"运算。<br />运算规则：`0^0=0;  0^1=1;  1^0=1;  1^1=0;` | (A ^ B) 将得到 49，即为 0011 0001                            |
| ~      | 取反运算符，按二进制位进行"取反"运算。<br />运算规则：`~1=-2;  ~0=-1;` | (~A ) 将得到 -61，即为 1100 0011，<br />一个有符号二进制数的补码形式。 |
| <<     | 二进制左移运算符。<br />将一个运算对象的各二进制位全部左移若干位<br />（左边的二进制位丢弃，右边补0）。 | A << 2 将得到 240，即为 1111 0000                            |
| >>     | 二进制右移运算符。<br />将一个数的各二进制位全部右移若干位，<br />正数左补0，负数左补1，右边丢弃。 | A >> 2 将得到 15，即为 0000 1111                             |

不同长度的数据进行位运算时，系统会将二者按右端对齐，然后进行位运算。详见**评论笔记5**
（1）如果整型数据为正数，左边补 16 个 0。
（2）如果整型数据为负数，左边补 16 个 1。

#### 11.5 赋值运算符

| 运算符 | 描述                                                         | 实例                            |
| :----- | :----------------------------------------------------------- | :------------------------------ |
| =      | 简单的赋值运算符，把右边操作数的值赋给左边操作数             | C = A + B 将把 A + B 的值赋给 C |
| +=     | 加且赋值运算符，把右边操作数加上左边操作数的结果赋值给左边操作数 | C += A 相当于 C = C + A         |
| -=     | 减且赋值运算符，把左边操作数减去右边操作数的结果赋值给左边操作数 | C -= A 相当于 C = C - A         |
| *=     | 乘且赋值运算符，把右边操作数乘以左边操作数的结果赋值给左边操作数 | C *= A 相当于 C = C * A         |
| /=     | 除且赋值运算符，把左边操作数除以右边操作数的结果赋值给左边操作数 | C /= A 相当于 C = C / A         |
| %=     | 求模且赋值运算符，求两个操作数的模赋值给左边操作数           | C %= A 相当于 C = C % A         |
| <<=    | 左移且赋值运算符                                             | C <<= 2 等同于 C = C << 2       |
| >>=    | 右移且赋值运算符                                             | C >>= 2 等同于 C = C >> 2       |
| &=     | 按位与且赋值运算符                                           | C &= 2 等同于 C = C & 2         |
| ^=     | 按位异或且赋值运算符                                         | C ^= 2 等同于 C = C ^ 2         |
| \|=    | 按位或且赋值运算符                                           | C \|= 2 等同于 C = C \| 2       |

#### 11.6 其他运算符

| 算符              | 描述                       | 实例                                 |
| :---------------- | :------------------------- | :----------------------------------- |
| sizeof()          | 返回变量的大小 (字节)      | sizeof(int) 将返回 4                 |
| ? :               | 条件表达式                 | 如果条件为真 ? 则值为 X : 否则值为 Y |
| &                 | 返回变量的地址             | &a; 将给出变量的实际地址。           |
| *                 | 指向一个变量               | *a; 将指向一个变量。                 |
| (type) expression | 强制转换运算符             | (int)21.2 = 21                       |
| . 和 ->           | 引用类、结构和共用体的成员 |                                      |
| ,                 | 用于分割一系列运算         |                                      |

#### 11.7  C 中的运算符优先级 (评论笔记8、10)

**[运算符优先级](https://baike.baidu.com/item/运算符优先级/4752611)**

> 括号成员是老大;           // 括号运算符 \[\]() ；成员运算符.  ->
> 全体单目排老二;           // 所有的单目运算符比如++、 --、 +(正)、 -(负) 、 !(逻辑非)、 ~(按位取反)、指针运算\*、&、(type)、sizeof()
> 乘除余三,加减四;         // 这个"余"是指取余运算即%
> 移位五，关系六;          // 移位运算符：<< >> ，关系：> < >= <= 等
> 等与不等排行七;          // 即 == 和 !=
> 位与异或和位或;          // 这几个都是位运算: 位与(&)异或(^)位或(|)    
> "三分天下"八九十;  
> 逻辑与，逻辑或;         // 逻辑运算符: || 和 &&
> 十一十二紧挨着;         // 注意顺序: 优先级(&&) 高于 优先级(||) 
> 条件只比赋值高,         // 三目运算符优先级排到 13 位只比赋值运算符和 "," 高
> 逗号运算最低级!         // 逗号运算符优先级最低 

此外，**单目**、条件、赋值 运算符为**从右到左**，其余均为从左到右。

**关于 *p++ 运算：**

```C
#include <stdio.h>

int main()
{
    // 测试*p++
    int a[5] = {1, 100, 200, 300};
    int *p = a;
    *p++ = 10;
    printf("*p: %d\n",*p);			// *p: 100
    printf("a[0]: %d\n",a[0]);		// a[0]: 10
    printf("a[1]: %d\n\n",a[1]);	// a[1]: 100

    // 测试*(p++）
    int b[5] = {1, 100, 200, 300};
    int *q = b;
    *(q++) = 10;
    printf("*q: %d\n",*q);			// *q: 100
    printf("b[0]: %d\n",b[0]);		// b[0]: 10
    printf("b[1]: %d\n\n",b[1]);	// b[1]: 100
    
    return 0;
}
```

**总结：** \*p++和\*(p++)没有区别，查阅资料得到正确的理解，应该理解为，**由于单目运算符从右到左运算**，后++优先级高于\*，应该先p++,后取值，但因为是后++,所以先执行\*p,然后等赋值完成以后，p再++。

```C
#include <stdio.h>

int main()
{
    // 测试*p++
    int a[5] = {1, 100, 200, 300};
    int *p = a;
    *p++;
    printf("*p: %d\n",*p);			// *p: 100
    printf("a[0]: %d\n",a[0]);		// a[0]: 1
    printf("a[1]: %d\n\n",a[1]);	// a[1]: 100

    // 测试*(p++）
    int b[5] = {1, 100, 200, 300};
    int *q = b;
    (*q)++;
    printf("*q: %d\n",*q);			// *q: 2
    printf("b[0]: %d\n",b[0]);		// b[0]: 2
    printf("b[1]: %d\n\n",b[1]);	// b[1]: 100
    
    return 0;
}
```

**总结：**（\*p）++，先取\*p,再使\*p这个值加1，p指针并没有移动




### 12. [C 存储类 (数据的存储) ](https://www.runoob.com/cprogramming/c-storage-classes.html)

存储类定义 C 程序中变量/函数的范围（可见性）和生命周期。
C 可用的存储类：`auto`、`register`、`static`、`extern`；

### 12.1.1 变量在内存中的地址 [评论笔记6](https://www.runoob.com/cprogramming/c-variables.html)

C语言经过编译之后将内存分为以下几个区域：

> 1）栈（stack）：由编译器进行管理，自动分配和释放，存放函数调用过程中的各种参数、局部变量、返回值以及函数返回地址。操作方式类似数据结构中的栈。
> 2）堆（heap）：用于程序动态申请分配和释放空间。C语言中的malloc和free，C++中的new和delete均是在堆中进行的。正常情况下，程序员申请的空间在使用结束后应该释放，若程序员没有释放空间，则程序结束时系统自动回收。注意：这里的“堆”并不是数据结构中的“堆”。
> 3）全局（静态）存储区：分为DATA段和BSS段。DATA段（全局初始化区）存放初始化的全局变量和静态变量；BSS段（全局未初始化区）存放未初始化的全局变量和静态变量。程序运行结束时自动释放。其中BBS段在程序执行之前会被系统自动清0，所以未初始化的全局变量和静态变量在程序执行之前已经为0。
> 4）文字常量区：存放常量字符串。程序结束后由系统释放。
> 5）程序代码区：存放程序的二进制代码。

堆与栈的区别：

> - **内存分配方式：**堆上的内存分配是动态的，可以在程序运行期间动态地分配和释放。程序员需要通过内存分配函数（如或）来分配堆内存，并在不再需要时使用释放函数（如或）进行回收。栈上的内存分配是静态的，编译器自动分配和回收。局部变量和函数调用时的参数通常存储在栈上。
>
> - **生命周期：**堆上的内存生命周期在分配内存后，一直持续到程序员显式释放它。这意味着在多个函数调用之间，堆上的数据可以一直保留。栈上的内存生命周期与函数的调用周期相关。函数返回时，分配在栈上的内存会自动被释放。
>
> - **碎片化问题：**堆上的内存分配可能导致内存碎片化问题，因为内存分配和释放的顺序可能是不连续的。长时间运行的程序可能导致堆空间中出现许多空闲碎片，从而降低内存利用率。而栈上的内存分配和回收顺序是线性的，不存在内存碎片化问题。
>
> - 存储空间大小：栈空间通常相对较小，受到操作系统限制。如果栈空间过大，可能导致栈溢出。堆空间相对较大，受限于计算机的可用内存。因此，对于较大的内存需求，通常需要使用堆空间进行分配。
>
> - **访问速度：**栈上的内存访问速度通常比堆上的内存访问速度要快。这是因为栈上的内存分配和回收操作只涉及指针移动，而堆上的内存分配和回收操作需要在内存中搜索可用空间，可能导致性能下降。
>
> - 线程安全性：堆是线程共享的内存区域，分配在堆上的内存可以在多个线程之间共享。然而，这可能导致线程安全问题，因为多个线程可能同时访问和修改堆上的内存。因此，使用堆时需要注意同步和互斥。而栈是线程独立的内存区域，每个线程都有自己的栈，栈上的数据在默认情况下仅对当前线程可见，这意味着栈上的数据在某种程度上具有线程安全性。



#### 12.1.2 数字存储形式[评论笔记11](https://www.runoob.com/cprogramming/c-operators.html)
正数，负数均以 **补码** 形式存储，5的二进制数： 00000101；

> 原码：一个整数，按照绝对值大小转换成的二进制数，称为原码。
> 5的原码： 00000101
>
> 反码：将二进制数按位取反，所得的新二进制数称为原二进制数的反码。
> 5的反码： 11111010
>
> 补码：反码加1称为补码。
> 5的补码： 11111011


#### 12.2 auto 存储类

**auto** 存储类是所有局部变量默认的存储类。`{int mount;}` 与 `{auto int month;}`相同，实际一般隐藏 `auto`

#### 12.3 register 存储类

定义存储在寄存器中而不是 RAM 中的局部变量；只用于需要快速访问的变量，比如计数器。
详细解释：[**评论笔记3**](https://www.runoob.com/cprogramming/c-storage-classes.html)；

> 动态和静态变量都是存放在内存中，程序中遇到该值时用控制器发指令将变量的值送到运算器中，需要存数再保存到内存中。
> 如果频繁使用一个变量，比如一个函数体内的多次循环每次都引用该局部变量 (累加计数器) ，我们则可以把局部变量的值放到CPU的寄存器中，叫寄存器变量，不需要多次到内存中存取提高效率。
> 只有局部自动变量和形参可以做寄存器变量，在函数调用时占用一些寄存器，函数结束时释放。
> **在程序一般不用。**

#### 12.4 extern 存储类

**提供一个全局变量的引用。**
有多个文件且定义了一个可以在其他文件中使用的全局变量 (函数) 时，可在其他文件中使用 extern 来得到已定义的变量 (函数) 的引用。
**简单理解：**函数/变量 声明，编译器只知道有这么个 函数/变量，具体 函数/变量 是什么需要编译器去其他地方找。

如：
**第一个文件：main.c**

```c
#include <stdio.h>
int count;
extern void write_extern();

int main(){
  count = 5;
  write_extern();
  return 0;
}
```

**第二个文件：support.c**

```C
#include <stdio.h>
extern int count;
void write_extern(void){
   printf("count is %d\n", count);
}
```

运行 **main.c**，输出 `count is 5`

`extern`为变量声明，不是变量定义，详见：[C 变量正文 评论笔记1、2](https://www.runoob.com/cprogramming/c-variables.html)、[评论笔记5、6](https://www.runoob.com/cplusplus/cpp-variable-types.html)



### 12.5 static 存储类
#### 12.5.1 [C 作用域规则](https://www.runoob.com/cprogramming/c-scope-rules.html)

**变量声明：**
**函数 (代码块) 内部声明——局部变量**：调用函数时分配内存，函数结束时释放内存；只能被该函数 (代码块) 内部的语句使用；
**函数外部声明 (通常程序顶部, .h 头文件) ——全局变量**：整个程序生命周期内都是有效的，在任意的函数内部能访问全局变量；
函数的形式参数：被当作该函数内的局部变量；

注意**局部变量与全局变量名相同时，优先使用局部变量；**

全局变量初始化默认值为：0 (int、float) 、'\0' (char)、NULL (pointer)；
局部变量初始化值为 随机值。

#### 12.5.2 static 存储类

使用**` static`**修饰的变量称为静态变量； **` static`**作用主要为：**①变量局限于当前域**；**②变量持续存在**；**③初始化默认为 0**
修饰**局部变量**——变量仅初始化一次，可以在函数调用之间保持局部变量的值（或者说此变量性质类似全局变量，但是作用域仅局限于函数内）；
修饰**全局变量 (修饰函数)** ——使变量的作用域限制在声明它的文件内；

**C 语言中全局变量、局部变量、静态全局变量、静态局部变量的区别**
**从作用域看：**

> 1、**全局变量**具有全局作用域。全局变量只需在一个源文件中定义，就可以作用于所有的源文件。当然，其他不包含全局变量定义的源文件需要用extern 关键字再次声明这个全局变量。
> 2、**静态局部变量**具有局部作用域。它只被初始化一次，自从第一次被初始化直到程序运行结束都一直存在。它和全局变量的区别在于：全局变量对所有的函数都是可见的，而静态局部变量只对定义自己的函数体始终可见。
> 3、**局部变量**也只有局部作用域，它是自动对象（auto），它在程序运行期间不是一直存在，而是只在函数执行期间存在，函数的一次调用执行结束后，变量被撤销，其所占用的内存也被收回。
> 4、**静态全局变量**也具有全局作用域，它与全局变量的区别在于：如果程序包含多个文件的话，它作用于定义它的文件里，不能作用到其它文件里，即被static关键字修饰过的变量具有文件作用域。这样即使两个不同的源文件都定义了相同名字的静态全局变量，它们也是不同的变量。

**从分配内存空间看：**
全局变量，静态局部变量，静态全局变量都在静态存储区分配空间，定义未初始化，其值为0；
局部变量在栈里分配空间，定义未初始化，其值未知；

**Tips：**

> A、若**全局变量**仅在**单个C文件**中访问，则可以将这个变量修改为**静态全局变量**，以降低模块间的耦合度；
> B、若**全局变量**仅由**单个函数**访问，则可以将这个变量改为该函数的静**态局部变量**，以降低模块间的耦合度；
> C、设计和使用访问动态全局变量、静态全局变量、静态局部变量的函数时，需要考虑重入问题，因为他们都放在静态数据存储区，全局可见；
> D、如果我们需要一个可重入的函数，那么，我们一定要避免函数中使用static变量(这样的函数被称为：带“内部存储器”功能的的函数)
> E、函数中必须要使用static变量情况: 比如当某**函数的返回值为指针类型**时，则**必须是static的局部变量的地址**作为返回值，若为auto类型，则返回为错指针。

`static`应用实例：

```C
#include<stdio.h>  
void fun()  
{   
    static int a=1;     
    a++;   
    printf("%d\n",a);  
}  
int main(void)  
{   
    fun();    // a=2
    fun();    // a=3
    fun();    // a=4
    return 0;  
}  
```

更多见[**评论笔记2、4、5**](https://www.runoob.com/cprogramming/c-storage-classes.html)、[**评论笔记7**](https://www.runoob.com/cplusplus/cpp-variable-scope.html)



### 13. [C 判断](https://www.runoob.com/cprogramming/c-decision.html)
#### 13.1 `if...else...`[if 语句](https://www.runoob.com/cprogramming/c-if.html)、[if…else语句](https://www.runoob.com/cprogramming/c-if-else.html)、[嵌套 if 语句](https://www.runoob.com/cprogramming/c-nested-if.html)

**流程图：**

![](https://static.jyshare.com/wp-content/uploads/c/C-decision-20200923-1.svg)

**语法结构如下：**

```C
if ( boolean_expression )    // boolean_expression 使用关系运算符和逻辑运算符，计算值为 true 或 false
{
     /*如果 if 条件为真，则输出下面的语句*/ 
}
else if ( boolean_expression )  // if 后可跟零个或多个else if，else if必须在else前
{
     /*如果else if 条件为真，则输出下面的语句*/ 
}
...  // if 后可跟零个或多个else if，else if必须在else前
...  // if 后可跟零个或多个else if，else if必须在else前
else   // if 后可跟零个或一个else
{
     /*如果上面条件都不为真，则输出下面的语句*/
}
```

**PS1：**C 语言把任何**非零**和**非空**的值假定为 **true**，把**零**或 **null** 假定为 **false**。
**PS2：**从前往后，只要有一个`if`，`else if`，`else`匹配成功，后面的`else if`和`else`均不会进行检测；
**PS3：**`if` 只将后面一条语句视为所执行语句，所以当`if`使用多条语句时，把多条语句放在 `{}` 表示一条；

**补充：**`if` 可以进行嵌套，详见：[**C 嵌套 if 语句**](https://www.runoob.com/cprogramming/c-nested-if.html)


#### 13.2 `switch 语句`[switch 语句](https://www.runoob.com/cprogramming/c-switch.html)、[嵌套 switch 语句](https://www.runoob.com/cprogramming/c-nested-switch.html)

一个 **switch** 语句允许测试一个变量等于多个值时的情况，每个值称为一个 case。

**流程图：**

![](https://www.runoob.com/wp-content/uploads/2014/09/switch_statement.jpg)

**语法结构如下：**

```C
switch(expression)   // expression 是一个 常量表达式，必须是一个 整型或枚举类型
{ 
    case constant-expression:  // case的constant-expression必须与switch中的变量具有相同的数据类型
       statement(s);  /* statement(s)代表执行的语句 */       
       break;    // 当被测试的变量等于 case 中的常量时，case 后跟的语句将被执行，直到遇到 break 语句为止 
    case constant-expression:  // case的constant-expression必须是一个常量或字面量
       statement(s);  // switch...case不像if...else只执行一条，所以不需要给每个case加括号；      
       break;    // break 可选择。如果 case 语句不包含 break，控制流将会继续后续的 case，直到遇到 break 为止。
  
    /* 可以有任意数量的 case 语句 */
    default :    // 可选的，上面所有 case 都不为真时执行一个任务 
       statement(s);
}
```

**PS：**`switch` 语句不会在执行判断为真后的语句之后跳出循环，而是继续执行后面所有 `case` 语句，知道遇到`break;`才跳出循环；
详见：[**评论笔记2**](https://www.runoob.com/cprogramming/c-decision.html)

**补充：**`switch` 可以进行嵌套，详见：[**C 嵌套 switch 语句**](https://www.runoob.com/cprogramming/c-nested-switch.html)

#### 13.3 `? : 运算符(三元运算符)` 

`Exp1 ? Exp2 : Exp3;`  Exp1、Exp2 和 Exp3 是表达式。
`?` 表达式的值是由 Exp1 决定的，如果 Exp1 为真，则计算 Exp2 的值，结果即为整个表达式的值。如果 Exp1 为假，则计算 Exp3 的值，结果即为整个表达式的值。
**流程图如图：**

<img src="https://www.runoob.com/wp-content/uploads/2014/09/Conditional-Statement-in-C-Programming-Lanuage-Ternary-Operator.png" alt="1" style="zoom:75%;" />



### 14. [C 循环](https://www.runoob.com/cprogramming/c-loops.html)

**循环工作流程图如图：**

![](https://www.runoob.com/wp-content/uploads/2015/12/loop.png)

#### 14.1 循环类型

| 循环类型                                                     | 描述                                                         |
| :----------------------------------------------------------- | :----------------------------------------------------------- |
| **[while 循环](https://www.runoob.com/cprogramming/c-while-loop.html)** | 当给定条件为真时，重复语句或语句组。它会在执行循环主体之前测试条件。 |
| **[for 循环](https://www.runoob.com/cprogramming/c-for-loop.html)** | 多次执行一个语句序列，简化管理循环变量的代码。               |
| **[do...while 循环](https://www.runoob.com/cprogramming/c-do-while-loop.html)** | 除了它是在循环主体结尾测试条件外，其他与 while 语句类似。    |

**1\. `while` 循环**
只要给定的条件为真，C 语言中的 `while` 循环语句会重复执行一个目标语句。
**语法结构如下：**

```C
while(condition)   // 只要 contion 为 true，就一直进行循环
{
   statement(s);   // statement(s)代表执行的语句
}
```

**PS1：**`while` 只将后面一条语句视为所执行语句，所以当`while`使用多条语句时，把多条语句放在 `{}` 表示一条；
**注意：**`while(i--);`，当` i=0`时，退出循环，之后`i`继续进行自减操作，最终结果`i=-1`；一般计数循环推荐使用`for`循环；

**2\. `do...while` 循环**
`do...while` 先执行一次循环内容，如果条件为真，然后重新执行循环，直到给定条件变为假为止。

```C
do
{ 
   statement(s);        // statement(s)代表执行的语句
}while( condition );    // 只要 contion 为 true，就一直进行循环
```

**3\. `for`循环**
`for` 循环常用来编写一个执行指定次数的循环控制结构。

```C
for (init; condition; increment)
{
   statement(s);
}

/* 典型示例 */
int a;
for(a = 10; a < 20; a++ )
{
   printf("a 的值： %d\n", a);   // 输出：10,11,12...19
}
```

下面是 for 循环的控制流：

1\. `init` 会首先被执行，且只会执行一次。这一步允许您声明并初始化任何循环控制变量 **(注意C99之后才支持)** 。当然也可以不写任何语句只保留`;`。
2\. 判断 `condition`。如果为真，则执行循环主体，如果为假，退出循环。
3\. 执行完 for 循环主体后，控制流跳回上面的 `increment` 语句。该语句允许您更新循环控制变量。该语句可以留空只保留`;`。
4\. 再次判断 `condition`。如果为真，则执行循环主体，如果为假，退出循环。这个过程会不断重复。

**注意：**C89不允许在 `init` 中定义，只能在外部定义；C99 允许在此处定义；

**补充：**循环支持嵌套，可在任何类型的循环内嵌套其他任何类型的循环，详见：**[C 嵌套循环](https://www.runoob.com/cprogramming/c-nested-loops.html)**

#### 14.2 循环控制语句

| 控制语句                                                     | 描述                                                     |
| :----------------------------------------------------------- | :------------------------------------------------------- |
| **[break 语句](https://www.runoob.com/cprogramming/c-break-statement.html)** | 终止**循环**或 **switch** 语句。                         |
| **[continue 语句](https://www.runoob.com/cprogramming/c-continue-statement.html)** | 停止本次循环迭代，重新开始下次循环迭代。                 |
| **[goto 语句](https://www.runoob.com/cprogramming/c-goto-statement.html)、[(更详细)](https://www.runoob.com/cplusplus/cpp-goto-statement.html)** | 将控制转移到被标记的语句。不建议在程序中使用 goto 语句。 |

**补充：无限循环：**
`while(1);`或者`for( ; ; );`均可



### 15. [C 函数](https://www.runoob.com/cprogramming/c-functions.html)

通常是根据每个函数执行一个特定的任务，将代码划分到不同的函数中

#### 15.1 函数定义

函数**定义**包含：返回类型、函数名称、参数、函数主体，其一般形式举例：

```C
int max(int num1, int num2)     // int为返回类型，max为函数名称，()内为函数参数，{}内为函数主体
{
   int result;   // 定义局部变量
    
   if (num1 > num2)
      result = num1;
   else
      result = num2;
    
   return result; 
}
```

**注意：函数名和参数列表一起构成了函数签名**，意味着可以出现**参数列表不同**但是**函数名相同**的函数。
如：`void print() {}` 与  `void print(int nums) {}`可以同时存在。 详见：**评论笔记14**

#### 15.2 函数声明

函数**声明**会告诉编译器函数名称及如何调用函数。
函数必须在使用前进行声明，而函数的实际主体可以单独定义。见 **正文** 及 **评论笔记9**

声明举例：

```c
int max(int num1, int num2);    // 函数声明 形参可以与定义不相同、可省略，但一般和函数定义形参相同
int max(int, int);              // 函数声明 可以省略形参
```

#### 15.3 函数使用

举例： `  ret = max(1, 2);`   ，将 `1,2` 传递至`max`函数，`max`函数计算，将`result`返回到`ret`中

函数 **形参**、**实参 **区别见：[**评论笔记1、2**](https://www.runoob.com/cprogramming/c-scope-rules.html)

#### 15.4 函数参数传递的形式

| 调用类型                                                     | 描述                                                         |
| :----------------------------------------------------------- | :----------------------------------------------------------- |
| **[值传递](https://www.runoob.com/cprogramming/c-function-call-by-value.html)** | 该方法把参数的实际值复制给函数的形式参数。在这种情况下，修改函数内的形式参数不会影响实际参数。 |
| **[指针传递](https://www.runoob.com/cprogramming/c-function-call-by-pointer.html)** | 通过指针传递方式，形参为指向实参地址的指针，当对形参的指向操作时，就相当于对实参本身进行的操作。<br />指针传递的本质也是值传递[**评论笔记7**](https://www.runoob.com/cprogramming/c-pointers.html) |

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
```

注意在 C++ 中还有 **引用传递**，详见**[评论笔记5](https://www.runoob.com/cprogramming/c-functions.html)**；

#### 15.5 数组、指针在函数间的传递

**1\. [传递数组给函数(多维数组传递方法见评论笔记1、2)](https://www.runoob.com/cprogramming/c-passing-arrays-to-functions.html)**、**[传递指针给函数](https://www.runoob.com/cprogramming/c-passing-pointers-to-functions.html)**

```C
// 方法1 形参指针 (传递指针给函数，推荐！)
void myFunction(int *param) {}
// 方法2 形参已定义大小的数组
void myFunction(int param[10]) {}
// 方法3 未定义大小的数组
void myFunction(int param[]) {}

// 主函数使用，传递指向数组的指针；如：
int balance[5] = {1000, 2, 3, 17, 50};
avg = myFunction(balance);   // 因为是指针传递，所以值会改变
```

**注意：** 数组形参传递的**本质**是一个**指针**；

```C
#include <stdio.h>

void test(int arr[], int size)
{
    printf("Inside sizeof(arr)= %d \n",sizeof(arr));
}

int main(int argc, char const *argv[])
{
    // 带有 5 个元素的整型数组
    int balance[5] = {1000, 2, 3, 17, 50};
    int *pt1 = balance;
    
    printf("sizeof(balance)= %d \n",sizeof(balance));   // sizeof(balance)= 20 
    printf("sizeof(pt1)= %d \n",sizeof(pt1));           // sizeof(pt1)= 8 
    // 分别计算数组元素个数，以及整型指针的字节数

    test(balance,5);      // Inside sizeof(arr)= 8
    // 64位系统，指针大小为8；32位系统，指针大小为4；
    return 0;
}
```

所以在数组传递时，一般要**同时传递数组大小**，因为在函数内使用**`sizeof(ARR)`**，返回**指针**大小！

**2\. [从函数返回数组](https://www.runoob.com/cprogramming/c-return-arrays-from-function.html)**、**[C 从函数返回指针](https://www.runoob.com/cprogramming/c-return-pointer-from-functions.html)**

通过指定**不带索引的数组名**来返回一个**指向数组的指针**；并且该返回变量必须为 **static** 变量，例：

```C
int * getRandom()
{
  static int r[10];
  for ( i = 0; i < 10; ++i)
		r[i] = rand();
  return r;
}

int *p = getRandom();

// 返回值为一个地址；
// 函数运行结束后，释放内存空间，所以局部变量值被释放，此时指针指向地址的值为随机值；
// 返回变量为 static 变量，此时指针指向地址的值在函数运行结束后也不会被释放。 

// 另一种方法：在堆区malloc()分配内存空间，在主程序，不使用变量时可以手动释放内存空间。
// 相较于声明为 static 静态变量，这种方法更加推荐。

// 一般来说不建议使用此写法，通常写法为：
// 传入一个数组，直接对传入数组数据进行修改
```

#### 15.6 [可变参数](https://www.runoob.com/cprogramming/c-variable-arguments.html)

**结构：**
`int func(int, ... )  {   .   .   . }`   省略号之前的那个参数是 **int**，代表了要传递的可变参数的总数；

**方法：**

> 1\. 使用 **stdarg.h** 头文件，提供了实现可变参数功能的函数和宏。
> 2\. 定义一个函数，最后一个参数为省略号，省略号前面可以设置自定义参数。
> 3\. 在函数定义中创建一个 **va_list** 类型变量，该类型是在 **stdarg.h** 头文件中定义的。
> 4\. 使用 **int** 参数和 **va_start** 宏来初始化 **va_list** 变量为一个参数列表。宏 **va_start** 是在 **stdarg.h** 头文件中定义的。
> 5\. 使用 **va_arg** 宏和 **va_list** 变量来访问参数列表中的每个项。
> 6\. 使用宏 **va_end** 来清理赋予 **va_list** 变量的内存。

**使用到的宏**
`void va_start( va_list arg_ptr, prev_param);` 
`type va_arg( va_list arg_ptr, type);` 
`void va_end( va_list arg_ptr);`

**举例：**

```C
#include <stdio.h>
#include <stdarg.h>

double sum(int num, ...)
{
    va_list valist;          // va 在这里是 variable-argument(可变参数) 的意思。
    double sum = 0.0;
    int i;

    va_start(valist, num);   // 为 num 个参数初始化 valist 
    for (i = 0; i < num; i++)
        sum += va_arg(valist, int);   // 访问所有赋给 valist 的参数 
    va_end(valist);          // 清理为 valist 保留的内存 

    return sum;
}

int main()
{
    printf("Sum of 2, 3, 4, 5 = %f\n", sum(4, 2, 3, 4, 5));    // 14.0
    printf("Sum of 5, 10, 15 = %f\n", sum(3, 5, 10, 15));      // 30.0
    return 0;
}
```

可变参数更多解释见**评论笔记3。**

#### 15.7 其他

**1\. 内部函数  (静态函数)**
用 `static` 修饰为内部函数，只能被本文件中其他函数所调用；
详细内容可参照：**评论笔记1** 及**12.5 static存储类**

**2\. 函数外部调用** 
使用`extern`声明该函数是在其他文件中定义的外部函数；
详细内容可参照：**评论笔记1** 及**12.4 extern存储类**

内部函数与函数外部调用综合应用 见**评论笔记1** 

**3\. [内联函数](https://www.runoob.com/w3cnote/cpp-inline-usage.html)**
用`inline`关键字修饰的函数，在编译器编译时**将函数调用处直接展开为函数体**，从而避免了函数调用的开销，提高程序的运行速度。
内联函数是用来解决 **频繁调用函数大量消耗栈空间** 的问题，通常用于**频繁执行**的**小函数**，可以消除函数调用时的时间开销，对于小内存空间的函数非常受益。

```C
#include <stdio.h>

char* test(int i);          // 函数声明 可不使用inline

inline char* test(int i) {  // 函数定义 使用inline，即为内联函数
    return (i % 2 > 0) ? "奇" : "偶";
} 

int main()
{
   int i = 0;
   for (i=1; i < 100; i++) {
       printf("i:%d    奇偶性:%s /n", i, test(i));    
   }// 编译器在每个for循环的内部任何调用test(i)的地方都换成了(i%2>0)?"奇":"偶"，
   return 0;
}   // 等价于： printf("i:%d    奇偶性:%s /n", i, (i % 2 > 0) ? "奇" : "偶")
```

编译器在每个for循环的内部任何调用`test(i)`的地方都换成了`(i%2>0)?"奇":"偶"`，
这样就**避免了频繁调用函数对栈内存重复开辟所带来的消耗**。

注意：inline的使用时有所限制的，
内联是**以代码膨胀（复制）为代价**，仅仅省去了函数调用的开销，从而提高函数的执行效率。
inline**只适合函数体内部代码简单的函数使用**，**不能包含复杂的结构控制语句**例如while、switch，并且不能内联函数本身**不能是直接递归函数**（即，自己内部还调用自己的函数）。

内联函数**适合**于被频繁调用、函数体较小、函数参数较简单的函数，可以减少函数调用的开销，提高程序的运行速度。
内联函数**不适合**于包含复杂的循环结构、递归调用等的函数，否则可能会导致代码膨胀，降低程序的运行效率。

**内联函数和宏定义的区别：**
**宏定义**是由**预处理器**处理的文本替换，不会对类型进行检查，且不加括号可能导致计算错误；
**内联函数**是**编译器**处理的，会检查参数类型，保证调用正确；

详见 **评论笔记2** 

**一些奇奇怪怪用法：**实测inline函数必须同时声明和定义，才可以使用；声明时不可使用inline；……
PS：static 声明时，必须带 static……

**4\. 缺省参数（只有C++有）** 
相当于指定默认参数，如：

```C
/* 注意：多个缺省参数，则缺省参数必须是从右向左定义，且一个缺省参数的右边不能有未指定缺省值的参数。 */
int fun(int a, int b, int c = 100)        
{
	return a + b + c;
}

fun(100, 100);           // return 100 + 100 + 100
fun(100, 100, 200);      // return 100 + 100 + 200
```

**5\. 函数重载（只有C++有）** 
取相同的函数名，但是形参的个数或者形参的类型不应相同。
如：`int f(int a, float b);`
	`int f(int a, float b, int c);`
`// 注：不可定义仅函数返回值不同的函数`

**6\. const 和函数形参**
如果形参是一个指针，为了防止在函数内部修改指针指向的数据，使用 const 来限制，如：

```c
int strcmp ( const char * str1, const char * str2 );
char * strcat ( char * destination, const char * source );
char * strcpy ( char * destination, const char * source );
```

**7. 函数的压栈过程**
函数调用时，需要先将返回地址、函数参数和函数局部变量压入栈中，然后跳转到函数体执行。当函数返回时，需要将栈顶的返回地址弹出，恢复到函数调用点继续执行。

#### 15.8 [函数递归](https://blog.csdn.net/m0_63123468/article/details/122462534)

**1\. 递归原理讲解：**

```C
// 递归程序示例
#include <stdio.h>

void print(int n)
{
	if (n > 9)
	{
		print(n / 10);
	}
	printf("%d ", n % 10);
}

// 递归求阶乘
int Fact(int n)
{
    if (n > 0)					/*n==0时阶乘为1*/
		return n*Fact(n - 1);		/*递归求n的阶乘*/
	else if (n == 0)
		return 1;
    else if(n < 0)
        printf("error\n");
    	return -1;
}

// 递归求斐波那契数列
int fun(int n)
{
	if(n==1||n==2)//通过数列的规律发现,前两项都为1,作为递归的终止条件
	{
		return 1;
	}
	else
	{
		return fun(n-1)+fun(n-2);//要求第n项,就是求n-1项和n-2项的和
	}

int main()
{
	int num = 123;
	print(num);
	return 0;
}
```
**工作原理：**
<img src="https://img-blog.csdnimg.cn/img_convert/98ced92a1a6be038f4c2d89a5f62bdd7.png" style="zoom:100%;" />

**递归必须满足两个必要条件：**
1.存在限制条件，当满足这个限制条件的时候，递归便不再继续。
2.每次递归调用之后越来越接近这个限制条件。

**PS：由上到下的算法设计思维：** 
① 由上→下，任务分解
② 实现模块的基础操作：如斐波那契是前两个数据和，递归是`n *( (n-1)! )`，快速排序/归并排序，就是任务分解过程；
③ if()任务分解至最小模块，则不进行分解 (return 值，如 数列/阶乘均return 1; 排序，为执行排序操作 )


**2\. 栈溢出：**

系统分配给程序的栈空间是有限的，但是如果出现了死循环，或者（死递归），这样有可能导致一直开辟栈空间，最终产生栈空间耗尽的情况，这样的现象我们称为栈溢出；

函数压栈过程见：15.7.7 ，递归是最常见的一种栈溢出原因；
栈溢出其他原因：函数中使用了大量的局部变量，函数中使用了大量的参数……



### 16. [C 数组](https://www.runoob.com/cprogramming/c-arrays.html)

**数组**用来存储一个固定大小的相同类型元素的顺序集合；

#### 16.1 一维数组声明

声明格式： `type arrayName[arraySize];`，**arraySize** 是一个大于零的整数常量，**type** 是任意有效的 C 数据类型。
如：`int array[10];`   

#### 16.2 一维数组初始化

**1\. 声明时进行初始化**
如：`float balance[5] = {1000.0, 2.0, 3.4, 7.0, 50.0};` 
**注1**：如果元素不足会在后面补 **0** (int 是 0，char 是 '\0'，float 是 0.0)，
          如：`int a[4] = {1,2}`；等价于`int a[4] = {1,2,0,0}`
**注2**：省略数组的大小，数组的大小为初始化时元素的个数；
如：`int a[] = {1,2,3};` ，`sizeof(a) / sizeof(a[0]) `   // 计算结果为3
**注3**：**数组定义与初始化分开时，只能进行单个元素的赋值，而不能进行统一赋值。**如：
`int a[5];  a = {1,2,3,4,5};`   会报错误，原因见**16.5 数组的本质**。

**2\. 数组元素的访问**
数组元素只能通过**数组名称**加**索引**进行访问，**不能使用整体赋值**
数组索引从 **0** 开始；访问举例：

```C
int i, j, n[10];
for (i = 0; i < 10; i++)
   n[i] = i + 100;    /* 设置元素 i 为 i + 100 */
for (j = 0; j < 10; j++ )
   printf("Element[%d] = %d\n", j, n[j] );    // Element[0] = 100, Element[1] = 101...Element[9] = 109
```

**PS：数组元素计算**
可以使用： **`sizeof(a)/sizeof(a[0])`**计算数组元素多少；详见：**[评论笔记2](https://www.runoob.com/cprogramming/c-arrays.html)**

#### 16.3 [C 多维数组](https://www.runoob.com/cprogramming/c-multi-dimensional-arrays.html)

**16.3.1 多维数组声明**
声明格式：`type name[size1][size2]...[sizeN];`，如：`int x[3][4];`

![int x[3][4];](https://www.runoob.com/wp-content/uploads/2014/09/two_dimensional_arrays.jpg)

**16.3.2 多维数组初始化**

```C
int a[3][4] = {  
 {0, 1, 2, 3} ,   /*  初始化索引号为 0 的行 */
 {4, 5, 6, 7} ,   /*  初始化索引号为 1 的行 */
 {8, 9, 10, 11}   /*  初始化索引号为 2 的行 */
};

int a[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};    // 与上面初始化等价
```

**16.3.3 多维数组访问**

举例：

```C
int i, j, n[5][2] = {{0,0}, {1,2}, {2,4}, {3,6}, {4,8}};
for (i = 0; i < 5; i++)
    for ( j = 0; j < 2; j++ )
        printf("a[%d][%d] = %d\n", i,j, a[i][j] );     // 输出a[0][0]=0, a[1][0]=1...a[4][1]=8; 
```



### 16.4 [C 字符串](https://www.runoob.com/cprogramming/c-strings.html)

**字符串**本质是使用空字符 **\\0** 结尾的一维字符数组；
`char site[] = "RUNOOB";` 等价于 `char site[7] = {'R', 'U', 'N', 'O', 'O', 'B', '\0'};`

字符串同数组，其**字符数组名 (字符串名) 代表其首地址**，但**默认显示方式为整个字符串**；C中不存在 字符串 变量。
如：**指针** 可以**直接指向** **字符串**；C++将 **字符串名 直接cout**，默认**输出结果**为 **字符串**；

**注意1**：使用`""`声明字符串结尾默认会加`'\0'`，没有`'\0'`输出会有误；**[评论笔记2](https://www.runoob.com/cprogramming/c-strings.html)**、**[评论笔记1](https://www.runoob.com/cplusplus/cpp-arrays.html)**
**注意2**：**字符** 与 **字符串** 区别：**'a'** 表示是一个字符，**"a"** 表示一个字符串相当于 **'a'+'\0'**;   **[评论笔记4](https://www.runoob.com/cprogramming/c-strings.html)**
**注意3**：字符串换行使用`\`，注意字符串换行，下一行前**不能有空格或者Tab键；**
**注意4**：`char site[] = "RUNOOB";`此时`site`有7个字符，`char site[6] = "RUNOOB";   // ERROR`

#### **16.4.1 字符串详细使用方法 ** **详见评论笔记5**
##### **1. 字符数组声明：**
1）数组形式
`char hi[] = {'h','e','l','l','o','\0'};`
2）直接赋首地址：
`char hi[50] ="hello" ;`
3）省略长度
`char hi[] = "hello";` ， `char hi[] = { "hello" };`
4）字符指针：(注意指针不能直接赋给数组)
`char *hi = "hello";`
**注意：不建议使用方法4**，因为前三种方法定义数组，其数组内部元素均可以修改；而第四种方法定义字符指针，其内部元素无法修改；会弹出警告。

##### **2. 字符数组使用输出：**
`char hi[]="hello";`

1）字符串遍历：
`for(i=0; i<6; i++)   printf("%c",hi[i]); `
2）字符串直接输出：
`printf(hi);`
3）字符串格式（%s）输出：
`printf("%s",hi);`
以上输出均为：`hello`

4）字符串格式（%p）输出：
`printf("%p",hi);`
此时输出为指针地址；

5）对字符串取值输出，(\*p)，结果为第一个字符：
`printf("%c",*hi);`，输出结果为：h；
`printf("%d",*hi);`，输出结果为：104；（字符'h'所对应的ASCLL码值为104）
字符串遍历：`for(i=0; i<6; i++)   printf("%c",*(hi+i) ); `

**注：** **数组名**，代表**数组首地址**；
&nbsp;     对于**字符数组**，**字符数组名 (字符串名) 代表其首地址**，但**默认显示方式为整个字符串**；
&nbsp;     对**字符数组取值(\*p)**，结果为**当前地址所存储字符 (字符串首字母) **；

#### 16.4.2 字符串操作函数

头文件：  `#include <string.h>`

| 函数                                | 作用                                                         |
| :---------------------------------- | :----------------------------------------------------------- |
| **strcpy(s1, s2);**                 | string copy ，复制字符串 s2 到字符串 s1。(其实作用就是字符串直接赋值) |
| **strcat(s1, s2);**                 | string catenate ，连接字符串 s2 到字符串 s1 的末尾。         |
| **strlen(s1);**                     | string length ，返回字符串 s1 的长度。与 **sizeof()** 区别见 **评论笔记3** |
| **strcmp(s1, s2);**                 | string compare ，如果 s1 和 s2 是相同的，则返回 0；<br />如果两个字符串不相同，且第一个字符串的第一个字符小于第二个字符串的第一个字符，返回值＜ 0，<br />反之，返回值＞0。 |
| **strchr(s1, ch);**                 | 返回一个指针，指向字符串 s1 中字符 ch 的第一次出现的地址。<br />返回地址 - 字符串起始地址 = 字符 ch 第一次出现位置。 |
| **strstr(s1, s2);**                 | 返回一个指针，指向字符串 s1 中字符串 s2 的第一次出现的地址。<br />返回地址 - 字符串起始地址 = 子串 s2 第一次出现位置。 |
| **atoi();<br/>atof();<br/>atol();** | 输入数据：字符串；  返回数据：int/double 等类型<br />将字符串转化为int型；<br/>将字符串转换为double类型；<br/>将字符串转化为long类型；<br/>注意：此函数及下面函数均在<stdlib.h>中 |
| **itoa()**                          | `char *itoa(int i,char *s,int radix);`<br />`int i `要转换为字符的数字、`char *s` 转换后的指向字符串的指针、`int radix `转换数字的进制数<br />E.P `char string[16] = {0};    itoa(number1,string,10);` |

**PS：数组相关 重要函数**

**1\.** **`memcpy();`** 数组复制函数。
**`strcpy(s1, s2);`**与**`memcpy();`**区别
[void **\*memcpy**(void \*dest, const void \*src, size_t n)](https://www.runoob.com/cprogramming/c-function-memcpy.html)               
将数组**src**的前**n**个字节复制到**dest**中，数组src适用于 **字符数组、整型/浮点数组、结构体** 等所有类型数据；
`strcpy(s1, s2);`只适用于字符串。

**2\.** **`memset();`** 数组清零函数。
[void **\*memset**(void *str, int c, size_t n)](https://www.runoob.com/cprogramming/c-function-memset.html)               
复制字符 **c** 到 **str** 所指向的 **数组/结构体/字符串** 的前 **n** 个字节；
常用于数组清零：memset(\*str, 0, sizeof(\*str))。
**注意：**该函数**按照字节复制**，如：int32_t数组，将01(int8_t)复制入数组，此时数组元素为：01010101、01010101。

**注意：** `strlen(s1)`求 字符串长度 和 使用`sizeof(s1)`求 字符数组占用大小 的区别 见 **评论笔记3**；

**补充：**函数声明时，使用**`void*`**指针，**`void*`**指针详见17.7节。

**3\.** **`memmove();`** 数组复制函数。
[void *memmove(void *str1, const void *str2, size_t n)](https://www.runoob.com/cprogramming/c-function-memmove.html)          // 与 `memcpy` 功能相同，不过memmove更安全

```C
// memcpy与memmove区别
char data[10] = "abcdefghi"; // 初始化一个字符串
// 将 data 的前 5 个字节复制到 data+2 的位置
memcpy(data + 2, data, 5);    // abababahi(复制过程中出现覆盖)
memmove(data + 2, data, 5);   // ababcdehi
```



### 16.5 数组的本质

数组名本质是一个**指向数组中第一个元素**的**常量指针**；
例：`double balance[10];`，**balance** 是一个指向 **&balance[0]** 的指针；
所以**数组可以使用指针方法访问数值**：
`*(balance + 4)` 是一种访问 `balance[4]` 数据的合法方式；
`balance+4`也是访问 `&balance[4]` 地址的合法方式；

**注意：**`&balance`是对整个数组名取地址，`balance+1` 会将地址加 8 个字节；但 `&balance+1` 就是将地址增加 10*8 个字节；

**指针与数组名本质区别**    [**评论笔记6**](https://www.runoob.com/cprogramming/c-arrays.html)
指针：是一个变量，存储的数据是地址。
数组名：代表的是该数组最开始的一个元素的地址，是个常量；

常量指针的理解：
`double *p = balance;`  定义**p**为指向数组的数组指针
`p++`合法，表示`p`地址变为下一个存储位置，`balance++`不合法，因为`balance`存储地址不能变。

**PS1：**字符数组数组名除代表第一个元素首地址外，还代表整个字符串；详见**16.4**；
&nbsp;          例：`char name[] = "Zara Ali";`，`&name[2]`代表着：`ra Ali` 字符串；

**PS2：**对数组名取地址：`&balance`，得到的是整个数组的地址，`&balance == balance`
&nbsp;       （&balance+1）得到的是增大整个数组内存大小的地址：增大4*50。**详见：[评论笔记11](https://www.runoob.com/cprogramming/c-arrays.html)**

**数组、指针元素的区别及更多访问方式见：[评论笔记1、4、6、7、11](https://www.runoob.com/cprogramming/c-arrays.html)**



**二维数组本质：[评论笔记3、4](https://www.runoob.com/cprogramming/c-multi-dimensional-arrays.html)**

**以下为我的理解：**二维数组本质为 一维数组，但每一个维度 存储的是一个 一维数组；
如：a\[3][2]={{1,2} , {3,4} , {5,6}};    a[0]={1,2} ;  a[1]={3,4} ……
	a\[3][2]={{1,2} , {3,4} , {5,6}};    a为数组首地址，即为 a[0]地址，a+1 为数组第二个成员地址，即为a[1]地址；……

二维数组 在逻辑上是方阵，在物理上是线性的，内存是连续的。

**如果使用指针来表示：**那么用到的下面的：**数组指针**！

`(**a+1)`，取a\[0][0]值+1，即`a[0][0]+1`；`(*a+1)`，取a\[0]值，即&a\[0][0] +1，即为`&a[0][1]`；
`(a+1)`，等效于&a\[0] +1，即为`&a[1][0]`；`(&a+1)`，获取数组a大小，即为`&a+1`；

正确访问方式：`*( *(a + 1) + 2)` 即 `a[1][2]`；



<u>**修改：**</u>

数组名本质是一个**指向数组中第一个元素**的**常量指针**；（不完全正确，**其实蕴含着一个<u>强制类型转换</u>……**）。

**`double balance[10];`**，**balance** 是一个指向 **&balance[0]** 的指针；

`balance`其实代表着，数组第一个元素的地址；是常量指针，不能`++`；`(balance+1)`即访问`balance`向后的第一个元素(`balance[1]`)。
`&balance`代表着，整个数组的起始地址，`sizeof(balance)`，得到是整个数组的大小。`(&balance+1)`，访问下一个数组。

结合下面**数组指针**，**指针类型强转/void指针**……理解一下




### 17. [C 指针](https://www.runoob.com/cprogramming/c-pointers.html)

什么是指针？ 指针也就是内存地址，指针变量是用来存放内存地址的变量。更多指针基础特性讲解参照[**评论笔记1、9、10**](https://www.runoob.com/cprogramming/c-pointers.html)
指针运用举例：
![img](https://www.runoob.com/wp-content/uploads/2014/09/c-pointer.png)
指针常用的运算符：定义一个指针变量`*`、把变量地址赋值给指针`&`、访问指针变量中可用地址的值`*`。示例如下：

```C
int  var = 20;     // 实际变量的声明 
int  *ip;     // 指针变量的声明，指针不指定初始值，会指向随机地址; 
// int  *ip = NULL;     // 为指针变量赋一个 NULL 值是一个良好的编程习惯; 指针未初始化使用可能导致系统崩溃！
ip = &var;  /* 在指针变量中存储 var 的地址 */
 
printf("var 变量的地址: %p\n", &var  );       // var 变量的地址: 0x7ffeeef168d8
printf("ip 变量存储的地址: %p\n", ip );        // ip 变量存储的地址: 0x7ffeeef168d8
printf("*ip 变量的值: %d\n", *ip );           // *ip 变量的值: 20
```

指针占用变量存储空间为 4字节(32位)，8 字节(64位)  [**C 指针数组 评论笔记1**](https://www.runoob.com/cprogramming/c-array-of-pointers.html)

指针的复杂操作见：[**评论笔记4、5**](https://www.runoob.com/cprogramming/c-pointers.html)，[**评论笔记3**](https://www.runoob.com/cprogramming/c-array-of-pointers.html)，[**评论笔记3**](https://www.runoob.com/cprogramming/c-pointers.html)

#### 17.1 [C 指针的算术运算](https://www.runoob.com/cprogramming/c-pointer-arithmetic.html)

**1\. 指针的四种算术运算：++、--、+、- **

指针的加减规则：
1\. 指针的每一次递增，它都会指向下一个元素的存储单元。
2\. 指针的每一次递减，它都会指向前一个元素的存储单元。
3\. 指针在递增和递减时跳跃的字节数取决于指针所指向变量数据类型长度，比如 int 就是 4 个字节。

如：

```C
int var[] = {10, 100, 200};
int i, *ptr;
ptr = var;

for (i = 0; i < MAX; i++)                      // 依次输出：存储地址、存储值
{
    printf("存储地址：var[%d] = %p\n", i, ptr);  // var[0] = 518a0adc、var[1]=518a0ae0、var[2]=518a0ae4
    printf("存储值：var[%d] = %d\n", i, *ptr);   // var[0] = 10、var[1] = 100、var[2] = 200
    /* 指向下一个位置 */
    ptr++;
}
```

**注意：**指针使用++和--时，前后顺序区别

```C
int a[5]={10,12,14,16,18};
int *p=a;                                                // 存储地址：000000bd74bff930，  存储值：10

++p;
p++;    // 二者完全相同，指针p移向下一个存储单元
printf("存储地址：%p，  存储值：%d\n", p, *p);               // 存储地址：000000bd74bff934，  存储值：12

++*p;   // 对 指针所指向单元 的值，进行++                     // 存储地址：000000bd74bff930，  存储值：11
*p++;   // 对 指针所指向单元，进行++（指针p移向下一个存储单元）   // 存储地址：000000bd74bff934，  存储值：12
printf("存储地址：%p，  存储值：%d\n", p, *p);     
```

**2\. 指针的比较： ==、< 和 >**

如果 p1 和 p2 指向两个相关的变量，比如同一个数组中的不同元素，则可对 p1 和 p2 进行大小比较。
**如：**`while(ptr <= &var[2]) ;`

#### 17.2 [C 指向数组的指针](https://www.runoob.com/cprogramming/c-pointer-to-an-array.html)

指向数组的指针 (数组指针)，指的是：定义一个指针，指针指向数组的首地址；
如：`double balance[50],*p; p = balance;` **p**是指向**balance**的数组指针
之后可使用`p+4`访问 `&balance[4]` 地址，`p[4]`访问 `balance[4]` 数据；
由于指针是变量，还可以使用`p++`访问数据，而`balance`是常量不可`++`。
**注意：**`&balance`是对整个数组名取地址，`balance+1` 会将地址加 **8** 个字节；但 `&balance+1` 就是将地址增加 **10*8** 个字节

**数组、指针元素的区别及更多访问方式**见：**[评论笔记1、4、6、7、11](https://www.runoob.com/cprogramming/c-arrays.html)**

#### 17.3 [C 指针数组](https://www.runoob.com/cprogramming/c-array-of-pointers.html) [(另一个讲解)](https://blog.csdn.net/itszok/article/details/121198169)

使用数组存储指向 int 或 char 或其他数据类型的指针，称为指针数组。

如：

```C
int var[] = {10, 100, 200};
int i, *ptr[3];

for (i = 0; i < 3; i++)
    ptr[i] = &var[i];     // 赋值为整数的地址 
for (i = 0; i < MAX; i++)
    printf("Value of var[%d] = %d\n", i, *ptr[i]);   // 输出指针指向的值
```

再如：用一个指向字符的指针数组来存储一个字符串列表

```C
const char *names[4] = {"Zara Ali","Hina Ali","Nuha Ali","Sara Ali"};
int i = 0;

for (i = 0; i < 4; i++)
{
    printf("Value of names[%d] = %s\n", i, names[i]);
}

// 感觉不如直接定义二维数组
char[4][10] = {"Zara Ali","Hina Ali","Nuha Ali","Sara Ali"};
// 后续可以使用：char[1]、char[2]访问每个字符串
```

**指针数组，数组指针区别：[评论笔记1、2、3、4、5、6](https://www.runoob.com/cprogramming/c-array-of-pointers.html)**

**指针数组：**表示的是一个**由指针变量组成的数组**，也就是说其中的元素都是指针变量。
指针数组定义举例：int \*p[3]; （[]优先级比 \* 高，先与[]结合，所以是数组，之后与 \* 结合, 说明数组里元素是指针类型 ）
等效于：int \*(ptr[3]);
**数组指针：**~~表示的是这是个**指向(二维)数组的指针**，那么该指针变量存储的地址就必须是(二维)数组的首地址~~
表示的是这个是**指向由一维数组构成的数组**的指针；
数组指针定义举例：int (\*p)[4];（()优先级最高，先与\*结合，所以是指针，之后与[]结合，说明指针指向数组）
~~（int (*p)[4]定义了一个指向含有4个元素的一维数组的指针）~~
（`int (*p)[4]` 含义： `p` 指向 由 `int [4]` 一维数组 构成的 (二维)数组！）

**一维数组：**
<img src="https://img-blog.csdnimg.cn/726e89345b014652838e65e1a73c8e76.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBA6JSh5rO95Z-64pyU4oSh,size_10,color_FFFFFF,t_70,g_se,x_16#pic_center" alt="请添加图片描述" style="zoom:90%;" />
**二维数组：**
<img src="https://img-blog.csdnimg.cn/554d5122101449f7b31d556c4ae6a645.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBA6JSh5rO95Z-64pyU4oSh,size_20,color_FFFFFF,t_70,g_se,x_16#pic_center" alt="请添加图片描述" style="zoom: 90%;" />

数组指针的使用：

```C
int A[2][2] = {{1, 2}, {3, 4}};
int(*pA)[2] = A;

int B[8] = {1, 2, 3, 4, 5, 6, 7, 8};
int(*pB)[4] = &B;
// 此时等级为 pB[2][4];

printf("%d\t", **pA);  // 1
pA++;
printf("%d\t", **pA);  // 3

printf("%d\t", **pB);  // 1
pB++;
printf("%d\t", **pB);  // 5
````
**解析：**数组指针，存储的是 数组的首地址，`指针pA`存储的是`指针A`的地址，`指针pA`的值是`指针A`指向的地址；
数组指针的偏移量为 `[]` 定义的偏移量 (其实就是定义数组指针的大小)。

**数组指针** 常用于 **二维数组**，如上面的 int(\*pA)[2] = A; ，这样子指针pA就知道数组单维度的大小，如果 int \*pA = A;  会报警告，编译器会按照一维数组规律寻址；

**更详细的测试例程：**

```C
/*-------------------指针数组-------------------*/
const char *names[4] = {"Zara Ali", "Hina Ali al", "Sara Ali cccd", "Nuha Ali"};
                        // char[9]   char[12]       char[14]         char[9]
// 数组存储4个 char* 指针
for (int i = 0; i < 4; i++)
{
    printf("names[%d]地址为%p\n", i, names[i]);
    // 0x50    0x059    0x065    0x073
}

int *p[3]; // 定义指针数组
// 数组存储3个 int* 指针
int a[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
for (int i = 0; i < 3; i++)
{
    p[i] = a[i]; // 通过循环将a数组每行的首地址分别赋值给p里的元素
    printf("p[i]地址为%p\n", p[i]);     // 0xD0  0xE0  0xF0
}
// p = a;           // ERROR, p是一个不可知变量，只存在p[0],p[1],p[2]
// 引用方式：*(*(p+i)+j)、(*(p+i))[j]、p[i][j]、*(p[i]+j)

LNode *arrp[3];   // 定义指针数组
// 存储3个LNode节点指针
arrp[0] = L->next;
arrp[0] = L->next->next;
arrp[0] = L->next->next->next;

/*-------------------数组指针-------------------*/
// 一维数组
int B[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
int *pA = B;

printf("数组B大小为%d\n",  sizeof(B));     // 数组B大小为48
printf("指针pA大小为%d\n", sizeof(pA));    // 数组B大小为8  （64位系统指针大小恒为8）

printf("B[0]地址为%p\n", &B[0]);      // 0x20
printf("B[1]地址为%p\n", &B[1]);      // 0x24
printf("B[4]地址为%p\n", &B[4]);      // 0x30

printf("B + 1地址为%p\n", (B + 1));   // 0x24
pA++;
printf("B++地址为%p\n", pA);          // 0x24

// 二维数组
int arrB[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
// pB指向 含有4个元素的一维数组的 指针  (pB等于 含有4个元素的一维数组的 二维数组)
int(*pB)[4] = arrB;
int(*pC)[4] = (int(*)[4])B;      // 对于一维数组   B，编译器按照二维数组方式进行寻址
int *pD = (int *)arrB;           // 对于二维数组arrB，编译器按照一维数组方式进行寻址    

int(*pE)[4] = &arrB[1][1];       // 编译合法，arrB = 0x20; pE = 0x34；
// 编译器会把 从 arrB[1][1] 开始往后的4个数据，视为一个含有4个元素的一维数组；编译通过；
// 实际程序运行会出现数组越界错误
int F[4] = {1, 2, 3, 4};
int(*pF)[4] = F;                 // 合法  pF = 0x20; pF++ = 0x30
// 编译器会把 从F 开始往后的4个数据，视为一个含有4个元素的一维数组；
int*pG = F;                      // 合法  pF = 0x20; pF++ = 0x24
// pG是一个指向元素F[0]地址的普通的指针

printf("数组arrB大小为%d\n", sizeof(arrB));    // 数组arrB大小为48

printf("arrB地址为%p\n", arrB);               // 0xE20

printf("arrB[0][0]地址为%p\n", &arrB[0][0]);  // 0xE20
printf("arrB[0][1]地址为%p\n", &arrB[0][1]);  // 0xE24
printf("arrB[0][2]地址为%p\n", &arrB[0][2]);  // 0xE28
printf("arrB[1][0]地址为%p\n", &arrB[1][0]);  // 0xE30
printf("arrB[2][0]地址为%p\n", &arrB[2][0]);  // 0xE40

printf("arrB[0]地址为%p\n", arrB[0]);         // 0xE20 (第1个一维数组)
printf("arrB[1]地址为%p\n", arrB[1]);         // 0xE30 (第2个一维数组)
printf("arrB[2]地址为%p\n", arrB[2]);         // 0xE40 (第3个一维数组)

printf("arrB+0地址为%p\n", arrB + 0);         // 0xE20 (第1个一维数组)
printf("arrB+1地址为%p\n", arrB + 1);         // 0xE30 (第2个一维数组)
printf("arrB+2地址为%p\n", arrB + 2);         // 0xE40 (第3个一维数组)

printf("arrB[0]+0地址为%p\n", arrB[0] + 0);   // 0xE20 (第1个一维数组 的 第1个元素)
printf("arrB[0]+1地址为%p\n", arrB[0] + 1);   // 0xE24 (第1个一维数组 的 第2个元素)
printf("arrB[0]+2地址为%p\n", arrB[0] + 2);   // 0xE28 (第1个一维数组 的 第3个元素)

printf("*(arrB+0)地址为%p\n", *(arrB + 0));   // 0xE20 (第1个一维数组)
printf("*(arrB+1)地址为%p\n", *(arrB + 1));   // 0xE30 (第2个一维数组)
printf("*(arrB+2)地址为%p\n", *(arrB + 2));   // 0xE40 (第3个一维数组)

printf("*(arrB + 0) + 0地址为%p\n", *(arrB + 0) + 0);   // 0xE20 (第1个一维数组 的 第1个元素) 
printf("*(arrB + 0) + 1地址为%p\n", *(arrB + 0) + 1);   // 0xE24 (第1个一维数组 的 第2个元素)
printf("*(arrB + 0) + 2地址为%p\n", *(arrB + 0) + 2);   // 0xE28 (第1个一维数组 的 第3个元素)

// *(*(p+i)+j)、(*(p+i))[j]、p[i][j]、*(p[i]+j)

printf("arrB[0][1]值为%d\n", arrB[0][1]);     // 2
printf("arrB[1][2]值为%d\n", arrB[1][2]);     // 7
printf("arrB[2][3]值为%d\n", arrB[2][3]);     // 12

printf("*(*(arrB + 0)+1)地址为%d\n", *(*(arrB + 0) + 1)); // 2
printf("*(*(arrB + 1)+2)地址为%d\n", *(*(arrB + 1) + 2)); // 7
printf("*(*(arrB + 2)+3)地址为%d\n", *(*(arrB + 2) + 3)); // 12

printf("*(arrB + 0)[1]值为%d\n", *(arrB + 0)[1]);  // 5  ERROR，原因不好说……
printf("*(arrB + 1)[2]值为%d\n", *(arrB + 1)[2]);  // 0  ERROR，原因不好说…… 
printf("*(arrB + 2)[3]值为%d\n", *(arrB + 2)[3]);  // 1  ERROR，原因不好说…… 

// arrB + 0 与 *(arrB + 0) 指向地址相同，但对指针的解析方法不同
// arrB + 0，此时指针解析方法，仍为二维数组指针，(arrB + 0)+1，移至第2个一维数组
// *(arrB + 0)，此时指针解析方法，为一维数组指针，*(arrB + 0)+1，移至第1个一维数组 的 第2个元素

pB = arrB;
printf("pB地址为%p\n", pB);   // 0xE20
pB++;
printf("pB地址为%p\n", pB);   // 0xE30   // 移动至 第2个一维数组

pB = arrB; 
printf("pB地址为%p\n", pB);   // 0xE20
*pB++;
printf("pB地址为%p\n", pB);   // 0xE30   // 移动至 第2个一维数组 (单目运算符由右向左，先++后取值)

pB = arrB;
printf("pB地址为%p\n", pB);   // 0xE20
// (*pB)++;    // ERROR，pB取值后是第一个一维数组，数组不可以++了
int *ppp = (*pB)+1;        
printf("pB地址为%p\n", ppp);  // 0xE24   // 移动至 第1个一维数组 的 第2个元素

// 用malloc动态申请一个二维数组
int (*cc)[4]=(int(*)[4])malloc(sizeof(int)*3*4);     // 直接内存分配强转即可
// 之后按照正常数组使用
free(cc);

/*-------------------二级指针-------------------*/
int V;
int *Pt1;
int **Pt2;

V = 100;     // var = 100
Pt1 = &V;    // Pt1 获取 V 的地址       // Pt1 = 0x7ffee2d5e8d8，*Pt1 = 100
Pt2 = &Pt1;  // Pt2 获取 Pt1 的地址   // Pt2 = 0x7ffee2d5e8d0，*Pt1 = 0x7ffee2d5e8d8，**Pt2 = 100

// 注意！
// **Pt2 与 (*Pt)[4]  不是同一个东西！
// 二维数组，使用数组指针进行表示，不是使用二级指针！
```

**[详见评论笔记4、5](https://www.runoob.com/cprogramming/c-pointers.html)、[评论笔记3、7](https://www.runoob.com/cplusplus/cpp-array-of-pointers.html)、[评论笔记5](https://www.runoob.com/cplusplus/cpp-pointer-to-pointer.html)**

#### 17.4 [C 指向指针的指针 (多维指针)](https://www.runoob.com/cprogramming/c-pointer-to-pointer.html)

![img](https://www.runoob.com/wp-content/uploads/2014/09/c-pointerxxxxx.png)



```C
int V;
int *Pt1;
int **Pt2;

V = 100;     // var = 100
Pt1 = &V;    // Pt1 获取 V 的地址       // Pt1 = 0x7ffee2d5e8d8，*Pt1 = 100
Pt2 = &Pt1;  // Pt2 获取 Pt1 的地址   // Pt2 = 0x7ffee2d5e8d0，*Pt1 = 0x7ffee2d5e8d8，**Pt2 = 100
```

~~**注意：**数组无多维指针，如：`int a[5];`，`a`和`&a`值是一样的；[**评论笔记1**](https://www.runoob.com/cprogramming/c-arrays.html)~~
错误：`int a[5];`，`a`是指向数组第一个元素的指针，`&a`是指向整个数组的指针，虽然二者地址相同。

#### 17.5 [C 指向函数的指针 (函数指针)](https://www.runoob.com/cprogramming/c-fun-pointer-callback.html)、[函数指针(C++)](https://www.runoob.com/w3cnote/cpp-func-pointer.html)

**函数指针指向函数；**

```C
/******** 实例1 ********/
#include <stdio.h>
 
int max(int x, int y)
{
    return x > y ? x : y;
}
 
int main(void)
{
    /* p 是函数指针 */
    int (* p)(int, int) = & max; // &可以省略
    int a, b, c, d;
 
    printf("请输入三个数字:");
    scanf("%d %d %d", & a, & b, & c);
 
    /* 与直接调用函数等价，d = max(max(a, b), c) */
    d = p( p(a, b) , c); 
 
    printf("最大的数字是: %d\n", d);
 
    return 0;
}

/******** 实例2 ********/
int test(int a)
{
    return a;
}
int main()
{
    int (*fp)(int a);
    fp = test;
    cout<<fp(2)<<endl;
    return 0;
}
```

**回调函数**
**函数指针作为某个函数的参数使用**
例：

```C
/******** 实例1 ********/
#include <stdio.h>
 
// 回调函数
void populate_array(int *array, int arraySize, int (*getNextValue)(void) )
{
	*array = getNextValue();
}
 
// 获取随机值
int getNextRandomValue(void)
{
    return rand();
}
 
int main(void)
{
    int myarray;
    /* getNextRandomValue 不能加括号，否则无法编译，因为加上括号之后相当于传入此参数时传入了 int , 而不是函数指针*/
    populate_array(&myarray, 10, getNextRandomValue);
    printf("%d \n", myarray);
    return 0;
}


/******** 实例2 ********/
#include <stdio.h>

int sum(int a,int b)
{
    return a+b;
}

//sum2是回调函数，通过函数指针*p回调sum函数
int sum2(int num,int (*p)(int,int),int a,int b)
{
    return  num * p(a,b);
}

int main()
{
    int (* p)(int a,int b) = sum;
    // int (* p)(int, int); 
    // p = max;

    printf("SUM = %d\n",p(1,2));
    printf("SUM2 = %d\n",sum2(2,sum,1,2));
    return 0;
}
```

[**本质：**](https://blog.csdn.net/u014221279/article/details/50978204)

从指针层面上理解函数：即函数的函数名实际上是一个指针，该指针指向函数在内存中的首地址；
函数指针定义：`char (*pFun)(int);` 定义一个函数指针pFun，它指向一个返回类型为char，有一个整型的参数的函数，

使用typedef可以让函数指针更直观方便：
`typedef char (*PTRFUN)(int);`	`typedef  返回类型(*新类型)(参数表)`
后续直接使用`PTRFUN`定义新类型即可，如：`PTRFUN pFun;`

```C
#include <stdio.h>
 
//定义一个函数指针pFUN，它指向一个返回类型为char，有一个整型的参数的函数
char (*pFun)(int);
//定义一个返回类型为char，参数为int的函数
//从指针层面上理解该函数，即函数的函数名实际上是一个指针，
//该指针指向函数在内存中的首地址

// 而typedef可以让函数指针更直观方便
// 形式2：typedef  返回类型(*新类型)(参数表)
typedef char (*PTRFUN)(int); 
PTRFUN pFun2; 

char glFun(int a)
{
    printf("进入glFun函数，返回值为: %d\n",a);
    return a;
}
 
int main()
{
    char ret;
    
	//将函数glFun的地址赋值给变量pFun
    pFun = glFun;
	//*pFun”显然是取pFun所指向地址的内容，当然也就是取出了函数glFun()的内容，然后给定参数为2。    
    ret = (*pFun)(2);
    // ret = pFun(2);    // 直接这样写就可以
    printf("pFun函数，返回值为: %d\n",ret);
    
    pFun2 = glFun;    
    ret = (*pFun2)(2);   // 直接这样写就可以
    printf("pFun函数，返回值为: %d\n",ret);
    
    return 0;
}

/*
入glFun函数，返回值为: 2
pFun函数，返回值为: 2
进入glFun函数，返回值为: 2
pFun2函数，返回值为: 2
*/
```

更多参照：**[正文](https://www.runoob.com/cprogramming/c-fun-pointer-callback.html)、[评论笔记2、3](https://www.runoob.com/cprogramming/c-passing-pointers-to-functions.html)、[评论笔记6](https://www.runoob.com/cprogramming/c-pointers.html)**

#### 17.6 [const 和 指针](http://c.biancheng.net/view/2041.html)

**1\. const 和指针**

```c
const int *p1;     // 常量指针
int const *p1;	   // 常量指针
// const距离 * 近，此时修饰指针指向的数据，此时 p1 本身的值可以修改（指向不同的数据），但它们指向的数据不能被修改。
// 助记：从右往左看，const修饰int，所以指针指向数据不能改变

int * const p2;    // 指针常量
// const距离 变量名 近，此时修饰指针变量，此时 p2 本身的值不能被修改，但是可以修改指向的数据。
// 助记：从右往左看，const修饰*，所以指针本身值不能改变
// 此外由于 指针本身值不能改变，定义时必须初始化！

int a=1,b=2;
const int *p1 = &a;
int * const p2 = &a;  
p1= &b;    // 合法
*p2= 6;    // 合法
*p1= 6;    // 不合法
p2= &b;    // 不合法

const int * const p3;
int const * const p3;
// 此时 p3 指针本身和它指向的数据都是只读的。
// 注意 指针本身值不能改变，定义时必须初始化！

const int a[5]={0,1,2,3,4};
a[1] = 2;  // ERROR，此时a[5]内的值无法修改；
// 由于数组本质是 指向数组中第一个元素的常量指针，所以指向对象也无法修改。

typedef int * pint;
const pint p1 = &i1;     // 等价于 int * const p;
```

**2\. const 和函数形参**

```c
// 在C语言标准库中，有很多函数的形参都被 const 限制了，下面是部分函数的原型：
size_t strlen ( const char * str );
int strcmp ( const char * str1, const char * str2 );
char * strcat ( char * destination, const char * source );
char * strcpy ( char * destination, const char * source );
int system (const char* command);
int puts ( const char * str );
int printf ( const char * format, ... );
// 主要作用为：保护数据不被修改；

// 如：printf ( const char * format, ... );
// format 指向的数据可以变化，
// 但是指向数据值不能改变，
// 通过 const 限制，保证输出结果无误。
```

**3\. const 和非 const 类型转换**

```C
const char *str1 = "c.biancheng.net";
char *str2 = str1;   // ERROR
// str1通过 const 限制，指针指向的值不能修改，
// 但是str2未被 const 修饰，指针指向的值可以修改，
// 此时编译器会警告或报错。

char *str2 = "c.biancheng.net";   
const char *str1 = str2;
// 此时编译通过，
// 尽管str1和str2指向相同地址，
// str2所指向值可以修改，但是str1指向值不可以修改。
// C语言标准库中很多函数的参数都被 const 限制了，参数传递时均隐含此转换。

char * const str1 = "c.biancheng.net";
char *str2 = str1;   // 合法，此时const修饰*而不是str1。

const char *str1 = "c.biancheng.net";
const char *str2 = str1;   // 合法，二者均被const修饰。
```

**[注意：char p[]和char *p 区别](https://www.cnblogs.com/zkfopen/p/10521715.html)：** **[评论笔记9](https://www.runoob.com/cplusplus/cpp-pointers.html)**

```C++
char *str2 = "c.biancheng.net";     // C/C++中会报出警告
// warning: ISO C++ forbids converting a string constant to 'char*' [-Wwrite-strings]
// 解决方法：
const char *str2 = "c.biancheng.net";        // 编译通过
char *str2 = (char *)"c.biancheng.net";      // 编译通过 
char str2[] = "c.biancheng.net";             // 编译通过

// 在C和C++中，"c.biancheng.net"字符串被视为 字符串常量，其类型为const char *，不可修改。
// 由上讲解知，const char *转化为char *，会报出警告；
// 若要将"c.biancheng.net"视为字符数组，正确方法为：char str3[] = "c.biancheng.net";
```

更多见**[评论笔记6、11、12、13](https://www.runoob.com/cplusplus/cpp-constants-literals.html)。**

#### 17.7 **指针强制类型转换与[void\* 指针](https://www.runoob.com/w3cnote/c-void-intro.html)**

**指针元素转换讲解：**[C语言指针强制类型转换](https://blog.csdn.net/mhjcumt/article/details/7355127)、[c语言指针强制类型转换的应用](https://blog.csdn.net/j5856004/article/details/78379908)

指针类型的强制类型转换就是**重新告诉**编译器：

1\. 需要从这个地址开始对**多少字节（n）**的数据进行操作, 以及操作模式
2\. 对这个指针进行增减操作时，每加（减）一对应实际地址内存移动的**字节数（n）**

```c
/* 指针转换举例： */
unsigned long int  NUM = 0x12345678;
unsigned long int* pointer3 = NUM;	// 该指针指向从该地址开始一个4字节的内容
// pointer3 = 0xea577ff84d，*pointer3 = 0x12345678
unsigned char* pointer1;			// 该指针指向从该地址开始一个1字节的内容
pointer1 = (char*)pointer3;	        // 强制类型转换
// pointer1 = 0xea577ff84d，*pointer3 = 0x78；
// 注意C语言GCC编译器数据，低位在左高位在右；这个由编译器决定

/* 指针大小展示： */
pointer1++; // 0xea577ff84e
pointer3++; // 0xea577ff851

/* 反向转换也可： */
unsigned int  *pointer3;
unsigned char  ch=0xCC;
unsigned char* pointer1 = &ch; // pointer1 = 0xea577ff84d，*pointer1 = 0xCC
pointer3 = (int*)pointer1;	   // pointer3 = 0xea577ff84d，*pointer3 = 0xFFFBBFCC (后续内存未知，因此为随机值)

/* 整型/浮点转换也可 */
float f = 12.34;        // f = 12.3400002
float *p1 = &f;         // p1 = 0xea577ff84d; *p1 = 12.3400002
int *p2 = (int*) p1;    // p2 = 0xea577ff84d; *p2 = 1095069860(0x414570A4)

/* 结构体不能直接赋值，常用强制类型转换 */
struct str1 a;
struct str2 b;

// a=(struct str1) b;         // 错误，数组不能直接赋值
a=*( (struct str1*)&b );   // 正确，地址可以强制转换
// 也可以直接使用memcpy()内存拷贝函数
memcpy(&a, &b, sizeof(struct str1) );

/* 结构体与数组之间的类型转换 */
struct str1 a;
unsigned char *p = (unsigned char*)&a ;
// 数组本质为首地址确定的指针，因此之后可以使用：p[0], p[1]访问数组成员

// 也可以直接使用memcpy()内存拷贝函数
unsigned char ch[sizeof(struct str1)];
memcpy(ch, &a, sizeof(struct str1) );
```

**补充：void指针：**

**1\.** void 指针可以指向任意类型的数据，就是说可以用任意类型的指针对 void 指针赋值。
如：`int *a;       void *p;      p=a;`      // 合法正确；

但是  void 指针 赋给其他类型的指针，则必须强制类型转换；
如：`int *a;       void *p;     a=（int *）p;` 

**2\. ** ANSI C 标准，不允许对 void 指针进行一些算术运算，如： p++ 或 p+=1 等；
&nbsp;    GNU 系统，认为 **void \*** 和 **char \*** 一样，可以进行一系列算数运算操作，如： p++ 或 p+=1 等。

#### 17.8 野指针

野指针是指向无效内存地址或已释放内存区域的指针。野指针的出现可能导致程序崩溃、数据损坏或不可预测的行为。以下是一些常见的野指针产生情况：

- 未初始化的指针：声明指针变量时未对其进行初始化，导致指针指向一个随机的内存地址。
- 已释放的内存：指针指向的内存区域已经被释放，但没有将指针置为NULL，仍然尝试访问该内存。
- 指针越界：指针在数组或内存块中越过边界，访问了不属于它的内存区域。
- 内存泄漏：连续分配内存而未释放，导致原来的指针丢失，并且无法释放已分配的内存。




### 18. [C typedef](https://www.runoob.com/cprogramming/c-typedef.html)

由**编译器**执行解释，为**数据类型**定义一个新的名字；
**举例：**

```C
typedef unsigned         char  uint8_t;
typedef unsigned short   int   uint16_t;

typedef signed           char  int8_t;
typedef signed short     int   int16_t;

uint8_t temp;       // 等价于  unsigned char temp;
uint16_t count;     // 等价于  unsigned int count;

typedef int * pint;
const pint p1 = &i1;     // 等价于 int * const p1;  *p1 = 1;
pint const p1 = &i1;     // 与上式相同

typedef char Line[81];   // 此时Line类型即代表了具有81个元素的字符数组
Line text;   			 // 等价于char text[81]
````

**typedef 与 #define 对比**
注意：**typedef** 有作用域限制。
见[**正文+评论笔记1、2**](https://www.runoob.com/cprogramming/c-typedef.html)、**[评论笔记7](https://www.runoob.com/cplusplus/cpp-data-types.html)**

**typedef 其他用法**

[**正文+评论笔记3、4**](https://www.runoob.com/cprogramming/c-typedef.html)
PS1：`static int` 不是数据类型，故不可`typedef static int static_int;`
PS2：`typedef char ch;unsigned ch uchar;`错误，`typedef`不是替换！

注意：C语言，`uint8_t`，`int16_t`等等，**包含在` <stdint.h>`库里面**，使用时需要`#include`



### 19. [C enum(枚举)](https://www.runoob.com/cprogramming/c-enum.html)

#### 19.1 枚举的作用

主要是简化了多行 `#define`代码；
如：

```C
#define MON  1
#define TUE  2
...
#define SUN  7      // 使用宏定义

typedef enum
{
	MON=1, TUE, WED, THU, FRI, SAT, SUN   // 使用枚举
} DAY;
```

#### 19.2 枚举的定义

以下程序定义名为 **DAY** 的枚举类型，使用 **DAY** 枚举定义一个名叫 **day** 的枚举变量
```C
// 1、先定义枚举类型，再定义枚举变量
enum DAY
{
      MON=1, TUE, WED, THU, FRI, SAT, SUN
};
enum DAY day;   

// 2、定义枚举类型的同时定义枚举变量
enum DAY
{
      MON=1, TUE, WED, THU, FRI, SAT, SUN
} day;

// 3、省略枚举名称，直接定义枚举变量
enum
{
      MON=1, TUE, WED, THU, FRI, SAT, SUN
} day;

// 4、使用 typedef 定义枚举变量（参照16. typedef讲解）
typedef enum DAYS  // 此处DAYS可省略可换成其他，常省略不加
{
      MON=1, TUE, WED, THU, FRI, SAT, SUN
} DAY;             // 给 enum DAYS 取个别名叫 DAY 
DAY day; 
```

**程序分析：**
定义名为 **DAY** 的枚举类型，使用 **DAY** 枚举定义一个名叫 **day** 的枚举变量
此时 **DAY** 相当于 **int**，**DAY** 定义的变量 **day** 取值为 **{}** 内的值，如: **MON, TUE...SUN** (使用 **MON,TUE...** 代表的数字 **1,2...** 也可以)；

**PS1：**第一个枚举成员的默认值为整型的 0，后续枚举成员的值在前一个成员上加 1，可以在定义枚举类型时改变枚举元素的值。
如：`enum season {spring, summer=3, autumn, winter};`；spring = 0，summer = 3，autumn = 4，winter = 5

**PS2：**枚举类型是被当做 **int** 或者 **unsigned int** 类型来处理的

#### 19.3 枚举的使用

```C
typedef enum
{
      MON=1, TUE, WED, THU, FRI, SAT, SUN
} DAY; 
 
int main()
{
    DAY day;
    day = WED;
    printf("%d",day);    // 输出结果为 3
    return 0;
}
```

**枚举的遍历：**见正文及评论笔记 1、3、**4**、5、6
**枚举在 switch 中的使用：**见正文及评论笔记7
**枚举的直接使用：**评论笔记**2**、**8**



### 20. [C 结构体](https://www.runoob.com/cprogramming/c-structures.html)

C **数组**允许定义相同类型数据项的变量，**结构体**是 C 编程中另一种用户自定义的数据类型，它允许您存储**不同类型的数据项**。
如：图书馆中书本记录表，跟踪书籍 Title、Author、Subject、Book ID 等属性；

#### 20.1 结构体的定义

声明一个名为 **SIMPLE** 的结构体，结构体声明的变量为 **t1,  t2[20],  \*t3**；
结构体内拥有三个变量，分别为 整型的a，字符型的b 和双精度的c；

```C
// 1、先定义结构体名称，再定义结构体变量
struct SIMPLE
{
    int a;
    char b;
    double c;
};
struct SIMPLE t1, t2[20], *t3;
 
// 2、定义结构体类型的同时定义结构体变量
struct SIMPLE
{
    int a;
    char b;
    double c;
} t1, t2[20], *t3;

// 3、省略结构体名称，直接定义结构体变量
struct 
{
    int a;
    char b;
    double c;
} t1, t2[20], *t3;

// 4、使用 typedef 定义结构体变量（参照16. typedef讲解）
typedef struct Simple    // 此处Simple可省略可换成其他，常省略不加
{
    int a;
    char b;
    double c; 
} SIMPLE;
SIMPLE t1, t2[20], *t3;

// 5、使用 typedef 可以同时定义多个别名
typedef struct Simple    // 此处Simple可省略可换成其他，常省略不加
{
    int a;
    char b;
    double c; 
} SIMPLE,SIM,*SIMptr;  // SIMPLE,SIM是结构体的两个别名；SIMptr是结构体指针别名
// 以下两种方法定义变量相同
SIMPLE t1; 
SIM t1;    

SIMptr p1 = &t1;       // 等价于 SIMPLE * p1 = &t1;
```

#### 20.2 结构体初始化

定义时进行初始化

```C
// 方式2
struct SIMPLE
{
    int a;
    char b;
    double c;
} t1 = {10,'C',10.0} ;

// 方式1
typedef struct
{
    int a;
    char b;
    double c; 
} SIMPLE;
SIMPLE t1 = {10,'C',10.0};

// 方式3（C99及以上标准）
typedef struct
{
    int a;
    char b;
    double c; 
} SIMPLE;
SIMPLE t1 = {.a = 10, .b = 'C', .c = 10.0};
```

**注：**不同结构体，即使成员相同，也**不可相互赋值**（类似数组），但是C++可以；但可以**使用结构体指针**，**指向相同的地址**。

#### 20.3 结构体的访问

使用**成员访问运算符**`.`进行访问，如：

```C
struct 
{
    int a;
    char b;
    double c;
} t1;

t1.a = 10;
t1.b = 'C';
t1.c = 10.0;

// 注意！不建议这样子赋值，可能会报错！  实测编辑环境提示错误，但编译成功；   猜测新标准支持，旧标准不支持
t1 = {10,'C',10.0};     
```

#### 20.4 结构体指针

与其他变量的指针类似；**注：**结构的指针访问结构的成员，必须使用 `->` 运算符

```c
struct 
{
    int a;
    char b;
    double c;
} t1 = {10,'C',10.0}, *t2;
t2 = &t1;
t1.a = 20;     // 修改结构体t1中a值为20，(此时t2值跟着修改)
t2->a = 20;    // 修改结构体t2中a值为20，(此时t1值跟着修改)
```

注意：结构体作为变量在函数间的传递，通常使用**指针**。

#### 20.5 结构体中定义指向自身的指针 [(参考1)](https://blog.csdn.net/daheiantian/article/details/6233058)[(参考2)](https://blog.csdn.net/weixin_41262453/article/details/88120561)

结构体的**自引用(self reference)**，就是在结构体内部，包含指向自身类型结构体的指针。
结构体的**相互引用（mutual reference）**，就是说在多个结构体中，都包含指向其他结构体的指针。

**结构体自引用：**

```C
/********** 结构体自引用 **********/
// 错误方式，无线嵌套，非法；
struct tag_1{
    struct tag_1 A;  
    int value;
};
// 正确的方式：（使用指针）
struct tag_1{
    struct tag_1 *A; 
    int value;
};
// 指针指向的是同一类型的不同结构体，这里存储的是 地址 信息，所以不会无限嵌套；

// 当使用typedef时
// 错误方式，因为NODE是别名，在struct结尾才定义，在结构体内部不能使用
typedef struct {
    int value;
    NODE *link; 
} NODE;

// 正确方式
typedef struct tag_1{
    int value;
    struct tag_1 *link; 
} NODE;

struct tag_2;
typedef struct tag_2 NODE;
struct tag_2{
    int value;
    NODE *link;   
};

struct tag_3{
    int value;
    struct tag_3 *link; 
};
typedef struct tag_3 NODE;
```

**结构体相互引用：**

```C
/********** 结构体相互引用 **********/
// 结构体互相包含时，后面定义结构体需提前声明，
struct B;    // 对结构体B进行不完整声明
 
// 结构体A中包含指向结构体B的指针
struct A
{
    struct B *partner;
    //other members;
};
 
// 结构体B中包含指向结构体A的指针，在A声明完后，B也随之进行声明
struct B
{
    struct A *partner;
    //other members;
};
```

#### 20.5 其他

1\. 结构体的内存空间见 **评论笔记1、6、[C 位域 (位域主要讲解结构体所占用空间的分配) ](https://www.runoob.com/cprogramming/c-bit-fields.html)**；

```C
// 典型C位域使用方法
struct bs{
    int b:2;    // b使用2位存储
    int c:6;    // c使用6位存储
}data;
```

2\. 结构体数组见 **评论笔记2、4、5**；
3\. 结构体内存空间占用：**[C语言 | 关于结构体内存对齐，看这篇就够了](https://cloud.tencent.com/developer/article/1703257)**

> 1、第一个成员的首地址为0.
> 2、每个成员的首地址是自身大小的整数倍
> 3、结构体的总大小，为其成员中所含最大类型的整数倍。

```C
#include <stdio.h>

typedef struct t1{
    char x;     // 第一个成员首地址为0
    int y;      // 第二个成员 地址为 int倍数(4)
    double z;   // 第三个成员 地址为 double倍数(8)
}T1;   // 总地址为 最大类型double 倍数 (8)

typedef struct t2{
    char x;     // 第一个成员首地址为0
    double z;   // 第二个成员 地址为 double倍数(8)
    int y;      // 第三个成员 地址为 int倍数(4)
}T2;   // 总地址为 最大类型double 倍数 (8)

int main(int argc, char* argv[])
{
    printf("sizeof(T1) = %lu\n", sizeof(T1));     // 16
    printf("sizeof(T2) = %lu\n", sizeof(T2));     // 24

    return 0;
}
```

**注意：**若使用 *#pragma pack* 宏，则 结构体内存会 紧密对齐。参考讲解：[C语言 | 关于结构体内存对齐，看这篇就够了](https://cloud.tencent.com/developer/article/1703257)、[C语言结构体中\_\_packed 和位段的理解！](https://blog.csdn.net/weibo1230123/article/details/84106028)



### 21. [C 共用体](https://www.runoob.com/cprogramming/c-unions.html)

**共用体**是一种特殊的数据类型，允许您在相同的内存位置存储不同的数据类型。您可以定义一个带有多成员的共用体，但是任何时候**只能有一个成员**带有值。

#### 21.1 共用体的定义

类似之前 枚举，结构体，共四种方式；这里展示其中一种方法：

```C
union Data
{
   int i;
   float f;
   char str[20];
} data;      // 现在，Data 类型的变量可以存储一个整数、一个浮点数，或者一个字符串。
```

#### 21.2 访问共用体成员

使用**成员访问运算符**`.`进行访问，如：

```c
data.i = 10;
data.f = 220.5;      // 此时data.i 值被损毁
strcpy( data.str, "C Programming");      // 此时data.f 值被损毁
```

#### 21.3 其他

共用体的内存空间：共用体占用的内存为所存储的最大值；
详见：正文，评论笔记1、3、5、6、7

共用体的典型应用场景：评论笔记2、4



### 22. [C 内存管理——动态内存分配](https://www.runoob.com/cprogramming/c-memory-management.html)

**内存管理的意义：**数组、基本数据类型、结构体、共用体都是固定的为数据分配内存空间，而内存管理却可以直接申请一块内存，然后给其指定存储的数据类型，之后就可以存储数据了，且还可以**根据数据的大小来扩展内存空间**；

**[内存管理作用](https://blog.csdn.net/weixin_46637351/article/details/125776224)：**主要为代替传统数组；

> **传统数组的缺点:**
>
> 1. 数组的长度必须事先指定，且只能是常整数，**不能是变量**
> 2. 传统形式定义的数组，该数组的内存程序员**无法手动释放，**数组一旦定义，系统位该数组分配的存储空间就一直存在，**直到该函数运行结束，数组的空间才会被系统释放**
> 3. 数组的长度不能在函数运行的过程中**不能动态改变**，一旦定义，**长度不能更改**
> 4. A函数定义的数组，在A函数运行期间可以被其他函数使用，但A函数运行完毕之后，**A** **函数中的数组将无法再被其他函数使用（传统定义的数组不能跨函数使用）**

内存管理函数，可在 **<stdlib.h>** 头文件中找到

| 序号 | 函数和描述                                                   |
| :--- | :----------------------------------------------------------- |
| 1    | **`void *calloc(int num, int size);`** 在内存中动态地分配 num 个长度为 size 的连续空间，并将每一个字节都初始化为 0。所以它的结果是分配了 num\*size 个字节长度的内存空间，并且每个字节的值都是0。 |
| 2    | **`void free(void *address);`** 该函数释放 address 所指向的内存块，释放的是动态分配的内存空间。 |
| 3    | **`void *malloc(int num);`** 在堆区分配一块指定大小的内存空间，用来存放数据。这块内存空间在函数执行完成后不会被初始化，它们的值是未知的。 |
| 4    | **`void *realloc(void *address, int newsize);`** 该函数重新分配内存，把内存扩展到 **newsize**。 |

**实例1：动态内存分配示例**

```C
// 1. void *malloc(int num);    
char *decrp1;
decrp1 = (char *)malloc(200 * sizeof(char));  
// 为description1分配了200*1字节的空间, 并强制转化为char类型指针; 此时decrp1相当于char decrp1[200];

// 2. void *calloc(int num, int size);
char *decrp2;
decrp2 = (char *)calloc(200, sizeof(char));   
// 为description2分配了200*1字节的空间, 且每个字节存储值均为0, 并强制转化为char类型指针; 
// 此时decrp2相当于char decrp2[200] = {0};

//3. void *realloc(void *address, int newsize);
decrp1 = (char *)realloc(decrp1, 100 * sizeof(char));   
// 为decrp1重新分配100*1字节的空间,强制转化为char类型指针; 此时decrp1相当于char decrp1[100]
// 注意重新分配空间，decrp里内容是不会变的

//4. void free(void *address);
free(decrp1);   // 释放decrp1占用内存

// 5. 分配二维数组
// 用malloc动态申请一个二维数组
int (*cc)[4]=(int(*)[4])malloc(sizeof(int)*3*4);     // 直接内存分配强转即可
```

**实例2：一维数组的构造**

```C
int main(int argc, char const *argv[])
{
    int a[5];
    //如果int占4个字节的话，则本数组总共包含有20字节
    //每4个字节被当作了一个int变量来使用
 
    //--------动态创建数组---------
    int len;
    int *pArr;
    printf("请输入你想要存放的元素个数");
    scanf("%d", &len);
    pArr = (int *)malloc(sizeof(int) * len);
    //等价于写了int pArr[len];
    //该数组的数组名是pArr,该数组的每个元素是int类型，长度位len
    //因为它和一维数组的形式非常相似，pArr也存放着第一个元素的地址
    //*pArr指向的是前4个字节 *(pArr+1)指向后4个
    
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &pArr[i]);
    }
 
    //输出数组
    printf("该数组为：\n");
    for (int j = 0; j < len; j++)
    {
        printf("%d\n", *(pArr + j));
    }
    
    free(pArr); //释放掉动态分配的数组
    return 0;
}
```



### 23. **[C 文件读写](https://www.runoob.com/cprogramming/c-file-io.html)**：

**1. 打开文件：**

`FILE *fopen( const char *filename, const char *mode );`
filename 是字符串，用来命名文件，访问模式 mode 的值可以是下列值中的一个：

| 模式 | 描述                                                         |
| :--- | :----------------------------------------------------------- |
| r    | 打开一个已有的文本文件，允许读取文件。                       |
| w    | 打开一个文本文件，允许写入文件。如果文件不存在，则会创建一个新文件。在这里，您的程序会从文件的开头写入内容。如果文件存在，文件内容会被清空（即文件长度被截断为0）。 |
| a    | 打开一个文本文件，以追加模式写入文件。如果文件不存在，则会创建一个新文件。在这里，您的程序会在已有的文件内容中追加内容。 |
| r+   | 打开一个文本文件，允许读写文件。                             |
| w+   | 打开一个文本文件，允许读写文件。如果文件已存在，则文件会被截断为零长度，如果文件不存在，则会创建一个新文件。 |
| a+   | 打开一个文本文件，允许读写文件。如果文件不存在，则会创建一个新文件。读取会从文件的开头开始，写入则只能是追加模式。 |

如果处理的是二进制文件，则需使用下面的访问模式来取代上面的访问模式：
`"rb", "wb", "ab", "rb+", "r+b", "wb+", "w+b", "ab+", "a+b"`

**2. 关闭文件：**

`int fclose( FILE *fp );`
关闭文件，return 0 ；

**3. 写入文件**

`int fputc( int c, FILE *fp );`
函数 **fputc()** 把参数 **c** 的字符值写入到 fp 所指向的输出流中。如果写入成功，它会返回写入的字符

`int fputs( const char *s, FILE *fp );`
函数 **fputs()** 把字符串 **s** 写入到 fp 所指向的输出流中。如果写入成功，它会返回一个非负值

**4\. 读取文件**

`int fgetc( FILE * fp );`
**fgetc()** 函数从 fp 所指向的输入文件中读取一个字符。返回值是读取的字符

`char *fgets( char *buf, int n, FILE *fp );`
函数 **fgets()** 从 fp 所指向的输入流中读取 n - 1 个字符。它会把读取的字符串复制到缓冲区 **buf**，并在最后追加一个 **null** 字符来终止字符串。

**5. 指定读取位置**

`int fseek(FILE *stream, long offset, int whence);`
fseek 设置当前读写点到 offset 处, whence 可以是 SEEK_SET,SEEK_CUR,SEEK_END 这些值决定是从文件头、当前点和文件尾计算偏移量 offset。

PS：以上函数发生错误时返回 **EOF**

```C
/* 综合例程 */
#include <stdio.h>

int main() {
    FILE *file = NULL;
    char buffer[100];  // 缩小缓冲区更直观
    const char *filename = "test.txt";

    // 兼容新旧标准的文件打开方式
    #ifdef _MSC_VER
        if (fopen_s(&file, filename, "w+") != 0) {
            printf("文件打开失败\n");
            return 1;
        }
    #else
        file = fopen(filename, "w+");
        if (file == NULL) {
            printf("文件打开失败\n");
            return 1;
        }
    #endif

    // 写入数据
    if (fputs("第一行内容\n", file) == EOF) {
        printf("写入失败\n");
        fclose(file);
        return 1;
    }
    
    // 写入数据
    if (fputs("第二行内容\n", file) == EOF) {
        printf("写入失败\n");
        fclose(file);
        return 1;
    }

    // 移动文件指针到开头
    if (fseek(file, 0, SEEK_SET) != 0) {
        printf("指针移动失败\n");
        return 1;
    }

    // 读取数据
    printf("文件内容：\n");
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);  // 自动带换行
    }

    // 关闭文件
    if (fclose(file) != 0) {
        printf("文件关闭异常\n");
        return 1;
    }

    printf("\n操作完成\n");
    return 0;
}

/*
文件内容：
第一行内容
第二行内容

操作完成
*/
```



### 24. C语言实例：
**[C 错误处理](https://www.runoob.com/cprogramming/c-error-handling.html)**
**[C 递归](https://www.runoob.com/cprogramming/c-recursion.html)**
**[C 排序算法](https://www.runoob.com/cprogramming/c-sort-algorithm.html)**
**[C 语言实例](https://www.runoob.com/cprogramming/c-examples.html)**
**[C 语言经典100例](https://www.runoob.com/cprogramming/c-100-examples.html)**



### 25. C 头文件：

常用头文件及函数：[C语言常用函数大全](https://www.bilibili.com/video/BV1BMp8ebEwV/)

#### 25.1 **[C 标准库 - <stdlib.h>](https://www.runoob.com/cprogramming/c-standard-library-stdlib-h.html)**
常用库函数：
[void *calloc(size_t nitems, size_t size)](https://www.runoob.com/cprogramming/c-function-calloc.html)     // 动态内存分配用
[void free(void *ptr)](https://www.runoob.com/cprogramming/c-function-free.html)                                    // 动态内存分配用
[void *malloc(size_t size) ](https://www.runoob.com/cprogramming/c-function-malloc.html)                           // 动态内存分配用
[void *realloc(void *ptr, size_t size)](https://www.runoob.com/cprogramming/c-function-realloc.html)          // 动态内存分配用

[void exit(int status)](https://www.runoob.com/cprogramming/c-function-exit.html)                                     // 程序正常终止 
[int system(const char *string)](https://www.runoob.com/cprogramming/c-function-system.html)                  // `system("pause");`

[int abs(int x)](https://www.runoob.com/cprogramming/c-function-abs.html)                                                 // 返回 x 的绝对值
[div_t div(int numer, int denom)](https://www.runoob.com/cprogramming/c-function-div.html)                // 分子除以分母

[int rand(void)](https://www.runoob.com/cprogramming/c-function-rand.html)                                               // 返回一个范围在 0 到 RAND_MAX 之间的伪随机数
[void srand(unsigned int seed)](https://www.runoob.com/cprogramming/c-function-srand.html)                  // `srand((unsigned)time(NULL));`，设置随机数的种子；注意需要`#include <time.h>`

[qsort() 快速排序](https://www.runoob.com/cprogramming/c-function-qsort.html)；
void qsort(void \*base, size_t nitems, size_t size, int (\*compar)(const void \*, const void \*));

**使用：**

```C
#include <stdio.h>
#include <stdlib.h>

// 定义一个包含五个整数的数组
int values[] = {88, 56, 100, 2, 25};

// 比较函数，用于比较两个整数
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main()
{
   // base: 指向待排序数组的第一个元素的指针。
   // nitems: 数组中的元素数量。
   // size: 数组中每个元素的大小（以字节为单位）。
   // compar: 比较函数的指针，该函数用于比较两个元素。比较函数应当返回一个整数，表示比较结果：
   // 		小于零：表示第一个元素小于第二个元素。
   // 		等于零：表示两个元素相等。
   // 		大于零：表示第一个元素大于第二个元素。 
    
   // 使用 qsort 函数对数组进行排序
   qsort(values, 5, sizeof(int), cmpfunc);
}
```




**关于[C的随机数讲解  (评论笔记1、2、3、4、5)](https://www.runoob.com/cplusplus/cpp-numbers.html)**

```C
#include <stdio.h>
#include <stdlib.h>    // 包含函数rand()，srand()；
#include <time.h>      // 包含time；

// rand()生产随机数范围：0~RAND_MAX，
// RAND_MAX和系统有关，window下的RAND_MAX为：0x7fff=2^15-1=32767。linux的RAND_MAX为2^31-1
// 可以过 求余数 限定随机数生成范围 
#define random(x)     (rand()%x)                  // 生成 0~x 之间的随机整数
#define random(min,max)   (rand()%(max-min+1)+min)   // 生成 min~max 之间的随机整数 ，注意此方法随机数概率不同
#define random(min,max)   (int)((double)rand() / (RAND_MAX + 1) * (max - min)+ min)  
// 生成 min~max 之间的 等概率 随机整数；
#define random()      ((double)rand()/RAND_MAX)   // 生成 0~1 之间的随机小数，

int main()
{
   int i;
   
   /* 初始化随机数发生器 */
   srand((unsigned) time(NULL));
 
   /* 输出 0 到 50 之间的 10 个随机数 */
   for( i = 0 ; i < 10 ; i++ ) {
      printf("%d\n", random(50));
   }
   
  return 0;
}
```

#### 25.2 [C 标准库 - <stdio.h>](https://www.runoob.com/cprogramming/c-standard-library-stdio-h.html)

主要是与**输入输出**相关的各种函数，如：
[int scanf(const char \*format, ...)](https://www.runoob.com/cprogramming/c-function-scanf.html)
[int printf(const char \*format, ...)](https://www.runoob.com/cprogramming/c-function-printf.html)

#### 25.3 [C 标准库 - <string.h>](https://www.runoob.com/cprogramming/c-standard-library-string-h.html)

主要是与**字符串**相关函数，如：
[void *memcpy(void *dest, const void *src, size_t n)](https://www.runoob.com/cprogramming/c-function-memcpy.html)               // **字符数组、整型、结构体**等所有类型数据 copy，需要指定长度
[void *memset(void *str, int c, size_t n) ](https://www.runoob.com/cprogramming/c-function-memset.html)                                     // 数组str的前n字节使用字符c填充；**常用于数组&结构体清零**
[void *memmove(void *str1, const void *str2, size_t n)](https://www.runoob.com/cprogramming/c-function-memmove.html)          // 与 `memcpy` 功能相同，不过memmove更安全
[int strcmp(const char \*str1, const char \*str2)](https://www.runoob.com/cprogramming/c-function-strcmp.html)                          // string compare 
[char \*strcat(char \*dest, const char \*src) ](https://www.runoob.com/cprogramming/c-function-strcat.html)                                  // string catenate 
[char \*strcpy(char \*dest, const char \*src) ](https://www.runoob.com/cprogramming/c-function-strcpy.html)                                 // string copy
[size_t strlen(const char \*str)](https://www.runoob.com/cprogramming/c-function-strlen.html)                                                        // string length 

#### 25.4 [C 标准库 - <math.h>](https://www.runoob.com/cprogramming/c-standard-library-math-h.html)

主要是与数学相关函数，如：
[double sin(double x);](https://www.runoob.com/cprogramming/c-function-sin.html)        // 该函数返回弧度角（double 型）的正弦
[double cos(double x);](https://www.runoob.com/cprogramming/c-function-cos.html)       // 该函数返回弧度角（double 型）的余弦
[double tan(double x);](https://www.runoob.com/cprogramming/c-function-tan.html)       // 该函数返回弧度角（double 型）的余弦
[double exp(double x);](https://www.runoob.com/cprogramming/c-function-exp.html)      // 该函数返回以e为底的指数。
[double log(double x);](https://www.runoob.com/cprogramming/c-function-log.html)       // 该函数返回参数的自然对数。
[double pow(double x, double y);](https://www.runoob.com/cprogramming/c-function-pow.html)       // 假设第一个参数为 x，第二个参数为 y，则该函数返回 x 的 y 次方。
[double sqrt(double x);](https://www.runoob.com/cprogramming/c-function-sqrt.html)       // 该函数返回参数的平方根。
[int abs(int x);](https://www.runoob.com/cprogramming/c-function-abs.html)                        // 该函数返回整数的绝对值。
[double fabs(double x);](https://www.runoob.com/cprogramming/c-function-fabs.html)       // 该函数返回任意一个浮点数的绝对值。

#### 25.5 [C 标准库 - <time.h>](https://www.runoob.com/cprogramming/c-standard-library-time-h.html)

**time.h **中定义的四个与时间相关的变量类型：**clock_t、time_t、size_t** 和 **tm**。
**clock_t**  是一个适合存储处理器时间的类型，**time_t** 是一个适合存储日历时间类型。**tm** 是一个用来保存时间和日期的结构体。

```C
struct tm {
   int tm_sec;         /* 秒，范围从 0 到 59        */
   int tm_min;         /* 分，范围从 0 到 59        */
   int tm_hour;        /* 小时，范围从 0 到 23        */
   int tm_mday;        /* 一月中的第几天，范围从 1 到 31    */
   int tm_mon;         /* 月，范围从 0 到 11        */
   int tm_year;        /* 自 1900 年起的年数        */
   int tm_wday;        /* 一周中的第几天，范围从 0 到 6    */
   int tm_yday;        /* 一年中的第几天，范围从 0 到 365    */
   int tm_isdst;       /* 夏令时                */
};
```

主要是与时间相关的函数，如：
[clock_t clock(void)](https://www.runoob.com/cprogramming/c-function-clock.html)                                // 返回程序执行起（一般为程序的开头），处理器时钟所使用的时间。
[time_t time(time_t *timer)](https://www.runoob.com/cprogramming/c-function-time.html)                 // 该函数返回系统的当前日历时间，自 1970 年 1 月 1 日以来经过的秒数
[char *ctime(const time_t *timer) ](https://www.runoob.com/cprogramming/c-function-ctime.html)     // 返回一个当地时间的字符串，字符串形式 *day month year hours:minutes:seconds year\n\0*
[struct tm *localtime(const time_t *timer) ](https://www.runoob.com/cprogramming/c-function-localtime.html)     // 该函数返回一个指向表示本地时间的 tm 结构的指针。
[char *asctime(const struct tm *timeptr)](https://www.runoob.com/cprogramming/c-function-asctime.html)        // 该函数返回一个指向字符串的指针，字符串包含了 time 所指向结构中存储的信息

**举例：**

```C
#include <stdio.h>
#include <time.h>

int main( )
{
    time_t now = time(0);        // 获取当前系统时间
    printf("1970 到目前经过秒数:%ld\n",now);
    
    char* dt = ctime(&now);      // 把 time_t now 转换为字符串形式
    printf("本地日期和时间：%s\n", dt);

    struct tm *ltm = localtime(&now);   // 把 time_t now 转换为 tm 结构
    
    // 输出 tm 结构的各个组成部分
    printf("%d年%d月%d日 \n时间%d:%d:%d:",
           1900 + ltm->tm_year, 1 + ltm->tm_mon, ltm->tm_mday,
           ltm->tm_hour,ltm->tm_min,ltm->tm_sec);
    
    return 0;
}
```

更多内容见：**[C++ 日期 & 时间  评论笔记](https://www.runoob.com/cplusplus/cpp-date-time.html)**


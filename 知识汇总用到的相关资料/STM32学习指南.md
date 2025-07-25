### 1. STM32固件库 / HAL库 相关知识

主要结合 **零死角玩转STM32—F103霸道**

##### **知识划分：**

##### **1\. 软件安装、环境配置、工程建立等基础知识**
**软件安装：**参照：[同时安装keil4 和keil5](https://blog.csdn.net/HeGuang68207/article/details/97679653)；
**程序下载：**第3章  如何用 DAP 仿真器下载程序（注意使用DAP 下载的环境配置）；
&nbsp;                  第4章  如何使用串口下载程序(包括ISP自动下载电路)
&nbsp;   	   		补充：[FlyMcu串口下载&STLINK Utility](https://www.bilibili.com/video/BV1th411z7sn/?p=30)、[STM32 USART1一键下载电路](https://blog.csdn.net/hola_ya/article/details/81323743)
**环境配置：**第3章 3.3 仿真器配置
**工程建立：**第11章 新建工程—库函数版（库函数直接使用工程模板）
**工程文件名修改：**[修改MDK5(keil5)工程文件名称](https://blog.csdn.net/qq_45469653/article/details/119826784)；更改所含项目文件夹，同样在 ‘品’ 图标修改。

**CubeMX安装：**[CubeMX安装方法](.\安装方法.md)
**CubeMX基础操作：[STM32 CubeMx使用教程](https://www.cnblogs.com/jzcn/p/16313803.html)**
**HAL库工程建立：**
① CubeMX导出工程，导出方法参照**[STM32 CubeMx使用教程](https://www.cnblogs.com/jzcn/p/16313803.html)**，内含必须修改外设。( 补充：Code Genertator 选项也需修改 )
② 参照[STM32文件整理](.\STM32文件整理.docx)，文件整理为标准格式；
**HAL库后续外设补充：**
① Core文件夹，新增外设，改名为bsp_xxx.c，bsp_xxx.h，复制至User文件夹，并将bsp_xxx.c添加至工程文档；
② Drivers文件夹，直接复制，重名文件跳过；将Drivers\STM32F1xx_HAL_Driver\Src文件夹下驱动文件全部重新添加至工程文档；
③ stm32f1xx_hal_conf.h，直接使用新生成文件替代旧文件；
④ main.c，stm32f1xx_it.c和stm32f1xx_it.h文件，依据实践情况进行修改；

##### **2\. STM32本身知识**
第5章 初始STM32 **5.3 STM32 怎么选型**
第6章 什么是寄存器，主要讲解**STM32内部结构，内核**
第11章 初识 STM32 标准库 主要讲解**STM32标准库**
HAL库视频第16章 [**HAL库驱动框架简述**](.\HAL库驱动框架简述.emmx)

##### **3\. STM32各个外设知识**
第8、12章(GPIO外设原理、STM32中此外设结构及根据外设编程)，13章，16章及以后；

##### **4\. 编程知识**
**如何只修改寄存器某几位：**第6章  6.5.1 修改寄存器的位操作方法
第12章 12.3 STM32 标准库补充知识
2\. `assert_param();`   // 断言
3\. Doxygen注释规范
4\. `#ifndef __Peripheral_H`，`#define __Peripheral_H`   // 防止头文件重复包含

##### **5\. 软件调试方法**

参照HAL库视频讲解，第16-1讲；[第16-1讲-Debug功能及方法简述（补充章）1\_哔哩哔哩\_bilibili](https://www.bilibili.com/video/BV18X4y1M763/?p=26)
PS：个人认为，还是**串口打印输出调试**方法更好……




#### 几个重要的知识：

**1\.** 程序如何从 **寄存器** 操作变为 **库函数** 操作：
见 **第九章 构建库函数的雏形**，着重去看**四个例程**！；

**2\.** 对于STM32各个外设知识，整体分为**三部分**：
1\. 这个外设工作原理是什么；
2\. 在STM32中，此外设结构是什么；
3\. 如何根据STM32外设结构进行编程。





### 2. STM32 学习 / 编程方法

只需要看使用到的外设即可；
当使用到STM32某外设时，首先明白外设工作原理，包含：

**1\. 外设工作原理是什么；（了解 & 掌握）**
**2\. 在STM32中，此外设结构是什么（尽量了解）**

建议参照**《【野火®】零死角玩转STM32—F103霸道V2.pdf》**进行学习 / 后续**复习**可参照 **江科大** 快速过

之后，进行程序编写**（重要！不少外设原理复杂但实际程序操作简单！注意）**：

**1 学习HAL库例程(同时参考固件库程序及程序逻辑讲解)** **HAL库例程：参考野火 / 正点原子**

**2.1 使用CubeMX初始化程序**
**2.2 初始化后程序，按照野火文件格式整理，并进行程序移植改写**

**<u>学习重点：自己复现 写一遍！</u>**
<u>**学习目标：在CubeMX帮助下，自己可以手敲出完整的代码！**</u>












# 目录
[TOC]



#### Datasheet阅读

[如何快速阅读芯片数据手册（初学者和外行进）\_哔哩哔哩\_bilibili](https://www.bilibili.com/video/BV1Bq4y1Z7yq/)
[芯片数据手册阅读方法总结](.\知识汇总用到的相关资料\Datasheet.emmx)

[【必考】7步读懂芯片数据手册\_哔哩哔哩\_bilibili](https://www.bilibili.com/video/BV1UA411i7Vi)
[《万众一芯》004-芯片的Datasheet 数据手册怎么查询，如何阅读？(1)-Neo\_哔哩哔哩\_bilibili](https://www.bilibili.com/video/BV1nU4y1c7ZR)
[《万众一芯》005-芯片的Datasheet 数据手册怎么查询，如何阅读？(2)-Neo\_哔哩哔哩\_bilibili](https://www.bilibili.com/video/BV1Kb4y187d9)



### PCB相关
#### 0. PCB设计流程（个人向）
* 用户需求 → 系统指标 → 电路指标 → 器件选型 → 建库 → 原理图绘制 → PCB 绘制 → PCB制造 → 器件购买 → PCB贴片 → PCB调试 → 满足指标 → 是（交付）|  否（从出问题处修改）

0. 用户需求分析，系统指标制定，电路指标制定等等；
1. 器件选型 → 下载其原理图库 → 参照**芯片数据手册、开发板**等，**原理图初步连接**；
（先保证 芯片选型、基本连接 不出问题）
2. PCB设计绘制：
   1. 库绘制（原理图库、PCB库）
   2. 原理图连接
      注意：**1. 先保证使用；2. 在保证美观**
   3. PCB 布置
      按照自己经验进行布置；
      在器件摆放、连线等阶段，**也先按照经验布置，之后再看相关布置、连线规则检查，对其进行修改；**
      **（一定注意器件摆放阶段！不能着急！一旦摆错后期修改成本很大！）**
3. PCB制造 → 器件购买 → PCB贴片 → PCB调试 ……

* <u>实际PCB设计，有点类似数学题，只有不断尝试，不断练习，才可以不断提升经验，设计速度，熟练度，在重复中不断进步。</u>



#### 1. PCB相关知识
[PCB的相关知识](.\知识汇总用到的相关资料\PCB的相关知识.md)



#### 2. PCB的绘制
**1. 教程视频**
[【完结】极简PCB绘制教程 小白友好 0基础速进 基于Altium\_哔哩哔哩\_bilibili](https://www.bilibili.com/video/BV1d44y1b7Cc)
[Altium Designer 20 19（入门到精通全38集）四层板智能车PCB设计视频教程AD19 AD20 凡亿\_哔哩哔哩\_bilibili](https://www.bilibili.com/video/BV16t411N7RD)
[**【免费首发】Altium Designer 21最小系统板电子设计全流程实战教程（共54集全）\_哔哩哔哩\_bilibili**](https://www.bilibili.com/video/BV1eo4y1R7rm)
[**Altium Designer 21教学PPT**](.\知识汇总用到的相关资料\Altium Designer 21（中文版）电子设计速成宝典-教学PPT)

**2. 总结文档**
[建库→原理图绘制](.\知识汇总用到的相关资料\PCB的绘制.part1.emmx)
[**PCB 绘制**](.\知识汇总用到的相关资料\PCB的绘制.part2.md)



#### 3. PCB的加工制作
[PCB的加工制作](.\知识汇总用到的相关资料\PCB的加工工艺.md)



#### 仪器设备使用
##### 各种测试工具：
**示波器**
[5款电子人必须掌握的【硬件测试工具】：示波器/电源/信号发生器/频谱仪/万用表](https://www.bilibili.com/video/BV1sb4y127fh)

##### 焊接：
**[焊接经验技巧讲解(包括回流焊)](.\知识汇总用到的相关资料\焊接经验技巧讲解.md)**

##### PS: 元器件的失效机理
[【经验分享】元器件失效机理有哪些 ](https://mp.weixin.qq.com/s?__biz=Mzk0MDMwMjc0Nw==&mid=2247484448&idx=1&sn=907d04705dd35ceb0810b68c3a2502ca&chksm=c2e28cd4f59505c289d3de8eed1c4068f507a50abb2fe5db4d4e861051fba9af280400751c1f)



#### 芯片购买
**比较靠谱的：**
[立创商城  **很靠谱 优先选择**](https://www.szlcsc.com/)
[淘宝 **几乎什么器件都有，但不很靠谱，注意一定要咨询客服！**](https://ai.taobao.com/)
PS：推荐几家店铺：深圳市莱纬创电子，深圳市弘创微电子，红茂电子(电阻电容)

**海外代购网站**
立创商城搜芯片下方也会出现该网站
[贸泽电子](https://www.mouser.cn/)
[得捷电子](https://www.digikey.cn/)
[e络盟电子](https://cn.element14.com/)

**不知道靠不靠谱：**
[华强电子网](https://www.hqew.com/)
[百度爱采购](https://b2b.baidu.com/)


# 0. 学习之前：

Qt 的运用本质上依赖于 **C++** 能力，而非 Qt 框架本身。所以，在着手学习 Qt 之前，对 **C++** 进行透彻、深入的学习是必不可少的前提。



#  1. QT核心语法教程 ：

### 1. 界面设计

讲解(PPT)参考：[界面设计.pptx](QT学习\界面设计.pptx) 
讲解(图片)参考： [图片](QT学习\图片) 



### 2. 信号与槽

##### 一、基本概念

1\. 什么是信号与槽

- **信号(Signal)**：当对象内部状态发生改变时发出的通知
- **槽(Slot)**：响应信号的普通成员函数，可以像普通函数一样被调用

2\. 为什么需要信号与槽

- 替代传统GUI编程中的回调函数机制
- 解决回调函数的类型不安全问题
- 降低对象间的耦合度
- 提供更灵活的事件处理方式

##### 二、基础使用要求
- 类必须继承自`QObject`
- 类定义中必须包含`Q_OBJECT`宏
- 项目文件(.pro)中需包含`QT += core`

#### 三、信号与槽的使用

**0\. 基本定义**

`connect(sender, &Sender::signalName, receiver, &Receiver::slotName);`
`sender`对象的`&Sender::signalName`函数被触发，跳转到`receiver`对象的`&Receiver::slotName`函数执行相应的操作

##### 方法1：直接在UI界面中实现

![幻灯片21](.\QT学习\图片\幻灯片21.PNG)

如图所示，简单的 信号与槽 可以在设计界面实现；
**发送者**发送**信号**，**接收者**执行相应的**槽函数**操作

**发送者**和**接收者**是界面的各种控件，如图中右上方对象树的各种控件；
**发送的信号**一般是控件的状态改变信号，如按钮按下/文本更新等操作；
执行**槽函数**是控件自带槽函数，如控件隐藏/显示等操作；

此方法**优点**是简单，**缺点**是性能受限，仅能实现简单的信号/槽操作

**本质**：在`ui_×××.h`中添加`connect`函数

```C++
QObject::connect(btnOK, SIGNAL(clicked()), QWDialog, SLOT(accept())); 
QObject::connect(btnCancel, SIGNAL(clicked()), QWDialog, SLOT(reject()));
QObject::connect(btnClose, SIGNAL(clicked()), QWDialog, SLOT(close()));
```

##### 方法2：右键单击对象，执行跳转到槽函数操作

![幻灯片22](.\QT学习\图片\幻灯片22.PNG)

![幻灯片23](.\QT学习\图片\幻灯片23.PNG)

如图所示，右键单击对象，选择转到槽，选择相应的对象后，之后会在`.cpp`文件中添加以下内容：

```C++
void QWDialog::on_btnOK_clicked()   // OK按键被按下，执行函数内的内容
{
}
void QWDialog::on_chkBoxBold_clicked(bool checked)   // bold框被按下，执行函数内的内容
{ 
}
```

**发送者**和是界面的各种控件，如图中右上方对象树的各种控件；
**发送的信号**一般是控件的状态改变信号，如按钮按下/文本更新等操作；

**接收者**是this指针，也就是这个widget，**槽函数**自行定义
由于**接收者**是this指针，在**槽函数**中，与这个widget相关的任何对象（如widget里面的按钮/文本框/自身）都可以使用；

此方法**优点**是较为简单，且**自定义程度较高**；**缺点**是**函数名**必须匹配，函数名写错则无法进行匹配；

**本质**：通过`ui_×××.h`中的`QMetaObject::connectSlotsByName(QWDialog);`函数被调用；
`connectSlotsByName`会根据函数名进行匹配，匹配到`on_对象名_信号()`时，就会执行相应的槽函数操作；

##### 方法3：自行定义信号/自行定义槽函数/自行发送信号

**1\. 定义信号与槽：**

```C++
class MyClass : public QObject
{
    Q_OBJECT  // 必须包含此宏

public:
    explicit MyClass(QObject *parent = nullptr);
    
signals:
    void valueChanged(int newValue);  // 信号声明
    void dataReady(const QString &data, int id);
    
public slots:
    void handleValueChanged(int value);  // 公有槽
    void updateStatus(const QString &status);
    
private slots:
    void onInternalEvent();  // 私有槽
};
```

**2\. 连接信号与槽：**

```C++
// Qt5风格，执行速度快，推荐
connect(sender, &Sender::signalName, receiver, &Receiver::slotName);
// 示例：
connect(button, &QPushButton::clicked, this, &MainWindow::buttonClicked);
connect(this, &MainWindow::buttonClicked, statusBar, &QStatusBar::showMessage);

// Qt4风格，试用于信号/槽函数重载的情况，执行速度慢
connect(sender, SIGNAL(signalName()), receiver, SLOT(slotName()));
// 示例：
connect(button, SIGNAL(clicked()), this, SLOT(buttonClicked()));
connect(this, SIGNAL(buttonClicked(const QString &)), statusBar, SLOT(showMessage(const QString &)));
```

**3\. 发出信号：**

```C++
emit signal();
// 示例：
emit valueChanged(newValue);  // 发出信号
```

此方法**优点**是最为灵活，可以**自定义对象/自定义信号**；**缺点**是实现较为复杂；
自定义函数只能使用此方法；

**注意1：**
**槽函数**可以是**匿名(Lambda)函数**

```C++
connect(button, &QPushButton::clicked, this, [=]() {
    qDebug() << "Button clicked at" << QTime::currentTime();
    // 可以捕获外部变量
    processValue(capturedValue);
});
```

当Lambda**不捕获任何变量**或者**只捕获值类型变量**，可以省略`this`；
当Lambda**捕获了`this`**或者**调用成员函数**，不可以省略`this`；

**注意2：**信号与槽的参数匹配规则

- 信号的参数数量 ≥ 槽的参数数量，多余的信号参数会被忽略
- 参数类型必须兼容（可隐式转换）

**注意3：**当信号或槽有重载时，需明确指定

```C++
// 方法1：使用QT4风格，如：
connect(button, SIGNAL(toggled(bool)), this, SLOT(handleToggled(bool)));

// 方法2：使用qOverload
// qOverload<参数类型1, 参数类型2, ...>()
// 通过指定参数类型来明确选择特定的重载版本
// 需包含 <QOverload> 头文件
connect(button, qOverload<bool>(&QPushButton::toggled),
        this, qOverload<bool>(&MyClass::handleToggled));

// 方法3：使用函数指针
void (MyClass::*handler)(bool) = &MyClass::handleToggled;
connect(button, &QPushButton::toggled, this, handler);
```



### 3. QDebug()

```C++
#include <QDebug>

qDebug() << "Hello World";          // 普通调试信息，注意会自动在末尾添加'\n'
// 更多输出方法建议直接问AI
```



# 2. QT其他语法参考：

由于 Qt 的 API 接口函数极为丰富，直接使用时很容易陷入混乱。此前没有 AI 辅助，只能依赖 F1 快捷键调取英文参考文档查询，过程繁琐；而如今 AI 的出现改变了这一状况，无需再为 API 接口发愁，只要明确功能需求，向豆包等 AI 工具咨询即可。



# 3. QT的安装：

参考：Qt5.9 c++开发指南



# 4. QT教程参考：0. 我的QT学习

**文件地址**：[QT学习](.\QT学习)


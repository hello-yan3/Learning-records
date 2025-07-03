# 1. 视频教程

[『教程』简单明了的Git入门](https://www.bilibili.com/video/BV1Cr4y1J7iQ?spm_id_from=333.788.videopod.sections&vd_source=74420e655b8d1b39201d1080d78ddb75)——了解
[给傻子的Git教程](https://www.bilibili.com/video/BV1Hkr7YYEh8)——了解

**[【GeekHour】一小时Git教程](https://www.bilibili.com/video/BV1HM411377j/)——主要参照**

[Git - Reference](https://git-scm.com/docs)——官方参考手册

# 2. Git命令合辑

**建议找到图片地址打开：**

![Git-Cheet-Sheet-ByGeekHour](.\Git学习指南\Git-Cheet-Sheet-ByGeekHour.png)

![GitCheatSheet_byGeekHour_v1.0.0_page-0001](.\Git学习指南\GitCheatSheet_byGeekHour_v1.0.0_page-0001.jpg)

其他常见语言命令：
```
mkdir learn-git     // 在当前目录下新建一个 learn-git 文件夹
cd learn-git        // 终端切换至当前路径下的 learn-git 文件夹
cd ..               // 返回到根目录（上一个文件夹）
ls                  // 展示当前目录下的 非隐藏文件
ls -a               // 展示当前目录下的所有文件
ls -al              // 展示当前目录下的所有文件
\rm -rf .git        // 删除 当前目录下的 .git 文件夹
rm file1.txt        // 删除 当前目录下的 file1.txt 文件
echo "这是第一个文件" > file1.txt    // 创建 file1.txt，同时向其中添加 这是第一个文件 文本内容
cat file1.txt      // 输出 file1.txt 文件内的内容
```



# 3. 讲解及实操

### 3.2 Git安装及初始化

1\. 打开终端——右键：Open GitBashhere
2\. 第一次使用，需要：配置 用户名/邮箱

初始化设置用户名和邮箱：

```
git config --global user.name "Your Name"
git config --global user.emaill "email@mail.com"
```

### 3.3 新建仓库

```
git init <project-name>   // 创建一个新的本地仓库（省略project-name则在当前目录创建) 
git init my-repo          // 创建一个新的本地仓库，在当前目录下的 my-repo 文件夹

git clone <url>           // 下载一个远程仓库 
```

##### VsCode操作：
使用VsCode创建：直接点击：**初始化仓库** 即可。
![1](.\Git学习指南\图片\1.png)

### 3.4 工作区/暂存区/本地仓库

![2](.\Git学习指南\图片\2.png)

![3](.\Git学习指南\图片\3.png)

### 3.5 添加和提交文件

```
git init       // 创建仓库，使用方法参照3.3
git status     // 查看仓库的状态，直接命令行输入即可
git add        // 添加到暂存区
  git add file1.txt    // 提交 file1.txt 文件
  git add .    // 提交 所有文件
  git add *.txt   // 提交 所有.txt文件
git commit     // 提交
  git commit -m "这里输入提交时的信息"     // 注意这里只提交暂存区文件
  git commit -am "这里输入提交时的信息"    // 注意提交所有已修改文件
git log        // 查看提交记录
git log --oneline    // 查看提交记录
git ls-files         // 查看仓库中的文件
git log --oneline --graph --decorate --all     // 图形化显示所有分支
```

##### VsCode操作：
点击 + ，进入暂存区
![4](.\Git学习指南\图片\4.png)![5](.\Git学习指南\图片\5.png)

后面的 M/U 等等，代表当前状态，参照：3.4 工作区/暂存区/本地仓库

在上方 消息 处，输入 "这里输入提交时的信息" ，之后点击提交，即可完成提交操作；
（默认 只提交暂存区文件，如果暂存区无内容，此时会提交所有已修改文件）

### 3.6 回退版本/查看不同版本差异/删除文件

1\. 不同版本ID指代：

```
// 方法1：使用 git log --oneline 获取各版本ID，之后进行相应对比
// 方法2：使用HEAD进行指代，如：HEAD 表示当前版本，HEAD~ 上1个版本，HEAD~2 上2个版本
```

2\. 回退版本

```
git reset --soft  <commit_hash>    // 回退某版本，同时保留 工作区/暂存区 所有内容
git reset --hard  <commit_hash>    // 回退某版本，同时丢弃 工作区/暂存区 所有内容
git reset --mixed <commit_hash>   // 回退某版本，同时保留 工作区 所有内容，丢弃 暂存区 所有内容。mixed 为默认参数
// 这里 <commit_hash> 指的是 要回退到的 版本ID
```

人话：都是回退版本，"soft"和"mixed"回退之后，后面的修改仍然保留；二者区别，"soft"回退，修改后内容还在暂存区中；"mixed"回退，修改后内容不在暂存区，需要重新提交后才在暂存区。"hard"回退，丢失所有修改记录。

"hard"回退，一般是出现严重错误，丢弃所有后面修改内容；
"soft"和"mixed"回退类似，常用功能为去除多次小修改；使用"soft"回退到某一靠前版本，然后一次性提交所有修改。

VsCode暂未发现如何回退；

3\. 查看不同版本差异

```
git diff          // 查看当前 工作区 / 暂存区 中的区别
git diff HEAD         // 查看当前 工作区 / 本地仓库 中的区别
git diff --cached     // 查看当前 暂存区 / 本地仓库 中的区别
git diff <commit_hash> <commit_hash>    // 比较提交之间的差异
git diff HEAD~ HEAD                     // 比较提交之间的差异
// 注意：<commit_hash>指的是 要回退到的 版本ID
```

##### VsCode操作：
直接双击修改后的文件即可，左修改前/右修改后，简单直观！！！
![6](.\Git学习指南\图片\6.png)

4\. 删除文件

最简单方法，直接删除文件（删除/移动回收站），之后暂存文件，最后提交文件。

### 3.9 gitignore文件

git + ignore，那这个文件的作用也就是可以让我们忽略掉一些不应该被加入到版本库中的文件；

##### gitignore文件的匹配规则

```
：空行或者以#开头的行会被Git忽略。一般空行用于可读性的分隔，#一般用作注释
使用标准的Blob模式匹配，例如：
    星号＊通配任意个字符
    问号？匹配单个字符
    中括号［]表示匹配列表中的单个字符,比如：[abc] 表示a/b/c
两个星号**表示匹配任意的中间目录
中括号可以使用短中线连接，比如:
    [0-9] 表示任意一位数字,[a-z]表示任意一位小写字母
感叹号！表示取反
```

**示例：**

```
# 忽略所有的·a文件
*.a

# 但跟踪所有的lib.a，即便你在前面忽略了.a文件
!lib.a

#只忽略当前目录下的 TODO 文件，而不忽略子目录下的TODO文件 
/TODO

# 忽略任何目录下名为 build 的文件夹
build/

# 忽略 doc/notes.txt，但不忽略 doc/server/arch.txt
doc/*.txt

# 忽略doc/目录及其所有子目录下的·pdf文件
doc/**/*.pdf
```

C语言常见模版：PS：参考[Github项目](https://github.com/github/gitignore/blob/main/C.gitignore)，搜索[C.gitignore](https://github.com/github/gitignore/blob/main/C.gitignore)  

### 3.11 GitHub远程仓库操作

首先在Github上，创建一个仓库，不要添加任何文件；	以下为Github提示信息：

**在命令行上创建一个新的仓库：**

```3
echo "# linyigecesh" >> README.md
git init
git add README.md
git commit -m "first commit"
git branch -M main
git remote add origin https://github.com/hello-yan3/linyigecesh.git
git push -u origin main
```

**从命令行中推送现有的仓库：**

```
git remote add origin https://github.com/hello-yan3/linyigecesh.git
git branch -M main
git push -u origin main
```

**1\. 将本地仓库和远程仓库关联在一起：**
方法1：远程仓库克隆至本地，

```
git clone https://github.com/hello-yan3/linyigecesh.git     // 远程库克隆到本地
```

方法2：本地仓库关联至远程，

```
git remote add origin https://github.com/hello-yan3/linyigecesh.git   // 使用提示命令就好！
// git remote add <shortname> <url>     // origin为远程仓库名字，可修改
git remote -v   // 查看远程仓库别名以及地址
git push -u origin main      // 把远程仓库的origin分支和本地仓库的main分支合并
// git push -u origin master      // 把远程仓库的origin分支和本地仓库的master分支合并
```

**2\. 仓库间的同步：**

```
// 缩略版
git pull     // 远程仓库修改内容合并至本地仓库
git push     // 本地仓库修改内容提交至远程仓库
// 完整版
git push -u origin main      // 把远程仓库的origin分支和本地仓库的main分支合并
git pull origin main         // 把本地仓库的main分支和远程仓库的origin分支合并
```

##### VsCode操作

首先在Github上，创建一个仓库，不要添加任何文件；

然后，添加远程存储库，

![7](.\Git学习指南\图片\7.png)

之后，选择要添加的远程仓库

![8](.\Git学习指南\图片\8.png)

![9](.\Git学习指南\图片\9.png)

然后输入远程仓库名称：

![10](.\Git学习指南\图片\10.png)

此时 远程仓库与本地仓库创建关联

最后点击 同步更改，即可完成 远程仓库上传（执行`git push`操作）；

![11](.\Git学习指南\图片\11.png)
左侧拉取，即为`git pull`操作，右侧推送，即为`git push`操作（上面的同步更改）
![12](.\Git学习指南\图片\12.png)

### 3.16 分支

``` 
git branch     // 查看仓库中的所有分支
git branch <branch-name>    // 创建分支
  git branch dev    // 创建一个叫做 dev 的分支
git checkout <branch-name>  // 切换分支
git witch <branch-name>     // 切换分支
  git checkout dev   // 切换至 dev 分支
  git switch dev     // 切换至 dev 分支（新版本语法）
git merge <branch-name>   // 合并<branch-name>分支到当前分支中
  git merge dev    // 合并dev分支到当前分支(比如main/master分支)中
git branch -d <branch-name>   // 删除<branch-name>分支，只能删除已合并分支
git branch -D <branch-name>   // 删除<branch-name>分支
```

##### VsCode操作

分支可视化（在此处选择要看的分支）：

![15](.\Git学习指南\图片\15.png)

创建分支：

![13](.\Git学习指南\图片\13.png)

切换分支：

![14](.\Git学习指南\图片\14.png)

合并分支：

![16](.\Git学习指南\图片\16.png)

选择要合并的分支即可：

![17](.\Git学习指南\图片\17.png)

如果发生合并冲突：

![18](.\Git学习指南\图片\18.png)

点击，在合并编辑器中解析；然后，手动完成合并操作后，点击 完成合并；

![19](.\Git学习指南\图片\19.png)

##### 变基操作
 
![20](.\Git学习指南\图片\20.png)

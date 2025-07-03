**VSCode安装，配置C/C++，配置Python，配置QT，主要参考这个，一个超级详细的讲解视频**
[VSCode 搭建多语言环境（超级详细）\_哔哩哔哩\_bilibili](https://www.bilibili.com/video/av465295465)



**配置C/C++**
[VSCode 搭建多语言环境（超级详细）\_哔哩哔哩\_bilibili](https://www.bilibili.com/video/av465295465)

安装：MinGW
安装插件：C/C++ Extension Pack

.vscode文件夹
launch.json

```c
{
    // 使用 IntelliSense 了解相关属性。 
    // 悬停以查看现有属性的描述。
    // 欲了解更多信息，请访问: https://go.microsoft.com/fwlink/?linkid=830387
    "version": "0.2.0",
    "configurations": [
        {
            "name": "g++.exe - 生成和调试活动文件",
            "type": "cppdbg",  // 配置类型，只能为cppdbg
            "request": "launch",  // 请求配置类型，可以为launch（启动）或attach（附加）
            "program": "${fileDirname}\\${fileBasenameNoExtension}.exe",  // 调试程序的路径名称
            // "program": "${command:cmake.launchTargetPath}",  // 多文件Cmake使用
            "args": [],  // 调试传递参数
            "stopAtEntry": false,
            "cwd": "${fileDirname}",
            "environment": [],
            "externalConsole": false,  // true显示外置的控制台窗口，false显示内置终端
            "MIMode": "gdb",
            "miDebuggerPath": "D:\\Software\\MinGW-w64 9.0.0\\MinGW64\\bin\\gdb.exe",
            "setupCommands": [
                {
                    "description": "为 gdb 启用整齐打印",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                },
                {
                    "description": "将反汇编风格设置为 Intel",
                    "text": "-gdb-set disassembly-flavor intel",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "C/C++: g++.exe 生成活动文件"   // 调试前执行的任务，就是之前配置的tasks.json中的label字段  使用Cmake注释掉这句话即可
        }
    ]
}
```
tasks.json
```c
{
    "tasks": [
        {
            "type": "cppbuild",
            "label": "C/C++: g++.exe 生成活动文件",  // 与launch.json中的preLaunchTask字段相同
            "command": "D:\\Software\\MinGW-w64 9.0.0\\MinGW64\\bin\\g++.exe",
            "args": [
                "-fdiagnostics-color=always",
                "-g",  // 添加gdb调试选项
                "${file}",
                "-o",  // 指定生成可执行文件的名称
                "${fileDirname}\\${fileBasenameNoExtension}.exe"
            ],
            "options": {
                "cwd": "${fileDirname}"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "detail": "调试器生成的任务。"
        }
    ],
    "version": "2.0.0"
}
```

注意所有文件 / 文件夹路径 不能有中文！



配置多文件 Cmake
创建：CMakelists.txt

```python
project(test)                                          # 项目名称

aux_source_directory(./src SRCS)                       # 编译./src内的所有文件

add_executable(${PROJECT_NAME} ${SRCS})                # 被 project name ，.src/所有文件.c 替换掉
```

在下方选择 GCC 编译器 ，Debug模式 (或者 release 模式)，Build；

注意如果还出什么问题，重新打开VSCode刷新一下 （Cmake文档加减空格刷新等等）



**配置 Keil** 
[Keil+vscode合作 ，摆脱keil不友好的界面\_哔哩哔哩\_bilibili](https://www.bilibili.com/video/av673176183)

安装插件：C/C++ Extension Pack 
安装插件：Keil Assistant

打开插件 Keil Assistant 细节，看插件操作说明，按操作说明配置即可

settings.json 路径： C:\Users\86134\AppData\Roaming\Code\User
settings.json 文件里面内容

```c
{
    "KeilAssistant.C51.Uv4Path": "D:\\Software\\Keil\\keil 5 for ARM\\install\\UV4\\UV4.exe",
    "KeilAssistant.MDK.Uv4Path": "D:\\Software\\Keil\\keil 5 for ARM\\install\\UV4\\UV4.exe",
    "files.autoGuessEncoding": true,
    "bracketPairColorizer.depreciation-notice": false,
    "workbench.colorTheme": "Quiet Light"
}
```



**配置 Python (Anaconda)**
[VSCode 搭建多语言环境（超级详细）\_哔哩哔哩\_bilibili](https://www.bilibili.com/video/av465295465)

[ANACONDA使用参考（WIN版）\_FastAPIyes的博客-CSDN博客\_anaconda使用参考](https://blog.csdn.net/weixin_43605788/article/details/104152011)
[Anaconda使用IDLE_Jerry不认识Tom的博客-CSDN博客_anaconda中idle](https://blog.csdn.net/qq_32119243/article/details/80017010)

安装：Anaconda
安装插件：Python && Pylance && Python Environment Manager

直接Run，系统自动寻找 Pyhon 开发环境
PS：左下角 (或者右下角) 可以选择Python编辑器

之后在launch.json里选择 Cmake



配置 **MATLAB**
[VScode运行MATLAB（最正确版本） - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/113231869)

安装：Code Runner && Matlab Extension Pack

```matlab
{
	"editor.fontSize":20,
	"files.associations": {
		"*.m" : "matlab"
	},
	"[matlab]": {
		"files.encoding" : "gb2312"
				},
				"code-runner.runInTerminal": true,
	"matlab.matlabpath": "D:\\Software\\MATLAB\\install\\bin\\matlab.exe",
	"matlab.mlintpath": "D:\\Software\\MATLAB\\install\\bin\\win64\\mlint.exe",
	"matlab.linterEncoding": "GB 2312",
	"code-runner.executorMap" :{
		"matlab": "cd $dir && matlab -nosplash -nodesktop -r $fileNamewithoutExt"
}
```

之后只能使用 CodeRunner 运行

实际建议在VSCode里面书写 (因为该有的语法提示都有) ，在 Matlab 里运行






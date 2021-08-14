# 1.创建工作文件(create a project)

(本工作终端或者 VScode 终端)Terminal 中创建 projects
projects 中创建子文件夹 helloworld

```
mkdir projects
cd projects
mkdir helloworld
cd helloworld
code .
```

> code.

此命令在当前工作文件夹中打开 vscode，于是该文件夹成为您的“工作区”_workspace_

# 2. 添加工作文件源代码(adding source code)

##新建 File 命名为.cpp

![见本图](../2021-08-13-17-01-40.png)

按 Ctrl + s 来保存文件。文件列在文件浏览器视图(Ctrl + Shift + e)的 VS 代码边栏中（File 中已经勾选自动保存）

最左侧是*The Activity Bar*活动栏：搜索,源代码管理*source control*,运行*run*,扩展*extension* \*保存或打开文件时可能会弹出 a notification from the C/C++ extension about the availability of an Insiders version 内部版本可用性通知，直接点 × 即可

# 3.常用词

- _IntelliSense_ 感知智能
- _variable_ 变量
- _vector_ 向量
- _type information_ 类型信息
- _calling a member function_ 调用成员函数
- _shell_ 壳，类似于 cmd.exe。它接收用户命令，然后调用相应的应用程序
- 悬停在 msg(结构体)，会显示各个成员函数？？

# 4.构建 cpp(build)

## 等于 task.json 0-1

作用：==executable file 0-1 based on the source code==
步骤：

1. 打开此 cpp，形成活动文件 activate file
2. Terminal > Configure Default Build Task
   _终端配置默认构建任务_
   选择 g++工具
3. task.json 建好了

```cpp
{
"version": "2.0.0",
"tasks": [
 {
   "type": "shell",
   "label": "g++ build active file",
   "command": "/usr/bin/g++",
   "args": ["-g", "${file}", "-o", "${fileDirname}/${fileBasenameNoExtension}"],
   "options": {
     "cwd": "/usr/bin"
   },
   "problemMatcher": ["$gcc"],
   "group": {
     "kind": "build",
     "isDefault": true
   }
 }
]
}
```

里面具体的命令作业是把==args==里面的 arguments 参数传给 g++，并且运行 g++ ，顺序也是指定的

这个任务 Configure Default Build Task 告诉 g + + 获取活动文件(${ file }) ，编译它，然后在工作目录文件夹(${ fileDirname }) 中创建一个可执行文件 ，名称与活动文件相同，==但没有扩展名==(${ filebasicenoextension }) ，这就是我们的例子中的 helloworld

==label==就是在任务列表中的任务名，想改成啥都可

==“ isDefault”: true value==指定当您按下 Ctrl + Shift + b 时将运行此任务。此属性仅为方便，false 不用快捷键可以在 T 菜单中打开 run task

# 4. 运行构建（run the build）

要运行 tasks. json 中定义的构建任务，请按 Ctrl + Shift + b 或从终端主菜单中选择 Run Build Task

运行 TASK 以后，*the Integrated Terminal panel*集成终端面板出现在下方，点击+增加新终端

这样将拥有一个运行默认 shell 的终端，helloworld 文件夹作为工作目录文件夹。运行 ls，您现在应该看到==可执行的 helloworld (没有文件扩展名)==
![终端显示如图](../2021-08-14-13-53-50.png)

输入./helloworld （目录名/文件名）在终端中运行 helloworld

**构建多个可执行文件方法：**
task. json 中修改
"args": ["-g", "${file}", "-o", "${fileDirname}/${fileBasenameNoExtension}"]
"${workspaceFolder==工作文件夹名==}/*.cpp" instead of ${file}. You can also modify the output filename by replacing "${fileDirname}/${fileBasenameNoExtension}" with a hard-coded filename (for example 'helloworld.out')

# 5.调试（Debug）

## 等于创建一个 launch.json 文件，以便按 F5 运行

在主菜单中，选择 Run > Add Configuration 添加配置 然后选择 c + + (GDB/LLDB)

```C++
{
  "version": "0.2.0",
  "configurations": [
    {
      "name": "g++ build and debug active file",
      "type": "cppdbg",
      "request": "launch",
      "program": "${fileDirname}/${fileBasenameNoExtension}",
      // 与.cpp同名的无扩展名文件
      "args": [],
      "stopAtEntry": false,
      // 默认情况下，c + + 扩展不会向源代码添加任何断点，而 stopAtEntry 值设置为 false
      //将 stopAtEntry 值更改为 true，以便在开始调试时使调试器在 main 方法上停止
      "cwd": "${workspaceFolder}",
      "environment": [],
      "externalConsole": false,
      "MIMode": "gdb",
      "setupCommands": [
        {
          "description": "Enable pretty-printing for gdb",
          "text": "-enable-pretty-printing",
          "ignoreFailures": true
        }
      ],
      "preLaunchTask": "g++ build active file",
      "miDebuggerPath": "/usr/bin/gdb"
    }
  ]
}
```
# 6.启动调试会话（Start a debugging session）
按F5或run里启动调试

编辑器突出显示 main 方法中的第一条语句。这个断点是 c + + 扩展自动为你设置的

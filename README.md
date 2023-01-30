# Snake_Game
It is a real program based on C language.
Hope everyone enjoy this program and make friends here!

The recommended compile process is listed below. 

For windows: 

1. 编译

1.1 搭建编译环境
	
  1. 安装vscode， 然后在vscode中安装插件：
		
    1. C/C++
		2. C/C++ Extension Pack
		3. CMake
		4. CMake Language Support  
		5. CMake Tools 
    
	2. 安装MinGW编译工具, 并配置环境变量
  
		1. 安装gcc工具 
		2. 安装g++工具
		3. 安装gdb 工具
    
	3. 安装cmake 工具, 并配置环境变量
  
	4. 测试MinGW编译工具和cmake 工具的安装状态。
  
		打开一个终端 （win + r 输入 cmd）
![image](https://user-images.githubusercontent.com/106960367/215380021-2808b6ea-1624-4185-8158-5d32908794f9.png)

如果出现各个软件的对应版本信息，则说明安装正确。

1.2 编译方法一（基于命令编译项目）：不推荐

	cd <项目文件夹>
	gcc main.c ./src/*.c -o snake_game -I ./include/

1.3 编译方法二（基于cmake手动编译项目）：推荐

	用vscode打开Snake_Game。 
	配置cmake： 按快捷键 ctrl+shift+p，在窗口中搜索 CMake configure，选中这个配置项
![image](https://user-images.githubusercontent.com/106960367/215380502-6fd7033d-3583-4bbd-8407-97276cc28c84.png)
	
  点击CMake configuration后，会在工作区自动生成build文件夹。
  修正（重要步骤）： 根据安装的MinGW选择MinGW套件中的GCC编译器。

![image](https://user-images.githubusercontent.com/106960367/215380584-36bf02f2-8a83-4985-8fa3-a804f82ff9db.png)

  cd 到build文件夹
  执行"cmake .."
  执行“mingw32-make” (根据自己安装的make工具的名字来写指令)，生成可执行文件snake_game.exe

1.4  编译优化（利用vscode中 cmake工具）

  点击下图中1标记的位置或者2标记的位置，进行编译。
![image](https://user-images.githubusercontent.com/106960367/215380693-6c745e3a-6fba-4256-ab5e-4efe07e1bf0d.png)

2. 调试

2.1 搭建调试环境

  1. 安装gdb
  
2.2 在vscode中输入Ctrl+Shift+P调出vscode控制台，输入task，生成一个tasks.json文件，并替换为如下内容。

	  {
	      "version": "2.0.0",
	      "options": {
		  "cwd": "${workspaceFolder}/build"
	      },
	      "tasks": [
		  {
		      "type": "shell",
		      "label": "cmake", //第一个动作，执行cmake
		      "command": "cmake",
		      "args": [
			  ".."
		      ]
		  },
		  {
		      "label": "make", //第二个动作，执行make
		      "group": {
			  "kind": "build",
			  "isDefault": true
		      },
		      "command": "mingw32-make",
		      "args": []
		  },
		  {
		      "label": "Build", //把上面的两个动作绑定，命名为Build
		      "dependsOrder": "sequence",
		      "dependsOn": [
			  "cmake",
			  "make"
		      ]
		  }
	      ]
	  }



2.3 在vscode中打开debug选项，选择create a launch.json，并替换为如下内容。

    {
      // 使用 IntelliSense 了解相关属性。 
      // 悬停以查看现有属性的描述。
      // 欲了解更多信息，请访问: https://go.microsoft.com/fwlink/?linkid=830387
      "version": "0.2.0",
      "configurations": [
          {
              "name": "(gdb) 启动",
              "type": "cppdbg",
              "request": "launch",
              //只需要改两处
              //第一处，在这里指定你的可执行文件的路径和名称
              "program": "${workspaceFolder}/build/snake_game.exe",   // todo: 需要根据build生成的exe修改名称
              "args": [],
              "stopAtEntry": false,
              "cwd": "${workspaceFolder}/build",       // cwd = cd  进入调试文件
              "environment": [],
              "externalConsole": true,      // 在编译器内执行还是弹出黑框
              "MIMode": "gdb",
              "preLaunchTask": "Build",     //第二处，绑定刚才的task
              "setupCommands": [
                  {
                      "description": "为 gdb 启用整齐打印",
                      "text": "-enable-pretty-printing",
                      "ignoreFailures": true
                  }
              ]
          }
      ]
  }

3.自动调整google style programme guide

3.1 自动调整

  下载工具LLVM\\bin\\clang-format.exe

3.2 在vscode中创建setting.json,并替换为如下内容。

	  {
	      "C_Cpp.clang_format_path": "C:\\Program Files\\LLVM\\bin\\clang-format.exe", // 谷歌代码风格自动更改内容
	      "files.associations": {
		  "cstdio": "c",
		  "stdio.h": "c",
		  "cwchar": "c",
		  "type_traits": "c",
		  "typeinfo": "c",
		  "random": "c"
	      }
	  } 

For linux:

	Same as the windows. 

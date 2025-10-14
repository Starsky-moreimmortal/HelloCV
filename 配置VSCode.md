1**.下载VSCode**

![](https://cdn.nlark.com/yuque/0/2025/png/61715014/1760446689172-7835fcfa-7ba0-4789-8e93-0f5e4bb63e0a.png)

2**.****<font style="color:rgb(0, 0, 0);">安装核心扩展(</font>**`<font style="color:rgb(0, 0, 0);">Ctrl+Shift+X</font>`<font style="color:rgb(0, 0, 0);">打开扩展面板</font>**<font style="color:rgb(0, 0, 0);">)</font>**

| <font style="color:rgb(0, 0, 0);">扩展名</font> | <font style="color:rgb(0, 0, 0);">作用</font> | <font style="color:rgb(0, 0, 0);">说明</font> |
| :--- | :--- | :--- |
| **<font style="color:rgb(0, 0, 0);">WSL</font>** | <font style="color:rgb(0, 0, 0);">在 VSCode 中无缝集成 WSL</font> | <font style="color:rgb(0, 0, 0);">允许你直接打开 WSL 中的文件夹</font> |
| **<font style="color:rgb(0, 0, 0);">C/C++</font>** | <font style="color:rgb(0, 0, 0);">C++ 语言支持</font> | <font style="color:rgb(0, 0, 0);">提供代码补全、调试等功能</font> |
| **<font style="color:rgb(0, 0, 0);">Python</font>** | <font style="color:rgb(0, 0, 0);">Python 语言支持</font> | <font style="color:rgb(0, 0, 0);">你的 ROS 2 节点可能用 Python 编写</font> |
| **<font style="color:rgb(0, 0, 0);">CMake Tools</font>** | <font style="color:rgb(0, 0, 0);">CMake 项目支持</font> | <font style="color:rgb(0, 0, 0);">简化 CMake 项目的配置和构建</font> |
| **<font style="color:rgb(0, 0, 0);">ROS</font>** | <font style="color:rgb(0, 0, 0);">ROS 2 专用支持</font> | <font style="color:rgb(0, 0, 0);">提供 ROS 2 消息、服务等的自动补全</font> |


![](https://cdn.nlark.com/yuque/0/2025/png/61715014/1760446769722-bca6cdca-34c5-479e-a634-a20b109f9c83.png)

<font style="color:rgb(0, 0, 0);">3.</font>**<font style="color:rgb(0, 0, 0);">配置 VSCode 连接到 WSL</font>**

**<font style="color:rgb(0, 0, 0);">4.打开项目文件夹</font>**

**<font style="color:rgb(0, 0, 0);">5.配置工作区设置</font>**

<font style="color:rgb(0, 0, 0);">在项目根目录创建 </font>`<font style="color:rgb(0, 0, 0);">.vscode/settings.json</font>`<font style="color:rgb(0, 0, 0);">文件，添加以下配置：</font>

```plain
{
    "cmake.configureSettings": {
        "CMAKE_PREFIX_PATH": "/opt/ros/humble"
    },
    "python.autoComplete.extraPaths": [
        "/opt/ros/humble/local/lib/python3.10/dist-packages"
    ],
    "C_Cpp.default.configurationProvider": "ms-vscode.cmake-tools"
}
```

<font style="color:rgb(0, 0, 0);">这个配置告诉我们 VSCode 如何找到 ROS 2 的包和 Python 路径。</font>


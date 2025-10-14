1.更新

```plain
sudo apt update && sudo apt upgrade -y
```

2.确保支持 universe 仓库

```plain
sudo apt install software-properties-common
sudo add-apt-repository universe
```

3.添加 ROS 2 的 GPG 密钥

```plain
sudo apt update && sudo apt install curl
sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg
```

4.将 ROS 2 软件源添加到系统列表

```plain
echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(. /etc/os-release && echo $UBUNTU_CODENAME) main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null
```

5.**<font style="color:rgb(0, 0, 0);">安装 ROS 2 桌面版</font>**

```plain
sudo apt update
sudo apt install ros-humble-desktop
```

此时遇到问题，![](https://cdn.nlark.com/yuque/0/2025/png/61715014/1760439813364-8be4f217-935f-4cbb-bfd6-e6a00a43e7a5.png)

询问DeepSeek后得知：

**<font style="color:rgb(0, 0, 0);">核心问题：你的 Ubuntu 版本（24.04，代号 Noble Numbat）与 ROS 2 Humble（为 Ubuntu 22.04，代号 Jammy Jellyfish 设计）不兼容。</font>**

**<font style="color:rgb(0, 0, 0);">于是：</font>**

<font style="color:rgb(0, 0, 0);">5*（1）</font>**<font style="color:rgb(0, 0, 0);">清理之前的错误配置</font>**<font style="color:rgb(0, 0, 0);">（确保起点干净）</font>

```plain
sudo rm /etc/apt/sources.list.d/ros2.list
```

<font style="color:rgb(0, 0, 0);">5*（2）</font>**<font style="color:rgb(0, 0, 0);">添加适用于 Ubuntu 24.04 (Noble) 的 ROS 2 Jazzy 软件源</font>**

```plain
sudo apt install curl
sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg
```

```plain
echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu noble main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null
```

5*（3）**<font style="color:rgb(0, 0, 0);">更新软件源并安装 ROS 2 Jazzy 桌面版（</font>**~~**<font style="color:rgb(0, 0, 0);">吐槽一下：这里真的安装了好久</font>**~~**<font style="color:rgb(0, 0, 0);">）</font>**![](https://cdn.nlark.com/yuque/0/2025/png/61715014/1760442107423-e08f0c57-72fa-4d66-bbfa-0de282fc47be.png)

```plain
sudo apt update
sudo apt install ros-jazzy-desktop
```

5*（4）**环境配置**

```plain
echo "source /opt/ros/jazzy/setup.bash" >> ~/.bashrc
source ~/.bashrc
```

5*（5）**<font style="color:rgb(0, 0, 0);">验证安装</font>**

```plain
ros2 version
```

![](https://cdn.nlark.com/yuque/0/2025/png/61715014/1760440179050-1f4dac73-d7c6-44ef-af39-1ecdae567a03.png)

👆这是DeepSeek给的警示：安装需要注意**版本问题!!!**

****

****


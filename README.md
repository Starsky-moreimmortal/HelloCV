# HelloCV
bash

sudo apt update && sudo apt install curl

sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key-o /usr/share/keyrings/ros-archive-keyring.gpg

echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntunoble main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null

sudo apt update

sudo apt install ros-jazzy-desktop

echo "source /opt/ros/jazzy/setup.bash" >> ~/.bashrc

source ~/.bashrc

### 2. 安装 OpenCV 4.5.5

bash

sudo apt install -y build-essential cmake git

mkdir -p ~/opencv_build && cd ~/opencv_build

git clone https://github.com/opencv/opencv.git

cd opencv && git checkout 4.5.5

cd ..

git clone https://github.com/opencv/opencv_contrib.git

cd opencv_contrib && git checkout 4.5.5

cd ..

mkdir build && cd build

cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local -D OPENCV_EXTRA_MODULES_PATH=~/opencv_build/opencv_contrib/modules ../opencv

make -j$(nproc)

sudo make install

sudo ldconfig

### 3. 配置 Git & SSH

bash

git config --global user.name "Starsky-moreimmortal"

git config --global user.email "tysqwe@qq.com"

ssh-keygen -t ed25519 -C "tysqwe@qq.com"

cat ~/.ssh/id_ed25519.pub copy to GitHub SSH Keys

### 4. 获取项目代码

bash

mkdir -p ~/cv_ws/src

cd ~/cv_ws/src

git clone git@github.com:Starsky-moreimmortal/HelloCV.git

cd ..

rosdep install -i --from-path src --rosdistro jazzy -y

colcon build

source install/setup.bash

## 📁 项目结构

HelloCV/

├── src/                 # ROS 2 包源码

├── launch/              # 启动文件

├── config/              # 配置文件

├── docs/                # 项目文档

└── README.md            # 说明文件

## 💡 使用方法

bash

运行示例节点
ros2 launch hello_cv demo.launch.py

查看运行状态
ros2 node list

ros2 topic list

查看运行状态
ros2 node list

ros2 topic list

## 🆘 遇到问题？
1. 检查环境变量：`source /opt/ros/jazzy/setup.bash`
2. 验证安装：`ros2 version` 和 `pkg-config --modversion opencv4`
3. 查看项目文档：`docs/` 目录

**开发者**: Starsky-moreimmortal  
**仓库**: https://github.com/Starsky-moreimmortal/HelloCV


### 项目结构
HelloCV/

├── src/

│   └── hello_cv_node.cpp  # ROS 2 图像处理节点

├── launch/

│   └── camera.launch.py   # 相机启动文件

├── config/

│   └── params.yaml        # 参数配置文件

└── CMakeLists.txt         # ROS 2 构建配置

---

## 🔐 第二部分：文件加密工具

### ✨ 功能亮点
- **凯撒密码算法**：支持任意整数密钥的加密/解密
- **文件操作**：完整的文件读写功能
- **交互式界面**：用户友好的命令行菜单
- **跨平台支持**：兼容 Windows/WSL 和 Linux 系统

### 🛠️ 使用指南
bash

克隆项目
git clone https://github.com/Starsky-moreimmortal/HelloCV.git

编译项目
cd ~/cv_ws

colcon build
运行加密工具
./install/hello_cv/lib/hello_cv/crypto_tool

#### 操作示例
🔐 文本加密解密工具
加密文本

解密文本

加密文件

解密文件

退出程序
请选择操作 (1-5): 3

📁 文件加密
请输入要加密的文件路径: /mnt/c/Users/tysqw/Desktop/secret.txt

请输入加密密钥 (整数): 7

请输入输出文件路径: /mnt/c/Users/tysqw/Desktop/encrypted_secret.txt

✅ 文件加密完成！

### 📂 核心类说明
| 类名 | 功能 |
|------|------|
| **Crypto** | 实现凯撒密码算法 |
| **FileHandler** | 文件读写操作 |
| **Menu** | 用户交互界面 |

### 🌐 路径处理参考
| 系统 | 桌面文件路径示例 |
|------|------------------|
| **WSL** | `/mnt/c/Users/用户名/Desktop/文件.txt` |
| **原生 Linux** | `~/Desktop/文件.txt` |
| **Windows CMD** | `C:\Users\用户名\Desktop\文件.txt` |

---

## 🏗️ 项目结构

HelloCV/

├── CMakeLists.txt          # 项目构建配置

├── package.xml             # ROS 2 包配置

├── README.md               # 项目文档

├── src/

│   ├── Crypto.h/cpp       # 加密算法

│   ├── FileHandler.h/cpp   # 文件操作

│   ├── Menu.h/cpp          # 用户界面

│   └── crypto_main.cpp     # 程序入口

└── test_files/             # 测试用例

---

## 📜 许可证
本项目采用 MIT 许可证 - 详情请查看 [LICENSE](LICENSE) 文件

---

**开发者**：Starsky-moreimmortal  
**最后更新**：2025年3月15日


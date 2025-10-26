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
```bash
#克隆项目
git clone https://github.com/Starsky-moreimmortal/HelloCV.git
#编译项目
cd ~/cv_ws
colcon build
运行加密工具
./install/hello_cv/lib/hello_cv/crypto_tool
```

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
```
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
```

## 📜 许可证
本项目采用 MIT 许可证 - 详情请查看 [LICENSE](LICENSE) 文件

---

TrafficLight 交通灯检测项目

项目概述

这是一个基于 ​OpenCV​ 和 ​C++​​ 的交通灯颜色检测系统，能够从视频流中实时检测并识别交通灯的红绿状态。项目涵盖了从环境配置、算法开发到实际应用的完整计算机视觉开发流程。

核心功能：
视频处理​：支持多种视频格式输入（AVI、MP4等）
颜色识别​：准确检测红灯和绿灯状态
实时处理​：逐帧分析视频流，实时输出检测结果
多后端兼容​：支持 FFmpeg、V4L 等多种视频后端
​跨平台​：在 WSL/Ubuntu 和 Windows 环境下均可运行

项目结构：
TrafficLight/
├── src/
│   ├── main.cpp              # 主程序 - 交通灯检测核心逻辑
│   ├── diagnose_video.cpp    # 视频后端诊断工具
│   └── generate_images.cpp   # 测试图像生成器
├── test_images/              # 测试图像目录
│   ├── traffic_light_red.jpg    # 红灯测试图像
│   ├── traffic_light_green.jpg   # 绿灯测试图像
│   └── traffic_light_yellow.jpg # 黄灯测试图像
├── frames/                   # 视频帧序列（由FFmpeg生成）
├── build/                    # 构建目录
├── CMakeLists.txt            # 项目构建配置
└── README.md                 # 项目说明文档

环境要求
​Ubuntu/WSL 环境​
​OpenCV 4.5.5+​​（需包含视频支持）
​FFmpeg​（用于视频处理）
​GCC/G++​​（C++编译器）

使用指南：
将交通灯视频文件放置在项目目录中：
C:/Users/用户名/Desktop/OpenCV_Test/

视频预处理（关键步骤！！！）
​将视频转换为【图片序列】，这是本项目采用的核心方法：
bash
# 创建帧存储目录
mkdir -p /mnt/c/Users/tysqw/Desktop/OpenCV_Test/frames

# 使用FFmpeg将视频拆分为图像序列
ffmpeg -i "/mnt/c/Users/tysqw/Desktop/OpenCV_Test/TrafficLight.mp4" \
       -qscale:v 2 \  # 图像质量参数
       "/mnt/c/Users/tysqw/Desktop/OpenCV_Test/frames/frame_%04d.jpg"

# 验证生成结果
ls -la /mnt/c/Users/tysqw/Desktop/OpenCV_Test/frames/ | head -10

项目编译：
```bash
cd ~/cv_ws/src/HelloCV/OpenCV_Test/
mkdir -p build && cd build
cmake ..
make
```

配置图片序列路径：
string image_pattern = "/mnt/c/Users/tysqw/Desktop/OpenCV_Test/frames/frame_%04d.jpg";
（注意：WSL不能直接读取Windows的文件，需要改为mnt/c的形式！！！）

运行：
./OpenCV_test

main.cpp:
```cpp
#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>
#include <string>

using namespace cv;
using namespace std;

int main() {
    string image_pattern = "/mnt/c/Users/tysqw/Desktop/OpenCV_Test/frames/frame_%04d.jpg";
    
    VideoCapture cap(image_pattern);
    
    if(!cap.isOpened()) {
        return -1;
    }
    
    Mat frame;
    namedWindow("TrafficLights", WINDOW_AUTOSIZE);
    
    while(true) {
        cap >> frame;
        if(frame.empty()) break;
        
        Mat hsv;
        cvtColor(frame,hsv,COLOR_BGR2HSV);
        
        Scalar red_low1(0, 120, 70), red_high1(10, 255, 255);
        Scalar red_low2(170, 120, 70), red_high2(180, 255, 255);
        Mat red_mask1, red_mask2, red_mask;
        inRange(hsv, red_low1, red_high1, red_mask1);
        inRange(hsv, red_low2, red_high2, red_mask2);
        red_mask=red_mask1 | red_mask2;
        int red_pixels=countNonZero(red_mask);
        
        Scalar green_low(35, 100, 100), green_high(85, 255, 255);
        Mat green_mask;
        inRange(hsv, green_low, green_high, green_mask);
        int green_pixels=countNonZero(green_mask);
        
        string light_state="UNKNOWN";
        Scalar text_color(255, 255, 255); 
        
        if(red_pixels>100 && red_pixels>green_pixels) {
            light_state = "RED LIGHT";
            text_color = Scalar(0, 0, 255); 
        } else if(green_pixels>100 && green_pixels>red_pixels) {
            light_state="GREEN LIGHT"; 
            text_color=Scalar(0, 255, 0); 
        }
        
        putText(frame, light_state, Point(50, 50), 
                FONT_HERSHEY_SIMPLEX, 1, text_color, 2);
        
        string stats = "Red: " + to_string(red_pixels) + " Green: " + to_string(green_pixels);
        putText(frame, stats, Point(50, 90), 
                FONT_HERSHEY_SIMPLEX, 0.6, Scalar(255, 255, 255), 1);
        
        imshow("TrafficLights", frame);
        if(waitKey(30)==27) break;
    }
    cap.release();
    return 0;
}
```

结果：
1.图片流形式
2.左上角颜色状态文字显示
3.显示实时像素统计信息
4.按ESC即可退出（叉不掉的）

**开发者**：Starsky-moreimmortal  
**最后更新**：2025年10月26日


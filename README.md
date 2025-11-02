# 首先说明，本人是在边做边学，学习笔记已详细整理至“Starsky语雀链接”，每周更新，已设为公开访问！

https://github.com/Starsky-moreimmortal/HelloCV/blob/main/Starsky%E8%AF%AD%E9%9B%80%E9%93%BE%E6%8E%A5.txt

# HelloCV

```bash
sudo apt update && sudo apt install curl
sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key-o /usr/share/keyrings/ros-archive-keyring.gpg
echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntunoble main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null
sudo apt update
sudo apt install ros-jazzy-desktop
echo "source /opt/ros/jazzy/setup.bash" >> ~/.bashrc
source ~/.bashrc
```

### 2. 安装 OpenCV 4.5.5

```bash
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
```

### 3. 配置 Git & SSH

```bash
git config --global user.name "Starsky-moreimmortal"
git config --global user.email "tysqwe@qq.com"
ssh-keygen -t ed25519 -C "tysqwe@qq.com"
cat ~/.ssh/id_ed25519.pub copy to GitHub SSH Keys
```

### 4. 获取项目代码

```bash
mkdir -p ~/cv_ws/src
cd ~/cv_ws/src
git clone git@github.com:Starsky-moreimmortal/HelloCV.git
cd ..
rosdep install -i --from-path src --rosdistro jazzy -y
colcon build
source install/setup.bash
```

## 📁 项目结构
```
HelloCV/

├── src/                 # ROS 2 包源码

├── launch/              # 启动文件

├── config/              # 配置文件

├── docs/                # 项目文档

└── README.md            # 说明文件
```

## 💡 使用方法

```bash
#运行示例节点
ros2 launch hello_cv demo.launch.py
#查看运行状态
ros2 note list
ros2 topic list
```

## 🆘 遇到问题？
```
1. 检查环境变量：`source /opt/ros/jazzy/setup.bash`
2. 验证安装：`ros2 version` 和 `pkg-config --modversion opencv4`
3. 查看项目文档：`docs/` 目录
```

**开发者**: Starsky-moreimmortal  
**仓库**: https://github.com/Starsky-moreimmortal/HelloCV

### 项目结构
```
HelloCV/

├── src/

│   └── hello_cv_node.cpp  # ROS 2 图像处理节点

├── launch/

│   └── camera.launch.py   # 相机启动文件

├── config/

│   └── params.yaml        # 参数配置文件

└── CMakeLists.txt         # ROS 2 构建配置
```
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

# TrafficLight 交通灯检测项目

# 项目概述

这是一个基于 ​OpenCV​ 和 ​C++​​ 的交通灯颜色检测系统，能够从视频流中实时检测并识别交通灯的红绿状态。项目涵盖了从环境配置、算法开发到实际应用的完整计算机视觉开发流程。

# 核心功能：
视频处理​：支持多种视频格式输入（AVI、MP4等）
颜色识别​：准确检测红灯和绿灯状态
实时处理​：逐帧分析视频流，实时输出检测结果
多后端兼容​：支持 FFmpeg、V4L 等多种视频后端
​跨平台​：在 WSL/Ubuntu 和 Windows 环境下均可运行

# 项目结构：
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

# 环境要求
​Ubuntu/WSL 环境​
​OpenCV 4.5.5+​​（需包含视频支持）
​FFmpeg​（用于视频处理）
​GCC/G++​​（C++编译器）

# 使用指南：
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

# 项目编译：
```bash
cd ~/cv_ws/src/HelloCV/OpenCV_Test/
mkdir -p build && cd build
cmake ..
make
```

# 配置图片序列路径：
string image_pattern = "/mnt/c/Users/tysqw/Desktop/OpenCV_Test/frames/frame_%04d.jpg";
（注意：WSL不能直接读取Windows的文件，需要改为mnt/c的形式！！！）

# 运行：
./OpenCV_test

# main.cpp:
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

# 结果：
```
1.图片流形式
2.左上角颜色状态文字显示
3.显示实时像素统计信息
4.按ESC即可退出（叉不掉的）
```
# 具体结果：result(speedy).mp4

## 📜 许可证
本项目采用 MIT 许可证 - 详情请查看 [LICENSE](LICENSE) 文件

---

**开发者**：Starsky-moreimmortal  
**最后更新**：2025年10月26日

# Vocabulary Appendix

## 基于图片1的内容：Section 1, Episode 1 New words 等

### Section 1

### Episode 1

### New words

- **injury /ˈɪndʒəri/ n. [C, U] a wound or damage to part of your body caused by an accident or attack (身体上的) 伤害  
  attracte**
- **distracted /dɪˈstræktɪd/ a. anxious and unable to think clearly 心神不定的；心烦意乱的；精神无法集中的**  
  impair
- **constitute /ˈkɒnstɪˌtju:t/ v. (linking verb) if several people or things constitute sth., they are the parts that form it组成；构成  
  include**
- **exclusively /ɪkˈskluːsɪvli/ ad. used for emphasizing that sth. is available to or limited to one specific thing or group 仅仅；单独地；专门地**  
  correspond
- **emission /ɪˈmɪʃn/ n. [C, usu. pl.] a gas or other substance that is sent into the air 排放物；散发物**  
  correspond
- **honeymoon /ˈhʌniˌmuːn/ n. [C] the beginning of a period of time when everything is pleasant and people try not to criticize (开始时的) 和谐时期；蜜月时期**  
  impaired
- **facial recognition /ˌfeɪʃlˌrekaɡˈnɪʃn/ n. [U] technology that makes it possible for a computer to recognize sb.’s face 面部识别；人脸识别**  
  distant
- **terrorist /ˈterərɪst/ n. [C] sb. who uses violence in order to achieve political aims 恐怖分子**  
  engagement
- **criminal /ˈkrɪmɪml/ n. [C] sb. who has committed a crime 罪犯  
  [C] a. (usu. before noun) relating to illegal acts 犯罪的；犯法的  
  [C] a formal agreement to get married 婚约**
- **cop /kɒp/ n. [C] (infml.) a police officer 警察**  
  hang around  
  at best  
  hang around being  
  being  
  at best  
  hang around  
  at best  
  hang around  
  used for saying what is the best opinion you can have of sb. or sth., or the best thing that can happen, when the situation is bad (表达最好的看法，或恶劣状况下可能出现的最好转机) 充其量  
  used for saying what is the worst thing that can happen (指可能出现的最坏情况) 往最坏处说  
  used for saying what is the worst thing that can happen (指可能出现的最坏情况) 往最坏处说  
  get into (infml.) to begin to discuss sth. 开始讨论

### Phrases and expressions

hang around  
to spend time in a place waiting or doing nothing (在某处) 闲呆着  
at best  
used for saying what is the best opinion you can have of sb. or sth., or the best thing that can happen, when the situation is bad (表达最好的看法，或恶劣状况下可能出现的最好转机) 充其量  
at (the) worst  
used for saying what is the worst thing that can happen (指可能出现的最坏情况) 往最坏处说  
get into (infml.) to begin to discuss sth. 开始讨论

---

## 基于图片2的内容：Episode 2 New words 等

on the fly simultaneously with another task 同时

take up to fill a particular amount of space or time 占去（空间或时间）

free up to make sb. or sth. available to be used for sth. else 腾出；省下；使用于

with regard to concerning a particular subject 关于；有关

### Episode 2

### New words

nerve-racking /'nɜːvˌrækɪŋ/ a. making you very nervous or worried 使人精神紧张的；令人心烦的

rigid /ˈrɪdʒɪd/ a. not easily changed 刻板的；不易改变的

terminology /tɜːmɪˈnɒdʒɜːn. [U] the words and phrases used in a particular business, science, or profession 术语；专门用语

$ ^{\ast} $thesis /ˈθiːsɪs/ n. [C] (pl. theses)  
1 (fml.) an idea, opinion, or theory that is used to explain sth. 论点；论题  
2 a long piece of writing that is the final part of an advanced university degree（学位）论文

$ ^{\ast} $capture /'kæptʃə/ vt. to catch sb. so that they become your prisoner 俘虏；捕获

$ ^{\ast} $diagram /ˈdɑrəˌgræm/ n. [C] a drawing that explains sth. 图表；示意图

$ ^{\ast} $quote /kwəʊt/  
n. [C] a quotation from a book, play, speech, etc. 引文；引语  
v. to say or write words that sb. else has said or written 引用；引述

$ ^{\ast} $stimulating /ˈstɪmjuˌleɪtɪŋ/ a. exciting or full of new ideas 使人兴奋的；饶有兴趣的；充满新思想的

$ ^{\ast} $enthusiastic /ɪnˌθjuːziˈæstɪk/ a. very interested in sth. or excited by it 极感兴趣的；热情的；热心的

$ ^{\ast} $informative /ɪnˈfɔːmətɪv/ a. providing many useful facts or ideas 资料丰富的；增进知识的

scenario /səˈnɑːriəʊ/ n. [C] (pl. ~s) a situation that could possibly happen but has not happened yet 可能发生的事；可能出现的情况

delay /dɪˈleɪt/ v. to wait until a later time to do sth. 推迟；延期

$ ^{\ast} $scope /skəʊp/ n. [U] the things that a particular activity, organization, subject, etc. deals with（活动、机构或学术）范围

$ ^{\ast} $speculate /ˈspekjuˌleɪt/ v. to consider or discuss why sth. has happened 思索；沉思；推测；猜测

$ ^{\ast} $disastrous /dɪˈzɑːstrəs/ a. causing a lot of damage or harm 造成灾难的；灾难性的

$ ^{\ast} $disagreement /ˌdɪsəˈgriːmənt/ n. [C, U] a situation in which people express different opinions about sth. and sometimes argue 意见不合；分歧；争论

$ ^{\ast} $flaw /floː/ n. [C] a mistake or fault in sth. that makes it useless or less effective 错误；缺陷

$ ^{\ast} $clarify /ˈklərəˌfaɪ/ vt. (fml.) to explain sth. more clearly so that it is easier to understand 澄清；阐明

### Phrases and expressions

or else used for saying that there will be a bad result if sth. does not happen 否则（用于表示如果某事不发生就会有坏的结果）

capture one's attention to make sb. feel very interested and attracted 吸引某人的注意

keep to to follow an agreement or a rule, by doing what you should do or what you said you would do 遵守，信守（协定或规则）

as best you can (spoken) as well as you can, even if this is not very good 尽最大努力；竭力

defer to to accept sb.'s opinion or decision, esp. because you respect them（尤因尊敬而）听从，接受（观点或决定）

take sth. personally to feel that a failure or unpleasant situation is your fault and be upset about it 为某事感到自责

### Proper names

Malaysia /məˈleɪʒə/ 马来西亚（东南亚国家）

Kota Kinabalu /ˌkəʊtəˌkɪnəbəˈluː/ Airport 哥打基纳巴卢机场（哥打基纳巴卢为马来西亚沙巴州首府）

---

## 基于图片3的内容：Section 2 Text A New words

*grave /greiv/ a. so serious that you feel worried 严重的;  
沉重的

*synthetic /sin'θetik/ a. made from artificial materials or substances, not from natural ones 合成的; 人造的

*generate /dʒenə,reIT/ vt. to produce or cause sth. 产生;创造

*indistinguishable /ɪndtɪstɪngwɪʃəbl/ a. if two things are indistinguishable, you cannot see any difference between them 难以分辨的; 无法辨别的

*knaked /'neɪkɪd/ a.  
1 (the~ eye) if you can see sth. with the naked eye, you can see it without using a telescope, microscope, etc. 肉眼  
2 not wearing clothes or not covered by clothes 裸体的

*synthesize /'sinθə,saɪz/ vt.  
1 to produce sounds using a synthesizer (用音响合成器) 合成 (声音)  
2 to produce sth. by combining different things or substances 合成

*programmer /'prəuˌgræmə/ n. [C] sb whose job is to create computer programs (计算机的) 程序编写员, 程序设计员

*scandal /'skændl/ n. [C, U] a situation in which important people behave in a dishonest or immoral way that shocks people 丑闻; 丑行; 丑事

*fake /ferk/  
n. [C] a copy of a valuable object, painting, etc. that is intended to deceive people 赝品; 假货  
a. made to look like sth. real in order to trick people 假的; 伪造的; 冒充的

*overwhelming /ˌəʊvə'welmiŋ/ a. having such a great effect on you that you feel confused and do not know how to act 难以抗拒的; 令人不知所措的

*frightening /'frattnɪŋ/ a. making you feel afraid 可怕的; 骇人的

*skepticism /'skeptɪˌsɪz(ə)m/ n. [U] (BrE scepticism) an attitude of doubt about whether sth. is true, right, or good 怀疑态度; 怀疑论

*capability /ˌkeɪpə'bɪləti/ n. [C] the natural ability, skill, or power that makes a machine, person, or organization able to do sth., esp. sth. difficult (尤指完成困难事情的) 能力, 才能

---

## 基于图片4的内容：Phrases and expressions、Proper names、Text B New words 等

* deprive /dɪˈpraɪv/ vt. (~ sb. of sth.) to take sth. from sb. ，esp. sth. that they need or want 剥夺

### Phrases and expressions

take over to take control of sth. 接管；取得对…的控制

here and now at the present time 目前；此刻

in one respect / in some respects, etc. used to say that sth. is true in one way, in some ways, etc. 在某个/某些方面等

pop up to appear very quickly or suddenly 突然出现；迅速出现

engage with to make an effort to understand and deal with sb. or sth. 理会；处理

custom /'kʌstəm/ a. (only before noun) (esp. AmE)  
custom products or services are specially designed and made for a particular person 定制的；定做的

synthesizer /'sɪnθəˌsaɪzə/ n. [C] 电子音响合成器

hologram /'hɒləˌgræm/ n. [C] a kind of picture that is three-dimensional and does not look flat, esp. one created using lasers（尤指用激光制作的）（立体）全息图

solo /'səʊləʊ/ a. (usu. before noun) done by one person alone, without any help 单独的；独自的

* portrait /'pɔ:trɪt/ n. [C] a painting, drawing, or photograph of a person（人的）画像，照片，肖像

* resemble /rɪˈzembl/ vt. (never passive) to be similar to sb. or sth., esp. in appearance（尤指外表上）像，类似，与…相似

### Proper names

AlphaGo /'ælfəˌɡəʊ/ 阿尔法围棋（一款围棋人工智能程序）

DeepMind 谷歌旗下的人工智能实验室

Lee Sedol /iːˈseɪdəʊl/ 李世石（1983-，韩国前围棋棋手）

### Text B

### New words

* album /'ælbəm/ n. [C] a group of songs or pieces of music on a CD, tape, etc.（歌曲或音乐的）专辑

* masterpiece /'mɑːstəˌpiːs/ n. [C] an excellent painting, book, piece of music, etc., or the best work of art that a particular artist, writer, musician, etc. has ever produced. 杰作；名著；大作

downstate /ˌdaunˈsteɪt/ ad. (AmE) in or from the southern part of a state 在某州南部；来自某州南部

* complexity /kəmˈpleksəti/ n. [U] the complicated nature of sth. 复杂性

* creation /kriˈeɪʃn/ n. [U] the act of creating sth. 创造；创建；创作

* rival /'raɪvl/ vt. to be as good or important as sb. or sth. else 与…匹敌；与…媲美

* profound /praˈfaʊnd/ a. having a strong influence or effect（影响）深刻的，极大的

hum /hʌm/ v. to sing a tune by making a continuous sound with your lips closed 哼（曲子）

* custom /'kʌstəm/ a. (only before noun) (esp. AmE)  
custom products or services are specially designed and made for a particular person 定制的；定做的

synthesizer /'sɪnθəˌsaɪzə/ n. [C] 电子音响合成器

hologram /'hɒləˌgræm/ n. [C] a kind of picture that is three-dimensional and does not look flat, esp. one created using lasers（尤指用激光制作的）（立体）全息图

solo /'səʊləʊ/ a. (usu. before noun) done by one person alone, without any help 单独的；独自的

* portrait /'pɔ:trɪt/ n. [C] a painting, drawing, or photograph of a person（人的）画像，照片，肖像

* resemble /rɪˈzembl/ vt. (never passive) to be similar to sb. or sth., esp. in appearance（尤指外表上）像，类似，与…相似

* abstract /'æbstrækt/  
a. based on general ideas or principles rather than specific examples or real events 纯理论的；纯概念的；抽象的  
n. [C] a summary of a report, speech, or academic paper 摘要；概括

artwork /'ɑːtˌwɜːk/ n. [C, U] paintings, sculptures, etc. 艺术作品；美术作品

* involvement /ɪnˈvɒlvmənt/ n. [C, U] the act of taking part in an activity, event, or situation 参与；卷人；牵连

* collaboration /kəˌlæbəˈreɪʃn/ n. [C, U] when you work together with another person or group to achieve sth., esp. in science or art（尤指在科学或艺术方面的）合作，协作

spec /spek/ n. [C, usu. pl.] (abbrev. for specification) a detailed instruction about how a building, car, piece of equipment, etc. should be made（制造房子、汽车、设备等）的规格说明

subset /'sʌb,set/ n. [C] a small group of people or things that is a part of a larger group 亚群；小组；子集

* distinction /dɪˈstɪŋkʃn/ n. [C, U] a clear difference or separation between two similar things 差别；区别；不同

* formulate /'fɔ:mjuˌleɪt/ vt. to develop sth. such as a plan or a set of rules, and decide all the details of how it will be done 规划；制定；准备

* mechanic /mɪˈkænɪk/ n.  
1 (the ~s of) [pl.] the way in which sth. works or is done 工作方法；工作技巧  
2 [C] sb. whose job is to repair vehicles and machines 机修工；技工

---

## 基于图片5的内容：单词、Phrases and expressions、Proper names 等

*disbelief /ˌdɪsɒrˈliːf/ n. [U] the feeling of not believing sb. or sth., esp. sth. shocking or unexpected 怀疑；不相信

*subjective /səbˈdʒəktɪv/ a. a statement, report, attitude, etc. that is subjective is influenced by personal opinion and can therefore be unfair 主观的

legitimate /ˈlɪˈdʒɪtəmət/ a. fair and reasonable 公正合理的

### Phrases and expressions

play back to play music, film, etc. that has been recorded on a tape, video, etc.播放录音（或录像等）

the other way around / round the opposite of what you have just mentioned 正相反；倒过来

give over to to give responsibility for or control over sth. to a particular person, organization, etc. 交给给；移交给

### Proper names

New Jersey /ˈdʒɜːzɪ/ 新泽西州（美国州名）

John Coltrane /ˈkɒltreɪn/ 约翰·科尔特雷恩（1926-1967，美国爵士乐萨克斯手）

Ji-Sung Kim /ˈdʒiːˌsɒŋ kɪm/ 金智成（人名）

Princeton /ˈprɪnstən/ 普林斯顿大学（美国）

Vocaloid /ˈvəʊkləɪd/ 雅马哈开发的语音合成程序

Yamaha /ˈjɑːmɑːhɑː/ 雅马哈（一家生产乐器、音响设备及音效产品的日本公司）

Crypton /ˈkrɪptən/ 克里普敦未来媒体（一家从事音声制作和音乐软件制作的日本公司）

Hatsune Miku /hɑːˌtsʊneˈmiːkuː/ 初音未来（用语音合成程序开发的音源库）

Hammerstein /ˈhæməˌstæn/ Ballroom 哈默斯坦舞厅（美国纽约）

Ahmed Elgammal /ˈɑːmədˌelgəməl/ 艾哈迈德·埃尔加马尔（人名）

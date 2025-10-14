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



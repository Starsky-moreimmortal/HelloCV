<font style="color:rgb(0, 0, 0);">1.</font>**<font style="color:rgb(0, 0, 0);">安装编译工具和OpenCV的各种依赖库</font>**

```plain
sudo apt update
sudo apt install -y build-essential cmake git pkg-config libgtk-3-dev \
    libavcodec-dev libavformat-dev libswscale-dev libv4l-dev \
    libxvidcore-dev libx264-dev libjpeg-dev libpng-dev libtiff-dev \
    gfortran openexr libatlas-base-dev python3-dev python3-numpy \
    libtbb-dev libdc1394-dev
```

2.**<font style="color:rgb(0, 0, 0);">下载OpenCV 4.5.5源码</font>**

```plain
# 创建一个工作目录并进入
mkdir -p ~/opencv_build
cd ~/opencv_build

# 克隆OpenCV源码（此步骤网络耗时，可并行ROS安装）
git clone https://github.com/opencv/opencv.git
cd opencv
# 切换到4.5.5这个特定版本
git checkout 4.5.5

# 克隆OpenCV的额外模块（如SIFT特征提取等）
cd ..
git clone https://github.com/opencv/opencv_contrib.git
cd opencv_contrib
git checkout 4.5.5
```

3.**<font style="color:rgb(0, 0, 0);">配置构建（CMake）</font>**

```plain
# 退回到opencv_build目录，并创建build目录
cd ~/opencv_build
mkdir build
cd build

# 运行CMake进行配置（这是一条很长的命令，请完整复制）
cmake -D CMAKE_BUILD_TYPE=RELEASE \
      -D CMAKE_INSTALL_PREFIX=/usr/local \
      -D OPENCV_EXTRA_MODULES_PATH=~/opencv_build/opencv_contrib/modules \
      -D WITH_TBB=ON \
      -D WITH_OPENGL=ON \
      -D OPENCV_ENABLE_NONFREE=ON \
      -D BUILD_EXAMPLES=OFF \
      -D BUILD_opencv_python3=ON \
      -D BUILD_NEW_PYTHON_SUPPORT=ON \
      -D INSTALL_PYTHON_EXAMPLES=OFF \
      -D OPENCV_GENERATE_PKGCONFIG=ON \
      -D BUILD_EXAMPLES=OFF ..
```

遇到一点问题

![](https://cdn.nlark.com/yuque/0/2025/png/61715014/1760443871899-a28d087c-9d9e-4cac-a724-610fa24eaa22.png)

由于没有opencv目录，所以重新克隆 OpenCV 源码

![](https://cdn.nlark.com/yuque/0/2025/png/61715014/1760444520312-f25f9cf0-feeb-4f78-9ec3-fb9c53b9b5b5.png)

由于网络连接问题，增加了SSH

4.**<font style="color:rgb(0, 0, 0);">编译（Compile）</font>**

```plain
# 使用所有可用的CPU核心进行编译，数字8可根据我的CPU的核心数修改
make -j8
```

5.**<font style="color:rgb(0, 0, 0);">安装</font>**

```plain
sudo make install
```

6.**<font style="color:rgb(0, 0, 0);">配置系统环境</font>**

```plain
# 更新动态链接库的缓存
sudo ldconfig

# 验证安装
pkg-config --modversion opencv4
```


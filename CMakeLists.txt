cmake_minimum_required(VERSION 3.8)
project(hello_cv)

# 默认使用 C++14
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# 寻找依赖
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(image_transport REQUIRED)
find_package(OpenCV REQUIRED)

# 包含头文件目录
include_directories(include)

# 创建可执行文件
add_executable(hello_cv_node src/hello_cv_node.cpp)
ament_target_dependencies(hello_cv_node
  rclcpp
  std_msgs
  sensor_msgs
  cv_bridge
  image_transport
  OpenCV
)

# 安装目标
install(TARGETS hello_cv_node
  DESTINATION lib/${PROJECT_NAME})

# 安装启动文件
install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME})

# ========================================
# 加密工具可执行文件（独立目标）
# ========================================

# 添加加密工具可执行文件
add_executable(crypto_tool
    src/crypto_main.cpp
    src/Crypto.cpp
    src/FileHandler.cpp
    src/Menu.cpp
)

# 设置C++标准
set_target_properties(crypto_tool PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
)

# 包含头文件目录
target_include_directories(crypto_tool PRIVATE src)

# 安装到lib目录
install(TARGETS crypto_tool
    DESTINATION lib/${PROJECT_NAME}
)

# 导出包
ament_package()
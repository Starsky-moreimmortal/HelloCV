#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <cv_bridge/cv_bridge.hpp>
#include <opencv2/opencv.hpp>
class HelloCVNode : public rclcpp::Node
{
public:
  HelloCVNode() : Node("hello_cv_node")
  {
    // 创建发布者
    publisher_ = this->create_publisher<sensor_msgs::msg::Image>("output_image", 10);
    
    // 创建定时器，每秒发布一次
    timer_ = this->create_wall_timer(
      std::chrono::seconds(1),
      std::bind(&HelloCVNode::timer_callback, this));
    
    RCLCPP_INFO(this->get_logger(), "HelloCV Node started!");
  }

private:
  void timer_callback()
  {
    // 创建一个简单的 OpenCV 图像（红色矩形）
    cv::Mat image(480, 640, CV_8UC3, cv::Scalar(0, 0, 255)); // 红色背景
    cv::rectangle(image, cv::Point(100, 100), cv::Point(200, 200), 
                  cv::Scalar(255, 0, 0), -1); // 蓝色矩形
    
    // 添加文字
    cv::putText(image, "Hello OpenCV + ROS 2!", cv::Point(150, 300),
                cv::FONT_HERSHEY_SIMPLEX, 1.0, cv::Scalar(255, 255, 255), 2);
    
    // 转换为 ROS 2 图像消息
    auto msg = cv_bridge::CvImage(std_msgs::msg::Header(), "bgr8", image).toImageMsg();
    msg->header.stamp = this->now();
    msg->header.frame_id = "camera_frame";
    
    // 发布消息
    publisher_->publish(*msg);
    RCLCPP_INFO(this->get_logger(), "Published an image!");
  }
  
  rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<HelloCVNode>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}

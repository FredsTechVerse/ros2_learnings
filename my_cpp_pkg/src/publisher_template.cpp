#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class PublisherTemplateNode : public rclcpp::Node
{
public:
    PublisherTemplateNode() : Node("publisher_template"), robot_name_("R2D2")
    {
        publisher_ = this->create_publisher<std_msgs::msg::String>("publisher_topic", 10);
        timer_ = this->create_wall_timer(std::chrono::milliseconds(500), std::bind(&PublisherTemplateNode::publishInformation, this));
        RCLCPP_INFO(this->get_logger(), "Publisher template has been started");
    };

private:
    void publishInformation()
    {
        auto msg = std_msgs::msg::String();
        msg.data = std::string("Hi,this is ") + robot_name_ + std::string("from the Robot News Station");
        publisher_->publish(msg);
    };

    std::string robot_name_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<PublisherTemplateNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
class SubscriberTemplateNode : public rclcpp::Node
{
public:
    SubscriberTemplateNode() : Node("subscriber_template")
    {
        subscriber_ = this->create_subscription<std_msgs::msg::String>("publisher_topic", 10, std::bind(&SubscriberTemplateNode::callbackPublisherNews, this, std::placeholders::_1));
        RCLCPP_INFO(this->get_logger(), "Subscriber template node has been started");
    };

private:
    void callbackPublisherNews(const std_msgs::msg::String::SharedPtr msg)
    {
        RCLCPP_INFO(this->get_logger(), "%s", msg->data.c_str());
    };

    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscriber_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<SubscriberTemplateNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
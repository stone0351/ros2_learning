// Don't forget to update the CMakeList.txt
#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"

// MyCustomNode is child class of rclcpp::Node
class SmartphoneNode: public rclcpp::Node // modify name
{
public:
    // MyCustomNode() is function same name as its class name, so it is constructor
    // constructor will be automatically called when an object of a class is created
    SmartphoneNode():Node("smartphone") // modify name
    {
        // std::bind took 1st parameter a function i.e. &MyFunc, then its arguments as _1 & _2 as his own arguments.
        // below std::bind returns a function object
        // original func callback_robot_news() has no arguments, no _1 , _2, etc.
        // call_back_OBJ is just calling class SmartphoneNode member function callback_robot_news() 
        auto call_back_OBJ = std::bind(&SmartphoneNode::callback_robot_news, this, std::placeholders::_1);
        subscriber_ = this->create_subscription<example_interfaces::msg::String>("robot_news", 10, call_back_OBJ);
        RCLCPP_INFO(this->get_logger(), "Smartphone has been started.");
    } // at the end of function no semi-colon
    
private:
    rclcpp::Subscription<example_interfaces::msg::String>::SharedPtr subscriber_;
    
        void callback_robot_news(const example_interfaces::msg::String::SharedPtr msg){
            // std::cout << msg->data.c_str() << std::endl;
            // "%s" be careful the s is lawer case letter
            RCLCPP_INFO(this->get_logger(), "%s", msg->data.c_str());
    }

};  // at the end of class needs the semi-colon

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    //make_shared created the Node class instance and node shared_ptr at one time
    //node is shared_ptr, "std::" equal to "using namespace std;"
    auto node = std::make_shared<SmartphoneNode>();  // modify name
    // spin() need to input the Node class shared_ptr
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
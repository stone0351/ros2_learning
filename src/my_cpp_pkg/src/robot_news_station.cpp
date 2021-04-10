// Don't forget to update the CMakeList.txt
#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"

// MyCustomNode is child class of rclcpp::Node
class RobotNewsStationNode : public rclcpp::Node // modify name
{
public:
    // MyCustomNode() is function same name as its class name, so it is constructor
    // constructor will be automatically called when an object of a class is created
    RobotNewsStationNode():Node("robot_news_station") // modify name
    {
        publisher_ = this->create_publisher<example_interfaces::msg::String>("robot_news", 10);
        // std::bind took 1st parameter a function i.e. &MyFunc, then its arguments as _1 & _2 as his own arguments.
        // below std::bind returns a function object
        // original func publish_news() has no arguments, no _1 , _2, etc.
        // call_back_OBJ is just calling class RobotNewsStationNode member function publish_news() 
        auto call_back_OBJ = std::bind(&RobotNewsStationNode::publish_news, this);
        RCLCPP_INFO(this->get_logger(), "Robot News Station has been stated");
        timer_ = this->create_wall_timer(std::chrono::milliseconds(500), call_back_OBJ);
    } // at the end of function no semi-colon
    
private:
    std::string robot_name_ = "CPP88";
    rclcpp::Publisher<example_interfaces::msg::String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;

    void publish_news(){
        example_interfaces::msg::String msg;
        msg.data = "Hi, this is " + robot_name_ + " from the robot_news_station.";
        publisher_->publish(msg);
    }

};  // at the end of class needs the semi-colon

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    //make_shared created the Node class instance and node shared_ptr at one time
    //node is shared_ptr, "std::" equal to "using namespace std;"
    auto node = std::make_shared<RobotNewsStationNode>();  // modify name
    // spin() need to input the Node class shared_ptr
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
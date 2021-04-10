// Don't forget to update the CMakeList.txt
#include "rclcpp/rclcpp.hpp"

// MyCustomNode is child class of rclcpp::Node
class MyCustomNode : public rclcpp::Node // modify name
{
public:
    // MyCustomNode() is function same name as its class name, so it is constructor
    // constructor will be automatically called when an object of a class is created
    MyCustomNode():Node("node_name") // modify name
    {

    } // at the end of function no semi-colon
    
private:

};  // at the end of class needs the semi-colon

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    //make_shared created the Node class instance and node shared_ptr at one time
    //node is shared_ptr, "std::" equal to "using namespace std;"
    auto node = std::make_shared<MyCustomNode>();  // modify name
    // spin() need to input the Node class shared_ptr
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
// need to edit c_cpp_properties.json first include the path
#include "rclcpp/rclcpp.hpp"

// MyNode is child class of rclcpp::Node
class MyNode: public rclcpp::Node
{
public:
    // MyNode() is class constructor, inherite from parent Node.Node()
    // constructor will be automatically called when an object of a class is created.
    //To create a constructor, use the same name as the class, followed by parentheses ()
    MyNode():Node("cpp_test")
    {
        // "this" is the class pointer 
        RCLCPP_INFO(this->get_logger(), "Hello Cpp Node");
        // std::bind took 1st parameter a function i.e. &MyFunc, then its arguments as _1 & _2 as his own arguments.
        // below std::bind returns a function object
        // original func timer_callback() has no arguments, no _1 , _2, etc.
        // bind_func_OBJ is just calling class MyNode member function timer_callback()
        auto bind_func_OBJ = std::bind(&MyNode::timer_callback, this);
        // ‘\n’ single quotes are needed. When embedded into text double-quoted, single quotes aren’t needed.
        // Prefer ‘\n’ over std::endl when outputting text to the console
        std::cout << "std::bind(&MyNode::timer_callback, this)= " << &bind_func_OBJ << '\n';
        timer_ = this->create_wall_timer(std::chrono::milliseconds(500), bind_func_OBJ);
    }

private:
    rclcpp::TimerBase::SharedPtr timer_;
    int counter_ = 0;
    void timer_callback() 
    {
        counter_ += 1;
        // "Hello %d", counter_ is similar to printf 
        RCLCPP_INFO(this->get_logger(), "Hello %d", counter_);
    }
   
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    //make_shared created the Node class instance and node shared_ptr at one time
    //node is shared_ptr, "std::" equal to "using namespace std;"
    auto node = std::make_shared<MyNode>();
    // spin() need to input the Node class shared_ptr
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
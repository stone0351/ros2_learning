# don't forget to update the execution table entry_points at the setup.py
import rclpy
from rclpy.node import Node

# don't forget to update <depend> at package.xml
from example_interfaces.msg import String


class SmartphoneNode(Node):  # modify name
    def __init__(self):
        super().__init__("Smartphone")  # modify name
        # self.subscriber type is <class 'rclpy.subscription.Subscription'>
        self.subscriber_ = self.create_subscription(
            String, "robot_news", self.callback_robot_news, 10)
        # print(type(self.subscriber_))
        # print(dir(rclpy.subscription.Subscription))
        self.get_logger().info("Smartphone has been started.")

    def callback_robot_news(self, msg):
        self.get_logger().info(msg.data)


def main(args=None):
    rclpy.init(args=args)
    node = SmartphoneNode()  # modify name
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()

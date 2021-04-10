import rclpy
from rclpy.node import Node
# don't forget to update <depend> at package.xml
from example_interfaces.msg import String

class RobotNewsStationNode(Node): # modify name
    def __init__(self):
        super().__init__("robot_news_station") # modify name


        self.robot_name_ = "PYY88"
        # self.publisher type is <class 'rclpy.publisher.Publisher'>
        # create_publisher() 3 agrs: MsgType:String, TopicName:"robot_news", MsgBufferNum(QOS):10
        self.publisher_ = self.create_publisher(String, "robot_news", 10)
        # print(type(self.publisher_))
        self.timer_ = self.create_timer(0.5, self.publish_news)
        self.get_logger().info("Robot News Station has been stated")

    def publish_news(self):
        msg = String() # create an instance
        msg.data = "Hi, this is " + str(self.robot_name_) + " from the robot_news_station."
        self.publisher_.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    node = RobotNewsStationNode() # modify name
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()
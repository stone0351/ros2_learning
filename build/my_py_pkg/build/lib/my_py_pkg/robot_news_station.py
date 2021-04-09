import rclpy
from rclpy.node import Node
# don't forget to update <depend> at package.xml
from example_interfaces.msg import String

class RobotNewsStationNode(Node): # modify name
    def __init__(self):
        super().__init__("robot_news_station") # modify name

        # 3 parameters: MsgType:String, TopicName:"robot_news", MsgBufferNum(QOS):10
        self.publisher_ = self.create_publisher(String, "robot_news", 10)
        self.counter_ = 0
        self.create_timer(0.5, self.timer_callback)

    def publish_news(self):
        msg = String() # create an instance
        msg.data = "Hello"
        self.publisher_.publish(msg)
    
    def timer_callback(self):
        self.counter_ += 1
        self.publish_news()

def main(args=None):
    rclpy.init(args=args)
    node = RobotNewsStationNode() # modify name
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()
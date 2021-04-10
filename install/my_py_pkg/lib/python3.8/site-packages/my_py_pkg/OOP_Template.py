# don't forget to update the execution table entry_points at the setup.py
import rclpy
from rclpy.node import Node

class MyCustomNode(Node): # modify name
    def __init__(self):
        super().__init__("node_name") # modify name


def main(args=None):
    rclpy.init(args=args)
    node = MyCustomNode() # modify name
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()
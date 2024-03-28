#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

class MyNode(Node):

    def __init__(self):
        super().__init__("package_1")
        self.counter_= 0
        self.get_logger().info("Hello from package 2")
        self.create_timer(0.5,self.timer_callback)

    def timer_callback(self):
        self.counter_ +=1
        self.get_logger().info("Hello count : " + str(self.counter_))

def main(args=None):
    rclpy.init(args=args)
    node=MyNode()
    rclpy.spin(node)
    rclpy.shutdown()
    
if __name__== "__main__":
    main()
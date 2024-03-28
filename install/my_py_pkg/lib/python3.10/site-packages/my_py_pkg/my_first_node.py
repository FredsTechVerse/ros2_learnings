#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
def main(args=None):
    rclpy.init(args=args)
    node=Node("py_test")
    node.get_logger().info("Hello , its Alfred writing the first node program which is being automatically rebuild")
    rclpy.spin(node)
    rclpy.shutdown()
if __name__== "__main__":
    main()
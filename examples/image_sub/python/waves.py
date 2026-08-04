#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
import numpy as np
import math

class OscilloscopePublisher(Node):
    def __init__(self):
        super().__init__('oscilloscope_node')
        self.publisher_ = self.create_publisher(Image, '/matrix_image', 10)

        self.width = 13
        self.height = 8
        self.t = 0.0

        # Timer for ~20 FPS
        self.timer = self.create_timer(0.05, self.timer_callback)

    def timer_callback(self):
        # Create a blank 8-bit canvas
        canvas = np.zeros((self.height, self.width), dtype=np.uint8)

        self.t += 0.15

        for x in range(self.width):
            # Calculate two interfering sine waves
            # Scale x to fit wave cycles into 13 pixels
            norm_x = x * 0.5

            # Wave 1: Fast moving, Wave 2: Slow drifting
            y1 = math.sin(norm_x + self.t)
            y2 = math.sin(norm_x * 0.6 - self.t * 0.5)

            # Combine waves and map to the 8-pixel height (center is 3.5)
            combined_y = 3.5 + (y1 + y2) * 1.8

            # Draw the "string" with vertical intensity falloff (Glow effect)
            for y_offset in range(-1, 2):
                target_y = int(round(combined_y + y_offset))

                if 0 <= target_y < self.height:
                    if y_offset == 0:
                        # Core of the string: Max intensity (will be 7 on Arduino)
                        canvas[target_y, x] = 255
                    else:
                        # Glow edges: Mid intensity (will be 2-3 on Arduino)
                        # We use 96 so that 96 >> 5 = 3
                        canvas[target_y, x] = max(canvas[target_y, x], 96)

        msg = Image()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = "matrix_frame"
        msg.height = self.height
        msg.width = self.width
        msg.encoding = "mono8"
        msg.step = self.width
        msg.data = canvas.flatten().tolist()
        self.publisher_.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    node = OscilloscopePublisher()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
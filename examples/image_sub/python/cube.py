#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
import numpy as np
import cv2
import math

class UltraLightCubePublisher(Node):
    def __init__(self):
        super().__init__('cube_publisher_node')
        self.publisher_ = self.create_publisher(Image, '/matrix_image', 10)

        self.width = 13
        self.height = 8
        self.angle_x = 0.0
        self.angle_y = 0.0
        self.angle_z = 0.0

        self.vertices = np.array([
            [-1, -1, -1], [1, -1, -1], [1, 1, -1], [-1, 1, -1],
            [-1, -1,  1], [1, -1,  1], [1, 1,  1], [-1, 1,  1]
        ], dtype=np.float32)

        self.edges = [
            (0,1), (1,2), (2,3), (3,0),
            (4,5), (5,6), (6,7), (7,4),
            (0,4), (1,5), (2,6), (3,7)
        ]

        self.timer = self.create_timer(1.0 / 15.0, self.timer_callback)

    def timer_callback(self):
        canvas = np.zeros((self.height, self.width), dtype=np.uint8)

        self.angle_x += 0.07
        self.angle_y += 0.09
        self.angle_z += 0.04

        rx = np.array([[1, 0, 0], [0, math.cos(self.angle_x), -math.sin(self.angle_x)], [0, math.sin(self.angle_x), math.cos(self.angle_x)]])
        ry = np.array([[math.cos(self.angle_y), 0, math.sin(self.angle_y)], [0, 1, 0], [-math.sin(self.angle_y), 0, math.cos(self.angle_y)]])
        rz = np.array([[math.cos(self.angle_z), -math.sin(self.angle_z), 0], [math.sin(self.angle_z), math.cos(self.angle_z), 0], [0, 0, 1]])

        r_matrix = rz @ ry @ rx

        # Store rotated vertices to calculate depth for intensity scaling
        rotated_vertices = []
        projected_points = []
        for vertex in self.vertices:
            rotated = r_matrix @ vertex
            rotated_vertices.append(rotated)

            # Projection logic
            x_2d = int(self.width / 2 + rotated[0] * 2.2)
            y_2d = int(self.height / 2 + rotated[1] * 2.2)
            projected_points.append((x_2d, y_2d))

        for edge in self.edges:
            pt1 = projected_points[edge[0]]
            pt2 = projected_points[edge[1]]

            # IMPROVEMENT: Calculate depth-based intensity (Z-shading)
            # Front of the cube (higher Z) will be brighter, back will be dimmer.
            avg_z = (rotated_vertices[edge[0]][2] + rotated_vertices[edge[1]][2]) / 2.0

            # Map Z (approx -1.7 to 1.7) to intensity range 64-255.
            # On the Arduino (>> 5), 255 becomes 7 (max), 64 becomes 2.
            # This uses the 0-7 span to show 3D depth without blurring the image.
            intensity = int(((avg_z + 1.7) / 3.4) * 191) + 64
            intensity = max(0, min(255, intensity))

            # Use LINE_8 (default) for sharp 1-pixel lines.
            cv2.line(canvas, pt1, pt2, intensity, 1)

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
    node = UltraLightCubePublisher()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
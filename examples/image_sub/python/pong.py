
#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
import numpy as np

class PongPublisher(Node):
    def __init__(self):
        super().__init__('pong_node')
        self.publisher_ = self.create_publisher(Image, '/matrix_image', 10)

        self.width = 13
        self.height = 8

        # Game State
        self.ball_x = 6.0
        self.ball_y = 4.0
        self.ball_dx = 0.5
        self.ball_dy = 0.3

        self.paddle_h = 3
        self.p1_y = 2.0
        self.p2_y = 2.0

        # Persistent canvas for the motion blur trail effect
        self.canvas = np.zeros((self.height, self.width), dtype=np.uint8)

        self.timer = self.create_timer(0.06, self.timer_callback)

    def timer_callback(self):
        # 1. Fade the previous frame to create a motion trail
        # Multiplying by 0.5 quickly drops the intensity (255 -> 127 -> 63 -> 31)
        # This maps to intensity 7 -> 3 -> 1 -> 0 on the Arduino
        self.canvas = (self.canvas * 0.5).astype(np.uint8)

        # 2. Update Ball Position
        self.ball_x += self.ball_dx
        self.ball_y += self.ball_dy

        # 3. Wall Collisions (Top/Bottom)
        if self.ball_y <= 0 or self.ball_y >= self.height - 1:
            self.ball_dy *= -1

        # 4. Paddle Logic (Simple AI)
        # Move paddles towards the ball's Y position
        self.p1_y += (self.ball_y - (self.p1_y + self.paddle_h/2)) * 0.2
        self.p2_y += (self.ball_y - (self.p2_y + self.paddle_h/2)) * 0.2

        # 5. Paddle Collisions
        # Left Paddle
        if self.ball_x <= 1 and self.p1_y <= self.ball_y <= self.p1_y + self.paddle_h:
            self.ball_dx = abs(self.ball_dx)
        # Right Paddle
        if self.ball_x >= self.width - 2 and self.p2_y <= self.ball_y <= self.p2_y + self.paddle_h:
            self.ball_dx = -abs(self.ball_dx)

        # 6. Reset if Out of Bounds
        if self.ball_x < 0 or self.ball_x > self.width:
            self.ball_x, self.ball_y = 6.0, 4.0

        # 7. Draw Paddles (Intensity 5: 160 >> 5 = 5)
        for i in range(self.paddle_h):
            y1 = int(np.clip(self.p1_y + i, 0, self.height - 1))
            y2 = int(np.clip(self.p2_y + i, 0, self.height - 1))
            self.canvas[y1, 0] = 160
            self.canvas[y2, self.width - 1] = 160

        # 8. Draw Ball (Intensity 7: 255 >> 5 = 7)
        bx = int(np.clip(self.ball_x, 0, self.width - 1))
        by = int(np.clip(self.ball_y, 0, self.height - 1))
        self.canvas[by, bx] = 255

        # 9. Publish
        msg = Image()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = "matrix_frame"
        msg.height = self.height
        msg.width = self.width
        msg.encoding = "mono8"
        msg.step = self.width
        msg.data = self.canvas.flatten().tolist()
        self.publisher_.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    node = PongPublisher()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
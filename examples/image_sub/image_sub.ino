/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#include <Arduino_RouterBridge_ROS.h>
#include <Arduino_LED_Matrix.h>

// 1. Initialize Matrix and Thread-Safety Mutex
Arduino_LED_Matrix matrix;

// 2. Completed Image Callback
void imageCallback(sensor_msgs::msg::Image* msg, void* arg) {
    Monitor.println("image cbk --");

    Monitor.print("image h: ");
    Monitor.println(msg->height);
    Monitor.print("image w: ");
    Monitor.println(msg->width);
    Monitor.print("enc: ");
    Monitor.println(msg->encoding);
    Monitor.println("be: ");
    Monitor.println(msg->is_bigendian);
    Monitor.println("step: ");
    Monitor.println(msg->step);
    Monitor.print("data size: ");
    Monitor.println(msg->data.size());

    if (msg->data.empty()) return;

    const size_t expected_pixels = 104;
    uint8_t local_frame_buffer[expected_pixels] = {0};

    Monitor.println("img unpacking");
    // Check if we are dealing with the optimized mono1 bitmask
    if (msg->encoding == "mono1") {
        Monitor.println("mono1 enc");
        size_t pixel_idx = 0;
        size_t bytes_per_row = msg->step;

        for (uint32_t row = 0; row < msg->height; ++row) {
            for (uint32_t col = 0; col < msg->width; ++col) {
                // Find which byte and which specific bit contains this pixel
                size_t byte_idx = (row * bytes_per_row) + (col / 8);
                int bit_shift = 7 - (col % 8); // NumPy packs MSB-first

                // Extract the bit (0 or 1)
                uint8_t bit = (msg->data[byte_idx] >> bit_shift) & 0x01;

                // Scale it up to your matrix brightness (1 -> Full brightness 7, 0 -> 0)
                if (pixel_idx < expected_pixels) {
                    local_frame_buffer[pixel_idx++] = bit ? 7 : 0;
                }
            }
        }
    } else {
        Monitor.println("mono8 enc");
        // Fallback for raw mono8 if the buffer size permits it
        size_t pixels_to_copy = (msg->data.size() < expected_pixels) ? msg->data.size() : expected_pixels;
        for (size_t i = 0; i < pixels_to_copy; ++i) {
            local_frame_buffer[i] = msg->data[i] >> 5;
        }
    }
Monitor.println("drawing");
    matrix.draw(local_frame_buffer);

    (void)arg;
}
// 3. Node Class Definition
class ImageSub : public ros2ino::Node {
public:
    ImageSub() : Node("image_sub_node") {
        ros2ino::Subscriber<sensor_msgs::msg::Image>* subscription_ =
            this->create_subscription<sensor_msgs::msg::Image>(
                "/matrix_image",
                (ros2ino::CallBack)imageCallback,
                nullptr
            );

        if (subscription_ != nullptr) {
            Serial1.println("Subscribed to /matrix_image successfully!");
        } else {
            Serial1.println("Failed to subscribe to image topic.");
        }
    }
};

void setup() {
    Serial1.begin(115200);
    Bridge.begin();
    Monitor.begin(115200);

    // Initialize the LED matrix hardware with 3-bit depth configuration
    matrix.begin();
    matrix.setGrayscaleBits(3);
    matrix.clear();

    Monitor.println("LED Matrix Initialized in 3-bit Grayscale Mode.");
}

void loop() {
    static ImageSub node;
    ros2ino::spin(&node);

    static unsigned long last_serial_print = 0;
    if (millis() - last_serial_print > 5000) {
        Monitor.println("image_sub node spinning...");
        last_serial_print = millis();
    }
}
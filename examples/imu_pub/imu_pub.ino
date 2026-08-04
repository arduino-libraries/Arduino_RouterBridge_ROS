/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#include <Arduino_RouterBridge_ROS.h>

ros2ino::Node myNode("imu_node");
ros2ino::Publisher<sensor_msgs::msg::Imu>* imu_pub = nullptr;

void setup() {
    Serial1.begin(115200);
    Bridge.begin();
    Monitor.begin(115200);

    // Create the publisher for the IMU topic
    imu_pub = myNode.create_publisher<sensor_msgs::msg::Imu>("/imu/data_raw");
}

void loop() {
    static uint32_t seq = 0;

    if (imu_pub != nullptr) {
        sensor_msgs::msg::Imu imu_msg;

        // 1. Prepare sub-messages
        std_msgs::msg::Header header;
        header.stamp.sec = millis() / 1000;
        header.stamp.nanosec = (millis() % 1000) * 1000000;
        header.frame_id = "imu_link";

        geometry_msgs::msg::Quaternion orientation;
        orientation.x = 0.0; orientation.y = 0.0; orientation.z = 0.0; orientation.w = 1.0;

        geometry_msgs::msg::Vector3 angular_velocity;
        angular_velocity.x = 0.05; angular_velocity.y = -0.01; angular_velocity.z = 0.02;

        geometry_msgs::msg::Vector3 linear_acceleration;
        linear_acceleration.x = 0.0; linear_acceleration.y = 0.0; linear_acceleration.z = 9.81; // Gravity

        // 2. Instantiate the IMU struct using your defined constructor
        imu_msg.header = header;
        imu_msg.orientation = orientation;
        imu_msg.angular_velocity = angular_velocity;
        imu_msg.linear_acceleration = linear_acceleration;

        // Note: orientation_covariance, angular_velocity_covariance,
        // and linear_acceleration_covariance remain empty vectors.

        // 3. Publish the message
        imu_pub->publish(&imu_msg);
    }

    delay(100); // Publish at roughly 10 Hz
}
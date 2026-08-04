/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#include <Arduino_RouterBridge_ROS.h>
#include "Arduino_Modulino.h"

ModulinoMovement movement;

ros2ino::Node myNode("imu_node");
ros2ino::Publisher<sensor_msgs::msg::Imu>* imu_pub = nullptr;


float x, y, z;
float roll, pitch, yaw;

void setup() {
    Bridge.begin();
    Modulino.begin(Wire1);
    movement.begin();

    // Create the publisher for the IMU topic
    imu_pub = myNode.create_publisher<sensor_msgs::msg::Imu>("/imu/data_raw");
}

void loop() {
    static uint32_t seq = 0;

    movement.update();

    // Get acceleration and gyroscope values
    x = movement.getX() * 9.8;
    y = movement.getY() * 9.8;
    z = movement.getZ() * 9.8;
    roll = movement.getRoll();
    pitch = movement.getPitch();
    yaw = movement.getYaw();

    if (imu_pub != nullptr) {
        // 1. Prepare sub-messages
        std_msgs::msg::Header header;
        header.stamp = builtin_interfaces::msg::Time();
        header.frame_id = "imu_link";

        geometry_msgs::msg::Quaternion orientation;
        orientation.x = 0.0; orientation.y = 0.0; orientation.z = 0.0; orientation.w = 1.0;

        std::array<double, 9> covariance = {0.01, 0.0, 0.0, 0.0, 0.01, 0.0, 0.0, 0.0, 0.01};

        geometry_msgs::msg::Vector3 angular_velocity;
        angular_velocity.x = 0.00; angular_velocity.y = 0.0; angular_velocity.z = 0.0;

        geometry_msgs::msg::Vector3 linear_acceleration;
        linear_acceleration.x = x; linear_acceleration.y = y; linear_acceleration.z = z; // Gravity

        // 2. Instantiate the IMU struct using your defined constructor
        sensor_msgs::msg::Imu imu_msg;
        imu_msg.header = header;
        imu_msg.orientation = orientation;
        imu_msg.angular_velocity = angular_velocity;
        imu_msg.linear_acceleration = linear_acceleration;
        imu_msg.linear_acceleration_covariance = covariance;
        imu_msg.orientation_covariance = covariance;
        imu_msg.angular_velocity_covariance = covariance;

        // Note: orientation_covariance, angular_velocity_covariance,
        // and linear_acceleration_covariance remain empty vectors.

        // 3. Publish the message
        imu_pub->publish(&imu_msg);
    }

}
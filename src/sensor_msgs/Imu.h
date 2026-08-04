/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_SENSOR_MSGS_IMU_H
#define ROUTERBRIDGE_ROS_SENSOR_MSGS_IMU_H
#include <MsgPack.h>

#include "../geometry_msgs/Quaternion.h"
#include "../geometry_msgs/Vector3.h"
#include "../std_msgs/Header.h"

#define ROUTERBRIDGE_ROS_SENSOR_MSGS_IMU "sensor_msgs/msg/Imu"

namespace sensor_msgs {

namespace msg {

    struct Imu {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_SENSOR_MSGS_IMU;

        MsgPack::str_t key1 = "header";
        std_msgs::msg::Header header;

        MsgPack::str_t key2 = "orientation";
        geometry_msgs::msg::Quaternion orientation;

        MsgPack::str_t key3 = "orientation_covariance";
        std::array<double, 9> orientation_covariance{};

        MsgPack::str_t key4 = "angular_velocity";
        geometry_msgs::msg::Vector3 angular_velocity;

        MsgPack::str_t key5 = "angular_velocity_covariance";
        std::array<double, 9> angular_velocity_covariance{};

        MsgPack::str_t key6 = "linear_acceleration";
        geometry_msgs::msg::Vector3 linear_acceleration;

        MsgPack::str_t key7 = "linear_acceleration_covariance";
        std::array<double, 9> linear_acceleration_covariance{};

        Imu() = default;

        Imu(std_msgs::msg::Header header, geometry_msgs::msg::Quaternion orientation, std::array<double, 9> orientation_covariance, geometry_msgs::msg::Vector3 angular_velocity, std::array<double, 9> angular_velocity_covariance, geometry_msgs::msg::Vector3 linear_acceleration, std::array<double, 9> linear_acceleration_covariance): header(header), orientation(orientation), orientation_covariance(orientation_covariance), angular_velocity(angular_velocity), angular_velocity_covariance(angular_velocity_covariance), linear_acceleration(linear_acceleration), linear_acceleration_covariance(linear_acceleration_covariance) {}

        MSGPACK_DEFINE_MAP(key1, header, key2, orientation, key3, orientation_covariance, key4, angular_velocity, key5, angular_velocity_covariance, key6, linear_acceleration, key7, linear_acceleration_covariance);

        bool operator==(const Imu& other) const { return this->header == other.header && this->orientation == other.orientation && this->orientation_covariance == other.orientation_covariance && this->angular_velocity == other.angular_velocity && this->angular_velocity_covariance == other.angular_velocity_covariance && this->linear_acceleration == other.linear_acceleration && this->linear_acceleration_covariance == other.linear_acceleration_covariance; }
    };

} // namespace msg

} // namespace sensor_msgs
#endif //ROUTERBRIDGE_ROS_SENSOR_MSGS_IMU_H
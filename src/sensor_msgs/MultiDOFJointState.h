/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_SENSOR_MSGS_MULTIDOFJOINTSTATE_H
#define ROUTERBRIDGE_ROS_SENSOR_MSGS_MULTIDOFJOINTSTATE_H
#include <MsgPack.h>

#include "../geometry_msgs/Transform.h"
#include "../geometry_msgs/Twist.h"
#include "../geometry_msgs/Wrench.h"
#include "../std_msgs/Header.h"

#define ROUTERBRIDGE_ROS_SENSOR_MSGS_MULTIDOFJOINTSTATE "sensor_msgs/msg/MultiDOFJointState"

namespace sensor_msgs {

namespace msg {

    struct MultiDOFJointState {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_SENSOR_MSGS_MULTIDOFJOINTSTATE;

        MsgPack::str_t key1 = "header";
        std_msgs::msg::Header header;

        MsgPack::str_t key2 = "joint_names";
        std::vector<MsgPack::str_t> joint_names;

        MsgPack::str_t key3 = "transforms";
        std::vector<geometry_msgs::msg::Transform> transforms;

        MsgPack::str_t key4 = "twist";
        std::vector<geometry_msgs::msg::Twist> twist;

        MsgPack::str_t key5 = "wrench";
        std::vector<geometry_msgs::msg::Wrench> wrench;

        MultiDOFJointState() = default;

        MultiDOFJointState(std_msgs::msg::Header header, std::vector<MsgPack::str_t> joint_names, std::vector<geometry_msgs::msg::Transform> transforms, std::vector<geometry_msgs::msg::Twist> twist, std::vector<geometry_msgs::msg::Wrench> wrench): header(header), joint_names(joint_names), transforms(transforms), twist(twist), wrench(wrench) {}

        MSGPACK_DEFINE_MAP(key1, header, key2, joint_names, key3, transforms, key4, twist, key5, wrench);

        bool operator==(const MultiDOFJointState& other) const { return this->header == other.header && this->joint_names == other.joint_names && this->transforms == other.transforms && this->twist == other.twist && this->wrench == other.wrench; }
    };

} // namespace msg

} // namespace sensor_msgs
#endif //ROUTERBRIDGE_ROS_SENSOR_MSGS_MULTIDOFJOINTSTATE_H
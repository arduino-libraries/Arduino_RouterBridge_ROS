/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_SENSOR_MSGS_JOINTSTATE_H
#define ROUTERBRIDGE_ROS_SENSOR_MSGS_JOINTSTATE_H
#include <MsgPack.h>

#include "../std_msgs/Header.h"

#define ROUTERBRIDGE_ROS_SENSOR_MSGS_JOINTSTATE "sensor_msgs/msg/JointState"

namespace sensor_msgs {

namespace msg {

    struct JointState {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_SENSOR_MSGS_JOINTSTATE;

        MsgPack::str_t key1 = "header";
        std_msgs::msg::Header header;

        MsgPack::str_t key2 = "name";
        std::vector<MsgPack::str_t> name;

        MsgPack::str_t key3 = "position";
        std::vector<double> position;

        MsgPack::str_t key4 = "velocity";
        std::vector<double> velocity;

        MsgPack::str_t key5 = "effort";
        std::vector<double> effort;

        JointState() = default;

        JointState(std_msgs::msg::Header header, std::vector<MsgPack::str_t> name, std::vector<double> position, std::vector<double> velocity, std::vector<double> effort): header(header), name(name), position(position), velocity(velocity), effort(effort) {}

        MSGPACK_DEFINE_MAP(key1, header, key2, name, key3, position, key4, velocity, key5, effort);

        bool operator==(const JointState& other) const { return this->header == other.header && this->name == other.name && this->position == other.position && this->velocity == other.velocity && this->effort == other.effort; }
    };

} // namespace msg

} // namespace sensor_msgs
#endif //ROUTERBRIDGE_ROS_SENSOR_MSGS_JOINTSTATE_H
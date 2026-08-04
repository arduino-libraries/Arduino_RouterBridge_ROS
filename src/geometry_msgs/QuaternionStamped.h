/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_GEOMETRY_MSGS_QUATERNIONSTAMPED_H
#define ROUTERBRIDGE_ROS_GEOMETRY_MSGS_QUATERNIONSTAMPED_H
#include <MsgPack.h>

#include "Quaternion.h"
#include "../std_msgs/Header.h"

#define ROUTERBRIDGE_ROS_GEOMETRY_MSGS_QUATERNIONSTAMPED "geometry_msgs/msg/QuaternionStamped"

namespace geometry_msgs {

namespace msg {

    struct QuaternionStamped {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_GEOMETRY_MSGS_QUATERNIONSTAMPED;

        MsgPack::str_t key1 = "header";
        std_msgs::msg::Header header;

        MsgPack::str_t key2 = "quaternion";
        Quaternion quaternion;

        QuaternionStamped() = default;

        QuaternionStamped(std_msgs::msg::Header header, Quaternion quaternion): header(header), quaternion(quaternion) {}

        MSGPACK_DEFINE_MAP(key1, header, key2, quaternion);

        bool operator==(const QuaternionStamped& other) const { return this->header == other.header && this->quaternion == other.quaternion; }
    };

} // namespace msg

} // namespace geometry_msgs
#endif //ROUTERBRIDGE_ROS_GEOMETRY_MSGS_QUATERNIONSTAMPED_H
/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_GEOMETRY_MSGS_TWISTSTAMPED_H
#define ROUTERBRIDGE_ROS_GEOMETRY_MSGS_TWISTSTAMPED_H
#include <MsgPack.h>

#include "Twist.h"
#include "../std_msgs/Header.h"

#define ROUTERBRIDGE_ROS_GEOMETRY_MSGS_TWISTSTAMPED "geometry_msgs/msg/TwistStamped"

namespace geometry_msgs {

namespace msg {

    struct TwistStamped {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_GEOMETRY_MSGS_TWISTSTAMPED;

        MsgPack::str_t key1 = "header";
        std_msgs::msg::Header header;

        MsgPack::str_t key2 = "twist";
        Twist twist;

        TwistStamped() = default;

        TwistStamped(std_msgs::msg::Header header, Twist twist): header(header), twist(twist) {}

        MSGPACK_DEFINE_MAP(key1, header, key2, twist);

        bool operator==(const TwistStamped& other) const { return this->header == other.header && this->twist == other.twist; }
    };

} // namespace msg

} // namespace geometry_msgs
#endif //ROUTERBRIDGE_ROS_GEOMETRY_MSGS_TWISTSTAMPED_H
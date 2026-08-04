/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_GEOMETRY_MSGS_WRENCHSTAMPED_H
#define ROUTERBRIDGE_ROS_GEOMETRY_MSGS_WRENCHSTAMPED_H
#include <MsgPack.h>

#include "Wrench.h"
#include "../std_msgs/Header.h"

#define ROUTERBRIDGE_ROS_GEOMETRY_MSGS_WRENCHSTAMPED "geometry_msgs/msg/WrenchStamped"

namespace geometry_msgs {

namespace msg {

    struct WrenchStamped {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_GEOMETRY_MSGS_WRENCHSTAMPED;

        MsgPack::str_t key1 = "header";
        std_msgs::msg::Header header;

        MsgPack::str_t key2 = "wrench";
        Wrench wrench;

        WrenchStamped() = default;

        WrenchStamped(std_msgs::msg::Header header, Wrench wrench): header(header), wrench(wrench) {}

        MSGPACK_DEFINE_MAP(key1, header, key2, wrench);

        bool operator==(const WrenchStamped& other) const { return this->header == other.header && this->wrench == other.wrench; }
    };

} // namespace msg

} // namespace geometry_msgs
#endif //ROUTERBRIDGE_ROS_GEOMETRY_MSGS_WRENCHSTAMPED_H
/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_GEOMETRY_MSGS_ACCELSTAMPED_H
#define ROUTERBRIDGE_ROS_GEOMETRY_MSGS_ACCELSTAMPED_H
#include <MsgPack.h>

#include "Accel.h"
#include "../std_msgs/Header.h"

#define ROUTERBRIDGE_ROS_GEOMETRY_MSGS_ACCELSTAMPED "geometry_msgs/msg/AccelStamped"

namespace geometry_msgs {

namespace msg {

    struct AccelStamped {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_GEOMETRY_MSGS_ACCELSTAMPED;

        MsgPack::str_t key1 = "header";
        std_msgs::msg::Header header;

        MsgPack::str_t key2 = "accel";
        Accel accel;

        AccelStamped() = default;

        AccelStamped(std_msgs::msg::Header header, Accel accel): header(header), accel(accel) {}

        MSGPACK_DEFINE_MAP(key1, header, key2, accel);

        bool operator==(const AccelStamped& other) const { return this->header == other.header && this->accel == other.accel; }
    };

} // namespace msg

} // namespace geometry_msgs
#endif //ROUTERBRIDGE_ROS_GEOMETRY_MSGS_ACCELSTAMPED_H
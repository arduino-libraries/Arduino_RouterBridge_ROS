/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_GEOMETRY_MSGS_POINTSTAMPED_H
#define ROUTERBRIDGE_ROS_GEOMETRY_MSGS_POINTSTAMPED_H
#include <MsgPack.h>

#include "Point.h"
#include "../std_msgs/Header.h"

#define ROUTERBRIDGE_ROS_GEOMETRY_MSGS_POINTSTAMPED "geometry_msgs/msg/PointStamped"

namespace geometry_msgs {

namespace msg {

    struct PointStamped {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_GEOMETRY_MSGS_POINTSTAMPED;

        MsgPack::str_t key1 = "header";
        std_msgs::msg::Header header;

        MsgPack::str_t key2 = "point";
        Point point;

        PointStamped() = default;

        PointStamped(std_msgs::msg::Header header, Point point): header(header), point(point) {}

        MSGPACK_DEFINE_MAP(key1, header, key2, point);

        bool operator==(const PointStamped& other) const { return this->header == other.header && this->point == other.point; }
    };

} // namespace msg

} // namespace geometry_msgs
#endif //ROUTERBRIDGE_ROS_GEOMETRY_MSGS_POINTSTAMPED_H
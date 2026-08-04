/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_GEOMETRY_MSGS_POLYGON_H
#define ROUTERBRIDGE_ROS_GEOMETRY_MSGS_POLYGON_H
#include <MsgPack.h>

#include "Point32.h"

#define ROUTERBRIDGE_ROS_GEOMETRY_MSGS_POLYGON "geometry_msgs/msg/Polygon"

namespace geometry_msgs {

namespace msg {

    struct Polygon {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_GEOMETRY_MSGS_POLYGON;

        MsgPack::str_t key = "points";
        std::vector<Point32> points;

        Polygon() = default;

        Polygon(std::vector<Point32> points): points(points) {}

        MSGPACK_DEFINE_MAP(key, points);

        bool operator==(const Polygon& other) const { return this->points == other.points; }
    };

} // namespace msg

} // namespace geometry_msgs
#endif //ROUTERBRIDGE_ROS_GEOMETRY_MSGS_POLYGON_H
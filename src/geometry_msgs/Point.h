/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_GEOMETRY_MSGS_POINT_H
#define ROUTERBRIDGE_ROS_GEOMETRY_MSGS_POINT_H
#include <MsgPack.h>

#define ROUTERBRIDGE_ROS_GEOMETRY_MSGS_POINT "geometry_msgs/msg/Point"

namespace geometry_msgs {

namespace msg {

    struct Point {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_GEOMETRY_MSGS_POINT;

        MsgPack::str_t key1 = "x";
        double x;

        MsgPack::str_t key2 = "y";
        double y;

        MsgPack::str_t key3 = "z";
        double z;

        Point() = default;

        Point(double x, double y, double z): x(x), y(y), z(z) {}

        MSGPACK_DEFINE_MAP(key1, x, key2, y, key3, z);

        bool operator==(const Point& other) const { return this->x == other.x && this->y == other.y && this->z == other.z; }
    };

} // namespace msg

} // namespace geometry_msgs
#endif //ROUTERBRIDGE_ROS_GEOMETRY_MSGS_POINT_H
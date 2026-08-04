/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_GEOMETRY_MSGS_POINT32_H
#define ROUTERBRIDGE_ROS_GEOMETRY_MSGS_POINT32_H
#include <MsgPack.h>

#define ROUTERBRIDGE_ROS_GEOMETRY_MSGS_POINT32 "geometry_msgs/msg/Point32"

namespace geometry_msgs {

namespace msg {

    struct Point32 {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_GEOMETRY_MSGS_POINT32;

        MsgPack::str_t key1 = "x";
        float x;

        MsgPack::str_t key2 = "y";
        float y;

        MsgPack::str_t key3 = "z";
        float z;

        Point32() = default;

        Point32(float x, float y, float z): x(x), y(y), z(z) {}

        MSGPACK_DEFINE_MAP(key1, x, key2, y, key3, z);

        bool operator==(const Point32& other) const { return this->x == other.x && this->y == other.y && this->z == other.z; }
    };

} // namespace msg

} // namespace geometry_msgs
#endif //ROUTERBRIDGE_ROS_GEOMETRY_MSGS_POINT32_H
/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_GEOMETRY_MSGS_QUATERNION_H
#define ROUTERBRIDGE_ROS_GEOMETRY_MSGS_QUATERNION_H
#include <MsgPack.h>

#define ROUTERBRIDGE_ROS_GEOMETRY_MSGS_QUATERNION "geometry_msgs/msg/Quaternion"

namespace geometry_msgs {

namespace msg {

    struct Quaternion {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_GEOMETRY_MSGS_QUATERNION;

        MsgPack::str_t key1 = "x";
        double x;

        MsgPack::str_t key2 = "y";
        double y;

        MsgPack::str_t key3 = "z";
        double z;

        MsgPack::str_t key4 = "w";
        double w;

        Quaternion() = default;

        Quaternion(double x, double y, double z, double w): x(x), y(y), z(z), w(w) {}

        MSGPACK_DEFINE_MAP(key1, x, key2, y, key3, z, key4, w);

        bool operator==(const Quaternion& other) const { return this->x == other.x && this->y == other.y && this->z == other.z && this->w == other.w; }
    };

} // namespace msg

} // namespace geometry_msgs
#endif //ROUTERBRIDGE_ROS_GEOMETRY_MSGS_QUATERNION_H
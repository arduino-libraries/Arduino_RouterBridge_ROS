/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_GEOMETRY_MSGS_VECTOR3STAMPED_H
#define ROUTERBRIDGE_ROS_GEOMETRY_MSGS_VECTOR3STAMPED_H
#include <MsgPack.h>

#include "Vector3.h"
#include "../std_msgs/Header.h"

#define ROUTERBRIDGE_ROS_GEOMETRY_MSGS_VECTOR3STAMPED "geometry_msgs/msg/Vector3Stamped"

namespace geometry_msgs {

namespace msg {

    struct Vector3Stamped {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_GEOMETRY_MSGS_VECTOR3STAMPED;

        MsgPack::str_t key1 = "header";
        std_msgs::msg::Header header;

        MsgPack::str_t key2 = "vector";
        Vector3 vector;

        Vector3Stamped() = default;

        Vector3Stamped(std_msgs::msg::Header header, Vector3 vector): header(header), vector(vector) {}

        MSGPACK_DEFINE_MAP(key1, header, key2, vector);

        bool operator==(const Vector3Stamped& other) const { return this->header == other.header && this->vector == other.vector; }
    };

} // namespace msg

} // namespace geometry_msgs
#endif //ROUTERBRIDGE_ROS_GEOMETRY_MSGS_VECTOR3STAMPED_H
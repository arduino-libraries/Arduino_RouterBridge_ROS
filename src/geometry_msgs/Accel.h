/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_GEOMETRY_MSGS_ACCEL_H
#define ROUTERBRIDGE_ROS_GEOMETRY_MSGS_ACCEL_H
#include <MsgPack.h>

#include "Vector3.h"

#define ROUTERBRIDGE_ROS_GEOMETRY_MSGS_ACCEL "geometry_msgs/msg/Accel"

namespace geometry_msgs {

namespace msg {

    struct Accel {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_GEOMETRY_MSGS_ACCEL;

        MsgPack::str_t key1 = "linear";
        Vector3 linear;

        MsgPack::str_t key2 = "angular";
        Vector3 angular;

        Accel() = default;

        Accel(Vector3 linear, Vector3 angular): linear(linear), angular(angular) {}

        MSGPACK_DEFINE_MAP(key1, linear, key2, angular);

        bool operator==(const Accel& other) const { return this->linear == other.linear && this->angular == other.angular; }
    };

} // namespace msg

} // namespace geometry_msgs
#endif //ROUTERBRIDGE_ROS_GEOMETRY_MSGS_ACCEL_H
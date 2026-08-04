/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_GEOMETRY_MSGS_TWIST_H
#define ROUTERBRIDGE_ROS_GEOMETRY_MSGS_TWIST_H
#include <MsgPack.h>

#include "Vector3.h"

#define ROUTERBRIDGE_ROS_GEOMETRY_MSGS_TWIST "geometry_msgs/msg/Twist"

namespace geometry_msgs {

namespace msg {

    struct Twist {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_GEOMETRY_MSGS_TWIST;

        MsgPack::str_t key1 = "linear";
        Vector3 linear;

        MsgPack::str_t key2 = "angular";
        Vector3 angular;

        Twist() = default;

        Twist(Vector3 linear, Vector3 angular): linear(linear), angular(angular) {}

        MSGPACK_DEFINE_MAP(key1, linear, key2, angular);

        bool operator==(const Twist& other) const { return this->linear == other.linear && this->angular == other.angular; }
    };

} // namespace msg

} // namespace geometry_msgs
#endif //ROUTERBRIDGE_ROS_GEOMETRY_MSGS_TWIST_H
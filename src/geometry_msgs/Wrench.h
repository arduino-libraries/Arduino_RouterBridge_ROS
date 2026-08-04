/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_GEOMETRY_MSGS_WRENCH_H
#define ROUTERBRIDGE_ROS_GEOMETRY_MSGS_WRENCH_H
#include <MsgPack.h>

#include "Vector3.h"

#define ROUTERBRIDGE_ROS_GEOMETRY_MSGS_WRENCH "geometry_msgs/msg/Wrench"

namespace geometry_msgs {

namespace msg {

    struct Wrench {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_GEOMETRY_MSGS_WRENCH;

        MsgPack::str_t key1 = "force";
        Vector3 force;

        MsgPack::str_t key2 = "torque";
        Vector3 torque;

        Wrench() = default;

        Wrench(Vector3 force, Vector3 torque): force(force), torque(torque) {}

        MSGPACK_DEFINE_MAP(key1, force, key2, torque);

        bool operator==(const Wrench& other) const { return this->force == other.force && this->torque == other.torque; }
    };

} // namespace msg

} // namespace geometry_msgs
#endif //ROUTERBRIDGE_ROS_GEOMETRY_MSGS_WRENCH_H
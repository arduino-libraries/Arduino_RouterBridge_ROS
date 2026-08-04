/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_GEOMETRY_MSGS_POSE_H
#define ROUTERBRIDGE_ROS_GEOMETRY_MSGS_POSE_H
#include <MsgPack.h>

#include "Point.h"
#include "Quaternion.h"

#define ROUTERBRIDGE_ROS_GEOMETRY_MSGS_POSE "geometry_msgs/msg/Pose"

namespace geometry_msgs {

namespace msg {

    struct Pose {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_GEOMETRY_MSGS_POSE;

        MsgPack::str_t key1 = "position";
        Point position;

        MsgPack::str_t key2 = "orientation";
        Quaternion orientation;

        Pose() = default;

        Pose(Point position, Quaternion orientation): position(position), orientation(orientation) {}

        MSGPACK_DEFINE_MAP(key1, position, key2, orientation);

        bool operator==(const Pose& other) const { return this->position == other.position && this->orientation == other.orientation; }
    };

} // namespace msg

} // namespace geometry_msgs
#endif //ROUTERBRIDGE_ROS_GEOMETRY_MSGS_POSE_H
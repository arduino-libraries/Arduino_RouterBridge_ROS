/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_GEOMETRY_MSGS_POSEARRAY_H
#define ROUTERBRIDGE_ROS_GEOMETRY_MSGS_POSEARRAY_H
#include <MsgPack.h>

#include "Pose.h"
#include "../std_msgs/Header.h"

#define ROUTERBRIDGE_ROS_GEOMETRY_MSGS_POSEARRAY "geometry_msgs/msg/PoseArray"

namespace geometry_msgs {

namespace msg {

    struct PoseArray {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_GEOMETRY_MSGS_POSEARRAY;

        MsgPack::str_t key1 = "header";
        std_msgs::msg::Header header;

        MsgPack::str_t key2 = "poses";
        std::vector<Pose> poses;

        PoseArray() = default;

        PoseArray(std_msgs::msg::Header header, std::vector<Pose> poses): header(header), poses(poses) {}

        MSGPACK_DEFINE_MAP(key1, header, key2, poses);

        bool operator==(const PoseArray& other) const { return this->header == other.header && this->poses == other.poses; }
    };

} // namespace msg

} // namespace geometry_msgs
#endif //ROUTERBRIDGE_ROS_GEOMETRY_MSGS_POSEARRAY_H
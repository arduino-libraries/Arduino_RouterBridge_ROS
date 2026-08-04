/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_GEOMETRY_MSGS_POSEWITHCOVARIANCE_H
#define ROUTERBRIDGE_ROS_GEOMETRY_MSGS_POSEWITHCOVARIANCE_H
#include <MsgPack.h>

#include "Pose.h"

#define ROUTERBRIDGE_ROS_GEOMETRY_MSGS_POSEWITHCOVARIANCE "geometry_msgs/msg/PoseWithCovariance"

namespace geometry_msgs {

namespace msg {

    struct PoseWithCovariance {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_GEOMETRY_MSGS_POSEWITHCOVARIANCE;

        MsgPack::str_t key1 = "pose";
        Pose pose;

        MsgPack::str_t key2 = "covariance";
        std::array<double, 36> covariance{};

        PoseWithCovariance() = default;

        PoseWithCovariance(Pose pose, std::array<double, 36> covariance): pose(pose), covariance(covariance) {}

        MSGPACK_DEFINE_MAP(key1, pose, key2, covariance);

        bool operator==(const PoseWithCovariance& other) const { return this->pose == other.pose && this->covariance == other.covariance; }
    };

} // namespace msg

} // namespace geometry_msgs
#endif //ROUTERBRIDGE_ROS_GEOMETRY_MSGS_POSEWITHCOVARIANCE_H
/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_GEOMETRY_MSGS_TWISTWITHCOVARIANCE_H
#define ROUTERBRIDGE_ROS_GEOMETRY_MSGS_TWISTWITHCOVARIANCE_H
#include <MsgPack.h>

#include "Twist.h"

#define ROUTERBRIDGE_ROS_GEOMETRY_MSGS_TWISTWITHCOVARIANCE "geometry_msgs/msg/TwistWithCovariance"

namespace geometry_msgs {

namespace msg {

    struct TwistWithCovariance {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_GEOMETRY_MSGS_TWISTWITHCOVARIANCE;

        MsgPack::str_t key1 = "twist";
        Twist twist;

        MsgPack::str_t key2 = "covariance";
        std::array<double, 36> covariance{};

        TwistWithCovariance() = default;

        TwistWithCovariance(Twist twist, std::array<double, 36> covariance): twist(twist), covariance(covariance) {}

        MSGPACK_DEFINE_MAP(key1, twist, key2, covariance);

        bool operator==(const TwistWithCovariance& other) const { return this->twist == other.twist && this->covariance == other.covariance; }
    };

} // namespace msg

} // namespace geometry_msgs
#endif //ROUTERBRIDGE_ROS_GEOMETRY_MSGS_TWISTWITHCOVARIANCE_H
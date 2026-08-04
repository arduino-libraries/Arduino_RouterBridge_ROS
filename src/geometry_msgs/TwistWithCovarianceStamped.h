/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_GEOMETRY_MSGS_TWISTWITHCOVARIANCESTAMPED_H
#define ROUTERBRIDGE_ROS_GEOMETRY_MSGS_TWISTWITHCOVARIANCESTAMPED_H
#include <MsgPack.h>

#include "TwistWithCovariance.h"
#include "../std_msgs/Header.h"

#define ROUTERBRIDGE_ROS_GEOMETRY_MSGS_TWISTWITHCOVARIANCESTAMPED "geometry_msgs/msg/TwistWithCovarianceStamped"

namespace geometry_msgs {

namespace msg {

    struct TwistWithCovarianceStamped {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_GEOMETRY_MSGS_TWISTWITHCOVARIANCESTAMPED;

        MsgPack::str_t key1 = "header";
        std_msgs::msg::Header header;

        MsgPack::str_t key2 = "twist";
        TwistWithCovariance twist;

        TwistWithCovarianceStamped() = default;

        TwistWithCovarianceStamped(std_msgs::msg::Header header, TwistWithCovariance twist): header(header), twist(twist) {}

        MSGPACK_DEFINE_MAP(key1, header, key2, twist);

        bool operator==(const TwistWithCovarianceStamped& other) const { return this->header == other.header && this->twist == other.twist; }
    };

} // namespace msg

} // namespace geometry_msgs
#endif //ROUTERBRIDGE_ROS_GEOMETRY_MSGS_TWISTWITHCOVARIANCESTAMPED_H
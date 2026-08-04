/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_GEOMETRY_MSGS_ACCELWITHCOVARIANCE_H
#define ROUTERBRIDGE_ROS_GEOMETRY_MSGS_ACCELWITHCOVARIANCE_H
#include <MsgPack.h>

#include "Accel.h"

#define ROUTERBRIDGE_ROS_GEOMETRY_MSGS_ACCELWITHCOVARIANCE "geometry_msgs/msg/AccelWithCovariance"

namespace geometry_msgs {

namespace msg {

    struct AccelWithCovariance {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_GEOMETRY_MSGS_ACCELWITHCOVARIANCE;

        MsgPack::str_t key1 = "accel";
        Accel accel;

        MsgPack::str_t key2 = "covariance";
        std::array<double, 36> covariance{};

        AccelWithCovariance() = default;

        AccelWithCovariance(Accel accel, std::array<double, 36> covariance): accel(accel), covariance(covariance) {}

        MSGPACK_DEFINE_MAP(key1, accel, key2, covariance);

        bool operator==(const AccelWithCovariance& other) const { return this->accel == other.accel && this->covariance == other.covariance; }
    };

} // namespace msg

} // namespace geometry_msgs
#endif //ROUTERBRIDGE_ROS_GEOMETRY_MSGS_ACCELWITHCOVARIANCE_H
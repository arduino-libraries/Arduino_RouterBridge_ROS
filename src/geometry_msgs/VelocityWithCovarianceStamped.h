/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_GEOMETRY_MSGS_VELOCITYWITHCOVARIANCESTAMPED_H
#define ROUTERBRIDGE_ROS_GEOMETRY_MSGS_VELOCITYWITHCOVARIANCESTAMPED_H
#include <MsgPack.h>

#include "TwistWithCovariance.h"
#include "../std_msgs/Header.h"

#define ROUTERBRIDGE_ROS_GEOMETRY_MSGS_VELOCITYWITHCOVARIANCESTAMPED "geometry_msgs/msg/VelocityWithCovarianceStamped"

namespace geometry_msgs {

namespace msg {

    struct VelocityWithCovarianceStamped {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_GEOMETRY_MSGS_VELOCITYWITHCOVARIANCESTAMPED;

        MsgPack::str_t key1 = "header";
        std_msgs::msg::Header header;

        MsgPack::str_t key2 = "body_frame_id";
        MsgPack::str_t body_frame_id;

        MsgPack::str_t key3 = "reference_frame_id";
        MsgPack::str_t reference_frame_id;

        MsgPack::str_t key4 = "velocity";
        TwistWithCovariance velocity;

        VelocityWithCovarianceStamped() = default;

        VelocityWithCovarianceStamped(std_msgs::msg::Header header, MsgPack::str_t body_frame_id, MsgPack::str_t reference_frame_id, TwistWithCovariance velocity): header(header), body_frame_id(body_frame_id), reference_frame_id(reference_frame_id), velocity(velocity) {}

        MSGPACK_DEFINE_MAP(key1, header, key2, body_frame_id, key3, reference_frame_id, key4, velocity);

        bool operator==(const VelocityWithCovarianceStamped& other) const { return this->header == other.header && this->body_frame_id == other.body_frame_id && this->reference_frame_id == other.reference_frame_id && this->velocity == other.velocity; }
    };

} // namespace msg

} // namespace geometry_msgs
#endif //ROUTERBRIDGE_ROS_GEOMETRY_MSGS_VELOCITYWITHCOVARIANCESTAMPED_H
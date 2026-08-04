/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_GEOMETRY_MSGS_TRANSFORMSTAMPED_H
#define ROUTERBRIDGE_ROS_GEOMETRY_MSGS_TRANSFORMSTAMPED_H
#include <MsgPack.h>

#include "Transform.h"
#include "../std_msgs/Header.h"

#define ROUTERBRIDGE_ROS_GEOMETRY_MSGS_TRANSFORMSTAMPED "geometry_msgs/msg/TransformStamped"

namespace geometry_msgs {

namespace msg {

    struct TransformStamped {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_GEOMETRY_MSGS_TRANSFORMSTAMPED;

        MsgPack::str_t key1 = "header";
        std_msgs::msg::Header header;

        MsgPack::str_t key2 = "child_frame_id";
        MsgPack::str_t child_frame_id;

        MsgPack::str_t key3 = "transform";
        Transform transform;

        TransformStamped() = default;

        TransformStamped(std_msgs::msg::Header header, MsgPack::str_t child_frame_id, Transform transform): header(header), child_frame_id(child_frame_id), transform(transform) {}

        MSGPACK_DEFINE_MAP(key1, header, key2, child_frame_id, key3, transform);

        bool operator==(const TransformStamped& other) const { return this->header == other.header && this->child_frame_id == other.child_frame_id && this->transform == other.transform; }
    };

} // namespace msg

} // namespace geometry_msgs
#endif //ROUTERBRIDGE_ROS_GEOMETRY_MSGS_TRANSFORMSTAMPED_H
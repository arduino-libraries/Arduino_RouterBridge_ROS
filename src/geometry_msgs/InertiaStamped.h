/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_GEOMETRY_MSGS_INERTIASTAMPED_H
#define ROUTERBRIDGE_ROS_GEOMETRY_MSGS_INERTIASTAMPED_H
#include <MsgPack.h>

#include "Inertia.h"
#include "../std_msgs/Header.h"

#define ROUTERBRIDGE_ROS_GEOMETRY_MSGS_INERTIASTAMPED "geometry_msgs/msg/InertiaStamped"

namespace geometry_msgs {

namespace msg {

    struct InertiaStamped {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_GEOMETRY_MSGS_INERTIASTAMPED;

        MsgPack::str_t key1 = "header";
        std_msgs::msg::Header header;

        MsgPack::str_t key2 = "inertia";
        Inertia inertia;

        InertiaStamped() = default;

        InertiaStamped(std_msgs::msg::Header header, Inertia inertia): header(header), inertia(inertia) {}

        MSGPACK_DEFINE_MAP(key1, header, key2, inertia);

        bool operator==(const InertiaStamped& other) const { return this->header == other.header && this->inertia == other.inertia; }
    };

} // namespace msg

} // namespace geometry_msgs
#endif //ROUTERBRIDGE_ROS_GEOMETRY_MSGS_INERTIASTAMPED_H
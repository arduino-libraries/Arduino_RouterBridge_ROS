/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_STD_MSGS_HEADER_H
#define ROUTERBRIDGE_ROS_STD_MSGS_HEADER_H
#include <MsgPack.h>

#include "../builtin_interfaces/Time.h"

#define ROUTERBRIDGE_ROS_STD_MSGS_HEADER "std_msgs/msg/Header"

namespace std_msgs {

namespace msg {

    struct Header {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_STD_MSGS_HEADER;

        MsgPack::str_t key1 = "stamp";
        builtin_interfaces::msg::Time stamp;

        MsgPack::str_t key2 = "frame_id";
        MsgPack::str_t frame_id;

        Header() = default;

        Header(builtin_interfaces::msg::Time stamp, MsgPack::str_t frame_id): stamp(stamp), frame_id(frame_id) {}

        MSGPACK_DEFINE_MAP(key1, stamp, key2, frame_id);

        bool operator==(const Header& other) const { return this->stamp == other.stamp && this->frame_id == other.frame_id; }
    };

} // namespace msg

} // namespace std_msgs
#endif //ROUTERBRIDGE_ROS_STD_MSGS_HEADER_H
/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_STD_MSGS_STRING_H
#define ROUTERBRIDGE_ROS_STD_MSGS_STRING_H
#include <MsgPack.h>

#define ROUTERBRIDGE_ROS_STD_MSGS_STRING "std_msgs/msg/String"

namespace std_msgs {

namespace msg {

    struct String {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_STD_MSGS_STRING;

        MsgPack::str_t key = "data";
        MsgPack::str_t data;

        String() = default;

        String(MsgPack::str_t data): data(data) {}

        String& operator=(const MsgPack::str_t& str) {
            this->data = str;
            return *this;
        }

        MSGPACK_DEFINE_MAP(key, data);

        bool operator==(const String& other) const { return this->data == other.data; }
    };

} // namespace msg

} // namespace std_msgs
#endif //ROUTERBRIDGE_ROS_STD_MSGS_STRING_H
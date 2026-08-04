/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_STD_MSGS_UINT32_H
#define ROUTERBRIDGE_ROS_STD_MSGS_UINT32_H
#include <MsgPack.h>

#define ROUTERBRIDGE_ROS_STD_MSGS_UINT32 "std_msgs/msg/UInt32"

namespace std_msgs {

namespace msg {

    struct UInt32 {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_STD_MSGS_UINT32;

        MsgPack::str_t key = "data";
        uint32_t data;

        UInt32() = default;

        UInt32(uint32_t data): data(data) {}

        UInt32& operator=(uint32_t v) {
            this->data = v;
            return *this;
        }

        MSGPACK_DEFINE_MAP(key, data);

        bool operator==(const UInt32& other) const { return this->data == other.data; }
    };

} // namespace msg

} // namespace std_msgs
#endif //ROUTERBRIDGE_ROS_STD_MSGS_UINT32_H
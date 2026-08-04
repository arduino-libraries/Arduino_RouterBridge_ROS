/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_STD_MSGS_INT64_H
#define ROUTERBRIDGE_ROS_STD_MSGS_INT64_H
#include <MsgPack.h>

#define ROUTERBRIDGE_ROS_STD_MSGS_INT64 "std_msgs/msg/Int64"

namespace std_msgs {

namespace msg {

    struct Int64 {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_STD_MSGS_INT64;

        MsgPack::str_t key = "data";
        int64_t data;

        Int64() = default;

        Int64(int64_t data): data(data) {}

        Int64& operator=(int64_t v) {
            this->data = v;
            return *this;
        }

        MSGPACK_DEFINE_MAP(key, data);

        bool operator==(const Int64& other) const { return this->data == other.data; }
    };

} // namespace msg

} // namespace std_msgs
#endif //ROUTERBRIDGE_ROS_STD_MSGS_INT64_H
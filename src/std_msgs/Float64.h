/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_STD_MSGS_FLOAT64_H
#define ROUTERBRIDGE_ROS_STD_MSGS_FLOAT64_H
#include <MsgPack.h>

#define ROUTERBRIDGE_ROS_STD_MSGS_FLOAT64 "std_msgs/msg/Float64"

namespace std_msgs {

namespace msg {

    struct Float64 {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_STD_MSGS_FLOAT64;

        MsgPack::str_t key = "data";
        double data;

        Float64() = default;

        Float64(double data): data(data) {}

        Float64& operator=(double v) { this->data = v; return *this; }

        MSGPACK_DEFINE_MAP(key, data);

        bool operator==(const Float64& other) const { return this->data == other.data; }
    };

} // namespace msg

} // namespace std_msgs
#endif //ROUTERBRIDGE_ROS_STD_MSGS_FLOAT64_H
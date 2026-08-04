/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_STD_MSGS_FLOAT32_H
#define ROUTERBRIDGE_ROS_STD_MSGS_FLOAT32_H
#include <MsgPack.h>

#define ROUTERBRIDGE_ROS_STD_MSGS_FLOAT32 "std_msgs/msg/Float32"

namespace std_msgs {

namespace msg {

    struct Float32 {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_STD_MSGS_FLOAT32;

        MsgPack::str_t key = "data";
        float data;

        Float32() = default;

        Float32(float data): data(data) {}

        Float32& operator=(float v) { this->data = v; return *this; }

        MSGPACK_DEFINE_MAP(key, data);

        bool operator==(const Float32& other) const { return this->data == other.data; }
    };

} // namespace msg

} // namespace std_msgs
#endif //ROUTERBRIDGE_ROS_STD_MSGS_FLOAT32_H
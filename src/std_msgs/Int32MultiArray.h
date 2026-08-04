/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_STD_MSGS_INT32MULTIARRAY_H
#define ROUTERBRIDGE_ROS_STD_MSGS_INT32MULTIARRAY_H
#include <MsgPack.h>

#include "MultiArrayLayout.h"

#define ROUTERBRIDGE_ROS_STD_MSGS_INT32MULTIARRAY "std_msgs/msg/Int32MultiArray"

namespace std_msgs {

namespace msg {

    struct Int32MultiArray {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_STD_MSGS_INT32MULTIARRAY;

        MsgPack::str_t key1 = "layout";
        MultiArrayLayout layout;

        MsgPack::str_t key2 = "data";
        std::vector<int32_t> data;

        Int32MultiArray() = default;

        Int32MultiArray(MultiArrayLayout layout, std::vector<int32_t> data): layout(layout), data(data) {}

        MSGPACK_DEFINE_MAP(key1, layout, key2, data);

        bool operator==(const Int32MultiArray& other) const { return this->layout == other.layout && this->data == other.data; }
    };

} // namespace msg

} // namespace std_msgs
#endif //ROUTERBRIDGE_ROS_STD_MSGS_INT32MULTIARRAY_H
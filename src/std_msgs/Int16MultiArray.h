/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_STD_MSGS_INT16MULTIARRAY_H
#define ROUTERBRIDGE_ROS_STD_MSGS_INT16MULTIARRAY_H
#include <MsgPack.h>

#include "MultiArrayLayout.h"

#define ROUTERBRIDGE_ROS_STD_MSGS_INT16MULTIARRAY "std_msgs/msg/Int16MultiArray"

namespace std_msgs {

namespace msg {

    struct Int16MultiArray {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_STD_MSGS_INT16MULTIARRAY;

        MsgPack::str_t key1 = "layout";
        MultiArrayLayout layout;

        MsgPack::str_t key2 = "data";
        std::vector<int16_t> data;

        Int16MultiArray() = default;

        Int16MultiArray(MultiArrayLayout layout, std::vector<int16_t> data): layout(layout), data(data) {}

        MSGPACK_DEFINE_MAP(key1, layout, key2, data);

        bool operator==(const Int16MultiArray& other) const { return this->layout == other.layout && this->data == other.data; }
    };

} // namespace msg

} // namespace std_msgs
#endif //ROUTERBRIDGE_ROS_STD_MSGS_INT16MULTIARRAY_H
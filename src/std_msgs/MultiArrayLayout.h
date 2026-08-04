/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_STD_MSGS_MULTIARRAYLAYOUT_H
#define ROUTERBRIDGE_ROS_STD_MSGS_MULTIARRAYLAYOUT_H
#include <MsgPack.h>

#include "MultiArrayDimension.h"

#define ROUTERBRIDGE_ROS_STD_MSGS_MULTIARRAYLAYOUT "std_msgs/msg/MultiArrayLayout"

namespace std_msgs {

namespace msg {

    struct MultiArrayLayout {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_STD_MSGS_MULTIARRAYLAYOUT;

        MsgPack::str_t key1 = "dim";
        std::vector<MultiArrayDimension> dim;

        MsgPack::str_t key2 = "data_offset";
        uint32_t data_offset;

        MultiArrayLayout() = default;

        MultiArrayLayout(std::vector<MultiArrayDimension> dim, uint32_t data_offset): dim(dim), data_offset(data_offset) {}

        MSGPACK_DEFINE_MAP(key1, dim, key2, data_offset);

        bool operator==(const MultiArrayLayout& other) const { return this->dim == other.dim && this->data_offset == other.data_offset; }
    };

} // namespace msg

} // namespace std_msgs
#endif //ROUTERBRIDGE_ROS_STD_MSGS_MULTIARRAYLAYOUT_H
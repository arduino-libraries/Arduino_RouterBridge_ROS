/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_STD_MSGS_MULTIARRAYDIMENSION_H
#define ROUTERBRIDGE_ROS_STD_MSGS_MULTIARRAYDIMENSION_H
#include <MsgPack.h>

#define ROUTERBRIDGE_ROS_STD_MSGS_MULTIARRAYDIMENSION "std_msgs/msg/MultiArrayDimension"

namespace std_msgs {

namespace msg {

    struct MultiArrayDimension {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_STD_MSGS_MULTIARRAYDIMENSION;

        MsgPack::str_t key1 = "label";
        MsgPack::str_t label;

        MsgPack::str_t key2 = "size";
        uint32_t size;

        MsgPack::str_t key3 = "stride";
        uint32_t stride;

        MultiArrayDimension() = default;

        MultiArrayDimension(MsgPack::str_t label, uint32_t size, uint32_t stride): label(label), size(size), stride(stride) {}

        MSGPACK_DEFINE_MAP(key1, label, key2, size, key3, stride);

        bool operator==(const MultiArrayDimension& other) const { return this->label == other.label && this->size == other.size && this->stride == other.stride; }
    };

} // namespace msg

} // namespace std_msgs
#endif //ROUTERBRIDGE_ROS_STD_MSGS_MULTIARRAYDIMENSION_H
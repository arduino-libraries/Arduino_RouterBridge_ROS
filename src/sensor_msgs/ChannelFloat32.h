/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_SENSOR_MSGS_CHANNELFLOAT32_H
#define ROUTERBRIDGE_ROS_SENSOR_MSGS_CHANNELFLOAT32_H
#include <MsgPack.h>

#define ROUTERBRIDGE_ROS_SENSOR_MSGS_CHANNELFLOAT32 "sensor_msgs/msg/ChannelFloat32"

namespace sensor_msgs {

namespace msg {

    struct ChannelFloat32 {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_SENSOR_MSGS_CHANNELFLOAT32;

        MsgPack::str_t key1 = "name";
        MsgPack::str_t name;

        MsgPack::str_t key2 = "values";
        std::vector<float> values;

        ChannelFloat32() = default;

        ChannelFloat32(MsgPack::str_t name, std::vector<float> values): name(name), values(values) {}

        MSGPACK_DEFINE_MAP(key1, name, key2, values);

        bool operator==(const ChannelFloat32& other) const { return this->name == other.name && this->values == other.values; }
    };

} // namespace msg

} // namespace sensor_msgs
#endif //ROUTERBRIDGE_ROS_SENSOR_MSGS_CHANNELFLOAT32_H
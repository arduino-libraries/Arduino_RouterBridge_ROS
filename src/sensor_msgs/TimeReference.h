/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_SENSOR_MSGS_TIMEREFERENCE_H
#define ROUTERBRIDGE_ROS_SENSOR_MSGS_TIMEREFERENCE_H
#include <MsgPack.h>

#include "../builtin_interfaces/Time.h"
#include "../std_msgs/Header.h"

#define ROUTERBRIDGE_ROS_SENSOR_MSGS_TIMEREFERENCE "sensor_msgs/msg/TimeReference"

namespace sensor_msgs {

namespace msg {

    struct TimeReference {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_SENSOR_MSGS_TIMEREFERENCE;

        MsgPack::str_t key1 = "header";
        std_msgs::msg::Header header;

        MsgPack::str_t key2 = "time_ref";
        builtin_interfaces::msg::Time time_ref;

        MsgPack::str_t key3 = "source";
        MsgPack::str_t source;

        TimeReference() = default;

        TimeReference(std_msgs::msg::Header header, builtin_interfaces::msg::Time time_ref, MsgPack::str_t source): header(header), time_ref(time_ref), source(source) {}

        MSGPACK_DEFINE_MAP(key1, header, key2, time_ref, key3, source);

        bool operator==(const TimeReference& other) const { return this->header == other.header && this->time_ref == other.time_ref && this->source == other.source; }
    };

} // namespace msg

} // namespace sensor_msgs
#endif //ROUTERBRIDGE_ROS_SENSOR_MSGS_TIMEREFERENCE_H
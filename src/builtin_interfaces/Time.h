/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_BUILTIN_INTERFACES_TIME_H
#define ROUTERBRIDGE_ROS_BUILTIN_INTERFACES_TIME_H
#include <MsgPack.h>

#define ROUTERBRIDGE_ROS_BUILTIN_INTERFACES_TIME "builtin_interfaces/msg/Time"

namespace builtin_interfaces {

namespace msg {

    struct Time {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_BUILTIN_INTERFACES_TIME;

        MsgPack::str_t key1 = "sec";
        int32_t sec;

        MsgPack::str_t key2 = "nanosec";
        uint32_t nanosec;

        Time() = default;

        Time(int32_t sec, uint32_t nanosec): sec(sec), nanosec(nanosec) {}

        MSGPACK_DEFINE_MAP(key1, sec, key2, nanosec);

        bool operator==(const Time& other) const { return this->sec == other.sec && this->nanosec == other.nanosec; }
    };

} // namespace msg

} // namespace builtin_interfaces
#endif //ROUTERBRIDGE_ROS_BUILTIN_INTERFACES_TIME_H
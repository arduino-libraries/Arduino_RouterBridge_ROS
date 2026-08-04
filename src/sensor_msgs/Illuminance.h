/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_SENSOR_MSGS_ILLUMINANCE_H
#define ROUTERBRIDGE_ROS_SENSOR_MSGS_ILLUMINANCE_H
#include <MsgPack.h>

#include "../std_msgs/Header.h"

#define ROUTERBRIDGE_ROS_SENSOR_MSGS_ILLUMINANCE "sensor_msgs/msg/Illuminance"

namespace sensor_msgs {

namespace msg {

    struct Illuminance {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_SENSOR_MSGS_ILLUMINANCE;

        MsgPack::str_t key1 = "header";
        std_msgs::msg::Header header;

        MsgPack::str_t key2 = "illuminance";
        double illuminance;

        MsgPack::str_t key3 = "variance";
        double variance;

        Illuminance() = default;

        Illuminance(std_msgs::msg::Header header, double illuminance, double variance): header(header), illuminance(illuminance), variance(variance) {}

        MSGPACK_DEFINE_MAP(key1, header, key2, illuminance, key3, variance);

        bool operator==(const Illuminance& other) const { return this->header == other.header && this->illuminance == other.illuminance && this->variance == other.variance; }
    };

} // namespace msg

} // namespace sensor_msgs
#endif //ROUTERBRIDGE_ROS_SENSOR_MSGS_ILLUMINANCE_H
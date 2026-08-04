/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_SENSOR_MSGS_TEMPERATURE_H
#define ROUTERBRIDGE_ROS_SENSOR_MSGS_TEMPERATURE_H
#include <MsgPack.h>

#include "../std_msgs/Header.h"

#define ROUTERBRIDGE_ROS_SENSOR_MSGS_TEMPERATURE "sensor_msgs/msg/Temperature"

namespace sensor_msgs {

namespace msg {

    struct Temperature {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_SENSOR_MSGS_TEMPERATURE;

        MsgPack::str_t key1 = "header";
        std_msgs::msg::Header header;

        MsgPack::str_t key2 = "temperature";
        double temperature;

        MsgPack::str_t key3 = "variance";
        double variance;

        Temperature() = default;

        Temperature(std_msgs::msg::Header header, double temperature, double variance): header(header), temperature(temperature), variance(variance) {}

        MSGPACK_DEFINE_MAP(key1, header, key2, temperature, key3, variance);

        bool operator==(const Temperature& other) const { return this->header == other.header && this->temperature == other.temperature && this->variance == other.variance; }
    };

} // namespace msg

} // namespace sensor_msgs
#endif //ROUTERBRIDGE_ROS_SENSOR_MSGS_TEMPERATURE_H
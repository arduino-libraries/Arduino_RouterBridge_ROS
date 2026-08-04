/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_SENSOR_MSGS_RELATIVEHUMIDITY_H
#define ROUTERBRIDGE_ROS_SENSOR_MSGS_RELATIVEHUMIDITY_H
#include <MsgPack.h>

#include "../std_msgs/Header.h"

#define ROUTERBRIDGE_ROS_SENSOR_MSGS_RELATIVEHUMIDITY "sensor_msgs/msg/RelativeHumidity"

namespace sensor_msgs {

namespace msg {

    struct RelativeHumidity {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_SENSOR_MSGS_RELATIVEHUMIDITY;

        MsgPack::str_t key1 = "header";
        std_msgs::msg::Header header;

        MsgPack::str_t key2 = "relative_humidity";
        double relative_humidity;

        MsgPack::str_t key3 = "variance";
        double variance;

        RelativeHumidity() = default;

        RelativeHumidity(std_msgs::msg::Header header, double relative_humidity, double variance): header(header), relative_humidity(relative_humidity), variance(variance) {}

        MSGPACK_DEFINE_MAP(key1, header, key2, relative_humidity, key3, variance);

        bool operator==(const RelativeHumidity& other) const { return this->header == other.header && this->relative_humidity == other.relative_humidity && this->variance == other.variance; }
    };

} // namespace msg

} // namespace sensor_msgs
#endif //ROUTERBRIDGE_ROS_SENSOR_MSGS_RELATIVEHUMIDITY_H
/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_SENSOR_MSGS_MAGNETICFIELD_H
#define ROUTERBRIDGE_ROS_SENSOR_MSGS_MAGNETICFIELD_H
#include <MsgPack.h>

#include "../geometry_msgs/Vector3.h"
#include "../std_msgs/Header.h"

#define ROUTERBRIDGE_ROS_SENSOR_MSGS_MAGNETICFIELD "sensor_msgs/msg/MagneticField"

namespace sensor_msgs {

namespace msg {

    struct MagneticField {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_SENSOR_MSGS_MAGNETICFIELD;

        MsgPack::str_t key1 = "header";
        std_msgs::msg::Header header;

        MsgPack::str_t key2 = "magnetic_field";
        geometry_msgs::msg::Vector3 magnetic_field;

        MsgPack::str_t key3 = "magnetic_field_covariance";
        std::array<double, 9> magnetic_field_covariance{};

        MagneticField() = default;

        MagneticField(std_msgs::msg::Header header, geometry_msgs::msg::Vector3 magnetic_field, std::array<double, 9> magnetic_field_covariance): header(header), magnetic_field(magnetic_field), magnetic_field_covariance(magnetic_field_covariance) {}

        MSGPACK_DEFINE_MAP(key1, header, key2, magnetic_field, key3, magnetic_field_covariance);

        bool operator==(const MagneticField& other) const { return this->header == other.header && this->magnetic_field == other.magnetic_field && this->magnetic_field_covariance == other.magnetic_field_covariance; }
    };

} // namespace msg

} // namespace sensor_msgs
#endif //ROUTERBRIDGE_ROS_SENSOR_MSGS_MAGNETICFIELD_H
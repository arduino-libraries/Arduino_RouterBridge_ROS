/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_SENSOR_MSGS_NAVSATFIX_H
#define ROUTERBRIDGE_ROS_SENSOR_MSGS_NAVSATFIX_H
#include <MsgPack.h>

#include "NavSatStatus.h"
#include "../std_msgs/Header.h"

#define ROUTERBRIDGE_ROS_SENSOR_MSGS_NAVSATFIX "sensor_msgs/msg/NavSatFix"

namespace sensor_msgs {

namespace msg {

    struct NavSatFix {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_SENSOR_MSGS_NAVSATFIX;

        MsgPack::str_t key1 = "header";
        std_msgs::msg::Header header;

        MsgPack::str_t key2 = "status";
        NavSatStatus status;

        MsgPack::str_t key3 = "latitude";
        double latitude;

        MsgPack::str_t key4 = "longitude";
        double longitude;

        MsgPack::str_t key5 = "altitude";
        double altitude;

        MsgPack::str_t key6 = "position_covariance";
        std::array<double, 9> position_covariance{};

        MsgPack::str_t key7 = "COVARIANCE_TYPE_UNKNOWN";
        uint8_t COVARIANCE_TYPE_UNKNOWN;

        MsgPack::str_t key8 = "COVARIANCE_TYPE_APPROXIMATED";
        uint8_t COVARIANCE_TYPE_APPROXIMATED;

        MsgPack::str_t key9 = "COVARIANCE_TYPE_DIAGONAL_KNOWN";
        uint8_t COVARIANCE_TYPE_DIAGONAL_KNOWN;

        MsgPack::str_t key10 = "COVARIANCE_TYPE_KNOWN";
        uint8_t COVARIANCE_TYPE_KNOWN;

        MsgPack::str_t key11 = "position_covariance_type";
        uint8_t position_covariance_type;

        NavSatFix() = default;

        NavSatFix(std_msgs::msg::Header header, NavSatStatus status, double latitude, double longitude, double altitude, std::array<double, 9> position_covariance, uint8_t covariance_type_unknown, uint8_t covariance_type_approximated, uint8_t covariance_type_diagonal_known, uint8_t covariance_type_known, uint8_t position_covariance_type): header(header), status(status), latitude(latitude), longitude(longitude), altitude(altitude), position_covariance(position_covariance), COVARIANCE_TYPE_UNKNOWN(covariance_type_unknown), COVARIANCE_TYPE_APPROXIMATED(covariance_type_approximated), COVARIANCE_TYPE_DIAGONAL_KNOWN(covariance_type_diagonal_known), COVARIANCE_TYPE_KNOWN(covariance_type_known), position_covariance_type(position_covariance_type) {}

        MSGPACK_DEFINE_MAP(key1, header, key2, status, key3, latitude, key4, longitude, key5, altitude, key6, position_covariance, key7, COVARIANCE_TYPE_UNKNOWN, key8, COVARIANCE_TYPE_APPROXIMATED, key9, COVARIANCE_TYPE_DIAGONAL_KNOWN, key10, COVARIANCE_TYPE_KNOWN, key11, position_covariance_type);

        bool operator==(const NavSatFix& other) const { return this->header == other.header && this->status == other.status && this->latitude == other.latitude && this->longitude == other.longitude && this->altitude == other.altitude && this->position_covariance == other.position_covariance && this->COVARIANCE_TYPE_UNKNOWN == other.COVARIANCE_TYPE_UNKNOWN && this->COVARIANCE_TYPE_APPROXIMATED == other.COVARIANCE_TYPE_APPROXIMATED && this->COVARIANCE_TYPE_DIAGONAL_KNOWN == other.COVARIANCE_TYPE_DIAGONAL_KNOWN && this->COVARIANCE_TYPE_KNOWN == other.COVARIANCE_TYPE_KNOWN && this->position_covariance_type == other.position_covariance_type; }
    };

} // namespace msg

} // namespace sensor_msgs
#endif //ROUTERBRIDGE_ROS_SENSOR_MSGS_NAVSATFIX_H
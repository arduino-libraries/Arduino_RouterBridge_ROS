/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_SENSOR_MSGS_NAVSATSTATUS_H
#define ROUTERBRIDGE_ROS_SENSOR_MSGS_NAVSATSTATUS_H
#include <MsgPack.h>

#define ROUTERBRIDGE_ROS_SENSOR_MSGS_NAVSATSTATUS "sensor_msgs/msg/NavSatStatus"

namespace sensor_msgs {

namespace msg {

    struct NavSatStatus {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_SENSOR_MSGS_NAVSATSTATUS;

        MsgPack::str_t key1 = "STATUS_UNKNOWN";
        int8_t STATUS_UNKNOWN;

        MsgPack::str_t key2 = "STATUS_NO_FIX";
        int8_t STATUS_NO_FIX;

        MsgPack::str_t key3 = "STATUS_FIX";
        int8_t STATUS_FIX;

        MsgPack::str_t key4 = "STATUS_SBAS_FIX";
        int8_t STATUS_SBAS_FIX;

        MsgPack::str_t key5 = "STATUS_GBAS_FIX";
        int8_t STATUS_GBAS_FIX;

        MsgPack::str_t key6 = "status";
        int8_t status;

        MsgPack::str_t key7 = "SERVICE_UNKNOWN";
        uint16_t SERVICE_UNKNOWN;

        MsgPack::str_t key8 = "SERVICE_GPS";
        uint16_t SERVICE_GPS;

        MsgPack::str_t key9 = "SERVICE_GLONASS";
        uint16_t SERVICE_GLONASS;

        MsgPack::str_t key10 = "SERVICE_COMPASS";
        uint16_t SERVICE_COMPASS;

        MsgPack::str_t key11 = "SERVICE_GALILEO";
        uint16_t SERVICE_GALILEO;

        MsgPack::str_t key12 = "service";
        uint16_t service;

        NavSatStatus() = default;

        NavSatStatus(int8_t status_unknown, int8_t status_no_fix, int8_t status_fix, int8_t status_sbas_fix, int8_t status_gbas_fix, int8_t status, uint16_t service_unknown, uint16_t service_gps, uint16_t service_glonass, uint16_t service_compass, uint16_t service_galileo, uint16_t service): STATUS_UNKNOWN(status_unknown), STATUS_NO_FIX(status_no_fix), STATUS_FIX(status_fix), STATUS_SBAS_FIX(status_sbas_fix), STATUS_GBAS_FIX(status_gbas_fix), status(status), SERVICE_UNKNOWN(service_unknown), SERVICE_GPS(service_gps), SERVICE_GLONASS(service_glonass), SERVICE_COMPASS(service_compass), SERVICE_GALILEO(service_galileo), service(service) {}

        MSGPACK_DEFINE_MAP(key1, STATUS_UNKNOWN, key2, STATUS_NO_FIX, key3, STATUS_FIX, key4, STATUS_SBAS_FIX, key5, STATUS_GBAS_FIX, key6, status, key7, SERVICE_UNKNOWN, key8, SERVICE_GPS, key9, SERVICE_GLONASS, key10, SERVICE_COMPASS, key11, SERVICE_GALILEO, key12, service);

        bool operator==(const NavSatStatus& other) const { return this->STATUS_UNKNOWN == other.STATUS_UNKNOWN && this->STATUS_NO_FIX == other.STATUS_NO_FIX && this->STATUS_FIX == other.STATUS_FIX && this->STATUS_SBAS_FIX == other.STATUS_SBAS_FIX && this->STATUS_GBAS_FIX == other.STATUS_GBAS_FIX && this->status == other.status && this->SERVICE_UNKNOWN == other.SERVICE_UNKNOWN && this->SERVICE_GPS == other.SERVICE_GPS && this->SERVICE_GLONASS == other.SERVICE_GLONASS && this->SERVICE_COMPASS == other.SERVICE_COMPASS && this->SERVICE_GALILEO == other.SERVICE_GALILEO && this->service == other.service; }
    };

} // namespace msg

} // namespace sensor_msgs
#endif //ROUTERBRIDGE_ROS_SENSOR_MSGS_NAVSATSTATUS_H
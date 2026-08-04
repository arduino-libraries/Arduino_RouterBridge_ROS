/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_SENSOR_MSGS_MULTIECHOLASERSCAN_H
#define ROUTERBRIDGE_ROS_SENSOR_MSGS_MULTIECHOLASERSCAN_H
#include <MsgPack.h>

#include "LaserEcho.h"
#include "../std_msgs/Header.h"

#define ROUTERBRIDGE_ROS_SENSOR_MSGS_MULTIECHOLASERSCAN "sensor_msgs/msg/MultiEchoLaserScan"

namespace sensor_msgs {

namespace msg {

    struct MultiEchoLaserScan {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_SENSOR_MSGS_MULTIECHOLASERSCAN;

        MsgPack::str_t key1 = "header";
        std_msgs::msg::Header header;

        MsgPack::str_t key2 = "angle_min";
        float angle_min;

        MsgPack::str_t key3 = "angle_max";
        float angle_max;

        MsgPack::str_t key4 = "angle_increment";
        float angle_increment;

        MsgPack::str_t key5 = "time_increment";
        float time_increment;

        MsgPack::str_t key6 = "scan_time";
        float scan_time;

        MsgPack::str_t key7 = "range_min";
        float range_min;

        MsgPack::str_t key8 = "range_max";
        float range_max;

        MsgPack::str_t key9 = "ranges";
        std::vector<LaserEcho> ranges;

        MsgPack::str_t key10 = "intensities";
        std::vector<LaserEcho> intensities;

        MultiEchoLaserScan() = default;

        MultiEchoLaserScan(std_msgs::msg::Header header, float angle_min, float angle_max, float angle_increment, float time_increment, float scan_time, float range_min, float range_max, std::vector<LaserEcho> ranges, std::vector<LaserEcho> intensities): header(header), angle_min(angle_min), angle_max(angle_max), angle_increment(angle_increment), time_increment(time_increment), scan_time(scan_time), range_min(range_min), range_max(range_max), ranges(ranges), intensities(intensities) {}

        MSGPACK_DEFINE_MAP(key1, header, key2, angle_min, key3, angle_max, key4, angle_increment, key5, time_increment, key6, scan_time, key7, range_min, key8, range_max, key9, ranges, key10, intensities);

        bool operator==(const MultiEchoLaserScan& other) const { return this->header == other.header && this->angle_min == other.angle_min && this->angle_max == other.angle_max && this->angle_increment == other.angle_increment && this->time_increment == other.time_increment && this->scan_time == other.scan_time && this->range_min == other.range_min && this->range_max == other.range_max && this->ranges == other.ranges && this->intensities == other.intensities; }
    };

} // namespace msg

} // namespace sensor_msgs
#endif //ROUTERBRIDGE_ROS_SENSOR_MSGS_MULTIECHOLASERSCAN_H
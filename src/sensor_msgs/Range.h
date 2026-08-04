/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_SENSOR_MSGS_RANGE_H
#define ROUTERBRIDGE_ROS_SENSOR_MSGS_RANGE_H
#include <MsgPack.h>

#include "../std_msgs/Header.h"

#define ROUTERBRIDGE_ROS_SENSOR_MSGS_RANGE "sensor_msgs/msg/Range"

namespace sensor_msgs {

namespace msg {

    struct Range {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_SENSOR_MSGS_RANGE;

        MsgPack::str_t key1 = "header";
        std_msgs::msg::Header header;

        MsgPack::str_t key2 = "ULTRASOUND";
        uint8_t ULTRASOUND=0;

        MsgPack::str_t key3 = "INFRARED";
        uint8_t INFRARED=1;

        MsgPack::str_t key4 = "radiation_type";
        uint8_t radiation_type;

        MsgPack::str_t key5 = "field_of_view";
        float field_of_view;

        MsgPack::str_t key6 = "min_range";
        float min_range;

        MsgPack::str_t key7 = "max_range";
        float max_range;

        MsgPack::str_t key8 = "range";
        float range;

        MsgPack::str_t key9 = "variance";
        float variance;

        Range() = default;

        Range(std_msgs::msg::Header header, uint8_t ultrasound, uint8_t infrared, uint8_t radiation_type, float field_of_view, float min_range, float max_range, float range, float variance): header(header), ULTRASOUND(ultrasound), INFRARED(infrared), radiation_type(radiation_type), field_of_view(field_of_view), min_range(min_range), max_range(max_range), range(range), variance(variance) {}

        MSGPACK_DEFINE_MAP(key1, header, key2, ULTRASOUND, key3, INFRARED, key4, radiation_type, key5, field_of_view, key6, min_range, key7, max_range, key8, range, key9, variance);

        bool operator==(const Range& other) const { return this->header == other.header && this->ULTRASOUND == other.ULTRASOUND && this->INFRARED == other.INFRARED && this->radiation_type == other.radiation_type && this->field_of_view == other.field_of_view && this->min_range == other.min_range && this->max_range == other.max_range && this->range == other.range && this->variance == other.variance; }
    };

} // namespace msg

} // namespace sensor_msgs
#endif //ROUTERBRIDGE_ROS_SENSOR_MSGS_RANGE_H
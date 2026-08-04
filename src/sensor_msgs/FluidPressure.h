/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_SENSOR_MSGS_FLUIDPRESSURE_H
#define ROUTERBRIDGE_ROS_SENSOR_MSGS_FLUIDPRESSURE_H
#include <MsgPack.h>

#include "../std_msgs/Header.h"

#define ROUTERBRIDGE_ROS_SENSOR_MSGS_FLUIDPRESSURE "sensor_msgs/msg/FluidPressure"

namespace sensor_msgs {

namespace msg {

    struct FluidPressure {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_SENSOR_MSGS_FLUIDPRESSURE;

        MsgPack::str_t key1 = "header";
        std_msgs::msg::Header header;

        MsgPack::str_t key2 = "fluid_pressure";
        double fluid_pressure;

        MsgPack::str_t key3 = "variance";
        double variance;

        FluidPressure() = default;

        FluidPressure(std_msgs::msg::Header header, double fluid_pressure, double variance): header(header), fluid_pressure(fluid_pressure), variance(variance) {}

        MSGPACK_DEFINE_MAP(key1, header, key2, fluid_pressure, key3, variance);

        bool operator==(const FluidPressure& other) const { return this->header == other.header && this->fluid_pressure == other.fluid_pressure && this->variance == other.variance; }
    };

} // namespace msg

} // namespace sensor_msgs
#endif //ROUTERBRIDGE_ROS_SENSOR_MSGS_FLUIDPRESSURE_H
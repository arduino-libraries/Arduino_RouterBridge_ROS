/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_SENSOR_MSGS_LASERECHO_H
#define ROUTERBRIDGE_ROS_SENSOR_MSGS_LASERECHO_H
#include <MsgPack.h>

#define ROUTERBRIDGE_ROS_SENSOR_MSGS_LASERECHO "sensor_msgs/msg/LaserEcho"

namespace sensor_msgs {

namespace msg {

    struct LaserEcho {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_SENSOR_MSGS_LASERECHO;

        MsgPack::str_t key = "echoes";
        std::vector<float> echoes;

        LaserEcho() = default;

        LaserEcho(std::vector<float> echoes): echoes(echoes) {}

        MSGPACK_DEFINE_MAP(key, echoes);

        bool operator==(const LaserEcho& other) const { return this->echoes == other.echoes; }
    };

} // namespace msg

} // namespace sensor_msgs
#endif //ROUTERBRIDGE_ROS_SENSOR_MSGS_LASERECHO_H
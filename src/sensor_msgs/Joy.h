/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_SENSOR_MSGS_JOY_H
#define ROUTERBRIDGE_ROS_SENSOR_MSGS_JOY_H
#include <MsgPack.h>

#include "../std_msgs/Header.h"

#define ROUTERBRIDGE_ROS_SENSOR_MSGS_JOY "sensor_msgs/msg/Joy"

namespace sensor_msgs {

namespace msg {

    struct Joy {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_SENSOR_MSGS_JOY;

        MsgPack::str_t key1 = "header";
        std_msgs::msg::Header header;

        MsgPack::str_t key2 = "axes";
        std::vector<float> axes;

        MsgPack::str_t key3 = "buttons";
        std::vector<int32_t> buttons;

        Joy() = default;

        Joy(std_msgs::msg::Header header, std::vector<float> axes, std::vector<int32_t> buttons): header(header), axes(axes), buttons(buttons) {}

        MSGPACK_DEFINE_MAP(key1, header, key2, axes, key3, buttons);

        bool operator==(const Joy& other) const { return this->header == other.header && this->axes == other.axes && this->buttons == other.buttons; }
    };

} // namespace msg

} // namespace sensor_msgs
#endif //ROUTERBRIDGE_ROS_SENSOR_MSGS_JOY_H
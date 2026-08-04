/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_SENSOR_MSGS_REGIONOFINTEREST_H
#define ROUTERBRIDGE_ROS_SENSOR_MSGS_REGIONOFINTEREST_H
#include <MsgPack.h>

#define ROUTERBRIDGE_ROS_SENSOR_MSGS_REGIONOFINTEREST "sensor_msgs/msg/RegionOfInterest"

namespace sensor_msgs {

namespace msg {

    struct RegionOfInterest {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_SENSOR_MSGS_REGIONOFINTEREST;

        MsgPack::str_t key1 = "x_offset";
        uint32_t x_offset;

        MsgPack::str_t key2 = "y_offset";
        uint32_t y_offset;

        MsgPack::str_t key3 = "height";
        uint32_t height;

        MsgPack::str_t key4 = "width";
        uint32_t width;

        MsgPack::str_t key5 = "do_rectify";
        bool do_rectify;

        RegionOfInterest() = default;

        RegionOfInterest(uint32_t x_offset, uint32_t y_offset, uint32_t height, uint32_t width, bool do_rectify): x_offset(x_offset), y_offset(y_offset), height(height), width(width), do_rectify(do_rectify) {}

        MSGPACK_DEFINE_MAP(key1, x_offset, key2, y_offset, key3, height, key4, width, key5, do_rectify);

        bool operator==(const RegionOfInterest& other) const { return this->x_offset == other.x_offset && this->y_offset == other.y_offset && this->height == other.height && this->width == other.width && this->do_rectify == other.do_rectify; }
    };

} // namespace msg

} // namespace sensor_msgs
#endif //ROUTERBRIDGE_ROS_SENSOR_MSGS_REGIONOFINTEREST_H
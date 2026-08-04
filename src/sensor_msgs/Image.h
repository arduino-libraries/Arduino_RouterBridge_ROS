/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_SENSOR_MSGS_IMAGE_H
#define ROUTERBRIDGE_ROS_SENSOR_MSGS_IMAGE_H
#include <MsgPack.h>

#include "../std_msgs/Header.h"

#define ROUTERBRIDGE_ROS_SENSOR_MSGS_IMAGE "sensor_msgs/msg/Image"

namespace sensor_msgs {

namespace msg {

    struct Image {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_SENSOR_MSGS_IMAGE;

        MsgPack::str_t key1 = "header";
        std_msgs::msg::Header header;

        MsgPack::str_t key2 = "height";
        uint32_t height;

        MsgPack::str_t key3 = "width";
        uint32_t width;

        MsgPack::str_t key4 = "encoding";
        MsgPack::str_t encoding;

        MsgPack::str_t key5 = "is_bigendian";
        uint8_t is_bigendian;

        MsgPack::str_t key6 = "step";
        uint32_t step;

        MsgPack::str_t key7 = "data";
        std::vector<uint8_t> data;

        Image() = default;

        Image(std_msgs::msg::Header header, uint32_t height, uint32_t width, MsgPack::str_t encoding, uint8_t is_bigendian, uint32_t step, std::vector<uint8_t> data): header(header), height(height), width(width), encoding(encoding), is_bigendian(is_bigendian), step(step), data(data) {}

        MSGPACK_DEFINE_MAP(key1, header, key2, height, key3, width, key4, encoding, key5, is_bigendian, key6, step, key7, data);

        bool operator==(const Image& other) const { return this->header == other.header && this->height == other.height && this->width == other.width && this->encoding == other.encoding && this->is_bigendian == other.is_bigendian && this->step == other.step && this->data == other.data; }
    };

} // namespace msg

} // namespace sensor_msgs
#endif //ROUTERBRIDGE_ROS_SENSOR_MSGS_IMAGE_H
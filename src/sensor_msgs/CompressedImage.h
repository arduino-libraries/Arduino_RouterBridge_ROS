/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_SENSOR_MSGS_COMPRESSEDIMAGE_H
#define ROUTERBRIDGE_ROS_SENSOR_MSGS_COMPRESSEDIMAGE_H
#include <MsgPack.h>

#include "../std_msgs/Header.h"

#define ROUTERBRIDGE_ROS_SENSOR_MSGS_COMPRESSEDIMAGE "sensor_msgs/msg/CompressedImage"

namespace sensor_msgs {

namespace msg {

    struct CompressedImage {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_SENSOR_MSGS_COMPRESSEDIMAGE;

        MsgPack::str_t key1 = "header";
        std_msgs::msg::Header header;

        MsgPack::str_t key2 = "format";
        MsgPack::str_t format;

        MsgPack::str_t key3 = "data";
        std::vector<uint8_t> data;

        CompressedImage() = default;

        CompressedImage(std_msgs::msg::Header header, MsgPack::str_t format, std::vector<uint8_t> data): header(header), format(format), data(data) {}

        MSGPACK_DEFINE_MAP(key1, header, key2, format, key3, data);

        bool operator==(const CompressedImage& other) const { return this->header == other.header && this->format == other.format && this->data == other.data; }
    };

} // namespace msg

} // namespace sensor_msgs
#endif //ROUTERBRIDGE_ROS_SENSOR_MSGS_COMPRESSEDIMAGE_H
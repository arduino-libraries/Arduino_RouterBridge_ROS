/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_SENSOR_MSGS_POINTCLOUD2_H
#define ROUTERBRIDGE_ROS_SENSOR_MSGS_POINTCLOUD2_H
#include <MsgPack.h>

#include "PointField.h"
#include "../std_msgs/Header.h"

#define ROUTERBRIDGE_ROS_SENSOR_MSGS_POINTCLOUD2 "sensor_msgs/msg/PointCloud2"

namespace sensor_msgs {

namespace msg {

    struct PointCloud2 {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_SENSOR_MSGS_POINTCLOUD2;

        MsgPack::str_t key1 = "header";
        std_msgs::msg::Header header;

        MsgPack::str_t key2 = "height";
        uint32_t height;

        MsgPack::str_t key3 = "width";
        uint32_t width;

        MsgPack::str_t key4 = "fields";
        std::vector<PointField> fields;

        MsgPack::str_t key5 = "is_bigendian";
        bool is_bigendian;

        MsgPack::str_t key6 = "point_step";
        uint32_t point_step;

        MsgPack::str_t key7 = "row_step";
        uint32_t row_step;

        MsgPack::str_t key8 = "data";
        std::vector<uint8_t> data;

        MsgPack::str_t key9 = "is_dense";
        bool is_dense;

        PointCloud2() = default;

        PointCloud2(std_msgs::msg::Header header, uint32_t height, uint32_t width, std::vector<PointField> fields, bool is_bigendian, uint32_t point_step, uint32_t row_step, std::vector<uint8_t> data, bool is_dense): header(header), height(height), width(width), fields(fields), is_bigendian(is_bigendian), point_step(point_step), row_step(row_step), data(data), is_dense(is_dense) {}

        MSGPACK_DEFINE_MAP(key1, header, key2, height, key3, width, key4, fields, key5, is_bigendian, key6, point_step, key7, row_step, key8, data, key9, is_dense);

        bool operator==(const PointCloud2& other) const { return this->header == other.header && this->height == other.height && this->width == other.width && this->fields == other.fields && this->is_bigendian == other.is_bigendian && this->point_step == other.point_step && this->row_step == other.row_step && this->data == other.data && this->is_dense == other.is_dense; }
    };

} // namespace msg

} // namespace sensor_msgs
#endif //ROUTERBRIDGE_ROS_SENSOR_MSGS_POINTCLOUD2_H
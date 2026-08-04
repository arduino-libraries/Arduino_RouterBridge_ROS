/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_SENSOR_MSGS_CAMERAINFO_H
#define ROUTERBRIDGE_ROS_SENSOR_MSGS_CAMERAINFO_H
#include <MsgPack.h>

#include "RegionOfInterest.h"
#include "../std_msgs/Header.h"

#define ROUTERBRIDGE_ROS_SENSOR_MSGS_CAMERAINFO "sensor_msgs/msg/CameraInfo"

namespace sensor_msgs {

namespace msg {

    struct CameraInfo {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_SENSOR_MSGS_CAMERAINFO;

        MsgPack::str_t key1 = "header";
        std_msgs::msg::Header header;

        MsgPack::str_t key2 = "height";
        uint32_t height;

        MsgPack::str_t key3 = "width";
        uint32_t width;

        MsgPack::str_t key4 = "distortion_model";
        MsgPack::str_t distortion_model;

        MsgPack::str_t key5 = "d";
        std::vector<double> d;

        MsgPack::str_t key6 = "k";
        std::array<double, 9> k{};

        MsgPack::str_t key7 = "r";
        std::array<double, 9> r{};

        MsgPack::str_t key8 = "p";
        std::array<double, 12> p{};

        MsgPack::str_t key9 = "binning_x";
        uint32_t binning_x;

        MsgPack::str_t key10 = "binning_y";
        uint32_t binning_y;

        MsgPack::str_t key11 = "roi";
        RegionOfInterest roi;

        CameraInfo() = default;

        CameraInfo(std_msgs::msg::Header header, uint32_t height, uint32_t width, MsgPack::str_t distortion_model, std::vector<double> d, std::array<double, 9> k, std::array<double, 9> r, std::array<double, 12> p, uint32_t binning_x, uint32_t binning_y, RegionOfInterest roi): header(header), height(height), width(width), distortion_model(distortion_model), d(d), k(k), r(r), p(p), binning_x(binning_x), binning_y(binning_y), roi(roi) {}

        MSGPACK_DEFINE_MAP(key1, header, key2, height, key3, width, key4, distortion_model, key5, d, key6, k, key7, r, key8, p, key9, binning_x, key10, binning_y, key11, roi);

        bool operator==(const CameraInfo& other) const { return this->header == other.header && this->height == other.height && this->width == other.width && this->distortion_model == other.distortion_model && this->d == other.d && this->k == other.k && this->r == other.r && this->p == other.p && this->binning_x == other.binning_x && this->binning_y == other.binning_y && this->roi == other.roi; }
    };

} // namespace msg

} // namespace sensor_msgs
#endif //ROUTERBRIDGE_ROS_SENSOR_MSGS_CAMERAINFO_H
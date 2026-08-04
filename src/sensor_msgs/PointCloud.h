/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_SENSOR_MSGS_POINTCLOUD_H
#define ROUTERBRIDGE_ROS_SENSOR_MSGS_POINTCLOUD_H
#include <MsgPack.h>

#include "ChannelFloat32.h"
#include "../geometry_msgs/Point32.h"
#include "../std_msgs/Header.h"

#define ROUTERBRIDGE_ROS_SENSOR_MSGS_POINTCLOUD "sensor_msgs/msg/PointCloud"

namespace sensor_msgs {

namespace msg {

    struct PointCloud {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_SENSOR_MSGS_POINTCLOUD;

        MsgPack::str_t key1 = "header";
        std_msgs::msg::Header header;

        MsgPack::str_t key2 = "points";
        std::vector<geometry_msgs::msg::Point32> points;

        MsgPack::str_t key3 = "channels";
        std::vector<ChannelFloat32> channels;

        PointCloud() = default;

        PointCloud(std_msgs::msg::Header header, std::vector<geometry_msgs::msg::Point32> points, std::vector<ChannelFloat32> channels): header(header), points(points), channels(channels) {}

        MSGPACK_DEFINE_MAP(key1, header, key2, points, key3, channels);

        bool operator==(const PointCloud& other) const { return this->header == other.header && this->points == other.points && this->channels == other.channels; }
    };

} // namespace msg

} // namespace sensor_msgs
#endif //ROUTERBRIDGE_ROS_SENSOR_MSGS_POINTCLOUD_H
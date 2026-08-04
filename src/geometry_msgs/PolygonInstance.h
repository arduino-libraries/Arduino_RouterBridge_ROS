/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_GEOMETRY_MSGS_POLYGONINSTANCE_H
#define ROUTERBRIDGE_ROS_GEOMETRY_MSGS_POLYGONINSTANCE_H
#include <MsgPack.h>

#include "../geometry_msgs/Polygon.h"

#define ROUTERBRIDGE_ROS_GEOMETRY_MSGS_POLYGONINSTANCE "geometry_msgs/msg/PolygonInstance"

namespace geometry_msgs {

namespace msg {

    struct PolygonInstance {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_GEOMETRY_MSGS_POLYGONINSTANCE;

        MsgPack::str_t key1 = "polygon";
        geometry_msgs::msg::Polygon polygon;

        MsgPack::str_t key2 = "id";
        int64_t id;

        PolygonInstance() = default;

        PolygonInstance(geometry_msgs::msg::Polygon polygon, int64_t id): polygon(polygon), id(id) {}

        MSGPACK_DEFINE_MAP(key1, polygon, key2, id);

        bool operator==(const PolygonInstance& other) const { return this->polygon == other.polygon && this->id == other.id; }
    };

} // namespace msg

} // namespace geometry_msgs
#endif //ROUTERBRIDGE_ROS_GEOMETRY_MSGS_POLYGONINSTANCE_H
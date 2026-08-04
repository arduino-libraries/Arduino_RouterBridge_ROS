/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_GEOMETRY_MSGS_TRANSFORM_H
#define ROUTERBRIDGE_ROS_GEOMETRY_MSGS_TRANSFORM_H
#include <MsgPack.h>

#include "Quaternion.h"
#include "Vector3.h"

#define ROUTERBRIDGE_ROS_GEOMETRY_MSGS_TRANSFORM "geometry_msgs/msg/Transform"

namespace geometry_msgs {

namespace msg {

    struct Transform {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_GEOMETRY_MSGS_TRANSFORM;

        MsgPack::str_t key1 = "translation";
        Vector3 translation;

        MsgPack::str_t key2 = "rotation";
        Quaternion rotation;

        Transform() = default;

        Transform(Vector3 translation, Quaternion rotation): translation(translation), rotation(rotation) {}

        MSGPACK_DEFINE_MAP(key1, translation, key2, rotation);

        bool operator==(const Transform& other) const { return this->translation == other.translation && this->rotation == other.rotation; }
    };

} // namespace msg

} // namespace geometry_msgs
#endif //ROUTERBRIDGE_ROS_GEOMETRY_MSGS_TRANSFORM_H
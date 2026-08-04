/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_GEOMETRY_MSGS_INERTIA_H
#define ROUTERBRIDGE_ROS_GEOMETRY_MSGS_INERTIA_H
#include <MsgPack.h>

#include "../geometry_msgs/Vector3.h"

#define ROUTERBRIDGE_ROS_GEOMETRY_MSGS_INERTIA "geometry_msgs/msg/Inertia"

namespace geometry_msgs {

namespace msg {

    struct Inertia {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_GEOMETRY_MSGS_INERTIA;

        MsgPack::str_t key1 = "m";
        double m;

        MsgPack::str_t key2 = "com";
        geometry_msgs::msg::Vector3 com;

        MsgPack::str_t key3 = "ixx";
        double ixx;

        MsgPack::str_t key4 = "ixy";
        double ixy;

        MsgPack::str_t key5 = "ixz";
        double ixz;

        MsgPack::str_t key6 = "iyy";
        double iyy;

        MsgPack::str_t key7 = "iyz";
        double iyz;

        MsgPack::str_t key8 = "izz";
        double izz;

        Inertia() = default;

        Inertia(double m, geometry_msgs::msg::Vector3 com, double ixx, double ixy, double ixz, double iyy, double iyz, double izz): m(m), com(com), ixx(ixx), ixy(ixy), ixz(ixz), iyy(iyy), iyz(iyz), izz(izz) {}

        MSGPACK_DEFINE_MAP(key1, m, key2, com, key3, ixx, key4, ixy, key5, ixz, key6, iyy, key7, iyz, key8, izz);

        bool operator==(const Inertia& other) const { return this->m == other.m && this->com == other.com && this->ixx == other.ixx && this->ixy == other.ixy && this->ixz == other.ixz && this->iyy == other.iyy && this->iyz == other.iyz && this->izz == other.izz; }
    };

} // namespace msg

} // namespace geometry_msgs
#endif //ROUTERBRIDGE_ROS_GEOMETRY_MSGS_INERTIA_H
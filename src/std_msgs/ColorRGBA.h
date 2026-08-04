/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_STD_MSGS_COLORRGBA_H
#define ROUTERBRIDGE_ROS_STD_MSGS_COLORRGBA_H
#include <MsgPack.h>

#define ROUTERBRIDGE_ROS_STD_MSGS_COLORRGBA "std_msgs/msg/ColorRGBA"

namespace std_msgs {

namespace msg {

    struct ColorRGBA {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_STD_MSGS_COLORRGBA;

        MsgPack::str_t key1 = "r";
        float r;

        MsgPack::str_t key2 = "g";
        float g;

        MsgPack::str_t key3 = "b";
        float b;

        MsgPack::str_t key4 = "a";
        float a;

        ColorRGBA() = default;

        ColorRGBA(float r, float g, float b, float a): r(r), g(g), b(b), a(a) {}

        MSGPACK_DEFINE_MAP(key1, r, key2, g, key3, b, key4, a);

        bool operator==(const ColorRGBA& other) const { return this->r == other.r && this->g == other.g && this->b == other.b && this->a == other.a; }
    };

} // namespace msg

} // namespace std_msgs
#endif //ROUTERBRIDGE_ROS_STD_MSGS_COLORRGBA_H
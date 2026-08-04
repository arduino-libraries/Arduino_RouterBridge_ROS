/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_STD_MSGS_EMPTY_H
#define ROUTERBRIDGE_ROS_STD_MSGS_EMPTY_H
#include <MsgPack.h>

#define ROUTERBRIDGE_ROS_STD_MSGS_EMPTY "std_msgs/msg/Empty"

namespace std_msgs {

namespace msg {

    struct Empty {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_STD_MSGS_EMPTY;

        Empty() = default;

        MSGPACK_DEFINE_MAP();

        bool operator==(const Empty& other) const { (void)other; return true; }
    };

} // namespace msg

} // namespace std_msgs
#endif //ROUTERBRIDGE_ROS_STD_MSGS_EMPTY_H
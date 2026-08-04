/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_SENSOR_MSGS_JOYFEEDBACKARRAY_H
#define ROUTERBRIDGE_ROS_SENSOR_MSGS_JOYFEEDBACKARRAY_H
#include <MsgPack.h>

#include "JoyFeedback.h"

#define ROUTERBRIDGE_ROS_SENSOR_MSGS_JOYFEEDBACKARRAY "sensor_msgs/msg/JoyFeedbackArray"

namespace sensor_msgs {

namespace msg {

    struct JoyFeedbackArray {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_SENSOR_MSGS_JOYFEEDBACKARRAY;

        MsgPack::str_t key = "array";
        std::vector<JoyFeedback> array;

        JoyFeedbackArray() = default;

        JoyFeedbackArray(std::vector<JoyFeedback> array): array(array) {}

        MSGPACK_DEFINE_MAP(key, array);

        bool operator==(const JoyFeedbackArray& other) const { return this->array == other.array; }
    };

} // namespace msg

} // namespace sensor_msgs
#endif //ROUTERBRIDGE_ROS_SENSOR_MSGS_JOYFEEDBACKARRAY_H
/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_SENSOR_MSGS_JOYFEEDBACK_H
#define ROUTERBRIDGE_ROS_SENSOR_MSGS_JOYFEEDBACK_H
#include <MsgPack.h>

#define ROUTERBRIDGE_ROS_SENSOR_MSGS_JOYFEEDBACK "sensor_msgs/msg/JoyFeedback"

namespace sensor_msgs {

namespace msg {

    struct JoyFeedback {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_SENSOR_MSGS_JOYFEEDBACK;

        MsgPack::str_t key1 = "TYPE_LED";
        uint8_t TYPE_LED;

        MsgPack::str_t key2 = "TYPE_RUMBLE";
        uint8_t TYPE_RUMBLE;

        MsgPack::str_t key3 = "TYPE_BUZZER";
        uint8_t TYPE_BUZZER;

        MsgPack::str_t key4 = "type";
        uint8_t type;

        MsgPack::str_t key5 = "id";
        uint8_t id;

        MsgPack::str_t key6 = "intensity";
        float intensity;

        JoyFeedback() = default;

        JoyFeedback(uint8_t type_led, uint8_t type_rumble, uint8_t type_buzzer, uint8_t type, uint8_t id, float intensity): TYPE_LED(type_led), TYPE_RUMBLE(type_rumble), TYPE_BUZZER(type_buzzer), type(type), id(id), intensity(intensity) {}

        MSGPACK_DEFINE_MAP(key1, TYPE_LED, key2, TYPE_RUMBLE, key3, TYPE_BUZZER, key4, type, key5, id, key6, intensity);

        bool operator==(const JoyFeedback& other) const { return this->TYPE_LED == other.TYPE_LED && this->TYPE_RUMBLE == other.TYPE_RUMBLE && this->TYPE_BUZZER == other.TYPE_BUZZER && this->type == other.type && this->id == other.id && this->intensity == other.intensity; }
    };

} // namespace msg

} // namespace sensor_msgs
#endif //ROUTERBRIDGE_ROS_SENSOR_MSGS_JOYFEEDBACK_H
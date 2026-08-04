/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_SENSOR_MSGS_POINTFIELD_H
#define ROUTERBRIDGE_ROS_SENSOR_MSGS_POINTFIELD_H
#include <MsgPack.h>

#define ROUTERBRIDGE_ROS_SENSOR_MSGS_POINTFIELD "sensor_msgs/msg/PointField"

namespace sensor_msgs {

namespace msg {

    struct PointField {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_SENSOR_MSGS_POINTFIELD;

        MsgPack::str_t key1 = "INT8";
        uint8_t INT8;

        MsgPack::str_t key2 = "UINT8";
        uint8_t UINT8;

        MsgPack::str_t key3 = "INT16";
        uint8_t INT16;

        MsgPack::str_t key4 = "UINT16";
        uint8_t UINT16;

        MsgPack::str_t key5 = "INT32";
        uint8_t INT32;

        MsgPack::str_t key6 = "UINT32";
        uint8_t UINT32;

        MsgPack::str_t key7 = "FLOAT32";
        uint8_t FLOAT32;

        MsgPack::str_t key8 = "FLOAT64";
        uint8_t FLOAT64;

        MsgPack::str_t key9 = "name";
        MsgPack::str_t name;

        MsgPack::str_t key10 = "offset";
        uint32_t offset;

        MsgPack::str_t key11 = "datatype";
        uint8_t datatype;

        MsgPack::str_t key12 = "count";
        uint32_t count;

        PointField() = default;

        PointField(uint8_t int8, uint8_t uint8, uint8_t int16, uint8_t uint16, uint8_t int32, uint8_t uint32, uint8_t float32, uint8_t float64, MsgPack::str_t name, uint32_t offset, uint8_t datatype, uint32_t count): INT8(int8), UINT8(uint8), INT16(int16), UINT16(uint16), INT32(int32), UINT32(uint32), FLOAT32(float32), FLOAT64(float64), name(name), offset(offset), datatype(datatype), count(count) {}

        MSGPACK_DEFINE_MAP(key1, INT8, key2, UINT8, key3, INT16, key4, UINT16, key5, INT32, key6, UINT32, key7, FLOAT32, key8, FLOAT64, key9, name, key10, offset, key11, datatype, key12, count);

        bool operator==(const PointField& other) const { return this->INT8 == other.INT8 && this->UINT8 == other.UINT8 && this->INT16 == other.INT16 && this->UINT16 == other.UINT16 && this->INT32 == other.INT32 && this->UINT32 == other.UINT32 && this->FLOAT32 == other.FLOAT32 && this->FLOAT64 == other.FLOAT64 && this->name == other.name && this->offset == other.offset && this->datatype == other.datatype && this->count == other.count; }
    };

} // namespace msg

} // namespace sensor_msgs
#endif //ROUTERBRIDGE_ROS_SENSOR_MSGS_POINTFIELD_H
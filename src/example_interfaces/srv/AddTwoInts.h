/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_EXAMPLE_INTERFACES_ADDTWOINTS_H
#define ROUTERBRIDGE_ROS_EXAMPLE_INTERFACES_ADDTWOINTS_H


#define ROUTERBRIDGE_ROS_EXAMPLE_INTERFACES_ADDTWOINTS "example_interfaces/srv/AddTwoInts"

namespace example_interfaces
{
    namespace srv
    {

        struct AddTwoInts_Request
        {
            MsgPack::str_t key1 = "a";
            int64_t a;

            MsgPack::str_t key2 = "b";
            int64_t b;

            AddTwoInts_Request() = default;

            AddTwoInts_Request(int64_t a, int64_t b): a(a), b(b) {}

            MSGPACK_DEFINE_MAP(key1, a, key2, b);

            bool operator==(const AddTwoInts_Request& other) const { return this->a == other.a && this->b == other.b; }
        };

        struct AddTwoInts_Response
        {
            MsgPack::str_t key1 = "sum";
            int64_t sum;

            AddTwoInts_Response() = default;

            AddTwoInts_Response(int64_t sum): sum(sum) {}

            MSGPACK_DEFINE_MAP(key1, sum);

            bool operator==(const AddTwoInts_Response& other) const { return this->sum == other.sum; }
        };

        struct AddTwoInts
        {
            static constexpr const char* _iface = ROUTERBRIDGE_ROS_EXAMPLE_INTERFACES_ADDTWOINTS;

            using Request = AddTwoInts_Request;
            using Response = AddTwoInts_Response;
        };

    }
}

#endif //ROUTERBRIDGE_ROS_EXAMPLE_INTERFACES_ADDTWOINTS_H

/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_CLIENT_H
#define ROUTERBRIDGE_ROS_CLIENT_H

#endif //ROUTERBRIDGE_ROS_CLIENT_H

#include <Arduino_RouterBridge.h>
#include "common.h"

#define ROS2_REGISTER_SRV_CLI_CALL "ros2/client_reg"
#define ROS2_CALL_SRV "ros2/call_srv"

namespace ros2ino
{

    class ClientInterface {
    public:
        ClientInterface(): _id(0), is_registered(false){}
        virtual ~ClientInterface() = default;

        virtual void register_() = 0;

    protected:
        uint16_t _id;
        bool is_registered;
        const char* service_name_ = nullptr;
    };

    template <typename SrvType>
    class Client : public ClientInterface {
        using FutureAndRequestId = RpcCall<uint16_t&, typename SrvType::Request&>;
    public:
        Client(const char* service_name, bool use_client_timestamps=true)
        {
            this->service_name_ = service_name;
            this->use_client_timestamps = use_client_timestamps;
            this->Client::register_();
        }

        void register_() override
        {
            int assigned_id;
            MsgPack::str_t time_mode;
            use_client_timestamps ? time_mode = "" : time_mode = "o";
            is_registered = Bridge.call(ROS2_REGISTER_SRV_CLI_CALL, this->service_name_, SrvType::_iface, time_mode).result(assigned_id);

            if (is_registered && assigned_id >= 0)
            {
                this->_id = (uint16_t)assigned_id;
            }
        }

        FutureAndRequestId async_send_request(typename SrvType::Request* req)
        {
            return Bridge.call(ROS2_CALL_SRV, this->_id, *req);
        }

        bool isRegistered() const {return is_registered;}

    private:
        typename SrvType::Request req_;
        typename SrvType::Response resp_;
        bool use_client_timestamps;

    };

}
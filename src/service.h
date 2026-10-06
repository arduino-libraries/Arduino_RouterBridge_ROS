/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_SERVICE_H
#define ROUTERBRIDGE_ROS_SERVICE_H

#include <Arduino_RouterBridge.h>
#include "common.h"

#define ROS2_REGISTER_SRV_CALL "ros2/service_reg"

namespace ros2ino
{
    class ServiceInterface {
    public:
        ServiceInterface(): _id(0), is_registered(false), srv_req_cnt_(0) {}
        virtual ~ServiceInterface() = default;

        virtual void register_() = 0;
        virtual void runCallback(void* serialized_req, void* serialized_resp) = 0;

    protected:
        ServiceCallback callback_ = nullptr;
        void* callback_arg_ = nullptr;
        uint16_t _id;
        bool is_registered;
        uint32_t srv_req_cnt_;
        const char* service_name_ = nullptr;
    };

    template <typename SrvType>
    class Service : public ServiceInterface {
    public:
        explicit Service(const char* service_name, ServiceCallback callback, void* callback_arg, bool use_service_timestamps=true) {
            this->callback_ = callback;
            this->callback_arg_ = callback_arg;
            this->service_name_ = service_name;
            this->use_service_timestamps = use_service_timestamps;
            this->Service::register_();
        }

        void runCallback(void* serialized_req, void* serialized_resp) override {
            if (this->callback_ != nullptr) {
                this->callback_((typename SrvType::Request*)serialized_req, (typename SrvType::Response*)serialized_resp, this->callback_arg_);
            }
        }

        void register_() override {
            int assigned_id;
            MsgPack::str_t time_mode;
            use_service_timestamps ? time_mode = "" : time_mode = "o";
            is_registered = Bridge.call(ROS2_REGISTER_SRV_CALL, this->service_name_, SrvType::_iface, time_mode).result(assigned_id);

            if (is_registered && assigned_id >= 0) {
                this->_id = (uint16_t)assigned_id;

                this->bridge_method_name = MsgPack::str_t(this->_id) + MsgPack::str_t(this->service_name_);

                Bridge.provide(this->bridge_method_name,
                    [this](typename SrvType::Request req) -> typename SrvType::Response {
                        this->req_ = req;
                        this->resp_ = typename SrvType::Response();
                        ++this->srv_req_cnt_;
                        this->runCallback(&this->req_, &this->resp_);
                        return this->resp_;
                    }
                );
            }
        }

    bool isRegistered() const {return is_registered;}

    private:
        typename SrvType::Request req_;
        typename SrvType::Response resp_;
        MsgPack::str_t bridge_method_name;
        bool use_service_timestamps;

    };
}

#endif // ROUTERBRIDGE_ROS_SERVICE_H
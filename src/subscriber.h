/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_SUBSCRIBER_H
#define ROUTERBRIDGE_ROS_SUBSCRIBER_H

#include <Arduino_RouterBridge.h>
#include "common.h"

#define ROS2_SUBSCRIBE_TOPIC_CALL "ros2/sub"

namespace ros2ino
{
    class SubscriberInterface {
    public:
        SubscriberInterface(): _id(0), is_subscribed(false), sub_msg_cnt_(0) {}
        virtual ~SubscriberInterface() = default;

        virtual void subscribe() = 0;
        virtual void runCallback(void* serialized_msg) = 0;

    protected:
        CallBack callback_ = nullptr;
        void* callback_arg_ = nullptr;
        uint16_t _id;
        bool is_subscribed;
        uint32_t sub_msg_cnt_;
        const char* topic_name_ = nullptr;
    };

    template <typename MsgType>
    class Subscriber : public SubscriberInterface {
    public:
        explicit Subscriber(const char* topic_name, CallBack callback, void* callback_arg) {
            this->callback_ = callback;
            this->callback_arg_ = callback_arg;
            this->topic_name_ = topic_name;
            this->Subscriber::subscribe();
        }

        void runCallback(void* serialized_msg) override {
            if (this->callback_ != nullptr) {
                this->callback_((MsgType*)serialized_msg, this->callback_arg_);
            }
        }

        void subscribe() override {
            int assigned_id;
            is_subscribed = Bridge.call(ROS2_SUBSCRIBE_TOPIC_CALL, this->topic_name_, MsgType::_type).result(assigned_id);

            if (is_subscribed && assigned_id >= 0) {
                this->_id = (uint16_t)assigned_id;

                this->bridge_method_name = MsgPack::str_t(this->_id) + MsgPack::str_t(this->topic_name_);

                Bridge.provide(this->bridge_method_name,
                    [this](MsgType msg) -> void {
                        this->msg_ = msg;
                        this->sub_msg_cnt_++;
                        this->runCallback(&(this->msg_));
                    }
                );
            }
        }

    bool isSubscribed() const {return is_subscribed;}
        
    private:
        MsgType msg_;
        MsgPack::str_t bridge_method_name;
    };
}

#endif // ROUTERBRIDGE_ROS_SUBSCRIBER_H
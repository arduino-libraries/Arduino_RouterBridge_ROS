/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_PUBLISHER_H
#define ROUTERBRIDGE_ROS_PUBLISHER_H

#include <Arduino_RouterBridge.h>
#include "common.h"

#define ROS2_PUBLISH_CALL "ros2/pub"
#define ROS2_REGISTER_TOPIC_CALL "ros2/reg"

namespace ros2ino {

class PublisherInterface {

public:
    PublisherInterface(): _id(0), is_registered(false), pub_msg_cnt_(0) {}
    virtual ~PublisherInterface()= default;

    virtual void register_() = 0;
    virtual void publish() = 0;
    //virtual void destroy() = 0;


    void registerCallback(CallBack callback, void* callback_arg) {
        this->callback_ = callback;
        this->callback_arg_ = callback_arg;
    }

    void setPublishInterval(unsigned long interval) {
        publish_interval_ = interval;
    }

    bool isTimeToPublish() const {
        if (publish_interval_ == 0) return true;
        return (millis() - last_publish_time_) > publish_interval_;
    }

protected:
    CallBack callback_=nullptr;
    void* callback_arg_=nullptr;
    uint16_t _id;
    bool is_registered;
    uint32_t pub_msg_cnt_;
    const char* topic_name_=nullptr;
    unsigned long publish_interval_=0;
    unsigned long last_publish_time_=0;
};

template <typename MsgType>
class Publisher: public PublisherInterface{

public:
    Publisher(const char* topic_name, const bool use_publisher_timestamps = true) {
        this->use_publisher_timestamps = use_publisher_timestamps;
        topic_name_ = topic_name;
        Publisher<MsgType>::register_();
    }

    bool isRegistered() const {return is_registered;}

    void publish() override {
        if (!is_registered) return;
        if (callback_ == nullptr) return;

        callback_(&msg_, callback_arg_);
        this->publish(&msg_);
    }

    void publish(MsgType* msg) {
        if (!is_registered) return;
        if (msg == nullptr) return;

        bool ok;
        Bridge.call(ROS2_PUBLISH_CALL, this->_id, *msg).result(ok);
        if (ok) {
            this->last_publish_time_ = millis();
            ++this->pub_msg_cnt_;
        }
    }

private:
    void register_() override {
        int assigned_id;
        MsgPack::str_t time_mode;
        use_publisher_timestamps ? time_mode = "" : time_mode = "o";     // time_mode "o" to overwrite Time msg on arrival in ROS
        is_registered = Bridge.call(ROS2_REGISTER_TOPIC_CALL, this->topic_name_, MsgType::_type, time_mode).result(assigned_id);
        if (is_registered && assigned_id >= 0) this->_id = (uint16_t)assigned_id;
        // TODO error check could be useful here
    }

    // set use_publisher_timestamps to false to let ROS2 overwrite Time messages associated with this publisher
    bool use_publisher_timestamps;
    MsgType msg_;
};

}

#endif //ROUTERBRIDGE_ROS_PUBLISHER_H

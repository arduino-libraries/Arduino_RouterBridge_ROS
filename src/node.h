/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_NODE_H
#define ROUTERBRIDGE_ROS_NODE_H

#define ROS2_TIME_CALL "ros2/time"
#define RTC_UPDATE_T 10000

#include <zephyr/drivers/rtc.h>
#include <time.h>
#include "publisher.h"
#include "subscriber.h"
#include "builtin_interfaces/Time.h"

namespace ros2ino {

class Node {

    const char* name_;
    const char* node_namespace_;

public:
    explicit Node(const char* name, const char* node_namespace = "/"): name_(name), node_namespace_(node_namespace)
    {
        ros2ino::reset();
    }

    template <typename MsgType>
    Publisher<MsgType>* create_publisher(const char* topic_name, bool use_publisher_timestamps=true) {

        for (int i=0; i<ROUTERBRIDGE_ROS_PUB_MAX; ++i)
        {
            if (pub_list[i] == nullptr)
            {
                auto* pub_ptr = new Publisher<MsgType>(topic_name, use_publisher_timestamps);
                if (!pub_ptr->isRegistered()) return nullptr;
                pub_list[i] = pub_ptr;
                return (Publisher<MsgType>*)pub_list[i];
            }
        }

        return nullptr;
    }

    // TODO
    // deletePublisher(const char* topic_name) {}
    // deletePublisher(uint16_t id_) {}

    template <typename MsgType>
    Subscriber<MsgType>* create_subscription(const char* topic_name, CallBack callback, void* callback_arg) {

        for (int i=0; i<ROUTERBRIDGE_ROS_SUB_MAX; ++i)
        {
            if (sub_list[i] == nullptr)
            {
                auto* sub_ptr = new Subscriber<MsgType>(topic_name, callback, callback_arg);
                if (!sub_ptr->isSubscribed()) return nullptr;
                sub_list[i] = sub_ptr;
                return (Subscriber<MsgType>*)sub_list[i];
            }
        }

        return nullptr;
    }

    // TODO
    // deleteSubscription(const char* topic_name) {}
    // deleteSubscription(uint16_t id_) {}

    static builtin_interfaces::msg::Time now()
    {
        builtin_interfaces::msg::Time time{};
        const struct device *rtc_dev = DEVICE_DT_GET(DT_NODELABEL(rtc));

        // Fallback to system milliseconds if the RTC device is not available
        if (!device_is_ready(rtc_dev)) {
            uint32_t ms = millis();
            time.sec = ms / 1000;
            time.nanosec = (ms % 1000) * 1000000U;
            return time;
        }

        // Periodically update RTC with time from the ROS2 bridge
        static uint32_t last_rtc_update = 0;
        uint32_t current_ms = millis();

        if (current_ms - last_rtc_update > RTC_UPDATE_T) {
            last_rtc_update = current_ms;

            MsgPack::object::timespec time_spec;
            Bridge.call(ROS2_TIME_CALL).result(time_spec);

            struct tm* temp_tm = nullptr;
            struct rtc_time rtc_tm = {};

            // Convert Unix timestamp to broken-down time
            auto timestamp = (time_t)time_spec.tv_sec;
            temp_tm = gmtime(&timestamp);
            if (temp_tm == nullptr) {
                // Fallback on conversion failure
                uint32_t ms = millis();
                time.sec = ms / 1000;
                time.nanosec = (ms % 1000) * 1000000U;
                return time;
            }

            // Copy time components to RTC structure
            rtc_tm.tm_sec  = temp_tm->tm_sec;
            rtc_tm.tm_min  = temp_tm->tm_min;
            rtc_tm.tm_hour = temp_tm->tm_hour;
            rtc_tm.tm_mday = temp_tm->tm_mday;
            rtc_tm.tm_mon  = temp_tm->tm_mon;
            rtc_tm.tm_year = temp_tm->tm_year;
            rtc_tm.tm_wday = temp_tm->tm_wday;
            rtc_tm.tm_yday = temp_tm->tm_yday;
            rtc_tm.tm_isdst = 0;
            rtc_tm.tm_nsec = time_spec.tv_nsec;

            // Update RTC hardware
            if (rtc_set_time(rtc_dev, &rtc_tm) != 0) {
                // Fallback to milliseconds on RTC write failure
                uint32_t ms = millis();
                time.sec = ms / 1000;
                time.nanosec = (ms % 1000) * 1000000U;
                return time;
            }
        }

        // Read current time from RTC
        struct rtc_time z_time = {};
        int rc = rtc_get_time(rtc_dev, &z_time);

        if (rc == 0) {
            struct tm* z_tm = rtc_time_to_tm(&z_time);
            if (z_tm != nullptr) {
                time.sec = (int32_t)mktime(z_tm);
                time.nanosec = z_time.tm_nsec;
            } else {
                // Fallback on conversion failure
                uint32_t ms = millis();
                time.sec = ms / 1000;
                time.nanosec = (ms % 1000) * 1000000U;
            }
        } else {
            // Fallback to milliseconds on RTC read failure
            uint32_t ms = millis();
            time.sec = ms / 1000;
            time.nanosec = (ms % 1000) * 1000000U;
        }

        return time;
    }

    static void create_wall_timer(uint32_t msec, CallBack callback, void* callback_arg, PublisherInterface* pub) {
        if(pub == nullptr) return;

        pub->setPublishInterval(msec);
        pub->registerCallback(callback, callback_arg);
    }

    void runPublishers() {

        for (int i=0; i<ROUTERBRIDGE_ROS_PUB_MAX; ++i)
        {
            if (pub_list[i] != nullptr && pub_list[i]->isTimeToPublish())
            {
                pub_list[i]->publish();
            }
        }

    }

private:
    PublisherInterface* pub_list[ROUTERBRIDGE_ROS_PUB_MAX];
    SubscriberInterface* sub_list[ROUTERBRIDGE_ROS_SUB_MAX];
};

inline void spin(Node* node) {
    if (node == nullptr) return;
    node->runPublishers();
}

}

#endif //ROUTERBRIDGE_ROS_NODE_H

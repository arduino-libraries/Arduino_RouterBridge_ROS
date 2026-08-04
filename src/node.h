/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_NODE_H
#define ROUTERBRIDGE_ROS_NODE_H

#include "publisher.h"
#include "subscriber.h"

namespace ros2ino {

class Node {

    const char* name_;
    const char* node_namespace_;

public:
    explicit Node(const char* name, const char* node_namespace = "/"): name_(name), node_namespace_(node_namespace){}

    template <typename MsgType>
    Publisher<MsgType>* create_publisher(const char* topic_name) {

        for (int i=0; i<ROUTERBRIDGE_ROS_PUB_MAX; ++i)
        {
            if (pub_list[i] == nullptr)
            {
                auto* pub_ptr = new Publisher<MsgType>(topic_name);
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

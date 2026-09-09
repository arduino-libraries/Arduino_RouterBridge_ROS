/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#include <Arduino_RouterBridge_ROS.h>

void chatterCallback(std_msgs::msg::String* msg, void* arg) {
    Monitor.print("I heard: [");
    Monitor.print(msg->data.c_str());
    Monitor.println("]");

    (void)arg;
}

class StringSub : public ros2ino::Node {
public:
    StringSub()
    : Node("str_sub_node")
    {
        ros2ino::Subscriber<std_msgs::msg::String>* subscription_ = this->create_subscription<std_msgs::msg::String>("/chatter",
            (ros2ino::CallBack)chatterCallback,
            nullptr
            );

        if (subscription_ != nullptr) {
            Monitor.println("Successfully subscribed!");
        } else {
            Monitor.println("Failed to subscribe (List full or Bridge error).");
        }
    }
};

void setup() {
    Bridge.begin();
    Monitor.begin(115200);
}

void loop() {
    static StringSub node;
    ros2ino::spin(&node);

    static unsigned long last_serial_print = 0;
    if (millis() - last_serial_print > 5000)
    {
        Monitor.println("string_sub running");
        last_serial_print = millis();
    }
}
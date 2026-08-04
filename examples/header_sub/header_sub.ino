/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

/*
    This example demonstrates parsing of nested types like Header in the embedded subscriber
*/

#include <Arduino_RouterBridge_ROS.h>

void headerCallback(std_msgs::msg::Header* msg, void* arg) {
    Monitor.print("I got a header: ");
    Monitor.print(msg->frame_id);
    Monitor.print(" - ");
    Monitor.print("with a timestamp: ");
    Monitor.print(msg->stamp.sec);
    Monitor.print(".");
    Monitor.print(msg->stamp.nanosec);
    Monitor.println("");

    if (msg->stamp.sec == 0)
    {
        Monitor.println("sec == 0");
    }

    if (msg->stamp.nanosec == 0)
    {
        Monitor.println("nanosec == 0");
    }

    (void)arg;
}

class HeaderSub : public ros2ino::Node {
public:
    HeaderSub()
    : Node("header_sub_node")
    {
        ros2ino::Subscriber<std_msgs::msg::Header>* subscription_ = this->create_subscription<std_msgs::msg::Header>("/get_header",
            (ros2ino::CallBack)headerCallback,
            nullptr
            );

        if (subscription_ != nullptr) {
            Serial1.println("Successfully subscribed!");
        } else {
            Serial1.println("Failed to subscribe (List full or Bridge error).");
        }
    }
};

void setup() {
    Serial1.begin(115200);
    Bridge.begin();
    Monitor.begin(115200);
}

void loop() {
    static HeaderSub node;
    ros2ino::spin(&node);

    static unsigned long last_serial_print = 0;
    if (millis() - last_serial_print > 5000)
    {
        Monitor.println("header_sub running");
        last_serial_print = millis();
    }
}
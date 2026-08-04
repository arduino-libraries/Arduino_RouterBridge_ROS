/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

    Example demonstrating a combined Publisher and Subscriber in a single node
    using the Arduino_RouterBridge_ROS library.
*/

#include <Arduino_RouterBridge_ROS.h>

#define PUBLISH_INTERVAL_MS 500

// Callback for the subscriber
void stringCallback(std_msgs::msg::String* msg, void* arg) {
    Monitor.print("Subscriber received: [");
    Monitor.print(msg->data.c_str());
    Monitor.println("]");
    (void)arg;
}

// Callback for the publisher timer
void timerCallback(std_msgs::msg::Int32 *msg, void* arg) {
    static int count = 0;
    *msg = count++;
    Monitor.print("Timer publishing: ");
    Monitor.println(*msg);
    (void)arg;
}

class CombinedNode : public ros2ino::Node {
public:
    CombinedNode() : Node("combined_pub_sub_node") {
        // 1. Setup Publisher with a Timer
        ros2ino::Publisher<std_msgs::msg::Int32>* pub = this->create_publisher<std_msgs::msg::Int32>("counter_output");
        this->create_wall_timer(PUBLISH_INTERVAL_MS, (ros2ino::CallBack)timerCallback, nullptr, pub);

        // 2. Setup Subscriber
        this->create_subscription<std_msgs::msg::String>(
            "message_input",
            (ros2ino::CallBack)stringCallback,
            nullptr
        );

        Monitor.println("Node initialized with Publisher and Subscriber.");
    }
};

void setup() {
    Bridge.begin();
    Monitor.begin(115200);
}

void loop() {
    // Instantiate the node once
    static CombinedNode node;

    // Process incoming bridge messages and trigger timers
    ros2ino::spin(&node);

    // Heartbeat for the Monitor tool
    static unsigned long last_print = 0;
    if (millis() - last_print > 5000) {
        Monitor.print("Combined node is spinning...");
        last_print = millis();
    }
}
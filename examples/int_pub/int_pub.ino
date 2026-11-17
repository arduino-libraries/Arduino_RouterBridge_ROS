/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#include <Arduino_RouterBridge_ROS.h>

#define PUBLISH_INTERVAL_MS 100

void publishInt(std_msgs::msg::Int32 *val, void* arg) {
    (void)arg;

    static int cnt = 0;
    val->data = cnt++;
}

class IntPub : public ros2ino::Node {
public:
    IntPub() : Node("int_pub_node") {
        ros2ino::Publisher<std_msgs::msg::Int32>* publisher_ = this->create_publisher<std_msgs::msg::Int32>("simple_counter");
        this->create_wall_timer(PUBLISH_INTERVAL_MS, (ros2ino::CallBack)publishInt, nullptr, publisher_);
    }
};

void setup() {
    Bridge.begin();
    Serial.begin(115200);

    while (!ros2ino::available()) { Serial.println("No ROS 2 proxy available"); delay(1000); }
}

void loop() {
    static IntPub node;
    ros2ino::spin(&node);

    static unsigned long last_serial_print = 0;
    if (millis() - last_serial_print > 5000) {
        Serial.print("int_pub running");
        last_serial_print = millis();
    }
}

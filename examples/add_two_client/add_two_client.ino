/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#include <Arduino_RouterBridge_ROS.h>
#include "../../Arduino_RouterBridge_ROS/src/example_interfaces/srv/AddTwoInts.h"

ros2ino::Node* node = nullptr;
ros2ino::Client<example_interfaces::srv::AddTwoInts>* client = nullptr;

void setup() {
    Bridge.begin();
    Serial.begin(115200);

    while (!ros2ino::available()) {
        Serial.println("No ROS2 proxy available");
        delay(1000);
    }

    static ros2ino::Node n("add_two_ints_client");
    node = &n;
    client = node->create_client<example_interfaces::srv::AddTwoInts>("add_two_ints");

    if (client == nullptr) {
        Serial.println("create_client failed");
    }
}

void loop() {
    if (client == nullptr) { Serial.println("No CLIENT"); delay(1000); return; }

    if (!client->isRegistered()) {
        client->register_();
        if (!client->isRegistered()) {
            Serial.println("UNREG");
            delay(1000);
            return;
        }
    }

    static example_interfaces::srv::AddTwoInts::Request request;
    request.a = 10;
    request.b = 20;

    auto async_call = client->async_send_request(&request);
    static example_interfaces::srv::AddTwoInts::Response response;
    async_call.result(response);

    Serial.print("calling add_two_ints service returned: ");
    Serial.println(response.sum);

    delay(1000);
}
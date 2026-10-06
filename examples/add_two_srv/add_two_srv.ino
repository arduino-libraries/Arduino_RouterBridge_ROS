/*
This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#include <Arduino_RouterBridge_ROS.h>
#include "../../Arduino_RouterBridge_ROS/src/example_interfaces/srv/AddTwoInts.h"


void add_two_ints(example_interfaces::srv::AddTwoInts::Request *request, example_interfaces::srv::AddTwoInts::Response *response, void* arg)
{
    (void)arg;
    response->sum = request->a + request->b;
}

class AdderSrv : public ros2ino::Node
{
public:
    AdderSrv()
    : Node("adder_srv_node")
    {
        this->create_service<example_interfaces::srv::AddTwoInts>("add_two_ints", (ros2ino::ServiceCallback)add_two_ints, nullptr);
    }
};

void setup()
{
    Bridge.begin();
    Serial.begin(115200);

    if (!ros2ino::available()) {Serial.println("No ROS2 proxy available"); delay(1000);}
}

void loop()
{
    static AdderSrv node;
    ros2ino::spin(&node);

    static unsigned long last_serial_print = 0;
    if (millis() - last_serial_print > 5000)
    {
        Serial.print("adder_srv running");
        last_serial_print = millis();
    }

}

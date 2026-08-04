/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#include <Arduino_RouterBridge_ROS.h>
#include "Arduino_Modulino.h"

ModulinoJoystick joystick;

ros2ino::Node myNode("joy_node");
ros2ino::Publisher<sensor_msgs::msg::Joy>* joy_pub = nullptr;


bool is_pressed;
float x_axis, y_axis;

void setup() {
    Bridge.begin();
    Serial.begin(115200);

    Modulino.begin(Wire1);
    joystick.begin();

    // Create the publisher for the JOYSTICK topic
    joy_pub = myNode.create_publisher<sensor_msgs::msg::Joy>("/joy/data_raw");
}

void loop() {

    // throttling @ 100 Hz
    static long last_time = 0;
    if (millis() - last_time < 10) {
        return;
    } else {
        last_time = millis();
    }
    joystick.update();

    // Get axis and pressbtn values
    is_pressed = (bool)joystick.isPressed();
    x_axis = joystick.getX();
    y_axis = joystick.getY();

    //Serial.println(String(x)+" "+String(y)+" "+(is_pressed ? "pressed": "released"));

    if (joy_pub != nullptr) {
        std_msgs::msg::Header header;
        header.stamp = builtin_interfaces::msg::Time();
        header.frame_id = "joy_link";

        std::vector<float> axes = {x_axis, y_axis};
        std::vector<int32_t> buttons = {is_pressed ? 1 : 0};

        sensor_msgs::msg::Joy joy_msg(header, axes, buttons);

        joy_pub->publish(&joy_msg);
    }

}
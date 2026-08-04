/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#include <Arduino_RouterBridge_ROS.h>

#define PUBLISH_INTERVAL_MS 100

void publishStr(std_msgs::msg::String *val, void* arg)
{
    (void)arg;

    static int cnt = 0;

    MsgPack::str_t msg = "Sequence: #";

    val->data = msg + String(cnt++);
}

class StrPub : public ros2bridge::Node
{
public:
    StrPub()
    : Node("str_pub_node")
    {
        ros2bridge::Publisher<std_msgs::msg::String>* publisher_ = this->create_publisher<std_msgs::msg::String>("simple_string");
        this->create_wall_timer(PUBLISH_INTERVAL_MS, (ros2bridge::CallBack)publishStr, nullptr, publisher_);
    }
};

void setup()
{
    Bridge.begin();
    Monitor.begin(115200);
}

void loop()
{
    static StrPub node;
    ros2bridge::spin(&node);

    static unsigned long last_serial_print = 0;
    if (millis() - last_serial_print > 5000)
    {
        Monitor.print("string_pub running");
        last_serial_print = millis();
    }

}

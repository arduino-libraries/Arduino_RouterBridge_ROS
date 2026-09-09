#include <Arduino_RouterBridge_ROS.h>

void vector3Callback(geometry_msgs::msg::Vector3* msg, void* arg) {
    (void)arg;

    Monitor.print("Vector3: x=");
    Monitor.print(msg->x);
    Monitor.print(" y=");
    Monitor.print(msg->y);
    Monitor.print(" z=");
    Monitor.println(msg->z);
}

class Vector3Sub : public ros2ino::Node {
public:
    Vector3Sub() : Node("vector3_sub_node") {
        auto* sub = this->create_subscription<geometry_msgs::msg::Vector3>(
            "/vector3",
            (ros2ino::CallBack)vector3Callback,
            nullptr
        );

        if (sub != nullptr) Monitor.println("Vector3 subscribed!");
        else Monitor.println("Vector3 subscribe failed.");
    }
};

void setup() {
    Bridge.begin();
    Monitor.begin(115200);
}

void loop() {
    static Vector3Sub node;
    ros2ino::spin(&node);

    static unsigned long last = 0;
    if (millis() - last > 5000) {
        Monitor.println("vector3_sub running");
        last = millis();
    }
}
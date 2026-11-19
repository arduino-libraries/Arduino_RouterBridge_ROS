#include <Arduino_RouterBridge_ROS.h>

void vector3Callback(geometry_msgs::msg::Vector3* msg, void* arg) {
    (void)arg;

    Serial.print("Vector3: x=");
    Serial.print(msg->x);
    Serial.print(" y=");
    Serial.print(msg->y);
    Serial.print(" z=");
    Serial.println(msg->z);
}

class Vector3Sub : public ros2ino::Node {
public:
    Vector3Sub() : Node("vector3_sub_node") {
        auto* sub = this->create_subscription<geometry_msgs::msg::Vector3>(
            "/vector3",
            (ros2ino::CallBack)vector3Callback,
            nullptr
        );

        if (sub != nullptr) Serial.println("Vector3 subscribed!");
        else Serial.println("Vector3 subscribe failed.");
    }
};

void setup() {
    Bridge.begin();
    Serial.begin(115200);
    
    while (!ros2ino::available()) {Serial.println("No ROS2 proxy available"); delay(1000);}
}

void loop() {
    static Vector3Sub node;
    ros2ino::spin(&node);

    static unsigned long last = 0;
    if (millis() - last > 5000) {
        Serial.println("vector3_sub running");
        last = millis();
    }
}
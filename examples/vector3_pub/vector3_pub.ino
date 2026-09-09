#include <Arduino_RouterBridge_ROS.h>

ros2ino::Node node("vector3_pub_node");
ros2ino::Publisher<geometry_msgs::msg::Vector3>* pub = nullptr;

void setup() {
    Bridge.begin();
    Monitor.begin(115200);

    pub = node.create_publisher<geometry_msgs::msg::Vector3>("/vector3");
    if (pub == nullptr) {
        Monitor.println("Failed to create Vector3 publisher.");
    } else {
        Monitor.println("Vector3 publisher created.");
    }
}

void loop() {

    if (pub != nullptr) {
        geometry_msgs::msg::Vector3 msg;
        const float t = millis() * 0.001f;

        msg.x = t;          // ramp
        msg.y = -t;         // ramp (negative)
        msg.z = 1.0;        // constant

        pub->publish(&msg);
    }

    delay(100); // ~10 Hz
}
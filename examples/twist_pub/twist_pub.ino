#include <Arduino_RouterBridge_ROS.h>

ros2ino::Node node("twist_pub_node");
ros2ino::Publisher<geometry_msgs::msg::Twist>* pub = nullptr;

void setup() {
    Bridge.begin();
    Serial.begin(115200);

    while (!ros2ino::available()) {Serial.println("No ROS2 proxy available"); delay(1000);}

    pub = node.create_publisher<geometry_msgs::msg::Twist>("/twist_topic");
    if (pub == nullptr) {
        Serial.println("Failed to create Twist publisher.");
    } else {
        Serial.println("Twist publisher created.");
    }
}

void loop() {

    if (pub != nullptr) {
        geometry_msgs::msg::Twist msg;

        // Example command: move forward + yaw slowly
        msg.linear.x  = 0.20;
        msg.linear.y  = 0.00;
        msg.linear.z  = 0.00;

        msg.angular.x = 0.00;
        msg.angular.y = 0.00;
        msg.angular.z = 0.50;

        pub->publish(&msg);
    }

    delay(100); // ~10 Hz
}
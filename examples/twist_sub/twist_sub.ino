#include <Arduino_RouterBridge_ROS.h>

void twistCallback(geometry_msgs::msg::Twist* msg, void* arg) {
    (void)arg;

    Serial.print("Twist linear:  x=");
    Serial.print(msg->linear.x);
    Serial.print(" y=");
    Serial.print(msg->linear.y);
    Serial.print(" z=");
    Serial.print(msg->linear.z);

    Serial.print(" | angular: x=");
    Serial.print(msg->angular.x);
    Serial.print(" y=");
    Serial.print(msg->angular.y);
    Serial.print(" z=");
    Serial.println(msg->angular.z);
}

class TwistSub : public ros2ino::Node {
public:
    TwistSub() : Node("twist_sub_node") {
        auto* sub = this->create_subscription<geometry_msgs::msg::Twist>(
            "/twist_topic",
            (ros2ino::CallBack)twistCallback,
            nullptr
        );

        if (sub != nullptr) Serial.println("Twist subscribed!");
        else Serial.println("Twist subscribe failed.");
    }
};

void setup() {
    Bridge.begin();
    Serial.begin(115200);
    
    while (!ros2ino::available()) {Serial.println("No ROS2 proxy available"); delay(1000);}
    
}

void loop() {
    static TwistSub node;
    ros2ino::spin(&node);

    static unsigned long last = 0;
    if (millis() - last > 5000) {
        Serial.println("twist_sub running");
        last = millis();
    }
}
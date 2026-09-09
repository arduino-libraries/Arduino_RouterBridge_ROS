#include <Arduino_RouterBridge_ROS.h>

void twistCallback(geometry_msgs::msg::Twist* msg, void* arg) {
    (void)arg;

    Monitor.print("Twist linear:  x=");
    Monitor.print(msg->linear.x);
    Monitor.print(" y=");
    Monitor.print(msg->linear.y);
    Monitor.print(" z=");
    Monitor.print(msg->linear.z);

    Monitor.print(" | angular: x=");
    Monitor.print(msg->angular.x);
    Monitor.print(" y=");
    Monitor.print(msg->angular.y);
    Monitor.print(" z=");
    Monitor.println(msg->angular.z);
}

class TwistSub : public ros2ino::Node {
public:
    TwistSub() : Node("twist_sub_node") {
        auto* sub = this->create_subscription<geometry_msgs::msg::Twist>(
            "/twist_topic",
            (ros2ino::CallBack)twistCallback,
            nullptr
        );

        if (sub != nullptr) Monitor.println("Twist subscribed!");
        else Monitor.println("Twist subscribe failed.");
    }
};

void setup() {
    Bridge.begin();
    Monitor.begin(115200);
}

void loop() {
    static TwistSub node;
    ros2ino::spin(&node);

    static unsigned long last = 0;
    if (millis() - last > 5000) {
        Monitor.println("twist_sub running");
        last = millis();
    }
}
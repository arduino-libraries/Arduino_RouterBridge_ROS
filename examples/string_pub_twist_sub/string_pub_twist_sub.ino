// string_pub_twist_sub.ino
#include <Arduino_RouterBridge_ROS.h>

#define PUBLISH_INTERVAL_MS 100

// --- Subscriber callback: Twist ---
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

// --- Publisher timer callback: String ---
void publishStr(std_msgs::msg::String* val, void* arg) {
    (void)arg;

    static int cnt = 0;
    MsgPack::str_t prefix = "Sequence: #";
    val->data = prefix + String(cnt++);
}

class StringPubTwistSub : public ros2ino::Node {
public:
    StringPubTwistSub() : Node("string_pub_twist_sub_node") {
        // Publisher + timer
        ros2ino::Publisher<std_msgs::msg::String>* pub =
            this->create_publisher<std_msgs::msg::String>("simple_string");
        this->create_wall_timer(PUBLISH_INTERVAL_MS, (ros2ino::CallBack)publishStr, nullptr, pub);

        // Subscriber
        auto* sub = this->create_subscription<geometry_msgs::msg::Twist>(
            "/twist_topic",
            (ros2ino::CallBack)twistCallback,
            nullptr
        );

        if (sub != nullptr) Monitor.println("Twist subscribed!");
        else Monitor.println("Twist subscribe failed.");

        Monitor.println("String publisher started.");
    }
};

void setup() {
    Bridge.begin();
    Monitor.begin(115200);
}

void loop() {
    static StringPubTwistSub node;
    ros2ino::spin(&node);

    static unsigned long last = 0;
    if (millis() - last > 5000) {
        Monitor.println("string_pub_twist_sub running");
        last = millis();
    }
}
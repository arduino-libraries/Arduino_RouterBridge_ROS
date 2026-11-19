// string_pub_twist_sub.ino
#include <Arduino_RouterBridge_ROS.h>

#define PUBLISH_INTERVAL_MS 100

// --- Subscriber callback: Twist ---
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

        if (sub != nullptr) Serial.println("Twist subscribed!");
        else Serial.println("Twist subscribe failed.");

        Serial.println("String publisher started.");
    }
};

void setup() {
    Bridge.begin();
    Serial.begin(115200);
    
    while (!ros2ino::available()) {Serial.println("No ROS2 proxy available"); delay(1000);}
}

void loop() {
    static StringPubTwistSub node;
    ros2ino::spin(&node);

    static unsigned long last = 0;
    if (millis() - last > 5000) {
        Serial.println("string_pub_twist_sub running");
        last = millis();
    }
}
/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#include <Arduino_RouterBridge_ROS.h>
#include "Arduino_Modulino.h"
#include "Modulino_LED_Matrix.h"
#include "LEDMatrixGallery.h"

ModulinoLEDMatrix matrix(DEFAULT_ADDRESS, Wire2);
ModulinoMovement movement;
ModulinoPixels leds;
ModulinoColor OFF(0, 0, 0);


ros2ino::Node myNode("imu_node");
ros2ino::Publisher<sensor_msgs::msg::Imu>* imu_pub = nullptr;


float x, y, z;
float roll, pitch, yaw;

int brightness = 25;

void setLeds(int x){
    switch(x){
        case -1:
            matrix.clear();
        case 0:
            for (int i = 0; i < 8; i++) {
                leds.set(i, OFF, brightness);
            }     
            break;
        case 1:
            for (int i = 0; i < 8; i++) {
                leds.set(i, RED, brightness);
            }     
            break;   
        case 2:
            for (int i = 0; i < 8; i++) {
                leds.set(i, GREEN, brightness);
            }     
            break;   
        case 3:
            for (int i = 0; i < 8; i++) {
                leds.set(i, BLUE, brightness);
            }     
            break;  
        case 100:
            matrix.clear();
            break;
        case 101:
            matrix.setFrame(LEDMATRIX_HEART_BIG);
            break;
        case 102:
            matrix.setFrame(LEDMATRIX_HEART_SMALL);
            break;
        case 103:
            matrix.setFrame(LEDMATRIX_EMOJI_BASIC);
            break;
        case 104:
            matrix.setFrame(LEDMATRIX_EMOJI_HAPPY);
            break;
        case 105:
            matrix.setFrame(LEDMATRIX_EMOJI_SAD);
            break;
        case 106:
            matrix.setFrame(LEDMATRIX_LIKE);
            break;
        case 107:
            matrix.setFrame(LEDMATRIX_DANGER);
            break;
        case 108:
            matrix.setFrame(LEDMATRIX_BOOTLOADER_ON);
            break;
        default:
            for (int i = 0; i < 8; i++) {
                leds.set(i, WHITE, brightness);
            }     
            break; 
    }
    leds.show();
}

void intCallback(std_msgs::msg::Int16* msg, void* arg) {
    Monitor.print("I got data: int ");
    Monitor.print(msg->data);
    Monitor.println("");
    setLeds(msg->data);
    (void)arg;
}

class IntSub : public ros2ino::Node {
public:
    IntSub()
    : Node("str_sub_node")
    {
        ros2ino::Subscriber<std_msgs::msg::Int16>* subscription_ = this->create_subscription<std_msgs::msg::Int16>("/led_cmd",
            (ros2ino::CallBack)intCallback,
            nullptr
            );

        if (subscription_ != nullptr) {
            Monitor.println("Successfully subscribed!");
        } else {
            Monitor.println("Failed to subscribe (List full or Bridge error).");
        }
    }
};

void setup() {
    Bridge.begin();
    Monitor.begin(115200);

    Modulino.begin(Wire1);
    movement.begin();
    matrix.begin();
    leds.begin();


    // Create the publisher for the IMU topic
    imu_pub = myNode.create_publisher<sensor_msgs::msg::Imu>("/imu/data_raw");
}

void loop() {
    static IntSub node;
    ros2ino::spin(&node);
    static uint32_t seq = 0;

    movement.update();

    // Get acceleration and gyroscope values
    x = movement.getX() * 9.8;
    y = movement.getY() * 9.8;
    z = movement.getZ() * 9.8;
    roll = movement.getRoll();
    pitch = movement.getPitch();
    yaw = movement.getYaw();
    
    Monitor.println(String(x)+" "+String(y)+" "+String(z));

    

    if (imu_pub != nullptr) {
        // 1. Prepare sub-messages
        std_msgs::msg::Header header;
        header.stamp.sec = millis() / 1000;
        header.stamp.nanosec = (millis() % 1000) * 1000000;
        header.frame_id = "imu_link";

        geometry_msgs::msg::Quaternion orientation;
        orientation.x = 0.0; orientation.y = 0.0; orientation.z = 0.0; orientation.w = 1.0;

        std::vector<double> covariance = {0.01, 0.0, 0.0, 0.0, 0.01, 0.0, 0.0, 0.0, 0.01};
        
        
        geometry_msgs::msg::Vector3 angular_velocity;
        angular_velocity.x = 0.00; angular_velocity.y = 0.0; angular_velocity.z = 0.0;

        geometry_msgs::msg::Vector3 linear_acceleration;
        linear_acceleration.x = x; linear_acceleration.y = y; linear_acceleration.z = z; // Gravity

        // 2. Instantiate the IMU struct using your defined constructor
        sensor_msgs::msg::Imu imu_msg(header, orientation, angular_velocity, linear_acceleration);
        imu_msg.linear_acceleration_covariance = covariance;
        imu_msg.orientation_covariance = covariance;
        imu_msg.angular_velocity_covariance = covariance;

        // Note: orientation_covariance, angular_velocity_covariance,
        // and linear_acceleration_covariance remain empty vectors.

        // 3. Publish the message
        imu_pub->publish(&imu_msg);
    }

    delay(10); // Publish at roughly 100 Hz
}
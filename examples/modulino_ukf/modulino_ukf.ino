/*
    This file is part of the ROS_RouterBridge library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#include <ros2bridge.h>
#include "Arduino_Modulino.h"
#include "math.h"

#define PUBLISH_INTERVAL_MS 10

ModulinoMovement movement;

double odr = 104.0;  // ODR

double acc_noise_density_ug_sqrtHz = 70.0;  // FS ±2g
double acc_noise_density = acc_noise_density_ug_sqrtHz * 1e-6 * 9.81; // m/s^2/√Hz

double gyro_noise_density_mdps_sqrtHz = 3.8;
double gyro_noise_density = gyro_noise_density_mdps_sqrtHz * 1e-3 * (M_PI / 180.0); // rad/s/√Hz

double sigma_acc  = acc_noise_density  * sqrt(odr / 2.0);
double sigma_gyro = gyro_noise_density * sqrt(odr / 2.0);

double acc_var_  = sigma_acc  * sigma_acc;   // ≈ 2.82e-5 (@ FS=±4g, 104Hz)
double gyro_var_ = sigma_gyro * sigma_gyro;  // ≈ 2.29e-7 (104Hz)

std::vector<double> lin_acc_cov(9, 0.0);
std::vector<double> ang_vel_cov(9, 0.0);

void publishMovement(sensor_msgs::Imu *val, void* arg)
{
    (void)arg;

    movement.update();

    std_msgs::Header header;
    // this is overwritten by default
    // header.stamp.sec = millis() / 1000;
    // header.stamp.nanosec = (millis() % 1000) * 1000000;
    header.frame_id = "imu_link";

    // orientation is ignored
    geometry_msgs::Quaternion orientation;
    orientation.x = 0.0; orientation.y = 0.0; orientation.z = 0.0; orientation.w = 1.0;
    std::vector<double> ignore_covariance = {-1, 0.0, 0.0, 0.0, 0.00, 0.0, 0.0, 0.0, 0.00};

    float x, y, z, gx, gy, gz;
    x = movement.getX() * 9.8;
    y = movement.getY() * 9.8;
    z = movement.getZ() * 9.8;
    gx = movement.getRoll();
    gy = movement.getPitch();
    gz = movement.getYaw();

    val->header = header;
    val->orientation = orientation;
    val->linear_acceleration = geometry_msgs::Vector3(x, y, z);
    val->angular_velocity = geometry_msgs::Vector3(gx, gy, gz);

    val->orientation_covariance = ignore_covariance;
    val->linear_acceleration_covariance = lin_acc_cov;
    val->angular_velocity_covariance = ang_vel_cov;

}

class ModulinoMovementPub : public  ros2bridge::Node
{
public:
    ModulinoMovementPub()
    : Node("ukf_node")
    {
        ros2bridge::Publisher<sensor_msgs::Imu>* publisher_ = this->create_publisher<sensor_msgs::Imu>("imu/data_raw");
        this->create_wall_timer(PUBLISH_INTERVAL_MS, (ros2bridge::CallBack)publishMovement, nullptr, publisher_);
    }

};

void setup() {
    Bridge.begin();
    Serial.begin(115200);

    Modulino.begin(Wire1);
    movement.begin();

    lin_acc_cov[0] = acc_var_;
    lin_acc_cov[4] = acc_var_;
    lin_acc_cov[8] = acc_var_;

    ang_vel_cov[0] = gyro_var_;
    ang_vel_cov[4] = gyro_var_;
    ang_vel_cov[8] = gyro_var_;

}

void loop() {
    static ModulinoMovementPub node;
    ros2bridge::spin(&node);

    static unsigned long last_serial_print = 0;
    if (millis() - last_serial_print > 1000)
    {
        Serial.println("ukf example running");
        last_serial_print = millis();
    }

}
/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_COMMON_H
#define ROUTERBRIDGE_ROS_COMMON_H

#define ROUTERBRIDGE_ROS_PUB_MAX 10
#define ROUTERBRIDGE_ROS_SUB_MAX 10

#define ROS2_READY_CALL "ros2/ready"
#define ROS2_RESET_CALL "ros2/reset"

// types
#include "std_msgs/Bool.h"
#include "std_msgs/Byte.h"
#include "std_msgs/ByteMultiArray.h"
#include "std_msgs/Char.h"
#include "std_msgs/ColorRGBA.h"
#include "std_msgs/Empty.h"
#include "std_msgs/Float32.h"
#include "std_msgs/Float32MultiArray.h"
#include "std_msgs/Float64.h"
#include "std_msgs/Float64MultiArray.h"
#include "std_msgs/Header.h"
#include "std_msgs/Int8.h"
#include "std_msgs/Int8MultiArray.h"
#include "std_msgs/Int16.h"
#include "std_msgs/Int16MultiArray.h"
#include "std_msgs/Int32.h"
#include "std_msgs/Int32MultiArray.h"
#include "std_msgs/Int64.h"
#include "std_msgs/Int64MultiArray.h"
#include "std_msgs/MultiArrayDimension.h"
#include "std_msgs/MultiArrayLayout.h"
#include "std_msgs/String.h"
#include "std_msgs/UInt8.h"
#include "std_msgs/UInt8MultiArray.h"
#include "std_msgs/UInt16.h"
#include "std_msgs/UInt16MultiArray.h"
#include "std_msgs/UInt32.h"
#include "std_msgs/UInt32MultiArray.h"
#include "std_msgs/UInt64.h"
#include "std_msgs/UInt64MultiArray.h"
// builtin
#include "builtin_interfaces/Duration.h"
#include "builtin_interfaces/Time.h"
// geometry
#include "geometry_msgs/Accel.h"
#include "geometry_msgs/AccelStamped.h"
#include "geometry_msgs/AccelWithCovariance.h"
#include "geometry_msgs/AccelWithCovarianceStamped.h"
#include "geometry_msgs/Inertia.h"
#include "geometry_msgs/InertiaStamped.h"
#include "geometry_msgs/Point.h"
#include "geometry_msgs/Point32.h"
#include "geometry_msgs/PointStamped.h"
#include "geometry_msgs/Polygon.h"
#include "geometry_msgs/PolygonInstance.h"
#include "geometry_msgs/PolygonInstanceStamped.h"
#include "geometry_msgs/PolygonStamped.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/Pose2D.h"
#include "geometry_msgs/PoseArray.h"
#include "geometry_msgs/PoseStamped.h"
#include "geometry_msgs/PoseWithCovariance.h"
#include "geometry_msgs/PoseWithCovarianceStamped.h"
#include "geometry_msgs/Quaternion.h"
#include "geometry_msgs/QuaternionStamped.h"
#include "geometry_msgs/Transform.h"
#include "geometry_msgs/TransformStamped.h"
#include "geometry_msgs/Twist.h"
#include "geometry_msgs/TwistStamped.h"
#include "geometry_msgs/TwistWithCovariance.h"
#include "geometry_msgs/TwistWithCovarianceStamped.h"
#include "geometry_msgs/Vector3.h"
#include "geometry_msgs/Vector3Stamped.h"
#include "geometry_msgs/VelocityStamped.h"
#include "geometry_msgs/VelocityWithCovarianceStamped.h"
#include "geometry_msgs/Wrench.h"
#include "geometry_msgs/WrenchStamped.h"
// sensors
#include "sensor_msgs/BatteryState.h"
#include "sensor_msgs/CameraInfo.h"
#include "sensor_msgs/ChannelFloat32.h"
#include "sensor_msgs/CompressedImage.h"
#include "sensor_msgs/FluidPressure.h"
#include "sensor_msgs/Illuminance.h"
#include "sensor_msgs/Imu.h"
#include "sensor_msgs/Image.h"
#include "sensor_msgs/JointState.h"
#include "sensor_msgs/Joy.h"
#include "sensor_msgs/JoyFeedback.h"
#include "sensor_msgs/JoyFeedbackArray.h"
#include "sensor_msgs/LaserEcho.h"
#include "sensor_msgs/LaserScan.h"
#include "sensor_msgs/MagneticField.h"
#include "sensor_msgs/MultiDOFJointState.h"
#include "sensor_msgs/MultiEchoLaserScan.h"
#include "sensor_msgs/NavSatFix.h"
#include "sensor_msgs/NavSatStatus.h"
#include "sensor_msgs/PointCloud.h"
#include "sensor_msgs/PointCloud2.h"
#include "sensor_msgs/PointField.h"
#include "sensor_msgs/Range.h"
#include "sensor_msgs/RegionOfInterest.h"
#include "sensor_msgs/RelativeHumidity.h"
#include "sensor_msgs/Temperature.h"
#include "sensor_msgs/TimeReference.h"

namespace ros2ino
{

    typedef void(*CallBack)(void* msg, void* arg);

    inline bool available()
    {
        bool is_ready = false;
        return Bridge.call(ROS2_READY_CALL).result(is_ready) && is_ready;
    }

    inline bool reset()
    {
        return Bridge.call(ROS2_RESET_CALL).result();
    }

}

#endif //ROUTERBRIDGE_ROS_COMMON_H

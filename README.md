# ⚠️ Arduino_RouterBridge_ROS
> ⚠️ This library is WIP  
> At the moment Arduino_RouterBridge_ROS is only compatible with versions of the `arduino-router` that include:  
>[#60](https://github.com/arduino/arduino-router/pull/60)  
>[#62](https://github.com/arduino/arduino-router/pull/62)  
> As for example this RC: [v0.10.0-rc.1](https://github.com/arduino/arduino-router/releases/tag/v0.10.0-rc.1)

Arduino library to interface to ROS 2 through Arduino Router

---

## 🤖 Architecture Overview
> ⚠️ COMPATIBILITY: At the moment the [**Arduino® VENTUNO Q™**](https://www.arduino.cc/product-ventuno-q) is the only board supported
* **MCU side (Arduino):** Runs firmware built with this standalone Arduino library.
* **MPU side (Linux):** Runs the `arduino_proxy` node in [arduino_router_ros](https://github.com/arduino/arduino_router_ros) to expose MCU RPC interfaces as ROS 2 topics and services.

---

## ✅ Prerequisites

ROS2 Jazzy must be installed and sourced on the Linux side  
The library is based on [Arduino_RouterBridge](https://github.com/arduino-libraries/Arduino_RouterBridge.git) so an instance of arduino-router.service must be running  
An arduino_proxy ROS2 node must be running via the following command

```bash
ros2 run arduino_router_ros arduino_proxy
```

---

## Example benchmarks

### modulino_joy
throttled @100Hz
```bash
arduino@ventunoq:~$ ros2 topic hz /joy/data_raw
average rate: 98.551
        min: 0.008s max: 0.012s std dev: 0.00091s window: 100
average rate: 98.647
        min: 0.008s max: 0.012s std dev: 0.00096s window: 199
average rate: 98.876
        min: 0.006s max: 0.015s std dev: 0.00104s window: 299
average rate: 98.783
        min: 0.006s max: 0.015s std dev: 0.00103s window: 398
```
free running
```bash
arduino@ventunoq:~$ ros2 topic hz /joy/data_raw
average rate: 188.635
min: 0.002s max: 0.008s std dev: 0.00095s window: 190
average rate: 196.125
min: 0.001s max: 0.009s std dev: 0.00099s window: 394
average rate: 194.481
min: 0.001s max: 0.009s std dev: 0.00101s window: 586
average rate: 190.689
min: 0.001s max: 0.009s std dev: 0.00100s window: 766
```

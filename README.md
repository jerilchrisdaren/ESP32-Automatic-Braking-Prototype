# ESP32-Automatic-Braking-Prototype
ESP32-based front and rear obstacle detection with automatic braking control prototype.

# ESP32 Automatic Braking Prototype

An ESP32-based automotive safety prototype that uses front and rear ultrasonic sensors to detect nearby obstacles and automatically control a servo-based braking actuator.

## 🚗 Project Overview

This project demonstrates the basic concept of an **Automatic Emergency Braking (AEB) prototype** using an ESP32.

The system continuously monitors the distance from obstacles using two ultrasonic sensors:

- Front ultrasonic sensor
- Rear ultrasonic sensor

Based on the detected distance, the system provides visual and audio warnings and changes the position of a servo motor representing the braking actuator.

> **Note:** This is an educational prototype and is not designed to control the braking system of a real vehicle.

---

## 🎯 Objective

The main objectives of this project are:

- Detect obstacles in front and behind the vehicle.
- Monitor obstacle distance continuously.
- Provide different warning levels.
- Automatically activate the prototype braking actuator when an obstacle is critically close.
- Demonstrate automotive embedded-system control logic.

---

## 🧩 Components Used

| Component | Quantity |
|---|---:|
| ESP32 Development Board | 1 |
| HC-SR04 Ultrasonic Sensor | 2 |
| Servo Motor | 1 |
| 16×2 I2C LCD | 1 |
| Buzzer | 1 |
| Green LED | 1 |
| Yellow LED | 1 |
| Red LED | 1 |
| Jumper Wires | As required |

---

## 🔌 Pin Configuration

### Front Ultrasonic Sensor

| Function | ESP32 Pin |
|---|---:|
| TRIG | GPIO 5 |
| ECHO | GPIO 18 |

### Rear Ultrasonic Sensor

| Function | ESP32 Pin |
|---|---:|
| TRIG | GPIO 19 |
| ECHO | GPIO 23 |

### Other Components

| Component | ESP32 Pin |
|---|---:|
| Brake Servo | GPIO 25 |
| Buzzer | GPIO 14 |
| Green LED | GPIO 27 |
| Yellow LED | GPIO 26 |
| Red LED | GPIO 33 |
| I2C LCD | I2C |

LCD address:

```text
0x27

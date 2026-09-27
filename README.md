# ESP32-Automatic-Braking-Prototype
ESP32-based front and rear obstacle detection with automatic braking control prototype.



# ESP32 Automatic Braking Prototype

ESP32-based front and rear obstacle detection with automatic braking control prototype.

## 🚗 Project Overview

This project demonstrates an **ESP32-based automatic braking prototype** designed to detect obstacles from both the front and rear of a vehicle and automatically activate a braking actuator when a critical obstacle is detected.

The system provides:

- Front obstacle detection
- Rear obstacle detection
- Automatic braking
- Visual warning using LEDs
- Audio warning using a buzzer
- LCD status feedback
- Servo-based brake actuator control

> **Note:** This is an educational embedded-systems prototype and is not intended for use in a real vehicle.

## 🎯 Objective

The main objective of this project is to understand how an embedded controller can:

1. Monitor multiple ultrasonic sensors.
2. Determine obstacle distance.
3. Classify different safety conditions.
4. Automatically control a braking actuator.
5. Provide visual and audio warnings.
6. Display system status through an I2C LCD.

## 🧰 Components Used

- ESP32 Development Board
- 2 × HC-SR04 Ultrasonic Sensors
- Servo Motor
- 16×2 I2C LCD
- Red LED
- Yellow LED
- Green LED
- Buzzer
- Resistors
- Jumper Wires

## 🔌 Pin Configuration

| Component | ESP32 Pin |
|---|---|
| Front HC-SR04 TRIG | GPIO 5 |
| Front HC-SR04 ECHO | GPIO 18 |
| Rear HC-SR04 TRIG | GPIO 19 |
| Rear HC-SR04 ECHO | GPIO 23 |
| Brake Servo | GPIO 25 |
| Buzzer | GPIO 14 |
| Green LED | GPIO 27 |
| Yellow LED | GPIO 26 |
| Red LED | GPIO 33 |
| I2C LCD | I2C |

## 📟 LCD Address

```text
0x27
## 🔬 Wokwi Simulation

The project was designed and tested using the Wokwi online simulator.

### Circuit Diagram

![ESP32 Automatic Braking Prototype](automatic-braking-wokwi.png)

### Live Simulation

[Open the ESP32 Automatic Braking Prototype on Wokwi](YOUR_WOKWI_URL_HERE)

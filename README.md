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
| I2C LCD SDA | GPIO 21 |
| I2C LCD SCL | GPIO 22 |

## 📟 LCD Address

`0x27`
## ⚙️ Working Principle

The system uses two HC-SR04 ultrasonic sensors to continuously monitor obstacles in front of and behind the vehicle.

The ESP32 measures the distance detected by both sensors and compares the readings with predefined safety thresholds.

Based on the detected distance, the system operates in different safety states:

1. **System Safe** – No nearby obstacle is detected.
2. **Obstacle Warning** – An obstacle is detected within 50 cm.
3. **Brake Ready / Critical** – An obstacle is detected within 20 cm.
4. **Automatic Braking** – An obstacle is detected within 10 cm.

If either the front or rear sensor detects an obstacle within the critical range, the ESP32 activates the braking actuator and provides visual, audio, and LCD warnings.

The servo motor represents the braking actuator in this educational prototype.
## 🛡️ Safety Logic

The system uses distance thresholds to determine the appropriate safety response.

| Distance Condition | System Response |
|---|---|
| Distance ≥ 50 cm | System Safe |
| 20 cm ≤ Distance < 50 cm | Obstacle Warning |
| 10 cm ≤ Distance < 20 cm | Brake Ready / Critical Warning |
| Distance < 10 cm | Automatic Braking |

The safety condition is triggered when **either the front or rear ultrasonic sensor** detects an obstacle within the corresponding distance range.
## 🚨 System States

### 🟢 System Safe

When both detected distances are 50 cm or more:

- Green LED ON
- Yellow LED OFF
- Red LED OFF
- Buzzer OFF
- Brake servo returns to the normal position
- LCD displays:

```text
SYSTEM SAFE
Distance:OK
### 🟡 Obstacle Warning

When either sensor detects an obstacle below 50 cm but at least 20 cm away:

- Yellow LED ON
- Red LED OFF
- Green LED OFF
- Warning buzzer activates periodically
- Brake servo moves to the warning position
- LCD displays:

```text
OBSTACLE AHEAD
SLOW DOWN
```

### 🟡 Brake Ready / Critical

When either sensor detects an obstacle below 20 cm but at least 10 cm away:

- Yellow LED ON
- Red LED OFF
- Green LED OFF
- Warning buzzer activates
- Brake servo moves further toward the braking position
- LCD displays:

```text
BRAKE READY
CRITICAL
```

### 🔴 Automatic Braking

When either sensor detects an obstacle below 10 cm:

- Red LED ON
- Yellow LED OFF
- Green LED OFF
- Continuous buzzer
- Brake servo moves to the braking position
- LCD displays:

```text
AUTO BRAKING
STOP VEHICLE
```
The system uses LEDs and a buzzer to communicate different safety conditions to the user.

- 🟢 Green LED → System Safe
- 🟡 Yellow LED → Obstacle Warning / Brake Ready
- 🔴 Red LED → Automatic Braking
- 🔊 Buzzer → Audio warning based on obstacle distance

The buzzer uses different warning patterns depending on the detected safety condition.
## 💻 Software and Libraries

The project was developed using the **Arduino IDE** for ESP32 programming.

### Libraries Used
## 💻 Software and Libraries

The project was developed using the **Arduino IDE** for ESP32 programming.

### Libraries Used

```cpp
#include <LiquidCrystal_I2C.h>
#include <Servo.

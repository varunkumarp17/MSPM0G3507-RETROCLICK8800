# MSPM0G3507-RETROCLICK8800
# RC8800 – Driver Implementation Project

This repository contains an embedded **driver implementation project** for the **8800 Retro Click (AS1115 LED matrix driver)** using the **MSPM0G3507** microcontroller.

The project demonstrates basic **I2C driver development**, hardware abstraction, and separation between application code and driver logic.

---

## Overview
- Device: 8800 Retro Click (8×8 LED Matrix)
- Driver IC: AS1115
- MCU: MSPM0G3507
- Interface: I2C
- IDE: Code Composer Studio (CCS)

---

## Project Objective
To design and implement a reusable AS1115 driver that:
- Initializes the device
- Controls LED brightness
- Writes data to individual digits
- Separates driver code from application logic

---
## Address
<img width="172" height="206" alt="Address(0x00)" src="https://github.com/user-attachments/assets/19c51665-e40f-46d7-b238-bc120032e4ba" />

## Connection Diagram
<img width="1836" height="1802" alt="CD-VRN" src="https://github.com/user-attachments/assets/68d39a72-8277-4f94-8e94-9ea5c1746279" />

## Hardware Connections
### I2C Connections
| MSPM0G3507 Pin | Function | 8800 Retro Click |
|---------------|----------|------------------|
| PB2           | I2C SCL  | SCL              |
| PB3           | I2C SDA  | SDA              |
| 3.3V          | VCC      | VCC              |
| GND           | GND      | GND              |

> I2C pull-up resistors are provided on the 8800 Retro Click board.

---


# Autonomous Distance-Avoiding Car (ATmega32)

An advanced Embedded Systems project featuring an Autonomous Car built with a strict **Layered Architecture** on the **ATmega32** microcontroller. The system accurately measures distances, controls steering via a servo motor, drives DC motors, and outputs diagnostic data to an LCD.

## 🛠️ Hardware Specifications
- **Microcontroller:** ATmega32 (Clocked at 16MHz External Crystal)
- **Display:** 16x2 Character LCD (Configured in 4-Bit Mode with optimized delay timings)
- **Sensors:** HC-SR04 Ultrasonic Sensor 
- **Actuators:** SG90 Servo Motor (Driven via Timer1 16-bit Fast PWM at 50Hz) & DC Motors
- **Power & Safety:** 12V Li-ion Battery with activated **Brown-out Detection (BOD)** at 4.0V for power stability.

## 📂 Project Architecture
The software follows an institutional Embedded C Layered Architecture:
- `APP/`: Contains high-level application logic (`main.c`, `main.h`).
- `HAL/`: Hardware Abstraction Layer containing reusable drivers for LCD, Servo, Ultrasonic, and DC Motors.
- `MCAL/`: Microcontroller Abstraction Layer defining registers and peripheral hardware controls (DIO, TIM0, TIM1, GI).
- `LIB/`: Common libraries and configurations (`STD_TYPES.h`, `BIT_MATH.h`).

## ⚡ Key Software Optimizations
- **Timer Isolation:** Resolved critical hardware conflict by dedicating Timer1 entirely to the Servo's PWM, while handling Ultrasonic timing through non-blocking methods.
- **Signal Integrity:** Handled LCD data flickering at high clock speeds (16MHz) by introducing strict separation delays between High and Low nibbles in 4-bit mode.

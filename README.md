# 🚗 Autonomous Obstacle-Avoiding Car

An advanced, self-driving robotic system built on the **ATmega32** microcontroller. The car dynamically scans its surroundings using an ultrasonic sensor mounted on a servo motor, processes obstacles in real time, and navigates autonomously using a custom-built layered firmware stack.

---

## 📖 Overview

**Autonomous Obstacle-Avoiding Car** is an embedded project designed to showcase real-time peripheral handling and sensor fusion. By establishing precise timing controls, the car continuously measures forward distances, detects close walls, sweeps the area via a steering servo to find the optimal clear path, and drives its DC motors to navigate around obstacles without human intervention.

---

## 🏗️ System Architecture

The software architecture is engineered using an institutional **strict layered embedded design**, separating hardware controls from core application logic:

┌─────────────────────────────┐
│         APP Layer  │  ← Application Control Flow & Navigation Logic
├─────────────────────────────┤
│         HAL Layer  │  ← Hardware Abstraction (LCD, Servo, Ultrasonic, DC Motor)
├─────────────────────────────┤
│         MCAL Layer │  ← Microcontroller Abstraction (DIO, TIM0, TIM1, TIM2, GI)
└─────────────────────────────┘
---

This ensures high code modularity, making drivers fully reusable, isolated, and easy to debug or port to other hardware targets.

---

## 🔧 Hardware Components

| Component | Purpose |
| :--- | :--- |
| **ATmega32** | Core 8-bit AVR microcontroller coordinating all sensors and actuators |
| **HC-SR04** | Ultrasonic sensor for precise non-blocking distance measurement |
| **SG90 Servo** | Actuator for sweeping the ultrasonic sensor to look left and right |
| **L298N / L293D** | H-Bridge Motor Driver IC to control driving DC motors |
| **16x2 LCD** | Displays real-time diagnostic logs, current state, and distance readings |
| **12V Li-ion Battery** | High-capacity power source for the entire driving chassis |

---

## 🔌 How It Works

1. **Surrounding Scan:** The **APP layer** triggers the HC-SR04 Ultrasonic sensor via non-blocking software routines to monitor the front clearance.
2. **Diagnostic Feedback:** Current distance metrics and vehicle status are pushed instantly to the **16x2 LCD** screen.
3. **Decision Making:** When a wall or obstacle is detected within a threshold, the car stops. The **Timer1 PWM driver** sweeps the SG90 Servo to face Left ($0^\circ$) and Right ($180^\circ$) to measure alternate distances.
4. **Autonomous Navigation:** The MCU compares the clear paths, selects the direction with the maximum clearance, and signals the DC motors via the driver IC to turn and continue forward.

---

## ⚙️ Key Engineering Highlights

- ✅ **Hardware Timer Isolation:** Successfully isolated a critical timer clash by dedicating the 16-bit **Timer1 peripheral** entirely to the Servo's Fast PWM ($50\text{ Hz}$), while routing system delays and sensor measurements to independent timers.
- ✅ **Signal Integrity Optimization:** Handled LCD data corruption on high CPU clock speeds ($16\text{ MHz}$ External Crystal) by introducing optimized separation delays between High and Low nibbles in **4-Bit communication mode**.
- ✅ **Power Stability Control:** Activated the hardware **Brown-out Detector (BOD)** at $4.0\text{ V}$ to safeguard the microcontroller from power drops and random freezes caused by inductive motor startup spikes (Stall Current).
- ✅ **Layered Driver Implementation:** Complete custom driver stack built from scratch (MCAL $\rightarrow$ HAL $\rightarrow$ APP) using pure Embedded C.

---

## 🛠️ Tools & Environment

- **IDE:** Microchip Studio / Atmel Studio
- **Compiler:** AVR-GCC
- **Language:** Embedded C
- **Hardware Programmer:** USBasp (via AVRDUDESS)

---

## 📂 Project Structure

Project_3/
├── Project_3/
│   ├── APP/  # main.c, main.h (Application Loops)
│   ├── HAL/  # LCD, SERVO, ULTRASONIC, DC_MOTOR Drivers
│   ├── MCAL/ # DIO, TIM0, TIM1, TIM2, GI Drivers
│   └── LIB/  # STD_TYPES.h, BIT_MATH.h, VECTOR_TABLE.h└── Project_3.atsln   # Microchip Studio Solution File

---


## 👤 Author

**Zyad Hussein (Eltawel)**  
Mechatronics Engineer | Embedded Systems Developer  

- GitHub: [@Zyad5976](https://github.com/Zyad5976)  
- LinkedIn: [zyad-hussien-35a790199](https://www.linkedin.com/in/zyad-hussien-35a790199)

---

## 📜 License

This project is open for educational and personal use. Feel free to fork, learn from it, and build upon it.

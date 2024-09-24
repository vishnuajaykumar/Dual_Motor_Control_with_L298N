# Dual Motor Control with Joystick

**Author**: Vishnu Ajay  
**Date**: 2023  
**Revision**: A  

---

## Project Overview

This project lets you control two motors using a joystick! It's like driving a tiny robot 🚙 using just your thumb 🖐️! The joystick controls the speed and direction of two motors—one for forward and backward movement, and the other for left and right turns. With PWM, you can smoothly control the motor speeds, giving you precise control over your robot's movements.

---

## ⚙️ Components

- **Arduino** 🎛️: The brain of the operation.
- **DC Motors** 🚗🚕: Two motors controlled by the joystick.
- **Joystick** 🕹️: An analog joystick to control motor speed and direction.
- **Motor Driver** 🔌: To handle the power needed to drive the motors.
- **Wiring** 🔗: To connect everything together.

---

## 🛠️ How It Works

- **Joystick Input 🕹️**: The joystick has two axes:
  - **Y-axis** controls the first motor, which moves the robot **forward/backward**.
  - **X-axis** controls the second motor, which moves the robot **left/right**.
  
- **Motor Control 🔄**:
  - The script reads analog inputs from the joystick and converts them into motor speed and direction using PWM.
  - Depending on the joystick’s position, the motors will spin **forward**, **backward**, or **stop**. The joystick gives you proportional control over the speed!

---

## 📄 Code Breakdown

- **Pin Configuration**:
  - **IN1, IN2, ENA**: Control motor 1 (forward/backward).
  - **IN3, IN4, ENB**: Control motor 2 (left/right).
  - **X_PIN, Y_PIN**: Joystick pins for controlling the motors.

- **Joystick Values**:
  - The analog values from the joystick are mapped to a range from -255 to +255 for motor control.
  - Positive values make the motor move forward/left, while negative values make it move backward/right.

- **Motor Functions**:
  - **forward(in1, in2)**: Makes the motor spin forward by setting **IN1** HIGH and **IN2** LOW.
  - **backward(in1, in2)**: Reverses the motor by setting **IN1** LOW and **IN2** HIGH.
  - **stopMotor(in1, in2)**: Stops the motor by setting both **IN1** and **IN2** LOW.

---

## 🎮 How to Control the Motors

1. **Push the joystick forward ⬆️**: Motor 1 moves the robot forward.
2. **Pull the joystick backward ⬇️**: Motor 1 moves the robot backward.
3. **Move the joystick left ⬅️**: Motor 2 turns the robot left.
4. **Move the joystick right ➡️**: Motor 2 turns the robot right.
5. **Let go of the joystick 🛑**: Both motors stop.

---

## 🧰 Wiring

1. **Joystick**:
   - **X-axis** connected to **A0**.
   - **Y-axis** connected to **A1**.

2. **Motors**:
   - **Motor 1 (forward/backward)** pins: **IN1 (12)**, **IN2 (13)**, **ENA (11)**.
   - **Motor 2 (left/right)** pins: **IN3 (10)**, **IN4 (9)**, **ENB (5)**.
```bash
Arduino
  ┌──────────────────────────────────┐
  │                                  │
  │        ┌──────────────────┐      │
  │        │   IN1 (Pin 12)    │──────┼──> IN1 on L298N (Motor 1 control)
  │        └──────────────────┘      │
  │                                  │
  │        ┌──────────────────┐      │
  │        │   IN2 (Pin 13)    │──────┼──> IN2 on L298N (Motor 1 control)
  │        └──────────────────┘      │
  │                                  │
  │        ┌──────────────────┐      │
  │        │   ENA (Pin 11)    │──────┼──> ENA on L298N (PWM for Motor 1)
  │        └──────────────────┘      │
  │                                  │
  │        ┌──────────────────┐      │
  │        │   IN3 (Pin 10)    │──────┼──> IN3 on L298N (Motor 2 control)
  │        └──────────────────┘      │
  │                                  │
  │        ┌──────────────────┐      │
  │        │   IN4 (Pin 9)     │──────┼──> IN4 on L298N (Motor 2 control)
  │        └──────────────────┘      │
  │                                  │
  │        ┌──────────────────┐      │
  │        │   ENB (Pin 5)     │──────┼──> ENB on L298N (PWM for Motor 2)
  │        └──────────────────┘      │
  │                                  │
  │        ┌──────────────────┐      │
  │        │  X-axis (Pin A0)  │──────┼──> Joystick X-axis (Motor 2 control)
  │        └──────────────────┘      │
  │                                  │
  │        ┌──────────────────┐      │
  │        │  Y-axis (Pin A1)  │──────┼──> Joystick Y-axis (Motor 1 control)
  │        └──────────────────┘      │
  │                                  │
  │        ┌──────────────────┐      │
  │        │      GND          │──────┼──> Common Ground (shared with L298N)
  │        └──────────────────┘      │
  └──────────────────────────────────┘

L298N Motor Driver
  ┌──────────────────────────────────────────────┐
  │                                              │
  │   Power (5V External Supply) ────────────> 5V │
  │   Ground (Shared with Arduino) ──────────> GND│
  │                                              │
  │   Motor 1:                                   │
  │     IN1 (from Pin 12) ──────────────> Motor 1 Control │
  │     IN2 (from Pin 13) ──────────────> Motor 1 Control │
  │     ENA (from Pin 11) ──────────────> PWM Speed Control│
  │                                              │
  │   Motor 2:                                   │
  │     IN3 (from Pin 10) ──────────────> Motor 2 Control │
  │     IN4 (from Pin 9)  ──────────────> Motor 2 Control │
  │     ENB (from Pin 5)  ──────────────> PWM Speed Control│
  │                                              │
  │   Motor Outputs:                             │
  │     Motor 1 ──────────> Connected to Motor 1 │
  │     Motor 2 ──────────> Connected to Motor 2 │
  │                                              │
  └──────────────────────────────────────────────┘

Motors
  ┌──────────────────────────────┐
  │  │                          │
  │  │ Motor 1 connected to L298N│
  │  │ Motor Outputs             │
  │  │                          │
  │  │ Motor 2 connected to L298N│
  │  │ Motor Outputs             │
  └──────────────────────────────┘

Joystick
  ┌─────────────────────────────┐
  │  │                         │
  │  │ X-axis (A0) ─────────────┼──> X-axis control (Motor 2)
  │  │                         │
  │  │ Y-axis (A1) ─────────────┼──> Y-axis control (Motor 1)
  │  │                         │
  │  │ GND ─────────────────────┼──> Ground
  │  │ 5V ──────────────────────┼──> Power
  └─────────────────────────────┘
```
---

## 📋 Future Enhancements

- Add more advanced control with **diagonal movement**.
- Implement **acceleration and deceleration** curves for smoother control.
- Integrate an **LCD screen** to show motor speed and joystick position in real-time.

---

## 🚀 Run the Project

1. **Connect everything** as described in the wiring section.
2. Upload the code to your Arduino using the Arduino IDE.
3. Open the **Serial Monitor** to see the motor directions and speeds.
4. Move the joystick and watch your motors spin!



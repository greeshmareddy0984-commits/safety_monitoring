# ARM-Based Environmental Monitoring System

## 📌 Project Overview

This project focuses on environmental parameter monitoring using the LPC2129 ARM7 microcontroller. Developed using Embedded C in Keil µVision, it includes modules for temperature, light intensity, soil, and water monitoring.

## 🎯 Objectives

- Monitor environmental parameters using sensor modules.
- Interface sensors with the LPC2129 microcontroller.
- Use ADC for analog sensor data acquisition.
- Support LCD interfacing for displaying information.
- Implement GPIO and UART communication.

## 🛠️ Technologies Used

- **Microcontroller:** LPC2129 (ARM7TDMI)
- **Programming Language:** Embedded C
- **IDE:** Keil µVision
- **Compiler:** ARMCC
- **Interfaces:** ADC, GPIO, UART, LCD

## ⚙️ Project Modules

- `temp_read.c` – Temperature sensor reading module
- `ldr_read.c` – Light intensity reading module
- `soil_read.c` – Soil sensor reading module
- `water_read.c` – Water sensor reading module
- `ADC_init.c` – ADC initialization
- `lcd_driver.c` – LCD interface driver
- `uart0_init.c` – UART0 initialization
- `gpio_init.c` – GPIO initialization
- `led_init.c` – LED initialization
- `delay.c` – Delay functions
- `envi_main.c` – Main application module
- `header.h` – Header file
- `Startup.s` – ARM startup code

## 🚀 Getting Started

1. Install Keil µVision with support for the LPC2129 microcontroller.
2. Clone or download this repository.
3. Open `ARM_Project2.uvproj` in Keil µVision.
4. Ensure all c source files are available in their configured locations.
5. Build the project using the **Build** option.
6. Configure the appropriate hardware and debugging environment before testing.

## 💡 Applications

- Environmental parameter monitoring
- Sensor interfacing and data acquisition
- Embedded systems learning and development
- ARM microcontroller programming practice

## 📚 Learning Outcomes

- Understanding ARM7-based embedded system development
- Working with Embedded C and Keil µVision
- Learning ADC, GPIO, UART, and LCD interfacing
- Developing modular embedded software

## 👨‍💻 Project Information

**Project Name:** ARM-Based Environmental Monitoring System
**Controller:** LPC2129
**Development Environment:** Keil µVision
**Language:** Embedded C

---

*This project is intended for educational and embedded systems development purposes.*

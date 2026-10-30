# 🌡️ ESP32 Temperature & Wi-Fi Monitor

<div align="center">

[![Framework](https://img.shields.io/badge/Framework-ESP--IDF%20v5.x-blue?style=for-the-badge&logo=espressif)](https://docs.espressif.com/projects/esp-idf/)
[![Language](https://img.shields.io/badge/Language-C-informational?style=for-the-badge&logo=c)](https://en.cppreference.com/)
[![Status](https://img.shields.io/badge/Status-In%20Development-orange?style=for-the-badge)](https://github.com)
[![License: Non-Commercial](https://img.shields.io/badge/License-Non--Commercial-red.svg?style=for-the-badge)](LICENSE)

*A modular, component-based ESP32 firmware for real-time temperature monitoring, Wi-Fi connectivity, and LED status signaling.*

</div>

---

## 📜 Table of Contents
- [About The Project](#-about-the-project)
- [Design Philosophy & Vision](#-design-philosophy--vision)
- [Hardware & Architecture](#-hardware--architecture)
- [Core Features & Components](#-core-features--components)
- [Technical Approach & Architecture](#-technical-approach--architecture)
- [Roadmap & Development Status](#-roadmap--development-status)
- [Getting Started](#-getting-started)
- [Project Structure](#-project-structure)
- [Contributing](#-contributing)
- [License](#-license)

---

## 🎯 About The Project

**ESP32 Temperature & Wi-Fi Monitor** is an embedded C application designed to showcase a clean, production-ready architecture using the native **ESP-IDF** framework.

By leveraging ESP-IDF’s modular **Component System** and **FreeRTOS** multitasking, the project separates hardware drivers, network handlers, and main application orchestration into completely isolated, reusable modules.

---

## 🧠 Design Philosophy & Vision

> *"Modularity breeds scalability."*

- **Strict Component Isolation:** Each feature (LED, sensor, Wi-Fi) lives in its own decoupled folder within `components/`, making code clean and easily portbale to future projects.
- **Non-Blocking Multitasking:** Built upon FreeRTOS tasks to ensure sensor polling and network connection retries never freeze the main execution flow.
- **Robust Error Handling:** Native integration with ESP-IDF error checking (`ESP_ERROR_CHECK`) and NVS memory handling for persistent configurations.

---

## 🔌 Hardware & Architecture

Designed primarily for the **ESP32** family (including ESP32-S2, S3, C3, C6), interfacing with standard sensors and visual indicators.

- **Microcontroller:** [ESP32-S3 N16R8 DevKitC 1](https://mischianti.org/wp-content/uploads/2023/06/esp32-S3-DevKitC-1-original-pinout-low.jpg)
- **Temperature Sensor:** [DS18B20 Internal SoC Temperature Sensor](https://www.analog.com/media/en/technical-documentation/data-sheets/ds18b20.pdf)
- **Status Indicator:** Built-in board RGB LED

---

## 🛠️ Plan For Core Features & Components

| Component | Description |
| :--- | :--- |
| **`status_led`** | Manages GPIO state, non-blocking blinking patterns, and visual notifications. |
| **`temp_sensor`** | Handles periodic temperature readings in a dedicated background FreeRTOS task. |
| **`wifi_manager`** | Station mode (STA) handling, automatic reconnect logic, and event loop integration. |
| **NVS Storage** | Non-Volatile Storage initialization required for Wi-Fi calibration and credentials. |

---

## ⚙️ Technical Approach & Architecture

- **Framework:** ESP-IDF v5.x (Native Espressif SDK).
- **RTOS:** FreeRTOS for task management, mutexes, and inter-process communication (queues).
- **Build System:** CMake + Kconfig integration for flexible configuration.

---

## 🗺️ Roadmap & Development Status

- [x] **Phase 0: Project setup & repository init**
- [ ] **Phase 1: Project Scaffolding & Component Setup**
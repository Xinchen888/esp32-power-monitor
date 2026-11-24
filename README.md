# ESP32 Power & Environment Monitor

> 🚧 **Work in progress** – started November 2026. See the progress log below.

A small Wi-Fi monitoring device built on an ESP32. It measures **voltage, current and power**, plus **temperature, humidity and pressure**, and streams the readings to a live web dashboard.

## Why I'm building this

I'm interested in power electronics and the energy transition. Batteries, solar systems and EV chargers all depend on measuring voltage, current and power accurately and getting that data off the device. This project is my way of learning the whole chain – **sensors → microcontroller → wireless → dashboard** – on real hardware.

## Features

- [ ] Read temperature, humidity and pressure (BME280)
- [ ] Measure DC bus voltage, current and power (INA219)
- [ ] Serve a live dashboard over Wi-Fi directly from the ESP32
- [ ] Log readings and plot history
- [ ] Alerts when values go out of range (e.g. over-current, high temperature)
- [ ] Battery operation with low-power deep sleep
- [ ] 3D-printed enclosure

## Hardware

| Part | Purpose |
|---|---|
| Adafruit ESP32 Feather V2 | Microcontroller with Wi-Fi, USB-C and a built-in LiPo charger |
| Adafruit BME280 (STEMMA QT) | Temperature, humidity and pressure sensor |
| Adafruit INA219 (STEMMA QT) | High-side DC voltage, current and power sensor |
| STEMMA QT / Qwiic cables | Plug-in I²C connections – no soldering needed for the sensors |
| 3.7 V LiPo battery (later) | Untethered, low-power operation |

## How it works

```
 BME280 ─┐
         ├── I²C (STEMMA QT) ── ESP32 Feather V2 ── Wi-Fi ── Web dashboard (any browser)
 INA219 ─┘
```

Both sensors share one I²C bus (BME280 at address `0x77`, INA219 at `0x40`). The ESP32 reads them, runs a small web server and pushes new readings to the dashboard.

## Getting started

1. Install [Arduino IDE 2](https://www.arduino.cc/en/software) and the **esp32 by Espressif Systems** board package.
2. Select the board **Adafruit Feather ESP32 V2** and its COM port.
3. Install the libraries **Adafruit BME280**, **Adafruit INA219** and **Adafruit Unified Sensor** from the Library Manager.
4. Open the sketch in `firmware/` and put your Wi-Fi name and password in `secrets.h` (this file is not committed).
5. Upload, then open the Serial Monitor at **115200 baud**.

## Roadmap

- [ ] **Week 1** – Blink and Serial output; read the BME280
- [ ] **Week 2** – Add the INA219; build the Wi-Fi web dashboard
- [ ] **Week 3** – Data logging, alerts, battery power and deep sleep
- [ ] **Week 4** – Enclosure, write-up and demo video

## Progress log

- **18 Nov 2026** – Planned the project, ordered the parts, and set up Arduino IDE 2 with the ESP32 board package.
- **23 Nov 2026** – Ran blink and DHT22 temperature/humidity reading in the Wokwi simulator ([project link]https://wokwi.com/projects/481482470912041985)
- **24 Nov 2026** – Picked up the parts. Uploaded Blink to the real Feather ESP32 V2, then wrote my own `flash(int onTime)` function and for-loops to blink SOS in Morse code (started from the Arduino Blink example).

## What I'm learning

Embedded C++, the I²C bus, sensor calibration, Wi-Fi networking on microcontrollers, and low-power design.

## Author

**Xinchen Hou** – Electrical Engineering Systems student, University of Melbourne · [LinkedIn](https://www.linkedin.com/in/xinchen-hou)

Licensed under the [MIT License](LICENSE).

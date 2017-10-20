# Code Week IoT Workshop!

## Description
This repository contains sources for Code Week IoT Workshop.
The workshop is based on programming NodeMCU (ESP8266) with Arduino IDE.

Work is split to four parts (steps):
- Introduction
- device assembly
- work with temperature sensor
- HTTP calls and connecting to clound

## Requirements
Configuration for computers.

### Arduino

#### Install Arduino IDE
https://www.arduino.cc/en/Main/Software - choose your operating system in the menu on the right side, on next page click "Just download"

#### Add NodeMCU board

- run Arduino
- go to [File > Preferences](tools/screenshots/preferences.png?raw=true) and paste "http://arduino.esp8266.com/stable/package_esp8266com_index.json" into Additional Board Manager URLs", save changes
- go to Tools > Board > [Boards Manager](tools/screenshots/boards_manager.png?raw=true), search for ESP8266, click on it and Install  

#### Add libraries

Go to Sketch > Include Library > [Manage Libraries](tools/screenshots/library_manager.png?raw=true)
Search and install 3 packages (paste it exactly like it is):
 - "Adafruit Unified Sensor based libraries"
 - "DHT sensor library"

#### USB drivers
The newest drivers are available [here](https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers)

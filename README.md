# Arduino BLE Provisioning Example
This repo is a bare bones example of how to provision your Arduino-based ESP32 project using BLE.

This is a great option for provisioning devices that can spare the extra flash space required. 
It is generally easier for consumers to provision their devices with an app over BLE than to 
connect to a custom access point created by the ESP32.

## Why IDF and not Arduino IDE or PlatformIO
This project uses the ESP-IDF directly and is the recommended way of doing a project like this. 
This is not supported out-of-the-box in the standard
Arduino IDE and, while possible, is [not recommended](https://docs.espressif.com/projects/arduino-esp32/en/latest/faq.html#how-to-modify-an-sdkconfig-option-in-arduino) 
because it requires changes to the sdkconfig file. It _can_ be done in PlatformIO but, 
again, when using the Arduino library it is non-trivial. It's actually super simple to use
the native ESP-IDF, use the Arduino coding style, and get BLE provisioning in just a few minutes 
as you will see in the instructions given below.

## Instructions

### Windows and Mac
While it is possible to use this repo in a Docker Dev Container on Windows and Mac, 
it's easier to simply install the ESP-IDF natively using the VSCode extension.

  1. [Install VSCode](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/linux-macos-setup.html) if you haven't already
  1. In VSCode, install the Espressif IDF extension
  1. Clone this repo with `git clone --recurse-submodules https://github.com/deploythefleet/arduino_ble_provisioning.git`
  1. Open the repo in VSCode
  1. Connect your ESP32 development board to USB 

### Linux
Linux supports docker and USB devices within Docker containers natively. As such, 
all you need to install are VSCode and Docker. With those two dependencies installed 
the instructions are very simple. You do NOT have to install the ESP-IDF on your 
machine. It will be installed in the dev container for you :raised_hands:.

  1. [Install Docker](https://docs.docker.com/engine/install/) if you haven't already
  1. [Install VSCode](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/linux-macos-setup.html) if you haven't already
  1. Clone this repo with `git clone --recurse-submodules https://github.com/deploythefleet/arduino_ble_provisioning.git`
  1. Connect your ESP32 development board to USB
  1. Open the repo in VSCode
  1. In VSCode open the Command Palette with *Ctrl-Shift-P* or from the **View** menu.
  1. Type "open in container" and select the **Dev Containers: Reopen in Container** option. This will pull the necessary Docker image and build a dev container for you. It can take several minutes.
  1. Open a new shell prompt in VSCode
  1. Run `idf.py flash monitor`
  1. Your device will flash after the project builds and you will be ready to provision your device using the sample Espressif provisioning app for Apple or Android (instructions below).

  > **Note**
  > The Dev Container will fail to launch if your ESP32 Dev board does not enumerate as /dev/ttyUSB0 on your linux system. If your device has a different /dev path simply modify line 34 in the .devcontainer/devcontainer.json file of this repo to match your device's path and try to reopen in the dev container.

## Use the Example App to Provision
Once your device has been flashed you are ready to provision it with the sample BLE provisioning app from Espressif. This is available for both Android and Apple:

  - [Apple Espressif BLE Provisioning App](https://apps.apple.com/in/app/esp-ble-provisioning/id1473590141)
  - [Android Espressif BLE Provisioning App](https://play.google.com/store/apps/details?id=com.espressif.provble)

With the app installed and the firmware running on your device:

  1. Open the provisioning app on your phone
  1. On the first screen click **Provision Device**
  1. The following screen will ask to scan a QR code. Click **I don't have a QR code**
  1. On the *BLE Devices* screen, after a brief scan, the device **PROV_DTF** will appear in the list. Click on it.
  1. Enter the proof of posession PIN. Unless you changed it, the default is "abcd1234"
  1. Click **Next**
  1. Select your WiFi network from the list. It must be a 2.4GHz network with a password
  1. Enter your WiFi password
  1. Click **Provision**

  > **Note**
  > If you changed the service name in main.cpp from "PROV_DTF" to something else your device will show up in the list with the name you changed it to. If you removed the "PROV_" portion you will need to change the PREFIX value in the app so it finds your device.

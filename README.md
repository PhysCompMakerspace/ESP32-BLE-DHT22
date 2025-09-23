# Physical Computing Makerspace Workshop
## Getting Started Microcontrollers: ESP32, BLE, and DHT22

Read temperature and humidity from a DHT22 sensor, then send the data over BLE to a smartphone.
Use "nRF Connect" app on the smartphone to connect via Bluetooth to the ESP32.


## Install Drivers for ESP32:
* Go to: https://www.silabs.com/software-and-tools/usb-to-uart-bridge-vcp-drivers
* Download the “CP210x Windows Driver”
* Unzip and install the driver

## Arduino IDE Installation
* Download and install Arduino IDE: https://www.arduino.cc/en/software/

## Install Libraries: 
* Adafruit Unified Sensor
* Adafruit DHT sensor Library
<img width="356" height="349" alt="image" src="https://github.com/user-attachments/assets/689ec5b4-33d7-4a3b-9f78-5a4c7da2c101" />


## Add ESP32 Boards to Arduino 1
* Add ESP32 boards to the board types in Arduino IDE
* File -> Preferences…
* Add the following URL in the field “Additional boards manager URLs:”
  * https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
<img width="520" height="349" alt="image" src="https://github.com/user-attachments/assets/47b97130-9bba-4175-8971-0d3194825e54" />

 
## Add ESP32 Boards to Arduino 2
* Click on the Boards Manager
* Search for “esp32”
* Install the “esp32 by Espressif Systems”
<img width="287" height="477" alt="image" src="https://github.com/user-attachments/assets/5ab32eba-9c2a-4c66-bd30-1e9bfbef22c4" />


## Sketch Setup:
* Get code from GitHub:
  * https://github.com/PhysCompMakerspace/ESP32-BLE-DHT22 
* Arduino IDE expects that each sketch is in its own directory with the same name.
  * Save “ESP32-BLE-DHT22.ino” to a folder named “ESP32-BLE-DHT22.ino”
* Customize the name of your ESP32 on line 66 (or so):
  * BLEDevice::init("Evil ESP32");
* This helps uniquely identify your BLE server from your neighbors.

## Code Overview:
* Set up BLE on the ESP32
* Identify Bluetooth UUID values
* Establish BLE server callbacks
* Set up the DHT22 sensor
* Loop – read the sensor and notify clients of new data when it’s available

## Circuit:
Use the Dupont connector wires to connect the following:
* "+" pin -> 3V3 pin on ESP32
* OUT pin -> D4 pin on ESP32
* – pin -> GND pin on ESP32
<img width="892" height="381" alt="image" src="https://github.com/user-attachments/assets/e7716a63-df63-4c80-9501-558486184ab6" />

## Upload to ESP32:
* Select your board: search for “ESP32 Dev Module”. You may need to “Select other board and port...”
* Choose your COM port.
* If you’re unsure about the port, unplug the ESP32 to see which COM port disappears.
* When you’re ready, make sure the ESP32 is connected with via the USB cable, then press the upload button!
<img width="273" height="303" alt="image" src="https://github.com/user-attachments/assets/8f8914ec-2a17-4e2c-8d19-02611fb21a79" />

## Smartphone Setup
* Find the “nRF Connect” app in your app store.
* Under the “Scanner” tap, find your device by the name you gave it earlier.
* Select “Connect”.
* Tap on “Environmental Sensing” to view the data that the ESP32 is sending.
<img width="263" height="568" alt="image" src="https://github.com/user-attachments/assets/52024862-56bc-4cfa-9c4e-556dfb76b07b" />

<img width="262" height="566" alt="image" src="https://github.com/user-attachments/assets/ca3cb899-74a1-428d-a240-18b74460bbc6" />


## Next Steps:
* Enjoy your new Bluetooth IOT skill
* Design an app that reads BLE data
* Explore more sensors: force, pressure, color, light, etc.
* Explore Wi-Fi on the ESP32








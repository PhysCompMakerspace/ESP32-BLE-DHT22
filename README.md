Reads temperature and humidity from a DHT22 sensor and sends the data over BLE.

You can use "nRF Connect" app on your phone to connect to the ESP32 and read the values.


Install Drivers for ESP32:
* Go to: https://www.silabs.com/software-and-tools/usb-to-uart-bridge-vcp-drivers
* Download the “CP210x Windows Driver”
* Unzip and install the driver


Arduino IDE Installation
* Download and install Arduino IDE: https://www.arduino.cc/en/software/

Install Libraries: 
* Adafruit Unified Sensor
* Adafruit DHT sensor Library

Add ESP32 Boards to Arduino
* Add ESP32 boards to the board types in Arduino IDE
* File -> Preferences…
* Add the following URL in the field “Additional boards manager URLs:”
  * https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
 



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

Add ESP32 Boards to Arduino 1
* Add ESP32 boards to the board types in Arduino IDE
* File -> Preferences…
* Add the following URL in the field “Additional boards manager URLs:”
  * https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
 
Add ESP32 Boards to Arduino 2
* Click on the Boards Manager
* Search for “esp32”
* Install the “esp32 by Espressif Systems”

Sketch Setup
* Get code from GitHub:
 * https://github.com/PhysCompMakerspace/ESP32-BLE-DHT22 
* Arduino IDE expects that each sketch is in its own directory with the same name.
 * Save “ESP32-BLE-DHT22.ino” to a folder named “ESP32-BLE-DHT22.ino”
* Customize the name of your ESP32 on line 66 (or so):
 * BLEDevice::init("Evil ESP32");
* This helps uniquely identify your BLE server from your neighbors.

Code Overview:
* Set up BLE on the ESP32
* Identify Bluetooth UUID values
* Establish BLE server callbacks
* Set up the DHT22 sensor
* Loop – read the sensor and notify clients of new data when it’s available

Upload to ESP32
* Select your board: search for “ESP32 Dev Module”. You may need to “Select other board and port...”
* Choose your COM port.
* If you’re unsure about the port, unplug the ESP32 to see which COM port disappears.
* When you’re ready, make sure the ESP32 is connected with via the USB cable, then press the upload button!






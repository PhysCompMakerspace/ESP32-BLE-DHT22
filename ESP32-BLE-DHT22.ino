/*
Reads temperature and humidity from a DHT22 sensor and sends the data over BLE.
You can use "nRF Connect" app on your phone to connect to the ESP32 and read the values.
Based on Neil Kolban example for IDF: https://github.com/nkolban/esp32-snippets/blob/master/cpp_utils/tests/BLE%20Tests/SampleServer.cpp
Ported to Arduino ESP32 by Evandro Copercini
updates by chegewara
DHT22 sensor library by Adafruit
*/

#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <Arduino.h>
#include "DHT.h"


// BLE UUIDs =====================================================================
// See the following for generating UUIDs:
// https://www.uuidgenerator.net/

#define SERVICE_UUID (BLEUUID((uint16_t)0x181A))  //The Environmental Sensing Service from  
// https://www.bluetooth.com/wp-content/uploads/Files/Specification/HTML/Assigned_Numbers/out/en/Assigned_Numbers.pdf

// Temperature Characteristic and Descriptor (default UUID)
// Check the default UUIDs here: https://www.bluetooth.com/specifications/assigned-numbers/
BLECharacteristic temperatureCharacteristic(BLEUUID((uint16_t)0x2A6E), BLECharacteristic::PROPERTY_NOTIFY);
BLEDescriptor temperatureDescriptor(BLEUUID((uint16_t)0x2902));

// Humidity Characteristic and Descriptor (default UUID)
BLECharacteristic humidityCharacteristic(BLEUUID((uint16_t)0x2A6F), BLECharacteristic::PROPERTY_NOTIFY);
BLEDescriptor humidityDescriptor(BLEUUID((uint16_t)0x2902));


// DHT22 Sensor ===================================================================
#define DHTPIN 4     // Digital pin connected to the DHT sensor
// Connect the + on the DHT to 3.3V and - to GND.

// Uncomment whatever type you're using!
//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

DHT dht(DHTPIN, DHTTYPE);

// BLE Callbacks ================================================================
bool deviceConnected = false;

//Setup callbacks onConnect and onDisconnect
class MyServerCallbacks: public BLEServerCallbacks {
  void onConnect(BLEServer* pServer) {
    deviceConnected = true;
    Serial.println("Device Connected");
  };
  void onDisconnect(BLEServer* pServer) {
    deviceConnected = false;
    Serial.println("Device Disconnected");
  }
};


void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE!");

  // Initialize the BLE Device with a name
  BLEDevice::init("Evil ESP32");  // Change the name to whatever you want
  
  // Create the BLE Server
  BLEServer *pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  // Create the BLE Service
  BLEService *bmeService = pServer->createService(SERVICE_UUID);

  // Create BLE Characteristics and corresponding Descriptors
  bmeService->addCharacteristic(&temperatureCharacteristic);
  temperatureCharacteristic.addDescriptor(&temperatureDescriptor);
  
  bmeService->addCharacteristic(&humidityCharacteristic);
  humidityCharacteristic.addDescriptor(&humidityDescriptor);

  // Start the service
  bmeService->start();

  // Start advertising
  pServer->getAdvertising()->start();
  Serial.println("Waiting for a client connection to notify...");

  // Initialize the DHT sensor
  dht.begin();
}

void loop() {
  if (deviceConnected) {
    // Reading temperature or humidity takes about 250 milliseconds!
    // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
    float h = dht.readHumidity();
    float t = dht.readTemperature();      // Read temperature as Celsius (the default)
    float f = dht.readTemperature(true);  // Read temperature as Fahrenheit (isFahrenheit = true)

    // Check if any reads failed and exit early (to try again).
    if (isnan(h) || isnan(t) || isnan(f)) {
      Serial.println(F("Failed to read from DHT sensor!"));
      return;
    }

    float hif = dht.computeHeatIndex(f, h);  // Compute heat index in Fahrenheit (the default)
    float hic = dht.computeHeatIndex(t, h, false);  // Compute heat index in Celsius (isFahreheit = false)

    Serial.print(F("Humidity: "));
    Serial.print(h);
    Serial.print(F("%  Temperature: "));
    Serial.print(t);
    Serial.print(F("°C ("));
    Serial.print(f);
    Serial.print(F("°F)  Heat index: "));
    Serial.print(hic);
    Serial.print(F("°C ("));
    Serial.print(hif);
    Serial.println(F("°F)"));

    // Notify the temperature and humidity characteristics
    // Notify temperature reading and notify the client
    uint16_t temperature = (uint16_t)t * 100;
    temperatureCharacteristic.setValue(temperature);
    temperatureCharacteristic.notify();
    
    // Notify humidity reading and notify the client
    uint16_t humidity = (uint16_t)h * 100;
    humidityCharacteristic.setValue(humidity);
    humidityCharacteristic.notify();   

    // Wait a few seconds before the next reading
    delay(4000);
  }
}


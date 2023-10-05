#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <BLE2902.h>
#include <Wire.h>
#include "Adafruit_MCP9808.h"


#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

Adafruit_MCP9808 tempsensor = Adafruit_MCP9808();

#define SERVICE_UUID        "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"


BLEServer* pServer = NULL;
BLECharacteristic* pCharacteristic = NULL;
bool deviceConnected = false;
bool oldDeviceConnected = false;

class MyServerCallbacks: public BLEServerCallbacks {
    void onConnect(BLEServer* pServer) {
      deviceConnected = true;
      BLEDevice::startAdvertising();
    };

    void onDisconnect(BLEServer* pServer) {
      deviceConnected = false;
    }
};



void setup() {
  Serial.begin(115200);
   while (!Serial);
  Serial.println("Starting BLE work!");

  BLEDevice::init("Thermal-Sensor");
  pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  BLEService *pService = pServer->createService(SERVICE_UUID);
  
  BLEUUID serviceUUID = pService->getUUID();
const char* serviceUUIDStr = serviceUUID.toString().c_str();
Serial.print("Service UUID: ");
Serial.println(serviceUUIDStr);

  // Serial.
  pCharacteristic = pService->createCharacteristic(
                                         CHARACTERISTIC_UUID,
                                         BLECharacteristic::PROPERTY_READ   |
                                          BLECharacteristic::PROPERTY_WRITE  |
                                          BLECharacteristic::PROPERTY_NOTIFY |
                                          BLECharacteristic::PROPERTY_INDICATE
                                                          );
   pCharacteristic->setValue("Helll");
   pCharacteristic->addDescriptor(new BLE2902());
  pService->start();

  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
    // pAdvertising->setScanResponse(true);

  pAdvertising->setScanResponse(true);
  pAdvertising->setMinPreferred(0x0);

  BLEDevice::startAdvertising();
  Serial.println("Characteristic defined! Now you can read it on your phone!");

   if (!tempsensor.begin(0x18)) {
        while (1);
  }
  tempsensor.setResolution(3); 
}

void loop() {
  
  tempsensor.wake();
  float c = tempsensor.readTempC();
  String tempData = String(c, 4);
  Serial.println(tempData);
  


  if(deviceConnected)
  {
  //  int x=1;

     pCharacteristic->setValue(tempData.c_str());
    pCharacteristic->notify();
  }
 
  // disconnecting
    if (!deviceConnected && oldDeviceConnected) {
        delay(500); // give the bluetooth stack the chance to get things ready
        pServer->startAdvertising(); // restart advertising
        Serial.println("start advertising");
        oldDeviceConnected = deviceConnected;
    }
    // connecting
    if (deviceConnected && !oldDeviceConnected) {
        oldDeviceConnected = deviceConnected;
    }

 

  delay(2000);
  tempsensor.shutdown_wake(1);
  delay(200);
}

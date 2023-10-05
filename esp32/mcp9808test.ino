// #include <Wire.h>
// #include "Adafruit_MCP9808.h"


// Adafruit_MCP9808 tempsensor = Adafruit_MCP9808();

// void setup() {
//   Serial.begin(9600);
//   while (!Serial); 

//     if (!tempsensor.begin(0x18)) {
//         while (1);
//   }
    

//   tempsensor.setResolution(3); 
//   }

// void loop() {
//     tempsensor.wake();   
//   float c = tempsensor.readTempC();
//   float f = tempsensor.readTempF();

//     Serial.print(c, 4); 
//   Serial.print(",");
//     Serial.println(f, 4); 

  
//   delay(2000);
//     tempsensor.shutdown_wake(1); 
//     delay(200);
// }

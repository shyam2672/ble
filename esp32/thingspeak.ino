// #include <Wire.h>
// #include <Adafruit_MCP9808.h>
// #include <ESP8266WiFi.h>
// #include "ThingSpeak.h"

// Adafruit_MCP9808 tempsensor = Adafruit_MCP9808();

// const char* ssid = "IITRPR";
// const char* password = "V#6qF?pyM!bQ$%NX";

// WiFiClient client;

// unsigned long myChannelNumber = 1;
// const char* myWriteAPIKey = "QIJKGROO81RN6QER";

// unsigned long lastTime = 0;
// unsigned long timerDelay = 30000;

// String readMCP9808Temperature() {
//   float c = tempsensor.readTempC();
//   if (isnan(c)) {
//     Serial.println("Failed to read from MCP9808 sensor!");
//     return "";
//   } else {
//     Serial.println(c);
//     return String(c);
//   }
// }

// void setup() {
//   Serial.begin(9600);

//   if (!tempsensor.begin(0x18)) {
//     Serial.println("Could not find a valid MCP9808 sensor, check wiring!");
//     while (1);
//   }

//   WiFi.begin("IITRPR", "V#6qF?pyM!bQ$%NX"); // Connect to Wi-Fi using your credentials

//   while (WiFi.status() != WL_CONNECTED) {
//     delay(1000);
//     Serial.println("Connecting to WiFi..");
//   }

//   Serial.println("Connection Success!");
//   Serial.println(WiFi.localIP());

//   ThingSpeak.begin(client); // Initialize ThingSpeak client
// }

// void loop() {
//   if ((millis() - lastTime) > timerDelay) {
//     if (WiFi.status() != WL_CONNECTED) {
//       Serial.println("WiFi connection lost. Reconnecting...");
//       // WiFi.begin(ssid, password);
      
//     WiFi.begin("IITRPR", "V#6qF?pyM!bQ$%NX"); 
//       while (WiFi.status() != WL_CONNECTED) {
//         delay(1000);
//         Serial.println("Connecting to WiFi..");
//       }
//       Serial.println("Reconnected to WiFi.");
//     }

//     float temperatureC = tempsensor.readTempC();

//     Serial.print("Temperature (Celsius): ");
//     Serial.println(temperatureC);

//     // Write the temperature data to ThingSpeak field 1
//     int x = ThingSpeak.writeField(myChannelNumber, 1, temperatureC, myWriteAPIKey);

//     if (x == 200) {
//       Serial.println("Channel update successful.");
//     } else {
//       Serial.println("Problem updating channel. HTTP error code " + String(x));
//     }

//     lastTime = millis();
//   }
// }

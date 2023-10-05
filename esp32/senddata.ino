
// #include <Wire.h>
// #include <Adafruit_MCP9808.h>
// #include <ESP8266WiFi.h>
// #include <ESP8266HTTPClient.h>

// // Replace with your network credentials
// const char* ssid = "IITRPR";
// const char* password = "V#6qF?pyM!bQ$%NX";
// const char* server_url = "http://localhost:5000/get_temperature"; // Replace 'get_temperature' with your actual route



// Adafruit_MCP9808 tempsensor = Adafruit_MCP9808();


// void sendData(float temperature) {
//   WiFiClient client;
//   HTTPClient http;

//   // Construct the POST data
//   String post_data = "temperature=" + String(temperature);

//   // Send a POST request to the server
//   if (http.begin(client, server_url)) {
//     http.addHeader("Content-Type", "application/x-www-form-urlencoded");
//     int httpResponseCode = http.POST(post_data);

//     if (httpResponseCode > 0) {
//       Serial.print("HTTP Response code: ");
//       Serial.println(httpResponseCode);
//     } else {
//       Serial.println("HTTP POST request failed");
//     }

//     http.end();
//   } else {
//     Serial.println("Unable to connect to the server");
//   }
// }

// void setup() {
//   Serial.begin(115200);
//   WiFi.begin(ssid, password);
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(1000);
//     Serial.println("Connecting to WiFi...");

//   }
// }

// void loop() {
//   float temp = tempsensor.readTempC();
//   Serial.println(temp);
//   sendData(temp);
//   delay(10000); // Send data every 10 seconds
// }




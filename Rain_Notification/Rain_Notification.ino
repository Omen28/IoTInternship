#include <WiFi.h>   // Include the WiFi library
#include <EspRainmaker.h>   // Include the ESP Rainmaker library

const char* ssid = "SSID";   //  WiFi network SSID
const char* password = "PASSWORD";    // WiFi network password

const char* deviceName = "Device";    //  desired device name
const char* deviceType = "esp32";         //  desired device type
const char* deviceSecret = "DeviceSecret";      // device secret
const char* rainmakerEmail = "RainmakerEmail";    //  ESP Rainmaker account email
const char* rainmakerPassword = "RainmakerPassword";    //  ESP Rainmaker account password


EspRainmaker rainmaker;   // Create an instance of the EspRainmaker class

void setup() 
{
  Serial.begin(9600);     // Initialize serial monitor
  
  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
// Initialize the ESP Rainmaker
  rainmaker.begin(deviceName, deviceType, deviceSecret, rainmakerEmail, rainmakerPassword);
}

void loop() 
{
  rainmaker.handle();   // Handle ESP Rainmaker tasks
  delay(1000);
}

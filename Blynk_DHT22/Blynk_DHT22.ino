#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <BlynkSimpleEsp32.h>
#include <WiFi.h>
#include <WiFiClient.h>


#define DHTpin 4           // DHT22 sensor connected to GPIO pin 3   
#define DHTtype DHT22      // DHT type

char auth[] = "70827362";           //your authority token
char ssid[] = "Omen";               //your wifi ssid
char pass[] = "12345678";           //your wifi password

DHT dht(DHTpin, DHTtype);                   

void setup() 
{
  Serial.begin(9600);                  //baud rate for serial monitor
  Blynk.begin(auth, ssid, pass);       //blynk connection

  dht.begin();                         //sensor begin
}

void loop() 
{
  Blynk.run();

  
  float humidity = dht.readHumidity();               // Read humidity
  float temp = dht.readTemperature();                // Read temperature in Celsius

  if (isnan(temp) || isnan(humidity))                //If either the temperature or humidity value is NaN(not a valid number)
  {
    Serial.println("Failed to read from DHT22 sensor");     //prints to the Serial Monitor
    return;
  }

  Blynk.virtualWrite(V1, temp);              // Send temperature value to T1
  Blynk.virtualWrite(V2, humidity);          // Send humidity value to H1


  delay(1000);      // Update every 1 seconds
}

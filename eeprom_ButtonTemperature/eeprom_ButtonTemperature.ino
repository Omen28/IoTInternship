#include <EEPROM.h>

const int buttonPin = 2;    
const int ledPin = 13;      
const int eepromAddress = 0; 

int desiredTemp = 25;  // Initial desired temperature
int buttonState = HIGH;       // Current state of the button
int PreButtonState = HIGH;   // Previous state of the button

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);

  // Read the desired temperature from EEPROM
  desiredTemp = EEPROM.read(eepromAddress);

  // Set the LED state based on the desired temperature
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
}

void loop() {
  
  buttonState = digitalRead(buttonPin);     // Read the state of the button

  
  if (buttonState == LOW && PreButtonState == HIGH) // Check if the button is pressed and released
  {
    
    desiredTemp++;   // Increment the desired temperature by 1

    
    EEPROM.write(eepromAddress, desiredTemp);    // Store the new desired temperature in EEPROM

    // Blink the LED to indicate the temperature change
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
  }

  
  PreButtonState = buttonState;    // Update the button state
}

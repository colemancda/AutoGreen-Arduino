// 
// AutoGreen Arduino 
//
// Arduino-based Automated Modular Greenhouse
// Developed with [embedXcode](http://embedXcode.weebly.com)
// 
// Author	 	Alsey Coleman Miller
// 				ColemanCDA
//
// Date			9/27/14 2:03 PM
// Version		<#version#>
// 
// Copyright	© Alsey Coleman Miller, 2014
// License		<#license#>
//
// See			ReadMe.txt for references
//

// Core library for code-sense - IDE-based
#if defined(WIRING) // Wiring specific
#include "Wiring.h"
#elif defined(MAPLE_IDE) // Maple specific
#include "WProgram.h"
#elif defined(MPIDE) // chipKIT specific
#include "WProgram.h"
#elif defined(DIGISPARK) // Digispark specific
#include "Arduino.h"
#elif defined(ENERGIA) // LaunchPad specific
#include "Energia.h"
#elif defined(MICRODUINO) // Microduino specific
#include "Arduino.h"
#elif defined(TEENSYDUINO) // Teensy specific
#include "Arduino.h"
#elif defined(ARDUINO) // Arduino 1.0 and 1.5 specific
#include "Arduino.h"
#else // error
#error Platform not defined
#endif // end IDE

// Include application, user and local libraries
#include "Actuator.h"

// 3rd party libraries
#include "dht.h"
#include "PID_v1.h"


// Define variables and constants
//
// Brief	Name of the LED
// Details	Each board has a LED but connected to a different pin
//

#define InvalidValue -1

long previousMillis = 0; // stores milis
long interval = 5000; // interval the sensors will be checked (and light will blink)

Actuator led;
Actuator fanRelay;
Actuator valveRelay;

dht dht;
const int dhtPin = 9;

int temperature = InvalidValue;
int humidity = InvalidValue;

//
// Brief	Setup
// Details	Define the pin the LED is connected to
//
// Add setup code
void setup() {
    
    // Serial
    Serial.begin(9600);
    Serial.println("Initializing Automated Modular Greenhouse...");
    
    // Setup Actuators
    
    led.setPin(13);
    fanRelay.setPin(8);
    valveRelay.setPin(11);
    
    // setup sensors
    
    dht.read(9);
    
    // finish initialzation
    
    Serial.println("Finished Initialization\n");
}

//
// Brief	Loop
// Details	Blink the LED
//
// Add loop code
void loop() {
    
    // get sensor data at intervals...
    
    unsigned long currentMillis = millis();
    
    if (currentMillis - previousMillis > interval) {
        
        // save the last time you blinked the LED
        previousMillis = currentMillis;
        
        // activate actuators
        
        led.setState(!led.state());
        fanRelay.setState(!fanRelay.state());
        
        Serial.println(fanRelay.state());
        
        // read from sensors...
        
        // read from soil humidity
        
        Serial.println("Reading info from Soil Humidity Sensor...");
        
        // read from DHT
        
        Serial.println("Reading info from DHT...");
        
        int dhtCheckSum = dht.read11(dhtPin);
        
        switch (dhtCheckSum)
        {
            case DHTLIB_OK:
                Serial.println("Checksum ok");
                
                // read stats
                
                Serial.print("DHT Humidity: ");
                Serial.print(dht.humidity);
                humidity = dht.humidity;
                Serial.println("");
                
                Serial.print("DHT Temperature: ");
                Serial.print(dht.temperature);
                temperature = dht.temperature;
                Serial.println("");
                
                break;
            case DHTLIB_ERROR_CHECKSUM:
                Serial.println("Checksum error");
                break;
            case DHTLIB_ERROR_TIMEOUT:
                Serial.println("Time out error");
                break;
            default:
                Serial.println("Unknown error");
                break;
        }
        
        Serial.println("");
    }
    
    // turn LED off
    
    if (led.state() == true) {
        
        led.setState(false);
    }
    
    // read from Bluetooth...
    
    
    // control environment based on sensors and settings...
}

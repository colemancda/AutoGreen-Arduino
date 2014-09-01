// 
// AutoGreen Arduino 
//
// Arduino-based Automated Modular Greenhouse
// Developed with [embedXcode](http://embedXcode.weebly.com)
// 
// Author	 	Alsey Coleman Miller
// 				ColemanCDA
//
// Date			8/30/14 9:16 AM
// Version		1.0
// 
// Copyright	© Alsey Coleman Miller, 2014
// License		All rights reserved
//
// See			ReadMe.txt for references
//

// Core library for code-sense
#if defined(WIRING) // Wiring specific
#include "Wiring.h"
#elif defined(MAPLE_IDE) // Maple specific
#include "WProgram.h"   
#elif defined(MICRODUINO) // Microduino specific
#include "Arduino.h"
#elif defined(MPIDE) // chipKIT specific
#include "WProgram.h"
#elif defined(DIGISPARK) // Digispark specific
#include "Arduino.h"
#elif defined(ENERGIA) // LaunchPad MSP430, Stellaris and Tiva, Experimeter Board FR5739 specific
#include "Energia.h"
#elif defined(TEENSYDUINO) // Teensy specific
#include "Arduino.h"
#elif defined(ARDUINO) // Arduino 1.0 and 1.5 specific
#include "Arduino.h"
#else // error
#error Platform not defined
#endif

// Include application, user and local libraries
#include "Actuator.h"
#include "dht.h"

// Define variables and constants
//
// Brief	Name of the LED
// Details	Each board has a LED but connected to a different pin
//

long previousMillis = 0; // stores milis
long interval = 5000; // interval the sensors will be checked (and light will blink)

Actuator led;
Actuator fanRelay;
Actuator valveRelay;

dht dht;

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
    fanRelay.setPin(12);
    valveRelay.setPin(11);
    
    // finish initialzation
    
    Serial.println("Finished Initialization");
}

//
// Brief	Loop
// Details	Blink the LED
//
// Add loop code 
void loop() {
    
    // read from Bluetooth...
    
    
    
    // get sensor data at intervals...
    
    unsigned long currentMillis = millis();
    
    if (currentMillis - previousMillis > interval) {
        
        // save the last time you blinked the LED
        previousMillis = currentMillis;
        
        // activate actuators
        
        led.setState(!led.state());
        fanRelay.setState(!fanRelay.state());
        
        Serial.println(led.state());
        
    }
}



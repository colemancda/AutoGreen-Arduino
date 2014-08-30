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


// Define variables and constants
//
// Brief	Name of the LED
// Details	Each board has a LED but connected to a different pin
//
int myLED;

int fanRelayPin = 12;

int valveRelayPin = 11;

//
// Brief	Setup
// Details	Define the pin the LED is connected to
//
// Add setup code 
void setup() {
  // myLED pin number
#if defined(ENERGIA) // All LaunchPads supported by Energia
    myLED = RED_LED;
#elif defined(DIGISPARK) // Digispark specific
    myLED = 1; // assuming model A
#elif defined(MAPLE_IDE) // Maple specific
    myLED = BOARD_LED_PIN;
#elif defined(WIRING) // Wiring specific
    myLED = 15;
#else // Arduino, chipKIT, Teensy specific
    myLED = 13;
#endif

    pinMode(myLED, OUTPUT);
    
    pinMode(fanRelayPin, OUTPUT);
    
    pinMode(fanRelayPin, OUTPUT);
}

//
// Brief	Loop
// Details	Blink the LED
//
// Add loop code 
void loop() {
    digitalWrite(myLED, HIGH);
    digitalWrite(fanRelayPin, HIGH);
    delay(10000);
    digitalWrite(myLED, LOW);
    digitalWrite(fanRelayPin, LOW);
    delay(500);    
}



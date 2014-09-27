//
// File			Actuator.h
// Class library header
//
// Details		<#details#>
//
// Project	 	AutoGreen Arduino
// Developed with [embedXcode](http://embedXcode.weebly.com)
//
// Author		Alsey Coleman Miller
// 				ColemanCDA
//
// Date			8/30/14 6:59 PM
// Version		<#version#>
//
// Copyright	© Alsey Coleman Miller, 2014
// License	    <#license#>
//
// See			ReadMe.txt for references
//


// Core library - IDE-based
#if defined(WIRING) // Wiring specific
#include "Wiring.h"
#elif defined(MAPLE_IDE) // Maple specific
#include "WProgram.h"
#elif defined(MPIDE) // chipKIT specific
#include "WProgram.h"
#elif defined(DIGISPARK) // Digispark specific
#include "Arduino.h"
#elif defined(ENERGIA) // LaunchPad MSP430 G2 and F5529, Stellaris and Tiva, Experimeter Board FR5739 specific
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

#ifndef Actuator_h

#define Actuator_h


class Actuator {
    
    int _pin;
    bool _state;
  
public:
    
  Actuator();
  
    void setPin(int);
    int pin();
    
    void setState(bool);
    bool state();

};

#endif


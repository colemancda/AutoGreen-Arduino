//
// LocalLibrary.cpp 
// Library C++ code
// ----------------------------------
// Developed with embedXcode+ 
// http://embedXcode.weebly.com
//
// Project 		Autogreen Arduino
//
// Created by 	Alsey Coleman Miller, 10/4/14 10:05 PM
// 				ColemanCDA
//
// Copyright 	© Alsey Coleman Miller, 2014
// License		All rights reserved
//
// See 			LocalLibrary.cpp.h and ReadMe.txt for references
//


#include "LocalLibrary.h"

void blink(uint8_t pin, uint8_t times, uint16_t ms) {
#if defined(LIGHTBLUE_CORE)
    for (uint8_t i=0; i<times; i++) {
        Bean.setLed(0,0,255);
        Bean.sleep(ms >> 1);
        Bean.setLed(0,0,0);
        Bean.sleep(ms >> 1);
    }
    
#else
    for (uint8_t i=0; i<times; i++) {
        digitalWrite(pin, HIGH);
        delay(ms >> 1);
        digitalWrite(pin, LOW);
        delay(ms >> 1);
    }
#endif
}

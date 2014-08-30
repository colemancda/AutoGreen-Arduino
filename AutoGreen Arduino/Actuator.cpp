//
// Actuator.cpp 
// Class library C++ code
// ----------------------------------
// Developed with embedXcode 
// http://embedXcode.weebly.com
//
// Project 		AutoGreen Arduino
//
// Created by 	Alsey Coleman Miller, 8/30/14 6:59 PM
// 				ColemanCDA
//
// Copyright 	© Alsey Coleman Miller, 2014
// License     <#license#>
//
// See 			Actuator.h and ReadMe.txt for references
//


// Library header
#include "Actuator.h"

// Code
Actuator::Actuator() {
    
}

int Actuator::pin(){
    return _pin;
}

void Actuator::setPin(int pin){
    
    // set value
    _pin = pin;
    
    // configure board
    pinMode(_pin, OUTPUT);
}

bool Actuator::state(){
    
    return _state;
}

void Actuator::setState(bool state){
    
    // set value
    _state = state;
    
    // convert boolean state
    int hexState = LOW;
    
    if (state) {
        hexState = HIGH;
    }
    
    // set digital signal
    digitalWrite(_pin, hexState);
}




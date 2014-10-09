///
/// @file		LocalLibrary.h
/// @brief		Library header
///
/// @details	<#details#>
/// @n	
/// @n @b		Project Autogreen Arduino
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
/// 
/// @author		Alsey Coleman Miller
/// @author		ColemanCDA
///
/// @date		10/4/14 10:05 PM
/// @version	<#version#>
/// 
/// @copyright	(c) Alsey Coleman Miller, 2014
/// @copyright	All rights reserved
///
/// @see		ReadMe.txt for references
///


// Core library - IDE-based
#if defined(WIRING) // Wiring specific
#include "Wiring.h"
#elif defined(MAPLE_IDE) // Maple specific
#include "WProgram.h"
#elif defined(ROBOTIS)
#include "libpandora_types.h"
#include "pandora.h"
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
#elif defined(RFDUINO) // RFduino specific
#include "Arduino.h"
#elif defined(ARDUINO) // Arduino 1.0 and 1.5 specific
#include "Arduino.h"
#else // error
#error Platform not defined
#endif // end IDE

#ifndef Autogreen Arduino_LocalLibrary_h
#define Autogreen Arduino_LocalLibrary_h

///
/// @brief	Blink a LED
/// @details	LED attached to pin is light on then light off
/// @n		Total cycle duration = ms
/// @param	pin pin to which the LED is attached
/// @param	times number of times
/// @param	ms cycle duration in ms
///
void blink(uint8_t pin, uint8_t times, uint16_t ms);

#endif

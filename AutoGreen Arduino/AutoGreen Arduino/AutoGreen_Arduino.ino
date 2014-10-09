/// 
/// @mainpage	Autogreen Arduino 
///
/// @details	Arduino-based Automated Modular Greenhouse
/// @n 		
/// @n 
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
/// 
/// @author		Alsey Coleman Miller
/// @author		ColemanCDA
/// @date		10/4/14 10:05 PM
/// @version	<#version#>
/// 
/// @copyright	(c) Alsey Coleman Miller, 2014
/// @copyright	All rights reserved
///
/// @see		ReadMe.txt for references
///


///
/// @file		Autogreen_Arduino.ino
/// @brief		Main sketch
///
/// @details	<#details#>
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
/// 
/// @author		Alsey Coleman Miller
/// @author		ColemanCDA
/// @date		10/4/14 10:05 PM
/// @version	<#version#>
/// 
/// @copyright	(c) Alsey Coleman Miller, 2014
/// @copyright	All rights reserved
///
/// @see		ReadMe.txt for references
/// @n
///


// Core library for code-sense - IDE-based
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

// Include application, user and local libraries
#include "LocalLibrary.h"
#include "Actuator.h"

// 3rd party libraries
#include "dht.h"


// Prototypes


// Define variables and constants
///
/// @brief	Name of the LED
/// @details	Each board has a LED but connected to a different pin
///

#define InvalidValue -1

long previousMillis = 0; // stores milis
long interval = 5000; // interval the sensors will be checked (and light will blink)

Actuator led;
Actuator fanRelay;
Actuator valveRelay;

dht dht;
const int dhtPin = 2;

int temperature = InvalidValue;
int humidity = InvalidValue;

int targetTemperature = 23;

///
/// @brief	Setup
/// @details	Define the pin the LED is connected to
///
// Add setup code
void setup() 
{
    // Serial
    Serial.begin(9600);
    Serial.println("Initializing Automated Modular Greenhouse...");
    
    // Setup Actuators
    led.setPin(13);
    fanRelay.setPin(11);
    valveRelay.setPin(10);
    
    // finish initialzation
    Serial.println("Finished Initialization\n");
}

///
/// @brief	Loop
/// @details	Call blink
///
// Add loop code
void loop() 
{
    // get sensor data at intervals...
    
    unsigned long currentMillis = millis();
    
    if (currentMillis - previousMillis > interval) {
        
        // save the last time you blinked the LED
        previousMillis = currentMillis;
        
        // blink led
        led.setState(true);
        
        // read from sensors...
        
        /*
         // read from soil humidity
         
         Serial.println("Reading info from Soil Humidity Sensor...");
         */
        
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
        
        // Control fan...
        Serial.println("Fan Stats...");
        Serial.print("Fan power state: ");
        Serial.print(fanRelay.state());
        Serial.println("");
        
        // turn on / off fan
        if (temperature != InvalidValue && targetTemperature != temperature) {
            
            if (targetTemperature < temperature && fanRelay.state() != true) {
                Serial.println("Turning fan on to cool");
                fanRelay.setState(true);
            }
            if (targetTemperature > temperature && fanRelay.state() != false) {
                Serial.println("Turning fan off to warm");
                fanRelay.setState(false);;
            }
        }
        Serial.println("");
        
        // Saved variables
        Serial.println("Saved variables...");
        Serial.print("Target temperature: ");
        Serial.print((double)(targetTemperature));
        Serial.println("");
        
        
        Serial.println("");
        Serial.println("");
    }
    
    // turn LED off if on
    if (led.state() == true) {
        led.setState(false);
    }
    
    // read from Bluetooth...
    
    
    // control environment based on sensors and settings...
}

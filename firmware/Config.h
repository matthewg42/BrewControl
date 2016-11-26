#pragma once

#include <stdint.h>
#include <Arduino.h>

const uint8_t   RELAY_PIN               = A3;
const uint8_t   TEMP_SENSOR_PIN         = A2;

// Pins for DIP switch
const uint8_t   DIP_PIN_0               = 2;
const uint8_t   DIP_PIN_1               = 3;
const uint8_t   DIP_PIN_2               = 4;
const uint8_t   DIP_PIN_3               = 5;

// DIP switches are index into this array
const float     TEMP_TARGET[] = {  7.500,  8.875, 10.250, 11.625, 13.000, 14.375, 15.750, 17.125,
                                  18.500, 19.875, 21.250, 22.625, 24.000, 25.375, 29.125, 29.500  };

// How much variation we allow without switching, i.e.
// low threshold  = TEMP_TARGET[n] - (TEMP_RANGE/2)
// high threshold = TEMP_TARGET[n] + (TEMP_RANGE/2)
const float     TEMP_RANGE              = 0.1;

// How long to wait between sampling temperature
const unsigned long TEMP_INTERVAL_MS    = 2000;



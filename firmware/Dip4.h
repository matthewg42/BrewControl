#pragma once

#include "DebouncedButton.h"

class Dip4 {
public:
    Dip4(uint8_t pin0, uint8_t pin1, uint8_t pin2, uint8_t pin3, bool pullup=true);
    void begin();
    void update();

    // returns DIP setting (integer between 0 and 15)
    uint8_t get();

private:
    DebouncedButton _pin0;
    DebouncedButton _pin1;
    DebouncedButton _pin2;
    DebouncedButton _pin3;

};


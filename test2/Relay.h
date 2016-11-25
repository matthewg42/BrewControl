#pragma once

#include <stdint.h>

class Relay {
public:
    Relay(uint8_t pin, bool inverted=false);
    void begin();
    void set(bool on);
    bool get();

private:
    uint8_t _pin;
    bool _inverted;
    bool _state;
};


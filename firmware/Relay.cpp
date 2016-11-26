#include <Arduino.h>
#include "Debug.h"
#include "Relay.h"

Relay::Relay(uint8_t pin, bool inverted) :
    _pin(pin),
    _inverted(inverted),
    _state(false)
{
}

void Relay::begin()
{
    pinMode(_pin, OUTPUT);
    set(_state);
}

void Relay::set(bool on)
{
    DB(F("Relay::set("));
    DB(on);
    DBLN(F(")"));
    _state = on;
    digitalWrite(_pin, _inverted ? !_state : _state);
}

bool Relay::get()
{
    return _state;
}



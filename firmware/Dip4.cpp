#include "Dip4.h"
#include "Debug.h"

Dip4::Dip4(uint8_t pin0, uint8_t pin1, uint8_t pin2, uint8_t pin3, bool pullup) :
    _pin0(pin0, pullup),
    _pin1(pin1, pullup),
    _pin2(pin2, pullup),
    _pin3(pin3, pullup)
{
}

void Dip4::begin()
{
    _pin0.begin();
    _pin1.begin();
    _pin2.begin();
    _pin3.begin();
}

void Dip4::update()
{
    _pin0.update();
    _pin1.update();
    _pin2.update();
    _pin3.update();
}

uint8_t Dip4::get()
{
    return (_pin0.isPressed(false)*8 + _pin1.isPressed(false)*4 + _pin2.isPressed(false)*2 + _pin3.isPressed(false));
}


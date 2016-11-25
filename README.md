# Brewing Tempoerature Controller

## Motivation

I wanna make a bunch of wine. It's winter. The house is cold. The little yeasts will need to be provided with some therms so they can work their magic. To keep them happy, I want to control the nmber of therms they get so they stay the happiest they can be.

## Concept

1.  Arduino (Pro Mini 5V) reads temerature from probe (OneWire-based DS18B20), which is partly submerged in the pre-wine
2.  Turns on and off heat pads using an opto-isolated relay board. Power for heat pads comes from the mains
3.  Simple thermostat functionlity - low and high set points will be set at compile time



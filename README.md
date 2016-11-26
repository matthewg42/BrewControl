# Brewing Tempoerature Controller

## Motivation

I wanna make a bunch of wine. It's winter. The house is cold. The little yeasts will need to be provided with some therms so they can work their magic. To keep them happy, I want to control the nmber of therms they get so they stay the happiest they can be.

## Concept

1.  Arduino (Pro Mini 5V) reads temerature from probe (OneWire-based DS18B20), which is partly submerged in the pre-wine
2.  Turns on and off heat pads using an opto-isolated relay board. Power for heat pads comes from the mains
3.  Simple thermostat functionlity - based on a target temperature (set with DIP switches), and a range (set at compile time)

## DIP Switch settings

    P0  P1  P2  P3      Target temp (C)
    0   0   0   0       7.500
    0   0   0   1       8.875
    0   0   1   0       10.250
    0   0   1   1       11.625
    0   1   0   0       13.000
    0   1   0   1       14.375
    0   1   1   0       15.750
    0   1   1   1       17.125
    1   0   0   0       18.500
    1   0   0   1       19.875
    1   0   1   0       21.250
    1   0   1   1       22.625
    1   1   0   0       24.000
    1   1   0   1       25.375
    1   1   1   0       29.125
    1   1   1   1       29.500



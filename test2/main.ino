#include <OneWire.h>
#include <DallasTemperature.h>

#include "Config.h"
#include "Debug.h"
#include "Relay.h"

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(TEMP_SENSOR_PIN);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

Relay heaterRelay(RELAY_PIN, true);

float getTemperature()
{
    sensors.requestTemperatures(); // Send the command to get temperatures
    return(sensors.getTempCByIndex(0)); 
}

void setup(void)
{
    Serial.begin(115200);
    // IC Default 9 bit. If you have troubles consider upping it 12. Ups the 
    // delay giving the IC more time to process the temperature measurement 
    sensors.begin();
    heaterRelay.begin();
    delay(300);
}

void loop(void)
{ 
    float t = getTemperature();
    DB(F("temp="));
    DBLN(t);
    if (t < TEMP_LOW && ! heaterRelay.get()) {
        heaterRelay.set(true);
    } else if (t > TEMP_HIGH && heaterRelay.get()) {
        heaterRelay.set(false);
    }
}



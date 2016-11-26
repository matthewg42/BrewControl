#include <OneWire.h>
#include <DallasTemperature.h>

#include "Config.h"
#include "Debug.h"
#include "Relay.h"
#include "Dip4.h"

// Objects used for talking to peripherals
OneWire oneWire(TEMP_SENSOR_PIN);
DallasTemperature sensors(&oneWire);
Relay heaterRelay(RELAY_PIN, true);
Dip4 dipSwitch(DIP_PIN_0, DIP_PIN_1, DIP_PIN_2, DIP_PIN_3, true);

// Global variables for holding state
unsigned long lastTempRead = 0;
uint8_t tempSetting = 0;
float loLimit = TEMP_TARGET[tempSetting] - (TEMP_RANGE/2);
float hiLimit = TEMP_TARGET[tempSetting] + (TEMP_RANGE/2);

// Utility functions
float getTemperatureInC()
{
    // note: takes about 750 ms
    sensors.requestTemperatures(); // Send the command to get temperatures
    return(sensors.getTempCByIndex(0)); 
}

void setLimits(uint8_t idx) 
{
    DB(F("setLimits() from "));
    DB(tempSetting);
    DB(F(" [target="));
    DB(TEMP_TARGET[tempSetting]);
    DB(F(" lo="));
    DB(loLimit);
    DB(F(" hi="));
    DB(hiLimit);
    DB(F("] to "));
    tempSetting = idx;
    loLimit = TEMP_TARGET[tempSetting] - (TEMP_RANGE/2);
    hiLimit = TEMP_TARGET[tempSetting] + (TEMP_RANGE/2);
    DB(tempSetting);
    DB(F(" [target="));
    DB(TEMP_TARGET[tempSetting]);
    DB(F(" lo="));
    DB(loLimit);
    DB(F(" hi="));
    DB(hiLimit);
    DBLN(F("]"));
}

void setup(void)
{
    Serial.begin(115200);
    // IC Default 9 bit. If you have troubles consider upping it 12. Ups the 
    // delay giving the IC more time to process the temperature measurement 
    sensors.begin();
    heaterRelay.begin();
    dipSwitch.begin();
}

void loop(void)
{ 
    // Handle DIP switch reading and changes
    dipSwitch.update();
    uint8_t dip = dipSwitch.get();
    if (dip != tempSetting) {
        setLimits(dip);
    }

    if (millis() > lastTempRead + TEMP_INTERVAL_MS) {
        lastTempRead = millis();
        unsigned long b4 = millis();
        float t = getTemperatureInC();
        unsigned long took = millis() - b4;
        DB(F("Read took "));
        DB(took);
        DB(F("ms; target="));
        DB(TEMP_TARGET[tempSetting]);
        DB(F("C; temp="));
        DB(t);
        DBLN('C');
        if (t < loLimit && !heaterRelay.get()) {
            heaterRelay.set(true);
        } else if ( t > hiLimit && heaterRelay.get()) {
            heaterRelay.set(false);
        }
    }
}



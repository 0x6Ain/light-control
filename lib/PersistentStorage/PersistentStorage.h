#ifndef PERSISTENT_STORAGE_H
#define PERSISTENT_STORAGE_H

#include <Arduino.h>
#include <EEPROM.h>
#include <config.h>
#include <Utils.h>

class PersistentStorage
{
public:
    static void begin();
    // WIFI
    static String getSSID();
    static String getPassword();
    static void setSSID(const String &value);
    static void setPassword(const String &value);

    // Time
    static TimeRange getTimeRange();
    static void setTimeRange(const TimeRange &range);

private:
    static void writeString(int addr, const String &value, int maxLen);
    static String readString(int addr, int maxLen);
    static void writeByte(int addr, uint8_t value);
    static uint8_t readByte(int addr);
};

#endif

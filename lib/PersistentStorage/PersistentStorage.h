#ifndef PERSISTENT_STORAGE_H
#define PERSISTENT_STORAGE_H

#include <Arduino.h>
#include <EEPROM.h>

#define EEPROM_SIZE 256

#define ADDR_SSID 0
#define ADDR_PASS 64
#define ADDR_START_HOUR 128
#define ADDR_START_MIN 129
#define ADDR_END_HOUR 130
#define ADDR_END_MIN 131

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
    static uint8_t getStartHour();
    static uint8_t getStartMinute();
    static uint8_t getEndHour();
    static uint8_t getEndMinute();
    static void setStartHour(uint8_t hour);
    static void setStartMinute(uint8_t minute);
    static void setEndHour(uint8_t hour);
    static void setEndMinute(uint8_t minute);

private:
    static void writeString(int addr, const String &value, int maxLen);
    static String readString(int addr, int maxLen);
    static void writeByte(int addr, uint8_t value);
    static uint8_t readByte(int addr);
};

#endif

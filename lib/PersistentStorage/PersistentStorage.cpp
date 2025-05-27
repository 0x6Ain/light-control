#include "PersistentStorage.h"

void PersistentStorage::begin()
{
    EEPROM.begin(EEPROM_SIZE);
}

String PersistentStorage::getSSID()
{
    return readString(ADDR_SSID, 64);
}

String PersistentStorage::getPassword()
{
    return readString(ADDR_PASS, 64);
}

void PersistentStorage::setSSID(const String &value)
{
    writeString(ADDR_SSID, value, 64);
}

void PersistentStorage::setPassword(const String &value)
{
    writeString(ADDR_PASS, value, 64);
}

uint8_t PersistentStorage::getStartHour()
{
    return readByte(ADDR_START_HOUR);
}

uint8_t PersistentStorage::getStartMinute()
{
    return readByte(ADDR_START_MIN);
}

uint8_t PersistentStorage::getEndHour()
{
    return readByte(ADDR_END_HOUR);
}

uint8_t PersistentStorage::getEndMinute()
{
    return readByte(ADDR_END_MIN);
}

void PersistentStorage::setStartHour(uint8_t hour)
{
    writeByte(ADDR_START_HOUR, hour);
}

void PersistentStorage::setStartMinute(uint8_t minute)
{
    writeByte(ADDR_START_MIN, minute);
}

void PersistentStorage::setEndHour(uint8_t hour)
{
    writeByte(ADDR_END_HOUR, hour);
}

void PersistentStorage::setEndMinute(uint8_t minute)
{
    writeByte(ADDR_END_MIN, minute);
}

void PersistentStorage::writeString(int addr, const String &value, int maxLen)
{
    int len = value.length();
    if (len > maxLen - 1)
        len = maxLen - 1;
    for (int i = 0; i < len; i++)
    {
        EEPROM.write(addr + i, value[i]);
    }
    EEPROM.write(addr + len, 0);
    EEPROM.commit();
}

String PersistentStorage::readString(int addr, int maxLen)
{
    char buf[maxLen + 1];
    for (int i = 0; i < maxLen; i++)
    {
        buf[i] = EEPROM.read(addr + i);
        if (buf[i] == 0)
        {
            buf[i] = '\0';
            break;
        }
    }
    buf[maxLen] = '\0';
    return String(buf);
}

void PersistentStorage::writeByte(int addr, uint8_t value)
{
    EEPROM.write(addr, value);
    EEPROM.commit();
}

uint8_t PersistentStorage::readByte(int addr)
{
    return EEPROM.read(addr);
}

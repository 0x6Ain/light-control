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

TimeRange PersistentStorage::getTimeRange()
{
    TimeRange range;
    range.startHour = readByte(ADDR_START_HOUR);
    range.startMinute = readByte(ADDR_START_MIN);
    range.endHour = readByte(ADDR_END_HOUR);
    range.endMinute = readByte(ADDR_END_MIN);

    // 값이 EEPROM에 없거나 이상하면 기본값으로 설정 가능
    if (!isValidTimeRange(range))
    {
        range = getDefaultTimeRange();
    }
    return range;
}

void PersistentStorage::setTimeRange(const TimeRange &range)
{
    writeByte(ADDR_START_HOUR, range.startHour);
    writeByte(ADDR_START_MIN, range.startMinute);
    writeByte(ADDR_END_HOUR, range.endHour);
    writeByte(ADDR_END_MIN, range.endMinute);
    EEPROM.commit();
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

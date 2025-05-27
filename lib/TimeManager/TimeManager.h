#ifndef TIME_MANAGER_H
#define TIME_MANAGER_H

#include <NTPClient.h>
#include <WiFiUdp.h>

class TimeManager
{
public:
    TimeManager();
    void begin(const char *ntpServer = "pool.ntp.org", long gmtOffsetSec = 0, int updateIntervalMs = 60000);
    void update();
    String getCurrentTime();
    bool isWithinTimeRange(int startHour, int startMinute, int endHour, int endMinute);

private:
    WiFiUDP _ntpUDP;
    NTPClient _ntpClient;
};

#endif
#ifndef TIME_MANAGER_H
#define TIME_MANAGER_H

#include <NTPClient.h>
#include <WiFiUdp.h>
#include <Utils.h>

class TimeManager
{
public:
    TimeManager();
    void begin(const char *ntpServer = "pool.ntp.org", long gmtOffsetSec = 0, int updateIntervalMs = 4 * 60 * 60 * 1000);
    void update();
    Time getCurrentTime();
    bool isWithinTimeRange(const TimeRange &range);

private:
    WiFiUDP _ntpUDP;
    NTPClient _ntpClient;
};

#endif
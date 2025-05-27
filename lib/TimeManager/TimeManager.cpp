#include "TimeManager.h"

TimeManager::TimeManager()
    : _ntpClient(_ntpUDP) {}

void TimeManager::begin(const char *ntpServer, long gmtOffsetSec, int updateIntervalMs)
{
    _ntpClient.setPoolServerName(ntpServer);
    _ntpClient.setTimeOffset(gmtOffsetSec);
    _ntpClient.begin();
    _ntpClient.setUpdateInterval(updateIntervalMs);
    _ntpClient.update();
}

void TimeManager::update()
{
    _ntpClient.update();
}

String TimeManager::getCurrentTime()
{
    int h = _ntpClient.getHours();
    int m = _ntpClient.getMinutes();
    int s = _ntpClient.getSeconds();
    char buffer[9];
    snprintf(buffer, sizeof(buffer), "%02d:%02d:%02d", h, m, s);
    return String(buffer);
}

bool TimeManager::isWithinTimeRange(int startHour, int startMinute, int endHour, int endMinute)
{
    int currentTotal = _ntpClient.getHours() * 60 + _ntpClient.getMinutes();
    int startTotal = startHour * 60 + startMinute;
    int endTotal = endHour * 60 + endMinute;

    if (startTotal <= endTotal)
    {
        return (currentTotal >= startTotal && currentTotal < endTotal);
    }
    else
    {
        // 자정 넘김
        return (currentTotal >= startTotal || currentTotal < endTotal);
    }
}

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

Time TimeManager::getCurrentTime()
{
    return {
        _ntpClient.getHours(),
        _ntpClient.getMinutes(),
        _ntpClient.getSeconds()};
}

bool TimeManager::isWithinTimeRange(const TimeRange &range)
{
    int currentTotal = _ntpClient.getHours() * 60 + _ntpClient.getMinutes();
    int startTotal = range.startHour * 60 + range.startMinute;
    int endTotal = range.endHour * 60 + range.endMinute;

    if (startTotal <= endTotal)
    {
        // 같은 날 안에 있는 경우
        return (currentTotal >= startTotal && currentTotal < endTotal);
    }
    else
    {
        // 자정을 넘어가는 경우 (예: 23:00 ~ 06:00)
        return (currentTotal >= startTotal || currentTotal < endTotal);
    }
}
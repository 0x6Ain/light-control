// Utils.h
#ifndef UTILS_H
#define UTILS_H

#include <Arduino.h>
#include <config.h>

struct TimeRange
{
    int startHour;
    int startMinute;
    int endHour;
    int endMinute;
};

struct Time
{
    int hour;
    int minute;
    int second;
};

// 시각을 "HH:MM:SS" 문자열로 변환
inline String formatTime(int h, int m, int s)
{
    char buffer[9];
    snprintf(buffer, sizeof(buffer), "%02d:%02d:%02d", h, m, s);
    return String(buffer);
}

// 시각을 "HH:MM" 문자열로 변환
inline String formatTime(int h, int m)
{
    char buffer[6];
    snprintf(buffer, sizeof(buffer), "%02d:%02d", h, m);
    return String(buffer);
}

inline bool isValidTimeRange(const TimeRange &range)
{
    // 시(hour)는 0~23, 분(minute)는 0~59 범위여야 함
    if (range.startHour > 23 || range.startMinute > 59)
        return false;
    if (range.endHour > 23 || range.endMinute > 59)
        return false;
    return true;
}

inline TimeRange getDefaultTimeRange()
{
    // 기본값 예시: 오전 9시부터 오후 6시까지
    TimeRange defaultRange;
    defaultRange.startHour = SENSOR_OFF_START_HOUR;
    defaultRange.startMinute = SENSOR_OFF_START_MINUTE;
    defaultRange.endHour = SENSOR_OFF_END_HOUR;
    defaultRange.endMinute = SENSOR_OFF_END_MINUTE;
    return defaultRange;
}

#endif // UTILS_H

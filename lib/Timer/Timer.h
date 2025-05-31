#ifndef TIMER_H
#define TIMER_H

#include <Arduino.h>

class Timer
{
private:
    unsigned long interval;
    unsigned long lastTime;

public:
    explicit Timer(unsigned long intervalMillis)
        : interval(intervalMillis), lastTime(0) {}

    // loop()에서 주기적으로 호출, 시간 경과 시 콜백 실행
    bool check(void (*callback)())
    {
        unsigned long current = millis();
        if (current - lastTime >= interval)
        {
            lastTime = current;
            callback();
            return true;
        }
        return false;
    }
};

#endif // TIMER_H

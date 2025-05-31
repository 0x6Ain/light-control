#ifndef LEDCONTROLLER_H
#define LEDCONTROLLER_H

#include <Arduino.h>

class LEDController
{
public:
    static void begin(uint8_t pin, bool activeHigh = true);
    static void on();
    static void off();
    static bool isOn();

private:
    static uint8_t _pin;
    static bool _activeHigh;
    static bool _state;
};

#endif // LEDCONTROLLER_H

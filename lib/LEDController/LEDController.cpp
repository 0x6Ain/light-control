#include "LEDController.h"

uint8_t LEDController::_pin = 0;
bool LEDController::_activeHigh = true;
bool LEDController::_state = false;

void LEDController::begin(uint8_t pin, bool activeHigh)
{
    _pin = pin;
    _activeHigh = activeHigh;
    _state = false;
    pinMode(_pin, OUTPUT);
    digitalWrite(_pin, _activeHigh ? LOW : HIGH);
}

void LEDController::on()
{
    _state = true;
    digitalWrite(_pin, _activeHigh ? HIGH : LOW);
}

void LEDController::off()
{
    _state = false;
    digitalWrite(_pin, _activeHigh ? LOW : HIGH);
}

bool LEDController::isOn()
{
    return _state;
}

#include "OTAManager.h"
#include <Arduino.h>

OTAManager::OTAManager(const char *hostname)
{
    if (hostname)
    {
        ArduinoOTA.setHostname(hostname);
    }
    setupCallbacks();
}

void OTAManager::begin()
{
    ArduinoOTA.begin();
}

void OTAManager::handle()
{
    ArduinoOTA.handle();
}

void OTAManager::setupCallbacks()
{
    ArduinoOTA.onStart([]() {});
    ArduinoOTA.onEnd([]() {});
    ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {});
    ArduinoOTA.onError([](ota_error_t error) {});
}

#include <config.h>
#include <Arduino.h>
#include "WiFiController.h"
#include "TimeManager.h"
#include "PersistentStorage.h"
#include "WebConfigServer.h"
#include <ESP8266mDNS.h>
#include <OTAManager.h>
#include <LEDController.h>

WiFiController wifi;
TimeManager timeManager;
WebConfigServer webConfig;
PersistentStorage storage;
OTAManager ota(DEVICE_ID);
LEDController led;

void handleNetworkTasks()
{
    MDNS.update();
    webConfig.handleClient();
    ota.handle();
}

void handleLEDControl()
{
    const TimeRange range = storage.getTimeRange();
    if (timeManager.isWithinTimeRange(range))
    {
        LEDController::on();
    }
    else
    {
        LEDController::off();
    }
}
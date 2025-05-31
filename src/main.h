#include <config.h>
#include <Arduino.h>
#include <WiFiController.h>
#include <TimeManager.h>
#include <PersistentStorage.h>
#include <WebConfigServer.h>
#include <ESP8266mDNS.h>
#include <OTAManager.h>
#include <LEDController.h>
#include <Timer.h>

WiFiController wifi;
TimeManager timeManager;
WebConfigServer webConfig;
PersistentStorage storage;
OTAManager ota(DEVICE_ID);
LEDController led;

// 1시간 간격 (3600000 ms)
Timer ledControlTimer(3600000);

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

#ifndef WEB_CONFIG_SERVER_H
#define WEB_CONFIG_SERVER_H

#include <ESP8266WebServer.h>
#include "PersistentStorage.h"
#include "LEDController.h"
#include "Utils.h"
class WebConfigServer
{
public:
    WebConfigServer();
    void begin();
    void handleClient();

private:
    ESP8266WebServer server;
    PersistentStorage _storage;
    LEDController _led;

    void handleRoot();
    void handleWiFiForm();
    void handleTimerForm();
    void handleWiFiSave();
    void handleTimerSave();
    void handleLedOn();
    void handleLedOff();
    void handleLedToggle();
};

#endif

#ifndef WEB_CONFIG_SERVER_H
#define WEB_CONFIG_SERVER_H

#include <ESP8266WebServer.h>

class WebConfigServer
{
public:
    WebConfigServer();
    void begin();
    void handleClient();

private:
    ESP8266WebServer server;
    void handleRoot();
    void handleWiFiForm();
    void handleTimerForm();
    void handleWiFiSave();
    void handleTimerSave();
};

#endif

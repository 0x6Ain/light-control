#ifndef WIFI_CONTROLLER_H
#define WIFI_CONTROLLER_H

#include <Arduino.h>
#include <ESP8266WiFi.h> // ESP32일 경우 <WiFi.h>

class WiFiController
{
public:
    WiFiController() = default;
    bool connect(const char *ssid, const char *password, unsigned long timeoutMs = 10000);
    bool isConnected();
    String getLocalIP();
};

#endif

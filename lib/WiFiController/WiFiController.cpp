#include "WiFiController.h"
#include "PersistentStorage.h"

bool WiFiController::connect(const char *ssid, const char *password, unsigned long timeoutMs)
{
    WiFi.begin(ssid, password);
    unsigned long start = millis();
    while (WiFi.status() != WL_CONNECTED && millis() - start < timeoutMs)
    {
        delay(500);
    }
    return WiFi.status() == WL_CONNECTED;
}

bool WiFiController::isConnected()
{
    return WiFi.status() == WL_CONNECTED;
}

String WiFiController::getLocalIP()
{
    return WiFi.localIP().toString();
}

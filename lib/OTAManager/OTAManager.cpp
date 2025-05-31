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
    ArduinoOTA.onStart([]()
                       { Serial.println("OTA 시작"); });
    ArduinoOTA.onEnd([]()
                     { Serial.println("\nOTA 완료"); });
    ArduinoOTA.onProgress([](unsigned int progress, unsigned int total)
                          { Serial.printf("OTA 진행: %u%%\r", (progress / (total / 100))); });
    ArduinoOTA.onError([](ota_error_t error)
                       {
        Serial.printf("OTA 에러[%u]: ", error);
        if (error == OTA_AUTH_ERROR) Serial.println("인증 실패");
        else if (error == OTA_BEGIN_ERROR) Serial.println("초기화 실패");
        else if (error == OTA_CONNECT_ERROR) Serial.println("연결 실패");
        else if (error == OTA_RECEIVE_ERROR) Serial.println("데이터 수신 실패");
        else if (error == OTA_END_ERROR) Serial.println("종료 실패"); });
}

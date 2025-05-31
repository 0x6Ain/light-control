#ifndef OTAMANAGER_H
#define OTAMANAGER_H

#include <ArduinoOTA.h>

class OTAManager
{
public:
    explicit OTAManager(const char *hostname = nullptr);
    void begin();
    void handle();

private:
    void setupCallbacks();
};

#endif // OTAMANAGER_H

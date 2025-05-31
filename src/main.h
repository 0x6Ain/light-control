#include <config.h>
#include <Arduino.h>
#include "WiFiController.h"
#include "TimeManager.h"
#include "PersistentStorage.h"
#include "WebConfigServer.h"
#include <ESP8266mDNS.h>
#include <ArduinoOTA.h>
#include <OTAManager.h>

WiFiController wifi;
TimeManager timeManager;
WebConfigServer webConfig;
PersistentStorage persistentStorage;
OTAManager ota(DEVICE_ID);
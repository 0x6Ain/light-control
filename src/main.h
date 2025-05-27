#include <Arduino.h>
#include "WiFiController.h"
#include "TimeManager.h"
#include "config.h"
#include "PersistentStorage.h"
#include "WebConfigServer.h"
#include <ESP8266mDNS.h>

WiFiController wifi;
TimeManager timeManager;
WebConfigServer webConfig;
PersistentStorage persistentStorage;
#include "main.h"

void setup()
{
  Serial.begin(115200);
  persistentStorage.begin();

  String ssid = persistentStorage.getSSID();
  String pass = persistentStorage.getPassword();

  wifi.connect(ssid.c_str(), pass.c_str());

  // 연결 실패. AP 모드로 전환
  if (WiFi.status() != WL_CONNECTED)
  {
    WiFi.softAP(DEVICE_ID);
  }

  // http://${DEVICE_ID}.local
  MDNS.begin(DEVICE_ID);
  webConfig.begin();
  ota.begin();
}

void loop()
{
  MDNS.update();
  webConfig.handleClient();
  ota.handle();
}

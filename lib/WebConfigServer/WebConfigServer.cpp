#include "WebConfigServer.h"
#include "PersistentStorage.h"
#include <config.h>

WebConfigServer::WebConfigServer() : server(80) {}

void WebConfigServer::begin()
{
    server.on("/", std::bind(&WebConfigServer::handleRoot, this));
    server.on("/wifi", std::bind(&WebConfigServer::handleWiFiForm, this));
    server.on("/timer", std::bind(&WebConfigServer::handleTimerForm, this));
    server.on("/save_wifi", HTTP_POST, std::bind(&WebConfigServer::handleWiFiSave, this));
    server.on("/save_timer", HTTP_POST, std::bind(&WebConfigServer::handleTimerSave, this));
    server.begin();
}

void WebConfigServer::handleClient()
{
    server.handleClient();
}

void WebConfigServer::handleRoot()
{
    String ssid = PersistentStorage::getSSID();
    String pass = PersistentStorage::getPassword();
    int sh = PersistentStorage::getStartHour();
    int sm = PersistentStorage::getStartMinute();
    int eh = PersistentStorage::getEndHour();
    int em = PersistentStorage::getEndMinute();

    char timeStr[6];
    sprintf(timeStr, "%02d:%02d", sh, sm);
    String startTime = String(timeStr);
    sprintf(timeStr, "%02d:%02d", eh, em);
    String endTime = String(timeStr);

    String html = "<!DOCTYPE html><html><head><meta charset='UTF-8'><title>설정 상태</title></head><body>"
                  "<h1>현재 설정</h1>"
                  "<p><strong>SSID:</strong> " +
                  ssid + "</p>"
                         "<p><strong>Password:</strong> " +
                  pass + "</p>"
                         "<p><strong>Start Time:</strong> " +
                  startTime + "</p>"
                              "<p><strong>End Time:</strong> " +
                  endTime + "</p>"
                            "<br>"
                            "<a href='/wifi'><button>Wi-Fi 설정</button></a>"
                            "<a href='/timer'><button>타이머 설정</button></a>"
                            "<br><br>"
                            "<footer><small>버전: " +
                  VERSION_NUMBER + "</small></footer>"
                                   "</body></html>";

    server.send(200, "text/html; charset=utf-8", html);
}

void WebConfigServer::handleWiFiForm()
{
    String html = "<!DOCTYPE html><html><head><meta charset='UTF-8'><title>Wi-Fi 설정</title></head><body>"
                  "<h1>Wi-Fi 설정</h1>"
                  "<form method='POST' action='/save_wifi'>"
                  "SSID: <input name='ssid'><br>"
                  "Password: <input name='pass'><br>"
                  "<input type='submit' value='저장'></form>"
                  "<br><a href='/'><button>홈으로</button></a>"
                  "</body></html>";
    server.send(200, "text/html; charset=utf-8", html);
}

void WebConfigServer::handleTimerForm()
{
    String html = "<!DOCTYPE html><html><head><meta charset='UTF-8'><title>타이머 설정</title></head><body>"
                  "<h1>타이머 설정</h1>"
                  "<form method='POST' action='/save_timer'>"
                  "Start Time (HH:MM): <input name='start'><br>"
                  "End Time (HH:MM): <input name='end'><br>"
                  "<input type='submit' value='저장'></form>"
                  "<br><a href='/'><button>홈으로</button></a>"
                  "</body></html>";
    server.send(200, "text/html; charset=utf-8", html);
}

void WebConfigServer::handleWiFiSave()
{
    PersistentStorage::setSSID(server.arg("ssid"));
    PersistentStorage::setPassword(server.arg("pass"));

    String html = "<!DOCTYPE html><html><head><meta charset='UTF-8'><title>Wi-Fi 저장 완료</title></head><body>"
                  "<h1>Wi-Fi 저장 완료</h1>"
                  "<a href='/'><button>홈으로</button></a>"
                  "</body></html>";
    server.send(200, "text/html; charset=utf-8", html);
}

void WebConfigServer::handleTimerSave()
{
    String start = server.arg("start"); // HH:MM
    String end = server.arg("end");     // HH:MM

    int sh = start.substring(0, 2).toInt();
    int sm = start.substring(3, 5).toInt();
    int eh = end.substring(0, 2).toInt();
    int em = end.substring(3, 5).toInt();

    PersistentStorage::setStartHour(sh);
    PersistentStorage::setStartMinute(sm);
    PersistentStorage::setEndHour(eh);
    PersistentStorage::setEndMinute(em);

    String html = "<!DOCTYPE html><html><head><meta charset='UTF-8'><title>타이머 저장 완료</title></head><body>"
                  "<h1>타이머 저장 완료</h1>"
                  "<a href='/'><button>홈으로</button></a>"
                  "</body></html>";
    server.send(200, "text/html; charset=utf-8", html);
}

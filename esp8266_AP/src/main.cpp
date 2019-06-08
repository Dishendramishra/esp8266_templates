#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server;

IPAddress local_IP(192, 168, 1, 1);
IPAddress gateway(192, 168, 4, 9);
IPAddress subnet(255, 255, 255, 0);

void setup()
{
  Serial.begin(115200);
  Serial.println();

  //////////////////////////////////////////////////////////////////////////////
  //      Setting up Access Point
  //////////////////////////////////////////////////////////////////////////////
  Serial.print("Setting soft-AP configuration ... ");
  Serial.println(WiFi.softAPConfig(local_IP, gateway, subnet) ? "Ready" : "Failed!");

  Serial.print("Setting soft-AP ... ");
  Serial.println(WiFi.softAP("ESP8266", "qwerty@123") ? "Ready" : "Failed!");

  Serial.print("Soft-AP IP address = ");
  Serial.println(WiFi.softAPIP());
  //////////////////////////////////////////////////////////////////////////////

  server.on("/", []() { server.send(200, "text/plain", "Hello World!"); });
  server.begin();
}

void loop()
{
  server.handleClient();
  Serial.printf("Stations connected to soft-AP = %d\n", WiFi.softAPgetStationNum());
  delay(100);
}
#include <Arduino.h>
#include "handlingTG.h"



void setup()
{
    
  Serial.begin(115200);
  delay(512);
  Serial.println();
  Serial.print("Connecting to Wifi SSID: ");
  Serial.print(WIFI_NAME);
  WiFi.begin(WIFI_NAME, WIFI_PASSWORD);
  secured_client.setCACert(TELEGRAM_CERTIFICATE_ROOT); // Add root certificate for api.telegram.org
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.print("\nWiFi connected. IP address: ");
  Serial.println(WiFi.localIP());
}

void loop()
{

}
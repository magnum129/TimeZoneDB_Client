#include <ESP8266WiFi.h>
#include "TimeDB.h"

const char* ssid     = "your-ssid";
const char* password = "your-password";
String TIMEDBKEY = "your-timedb-key";
String LAT = "your-lat";
String LON = "your-lon";

TimeDB TimeDB("");

void setup() {
  Serial.begin(115200);
  delay(10);

  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  /* Explicitly set the ESP8266 to be a WiFi-client, otherwise, it by default,
     would try to act as both a client and an access-point and could cause
     network-issues with your other WiFi-devices on your WiFi-network. */
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  TimeDB.updateConfig(TIMEDBKEY, LAT, LON);
  setTime(TimeDB.getTime());
}

int value = 0;

void loop() {
  delay(5000);
  Serial.println(now());
}


// MyBlinkOTA.ino //
ADC_MODE(ADC_VCC)
#define BOARD "esp8266:esp8266:nodemcuv2"
#define IP_ADDRESS "192.168.0.177"
#define PORT "/dev/ttyUSB0"
#define OTAok (BOARD=="esp8266:esp8266:nodemcuv2")
// Test OTA using My_ESP8266_Functions

#include "My_ESP8266_Functions.h"

String IP = IP_ADDRESS; 
MyWiFi wifi("ESP8266",IP);

const byte led = 16;
unsigned long previousTime = millis();
const unsigned long interval = 2000;

void setup() {
  Serial.begin(115200); 
  delay(10);
  Serial.println('\n');
  wifi.connectWiFi();
  if (OTAok) wifi.myOTAsetup();
  pinMode(led, OUTPUT);
  digitalWrite(led, 1);
}

void loop() {
  if (OTAok) wifi.myOTAhandle();
  unsigned long diff = millis() - previousTime;
  if (diff > interval) {
    digitalWrite(led, !digitalRead(led));  // Change the state of the LED
    previousTime += diff;
    Serial.println(ESP.getVcc());
  }
}

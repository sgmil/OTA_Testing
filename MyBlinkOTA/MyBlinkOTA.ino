ADC_MODE(ADC_VCC)
#define BOARD esp8266:esp8266:nodemcuv2
#define IP_LAST_THREE 177
#define PORT /dev/ttyUSB0

// Test OTA using My_ESP8266_Functions


#include "My_ESP8266_Functions.h"

int IPlastThree=IP_LAST_THREE;
MyWiFi wifi("ESP8266",IPlastThree);

const byte led = 16;
unsigned long previousTime = millis();
const unsigned long interval = 250;

void setup() {
  Serial.begin(115200); 
  delay(10);
  Serial.println('\n');
  wifi.connectWiFi();
  wifi.myOTAsetup();
  pinMode(led, OUTPUT);
  digitalWrite(led, 1);
}

void loop() {
  wifi.myOTAhandle();
  unsigned long diff = millis() - previousTime;
  if (diff > interval) {
    digitalWrite(led, !digitalRead(led));  // Change the state of the LED
    previousTime += diff;
    Serial.println(ESP.getVcc());
  }
}
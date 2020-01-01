// Test OTA using My_ESP8266_Functions
ADC_MODE(ADC_VCC)

#include "My_ESP8266_Functions.h"
#include <string>

int IPlastThree=177;
MyWiFi wifi("ESP8266",IPlastThree);

const byte led = 16;
unsigned long previousTime = millis();
const unsigned long interval = 1000;

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

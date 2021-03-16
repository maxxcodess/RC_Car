#include "Wifi.h"
#include "Motors.h"

void setup(){
  
    Serial.begin(9600);
    pinMode(D4, OUTPUT);
    digitalWrite(D4, HIGH);

    MotorsInit();
    WifiInit();
}

void loop() {
  //loop1();
  parsPacket();
  
  
}


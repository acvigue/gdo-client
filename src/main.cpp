#include <Arduino.h>

#define TX_PIN 3

bool outgoingManchester[1000];
int outgoingManchesterPos = 0;

void setup ()
{
  pinMode(TX_PIN, OUTPUT);
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
  Serial.begin(115200);
}  // end of setup

void sendManchester() {
  for(int i = 0; i <= 16; i++) {
    for(int i = 0; i < outgoingManchesterPos; i++) {
      bool d = outgoingManchester[i];
      digitalWrite(TX_PIN, d);
      delayMicroseconds(250);
    }
  }
} 

void loop ()
{ 
  if(Serial.available()) {
    int l = Serial.read();
    if(l == 48) {
      outgoingManchester[outgoingManchesterPos] = false;
      outgoingManchesterPos++;
    } else if(l == 49) {
      outgoingManchester[outgoingManchesterPos] = true;
      outgoingManchesterPos++;
    } else if(l == 10) {
      sendManchester();
      memset(outgoingManchester, 0, outgoingManchesterPos);
      outgoingManchesterPos = 0;
    }
  }
}  // end of loop






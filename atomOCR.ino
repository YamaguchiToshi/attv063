#include <M5Atom.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>

const uint16_t kIrLed = 12;
const uint16_t extSw = 25;
IRsend irsend(kIrLed);

uint16_t rawDataOn[19] = {2578, 2686,  828, 890,  804, 866,  826, 1906,  830, 1906,  830, 1906,  828, 1906,  830, 890,  804, 890,  802};
uint16_t rawDataOff[19] = {2578, 2684,  830, 866,  826, 1906,  828, 866,  826, 868,  824, 1906,  828, 890,  802, 1906,  828, 1906,  828};

int sw = 0;

void setup() {
  pinMode(extSw, INPUT_PULLUP);
  irsend.begin();
  Serial.begin(115200, SERIAL_8N1);
}

void sendOn() {
  for(int i = 0; i < 3; ++i){
    irsend.sendRaw(rawDataOn, 19, 38);
  }
}

void sendOff() {
  for(int i = 0; i < 3; ++i){
    irsend.sendRaw(rawDataOff, 19, 38); 
  }
}

void loop() {
  
/*　こちらのコメントアウトされているのは，本体に実装されたボタン用
  M5.update();
  if( M5.Btn.isPressed() && sw == 0 ){
    sendOn();
    sw = 1;
    Serial.println("on..");
  } else if( M5.Btn.isReleased() && sw == 1 ){
    sendOff();
    sw = 0;
    Serial.println("off..");
  }
*/
  
  if( !digitalRead(extSw) && sw == 0 ){
    sendOn();
    sw = 1;  
  } else if( digitalRead(extSw) && sw == 1 ){
    sendOff();
    sw = 0;
  }
  
}

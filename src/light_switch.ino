#include <Servo.h>
#include <IRremote.hpp>

bool servoIsTapping = false;
unsigned long tapStartTime = 0;

Servo lightswitch;

int IRpin = 11;

IRrecv irrecv(IRpin);

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  lightswitch.attach(9);
  lightswitch.write(90);

}

void loop() {
  if (irrecv.decode()){
    uint32_t code = irrecv.decodedIRData.decodedRawData;
  
  if (code == 0xEA15FF00){ //on
    lightswitch.write(60);
    servoIsTapping = true;
    tapStartTime = millis();
  }

  if (code == 0xF807FF00){ //off
    lightswitch.write(120);
    servoIsTapping = true;
    tapStartTime = millis();
  }
  irrecv.resume();
  }

  if (servoIsTapping && (millis() - tapStartTime >= 3000)) {
    lightswitch.write(90);
    servoIsTapping = false;


  }

}


#include <Servo.h>

Servo myservo1;
Servo myservo2;

float positie = 0; //maak een variabele

void setup() {
  myservo1.attach(2);
  myservo2.attach(3);
}

void loop() {
  positie = positie + 0.01; //tel 1 op bij positie
  myservo1.write(sin(positie)*90+90);
  myservo2.write(sin(positie+3.14)*90+90);
  delay(100);
}

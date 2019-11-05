#include "ServoKeyer.h"
ServoKeyer servoKeyer(0,1);

void setup() {
}

void loop() {
  servoKeyer.move(30,0,2000);
  servoKeyer.move(105,0,2000);
}

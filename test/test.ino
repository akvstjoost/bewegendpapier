#include "ServoKeyer.h"
ServoKeyer servoKeyer(0,1);

void setup() {
  // put your setup code here, to run once:

  
}

void loop() {
  // put your main code here, to run repeatedly:
  servoKeyer.move(30,100,2000);

  servoKeyer.move(105,45,2000);
   servoKeyer.move(60,70,2000); 
      servoKeyer.move(60,170,2000); 
      servoKeyer.move(160,170,200); 
          servoKeyer.move(60,170,200); 
}

/* ServoKeyer - Library for moving 2 serovs at once with the Digispark
	Created by Thomas Rutgers in 2019 for the AKV|St.Joost Techlab -  tsrutrger@avans.nl
	Released into the public domain.
*/

#ifndef ServoKeyer_h
#define Servokeyer_h
 
#include "Arduino.h"
#include <SoftRcPulseOut.h>

class ServoKeyer {
  public:
    ServoKeyer(int pin1, int pin2);
    void set(int pos1, int pos2);
    void move(int pos1, int pos2, int time); 
    void wait(int time);
  private:
  	SoftRcPulseOut _servo1;
	SoftRcPulseOut _servo2;
	int _pos1;
	int _pos2;
  int calcPos(float loop, float loops, float start, float end);
};

#endif

#include "Arduino.h"
#include "ServoKeyer.h"

ServoKeyer::ServoKeyer(int pin1, int pin2) {
	_servo1.attach(pin1);
	_servo2.attach(pin2);
	_pos1 = 0;
	_pos2 = 0;
	Serial.begin(9600);
}


void ServoKeyer::move(int pos1, int pos2, int time) {
	int loops = time / 20;
	if (loops < 1) loops=1;
	int start1 = _pos1;
	int start2 = _pos2;
	int stop1 = pos1;
	int stop2 = pos2;
	for (int l=0;l<loops;l++) {
		_servo1.write(calcPos(l,loops,start1,stop1));
		_servo2.write(calcPos(l,loops,start2,stop2));
		delay(20);        // waits 20ms for refresh period 
    	SoftRcPulseOut::refresh(1); 
    	Serial.write(calcPos(l,loops,start1,stop1));
	}

    _pos1 = pos1;
    _pos2 = pos2;

}

void ServoKeyer::wait(int time) {
	int loops = time / 20;
	if (loops < 1) loops=1;

	for (int l=0;l<loops;l++) {
		_servo1.write(_pos1);
		_servo2.write(_pos2);
		delay(20);        // waits 20ms for refresh period 
    	SoftRcPulseOut::refresh(1); 
	}



}

int ServoKeyer::calcPos(float loop, float loops, float start, float end) {
	return int(end*(loop/loops))+ (start*(1-(loop/loops)));

}
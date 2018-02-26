/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>
#include <math.h>

Servo seizing_servo;
Servo savage_servo;

int seizingStage = 0;
int seizingPos = 0;
int seizingT = 0;
int seizingOffset = 3;

double savagePos = 0;
double savageAverage = 140;
double savageDifference = 40;
int savageT=0;

void setup() {
  seizing_servo.attach(9);
  savage_servo.attach(8);
}

void loop() {
  switch(seizingStage) {
    case 0:
    case 2:
    case 4:
      seizingOffset = 2;
      break;
    case 1:
    case 3:
    case 5:
      seizingOffset = -2;
      break;
    default:
      seizingOffset = 0;
  }
  seizingPos += seizingOffset;
  seizing_servo.write(seizingPos);
  seizingT++;
  if(seizingT>=15) {
    seizingT-=15;
    seizingStage++;
  }
  if (seizingStage>=8){
    seizingStage=0;
  }

  if(seizingPos>=30)
    seizingStage++;
  if(seizingPos<=0)
    seizingStage++;
  
  savagePos = savageAverage-(cos(savageT*0.0174533)*savageDifference);
  savage_servo.write(savagePos);
  savageT++;
  if(savageT>=360)
    savageT-=360;
  
  delay(5);
}


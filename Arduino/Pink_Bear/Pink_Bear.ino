/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>
#include <math.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

double pos = 0;    // variable to store the servo position
double maxValue = 180;
double minValue = 100;

double average = (maxValue+minValue)/2;
double difference = (maxValue-minValue)/2;
int t=0;

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  pos = average-(cos(t*0.0174533)*difference);
  myservo.write(pos);
  t++;
  if(t>=360)
    t-=360;
  delay(5);
    
}


/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo struggling;  // create servo object to control a servo
Servo other;
// twelve servo objects can be created on most boards
int timer = 0;
void setup() {
  struggling.attach(9);  // attaches the servo on pin 9 to the servo object
 // other.attach(8);
}

void loop() {
/*
   struggling.write(120);   
  delay(1000);

  struggling.write(90);
  delay(3000);
  struggling.write(45);
*/
 struggling.write(85);
  delay(1000);
  struggling.write(95);
  delay(1000);
  struggling.write(90);
  delay(3000);
 
  
}


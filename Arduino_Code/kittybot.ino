/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

 Servo s1,s2,s3,s4; // created on most boards
 

int pos = 0;    // variable to store the servo position
int t=2000;
void setup() {
  s1.attach(6);// attaches the servo on pin 9 to the servo object
  s1.write(50);
  s2.attach(5);
  s2.write(90);
  s3.attach(9);  // attaches the servo on pin 9 to the servo object
   s3.write(55);
  s4.attach(3);
  s4.write(90);
}

void loop() {
  
  s1.write(30);
  delay(t);
  s1.write(40);
  delay(t);
  s3.write(95);
  delay(t);
  s1.write(50);
  delay(t);
  s3.write(75);
  delay(t);
  s4.write(50);
  delay(t);
  s3.write(55);
  delay(t);
  s4.write(70);
  delay(t);
  s2.write(110);
  delay(t);
  s4.write(90);
  delay(t);
  s2.write(90);
  
//for (pos = 0; pos <= 180; pos += 90) { // goes from 0 degrees to 180 degrees
//    // in steps of 1 degree
//    myservo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(100);                       // waits 15ms for the servo to reach the position
//  }
//  for (pos = 180; pos >= 0; pos -= 90) { // goes from 180 degrees to 0 degrees
//    myservo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay();                       // waits 15ms for the servo to reach the position
//  }
}


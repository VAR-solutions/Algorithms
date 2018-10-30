#include<Servo.h>
Servo s1, s2, s3, s4;

void setup()
{s1.attach(6);// attaches the servo on pin 9 to the servo object
  s1.write(90);
  s2.attach(5);
  s2.write(90);
  s3.attach(9);  // attaches the servo on pin 9 to the servo object
   s3.write(90);
  s4.attach(3);
  s4.write(90);
  
}
void loop()
{
  s1.write(30);
  s2.write(40);
}


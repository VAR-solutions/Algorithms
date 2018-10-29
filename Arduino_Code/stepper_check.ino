
/*
 Stepper Motor Control - one revolution

 This program drives a unipolar or bipolar stepper motor.
 The motor is attached to digital pins 8 - 11 of the Arduino.

 The motor should revolve one revolution in one direction, then
 one revolution in the other direction.


 Created 11 Mar. 2007
 Modified 30 Nov. 2009
 by Tom Igoe*/

 

#include <Stepper.h>
const int leftpin = A0;
const int rightpin = 7;
long duration;
long duration1;
int distance1;
int distance;


const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor

const int trigPin=2 ;
const int echoPin = 12;
const int echoPin1 = 3;
const int trigPin1=4 ;
int state = 0;    ////////////////////////////0=STOP,1=LEFT,2=RIGHT
int leftstpr;
int rightstpr;  

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

void setup() {
  // set the speed at 60 rpm:
  myStepper.setSpeed(60);
  // initialize the serial port:
  Serial.begin(9600);
  pinMode(5,OUTPUT);
  pinMode(leftpin,INPUT);
  pinMode(rightpin,INPUT);
  pinMode(6,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin1, INPUT); // Sets the echoPin as an Input
  analogWrite(5,150);
  analogWrite(6,150);
  rightstpr = digitalRead(rightpin);
  leftstpr = digitalRead(leftpin);

// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;

// Prints the distance on the Serial Monitor
digitalWrite(trigPin1, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration1 = pulseIn(echoPin1, HIGH);
// Calculating the distance
distance1= duration1*0.034/2;

}

void loop() {

if(distance1 > 30)
{
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
}
else
distance = 100;

if(distance > 30){
// Prints the distance on the Serial Monitor
digitalWrite(trigPin1, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration1 = pulseIn(echoPin1, HIGH);
// Calculating the distance
distance1= duration1*0.034/2;
}
else
distance1 = 100;

Serial.print("Distance: ");
Serial.println(distance);
Serial.print("Distance1: ");
Serial.println(distance1);
  
  
if(state == 1){
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  
  }
  else if(state == 2){
    Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
    }

    else {
    Serial.println("stopped");
  myStepper.step(0);   
      }

  
  if((state == 2 && digitalRead(leftpin)==1-leftstpr) or (state == 0 && digitalRead(leftpin)==1-leftstpr) or (distance < 11 && state == 1) or (distance < 11&& state == 2))
  {// step one revolution  in one direction:
    rightstpr = digitalRead(rightpin);
  leftstpr = digitalRead(leftpin);
  state = 1;
  

  // step one revolution in the other direction:
  
  //Serial.println("counterclockwise");
  //myStepper.step(-stepsPerRevolution);
  //delay(500);
  }
   else if((state == 1 && digitalRead(rightpin)==1-rightstpr) or (state == 0 && digitalRead(rightpin)==1-rightstpr) or (distance1 < 12 && state==1) or (distance1 < 12 && state==2))
   
  { state = 2;
    rightstpr = digitalRead(rightpin);
  leftstpr = digitalRead(leftpin);
    
  // step one revoluti0on  in one direction:
  //Serial.println("clockwise");
 // myStepper.step(0);
  //delay(500);

  //step one revolution in the other direction:
  //Serial.println("counterclockwise");
  //myStepper.step(0);
  //
  
  
  }
else if((state == 1 && digitalRead(leftpin)==1-leftstpr) or (state == 2 && digitalRead(rightpin)==1-rightstpr) or (state==0 && distance < 10) or (state==0 && distance1 < 11))
   { state = 0;
     rightstpr = digitalRead(rightpin);
  leftstpr = digitalRead(leftpin);
   
   }

//   else if(digitalRead(leftpin)==LOW)
//   {
//    Serial.println("stopped");
//  myStepper.step(0);
//   }
  }
  


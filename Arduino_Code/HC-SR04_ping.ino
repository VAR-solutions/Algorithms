

/*Before attempting the project try to get some knowledge
about the HC-SR04 Ultrasound Sensor and Arduino.
                              Abhyuday Tripathi */





long duration; // defining variables for time taken by the wave to comeback after emission.

float distance;// defining variable for distance that has to be measured by the sensor.
int triggerPin = 13;
int echoPin = 11;

void setup() {
pinMode(triggerPin, OUTPUT);//initialising triggerPin as OUTPUT.
 
pinMode(echoPin, INPUT); //initialising echoPin as INPUT.
  
Serial.begin(9600); //Activating the Serial at 9600 baud.
}

void loop() {
  digitalWrite(triggerPin, LOW); //triggerPin at LOW initially.
  
  delayMicroseconds(2);

  digitalWrite(triggerPin, HIGH);// Activating triggerPin to HIGH to generate 8-bit pulse for 10 microseconds.
  delayMicroseconds(10);

  duration = pulseIn(echoPin, HIGH);// echoPin will be high untill no returning wave has hit it
                                     // that is the duration which is required fo the calculation.

  distance = duration*0.03356*0.5 ; //calculating distance in centmeters.
Serial.print("Distance in cm : ");//Serial Monitor will print the distance with interval of one second.
Serial.println(distance);
delay(1000);
}

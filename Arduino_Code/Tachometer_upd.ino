/* This Arduino Project Calculates RPM of any DC Wheeled Motor
Before attempting this project try to get some knowledge about 
IR Proximity Sensor module. For this project you will need a dc motor 
and wheel with **half black and half white** template on the wheel rim.
Main concept of IR Tachometer is transmission and reflection of IR signal.
                                                    Abhyuday Tripathi*/







long t ; //declaring global vaiable for time to complete half rotation.
const int out = 7; //IR OUT is set to digital Pin 7.
float rpm; //declaring RPM

void setup() 
{
 pinMode(out, INPUT); //initialising OUT as INPUT.
 
  Serial.begin(9600); //Activating Serial Connection at 9600 baud.
  }

void loop() {
  t = pulseIn(out, LOW);// calculating time for which out stays LOW.
 
 rpm = 60000*0.5*1000/t ; //calculating RPM by keeping in mind that default time unit in Arduino is in Microseconds.

 Serial.print("RPM : "); //Printing results on the Serial Monitor with interval of 1 second.
 Serial.println(rpm);
delay(1000);
}

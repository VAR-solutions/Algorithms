//Credit to: Angelo Casimiro 



String voice;
int 
led1 = 2, //Connect LED 1 To Pin #2 
led2 = 3, //Connect LED 2 To Pin #3 
led3 = 4, //Connect LED 3 To Pin #4 
led4 = 5, //Connect LED 4 To Pin #5 
led5 = 6; //Connect LED 5 To Pin #6 
//--------------------------Call A Function-------------------------------//  
void allon(){
     digitalWrite(led1, HIGH); 
     digitalWrite(led2, HIGH); 
     digitalWrite(led3, HIGH); 
     digitalWrite(led4, HIGH); 
     digitalWrite(led5, HIGH); 
}
void alloff(){
     digitalWrite(led1, LOW); 
     digitalWrite(led2, LOW); 
     digitalWrite(led3, LOW); 
     digitalWrite(led4, LOW); 
     digitalWrite(led5, LOW);
}
//-----------------------------------------------------------------------//  
void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT); 
  pinMode(led2, OUTPUT); 
  pinMode(led3, OUTPUT); 
  pinMode(led4, OUTPUT); 
  pinMode(led5, OUTPUT); 
}
  
void loop() {
  while (Serial.available()){ 
  delay(50);  
  char chunk = Serial.read(); //Data chunk recieved by the HC05 Module
  if (chunk == '#') {break;} //Empty Data Chunk
  voice += chunk; //Constructing instruction using data chunks
  }  
  if (voice.length() > 0) {
    Serial.println(voice); 
//-----------------------------------------------------------------------//    
  //----------Control Multiple Pins/ LEDs----------//  
       if(voice == "*all on") {allon();}  //Turn Off All Pins (Call Function)
  else if(voice == "*all off"){alloff();} //Turn On  All Pins (Call Function)
  
  //----------Turn On One-By-One----------// 
  else if(voice == "*L1 on") {digitalWrite(led1, HIGH);} 
  else if(voice == "*L2 on") {digitalWrite(led2, HIGH);}
  else if(voice == "*L3 on") {digitalWrite(led3, HIGH);}
  else if(voice == "*L4 on") {digitalWrite(led4, HIGH);}
  else if(voice == "*L5 on") {digitalWrite(led5, HIGH);}
  //----------Turn Off One-By-One----------// 
  else if(voice == "*L1 off") {digitalWrite(led1, LOW);} 
  else if(voice == "*L2 off") {digitalWrite(led2, LOW);}
  else if(voice == "*L3 off") {digitalWrite(led3, LOW);}
  else if(voice == "*L4 off") {digitalWrite(led4, LOW);}
  else if(voice == "*L5 off") {digitalWrite(led5, LOW);}
//-----------------------------------------------------------------------//  
voice="";}} //Reset the variable after initiating 

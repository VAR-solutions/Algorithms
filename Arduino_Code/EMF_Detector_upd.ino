/*This project measures the EMF intensity around any ac electrical appliances by LED 
 * this project is one of the simplest one that you can try.
 * Before attempting the project get some idea about constrain() and map() functions in arduino math
 * the fritzing sketch regarding the project can be found in Arduino101 repository 
                                                                               - Abhyuday  */
 





int antPin = 7;        // antenna Pin to analog 7 
int analogValue = 0;  // store small analog voltage values to analogValue and initialise it to 0
int LED = 11;         // Detection LED to A11

void setup() {
 
  Serial.begin(9600); // Beginning Serial Connection at 9600 Baud
  
}

void loop() {
  
  analogValue = analogRead(antPin); //Read analog values from antPin and assign them to analogValue 
                                                                   
  if(analogValue >= 1)   //if antPin sense analog wave in environment
  {
    
    analogValue = constrain(val, 1, 100);  //ranging the analogValue in (1 to 100)scale                                     
    analogValue = map(analogValue, 1, 100, 1, 255); //remapping analogValue in (1 to 255) scale
    analogWrite(LED, analogValue);  // HIGH the LED according to intensity of analogValue
   }else{                                                      
                                                                
    analogWrite(LED, 0);  //if antPin sense nothing then put LED at LOW                  
                                                             
  }
  
 Serial.println(analogValue);                   
 
}

long randomNumber;

void setup() {
  Serial.begin(9600);

  // use random seedon an unconnected pin (this code assumes pin 1) to generate a 
  // different seed everytime the code is run (due to random analog noise)
  randomSeed(analogRead(1));
}

void loop() {
  //provides a random number up to 700
  randomNumber = random(700);
  Serial.println(randomNumber);

  //another method to use random is giving it an upper and lower bound
  randomNumber = random(35, 4300);
  Serial.println(randomNumber);

  delay(500);
}

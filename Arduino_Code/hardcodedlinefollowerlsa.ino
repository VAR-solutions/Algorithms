#define dir2 7
#define pwm2 6
#define pwm1 5
#define dir1 4
#define pwm 9
#define dir 8
#define RX 1
#define TX 0 
#define serialEn 2
#define jnPulse 3 
#define An A0
int readVal,positionVal;

void forward()
{
  analogWrite(pwm1,30);
  digitalWrite(dir1,LOW);
  analogWrite(pwm2,30);
  digitalWrite(dir2,LOW);
  analogWrite(pwm,LOW);
  digitalWrite(dir,LOW);
  
}
void right()
{ 
  analogWrite(pwm1,30);
  digitalWrite(dir1,LOW);
  analogWrite(pwm2,30);
  digitalWrite(dir2,HIGH);
  analogWrite(pwm,30);
  digitalWrite(dir,HIGH);
}
void left()
{ 
  analogWrite(pwm1,30);
  digitalWrite(dir1,HIGH);
  analogWrite(pwm2,30);
  digitalWrite(dir2,LOW);
  analogWrite(pwm,30);
  digitalWrite(dir,LOW);
}
void reverse()
{ 
  analogWrite(pwm1,30);
  digitalWrite(dir1,HIGH);
  analogWrite(pwm2,30);
  digitalWrite(dir2,HIGH);
  analogWrite(pwm,LOW);
  digitalWrite(dir,LOW);
}
void stopbot()
{
  analogWrite(pwm1,LOW);
  analogWrite(pwm2,LOW);
  analogWrite(pwm,LOW);
}

void setup() {
  Serial.begin(9600);
  pinMode(dir2,OUTPUT);
  pinMode(dir1,OUTPUT);
  pinMode(pwm1,OUTPUT);
  pinMode(pwm2,OUTPUT);
  pinMode(dir,OUTPUT);
  pinMode(pwm,OUTPUT);

  pinMode(serialEn,OUTPUT); 
  pinMode(jnPulse,INPUT);

  digitalWrite(serialEn,30);
  
  analogWrite(pwm1,LOW);
  digitalWrite(dir1,LOW);
  analogWrite(pwm2,LOW);
  digitalWrite(dir2,LOW);
  analogWrite(pwm,LOW);
  digitalWrite(dir,LOW);

  delay(3000);  

}

void loop() {

  readVal = analogRead(An);
  positionVal = ((float)readVal/921)*70;

  if(positionVal<=25)
  { 
    
    left();
    delay(30);
    
  }
  else if(positionVal<=40)
  { 
    
    forward();
    
  }
  else if(positionVal<=70)
  { 
    
    right();
    delay(30);
    
  }
  
  else
  { 
   
    right();
    delay(30);
  
  }

}

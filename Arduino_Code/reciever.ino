//Connect the Receiver data pin to Arduino pin 11

#include <VirtualWire.h>
byte message[VW_MAX_MESSAGE_LEN]; // a buffer to store the incoming messages
byte messageLength = VW_MAX_MESSAGE_LEN; // the size of the message

int lm=9;
int lmr=8;
int rm=10;
int rmr=7;
int ledPin=13;//led on pin 13 is ON except when bot is stationary

void setup()
{
 //Serial.begin(9600);//Initialise the serial connection debugging

 pinMode(ledPin,OUTPUT);
 pinMode(lm,OUTPUT);
 pinMode(lmr,OUTPUT);
 pinMode(rm,OUTPUT);
 pinMode(rmr,OUTPUT);

 vw_setup(2000); // Bits per sec
 vw_rx_start(); // Start the receiver
}
void loop()
{
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;

    if (vw_get_message(buf, &buflen)) // Non-blocking
    {
  int i;

  //Serial.print("Got: ");//debugging
  
  for (i = 0; i < buflen; i++)
  {
     // Serial.print(buf[i],HEX);//You may also use integer values debugging
      //Serial.print(' ');// debugging

          if (buf[i]==0x73)//Stationary
          {
            digitalWrite(lm,LOW);  
            digitalWrite(lmr,LOW);
            digitalWrite(rm,LOW);
            digitalWrite(rmr,LOW);
          
            digitalWrite(ledPin,LOW);
          }
          else
          {
            if(buf[i]==0x66)//Forward
            {
              digitalWrite(lm,LOW);  
              digitalWrite(lmr,HIGH);
              digitalWrite(rm,HIGH);
              digitalWrite(rmr,LOW);
              
              digitalWrite(ledPin,HIGH);
            }
          
            if (buf[i]==0x61)//Backward
            {
              digitalWrite(lm,HIGH);  
              digitalWrite(lmr,LOW);
              digitalWrite(rm,LOW);
              digitalWrite(rmr,HIGH);
              
              digitalWrite(ledPin,HIGH);
          }
          
            if (buf[i]==0x72)//Left 
            {
              digitalWrite(lm,LOW);  
              digitalWrite(lmr,LOW);
              digitalWrite(rm,HIGH);
              digitalWrite(rmr,LOW);
              digitalWrite(ledPin,HIGH);
            }
          
            if (buf[i]==0x6C)//Right 
            {
              digitalWrite(lm,LOW);  
              digitalWrite(lmr,HIGH);
              digitalWrite(rm,LOW);
              digitalWrite(rmr,LOW);
              digitalWrite(ledPin,HIGH);
            }
           }   
    }
    //Serial.print("\n");// debugging
        }
        //delay(1000);
}

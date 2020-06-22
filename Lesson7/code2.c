#include<MsTimer2.h>
volatile int pinlnterrupt=2;
int n=0;
int b=0;
void abec()
{
  digitalWrite(8,LOW);
  if(digitalRead(pinlnterrupt) == LOW)
  b=9;
  n=b%10;
  digitalWrite(3,n&0x1);
  digitalWrite(4,(n>>1)&0x1);
  digitalWrite(5,(n>>2)&0x1);
   digitalWrite(6,(n>>3)&0x1);
b++;
digitalWrite(8,HIGH);
}
void setup()
{
  pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
digitalWrite(8,LOW);
digitalWrite(9,HIGH);
digitalWrite(10,HIGH);
Serial.begin(9600);

  MsTimer2::set(1000,abec);
  MsTimer2::start();
  attachInterrupt( digitalPinToInterrupt(pinlnterrupt),abec, CHANGE);
}
void loop()
{
}
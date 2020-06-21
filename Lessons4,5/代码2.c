void setup()
{
  pinMode(2, OUTPUT);//输入1
  pinMode(3, OUTPUT);//输入2
  pinMode(4, OUTPUT);//输入3
  pinMode(5, OUTPUT);//输入4
  pinMode(8, OUTPUT);//片选1
  pinMode(9, OUTPUT);//片选2
  pinMode(10, OUTPUT);//片选3
  pinMode(11, OUTPUT);//片选4
  pinMode(6,OUTPUT);//测试
  pinMode(7,OUTPUT);//消隐
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
  Serial.begin(9600);
}
byte income1,income2,income3,income4;
void loop()
{
  if(Serial.available()>0)
  {
  income1=Serial.read();
  income1=income1-'0';
  digitalWrite(5,income1&0x1);
  digitalWrite(2,(income1>>1)&0x1);
  digitalWrite(3,(income1>>2)&0x1);
  digitalWrite(4,(income1>>3)&0x1);
  delay(10);
  digitalWrite(8,HIGH);
  
  income2=Serial.read();
  income2=income2-'0';
  digitalWrite(5,income2&0x1);
  digitalWrite(2,(income2>>1)&0x1);
  digitalWrite(3,(income2>>2)&0x1);
  digitalWrite(4,(income2>>3)&0x1);
  delay(10);
  digitalWrite(9,HIGH);
  
  income3=Serial.read();
  income3=income3-'0';
  digitalWrite(5,income3&0x1);
  digitalWrite(2,(income3>>1)&0x1);
  digitalWrite(3,(income3>>2)&0x1);
  digitalWrite(4,(income3>>3)&0x1);
  delay(10);
  digitalWrite(10,HIGH);
  
  income4=Serial.read();
  income4=income4-'0';
  digitalWrite(5,income4&0x1);
  digitalWrite(2,(income4>>1)&0x1);
  digitalWrite(3,(income4>>2)&0x1);
  digitalWrite(4,(income4>>3)&0x1);
  delay(10);
  digitalWrite(11,HIGH);
  }
}
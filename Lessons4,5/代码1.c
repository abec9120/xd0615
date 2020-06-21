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
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(11,LOW);
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
  digitalWrite(11,HIGH);
  
  
  }
}
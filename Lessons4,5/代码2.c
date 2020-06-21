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
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  Serial.begin(9600);
}
byte income[4];
void loop()
{
  if(Serial.available()>0)
  {
  for(int i=0;i<4;i++)
  {
  income[i]=Serial.read();
  income[i]=income[i]-'0';
  digitalWrite(5,income[i]&0x1);
  digitalWrite(2,(income[i]>>1)&0x1);
  digitalWrite(3,(income[i]>>2)&0x1);
  digitalWrite(4,(income[i]>>3)&0x1);
  delay(10);
  digitalWrite(i+8,HIGH);
  }
  }
}
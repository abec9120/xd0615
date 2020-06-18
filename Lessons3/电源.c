char ch=' ';
void setup()
{
  Serial.begin(9600);
  pinMode(5,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  Serial.println("ok!");
}

/*
预定
'f':表示前进
'b':表示后退
'r':表示右转
'l':表示左转
's':表示停止
*/
void loop()
{
  if(Serial.available()>0)
  {
  	ch=Serial.read();
    switch(ch)
    {
    case 'f':
      digitalWrite(2,HIGH);
      digitalWrite(3,LOW);
      digitalWrite(4,HIGH);
      digitalWrite(5,LOW);
      digitalWrite(10,HIGH);
      digitalWrite(11,LOW);
      digitalWrite(12,LOW);
      digitalWrite(13,LOW);
      break;
    case 'b':
      digitalWrite(3,HIGH);
      digitalWrite(2,LOW);
      digitalWrite(5,HIGH);
      digitalWrite(4,LOW);
      digitalWrite(11,HIGH);
      digitalWrite(10,LOW);
      digitalWrite(12,LOW);
      digitalWrite(13,LOW);

      break;
    case 'r':
      digitalWrite(2,HIGH);
      digitalWrite(3,LOW);
      digitalWrite(5,HIGH);
      digitalWrite(4,LOW);
      digitalWrite(12,HIGH);
      digitalWrite(11,LOW);
      digitalWrite(10,LOW);
      digitalWrite(13,LOW);
      break;
    case 'l':
      digitalWrite(3,HIGH);
      digitalWrite(2,LOW);
      digitalWrite(4,HIGH);
      digitalWrite(5,LOW);
      digitalWrite(13,HIGH);
      digitalWrite(11,LOW);
      digitalWrite(12,LOW);
      digitalWrite(10,LOW);
      break;
    case 's':
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      digitalWrite(13,LOW);
      digitalWrite(11,LOW);
      digitalWrite(12,LOW);
      digitalWrite(10,LOW);
      break;
    default:
      break;
    }
  }
}

#include<stdio.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
String str1="";

void setup(){
  lcd.begin(16,2);
  Serial.begin(9600);
}

void loop(){
  while (Serial.available()>0)
  {
    str1 +=char(Serial.read());
    delay(2);
  }
  
  if (str1.length()>0)
  {
    Serial.println(str1);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(str1);
  }
  
  str1="";
}
 
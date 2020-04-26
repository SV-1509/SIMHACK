#include<LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup()
{
 lcd.begin(16, 2); 
}

float res()
{
  float k = analogRead(14);
  float v = k*5/1023;
  float r = (5000 - v*1000)/v;
  return r;
}
void loop()
{
  

  lcd.setCursor(0,0);          
  lcd.print("R ="); 
  lcd.setCursor(3,0);    
  float resistance = res();
  lcd.print(resistance);
 

  }
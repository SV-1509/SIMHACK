#include<LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup()
{
 lcd.begin(16, 2); 
 
 pinMode(9,OUTPUT);
 pinMode(8,OUTPUT);
 pinMode(7,OUTPUT);
 pinMode(6,OUTPUT);
}
float microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}
void loop()
{
  

  lcd.setCursor(0,0);          
  lcd.print("DISTANCE IN CM"); 
  lcd.setCursor(2,1);    
  
  pinMode(10, OUTPUT);
  digitalWrite(10, LOW);
  delayMicroseconds(2);
  digitalWrite(10, HIGH);
  delayMicroseconds(5);
  digitalWrite(10, LOW);
  
  pinMode(10, INPUT);      
  float dur=pulseIn(10,HIGH);
  float dis= microsecondsToCentimeters(dur);
  lcd.print(dis);
  if (dis > 200)
  {
   digitalWrite(7, LOW);
   digitalWrite(8, LOW);
   digitalWrite(6, HIGH);
  }
  if (dis < 100)
  {
   digitalWrite(7, LOW);
   digitalWrite(6, LOW);
   digitalWrite(8, HIGH);
   tone(9,420,250);
   delay(500);
  }
    if (dis >= 100 && dis <=200)
  { 
    digitalWrite(8, LOW);
    digitalWrite(6, LOW);
    
    digitalWrite(7, HIGH);
    tone(9,420,500);
    delay(1000);
  }

  }
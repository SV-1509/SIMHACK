#include <Servo.h>

Servo myservo;
int pos = 0;


void setup()
{
 
  myservo.attach(9); 
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(8, INPUT);
  pinMode(4, OUTPUT);
}
void motion_detect()
{
 digitalWrite(4,HIGH);
 digitalWrite(7,LOW);  
 digitalWrite(6,HIGH);
 for (pos = 0; pos <= 180; pos += 10)
   { 
    
    myservo.write(pos);             
    delay(10);  
     
   }
  delay(5000);
  
}
void no_motion()
{
 digitalWrite(4,LOW);
 digitalWrite(6,LOW);  
 digitalWrite(7,HIGH);
 for (pos ; pos >= 0; pos -= 10)
   { 
    
    myservo.write(pos);             
    delay(10);  
     
   }
   delay(1000);
  
}
void loop()
{
   if (digitalRead(8) == HIGH)
   {
    motion_detect();
   }
  if (digitalRead(8) == LOW)
   {
    no_motion();
   }
}
#include <IRremote.h>
#include<LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int RECV_PIN = 10;

IRrecv irrecv(RECV_PIN);

decode_results results;
long a;
int b;
long p ;
int c = 0;

void setup()
{
  lcd.clear();
  lcd.begin(16, 2); 
  
  irrecv.enableIRIn(); // Start the receiver
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
}
void lcdon()
{
  lcd.setCursor(0,0);          
  lcd.print("Enter Password"); 
  lcd.setCursor(0,1); 
  
}
void ir()
{
 if (irrecv.decode(&results))
  {
     a = results.value;
     
     switch (a)
     {
      case 16593103:
       b = 0;
       break;
      case 16582903:
       b = 1;
       break;
      case 16615543:
       b = 2;
       break;
      case 16599223:
       b = 3;
       break;
      case 16591063:
       b = 4;
       break;
      case 16623703:
       b = 5;
       break;
      case 16607383:
       b = 6;
       break;
      case 16586983:
       b = 7;
       break;
      case 16619623:
       b = 8;
       break;
      case 16603303:
       b = 9;
       break;
      
     }
     p = p*10 + b;
     c++;
 
     delay(100);
    irrecv.resume(); // Receive the next value
  }
  
}
void passw( )
{
  
  if (c >= 6)
  {
    if (p == 123456)
    {
      
      lcd.print("Correct Password "); 
      digitalWrite(8,HIGH);
      delay(1000);
      digitalWrite(8,LOW);
      p=0;
      c=0;
      b=0;
      lcd.clear();
    }
    else
    {
     
      lcd.print("Incorrect Password");
      digitalWrite(9,HIGH);
      delay(1000);
      digitalWrite(9,LOW);
      p=0;
      c=0;
      b=0;
      lcd.clear();
    }
  }
  else
  {
    if(c!=0)
    {
     lcd.setCursor(c,1);
      lcd.print(b);
    }
   
  }
}
void loop()
{
  lcdon();
  ir();
  passw();
}
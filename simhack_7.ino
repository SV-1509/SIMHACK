#include<LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int a;
char s;
String w="";
String m="";
String am[38][2]={
{"A",".-"},
{"B","-..."},
{"C","-.-."},
{"D","-.."},
{"E","."},
{"F","..-."},
{"G","--."},
{"H","...."},
{"I",".."},
{"J",".---"},
{"K","-.-"},
{"L",".-.."},
{"M","--"},
{"N","-."},
{"O","---"},
{"P",".--."},
{"Q","--.-"},
{"R",".-."},
{"S","..."},
{"T","-"},
{"U","..-"},
{"V","...-"},
{"W",".--"},
{"X","-..-"},
{"Y","-.--"},
{"Z","--.."},
{"1",".----"},
{"2","..---"},
{"3", "...--"},
{"4", "....-"},
{"5","....."},
{"6","-...."},
{"7","--..."},
{"8","---.."},
{"9","----."},
{"0","-----"},
{",","--..--"},
{"?","..--.."}};

int pov(int n,int p)
{
  int ans=1;
  for(int i=1;i<=p;i++)
  {
   ans=ans*n;
  }
  return ans;
}
void lcdprint(int no)
{
  if(no!=0)
  {
   lcd.setCursor(2,1);
   lcd.print(no);
   delay(1000);
   lcd.setCursor(2,1);
   lcd.print("                ");
  }
}
void lcd_print(String str)
{

   lcd.setCursor(2,1);
   lcd.print("                "); 
   lcd.setCursor(2,1);
   lcd.print(str);
   delay(1000);
   lcd.setCursor(2,1);
   lcd.print("                ");
  
}
void setup()
{
 lcd.begin(16, 2); 
 Serial.begin(9600);
 for(int i=14;i<19;i++)
 {
  pinMode(i,INPUT);
 }
 
}
void serialin()
{
  w="";
 while (Serial.available()>0)
  {
       
    w = Serial.readString();
    
   }
  

}
void morsein()
{
  int t=0;
  m="";
  while(t==0  && digitalRead(15)!=HIGH && digitalRead(14)==HIGH)
  {
    if(digitalRead(16)==1)
    {
      m=m+".";
      delay(500);
      lcd.print(".");
    }
    if(digitalRead(17)==1)
    {
      m=m+"-";
     
      delay(500);
      lcd.print("-");
    }
    if(digitalRead(18)==1 )
    {
     t++;
   
    }
  }
}
void mce()
{
  serialin();
  
  for(int i=0;i<39;i++)
  {
   
    if (am[i][0]==w)
    {
      
     lcd_print(am[i][1]);
      break;
    }
        
  }
  
}
void mcd()
{
  morsein();
  int t=0;
  for(int i=0;i<39;i++)
  {
   
    if (am[i][1]==m)
    {
      
     lcd_print(am[i][0]);
      t=1;
      break;
    }
  }
  if(t!=1)
  {
  lcd_print("unknown");
  }
}
void be()
{  
   String bin="";
   int n=w.toInt();
   
    if (n == 0)
    {
      bin="";
    }
    else
    {     
    while (n > 0)     
        { 
            bin = ((n & 1) == 0 ? '0' : '1') + bin;  
            n >>= 1; 
        } 
    }
 lcd_print(bin);
  
}
void bd()
{
 int d = 0;
    for (int i= w.length()-1; i>=0; i--)
    {
      if (w[i] == '1') 
      {
        d=d+pov(2,(w.length()-1-i));
      }
    }
  
 lcdprint(d);
  
}
void morse()
{
  if(digitalRead(15)==HIGH)
  {
   lcd.setCursor(0,0);          
   lcd.print("MC ENCODE  "); 
   lcd.setCursor(2,1);
   mce();
  }
  else
  {
    lcd.setCursor(0,0);          
    lcd.print("MC DECODE  "); 
    lcd.setCursor(2,1);
    mcd();
  }
}
void binary()
{
  serialin();
  if(digitalRead(15)==HIGH)
  {
   lcd.setCursor(0,0);          
   lcd.print("BIN ENCODE"); 
   lcd.setCursor(2,1);
   be();
  }
  else
  {
    lcd.setCursor(0,0);          
    lcd.print("BIN DECODE"); 
    lcd.setCursor(2,1);
    bd();
  }
}
void loop()
{
  if(digitalRead(14)==HIGH)
  {
   morse();
  }
  else
  {
    binary();
  }
}
//PINS 2-4 - AND GATE
//PINS 5-7 - OR GATE
//PINS 8-10 - NAND GATE
int p[9];
void setup()
{
 
  for(int i=2;i<11;i++)
  {
    pinMode(i, INPUT);
  }
  for(int i=11;i<17;i++)
  {
    pinMode(i, OUTPUT);
  }
     
}
void read_f()
{
   for(int i=2;i<11;i++)
  {
    p[i]=digitalRead(i);
     
  }
}
void and_f()
{
  int a=p[2]*p[3]*p[4];
  if(a==1)
     {
       digitalWrite(11,HIGH);
     }
  else
  {
    digitalWrite(11,LOW);
  }
    
}
void or_f()
{
  int a=p[5]+p[6]+p[7];
  if(a>=1)
     {
       digitalWrite(12,HIGH);
     }
   else
  {
    digitalWrite(12,LOW);
  } 
}
void nand_f()
{
  int a=p[8]*p[9]*p[10];
  if(a==0)
     {
       digitalWrite(13,HIGH);
     }
  else
  {
    digitalWrite(13,LOW);
  }  
}
void loop()
{
  read_f();
  and_f();
  or_f();
  nand_f();
}
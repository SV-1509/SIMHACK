/*
A0,A1 & 0-3  segment1
A2,A3 & 4-7  segment2
A4,A5 & 8-11 segment3
*/
int count=0;
int s1=0;
int s2=0;
int s3=0;
int a[10][4]={{0,0,0,0},{0,0,0,1},{0,0,1,0},{0,0,1,1},{0,1,0,0},{0,1,0,1},{0,1,1,0},{0,1,1,1},{1,0,0,0},{1,0,0,1}};
void setup()
{
  for(int i=0;i<12;i++)
  {
    pinMode(i,OUTPUT);
  }
  for(int i=14;i<20;i++)
  {
    pinMode(i,INPUT);
  }
}
void disp(int num,int s)
{
  for (int i=s;i<s+4;i++)
  {
   digitalWrite(i,a[num][3-i+s]);
  }
}
void reset()
{
  if(count==10)
  {
   count=0;
  }
 }
void token()
{
  if(digitalRead(14)==1)
     { 
       disp(s1,0);
       if(digitalRead(15)==1)
       {
        count++;
        reset();
        s1=count;
        delay(500);
       }
      }
  else 
  	{
        for(int i=0;i<4;i++)
  		{
    		digitalWrite(i,HIGH);
  		}
     }
  if(digitalRead(16)==1)
     {
       disp(s2,4);  		
       if(digitalRead(17)==1)
       {
        count++;
        reset();
        s2=count;
        delay(500);
       }
     }
  else 
  	{
   		for(int i=4;i<8;i++)
  		{
    		digitalWrite(i,HIGH);
  		}
    }
  if(digitalRead(18)==1)
     {
       disp(s3,8); 
       if(digitalRead(19)==1)
       {
        count++;
        reset();
        s3=count;
        delay(500);
       }       	         		
     }
  else 
  	{
   		for(int i=8;i<12;i++)
  		{
    		digitalWrite(i,HIGH);
  		}
    }
}
void loop()
{    
  token(); 
}

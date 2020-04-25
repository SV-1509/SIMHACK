void setup()
{
  for (int i=1;i<9;i++)
  {
  pinMode(i, OUTPUT);
  }
}
void loop()
{
  for (int i=1;i<9;i+=2)
  {
    digitalWrite(i,HIGH);
    delay(1000);
    digitalWrite(i,LOW);
    delay(1000);
  }
  for (int i=2;i<9;i+=2)
  {
    digitalWrite(i,HIGH);
    delay(1000);
    digitalWrite(i,LOW);
    delay(1000);
  }
}
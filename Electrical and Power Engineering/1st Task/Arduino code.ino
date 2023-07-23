#define led 8
#define button 7

void setup()
{
  pinMode(button, OUTPUT);
  pinMode(led, INPUT);
}

void loop()
{
  if(digitalRead(button) ==  HIGH)
  {
    digitalWrite(led, HIGH);
  }
  else
  {
    digitalWrite(led, LOW);
  }
}
#include <Wire.h>

int btn = 5;
int btn_state = 0;

void setup()
{
  Wire.begin();
  pinMode(btn, INPUT);
}

void loop()
{
   Wire.beginTransmission(1);
   btn_state = digitalRead(btn);
   Wire.write(btn_state);
   Wire.endTransmission();
}


#include <Servo.h>

int pos = 0;
int theta = 180;

Servo servo_9;

void setup()
{
  servo_9.attach(9, 500, 2500);
}

void loop()
{
  for (pos = 0; pos <= theta; pos += 1) 
  {
    servo_9.write(pos);
    delay(15); 
  }
  for (pos = theta; pos >= 0; pos -= 1)
  {
    servo_9.write(pos);
    delay(15); 
  }
}
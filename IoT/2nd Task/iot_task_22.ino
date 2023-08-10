#include <Wire.h>

int led=13;
int led_state =0;

void setup()
{
  Wire.begin(1);
  Wire.onReceive(receiveEvent); 
  pinMode(led, OUTPUT);
}

void loop()
{
  delay(100);
}

void receiveEvent(int bytes_rec){

led_state = Wire.read();
  
  if (led_state == 1){
  
        digitalWrite(led,HIGH);
  }
  else{
        digitalWrite(led,LOW);
  }
}
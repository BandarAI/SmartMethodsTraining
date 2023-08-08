#define trig 3
#define echo 4
#define led 8

int dis = 0, t = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led, OUTPUT); 
}

void loop()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(5);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trig, LOW);

  t = pulseIn(echo, HIGH);
  dis = (t / 2) * 0.0343;

  Serial.print("Distance in CM: ");
  Serial.println(dis);

  if (dis >= 2 && dis <= 300) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
  
  delay(500);
}

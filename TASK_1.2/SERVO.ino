#include <Servo.h>

Servo myservo;

int potpin=3;
int val;

void setup()
{
  myservo.attach(11);
}

void loop()
{
  val=analogRead(potpin);
  val=map(val,0,1023,0,179);
  myservo.write(val);
  delay(15);
}

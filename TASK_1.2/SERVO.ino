#include <Servo.h>

Servo myservo;

int angle = 0;
int stepdelay 15;

void setup()
{
  myservo.attach(9);
}

void loop()
{
  for (angle = 0; angle <= 180; angle++) {
    myservo.write(angle);
    delay(stepdelay);
  }

  for (angle = 180; angle >= 0; angle--) {
    myservo.write(angle);
    delay(stepdelay);
  }
}

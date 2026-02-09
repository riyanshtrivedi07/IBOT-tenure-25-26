//IR MODULE

int irpin = A0;
void setup()
{
  pinMode(irpin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int reading = analogRead(irpin);
  Serial.println(reading);
  delay(200);
}

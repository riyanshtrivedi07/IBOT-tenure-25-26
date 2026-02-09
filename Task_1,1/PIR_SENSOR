//PIR SENSOR
const int PIRpin = 2;
const int LEDpin = 3;
void setup() {
  pinMode(PIRpin, INPUT);
  pinMode(LEDpin, OUTPUT);
}

void loop() {
  bool motion = digitalRead(PIRpin);
  if (motion == HIGH) {
    digitalWrite(LEDpin, HIGH);
  }
  digitalWrite(LEDpin, LOW);
}

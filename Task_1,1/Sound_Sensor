//SOUND_SENSOR

const int soundpin = 2;
const int LEDpin = 3;
void setup() {
  pinMode(soundpin, INPUT);
  pinMode(LEDpin, OUTPUT);
}

void loop() {
  bool sound = digitalRead(soundpin);
  digitalWrite(LEDpin,LOW);
  if (sound == HIGH) {
    digitalWrite(LEDpin, HIGH);
  }
}

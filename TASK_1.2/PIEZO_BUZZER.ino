const int buzzerpin = 3;

void setup() {
  pinMode(buzzerpin, OUTPUT);
}

void loop(){
  tone(buzzerpin, 2000);
  delay(500);

  noTone(buzzerpin);
  delay(500);
}

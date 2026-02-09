//FLAME SENSOR

const int flamepin = A0;
void setup() {
  pinMode(flamepin, INPUT);
  Serial.begin(9600);
}
void loop() {
  int reading = analogRead(flamepin);
  Serial.println(reading);
}

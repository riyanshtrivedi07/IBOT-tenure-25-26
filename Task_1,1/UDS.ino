//ULTRASONIC DISTANCE SENSOR

const int TRIG_PIN = 9;
const int ECHO_PIN = 10;

void setup() {
  pinMode(TRIG_PIN, INPUT);
  pinMode(ECHO_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delay(2);

  digitalWrite(TRIG_PIN, HIGH);
  delay(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);

  float distance = 0.0343*duration/2;

  Serial.println("Distance :");
  Serial.println(distance);
  Serial.println(" cm");

  delay(500);
}
  

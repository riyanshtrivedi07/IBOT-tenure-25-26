// LASER PROTECTION SYSTEM
//

#include <Wire.h>
#include <LiquidCrystal.h>

const int laserpin  = 9;
const int ldrpin    = 6;
const int buzzerpin = 8;

// RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);

  pinMode(ldrpin, INPUT);
  pinMode(buzzerpin, OUTPUT);
  pinMode(laserpin, OUTPUT);

  digitalWrite(laserpin, HIGH);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Laser Security System");
}

void loop() {
  int state = digitalRead(ldrpin);

  lcd.setCursor(0, 1);

  if (state == LOW) {
    // Laser detected (normal condition)
    noTone(buzzerpin);
    lcd.print("No Interference ");
  }
  else {
    // Laser interrupted (intrusion)
    tone(buzzerpin, 1000);
    lcd.print("INTRUDER ALERT ");
  }

  delay(200);
}




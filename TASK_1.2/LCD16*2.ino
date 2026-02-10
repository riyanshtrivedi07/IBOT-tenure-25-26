//LCD DISPLAY
//

#include <Wire.h>
#include <LiquidCrystal.h>

// RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2); // 16 columns, 2 rows

  lcd.setCursor(0,0);
  lcd.print("Hello World");

  lcd.setCursor(0,1);
  lcd.print("ME25B105");
}

void loop() {
}


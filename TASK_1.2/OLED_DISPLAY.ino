//OLED display
//

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1      // No reset pin
#define OLED_ADDR 0x3C     // Change if scanner shows different

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.println(F("OLED not found"));
    for (;;);
  }

  display.clearDisplay();
  display.setTextSize(1.9);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(33, 32);
  display.println("HELLO WORLD");
  display.drawRect(30, 30, 71, 11, SSD1306_WHITE);
  display.display();
}

void loop() {
}


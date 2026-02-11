#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int soundpin = A0;
int level = 0;
int smoothedLevel = 0;

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();
  Serial.begin(9600);
}

void loop() {
  int peak = 0;
  
  // Sample audio
  for (int i = 0; i < 50; i++) {
    int s = analogRead(soundpin);
    int v = abs(s - 512);
    if (v > peak) peak = v;
  }
  Serial.println(analogRead(soundpin));
  // Map peak to screen height
  level = map(peak, 0, 512, 0, SCREEN_HEIGHT);

  // Simple smoothing
  smoothedLevel = (smoothedLevel * 3 + level) / 4;

  display.clearDisplay();

  display.fillRect(
    0,
    SCREEN_HEIGHT - smoothedLevel,
    20,
    smoothedLevel,
    SSD1306_WHITE
  );

  display.display();
}

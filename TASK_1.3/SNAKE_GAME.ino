#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Buttons
#define UP     2
#define DOWN   3
#define LEFT   4
#define RIGHT  5

// Grid
#define SIZE 8
#define MAX  5   // snake length

int sx[MAX] = {8, 7, 6, 5, 4};
int sy[MAX] = {4, 4, 4, 4, 4};

int dir = 3; // 0=UP 1=DOWN 2=LEFT 3=RIGHT
unsigned long t = 0;

void setup() {
  pinMode(UP, INPUT_PULLUP);
  pinMode(DOWN, INPUT_PULLUP);
  pinMode(LEFT, INPUT_PULLUP);
  pinMode(RIGHT, INPUT_PULLUP);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
}

void loop() {
  if (digitalRead(UP) == HIGH && digitalRead(DOWN) == LOW)    dir = 0;
  if (digitalRead(DOWN) == HIGH && digitalRead(UP) == LOW)  dir = 1;
  if (digitalRead(LEFT) == HIGH && digitalRead(RIGHT) == LOW)  dir = 2;
  if (digitalRead(RIGHT) == HIGH && digitalRead(LEFT) == LOW) dir = 3;

  if (millis() - t > 300) {
    moveSnake();
    drawSnake();
    t = millis();
  }
}

void moveSnake() {
  for (int i = MAX - 1; i > 0; i--) {
    sx[i] = sx[i - 1];
    sy[i] = sy[i - 1];
  }

  if (dir == 0) sy[0]++;
  if (dir == 1) sy[0]--;
  if (dir == 2) sx[0]++;
  if (dir == 3) sx[0]--;

  if (sx[0] < 0) sx[0] = 15;
  if (sx[0] > 15) sx[0] = 0;
  if (sy[0] < 0) sy[0] = 7;
  if (sy[0] > 7) sy[0] = 0;
}

void drawSnake() {
  display.clearDisplay();
  for (int i = 0; i < MAX; i++) {
    display.fillRect(sx[i] * SIZE, sy[i] * SIZE, SIZE, SIZE, SSD1306_WHITE);
  }
  display.display();
}



#include "LedControl.h"

// Initialize the LedControl library
LedControl lc = LedControl(51, 52, 53, 1);

byte smiley[8] = {
  0b00111100,
  0b01000010,
  0b10100101,
  0b10000001,
  0b10100101,
  0b10011001,
  0b01000010,
  0b00111100
};

void setup() {
  lc.shutdown(0, false);       // Wake up the MAX7219
  lc.setIntensity(0, 1);       // Set brightness
  lc.clearDisplay(0);          // Clear display
}

void loop() {
  for(int row = 0; row < 8; row++) {
    lc.setRow(0, row, smiley[row]);
    delay(200);
  }
}

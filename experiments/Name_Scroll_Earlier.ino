#include "LedControl.h"

// Pin definitions
#define DATA_IN  12  // DIN pin
#define CLK_PIN  11   // CLK pin
#define CS_PIN   10   // LOAD pin

// Create an instance of the LEDControl class
LedControl lc = LedControl(DATA_IN, CLK_PIN, CS_PIN, 1);

// Delay time for scrolling effect (increase for slower scroll)
unsigned long scrollDelay = 150; // Slower scrolling

// Letter patterns for T, R, O, Y
byte T[8] = {
  0b11111111, 0b00011000, 0b00011000, 0b00011000,
  0b00011000, 0b00011000, 0b00011000, 0b00011000
};

byte R[8] = {
  0b11111110, 0b11000110, 0b11000110, 0b11111110,
  0b11011000, 0b11001100, 0b11000110, 0b00000000
};

byte O[8] = {
  0b00111100, 0b01100110, 0b11000011, 0b11000011,
  0b11000011, 0b01100110, 0b00111100, 0b00000000
};

byte Y[8] = {
  0b11000011, 0b11000011, 0b01100110, 0b00111100,
  0b00011000, 0b00011000, 0b00011000, 0b00011000
};

// Function to shift and display each letter smoothly
void scrollLetter(byte letter[8]) {
  for (int col = 0; col < 8; col++) {
    for (int row = 0; row < 8; row++) {
      // Shift each column one position to the left
      lc.setRow(0, row, letter[row] << col);
    }
    delay(scrollDelay);  // Delay for scrolling effect
  }
}

void setup() {
  lc.shutdown(0, false);  // Wake up the MAX72XX
  lc.setIntensity(0, 1);  // Set brightness (0 is min, 15 is max)
  lc.clearDisplay(0);     // Clear the display
}

void loop() {
  // Scroll each letter with a slight pause in between
  scrollLetter(T);
  delay(150);
  scrollLetter(R);
  delay(150);
  scrollLetter(O);
  delay(150);
  scrollLetter(Y);
  delay(150);
}

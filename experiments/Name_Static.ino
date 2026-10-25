#include "LedControl.h"

// Pin definitions
#define DATA_IN  12  // DIN pin
#define CLK_PIN  11   // CLK pin
#define CS_PIN   10   // LOAD pin

// Create an instance of the LEDControl class
LedControl lc = LedControl(DATA_IN, CLK_PIN, CS_PIN, 1);

// Delay time between each letter
unsigned long delayTime = 1000;

// Function to clear the display
void clearDisplay() {
  lc.clearDisplay(0);
}

// Function to display a letter on the LED matrix
void displayLetter(byte charData[8]) {
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, charData[i]);
  }
}

void setup() {
  lc.shutdown(0, false);  // Wake up the MAX72XX
  lc.setIntensity(0, 1);  // Set brightness (0 is min, 15 is max)
  lc.clearDisplay(0);     // Clear the display
}

void loop() {
  // "T" pattern
  byte T[8] = {
    0b11111111, // Row 0
    0b00011000, // Row 1
    0b00011000, // Row 2
    0b00011000, // Row 3
    0b00011000, // Row 4
    0b00011000, // Row 5
    0b00011000, // Row 6
    0b00011000  // Row 7
  };
  
  // "R" pattern
  byte R[8] = {
    0b11111110, // Row 0
    0b11000110, // Row 1
    0b11000110, // Row 2
    0b11111110, // Row 3
    0b11011000, // Row 4
    0b11001100, // Row 5
    0b11000110, // Row 6
    0b00000000  // Row 7
  };
  
  // "O" pattern
  byte O[8] = {
    0b00111100, // Row 0
    0b01100110, // Row 1
    0b11000011, // Row 2
    0b11000011, // Row 3
    0b11000011, // Row 4
    0b01100110, // Row 5
    0b00111100, // Row 6
    0b00000000  // Row 7
  };
  
  // "Y" pattern
  byte Y[8] = {
    0b11000011, // Row 0
    0b11000011, // Row 1
    0b01100110, // Row 2
    0b00111100, // Row 3
    0b00011000, // Row 4
    0b00011000, // Row 5
    0b00011000, // Row 6
    0b00011000  // Row 7
  };

  // Display "T"
  displayLetter(T);
  delay(delayTime);
  clearDisplay();

  // Display "R"
  displayLetter(R);
  delay(delayTime);
  clearDisplay();

  // Display "O"
  displayLetter(O);
  delay(delayTime);
  clearDisplay();

  // Display "Y"
  displayLetter(Y);
  delay(delayTime);
  clearDisplay();
}

#include "LedControl.h"

// Initialize the LedControl library
// Parameters: (DIN, CLK, CS, Number of devices)
LedControl lc = LedControl(51, 52, 53, 1);

void setup() {
  // Wake up the MAX7219
  lc.shutdown(0, false);
  
  // Set the brightness (0 is min, 15 is max)
  lc.setIntensity(0, 8);
  
  // Clear the display
  lc.clearDisplay(0);
}

void loop() {
  // Light up the first three rows with a pattern
  lc.setRow(0, 0, B11111111); // Row 0
  lc.setRow(0, 1, B11111111); // Row 1
  lc.setRow(0, 2, B11111111); // Row 2
  delay(500);
  
  // Turn off the first three rows
  lc.setRow(0, 0, B00000000);
  lc.setRow(0, 1, B00000000);
  lc.setRow(0, 2, B00000000);
  delay(500);
  
  // Light up another pattern, for example, rows 3 to 5
  lc.setRow(0, 3, B11111111); // Row 3
  lc.setRow(0, 4, B11111111); // Row 4
  lc.setRow(0, 5, B11111111); // Row 5
  delay(500);
  
  // Turn off rows 3 to 5
  lc.setRow(0, 3, B00000000);
  lc.setRow(0, 4, B00000000);
  lc.setRow(0, 5, B00000000);
  delay(500);
}

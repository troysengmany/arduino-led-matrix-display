#include <LedControl.h>

const int DIN = 51;
const int CS = 53;
const int CLK = 52;
LedControl lc = LedControl(DIN, CLK, CS, 1);

const byte T[8] = {
  B11111111,
  B00011000,
  B00011000,
  B00011000,
  B00011000,
  B00011000,
  B00011000,
  B00011000
};

const byte R[8] = {
  B11111100,
  B11000110,
  B11000110,
  B11111100,
  B11110000,
  B11011000,
  B11001100,
  B11000110
};

const byte O[8] = {
  B01111100,
  B11111110,
  B11000110,
  B11000110,
  B11000110,
  B11000110,
  B11111110,
  B01111100
};

const byte Y[8] = {
  B11000110,
  B11000110,
  B11000110,
  B01111100,
  B00111000,
  B00011000,
  B00011000,
  B00011000
};

void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, 5);
  lc.clearDisplay(0);
}

void loop() {
  scrollLetter(T);
  scrollLetter(R);
  scrollLetter(O);
  scrollLetter(Y);
}

void scrollLetter(const byte letter[8]) {
  for (int shift = 0; shift < 8; shift++) {
    lc.clearDisplay(0);
    for (int row = 0; row < 8; row++) {
      byte shifted = letter[row] << shift;
      lc.setRow(0, row, shifted);
    }
    delay(200);
  }
  delay(300); // brief pause between letters
}

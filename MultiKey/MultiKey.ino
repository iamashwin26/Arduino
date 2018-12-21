#include <Keypad.h>

const byte ROWS = 6;
const byte COLS = 6;
char customKey;
char keys[ROWS][COLS] = {
  {'0', '1', '2', '3', '4', '5'},
  {'6', '7', '8', '9', '0', 'a'},
  {'b', 'c', 'd', 'e', 'f', 'g'},
  {'h', 'i', 'j', 'k', 'l', 'm'},
  {'n', 'o', 'p', 'q', 'r', 's'},
  {'t', 'u', 'v', 'w', 'x', 'y'}
};
byte rowPins[ROWS] = {2, 3, 4, 5, 6, 7};
byte colPins[COLS] = {14, 15, 16, 17, 18, 19};

Keypad customKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


void setup() {
  Serial.begin(9600);
}

void loop() {
  customKey = customKeypad.getKey();

  if (customKey) {
    Serial.println(customKey);
  }
}

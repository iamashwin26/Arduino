const int latchPin = 5; // Shift Register controls
const int clockPin = 6; // Shift Register controls
const int dataPin = 4;  // Shift Register controls


int arr[4];
int i = 0, j = 0;
int pinmatrix[4] = {9, 10, 11, 12};
int col;


void shift(void) {
//  Serial.print("shift");
  digitalWrite(latchPin, LOW);
  digitalWrite(clockPin, LOW);
  delayMicroseconds(2);
  digitalWrite(clockPin, HIGH);
  digitalWrite(latchPin, HIGH);
  digitalWrite(clockPin, LOW);
}

void rowRead(void) {
  for (i = 0; i < 4; i++) {
    arr[i] = digitalRead(pinmatrix[i]);
  }
  Serial.print("Col:");
  Serial.print(col);
  Serial.print (" ");
  for (j = 0; j < 4; j++)
    Serial.print(arr[j]);
  Serial.println();

}
void setup() {
  // put your setup code here, to run once:
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  for (int i = 0; i < 4; i++)
    pinMode(pinmatrix[i], INPUT);
  Serial.begin(9600);

}

void loop() {
  //Set 100000 to the IC
  digitalWrite(latchPin, LOW);
  digitalWrite(clockPin, LOW);
  digitalWrite(dataPin, HIGH);
  delayMicroseconds(2);
  digitalWrite(clockPin, HIGH);
  delayMicroseconds(2);
  digitalWrite(clockPin, LOW);
  digitalWrite(dataPin, LOW);
  digitalWrite(latchPin, HIGH);

//  Serial.print("hi");
  shift();
  col = 1;
  //rowRead();
  delay(500);

  shift();
  col = 2;
  //rowRead();
  delay(500);

  shift();
  col = 3;
  //rowRead();
  delay(500);

  shift();
  col = 4;
//  rowRead();
  delay(500);


}

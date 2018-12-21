int clockpin = 3;
// Reset pins resets the couter to Q0 position. This is the MR pin. pin 15
int resetpin_1 = 4, resetpin_2 = 5;  
int rowpins[30];
int i;


bool rowdata[6];

void setup() {
  for (i = 0; i < 30; i++) rowpins[i] = i + 22;
  pinMode(clockpin, OUTPUT);
  pinMode(resetpin_1, OUTPUT);
  pinMode(resetpin_2, OUTPUT);
  for (i = 0; i < 30; i++) pinMode(rowpins[i], INPUT);
  digitalWrite(resetpin_1, HIGH);
  digitalWrite(resetpin_2, HIGH);
  digitalWrite(clockpin, LOW);

}

void loop() {
  digitalWrite(resetpin_1, LOW);
  digitalWrite(10,LOW);
  delay(500);
  for (int j = 0; j < 9; j++) {
    digitalWrite(clockpin, HIGH);
    for (i = 0; i < 30; i++) rowdata[i] = digitalRead(rowpins[i]);
    delay(100);
    digitalWrite(10,HIGH);
    delay(100);
    digitalWrite(10,LOW);
    digitalWrite(clockpin, LOW);
    delay(500);
  }
  digitalWrite(resetpin_1, HIGH);
  delay(500);
  digitalWrite(resetpin_2, LOW);
  for (int j = 0; j < 9; j++) {
    digitalWrite(clockpin, HIGH);
    for (i = 0; i < 30; i++) rowdata[i] = digitalRead(rowpins[i]);
    delay(100);
    digitalWrite(10,HIGH);
    delay(100);
    digitalWrite(10,LOW);
    digitalWrite(clockpin, LOW);
    delay(500);
  }
  digitalWrite(resetpin_2, HIGH);
  delay(500);

}

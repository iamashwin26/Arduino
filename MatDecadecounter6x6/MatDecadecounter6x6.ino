int clockpin = 3;
int resetpin = 4;  // This pin resets the couter to Q0 position. This is the MR pin. pin 15
int rowpins[6]={8,9,10,11,12,13};
int i;


bool rowdata[6];

void setup() {
  for (i = 0; i < 6; i++) rowpins[i] = i + 5;
  pinMode(clockpin, OUTPUT);
  pinMode(resetpin, OUTPUT);
  for (i = 0; i < 6; i++) pinMode(rowpins[i], INPUT);
  digitalWrite(resetpin, HIGH);
  digitalWrite(clockpin, LOW);

}

void loop() {
  digitalWrite(resetpin, LOW);
  for (int j = 0; j < 6; j++) {
    digitalWrite(clockpin, HIGH);
    for (i = 0; i < 6; i++) rowdata[i] = digitalRead(rowpins[i]);
    digitalWrite(clockpin, LOW);
    delay(50);
  }
  digitalWrite(resetpin, HIGH);
  delay(50);

}

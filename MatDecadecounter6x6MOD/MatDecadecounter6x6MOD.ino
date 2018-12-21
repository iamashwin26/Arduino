int clockpin = 3;
int resetpin = 4;  // This pin resets the couter to Q0 position. This is the MR pin. pin 15
int rowpins[6] = {A0, A1, A2, A3, A4, A5};
int i;


int rowdata[6];

void setup() {
//  for (i = 0; i < 6; i++) rowpins[i] = i + 5;
  pinMode(clockpin, OUTPUT);
  pinMode(resetpin, OUTPUT);
  for (i = 0; i < 6; i++) pinMode(rowpins[i], INPUT);
  digitalWrite(resetpin, HIGH);
  digitalWrite(clockpin, LOW);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(resetpin, LOW);
  for (int j = 0; j < 6; j++) {

    
    for (i = 0; i < 6; i++) {
      rowdata[i] = map(analogRead(rowpins[i]), 0, 1023, 0, 9);
//      rowdata[i] = digitalRead(rowpins[i]);
      delayMicroseconds(200);

    }
    digitalWrite(clockpin, HIGH);
    delayMicroseconds(200);
    for (i = 0; i < 6; i++) {
      Serial.print(rowdata[i]);
      Serial.print('*');
    }
    Serial.println();
    delayMicroseconds(20);
    digitalWrite(clockpin, LOW);
    delay(50);
  }
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println();
  digitalWrite(resetpin, HIGH);
  delay(50);

}

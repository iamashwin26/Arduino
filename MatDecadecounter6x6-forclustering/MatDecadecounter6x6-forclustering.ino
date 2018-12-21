int clockpin = 3;
int resetpin = 4;  // This pin resets the couter to Q0 position. This is the MR pin. pin 15
int rowpins[6] = {A0, A1, A2, A3, A4, A5};
int i;


int rowdata;

void setup() {
  //  for (i = 0; i < 6; i++) rowpins[i] = i + 5;
  pinMode(clockpin, OUTPUT);
  pinMode(resetpin, OUTPUT);
  for (i = 0; i < 6; i++) pinMode(rowpins[i], INPUT);
  digitalWrite(resetpin, HIGH);
  digitalWrite(clockpin, LOW);
  Serial.begin(115200);
}

void loop() {
  digitalWrite(resetpin, LOW);
  for (int j = 0; j < 6; j++) {


    for (i = 0; i < 6; i++) {
      rowdata = analogRead(rowpins[i]) / 102;
      if (rowdata > 0) {
        Serial.print('/');
        Serial.print(j + 1);
        Serial.print('*');
        Serial.print(i + 1);
        Serial.print('-');
        Serial.print(rowdata);

      }

    }

    digitalWrite(clockpin, HIGH);
    delayMicroseconds(200);

    delayMicroseconds(20);
    digitalWrite(clockpin, LOW);
    Serial.println('+');
  }
  digitalWrite(resetpin, HIGH);


}

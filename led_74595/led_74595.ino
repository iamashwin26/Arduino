#define latchPin A1
#define clockPin A0
#define dataPin A2


byte i;
byte j;

byte dataToSend;

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {

  for (i = 0; i < 4; i++) {

    for (j = 0; j < 4; j++) {

      dataToSend = (1 << (i + 4)) | (15 & ~(1 << j)); //preprare byte (series of 8 bits) to send to 74HC595
      //for example when i =2, j = 3,
      //dataToSend = (1 << 6) | (15 & ~(1 << 3));
      //dataToSend = 01000000 | (15 & ~(00001000));
      //dataToSend = 01000000 | (15 & 11110111);
      //dataToSend = 01000000 | (15 & 11110111);
      //dataToSend = 01000000 | 00000111;
      //dataToSend = 01000111;
      //the first four bits of dataToSend go to the four rows (anodes) of the LED matrix- only one is set high and the rest are set to ground
      //the last four bits of dataToSend go to the four columns (cathodes) of the LED matrix- only one is set to ground and the rest are high
      //this means that going through i = 0 to 3 and j = 0 to three with light up each led once

      // setlatch pin low so the LEDs don't change while sending in bits
      digitalWrite(latchPin, LOW);
      // shift out the bits of dataToSend to the 74HC595
      shiftOut(dataPin, clockPin, LSBFIRST, dataToSend);
      //set latch pin high- this sends data to outputs so the LEDs will light up
      digitalWrite(latchPin, HIGH);

      delay(500);//wait
    }
  }

}




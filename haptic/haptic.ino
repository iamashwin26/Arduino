#include"joint.h"

/*Declarations*/
joint bot;
joint suit;

void setup() {
  Serial.begin(9600);
  bot.init(1, 8, A1, 528, 82);
  suit.init(2, 7, A0, 508, 136);

  bot.calibrate();
  suit.calibrate();

  
}

void loop() {

  int b = bot.whatAngle();
  int s = suit.whatAngle();

  Serial.print("Suit Rotated to ");
  Serial.print(s);
  Serial.print("       bot Rotated to ");
  Serial.println(b);

  if ( (b - s) > 10 || (b - s) < -10 ) {
    suit.attachit();
    suit.rotate(b);
    delay(1000);
    suit.unattach();
  }
  else {

    bot.rotate(s - (s % 3));
  }



  //  for (int i = 0; i < 181; i++) {
  //    bot.rotate(i);
  //    Serial.print("i = ");
  //    Serial.print(i);
  //
  //    Serial.print(" ");
  //    delay(1500);
  //    Serial.println(bot.whatAngle());
  //    delay(1000);
  //  }


}

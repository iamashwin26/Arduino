#include<Servo.h>
Servo s1;
void setup() {
  // put your setup code here, to run once:
s1.attach(10);


s1.write(0);


//Serial.begin(9600);
}

void loop() {
  s1.write(0);
  delay(1000);
   s1.write(180);
delay(1000);

}

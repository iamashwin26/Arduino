#include<Servo.h>
Servo s;

void setup() {
  // put your setup code here, to run once:


}

void loop() {
  // put your main code here, to run repeatedly:
  s.attach(7);
  s.write(00);
  delay(1000);
    s.write(60);
  delay(1000);
  s.detach();
}

#include<Servo.h>
//int servoPin = 7, button = 2, pot = A0;
int servoPin = PB0, button = PB4, pot = PB5;
void clicked() {
  Servo s1;
  s1.attach(servoPin);
  s1.write(10);
  Serial.println(analogRead(pot));
  delay(1325);
  s1.write(70);
  s1.detach();
}
void setup() {
 // attachInterrupt(button,clicked,HIGH);
  pinMode(button, INPUT);
  pinMode(pot, INPUT);
  Serial.begin(9600);

}

void loop() {
  if (digitalRead(button) == HIGH)
    clicked();

}

#include<Servo.h>
int servoPin = 6;
Servo s1;
void setup() {
s1.attach(servoPin);


}

void loop() {
 s1.write(0);
 delay(1000);
 s1.write(45);
 delay(1000);
 
 s1.write(90);
 delay(1000);
 s1.write(45);
 delay(1000);

  s1.write(0);
 delay(1000);
 s1.write(180);
 delay(1000);
 
}

#include<Servo.h>

Servo futaba;
void setup() {
 Serial.begin(9600);
 futaba.attach(8);

}

void loop() {
  futaba.write(0);
  Serial.println("Rotated to angle 0 ");
  delay(2000);
  
  futaba.write(180);
  Serial.println("Rotated to angle 180 ");
  delay(2000);

}

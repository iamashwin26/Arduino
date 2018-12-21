#include<Servo.h>


inline float joint::mapfloat(long x, long in_min, long in_max, long out_min, long out_max)
{
  return (float)(x - in_min) * (out_max - out_min) / (float)(in_max - in_min) + out_min;
}
void joint::calibrate() {
  Serial.print("####Calibration started of servono=");
  Serial.println(num);
  S[num].write(langle);
  delay(3000);
  lower = analogRead(pin);
  Serial.print("Lower = ");
  Serial.println(lower);

  S[num].write(uangle);
  delay(3000);
  upper = analogRead(pin);
  Serial.print("Upper = ");
  Serial.println(upper);
  Serial.println("###End of calibration");

}
void joint::rotate(int angle) {
  S[num].write(angle);
}
void joint::attachit() {
  S[num].attach(servoPin);
}
void joint::init(int no, int xservoPin, int xAnglePin, int u, int l) {
  num = no;
  S[num].attach(xservoPin);
  pin = xAnglePin;
  servoPin = xservoPin;
  upper = u;
  lower = l;
  mean = 0;
}
void joint::init (int no, int xservoPin, int xAnglePin) {
  num = no;
  S[num].attach(xservoPin);
  pin = xAnglePin;
  upper = 470;
  lower = 114;
}

inline float joint::whatAngle() {
  /*
  int trial = 20, reject = 6;
  // int trial = 1, reject = 0;
  int aangle;
  for (int i = 0; i < 20; i++)
  {
    reading[i] = analogRead(pin);
    delay(3);
  }

  done = false;
  while (done != true) {
    done = true;
    for (int j = 0; j < trial; j++) {
      if (reading[j] > reading[j + 1]) {
        test = reading[j + 1];
        reading [j + 1] = reading[j] ;
        reading[j] = test;
        done = false;
      }
    }
  }
  mean = 0;

  for (int i = reject; i < trial - reject ; i++)
  {
    mean += reading[i];
  }
  mean /= (trial - 2 * reject);*/
  
  mean = analogRead(pin);
  
  angle = mapfloat(mean, (lower), (upper), langle, uangle);
  return (angle);

}

void joint::unattach() {
  S[num].detach();
}


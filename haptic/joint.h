#include<Servo.h>

Servo S[20];
int langle = 0, uangle = 180;

class joint {
  private:
    float  mean, reading[20], test, angle;

    boolean done;
  public:
    float upper, lower;
    int pin, num, servoPin;
    float mapfloat(long x, long in_min, long in_max, long out_min, long out_max);

    void calibrate();
    void rotate(int angle);

    void init(int no, int xservoPin, int xAnglePin, int u, int l);
    void init (int no, int xservoPin, int xAnglePin);

    float whatAngle();

    void unattach();
    void attachit();
};

int isConstricted(int x, int y) {
int t=3;
  if (      abs(x - y) > t     )
    return 0;
  else
    return 1;
}



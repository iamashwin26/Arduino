#include<Servo.h>

/*All Declarations
*/
Servo S[20];
int langle = 20, uangle = 150;

class joint {
  private:
    float upper, lower, mean, reading[20], test, angle;
    int pin, num;
    boolean done;
  public:
    float mapfloat(long x, long in_min, long in_max, long out_min, long out_max)
    {
      return (float)(x - in_min) * (out_max - out_min) / (float)(in_max - in_min) + out_min;
    }
    void calibrate() {
      Serial.println("####Calibration started");
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
    void rotate(int angle) {
      S[num].write(angle);
    }

    void init(int no, int xservoPin, int xAnglePin, int u, int l) {
      num = no;
      S[num].attach(xservoPin);
      pin = xAnglePin;
      upper = u;
      lower = l;
      mean = 0;
    }
    void init (int no, int xservoPin, int xAnglePin) {
      num = no;
      S[num].attach(xservoPin);
      pin = xAnglePin;
      upper = 470;
      lower = 114;
    }

    float whatAngle() {

      for (int i = 0; i < 20; i++)
      {
        reading[i] = analogRead(pin);
        delay(3);
      }

      done = false;
      while (done != true) {
        done = true;
        for (int j = 0; j < 20; j++) {
          if (reading[j] > reading[j + 1]) {
            test = reading[j + 1];
            reading [j + 1] = reading[j] ;
            reading[j] = test;
            done = false;
          }
        }
      }
      mean = 0;

      for (int i = 06; i < 14; i++)
      {
        mean += reading[i];
      }
      mean /= 8.0;


      angle = mapfloat(mean, (lower), (upper), langle, uangle);
      return (angle);

    }

    void unattach() {
      S[num].detach();
    }
};

joint bot;
//joint suit;
/*All  Servo Declarations
*/




void setup() {
  //  analogReference(EXTERNAL);

  Serial.begin(9600);

  bot.init(1, 7, A0, 470, 114); 
 // suit.init(2, 6, A1, 470, 114);
  bot.calibrate();
 // suit.calibrate();

}

void loop() {
bot.rotate(0);
delay(2000);
      Serial.println(bot.whatAngle());
bot.rotate(180);
delay(1500);
      Serial.println(bot.whatAngle());


    for (int i = 0; i < 181; i++) {
      bot.rotate(i);
      Serial.print("i = ");
      Serial.print(i);

      Serial.print(" ");
      delay(1500);
      Serial.println(bot.whatAngle());
      delay(1000);
    }


}

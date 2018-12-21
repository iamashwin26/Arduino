#include<Servo.h>
Servo s1;

class rotary
{
  private:
    int outputA = 6;
    int outputB = 7;
  public:
    rotary(int x, int y)
    {
      pinMode (outputA, INPUT);
      pinMode (outputB, INPUT);

      aLastState = digitalRead(outputA);

      outputA = x;
      outputB = y;
   //   angle = z;
    }
    int angle = 0;
    int aState;
    int aLastState;
    int whatAngle()
    {
      aState = digitalRead(outputA);
      if (aState != aLastState)

      {

        if (digitalRead(outputB) != aState)
        {
          angle ++;
        }
        else
        {
          angle --;
        }
        aLastState = aState;
        if (angle == 181)angle = 180;
        if (angle == -1)angle = 0;
        Serial.print("Angle: ");
        Serial.println(angle);
      }

      return angle;
    }

} r1(6, 7);





void setup()
{
  s1.attach(10);

  Serial.begin (9600);


}

void loop()
{
  for (int i = 0; i < 181; i++)

  {
    s1.write(i);
 //   delay(1000);
    r1.whatAngle();


  }



}

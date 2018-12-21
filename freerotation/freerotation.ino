#include<Servo.h>

int servoPin = A1;
Servo s1;

float mapfloat(long x, long in_min, long in_max, long out_min, long out_max)
{
  return (float)(x - in_min) * (out_max - out_min) / (float)(in_max - in_min) + out_min;
}


int servoAngle(int pin)
{
  float upper = 471, lower = 115;
  float angle, mean = 0, reading[20], test;
  boolean done;


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

  for (int k = 06; k < 14; k++)
  {
    mean += reading[k];
  }
  mean /= 8.0;


  angle = mapfloat(mean, (lower), (upper), 0, 180);

  return (angle);
}



void setup() {

  s1.attach(11);
  Serial.begin(9600);
}

void loop() {

//  for (int m = 0; m < 181; m++)
//  {
//    s1.write(m);
//    delay(1000);
//    Serial.print( "i= " );
//    Serial.print( m );
//    Serial.print( " Angle = ");
//    Serial.print( servoAngle(servoPin));
//    Serial.print( " ");
   Serial.println( servoAngle(servoPin));
//    Serial.println( );
//  }
int current=servoAngle(servoPin);
delay(30);
int next=servoAngle(servoPin);
//if(next>current)s1.write(next+5);
//if(next<current)s1.write(next+5);

if(next!=current)s1.write(next);
}

/*     >Servo With Feedback_V2<
 Testing code for servo with hacked feedback from internal pot.
 Servo control cable connected to digital 10
 Position Feedback cable connected to analog 0
 Build a voltage divider on ARef pin with two 10K resistors.
 The resulting analog reference will be ~2.2V (see http://arduino.cc/en/Reference/AnalogReference)
 This will increase the resolution of the potentiometer reading.
 Use the following commands to toggel between reading the servo feedback
   and reading any other analog pin that needs to see 5V as a reference
 analogReference(EXTERNAL); //sets analog 1023 to voltage on the ARef pin
 analogReference(DEFAULT);  //sets analog 1023 to 5V or 3.3V depending on power supply
 */
#include        //import servo library

Servo Servo1;                //declair the servo!

int feedBack;           //used to hold servo feedback value
int mappedPulse;        //used to hold the value mapped between servo range and degree range
int lowEnd;             //servo feedback at 0 degrees
int highEnd;            //servo feedback at 180 degrees
int reading[20];
int servoPin1 = 10;
int test1;               //general purpose int
int test2;
int offset = 0;
int noise = 50;

boolean rangeTest= false;

void setup() {
 
    Serial.begin(9600);   // initialize serial output
    analogReference(EXTERNAL);
    pinMode (servoPin1,OUTPUT);
    Servo1.attach(servoPin1,570,2400);       // turn on servo control at digital pin 2   
    setRange();                            //go test the range and set the values
  }
 
void loop() {
    Servo1.write(0);
    delay(2000);                       // wait for it to get there
    for (int i=0; i<181; i++){         // loop through degrees going up
      Servo1.write(i);
      delay(50);
      feedBack = getFeedback();        // subroutine smooths data
      mappedPulse = map(i,0,180,lowEnd,highEnd);  // map degrees to setRange() readings
      offset = mappedPulse - feedBack;            // resolution of mapped V actual feedback
      printData();
  }
  for (int i=180; i>0; i--){            // loop through degrees going down
      Servo1.write(i);
      delay(50);
      feedBack = getFeedback();
      mappedPulse = map(i,0,180,lowEnd,highEnd);
      offset = mappedPulse - feedBack;
      printData();
  }
}

void printData(){
    Serial.print(i);
    Serial.print("  =  ");
    Serial.print(feedBack);
    Serial.print(" ");
    Serial.print(offset);
    Serial.print(" ");
    Serial.println(mappedPulse);
}

void setRange(){
  Servo1.write(0);
  delay(2000);              //wait for servo to get there 
  lowEnd = getFeedback();
  Servo1.write(180);
  delay(2000);              //wait for servo to get there  
  highEnd = getFeedback();
  rangeTest = true;
  Serial.print("0= ");
  Serial.print(lowEnd);
  Serial.print(" ");
  Serial.print("180= ");
  Serial.println(highEnd);
 
}
 
 
int getFeedback(){
    int mean;
    int result;
    int test;
    boolean done;
     
    for (int j=0; j<20; j++){
      reading[j] = analogRead(0);    //get raw data from servo potentiometer
      delay(3);
    }                                // sort the readings low to high in array                                
    done = false;              // clear sorting flag             
    while(done != true){       // simple swap sort, sorts numbers from lowest to highest
    done = true;
    for (int j=0; j<20; j++){
      if (reading[j] > reading[j + 1]){     // sorting numbers here
        test = reading[j + 1];
        reading [j+1] = reading[j] ;
        reading[j] = test;
        done = false;
       }
     }
   }
    mean = 0;
    for (int k=6; k<14; k++){        //discard the 6 highest and 6 lowest readings
      mean += reading[k];
    }
    result = mean/8;                  //average useful readings
    return(result);
}
// END SERVO_WITH_FEEDBACK_V2


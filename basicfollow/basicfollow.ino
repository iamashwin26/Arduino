
#include <Servo.h>

Servo myservo1; 
Servo myservo2;  
int potpin1 = A1;  
int potpin2 = A0; 
int val1;    
int val2;
void setup()
{
  Serial.begin(9600);
 // myservo1.attach(7);  
  myservo1.attach(8);
}

void loop()
{

//val1=analogRead(potpin1);                
//val1=constrain(val1,15,626);             
//val1=map(val1,15,626, 0,180);             
//myservo2.write(val1);                      
//delay(500);                              
val2=analogRead(potpin2);                    
val2=constrain(val2,76,590);                 
val2=map(val2,76,590, 0,180);
myservo1.write(val2);                      
delay(500);       
}


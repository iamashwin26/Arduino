int t=3000;
void leftc()
{
  digitalWrite(7,HIGH);
   digitalWrite(8,LOW);
}
void lefta()
{
  
   digitalWrite(7,LOW);
   digitalWrite(8,HIGH);
  }



void rightc()
{
  digitalWrite(6,HIGH);
   digitalWrite(5,LOW);
}
void righta()
{
  
   digitalWrite(6,LOW);
   digitalWrite(5,HIGH);
  }
void setup() {
  // put your setup code here, to run once:
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
  

}

void loop() {

rightc();
leftc();
delay(t);
 righta();
 lefta();
  delay(t);
rightc();

delay(t);
}

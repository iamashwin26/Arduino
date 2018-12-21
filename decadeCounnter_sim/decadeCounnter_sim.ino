int mr=11,clk=12;
void setup() {
  pinMode(clk,OUTPUT);
    pinMode(mr,OUTPUT);

}

void loop() {
  //set 1
  digitalWrite(mr,HIGH);
  delayMicroseconds(10);
  digitalWrite(mr,LOW);
 while(true){
  delay(1000);
    digitalWrite(clk,HIGH);
  delay(1000);
  digitalWrite(mr,LOW);
  
  }

}

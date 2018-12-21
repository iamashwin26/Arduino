
//Components

struct Wheel{
  int x,y;
  char dirn;
  void setWheel(int i,int j)
    {
      pinMode(i,OUTPUT);
      pinMode(j,OUTPUT);
      x=i;y=j;
    }
  void runWheel(char dirn)
    {
      if(dirn=='f')
      {
      digitalWrite(x,HIGH); 
      digitalWrite(y,LOW);
      }
      else
      if(dirn=='b')
      {
        digitalWrite(x,LOW);
        digitalWrite(y,HIGH);
      }
      else
      if(dirn=='n')
      {
        digitalWrite(x,LOW);
        digitalWrite(y,LOW);
      }
    }      
};

class IRSensor
{
private:
  int i,o;

public:
  void Setup(int pinIn,int pinOut)    
  {
    i=pinIn;
    o=pinOut;
    pinMode(i,INPUT);  
    pinMode(o,OUTPUT);
    digitalWrite(o,HIGH);
  }

  bool GetsObs()
  {
    if(digitalRead(i)==0)
    {
      return false;
    }
    if(digitalRead(i)==1)
    {
      return true;
    }
  }
};

class Car
{
private:
  Wheel Left,Right;
  bool isStarted=false;
  int n;
public:
  IRSensor IR1,IR2;
  void Setup(int Left0,int Left1,int Right0,int Right1,int IR1_1,int IR1_2,int IR2_1,int IR2_2)
  {
     Left.setWheel(Left0,Left1);
     Right.setWheel(Right0,Right1);
     IR1.Setup(IR1_1,IR1_2);
     IR2.Setup(IR2_1,IR2_2);
     isStarted=true;
     n=0;
  }

  void Count(int N)
  {
    if(n>=N)
    {
      isStarted=false;
    }
    n++;
  }

  void MoveUp(int t) const
  {
    if(isStarted)
    {
     Left.runWheel('f');
     Right.runWheel('f');
     digitalWrite(4,HIGH);
     delay(t);
     digitalWrite(4,LOW);
    }
    else DoNothing();
  }

  void MoveDown(int t) const
  {
    if(isStarted)
    {
     Left.runWheel('b');
     Right.runWheel('b');
     delay(t);
    }
    else DoNothing();
  }

  void TurnRight(int degree) const
  {
    float t= (degree/3)* 52;
    if(isStarted)
    {    
     Left.runWheel('f');
     Right.runWheel('b');
     digitalWrite(3,HIGH);
     delay(t);
     digitalWrite(3,LOW);
    }
    else DoNothing();
  }

  void TurnLeft(int degree) const
  {
    float t=(degree/3)*46;
    if(isStarted)
    {
     Left.runWheel('b');
     Right.runWheel('f');
     pinMode(2,OUTPUT);
     digitalWrite(2,HIGH);
     delay(t);
     digitalWrite(2,LOW);
    }
    else DoNothing();
  }

  void DoNothing() const
  {
      Left.runWheel('n');
      Right.runWheel('n');
  }

    void DoNothing(int t) const
  {
      DoNothing();
      delay(t);
  }

  void FollowBlackLine()
  {
    if(IR1.GetsObs()&&IR2.GetsObs())
    {
      MoveUp(1);
    }
    else
    if(!IR1.GetsObs())
    {
      TurnRight(1);
    }
    else
    if(!IR2.GetsObs())
    {
      TurnLeft(1);
    }
  }

  void FollowMe()
  {
    if(IR1.GetsObs()&&IR2.GetsObs())
    {
      MoveUp(1);
    }
        else 
    if(!IR1.GetsObs()&&!IR2.GetsObs())
    {
      DoNothing();
    }
    else
    if(!IR1.GetsObs())
    {
      TurnRight(1);
    }
    else
    if(!IR2.GetsObs())
    {
      TurnLeft(1);
    }
  }

  void FollowWallRight()
  {
    if(!IR1.GetsObs())
    {
      MoveUp(1);
      TurnRight(1);
    }
    if(!IR2.GetsObs())
    {
      TurnRight(1);
    }
    else 
    TurnLeft(1);

  }
  void FollowWallLeft()
  {
    if(!IR2.GetsObs())
    {
      MoveUp(1);
      TurnLeft(1);
    }
    else 
    TurnRight(1);

  }

  void RunAwayFromMe()
  {
    if(IR1.GetsObs()&&IR2.GetsObs())
    {
      MoveDown(1);
    }
        else 
    if(!IR1.GetsObs()&&!IR2.GetsObs())
    {
      MoveUp(1);
    }
    else
    if(!IR1.GetsObs())
    {
      TurnLeft(1);
    }
    else
    if(!IR2.GetsObs())
    {
      TurnRight(1);
    }
  }
};



//Main Logic

Car car;


void setup() {
  car.Setup(7,8,6,5,13,A0,12,A1);

}

void loop() {

 car.FollowWallRight();
}

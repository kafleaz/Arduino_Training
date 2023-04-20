#include <SoftwareSerial.h>
#define i1 3
#define i2 4
#define i3 5
#define i4 6
char command;

class motor
{
  private:
  int pin1;
  int pin2;
  int pin3;
  int pin4;

  public:
  motor (int m1,int m2, int m3, int m4)
  {
    this -> pin1=m1;
    this -> pin2= m2;
    this -> pin3= m3;
    this -> pin4= m4;
  }
  void stop()
  {
    digitalWrite(i1, LOW);
    digitalWrite(i2, LOW);
    digitalWrite(i3, LOW);
    digitalWrite(i4, LOW);
  }

  void front()
  {
    digitalWrite(i1, HIGH);
    digitalWrite(i2, LOW);
    digitalWrite(i3, HIGH);
    digitalWrite(i4, LOW);
  }

  void back()
  {
    digitalWrite(i1, LOW);
    digitalWrite(i2, HIGH);
    digitalWrite(i3, LOW);
    digitalWrite(i4, HIGH);
  }
  void left()
  {
    digitalWrite(i1, LOW);
    digitalWrite(i2, HIGH);
    digitalWrite(i3, HIGH);
    digitalWrite(i4, LOW);
  }
  void right()
  {
    digitalWrite(i1, HIGH);
    digitalWrite(i2, LOW);
    digitalWrite(i3, LOW);
    digitalWrite(i4, HIGH);
  }
  void set()
  {
    pinMode(i1,OUTPUT);
    pinMode(i2,OUTPUT);
    pinMode(i3,OUTPUT);
    pinMode(i4,OUTPUT);
  }
};
motor m(i1,i2,i3,i4);

void setup() 
{
  Serial.begin(9600);
  m.set();
  
  // put your setup code here, to run once:
}
void loop()
{
  if(Serial.available())
  {
    command = Serial.read();
    switch(command)
    {
      case 'F':
        m.front();
        break;

      case 'B':
        m.back();
        break;

      case 'L':
        m.left();
        break;

      case 'R':
        m.right();
        break;

      case 'S':
        m.stop();
    }
  }
}

// void front()
// {
//   digitalWrite(i1, HIGH);
//   digitalWrite(i2, LOW);
// }
// void back()
// {
//   digitalWrite(i1, LOW);
//   digitalWrite(i2, HIGH);
// }

// void loop() 
// {
//   front();
//   delay(2000);
//   back();
//   delay(1000);

//   // put your main code here, to run repeatedly:
// }


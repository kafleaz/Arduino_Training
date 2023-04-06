#include <AFMotor.h>
#include <SoftwareSerial.h>
#include<Servo.h>

AF_DCMotor m1(1); 
AF_DCMotor m2(2); 
AF_DCMotor m3(3);
AF_DCMotor m4(4);
SoftwareSerial myserial(A0,A1); //A0=rx A1=tx

char command;
int speed1;
int angle=90;
Servo myservo;

void setup() {

  myserial.begin(9600);
  // put your setup code here, to run once:
  pinMode(A2, OUTPUT); // Front Light
  pinMode(A3, OUTPUT); // BAck Light
  pinMode(A4, OUTPUT); // Horn
  myservo.attach(9);
  

}

void loop() 
{

  // put your main code here, to run repeatedly:
  myservo.write(angle);
  if(myserial.available())
  {
    command = myserial.read();

    switch(command)
    {
      case '1':
        speed1 = 255 * 0.1;
        break;

      case '2':
        speed1 = 255 * 0.2;
        break;

      case '3':
        speed1 = 255 * 0.3;
        break;

      case '4':
        speed1 = 255 * 0.4;
        break;

      case '5':
        speed1 = 255 * 0.5;
        break;

      case '6':
        speed1 = 255 * 0.6;
        break;

      case '7':
        speed1 = 255 * 0.7;
        break;

      case '8':
        speed1 = 255 * 0.8;
        break;

      case '9':
        speed1 = 255 * 0.9;
        break;

      case 'F':
        forward(speed1);
        break;

      case 'B':
        back(speed1);
        break;

      case 'L':
        left(speed1);
        break;

      case 'R':
        right(speed1);
        break;

      case 'G':
        forward_left(speed1);
        break;

      case 'I':
        forward_right(speed1);
        break;
      
      case 'H':
        back_left(speed1);
        break;

      case 'J':
        back_right(speed1);
        break;

      case 'W':
        digitalWrite(A2, HIGH);
        break;

      case 'w':
        digitalWrite(A2, LOW);
        break;

      case 'U':
        digitalWrite(A3, HIGH);
        break;

      case 'u':
        digitalWrite(A3, LOW);
        break;

      case 'V':
        digitalWrite(A4, HIGH);
        break;

      case 'v':
        digitalWrite(A4, LOW);
        break;

      case 'S':
        stop();    
        break;

      case 'D':
        stop();
        break;

      case 'X':
        angle=180;
        break;

      case 'x':
        angle=90;
        break;

      default:
        stop();    
    }
  }

}

void forward(int speed)
{
  setSpeed(speed);
  m1.run(FORWARD);
  m2.run(FORWARD);
  m3.run(FORWARD);
  m4.run(FORWARD);
}

void back(int speed)
{
  setSpeed(speed);
  m1.run(BACKWARD);
  m2.run(BACKWARD);
  m3.run(BACKWARD);
  m4.run(BACKWARD);
}

void left(int speed)
{
  setSpeed(speed);
  m1.run(BACKWARD);
  m2.run(BACKWARD);
  m3.run(FORWARD);
  m4.run(FORWARD);
}

void right(int speed)
{
  setSpeed(speed);
  m1.run(FORWARD);
  m2.run(FORWARD);
  m3.run(BACKWARD);
  m4.run(BACKWARD);
}

void forward_right(int speed)
{
  f_r_setSpeed(speed);
  m1.run(FORWARD);
  m2.run(FORWARD);
  m3.run(FORWARD);
  m4.run(FORWARD);
}

void forward_left(int speed)
{
  f_l_setSpeed(speed);
  m1.run(FORWARD);
  m2.run(FORWARD);
  m3.run(FORWARD);
  m4.run(FORWARD);
}

void back_left(int speed)
{
  b_l_setSpeed(speed);
  m1.run(BACKWARD);
  m2.run(BACKWARD);
  m3.run(BACKWARD);
  m4.run(BACKWARD);
}

void back_right(int speed)
{
  b_r_setSpeed(speed);
  m1.run(BACKWARD);
  m2.run(BACKWARD);
  m3.run(BACKWARD);
  m4.run(BACKWARD);
}

void stop()
{
  m1.run(RELEASE);
  m2.run(RELEASE);
  m3.run(RELEASE);
  m4.run(RELEASE);
}

void setSpeed(int speed)
{
  m1.setSpeed(speed);
  m2.setSpeed(speed);
  m3.setSpeed(speed);
  m4.setSpeed(speed);
}

void f_l_setSpeed(int speed) //Front left speed set
{
  m1.setSpeed(100);
  m2.setSpeed(100);
  m3.setSpeed(speed);
  m4.setSpeed(speed);
}

void f_r_setSpeed(int speed) //Front right speed set
{
  m1.setSpeed(speed);
  m2.setSpeed(speed);
  m3.setSpeed(100);
  m4.setSpeed(100);
}

void b_r_setSpeed(int speed) //Back right speed set
{
  m1.setSpeed(speed);
  m2.setSpeed(speed);
  m3.setSpeed(100);
  m4.setSpeed(100);
}

void b_l_setSpeed(int speed) //Back left speed set
{
  m1.setSpeed(100);
  m2.setSpeed(100);
  m3.setSpeed(speed);
  m4.setSpeed(speed);
}

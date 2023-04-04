 #include<AFMotor.h>
#include<Servo.h>
AF_DCMotor m1(1), m2(2), m3(3), m4(4);
int trig = A0;
int echo = A1;
float time_taken, distance, data;
int mind = 60;
char s;
int dist_L, dist_R, dist_F;

Servo myservo;
int pos = 0; //to store servo position

void setup()
{
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  myservo.attach(9); // pin 9 is connected to servo 2 &(10 to 1)
  s = 100;
}
void front(int speed)
{
  setSpeed(speed);
  m1.run(FORWARD);
  m2.run(FORWARD);
  m3.run(BACKWARD);
  m4.run(FORWARD);
}
void left(int speed)
{
  setSpeed(speed);
  m2.run(FORWARD);
  m1.run(FORWARD);
  m3.run(FORWARD);
  m4.run(BACKWARD);
}
void right(int speed)
{
  setSpeed(speed);
  m1.run(BACKWARD);
  m2.run(BACKWARD);
  m3.run(BACKWARD);
  m4.run(FORWARD);
}
void back(int speed)
{
  setSpeed(speed);
  m1.run(BACKWARD);
  m2.run(BACKWARD);
  m3.run(FORWARD);
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

void loop()
{
  dist_F= Sen_Data(); //dist= distance
  Serial.println(dist_F);

  if(dist_F> mind)  
  {
    front(s);
  }
  else 
  {
    servR();
  }
}

float Sen_Data() //data from sensor
{
  digitalWrite(trig,HIGH);
  delay(50);
  digitalWrite(trig,LOW);
  time_taken = pulseIn(echo, HIGH);
  distance = 0.017 * time_taken;
  return(distance);
}

void comp_dist() //Distance Comparision
{
  if(dist_L> dist_R)
  {
    left(s);
  }
  else if( dist_R > dist_L)
  {
    right(s);
  }
  else
  {
    back(s);
    delay(200);
    left(s);
  }
}

void servR() //servo rotation
{
  stop();

  myservo.write(0);
  delay(200);
  right(200);//right
  delay(100);  
  myservo.write(170);
  delay(200);
  left(200); //left
  delay(200);
  myservo.write(90);
  delay(200);
  comp_dist();
  

  }





  
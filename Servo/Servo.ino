
#include<Servo.h>
Servo myservo;
void setup() {
  myservo.attach(9);
  // put your setup code here, to run once:

}

void loop() {
  myservo.write(180);
  delay(2000);
  myservo.write(0);
  delay(1000);
  // put your main code here, to run repeatedly:
  

}

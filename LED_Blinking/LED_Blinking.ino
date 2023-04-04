void setup() {
  pinMode(11, OUTPUT);// put your setup code here, to run once:
  //pinMode(12,OUTPUT);
  //pinMode(13,OUTPUT);

}

void loop() {

  for(int i=0; i<255; i=i+5)
  {
    analogWrite(11,i);
    delay(20);

      for(int i=255; i>2; i=i-5)
    {
      analogWrite(9,i);
      delay(20);
        
    }
      for(int i=0; i<255; i=i+5)
    {
      analogWrite(10,i);
      delay(10);
    }
    for(int i=255; i>2; i=i-5)
  {
    analogWrite(11,i);
    delay(10);
  }

  }
}
  /*digitalWrite(13,1);// put your main code here, to run repeatedly:
  delay(1000);
  digitalWrite(13,0);
  delay(500);
  

  digitalWrite(12,1);
  delay(1000);
  digitalWrite(12,0);
  delay(500);

  digitalWrite(11,1);
  delay(1000);
  digitalWrite(11,0);
  delay(1000);
}
*/

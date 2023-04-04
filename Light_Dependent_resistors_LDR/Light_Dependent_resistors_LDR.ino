void setup() {
  // put your setup code here, to run once:
  pinMode(A1, INPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  int value=analogRead(A1);
  Serial.println(value);

  if(value<5)
  {
    digitalWrite(11,HIGH);
  }
  else
  {
    digitalWrite(11,LOW);
  }

}

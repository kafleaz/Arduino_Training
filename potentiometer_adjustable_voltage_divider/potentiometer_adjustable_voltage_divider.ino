
#define led_pin 11
#define potMt_pin A1

void setup() {
  Serial.begin(9600);
  pinMode(11, OUTPUT);// put your setup code here, to run once:

}

void loop() {
  int val = analogRead(potMt_pin);
  // int ledval= map (val, 0, 1023, 0, 255);
  int ledval= map (val, 0, 1023, 0, 180);
  analogWrite(led_pin, ledval);
  // int pot_MtVal= analogRead(A1);
  // int bright= pot_MtVal/4;
  // analogWrite(11, bright);// put your main code here, to run repeatedly:
  Serial.println(ledval);
  // delay(100);
}

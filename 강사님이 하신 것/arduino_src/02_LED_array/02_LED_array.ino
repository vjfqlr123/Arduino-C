int pinLed[8] = {12,11,10,9,8,7,6,5};

void setup() {
  // put your setup code here, to run once:
  int i=0;
  for(i=0; i<8; i++){
    pinMode(pinLed[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int i=0;
  for(i=0; i<8; i++)
  {
    digitalWrite(pinLed[i], HIGH);     // LED ON
  }
  delay(1000);
  for(i=0; i<8; i++)
  {
    digitalWrite(pinLed[i], LOW);     // LED OFF
  }
  delay(1000);
}

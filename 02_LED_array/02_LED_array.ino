int apinLed[8] = {12, 11, 10, 9, 8, 7, 6, 5};

void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i<8; ++i)
  {
      pinMode(apinLed[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int i;
  for(i = 0; i<8; ++i)
  {
    digitalWrite(apinLed[i], HIGH);   // LED ON
    delay(1000);
  }
  delay(1000);
  for(i = 0; i<8; ++i)
  {
    digitalWrite(apinLed[i], LOW);   // LED OFF
    delay(100);
  }
  delay(1000);
}

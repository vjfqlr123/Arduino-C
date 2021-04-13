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
  for(i = 0; i<4; ++i)    // 왼쪽에서 오른쪽으로
  {
    digitalWrite(apinLed[i], HIGH);   // LED ON
    digitalWrite(apinLed[i+4], HIGH);   // LED ON
    delay(1000);
    digitalWrite(apinLed[i], LOW);    // LED OFF
    digitalWrite(apinLed[i+4], LOW);   // LED OFF
  }
  for(i = 2; i>0; --i)    // 오른쪽에서 왼쪽으로
  {
    digitalWrite(apinLed[i], HIGH);   // LED ON
    digitalWrite(apinLed[i+4], HIGH);   // LED ON
    delay(1000);
    digitalWrite(apinLed[i], LOW);    // LED OFF
    digitalWrite(apinLed[i+4], LOW);   // LED OFF
  }
  
}

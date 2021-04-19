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
  int i = 0;
  
  // 왼쪽에서 오른쪽으로
  for(i=0; i<4; i++){
    digitalWrite(pinLed[i], HIGH);
    digitalWrite(pinLed[i+4], HIGH);
    delay(1000);
    digitalWrite(pinLed[i], LOW);
    digitalWrite(pinLed[i+4], LOW);
  }

  // 오른쪽에서 왼쪽으로
  for(i=2; i>0; i--){
    digitalWrite(pinLed[i], HIGH);
    digitalWrite(pinLed[i+4], HIGH);
    delay(1000);
    digitalWrite(pinLed[i], LOW);
    digitalWrite(pinLed[i+4], LOW);
  }
}

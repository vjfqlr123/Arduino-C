int pinLed0 = 12;
int pinLed1 = 11;

void setup() {       // 초기화
  // put your setup code here, to run once:
  pinMode(pinLed0, OUTPUT);     // 12번 핀을 출력으로 설정
  pinMode(pinLed1, OUTPUT);     // 11번 핀을 출력으로 설정
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pinLed0, HIGH);  // 13번 핀에 HIGH 값을 출력.(5V)
  digitalWrite(pinLed1, HIGH);
  delay(50);                 // 1000ms(1초) 동안 지연
  digitalWrite(pinLed0, LOW);   // 13번 핀에 LOW 값을 출력.(0V)
  digitalWrite(pinLed1, LOW);
  delay(50);                 // 1000ms(1초) 동안 지연
}

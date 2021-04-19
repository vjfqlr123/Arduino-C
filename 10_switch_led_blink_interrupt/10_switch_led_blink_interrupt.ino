// SW0번을 누르면 LED0의 OFF/BLINK(점멸) 0.5초마다
// SW1번을 누르면 LED0의 OFF/BLINK(점멸) 0.5초마다

// 스위치 할당
int pinswitch0 = 2;
int pinswitch1 = 3;

// LED 할당
int pinled0 = 12;
int pinled1 = 11;

// LED 상태
boolean led0_state = false;
boolean led1_state = false;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);       //시리얼 설정

  // 스위치 설정
  pinMode(pinswitch0, INPUT);
  pinMode(pinswitch1, INPUT);

  // LED 설정
  pinMode(pinled0, OUTPUT);
  pinMode(pinled1, OUTPUT);

  // interrupt 상승엣지
  attachInterrupt(digitalPinToInterrupt(pinswitch0), led0_state_change, RISING);
  attachInterrupt(digitalPinToInterrupt(pinswitch1), led1_state_change, RISING);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  // 상태값에 따른 구현
  if(led0_state==false) {
    digitalWrite(pinled0, LOW);
  }else {
    digitalWrite(pinled0, HIGH);
    delay(500);
    digitalWrite(pinled0, LOW);
    delay(500);
  }
  // 상태값에 따른 구현
  if(led1_state==false) {
    digitalWrite(pinled1, LOW);
  }else {
    digitalWrite(pinled1, HIGH);
    delay(300);
    digitalWrite(pinled1, LOW);
    delay(300);
  }
}

void led0_state_change() {
  // LED0의 상태값 변경
  if(led0_state == false) {
  led0_state = true;
  }
  else {
  led0_state = false;
  }
  Serial.println("Pushed SW0");
}

void led1_state_change() {
  // LED1의 상태값 변경
  if(led1_state == false) {
  led1_state = true;
  }
  else {
  led1_state = false;
  }
  Serial.println("Pushed SW1");
}

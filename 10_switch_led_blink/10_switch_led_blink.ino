// SW0번을 누르면 LED0의 OFF/BLINK(점멸) 0.5초마다

// 스위치 할당
int pinswitch0 = 2;

// LED 할당
int pinled0 = 12;

// LED 상태
boolean led0_state = false;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);       //시리얼 설정

  // 스위치 설정
  pinMode(pinswitch0, INPUT);

  // LED 설정
  pinMode(pinled0, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  if(digitalRead(pinswitch0)) {     // 레벨체크
    
    // LED0의 상태값 변경
    if(led0_state == false) {
      led0_state = true;
    }
    else {
      led0_state = false;
    }
  }

// 상태값에 따른 구현
  if(led0_state==false) {
    digitalWrite(pinled0, LOW);
  }
  else {
    digitalWrite(pinled0, HIGH);
    delay(500);
    digitalWrite(pinled0, LOW);
    delay(500);
  }

}

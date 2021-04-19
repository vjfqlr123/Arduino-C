// 'A'를 입력하면, LED0 ON/OFF
// 'B'를 입력하면, LED1 ON/OFF

// 헤더파일 선언

// 전역변수 선언
int pinLed0 = 12;
int pinLed1 = 11;
boolean led0_state = false;   // flase:LED OFF, true:LED ON
boolean led1_state = false;

// 사용자 함수 선언

void setup() {
  // put your setup code here, to run once:
  // 시리얼 통신 설정
  Serial.begin(115200);    // Serial.begin(speed, config)

  // LED 설정
  pinMode(pinLed0, OUTPUT);
  pinMode(pinLed1, OUTPUT);

  // 사용자 코드
  Serial.println("Serial LED Control !!");
  Serial.print("IN >> ");
}

void loop() {
  // put your main code here, to run repeatedly:
  char data;
  if(Serial.available() > 0)    // 수신된 데이터가 있으면, 수신 데이터의 갯수를 반환
  {
    data = Serial.read();       // 수신된 데이터를 읽기
    Serial.write(data);         // 데이터를 다시 PC로 송신
    
    // LED0 제어
    if(data == 'A'){
      if(led0_state==false){    // LED가 꺼져있을 때
        digitalWrite(pinLed0, HIGH);
        led0_state = true;
      }else{                   // LED가 켜져있을 때
        digitalWrite(pinLed0, LOW);
        led0_state = false;
      }
    }

    // LED1 제어
    if(data == 'B'){
      if(led1_state==false){    // LED가 꺼져있을 때
        digitalWrite(pinLed1, HIGH);
        led1_state = true;
      }else{                   // LED가 켜져있을 때
        digitalWrite(pinLed1, LOW);
        led1_state = false;
      }
    }
  }
}

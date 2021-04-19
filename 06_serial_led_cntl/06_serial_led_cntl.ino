// A를 입력하면, LED0을 ON/OFF
// B를 입력하면, LED1을 ON/OFF

// 전역변수 선언
int pinLed0 = 12;
int pinLed1 = 11;
boolean led0_state = false;    // flase:LED OFF, true:LED ON
boolean led1_state = false;    // flase:LED OFF, true:LED ON

void setup() {
  // put your setup code here, to run once:
  // 시리얼 통신 설정
  Serial.begin(115200);
  Serial.println("serial LED control !!");
  Serial.print("IN >> ");
  // LED 설정
  pinMode(pinLed0, OUTPUT);
  pinMode(pinLed1, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  char data;
  
  if(Serial.available() > 0)    // 수신된 데이터가 있으면, 수신 데이터의 갯수를 반환
  {
    data = Serial.read();       // 수신된 데이터를 읽기
    Serial.write(data);         // 데이터를 다시 pc로 송신

    if(data == 'A')            // LED0번제어
    {
      if(led0_state==false)
      {
        digitalWrite(pinLed0, HIGH);    //LED가 꺼져있을 때
        led0_state = true;
      }
      else
      {
        digitalWrite(pinLed0, LOW);     // LED가 켜져있을 때
        led0_state = false;
      }
    }
    
     if(data == 'B')            // LED1번제어
    {
      if(led1_state==false)
      {
        digitalWrite(pinLed1, HIGH);    //LED가 꺼져있을 때
        led1_state = true;
      }
      else
      {
        digitalWrite(pinLed1, LOW);     // LED가 켜져있을 때
        led1_state = false;
      }
    }
  }
}

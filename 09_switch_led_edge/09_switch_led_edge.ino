// 스위치0번을 누를때마다 LED0번을 ON/OFF
// 스위치1번을 누를때마다 LED1번을 ON/OFF

int pinswitch0 = 2;

int pinled0 = 12;

boolean led0_state = false;    // flase:LED OFF, true:LED ON

boolean pre_value = LOW, cur_value = LOW;    // 이전값, 현재값

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);       //시리얼 설정
  
  pinMode(pinswitch0, INPUT);    // 스위치0번 설정
  
  pinMode(pinled0, OUTPUT);      // LED0번 설정
}

void loop() {
  // put your main code here, to run repeatedly:
  cur_value = digitalRead(pinswitch0);      // 현재값을 읽어서 저장
  
  if(pre_value==HIGH && cur_value==LOW) {     // 하강엣지체크 
    if(led0_state==false)
    {
      digitalWrite(pinled0, HIGH);    //LED가 꺼져있을 때
      led0_state = true;
    }
    else
    {
      digitalWrite(pinled0, LOW);     // LED가 켜져있을 때
      led0_state = false;
    }
    Serial.println("Pushed SW0");
    //delay(500);
  }

  // 현재값을 이전값에 저장
  pre_value = cur_value;
}

// SW0을 누르면 LED0의 OFF/BLINK(점멸) 0.5초마다 
// SW1을 누르면 LED1의 OFF/BLINK(점멸) 0.3초마다 

// 핀 할당
int pinLed0 = 12;  // LED0
int pinLed1 = 11;  // LED1
int pinSwitch0 = 2;
int pinSwitch1 = 3;
boolean led0_state = false;
boolean led1_state = false;

void setup() {
  // put your setup code here, to run once:
  // 시리얼 설정
  Serial.begin(115200);
  
  // LED 설정
  pinMode(pinLed0, OUTPUT);
  pinMode(pinLed1, OUTPUT);
    
  // Switch 설정
  pinMode(pinSwitch0, INPUT);
  pinMode(pinSwitch1, INPUT);
  attachInterrupt(digitalPinToInterrupt(pinSwitch0),led0_state_change,RISING);
  attachInterrupt(digitalPinToInterrupt(pinSwitch1),led1_state_change,RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
  // 상태값에 따른 구현
  if(led0_state==false){
    digitalWrite(pinLed0, LOW);
  }else{
    digitalWrite(pinLed0, HIGH);
    delay(500);
    digitalWrite(pinLed0, LOW);
    delay(500);
  }
  
  if(led1_state==false){
    digitalWrite(pinLed1, LOW);
  }else{
    digitalWrite(pinLed1, HIGH);
    delay(300);
    digitalWrite(pinLed1, LOW);
    delay(300);
  }
}

void led0_state_change(){
  // LED0의 상태값 변경
  if(led0_state==false){    // LED가 꺼져있을 때
    led0_state = true;
  }else{                   // LED가 켜져있을 때
    led0_state = false;
  }
  Serial.println("Pushed SW0");
}

void led1_state_change(){
  // LED1의 상태값 변경
  if(led1_state==false){    // LED가 꺼져있을 때
    led1_state = true;
  }else{                   // LED가 켜져있을 때
    led1_state = false;
  }
  Serial.println("Pushed SW1");
}

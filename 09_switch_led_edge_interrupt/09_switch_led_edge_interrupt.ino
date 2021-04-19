// 스위치0번을 누를때마다 LED0번을 ON/OFF

int pinswitch0 = 2;
int pinswitch1 = 3;

int pinled0 = 12;
int pinled1 = 11;

boolean led0_state = false;    // flase:LED OFF, true:LED ON
boolean led1_state = false;    // flase:LED OFF, true:LED ON

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);       //시리얼 설정
  
  pinMode(pinswitch0, INPUT);    // 스위치 설정
  pinMode(pinswitch1, INPUT);
  
  pinMode(pinled0, OUTPUT);      // LED 설정
  pinMode(pinled1, OUTPUT);
  
  attachInterrupt(digitalPinToInterrupt(pinswitch0), led0_state_change, RISING);
  attachInterrupt(digitalPinToInterrupt(pinswitch1), led1_state_change, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
}

void led0_state_change() {      // 스위치가 눌렸을 때 해야 할 동작을 구현(ISR)
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
}

void led1_state_change() {      // 스위치가 눌렸을 때 해야 할 동작을 구현(ISR)
  if(led1_state==false)
  {
    digitalWrite(pinled1, HIGH);    //LED가 꺼져있을 때
    led1_state = true;
  }
  else
  {
    digitalWrite(pinled1, LOW);     // LED가 켜져있을 때
    led1_state = false;
  }
  Serial.println("Pushed SW1");
}

// 스위치0번을 누를때마다 LED0번을 ON/OFF
// 스위치1번을 누를때마다 LED1번을 ON/OFF

int pinswitch0 = 2;
int pinswitch1 = 3;

int pinled0 = 12;
int pinled1 = 11;

boolean led0_state = false;    // flase:LED OFF, true:LED ON
boolean led1_state = false;    // flase:LED OFF, true:LED ON

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);       //시리얼 설정
  
  pinMode(pinswitch0, INPUT);    // 스위치0번 설정
  pinMode(pinswitch1, INPUT);    // 스위치1번 설정
  
  pinMode(pinled0, OUTPUT);      // LED0번 설정
  pinMode(pinled1, OUTPUT);      // LED1번 설정
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(pinswitch0)) {    
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
    delay(500);
  }
  if(digitalRead(pinswitch1)) {    
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
    delay(500);
  }
}

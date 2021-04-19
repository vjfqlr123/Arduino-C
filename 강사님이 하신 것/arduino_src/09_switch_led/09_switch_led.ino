// SW0를 누를때마다 LED0을 ON/OFF
// SW1를 누를때마다 LED1을 ON/OFF

int pinLed0 = 12;
int pinLed1 = 11;
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
}

void loop() {
  // put your main code here, to run repeatedly:
  // SW0
  if(digitalRead(pinSwitch0)==HIGH)   // 레벨체크
  {
    if(led0_state==false){    // LED가 꺼져있을 때
      digitalWrite(pinLed0, HIGH);
      led0_state = true;
    }else{                   // LED가 켜져있을 때
      digitalWrite(pinLed0, LOW);
      led0_state = false;
    }
    
    Serial.println("Pushed SW0");
    delay(500);
  } 

  // SW1
  if(digitalRead(pinSwitch1)==HIGH)   // 레벨체크
  {
    if(led1_state==false){    // LED가 꺼져있을 때
      digitalWrite(pinLed1, HIGH);
      led1_state = true;
    }else{                   // LED가 켜져있을 때
      digitalWrite(pinLed1, LOW);
      led1_state = false;
    }
    
    Serial.println("Pushed SW1");
    delay(500);
  }
}

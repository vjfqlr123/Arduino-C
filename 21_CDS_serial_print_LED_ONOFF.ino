//CDS 센서를 이용해 빛의 밝기에 따라 LED를 On/Off 하고 

#include <YetAnotherPcInt.h>

// CDS 핀 번호
int pincds = A0;
int pinvcc = A1;
int pingnd = A2;

// LED 핀 번호
int pinled0 = 3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  // CDS 핀 설정
  pinMode(pingnd, OUTPUT);
  pinMode(pinvcc, OUTPUT);
  pinMode(pincds, INPUT);
  digitalWrite(pingnd, LOW);
  digitalWrite(pinvcc, HIGH);
  // LED 핀 설정
  pinMode(pinled0, OUTPUT);
}

// 평상시 : 170, 가렸을때 : 600
void loop() {
  // put your main code here, to run repeatedly:
  int adcdata = analogRead(pincds);
  float volt = adcdata * (5.0/1024.0);

  // LED 제어
  if(adcdata>500){
    digitalWrite(pinled0, HIGH);
  }else {
    digitalWrite(pinled0, LOW);
  }
  
  Serial.print("CDS : ");
  Serial.print(adcdata);
  Serial.print(", Volt : ");
  Serial.println(volt);
  // sprintf 함수를 이용해서 한줄로 출력
  delay(1000);
}

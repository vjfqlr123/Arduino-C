//CDS 센서를 이용해 빛의 밝기에 따라 LED를 On/Off 하고 밝기까지 조절

// CDS 핀 번호
int pincds = A0;
int pinvcc = A1;
int pingnd = A2;

// LED 핀 번호
int pinled0 = 3;

int bright_val = 0;

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

// 평상시 : 170, 가렸을때 : 700
float unit = (700.0-90.0)/5;
void loop() {
  // put your main code here, to run repeatedly:
  int adcdata = analogRead(pincds);
  float volt = adcdata * (5.0/1024.0);

  // LED 제어
  bright_val = map(adcdata,0,1023,0,255);     // (변환할수, 현재값의 하한, 현재값의 상한, 목표값의 하한, 목표값의 상한)
  analogWrite(pinled0, bright_val);

//  if(adcdata<90){
//    analogWrite(pinled0, 0);
//  }else if(adcdata<(90+unit)){
//    analogWrite(pinled0, 50);
//  }else if(adcdata<(90+(unit*2))) {
//    analogWrite(pinled0, 100);
//  }else if(adcdata<(90+(unit*3))) {
//    analogWrite(pinled0, 150);
//  }else if(adcdata<(90+(unit*4))) {
//    analogWrite(pinled0, 200);
//  }else if(adcdata<(90+(unit*5))) {
//    analogWrite(pinled0, 250);
//  }else {
//    analogWrite(pinled0, 255);
//  }
  
  Serial.print("CDS : ");
  Serial.print(adcdata);
  Serial.print(", Volt : ");
  Serial.println(volt);
  // sprintf 함수를 이용해서 한줄로 출력
  delay(1000);
}

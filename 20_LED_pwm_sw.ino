// 스위치 3개를 이용해서 LED의 밝기를 조절하세요.
// SW0 : 모터의 듀티비를 25씩 증가, 인터럽트 사용(8번pin)
// SW1 : 모터의 듀티비를 25씩 감소, 인터럽트 사용(9번pin)
// SW2 : 모터를 정지, 인터럽트 사용(10번pin)
// LED0 : 11번에 연결

#include <YetAnotherPcInt.h>

int duty_rate = 0;

// DC Motor 핀 번호
int pinPos = 5;
int pinNeg = 4;
int pinEn = 3;

// SW 핀 번호
int pinsw0 = 8;
int pinsw1 = 9;
int pinsw2 = 10;

// LED 핀 번호
int pinled0 = 11;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  // VCC
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
  
  // DC Motor 설정
  pinMode(pinPos, OUTPUT);
  pinMode(pinNeg, OUTPUT);
  pinMode(pinEn, OUTPUT);

  // SW 설정
  pinMode(pinsw0, INPUT);
  pinMode(pinsw1, INPUT);
  pinMode(pinsw2, INPUT);

  // LED 설정
  pinMode(pinled0, OUTPUT);

  // pc 인터럽트
  PcInt::attachInterrupt(pinsw0, sw0_func, RISING);
  PcInt::attachInterrupt(pinsw1, sw1_func, RISING);
  PcInt::attachInterrupt(pinsw2, sw2_func, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(pinled0, duty_rate);
}

void motor_cntl(int mode, int duty) {
  analogWrite(pinEn, duty);
  
  if(mode == 1) {               // CW
    digitalWrite(pinPos, LOW);
    digitalWrite(pinNeg, HIGH);
    delay(1000);
  }else if(mode == 2){          // STOP
    digitalWrite(pinPos, LOW);
    digitalWrite(pinNeg, LOW);
    delay(1000);
  }else if(mode == 3){          // CCW
    digitalWrite(pinPos, HIGH);
    digitalWrite(pinNeg, LOW);
    delay(1000);
  }else if(mode == 4){          // break
    digitalWrite(pinPos, HIGH);
    digitalWrite(pinNeg, HIGH);
    delay(1000);
  }
}

void sw0_func(bool pinstate) {
   duty_rate += 25;
   if(duty_rate>255){
    duty_rate = 255;
   }
   Serial.println(duty_rate);
}

void sw1_func(bool pinstate) {
   duty_rate -= 25;
   if(duty_rate<=0){
    duty_rate = 0;
   }
   Serial.println(duty_rate);
}

void sw2_func(bool pinstate) {
   duty_rate = 0;
   Serial.println(duty_rate);
}

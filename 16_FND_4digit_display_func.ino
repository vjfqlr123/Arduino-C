// FND의 앞 두자리에 원하는 숫자를 표시

int FndData[8] = {13, 12, 11, 10, 9, 8, 7, 6};
int FndSel[4] = {5, 4, 3, 2};

uint8_t FndValue[16] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x27,
                        0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};     // 0~F


void setup() {
  // put your setup code here, to run once:
  int i=0;
  for(i=0; i<8; ++i) {
    pinMode(FndData[i], OUTPUT);
    //digitalWrite(FndData[i], HIGH);
  }
  for(i=0; i<4; ++i) {
    pinMode(FndSel[i], OUTPUT);
  }

}
int i = 0;
int num = 1234;
void loop() {
  // put your main code here, to run repeatedly:
  FND4_Displat(num);
}
void fndSelOut(int data) {    // 출력하고 싶은 digit를 설정하는 함수(1~4)
  int i=0;
  for(i=0; i<4; ++i) {
    digitalWrite(FndSel[i], HIGH);
  }
  
  if(data<=4) {
    digitalWrite(FndSel[data-1], LOW);
  }
  
}

void fndDataOut(int data) {
  int i=0;
  for(i=0; i<8; ++i) {      
    if(FndValue[data] & (0x01<<i)) {      // 각 비트들의 값에 따라서 LED를 ON/OFF
      digitalWrite(FndData[i], HIGH);
    }else {
      digitalWrite(FndData[i], LOW);
    }
  }
}

void FND4_Displat(int data) {     // 4자리 숫자
  int num_1000 = data/1000;
  int num_100 = (data%1000)/100;
  int num_10 = (data%100)/10;
  int num_1 = (data%10);

  int num[4] = {num_1000, num_100, num_10, num_1};

  int i=0;
  for(i=0; i<4; ++i) {
    fndDataOut(num[i]);        // display 데이터
    fndSelOut(i+1);         // display 위치
    delay(1);
  
    fndSelOut(0);       // display OFF
    delay(1);
  }
}

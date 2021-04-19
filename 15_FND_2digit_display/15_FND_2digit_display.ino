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
int num = 12;
void loop() {
  // put your main code here, to run repeatedly:
  // digit1에 1을 표시
  digitalWrite(FndSel[0], LOW);
  digitalWrite(FndSel[1], HIGH);
  digitalWrite(FndSel[2], HIGH);
  digitalWrite(FndSel[3], HIGH);
  for(i=0; i<8; ++i) {      // 0x3F = 00111111
    if(FndValue[1] & (0x01<<i)) {      // 각 비트들의 값에 따라서 LED를 ON/OFF
      digitalWrite(FndData[i], HIGH);
    }else {
      digitalWrite(FndData[i], LOW);
    }
  }
  delay(1);
  
  // digit2에 2을 표시
  digitalWrite(FndSel[0], HIGH);
  digitalWrite(FndSel[1], LOW);
  digitalWrite(FndSel[2], HIGH);
  digitalWrite(FndSel[3], HIGH);
  
  for(i=0; i<8; ++i) {      // 0x3F = 00111111
    if(FndValue[2] & (0x01<<i)) {      // 각 비트들의 값에 따라서 LED를 ON/OFF
      digitalWrite(FndData[i], HIGH);
    }else {
      digitalWrite(FndData[i], LOW);
    }
  }
  delay(1);

  // digit3에 3을 표시
  digitalWrite(FndSel[0], HIGH);
  digitalWrite(FndSel[1], HIGH);
  digitalWrite(FndSel[2], LOW);
  digitalWrite(FndSel[3], HIGH);
  for(i=0; i<8; ++i) {      // 0x3F = 00111111
    if(FndValue[3] & (0x01<<i)) {      // 각 비트들의 값에 따라서 LED를 ON/OFF
      digitalWrite(FndData[i], HIGH);
    }else {
      digitalWrite(FndData[i], LOW);
    }
  }
  delay(1);

  // digit4에 4을 표시
  digitalWrite(FndSel[0], HIGH);
  digitalWrite(FndSel[1], HIGH);
  digitalWrite(FndSel[2], HIGH);
  digitalWrite(FndSel[3], LOW);
  for(i=0; i<8; ++i) {      // 0x3F = 00111111
    if(FndValue[4] & (0x01<<i)) {      // 각 비트들의 값에 따라서 LED를 ON/OFF
      digitalWrite(FndData[i], HIGH);
    }else {
      digitalWrite(FndData[i], LOW);
    }
  }
  delay(1);
}

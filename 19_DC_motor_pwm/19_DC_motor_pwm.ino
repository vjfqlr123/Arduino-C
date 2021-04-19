#define duty_rate 50
int pinPos = 5;
int pinNeg = 4;
int pinEn = 3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
  pinMode(pinPos, OUTPUT);
  pinMode(pinNeg, OUTPUT);
  pinMode(pinEn, OUTPUT);
}

void loop() {     // CW STOP CCW BREAK 반복
  // put your main code here, to run repeatedly:
  // CW
  digitalWrite(pinPos, LOW);
  digitalWrite(pinNeg, HIGH);
  analogWrite(pinEn, duty_rate);       // 0~255
  delay(1000);

  //  STOP
  digitalWrite(pinPos, LOW);
  digitalWrite(pinNeg, LOW);
  analogWrite(pinEn, duty_rate);
  delay(1000);

  // CCW
  digitalWrite(pinPos, HIGH);
  digitalWrite(pinNeg, LOW);
  analogWrite(pinEn, duty_rate);
  delay(1000);

  // break
  digitalWrite(pinPos, HIGH);
  digitalWrite(pinNeg, HIGH);
  analogWrite(pinEn, duty_rate);
  delay(1000);
}

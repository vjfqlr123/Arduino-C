int pincds = A0;
int pinvcc = A1;
int pingnd = A2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(pingnd, OUTPUT);
  pinMode(pinvcc, OUTPUT);
  pinMode(pincds, INPUT);
  digitalWrite(pingnd, LOW);
  digitalWrite(pinvcc, HIGH);
}

// 평상시 : 170, 가렸을때 : 600
void loop() {
  // put your main code here, to run repeatedly:
  int adcdata = analogRead(pincds);
  float volt = adcdata * (5.0/1024.0);
  Serial.print("CDS : ");
  Serial.print(adcdata);
  Serial.print(", Volt : ");
  Serial.println(volt);
  // sprintf 함수를 이용해서 한줄로 출력
  delay(1000);
}

int pinSwitch = 2;
int count = 0;

void setup() {
  // put your setup code here, to run once:
  // 시리얼 설정
  Serial.begin(115200);

  // Switch 설정
  pinMode(pinSwitch, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(pinSwitch)==HIGH)
  {
    Serial.println("Pushed");
    Serial.println(count);
    count++;
    delay(500);
  }
  
}

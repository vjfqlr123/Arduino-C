int pinswitch = 2;
int count = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);       //시리얼 설정
  pinMode(pinswitch, INPUT);    // 스위치 설정
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(pinswitch)) {    
    Serial.println("Pushed");
    Serial.println(count);
    count++;
    delay(500);
  }
}

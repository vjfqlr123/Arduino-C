void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("serial test !!");
  Serial.print("ECHO >>");
}

void loop() {
  // put your main code here, to run repeatedly:
  
}

void serialEvent(void) {    //데이터가 수신되면 자동으로 호출됨
  char data;
  data = Serial.read();
  Serial.write(data);
}

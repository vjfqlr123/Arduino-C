void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);    // 통신 속도
  Serial.write('H');
  Serial.write('e');
  Serial.write('l');
  Serial.write('l');
  Serial.write('o');
  Serial.write('\n');

  Serial.println(78);
  Serial.println(1.23456);
  Serial.println('N');
  Serial.println("Hello world") ;   
}

void loop() {
  // put your main code here, to run repeatedly:
}

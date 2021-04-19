void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);     // 통신 속도
  Serial.write('H');
  Serial.write('e');
  Serial.write('l');
  Serial.write('l');
  Serial.write('o');
  Serial.println("HELLO");

  Serial.write('\n');
  Serial.print(78);
  Serial.print(1.23456);
  Serial.print('N');
  Serial.print("HELLO");
}

void loop() {
  // put your main code here, to run repeatedly:

}

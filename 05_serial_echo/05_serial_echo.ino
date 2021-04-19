void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("serial test !!");
  Serial.print("echo >> ");
}

void loop() {
  // put your main code here, to run repeatedly:
  char data;
  if(Serial.available() > 0)
  {
    data = Serial.read();
    Serial.write(data);
  }
}

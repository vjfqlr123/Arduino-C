#define vcc 3
#define gnd 4
#define sig 2

boolean sig_state = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
  pinMode(vcc, OUTPUT);
  pinMode(gnd, OUTPUT);
  pinMode(sig, INPUT);

  digitalWrite(vcc, HIGH);
  digitalWrite(gnd, LOW);

  attachInterrupt(digitalPinToInterrupt(sig), tilt_state_print, CHANGE);

}

void loop() {
  // put your main code here, to run repeatedly:
  
}

void tilt_state_print() {
  if(!digitalRead(sig))       // tilt OFF: high, ON: low
  {
    Serial.println("Tilt ON");      // LOW
  }else {
    Serial.println("Tilt OFF");     // OFF
  }
}

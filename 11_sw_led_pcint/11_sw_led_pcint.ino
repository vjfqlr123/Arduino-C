#define PCINT_PIN8 8
#define PCINT_PIN9 14
#define LED_2      10

boolean led2_state = false;

#include <YetAnotherPcInt.h>

void pinChanged_8(const char* message, bool pinstate) {
  Serial.print(message);
  Serial.println(pinstate ? "HIGH" : "LOW");
}

void pinChanged_9(bool pinstate) {
  if(led2_state==false) {
    digitalWrite(LED_2, HIGH);
    led2_state = true;
  }else {
    digitalWrite(LED_2, LOW);
    led2_state = false;
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(PCINT_PIN8, INPUT_PULLUP);
  pinMode(PCINT_PIN9, INPUT_PULLUP);
  pinMode(LED_2, OUTPUT);
  PcInt::attachInterrupt(PCINT_PIN8, pinChanged_8, "Pin has changed to ", RISING);
  PcInt::attachInterrupt(PCINT_PIN9, pinChanged_9, RISING);
}

void loop() {}

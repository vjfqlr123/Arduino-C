#include <LiquidCrystal.h>

LiquidCrystal lcd(13,12,11,10,8,7,6,5,4,3);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.print("Hello!!");
  lcd.setCursor(0,1);     // 열,행
  lcd.print("Hello!!");
}

void loop() {
  // put your main code here, to run repeatedly:

}

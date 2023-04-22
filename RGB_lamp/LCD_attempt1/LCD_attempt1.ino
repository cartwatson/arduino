//carter watson
//06/21/2019
//attempt to conrol rgb light strip
//LCD trial
//help from mechatronics

#include <LiquidCrystal.h>
const int rs = 1, en = 2,d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup() {
  lcd.begin(16,2);
  
  lcd.setCursor(0,0);
  lcd.print("RED:");

  lcd.setCursor(0,1);
  lcd.print("BLU:");

  lcd.setCursor(8,0);
  lcd.print("GRN:");
}

void loop() {
 
}

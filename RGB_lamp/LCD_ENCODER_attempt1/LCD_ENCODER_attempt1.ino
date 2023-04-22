//carter watson
//06/21/2019
//attempt to conrol rgb light strip
//LCD+encoder trial


//LCD
#include <LiquidCrystal.h>
const int rs = 1, en = 2,d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//ENCODER
#define outputA 8         // Generating interrupts using CLK signal
#define outputB 9         // Reading DT signal
#define encoderButton 10  // Reading Push Button switch
int encoderButtonVar;

int aStateRED;
int aLastStateRED;
int counterRED = 0;
int onesRED;
int tensRED;
int hundRED;

int aStateBLU;
int aLastStateBLU;
int counterBLU = 0;

int aStateGRN;
int aLastStateGRN;
int counterGRN = 0;

int encoderState = 0;


void setup() {
//LCD
  lcd.clear();
  lcd.begin(16,2);
  
  lcd.setCursor(0,0);
  lcd.print("RED:");

  lcd.setCursor(0,1);
  lcd.print("BLU:");

  lcd.setCursor(8, 0);
  lcd.print("GRN:");
//ENCODER
  pinMode (outputA, INPUT);
  pinMode (outputB, INPUT);
  pinMode (encoderButton, INPUT);

  Serial.begin (9600);

  aLastStateRED = digitalRead(outputA);
  aLastStateBLU = digitalRead(outputA);
  aLastStateGRN = digitalRead(outputA);

  
}

void loop() { 
  //ENCODER

  counterRED = constrain(counterRED, 1, 254);
  counterBLU = constrain(counterBLU, 1, 254);
  counterGRN = constrain(counterGRN, 1, 254);
    
    aStateRED = digitalRead(outputA);
    if (aStateRED != aLastStateRED) {
      if (digitalRead(outputB) != aStateRED) {
      counterRED --;
    } else {
      counterRED ++;
    }
    Serial.print("PositionRED: ");
    Serial.println(counterRED);
//    lcd.rightToLeft();
    
      onesRED = (counterRED%10);
      tensRED = ((counterRED/10)%10);
      hundRED = ((counterRED/100)%10);
    
    lcd.home();
    lcd.print("RED:");
    lcd.print(hundRED);
//    lcd.setCursor(5,0);
    lcd.print(tensRED);
//    lcd.setCursor(6,0);
    lcd.print(onesRED);
    /*
    lcd.home();
    lcd.print("RED:");
    lcd.print(counterRED);
    */
    }
    aLastStateRED = aStateRED;
}

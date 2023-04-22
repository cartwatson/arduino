//carter watson
//06/21/2019
//attempt to conrol rgb light strip
//LCD+encoder trial

//LOOPS BROTHER
#include <Scheduler.h>

//LCD
#include <LiquidCrystal.h>
//const int rs = 1, en = 2,d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(1, 2, 4, 5, 6, 7);

//ENCODER
#define outputA 8         // Generating interrupts using CLK signal
#define outputB 9         // Reading DT signal
#define encoderButton 10  // Reading Push Button switch
int encoderButtonVar = 0 ;
int encoderButtonState;

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
  pinMode (encoderButton, INPUT_PULLUP);

  Serial.begin (9600);

  aLastStateRED = digitalRead(outputA);
  aLastStateBLU = digitalRead(outputA);
  aLastStateGRN = digitalRead(outputA);

//SCHEDULER
    Scheduler.startLoop(loop1);
    Scheduler.startLoop(loop2);
    Scheduler.startLoop(loop3);
}

void loop() {
   encoderButtonState = digitalRead(encoderButton);

  if (encoderButton == HIGH && encoderButtonVar == 0){
    encoderButtonVar ++;
    Serial.print("void RED");

  if (encoderButton == HIGH && encoderButtonVar == 1){
    encoderButtonVar ++;
    Serial.print("void BLU");
    BLU();
  }
  if (encoderButton == HIGH && encoderButtonVar == 2){
    encoderButtonVar ++;
    Serial.print("void GRN");
    GRN();
  }
}

void loop1() { //RED
  counterRED = constrain(counterRED, 1, 254);

   aStateRED = digitalRead(outputA);
    if (aStateRED != aLastStateRED) {
      if (digitalRead(outputB) != aStateRED) {
      counterRED --;
    } else {
      counterRED ++;
    }
    Serial.print("PositionRED: ");
    Serial.println(counterRED);
}
}

void loop2() { //BLU
  counterBLU = constrain(counterBLU, 1, 254);

   aStateBLU = digitalRead(outputA);
    if (aStateBLU != aLastStateBLU) {
      if (digitalRead(outputB) != aStateBLU) {
      counterBLU --;
    } else {
      counterBLU ++;
    }
    Serial.print("PositionBLU: ");
    Serial.println(counterBLU);
}
}

void loop3() { //GRN
  counterGRN = constrain(counterGRN, 1, 254);

   aStateGRN = digitalRead(outputA);
    if (aStateGRN != aLastStateGRN) {
      if (digitalRead(outputB) != aStateGRN) {
      counterGRN --;
    } else {
      counterGRN ++;
    }
    Serial.print("PositionGRN: ");
    Serial.println(counterGRN);
}
}

//carter watson
//06/24/2019
//attempt to conrol rgb light strip
//everything
//help from literally everywhere

/*******************************************************************************************/
//LCD CONTROL
#include <LiquidCrystal.h>
const int rs = 23, en = 25, d4 = 27, d5 = 29, d6 = 31, d7 = 33;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//ENCODER
#define outputA 8
#define outputB 9
#define Switch  10 

#define BLU 11
#define RED 12
#define GRN 13

int aStateRED;
int aLastStateRED;
int counterRED = 0;

int aStateBLU;
int aLastStateBLU;
int counterBLU = 0;

int aStateGRN;
int aLastStateGRN;
int counterGRN = 0;

int varRED = 1;
int varBLU = 0;
int varGRN = 0;

//RGB CONTROL
int lightness = 255;

/*******************************************************************************************/
void setup() {
//LCD CONTROL
  lcd.begin(16,2);
  
  lcd.setCursor(0,0);
  lcd.print("RED:");

  lcd.setCursor(0,1);
  lcd.print("BLU:");

  lcd.setCursor(8,0);
  lcd.print("GRN:");

  lcd.setCursor(8,1);
  lcd.print("");
  
//ENCODER
  pinMode (outputA, INPUT);
  pinMode (outputB, INPUT);
  pinMode (Switch, INPUT_PULLUP);

  Serial.begin (9600);

  aLastStateRED = digitalRead(outputA);
  aLastStateBLU = digitalRead(outputA);
  aLastStateGRN = digitalRead(outputA);

//RGB CONTROL
  pinMode(GRN, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(BLU, OUTPUT);

//RGB LCD
  lcd.setCursor(4,0);
  if (counterRED <100){
    lcd.print("0");
    if (counterRED < 10){
      lcd.print("0");
    }
  }
  lcd.print(counterRED);

  lcd.setCursor(4,1);
  if (counterBLU <100){
    lcd.print("0");
    if (counterBLU < 10){
      lcd.print("0");
    }
  }
  lcd.print(counterBLU);

  lcd.setCursor(12,0);
  if (counterGRN <100){
    lcd.print("0");
    if (counterGRN < 10){
      lcd.print("0");
    }
  }
  lcd.print(counterGRN);
}
/*******************************************************************************************/
void loop() { 
//ENCODER VARIABLES
  counterRED = constrain(counterRED, 0, 254);
  counterBLU = constrain(counterBLU, 0, 254);
  counterGRN = constrain(counterGRN, 0, 254);

//LOOPS  
  if (varRED == 1){
  loopRED();
  }

  if (varBLU == 1){
  loopBLU();
  }

  if (varGRN == 1){
  loopGRN();
  }
}
/*
  Functions for maintaining state to be manipulated
*/
void loopRED() {
  //read rotary encode
  aStateRED = digitalRead(outputA);
  if (aStateRED != aLastStateRED) {
    if (digitalRead(outputB) != aStateRED) {
      counterRED --;
    } else {
      counterRED ++;
    }
    //write change to serial monitor
    analogWrite(RED, counterRED);
    Serial.print("PositionRED: ");
    Serial.println(counterRED);
    aLastStateRED = aStateRED;
  }
  
  //check for button press
  if (digitalRead(Switch) == LOW) {
    varRED = 0;
    varBLU = 0;
    varGRN = 1;
    Serial.println("STATE CHANGE: GRN");
    delay(500);
  }

  //write filler space if needed
  lcd.setCursor(4,0);
  if (counterRED <100){
    lcd.print("0");
    if (counterRED < 10){
      lcd.print("0");
    }
  }
  
  //print to lcd
  if (counterRED > 0) {
    lcd.print(counterRED);
  } else {
    lcd.print(0);
  }
} //end loopRed

void loopBLU() {
   aStateBLU = digitalRead(outputA);
    if (aStateBLU != aLastStateBLU) {
      if (digitalRead(outputB) != aStateBLU) {
      counterBLU --;
    } else {
      counterBLU ++;
    }
    analogWrite(BLU, counterBLU);
    Serial.print("PositionBLU: ");
    Serial.println(counterBLU);
    aLastStateBLU = aStateBLU;
}

  if (digitalRead(Switch) == LOW) {
    varRED = 1;
    varBLU = 0;
    varGRN = 0;
    Serial.println("STATE CHANGE: RED");
    delay(500);
  }

  lcd.setCursor(4,1);
  if (counterBLU <100){
    lcd.print("0");
    if (counterBLU < 10){
      lcd.print("0");
    }
  }

  if (counterBLU > 0) {
    lcd.print(counterBLU);
  } else {
    lcd.print(0);
  }
  
}

void loopGRN() {
   aStateGRN = digitalRead(outputA);
    if (aStateGRN != aLastStateGRN) {
      if (digitalRead(outputB) != aStateGRN) {
      counterGRN --;
    } else {
      counterGRN ++;
    }
    analogWrite(GRN, counterGRN);
    Serial.print("PositionGRN: ");
    Serial.println(counterGRN);
    aLastStateGRN = aStateGRN;
}

  if (digitalRead(Switch) == LOW) {
    varRED = 0;
    varBLU = 1;
    varGRN = 0;
    Serial.println("STATE CHANGE: BLU");
    delay(500);
  }
    
  lcd.setCursor(12,0);
  if (counterGRN <100){
    lcd.print("0");
    if (counterGRN < 10){
      lcd.print("0");
    }
  }

  if (counterGRN > 0) {
    lcd.print(counterGRN);
  } else {
    lcd.print(0);
  }
}

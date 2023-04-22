//J Carter Watson
//04/25/2020
//Full_Control

//include libraries
#include <LiquidCrystal.h>

//Encoder pin setup
#define outputA 8
#define outputB 9
#define switchEncoder 10

//general pin setup
#define BLUE 11
#define RED 12
#define GREEN 13

//LCD pin setup
const int rs = 23, en = 25, d4 = 27, d5 = 29, d6 = 31, d7 = 33;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//initialize variables
int state;
int lastState;
int counterRed = 0;
int counterBlue = 0;
int counterGreen = 0;
//boolean for controling functions
bool red = true;
bool blue = false;
bool green = false;
//rgb control
int lightness = 255;


void setup() {
  //lcd setup
  lcd.begin(16, 2);
  //write initial state on lcd
  lcd.setCursor(0, 0);
  lcd.print("RED: ");
  lcd.setCursor(0, 1);
  lcd.print("BLU: ");
  lcd.setCursor(8, 0);
  lcd.print("GRN: ");
  //write initial value
  lcd.setCursor(4, 0);
  lcd.print("000");
  lcd.setCursor(4, 1);
  lcd.print("000");
  lcd.setCursor(12, 0);
  lcd.print("000");

  //encoder setup
  pinMode(outputA, INPUT);
  pinMode(outputB, INPUT);
  pinMode(switchEncoder, INPUT_PULLUP);

  Serial.begin(9600);

  lastState = digitalRead(outputA);

  //rgb control
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(RED, OUTPUT);
}

void loop() {
  //constrain counter variables
  counterRed = constrain(counterRed, 0, 255);
  counterBlue = constrain(counterBlue, 0, 255);
  counterGreen = constrain(counterGreen, 0, 255);

  //call function based on boolean condition
  if (red) {
    loopRed();
  }
  if (blue) {
    loopBlue();
  }
  if (green) {
    loopGreen();
  }
}

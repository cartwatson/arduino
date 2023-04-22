//carter watson
//06/23/2019
//attempt to conrol rgb light strip
//encoder trial with extra LOOPS
//help from literally everywhere

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
int brightness = 255;


void setup() {
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
}

void loop() { 
  //ENCODER
  counterRED = constrain(counterRED, 1, 254);
  counterBLU = constrain(counterBLU, 1, 254);
  counterGRN = constrain(counterGRN, 1, 254);
  
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

void loopRED() {
   aStateRED = digitalRead(outputA);
    if (aStateRED != aLastStateRED) {
      if (digitalRead(outputB) != aStateRED) {
      counterRED --;
    } else {
      counterRED ++;
    }
    analogWrite(RED, counterRED);
    Serial.print("PositionRED: ");
    Serial.println(counterRED);
    aLastStateRED = aStateRED;
}

  if (digitalRead(Switch) == LOW) {
    varRED = 0;
    varBLU = 0;
    varGRN = 1;
    Serial.print("STATE CHANGE: GRN");
    delay(500);
  }
}

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
    Serial.print("STATE CHANGE: RED");
    delay(500);
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
    Serial.print("STATE CHANGE: BLU");
    delay(500);
  }
}

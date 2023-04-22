//carter watson
//06/23/2019
//attempt to conrol rgb light strip
//RGB Control trial
//Help from Make Use Of


#define BLU 11
#define RED 12
#define GRN 13

int brightness = 255;
int fadeSpeed = 20;

int gBright = 0; 
int rBright = 0;
int bBright = 0;


void setup() {

  pinMode(GRN, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(BLU, OUTPUT);

}


void TurnOn(){
//RED  
    for (int i=0;i<256; i++){
      
      analogWrite(RED, rBright);
      rBright +=1;
      delay(fadeSpeed);

    }
          analogWrite(RED, rBright);
    for (int i=0;i<256; i++){
      
      analogWrite(RED, rBright);
      rBright -=1;
      delay(fadeSpeed);

    }
//BLUE
    for (int i=0;i<256; i++){
      
      analogWrite(BLU, bBright);
      bBright +=1;
      delay(fadeSpeed);

    }
          analogWrite(BLU, bBright);
    for (int i=0;i<256; i++){
      
      analogWrite(BLU, bBright);
      bBright -=1;
      delay(fadeSpeed);

    }
//GREEN
    for (int i=0;i<256; i++){
      
      analogWrite(GRN, gBright);
      gBright +=1;
      delay(fadeSpeed);
    }  
          analogWrite(GRN, gBright);
    for (int i=0;i<256; i++){
      
      analogWrite(GRN, gBright);
      gBright -=1;
      delay(fadeSpeed);

    }

//WHITE
    for (int i=0;i<256; i++){
      
      analogWrite(GRN, gBright);
      gBright +=1;
      
      analogWrite(BLU, bBright);
      bBright +=1;

      analogWrite(RED, rBright);
      rBright +=1;
      delay(fadeSpeed);
    }

    for (int i=0;i<256; i++){
      
      analogWrite(GRN, gBright);
      gBright -=1;

      analogWrite(BLU, bBright);
      bBright -=1;

      analogWrite(RED, rBright);
      rBright -=1;
      delay(fadeSpeed);
    }
}


void loop(){
  TurnOn();
}

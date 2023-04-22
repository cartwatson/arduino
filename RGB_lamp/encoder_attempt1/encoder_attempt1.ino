//carter watson
//06/21/2019
//attempt to conrol rgb light strip
//encoder trial
//help from mechatronics & arduino

#define outputA 8 // Generating interrupts using CLK signal
#define outputB 9 // Reading DT signal
#define Switch  10 // Reading Push Button switch

int aState;
int aLastState;
int counter = 0;

void setup() {
  pinMode (outputA, INPUT);
  pinMode (outputB, INPUT);

  Serial.begin (9600);

  aLastState = digitalRead(outputA);
}

void loop() {
 counter = constrain(counter, 1, 254);
  aState = digitalRead(outputA);
  if (aState != aLastState) {
    if (digitalRead(outputB) != aState) {
      counter --;
    } else {
      counter ++;
    }
    Serial.print("Position: ");
    Serial.println(counter);
    }
    aLastState = aState;
}

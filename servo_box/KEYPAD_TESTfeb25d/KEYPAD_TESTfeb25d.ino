#include <Keypad.h>

const byte rows = 4;
const byte cols = 4;
char keys [rows][cols] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[rows] = {9, 8, 7, 6};
byte colPins[cols] = {5, 4, 3, 2};
Keypad keypad =Keypad( makeKeymap(keys),rowPins,colPins,rows,cols );

void setup() {
  pinMode(9, INPUT);
  pinMode(8, INPUT);
  pinMode(7, INPUT);
  pinMode(6, INPUT);
  pinMode(5, INPUT);
  pinMode(4, INPUT);
  pinMode(3, INPUT);
  pinMode(2, INPUT);

  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  Serial.begin(9600);

  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
}

void loop() {
  int w = 0;
  int x = 0;
  int y = 0;
  int z = 0;
  
if(digitalRead(8) == LOW && digitalRead(5) == LOW){
  char key = keypad.getKey();
  Serial.print(key);
    int w = 1;
    digitalWrite(12, HIGH);
    delay(1000);
    digitalWrite(12, LOW);
    delay(1000);
}
while(w == 1){ 
  digitalWrite(10, HIGH);
}
digitalWrite(10, LOW);
if(digitalRead(8) == LOW && digitalRead(4) == LOW && w == 1){
    char key = keypad.getKey();
  Serial.print(key);
    int w = 1;
    digitalWrite(10, HIGH);
    delay(1000);
    digitalWrite(10, LOW);
    delay(1000);
}
}

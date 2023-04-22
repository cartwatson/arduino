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
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(0, OUTPUT);
}

void loop()
{
  char key = keypad.getKey();
  if(key)  // Check for a valid key.
  {
    switch (key) //#1
    {
      case '2':
        digitalWrite(12, HIGH);
        delay(1000);
        digitalWrite(12, LOW);
/////////////////////////////////////////
    digitalWrite(0, HIGH);
    while (key == NO_KEY);
    {}
    delay(1000);
    digitalWrite(0, LOW);
    
    switch (key) //#2
    {
      case '5':
        digitalWrite(12, HIGH);
        delay(1000);
        digitalWrite(12, LOW);    
/////////////////////////////////////////        
    switch (key) //#3
    {
      case '8':
        digitalWrite(12, HIGH);
        delay(1000);
        digitalWrite(12, LOW);    
//////////////////////////////////////////
    switch (key) //#4
    {
      case '0':
        digitalWrite(12, HIGH);
        delay(1000);
        digitalWrite(12, LOW);    
        break; //#4
    }
///////////////////////////////////////////        
        break; //#3
    }
///////////////////////////////////////////
        break; //#2
    }
///////////////////////////////////////////    
   break;//#1
          
      default:
        digitalWrite(11, HIGH);
        delay(1000);
        digitalWrite(11, LOW);
        break;
    }
  }
}

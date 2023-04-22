#include <Servo.h>
#include <Keypad.h>

Servo myservo;//create servo object to control a servo

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

void setup()
{
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
  myservo.attach(13);//attachs the servo on pin 10 to servo object
  myservo.write(0);//back to 0 degrees 
  delay(1000);//wait for a second
}
void loop()
{
  
  char key = keypad.getKey();
  if(key!= NO_KEY){
    Serial.print(key);
  }
  if(digitalRead(6) == LOW && digitalRead(5) == LOW){
    Serial.print(key);
  }
  
}

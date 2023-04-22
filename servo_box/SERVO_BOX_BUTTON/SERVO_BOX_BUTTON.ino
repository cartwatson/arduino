#include <Servo.h>
Servo myservo;

byte leds = 0;
void setup() {
  pinMode(12, OUTPUT);
  pinMode(10, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
     Serial.begin(9600);
      myservo.attach(13);//attachs the servo on pin 10 to servo object
      myservo.write(0);//back to 0 degrees 
      delay(1000);
}

void loop() {
  if (digitalRead (1) == LOW){
    digitalWrite(12, HIGH);
    myservo.write (180);
    delay(1000);
    }
if (digitalRead(10) == LOW){
   digitalWrite(12,LOW);
   myservo.write (0);
   delay(1000);
}
}

#include <Servo.h>
#include <SPI.h>
#include <MFRC522.h>

Servo myservo;
#define RST_PIN   2
#define SS_PIN    3

MFRC522 mfrc522(SS_PIN, RST_PIN);
#define NEW_UID {0xDE, 0xAD, 0xBE, 0xEF}
MFRC522::MIFARE_Key key;

void setup()
{
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
  myservo.attach(13);
  myservo.write(0); 
  delay(1000);
  
  SPI.begin();
  mfrc522.PCD_Init();
  for (byte i = 0; i < 6; i++) {
    key.keyByte[i] = 0xFF;
  }
}

void loop() {
  
  // Look for new cards, and select one if present
  if ( ! mfrc522.PICC_IsNewCardPresent() || ! mfrc522.PICC_ReadCardSerial() ) {
    delay(50);
    digitalWrite(11, HIGH);
    
  }
  
  Serial.print(F("Card UID:"));
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
  } 
  Serial.println();
  digitalWrite(11, LOW);
}

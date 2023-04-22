#include <DHT.h>
#include <DHT_U.h>
#include <LiquidCrystal.h>

#define DHTPIN  7
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


void setup() {
  Serial.begin(9600);
  // temp/humid setup
  dht.begin();
  // lcd setup
  lcd.begin(16, 2);
  // setup temp/humid on screen
  lcd.setCursor(0, 0);
  lcd.print("Temp:  ");
  lcd.setCursor(0, 1);
  lcd.print("Humid: ");
}

void loop() {
  // get temp and humid
  float temp  = 0;
  float humid = 0;
  temp  = dht.readTemperature(true);
  humid = dht.readHumidity();
  
  // debug serial prints
  Serial.print("Temp:  ");
  Serial.println(temp);
  Serial.print("Humid: ");
  Serial.println(humid);

  // refresh lcd
  lcd.setCursor(7, 0);
  lcd.print(temp);
  lcd.print(" *F");
  lcd.setCursor(7, 1);
  lcd.print(humid);
  lcd.print(" %");

  // delay for sensor
  delay(2000);
}

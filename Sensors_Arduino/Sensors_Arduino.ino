#include <NewPing.h>
#include <SimpleDHT.h>

#define TRIGGER_PIN  8
#define ECHO_PIN     9
#define MAX_DISTANCE 400

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

int x, y, z;
int a1 = A0;
int a2 = A1;
int a3 = A2;
int pinDHT11 = 10;
SimpleDHT11 dht11;
int  sensorPin  =  A3; 
int  ledPin  =  13;
int  sensorValue =  0;

void setup() {
  Serial.begin(9600); // Open serial monitor at 9600 baud
  pinMode(a1,INPUT);
  pinMode(a2,INPUT);
  pinMode(a3,INPUT);
  pinMode(ledPin,OUTPUT);
}

void loop() {
  //ultrasonic
  delay(2000);
  unsigned int uS = sonar.ping();
  Serial.print("Ping: ");
  Serial.print(uS / US_ROUNDTRIP_CM);
  Serial.println("cm");
  
  //accelerometer
  x = analogRead(a1);     
  y = analogRead(a2);     
  z = analogRead(a3);     
  Serial.print("x:  ");
  Serial.print(x, DEC);  
  Serial.print(" "); 
  Serial.print("y:  "); 
  Serial.print(y, DEC);   
  Serial.print(" "); 
  Serial.print("z:  "); 
  Serial.println(z, DEC); 
  
  //temp and humidity
  byte temperature = 0;
  byte humidity = 0;
  byte data[40] = {0};
  dht11.read(pinDHT11, &temperature, &humidity, data);
 
  if(temperature == 0 && humidity == 0) {}
  else{
  Serial.print("Sample: ");
  Serial.print((int)temperature); Serial.print(" *C, ");
  Serial.print((int)humidity); Serial.println(" %");
  }
  
   //sound
  sensorValue =  analogRead(sensorPin);
  digitalWrite(ledPin,  HIGH); 
  delay(sensorValue); 
  digitalWrite(ledPin,  LOW);
  delay(sensorValue);
  Serial.print("Sound: ");
  Serial.println(sensorValue,  DEC);

delay(2000);
}


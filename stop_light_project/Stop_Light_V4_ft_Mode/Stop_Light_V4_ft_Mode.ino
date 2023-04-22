#include <NewPing.h>
#include <Average.h>

#define TRIGGER_PIN  8  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     9  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
int u[4];
Average<float> ave(4);

void setup() {
  Serial.begin(9600); // Open serial monitor at 115200 baud to see ping results.
  pinMode (11, OUTPUT); // Green
  pinMode (12, OUTPUT); // Yellow
  pinMode (13, OUTPUT); // Red
}

void loop() {
//Code for ultrasonic sensor 
  delay(500);  // Wait 500ms between pings (about 2 pings/sec). 29ms should be the shortest delay between pings.
  unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
  Serial.print("Ping: ");
  Serial.print(uS / US_ROUNDTRIP_CM); // Convert ping time to distance and print result (0 = outside set distance range, no ping echo)
  Serial.println("cm");

//Code for Mode
  ave.push(uS / US_ROUNDTRIP_CM);
  
  int x;
  for (x=0; x < 4; x++) {
   ave.get(u);
   u[x] =  uS / US_ROUNDTRIP_CM ; 
  }
  int M;
Serial.print("Mode:   "); Serial.println(ave.mode());
  M = ave.mode();
//Conditions for the lights
 //Greeen 
  if ( M >= 201 || M == 0) {
    digitalWrite (11, HIGH);
    digitalWrite (12, LOW);
    digitalWrite (13, LOW);
  }
 //Yellow 
  if (M <= 199  && M >= 100) {
    digitalWrite (11, LOW);
    digitalWrite (12, HIGH);
    digitalWrite (13, LOW);
  }
 //Red
  if (M <= 99 && M >= 1) {
    digitalWrite (11, LOW);
    digitalWrite (12, LOW);
    digitalWrite (13, HIGH);
  }

}

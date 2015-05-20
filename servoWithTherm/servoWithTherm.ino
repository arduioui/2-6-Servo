// include the servo library
#include <Servo.h>
#include <OneWire.h>
#include <DallasTemperature.h>

Servo myServo;  // create a servo object

int const servoPin = 2;

#define BROCHE_ONEWIRE 13    // Broche utilisée pour le bus 1-Wire
 
OneWire oneWire(BROCHE_ONEWIRE);  // Création de l'objet OneWire ds

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);

void setup() {
  myServo.attach(servoPin);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);        // open a serial connection to your computer
  
  // Start up the library
  sensors.begin();
}

float tempFloat = 0.0;
int tempInt = 0;
int angle = 0;

void loop() {
  Serial.print(" Requesting temperatures...");
  sensors.requestTemperatures(); // Send the command to get temperatures
  Serial.println("DONE");

  Serial.print("Temperature for Device 1 is: ");
  tempFloat = sensors.getTempCByIndex(0);
  Serial.print(tempFloat); // Why "byIndex"?
  // You can have more than one IC on the same bus. 
  // 0 refers to the first IC on the wire
  // wait for the servo to get there
  tempInt = tempFloat * 100.0;
  angle = map(tempInt, 2000, 3600, 25, 160);
  // set the servo position
  myServo.write(angle);
  
  delay(500);
}

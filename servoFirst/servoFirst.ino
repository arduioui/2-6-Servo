// include the servo library
#include <Servo.h>

Servo myServo;  // create a servo object

void setup() {
  myServo.attach(9); // attaches the servo on pin 9 to the servo object
  Serial.begin(9600); // open a serial connection to your computer
}


void loop() {
  // set the servo position
  myServo.write(130);

  // wait for the servo to get there
  delay(200);
}



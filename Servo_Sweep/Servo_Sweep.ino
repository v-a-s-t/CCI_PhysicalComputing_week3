// Include servo library
#include <Servo.h>

// Servo attached to pin 3
#define SERVOPIN 3

// Create copy of servo library
Servo myServo;

void setup() {
  // Attach servo library to pin.
  myServo.attach(SERVOPIN);
}

void loop() {
  // For loop goes between 0 and 179, waiting in between each step.
  for (int i = 0; i < 180; i++) {
    myServo.write(i);
    delay(50);
  }
  // For loop goes between 180 and 1, waiting in between each step.
  for (int i = 180; i > 0; i--) {
    myServo.write(i);
    delay(50);
  }
}

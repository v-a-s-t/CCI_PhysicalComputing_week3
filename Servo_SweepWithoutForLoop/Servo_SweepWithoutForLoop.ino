// Include servo library
#include <Servo.h>

// Servo attached to pin 3
#define SERVOPIN 3

// Create copy of servo library
Servo myServo;

// Angle variable
int angle = 0;
// Variable to track if we're going up or down.
boolean countingUp = true;

void setup() {
  // Attach servo library to pin.
  myServo.attach(SERVOPIN);
}

void loop() {
  // If we're counting up, add one. If we're counting down,
  // subtract one.
  if (countingUp) {
    angle = angle + 1;
  }
  else {
    angle = angle - 1;
  }

  // If we've exceeded 180 degrees, it's time to count down.
  if (angle > 180) {
    angle = 180;
    countingUp = false;
  }
  // Else, if we've gone below zero, it's time to count back up.
  else if (angle < 0) {
    angle = 0;
    countingUp = true;
  }

  // Finally, write angle to servo!
  myServo.write(angle);

  // Slow this loop down so it's at a good speed.
  delay(50);
}

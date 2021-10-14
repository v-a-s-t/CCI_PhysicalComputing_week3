#define LEDPIN 9
#define BUTTONPIN 5

int buttonValue;
int prevButtonValue;
int ledState;

void setup() {
  // Sets the LED pin to be an output
  pinMode(LEDPIN, OUTPUT);
  // Sets the button pin to be an input.
  pinMode(BUTTONPIN, INPUT);
}

void loop() {
  // Read button input
  buttonValue = digitalRead(BUTTONPIN);

  // If we have a new button value, let's flip the LED's state.
  // From on to off, or from off to on.
  if (buttonValue == HIGH && buttonValue != prevButtonValue) {
    ledState = !ledState;
    digitalWrite(LEDPIN, ledState);
  }

  // Let's save the button value
  prevButtonValue = buttonValue;

  // Add a little delay for debouncing the button
  delay(10);
}

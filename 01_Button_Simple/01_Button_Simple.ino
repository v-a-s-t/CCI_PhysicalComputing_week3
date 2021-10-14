#define LEDPIN 9
#define BUTTONPIN 5

int buttonValue;

void setup() {
  // Sets the LED pin to be an output
  pinMode(LEDPIN, OUTPUT);
  // Sets the button pin to be an input.
  pinMode(BUTTONPIN, INPUT);
}

void loop() {
  // Read button input
  buttonValue = digitalRead(BUTTONPIN);

  // Set LED state as button value
  digitalWrite(LEDPIN, buttonValue);

  // Add a little delay for debouncing the button
  delay(10);
}

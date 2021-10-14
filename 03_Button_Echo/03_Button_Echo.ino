#define LEDPIN 9
#define BUTTONPIN 5

// Variable to hold button value
int buttonValue;
// Variable to hold previous button value
int prevButtonValue;
// Variable to hold the number of clicks
int numOfClicks;

unsigned long lastClick;

void setup() {
  // Sets the LED pin to be an output
  pinMode(LEDPIN, OUTPUT);
  // Sets the button pin to be an input.
  pinMode(BUTTONPIN, INPUT);
}

void loop() {
  // Read button input
  buttonValue = digitalRead(BUTTONPIN);

  // If we have a new button press, add 1 to our number of clicks.
  if (buttonValue == HIGH && buttonValue != prevButtonValue) {
    // Store when the button was pressed.
    lastClick = millis();
    // Add 1 to number of clicks.
    numOfClicks = numOfClicks + 1;
  }

  // If 1 second has elapsed since the button was pressed...
  if (millis() - lastClick >= 1500) {
    // While we have clicks left, blink the LED.
    while(numOfClicks > 0) {
      digitalWrite(LEDPIN, HIGH);
      delay(100);
      digitalWrite(LEDPIN, LOW);
      delay(500);
      numOfClicks = numOfClicks - 1;
    }
  }

  // Let's save the button value
  prevButtonValue = buttonValue;

  // Add a little delay for debouncing the button
  delay(10);
}

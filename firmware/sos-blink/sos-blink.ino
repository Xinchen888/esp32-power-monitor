void flash(int onTime) {
  digitalWrite(LED_BUILTIN, HIGH);  // change state of the LED by setting the pin to the HIGH voltage level
  delay(onTime);                    // keep LED on for onTime ms (200 = short, 600 = long)
  digitalWrite(LED_BUILTIN, LOW);   // change state of the LED by setting the pin to the LOW voltage level
  delay(200);                       // LED off: short gap before the next flash
}

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  for (int i = 0; i < 3; i++) {
    flash(200);  // S
  }
  for (int i = 0; i < 3; i++) {
    flash(600);  // O
  }

  for (int i = 0; i < 3; i++) {
    flash(200);  // S
  }
  delay(2000);  // pause before repeating SOS
}

void flash(int onTime) {
  digitalWrite(LED_BUILTIN, HIGH);  // change state of the LED by setting the pin to the HIGH voltage level
  delay(onTime);                    // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // change state of the LED by setting the pin to the LOW voltage level
  delay(200);                       // wait for a second
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

void setup() {
    pinMode(LED_BUILTIN, OUTPUT); // Initialize the onboard LED pin
}

void loop() {
    digitalWrite(LED_BUILTIN, HIGH); // Turn the LED on
    delay(1000);                     // Wait for 1 second
    digitalWrite(LED_BUILTIN, LOW);  // Turn the LED off
    delay(1000);                     // Wait for 1 second
}

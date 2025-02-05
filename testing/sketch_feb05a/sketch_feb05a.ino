const int potPin = A0;  // Potentiometer input pin
const int ledPins[] = {7, 8, 9, 10, 11, 12, 13}; // LED pins
const int numLeds = 7;

void setup() {
    Serial.begin(9600); // Start serial communication at 9600 baud
    
    // Set LED pins as OUTPUT
    for (int i = 0; i < numLeds; i++) {
        pinMode(ledPins[i], OUTPUT);
    }
}

void loop() {
    int potValue = analogRead(potPin); // Read the potentiometer (0-1023)
    int ledCount = map(potValue, 0, 1023, 0, numLeds + 1); // Map to number of LEDs

    // Turn on LEDs according to the mapped value
    for (int i = 0; i < numLeds; i++) {
        digitalWrite(ledPins[i], i < ledCount ? HIGH : LOW);
    }

    // Send potentiometer value over Serial
    Serial.print("Potentiometer Value: ");
    Serial.println(potValue);

    delay(50); // Small delay for stability
}

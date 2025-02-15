#include <CapacitiveSensor.h>

// Define capacitive sensor for pitch (send: pin 12, receive: pin 8)
CapacitiveSensor cs_12_8 = CapacitiveSensor(12, 8);

const int potPin = A0;  // Potentiometer to control sensitivity
const int ledPins[] = {2, 3, 4, 5, 6, 7}; // LED pins
const int numLeds = 6;  // Total number of LEDs

void setup() {
    Serial.begin(9600);  // Start serial communication
    for (int i = 0; i < numLeds; i++) {
        pinMode(ledPins[i], OUTPUT); // Set LED pins as outputs
    }
}

void loop() {
    long touchValue = cs_12_8.capacitiveSensor(30); // Read cap sense data
    int potValue = analogRead(potPin);             // Read potentiometer (0-1023)

    // Map pot value to set the max touch range (1000 to 10000)
    int touchMax = map(potValue, 0, 1023, 200, 5000);

    // Constrain touch value to the adjustable max range
    touchValue = constrain(touchValue, 0, touchMax);

    // Map cap sense data to number of LEDs
    int ledCount = map(touchValue, 0, touchMax, 0, numLeds);

    // Turn on/off LEDs based on mapped value
    for (int i = 0; i < numLeds; i++) {
        digitalWrite(ledPins[i], i < ledCount ? HIGH : LOW);
    }

    // Debugging output
    Serial.print("Touch Value: ");
    Serial.print(touchValue);
    Serial.print(" / Max: ");
    Serial.println(touchMax);

    delay(50); // Small delay for stability
}

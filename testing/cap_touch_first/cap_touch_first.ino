#include <CapacitiveSensor.h>

// Define capacitive sensor for pitch (send: pin 4, receive: pin 2)
CapacitiveSensor cs_12_8 = CapacitiveSensor(12, 8);

const int volumePin = A0;  // Potentiometer for volume

void setup() {
    Serial.begin(9600);  // Start serial communication
}

void loop() {
    long pitchValue = cs_12_8.capacitiveSensor(30); // Read pitch sensor
    int volumeValue = analogRead(volumePin);       // Read potentiometer (0-1023)

    // Normalize pitch (adjusting sensitivity)
    pitchValue = constrain(pitchValue, 0, 1000);  // Cap the sensor range

    // Normalize volume (scale 0-1023 to 0-127 for MIDI velocity)
    int mappedVolume = map(volumeValue, 0, 1023, 0, 127);

    // Send pitch and volume as CSV
    Serial.print(pitchValue);
    Serial.print(",");
    Serial.println(mappedVolume);

    delay(50); // Small delay for stability
}

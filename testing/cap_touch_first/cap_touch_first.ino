#include <CapacitiveSensor.h>

// Define a single capacitive sensor with a 10M resistor between pin 4 (send) and pin 2 (receive)
CapacitiveSensor cs_4_2 = CapacitiveSensor(4, 2);

void setup() {
    
    Serial.begin(9600); // Start serial communication
}

void loop() {
    long total = cs_4_2.capacitiveSensor(30); // Read capacitive sensor value

    Serial.print("Sensor Value: ");
    Serial.println(total); // Print the sensor value to serial output

    delay(50); // Small delay to make output readable
}

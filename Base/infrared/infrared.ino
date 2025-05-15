#define IR_SENSOR_PIN 2  // Define the digital pin connected to the IR sensor

void setup() {
  Serial.begin(9600);              // Initialize serial communication
  pinMode(IR_SENSOR_PIN, INPUT);    // Set the IR sensor pin as an input
}

void loop() {
  int sensorValue = digitalRead(IR_SENSOR_PIN);  // Read the sensor output

  if (sensorValue == LOW) {  // If an obstacle is detected
    Serial.println("Obstacle detected!");
  } else {                   // No obstacle detected
    Serial.println("No obstacle.");
  }
  
  delay(500);  // Wait a bit before reading again
}

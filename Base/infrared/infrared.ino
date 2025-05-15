#define IR_SENSOR_PIN 2  

void setup() {
  Serial.begin(9600);             
  pinMode(IR_SENSOR_PIN, INPUT);    
}

void loop() {
  int sensorValue = digitalRead(IR_SENSOR_PIN);  

  if (sensorValue == LOW) { 
    Serial.println("Obstacle detected!");
  } else {                  
    Serial.println("No obstacle.");
  }
  
  delay(500);  
}

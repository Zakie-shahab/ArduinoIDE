unsigned long previousMillis = 0;
const unsigned long interval = 1000; // 1-second interval

void setup() {
  Serial.begin(115200);
}

void loop() {
  unsigned long currentMillis = millis();

  // Handle elapsed time correctly, even after wraparound
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    Serial.println("1 second elapsed");
  }
}
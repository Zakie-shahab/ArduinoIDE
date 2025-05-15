void setup() {
  Serial.begin(115200);
  pinMode(13, INPUT);  
}

void loop() {
  int buttonState = digitalRead(13);  

  if (buttonState == HIGH) {
    Serial.println("Ditekan");
  } else {
    Serial.println("Tidak ditekan");
  }

  delay(200);  
}
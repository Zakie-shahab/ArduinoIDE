#include <RH_ASK.h>
#include <SPI.h>

RH_ASK rf_driver;

void setup() {
  Serial.begin(115200);
  if (!rf_driver.init()) {
    Serial.println("RF module initialization failed!");
  }
}

void loop() {
  const char *msg = "Hello, ESP32!";
  rf_driver.send((uint8_t *)msg, strlen(msg));  // Send the message
  rf_driver.waitPacketSent();                   // Wait for it to finish sending
  Serial.println("Message sent: Hello, ESP32!");
  delay(1000);                                  // Wait before sending again
}

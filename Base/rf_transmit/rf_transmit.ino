#include <RH_ASK.h>
#include <SPI.h>

RH_ASK rf_driver;

void setup() {
  Serial.begin(115200);
  if (!rf_driver.init()) {
    Serial.println("RF module gagal!");
  }
}

void loop() {
  const char *msg = "Gas!";
  rf_driver.send((uint8_t *)msg, strlen(msg));  
  rf_driver.waitPacketSent();                  
  Serial.println("Message sent: Hello, ESP32!");
  delay(1000);                                  
}

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
  uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
  uint8_t buflen = sizeof(buf);

  if (rf_driver.recv(buf, &buflen)) {
    Serial.print("Message received: ");
    Serial.println((char*)buf);
  }
}

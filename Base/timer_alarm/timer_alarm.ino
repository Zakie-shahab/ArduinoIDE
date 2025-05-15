#define set_alarm 25
#define set_timer 14
#define up_hour 27
#define up_minute 26
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(set_alarm, INPUT);
  pinMode(set_timer, INPUT);
  pinMode(up_hour, INPUT);
  pinMode(up_minute, INPUT);
  lcd.init(); // initialize the lcd
  lcd.backlight();
  lcd.setCursor(0, 0);            // move cursor the first row
  lcd.print("Suhu : 30.00");          // print message at the first row
  lcd.setCursor(0, 1);            // move cursor to the second row
  lcd.print("Lembaban : 60%"); // print message at the second row
  lcd.setCursor(0, 2);            // move cursor to the third row
  lcd.print("Jumat, 1 Nov 2024");          // print message at the third row
  lcd.setCursor(0, 3);            // move cursor to the fourth row
  lcd.print("22:10:33 WIB");   // print message the fourth row
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(up_minute) == HIGH) {
    Serial.println("Oke");
  }
  else {
    Serial.println("Gak Oke");
  }
}

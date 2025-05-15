#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4); 

int cek = 0;

void setup() {
  Serial.begin(115200);
  lcd.init(); 
  lcd.backlight();
  lcd.setCursor(0, 0);            
  lcd.print("Suhu : 30.00");          
  lcd.setCursor(0, 1);           
  lcd.print("Lembaban : 60%"); 
  lcd.setCursor(0, 2);            
  lcd.print("Jumat, 1 Nov 2024");         
  lcd.setCursor(0, 3);           
  lcd.print("22:10:33 WIB"); 
}

void loop() {
  Serial.println(cek);
  delay(1000);
}

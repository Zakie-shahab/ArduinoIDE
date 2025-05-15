#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);  

// Button pins
const int setAlarmButton = 12;
const int hourButton = 13;
const int minuteButton = 14;

// Variables to store alarm time
int alarmHour = 0;
int alarmMinute = 0;
bool setMode = false;  // Indicates if we are in alarm-setting mode

void setup() {
  Serial.begin(115200);

  // Initialize LCD
  lcd.init();  // 20x4 LCD
  lcd.backlight();

  // Button setup with pull-up resistors
  pinMode(setAlarmButton, INPUT_PULLUP);
  pinMode(hourButton, INPUT_PULLUP);
  pinMode(minuteButton, INPUT_PULLUP);

  // Initial display
  lcd.clear();
  lcd.print("Press Set to Adjust");
  lcd.setCursor(0, 1);
  lcd.print("Alarm Time:");
  displayAlarmTime();  // Display initial alarm time
}

void loop() {
  if (digitalRead(setAlarmButton) == LOW) {  // If Set Alarm button is pressed
    delay(200);  // Debounce delay
    if (!setMode) {
      setMode = true;  // Enter alarm setting mode
      lcd.clear();
      lcd.print("Setting Alarm...");
      displayAlarmTime();
    } else {
      setMode = false;  // Exit setting mode and confirm alarm
      lcd.clear();
      lcd.print("Alarm Set For:");
      displayAlarmTime();
    }
  }

  if (setMode) {  // In alarm-setting mode
    if (digitalRead(hourButton) == LOW) {  // Increment hour
      delay(200);  // Debounce delay
      alarmHour = (alarmHour + 1) % 24;  // Wrap around at 24
      displayAlarmTime();
    }
    if (digitalRead(minuteButton) == LOW) {  // Increment minute
      delay(200);  // Debounce delay
      alarmMinute = (alarmMinute + 1) % 60;  // Wrap around at 60
      displayAlarmTime();
    }
  }
}

// Function to display alarm time on the LCD
void displayAlarmTime() {
  lcd.setCursor(0, 2);  // Set to third line
  lcd.print("Time: ");
  lcd.print(alarmHour < 10 ? "0" : "");  // Zero padding for single digit hour
  lcd.print(alarmHour);
  lcd.print(":");
  lcd.print(alarmMinute < 10 ? "0" : "");  // Zero padding for single digit minute
  lcd.print(alarmMinute);
  lcd.setCursor(0, 3);  // Fourth line for instruction
  lcd.print("Use Hour/Min Buttons");
}

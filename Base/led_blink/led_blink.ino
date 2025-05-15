#define alarm_on 18
#define timer_on 19

void setup() {
  // put your setup code here, to run once:
  pinMode(alarm_on, OUTPUT);
  pinMode(timer_on, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(alarm_on, HIGH);
  digitalWrite(timer_on, HIGH);
  delay(3000);
  digitalWrite(alarm_on, LOW);
  digitalWrite(timer_on, LOW);
  delay(3000);
}

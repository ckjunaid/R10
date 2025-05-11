#define DIR_PIN 3
#define PWM_PIN 5

void setup() {
  pinMode(DIR_PIN, OUTPUT);
  pinMode(PWM_PIN, OUTPUT);
}

void loop() {
  // Forward
  digitalWrite(DIR_PIN, HIGH);
  analogWrite(PWM_PIN, 200);
  delay(3000);
analogWrite(PWM_PIN, 0);
delay(1000);
  // Reverse
  digitalWrite(DIR_PIN, LOW);
  analogWrite(PWM_PIN, 200);
  delay(3000);
}

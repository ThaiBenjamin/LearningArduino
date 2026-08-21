#define POTENTIOMETER_PIN A2
#define LED_PIN 11
void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(LED_PIN, analogRead(POTENTIOMETER_PIN)/4);
}

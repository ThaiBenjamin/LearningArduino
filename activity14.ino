#define ECHO_PIN 3
#define TRIGGER_PIN 4 

unsigned long lastTimeUltrasonicTrigger = millis();
unsigned long ultrasonicTriggerDelay = 100;

void triggerUltrasonicSensor(){
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
}

double getUltrasonicDistance(){
  unsigned long pulseInStart = micros();
  double durationMicros = pulseIn(ECHO_PIN, HIGH);
  unsigned long pulseInEnd = micros();
  Serial.print("Duration: ");
  Serial.println((pulseInEnd-pulseInStart));
  double distance = durationMicros / 148.0; // cm (58.0)
  return distance;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIGGER_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long timeNow = millis();

  if (timeNow - lastTimeUltrasonicTrigger > ultrasonicTriggerDelay) {
    lastTimeUltrasonicTrigger += ultrasonicTriggerDelay;
    triggerUltrasonicSensor();
    Serial.println(getUltrasonicDistance());
  }
}

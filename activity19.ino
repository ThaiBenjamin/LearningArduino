#define PHOTORESISTOR_PIN A0
#define LED_1_PIN 12
#define LED_2_PIN 10

#define LUMINOSITY_NIGHT_THRESHOLD 330


void setup() {
  // put your setup code here, to run once:
  pinMode(LED_1_PIN, OUTPUT);
  pinMode(LED_2_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int luminosity = analogRead(PHOTORESISTOR_PIN);
  
  if (luminosity < LUMINOSITY_NIGHT_THRESHOLD){
    digitalWrite(LED_1_PIN, HIGH);
  }

  else {
    digitalWrite(LED_1_PIN, LOW);
  }

  int brightness = 255 - luminosity / 4;
  analogWrite(LED_2_PIN, brightness);
}

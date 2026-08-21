#define LED_PIN 12
#define LED_PIN_2 11
#define LED_PIN_3 10
#define BUTTON_PIN 2
#define POTENTIOMETER_PIN A2

int delayTime = 500;
int LEDState = LOW;
unsigned long previousTimeLEDBlink = millis();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.setTimeout(10);

  pinMode(LED_PIN, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);
  pinMode(LED_PIN_3, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  pinMode(POTENTIOMETER_PIN, INPUT);
  

  digitalWrite(LED_PIN, LOW);
  digitalWrite(LED_PIN_2, LOW);
  digitalWrite(LED_PIN_3, LOW);
}

void loop() {
  if (Serial.available() > 0){
    int data = Serial.parseInt(); 
    if (data >= 100 and data <= 1000){
      delayTime = data;
    }
  }
  
  unsigned long timeNow = millis();

  
  if (timeNow - previousTimeLEDBlink >= delayTime){
    if (LEDState == LOW){
      LEDState = HIGH;
    }
    else{
      LEDState = LOW;
    }
    digitalWrite(LED_PIN, LEDState);
    previousTimeLEDBlink += delayTime;
  }

  // 1. set LED 2 (pin 11) brightness from potentiometer
  analogWrite(LED_PIN_2, analogRead(POTENTIOMETER_PIN)/4);
  // 2. power on LED 3 when button is pressed
  if(digitalRead(BUTTON_PIN) == HIGH){
    digitalWrite(LED_PIN_3, HIGH);
  }
  else{
    digitalWrite(LED_PIN_3, LOW);
  }
}

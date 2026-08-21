#define LED_PIN 12

int delayTime = 500;
int LEDState = LOW;
unsigned long previousTimeLEDBlink = millis();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.setTimeout(10);

  pinMode(LED_PIN, OUTPUT);
  

  digitalWrite(LED_PIN, LOW);
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
}

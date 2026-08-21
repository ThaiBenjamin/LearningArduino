#define LED_1 12
#define LED_2 11
#define LED_3 10
#define BUTTON_PIN 2

unsigned long lastTimeLED1Blinked = millis();
unsigned long blinkDelayLED1 = 1000;
byte LED1State = LOW;

unsigned long lastTimeButtonChanged = millis();
unsigned long debounceDelay = 100;
byte buttonState = LOW;

int toggleLEDState = 1;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  digitalWrite(LED_1, LOW);
  digitalWrite(LED_2, LOW);
  digitalWrite(LED_3, LOW);
}

void blinkLED1(){
  if(LED1State == LOW){
      LED1State = HIGH;
    }
    else{
      LED1State = LOW;
    }
    digitalWrite(LED_1, LED1State);
}

void toggleOtherLEDS(){
  if (toggleLEDState == 1){
          toggleLEDState = 2;
          digitalWrite(LED_2, LOW);
          digitalWrite(LED_3, HIGH);
        }
      
  else{
    toggleLEDState = 1;
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_3, LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long timeNow = millis();
  if(timeNow - lastTimeLED1Blinked > blinkDelayLED1){
    lastTimeLED1Blinked += blinkDelayLED1;
    blinkLED1();
  }

  if(timeNow - lastTimeButtonChanged > debounceDelay){
    byte newButtonState = digitalRead(BUTTON_PIN);
    if(newButtonState != buttonState){
      lastTimeButtonChanged = timeNow;
      buttonState = newButtonState;
      if (buttonState == HIGH){
        toggleOtherLEDS();
      }
    }
    
  }
}

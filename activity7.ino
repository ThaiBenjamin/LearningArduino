#define RED_PIN 12
#define YELLOW_PIN 11
#define GREEN_PIN 10
#define BUTTON_PIN 2

#define LED_PIN_ARRAY_SIZE 3
int LED_BLINK_STATE = 1;
byte LEDPinArray[LED_PIN_ARRAY_SIZE] = 
    {RED_PIN, YELLOW_PIN, GREEN_PIN};
void setLEDPinModes(){
  for(int i =0; i < LED_PIN_ARRAY_SIZE; i++){
    pinMode(LEDPinArray[i], OUTPUT);
  }
}

void turnOffAllLEDs(){
  for(int i =0; i < LED_PIN_ARRAY_SIZE; i++){
    digitalWrite(LEDPinArray[i], LOW);
  }
}

void toggleLEDs(){
  if (LED_BLINK_STATE == 1){
    digitalWrite(RED_PIN, HIGH);
    digitalWrite(GREEN_PIN, HIGH);
    digitalWrite(YELLOW_PIN, LOW);
    LED_BLINK_STATE = 2;
  }
  else{
    digitalWrite(RED_PIN, LOW);
    digitalWrite(GREEN_PIN, LOW);
    digitalWrite(YELLOW_PIN, HIGH);
    LED_BLINK_STATE = 1;
  }
}

void setup() {
  pinMode(BUTTON_PIN, INPUT);
  setLEDPinModes();
  turnOffAllLEDs();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(BUTTON_PIN) == LOW){
    toggleLEDs();
    delay(300);
  }
}

#define BUTTON_PIN 2

volatile unsigned long lastTimeButtonPressed = millis();
unsigned long debounceDelay = 50;
volatile bool buttonPressed = false;
int buttonCount = 0; 

void printButtonNumber(){
  buttonCount++;
  Serial.print("Counter is: ");
  Serial.println(buttonCount);
}
void buttonPressedLED(){
  unsigned long timeNow = millis();

  if(timeNow - lastTimeButtonPressed > debounceDelay){
    buttonPressed = true;
  }
  
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), buttonPressedLED, RISING);

  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(buttonPressed){
    buttonPressed = false;
    printButtonNumber();
  }
}

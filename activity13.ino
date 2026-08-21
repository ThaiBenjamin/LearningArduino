#include <EEPROM.h>

#define POTENTIOMETER_PIN A2 
#define LED_PIN 11

#define EEPROM_ADDRESS_MAX_BRIGHTNESS 350
#define MAX_BRIGHTNESS_DEFAULT 255
byte maxBrightness;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.setTimeout(10);
  pinMode(LED_PIN, OUTPUT);

  maxBrightness = EEPROM.read(EEPROM_ADDRESS_MAX_BRIGHTNESS);

  if (maxBrightness == 0){
    maxBrightness = MAX_BRIGHTNESS_DEFAULT;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){
    int data = Serial.parseInt();
    if((data >= 0) && (data < 256)){
      EEPROM.write(EEPROM_ADDRESS_MAX_BRIGHTNESS, data);
      maxBrightness = data;
    }
  }

  byte LEDBrightness = analogRead(POTENTIOMETER_PIN)/4;
  

  if (LEDBrightness > maxBrightness) {
    LEDBrightness = maxBrightness;
  }
  
  analogWrite(LED_PIN, LEDBrightness);


}

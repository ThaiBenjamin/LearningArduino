#include <LiquidCrystal.h>

#define LCD_RS_PIN A5
#define LCD_E_PIN A4
#define LCD_D4_PIN 6
#define LCD_D5_PIN 7
#define LCD_D6_PIN 8
#define LCD_D7_PIN 9

LiquidCrystal lcd(LCD_RS_PIN, LCD_E_PIN, LCD_D4_PIN, LCD_D5_PIN, LCD_D6_PIN, LCD_D7_PIN);

int cursorLine = 0;

void printUserTextOnDisplay(String text){
  if (text.length() > 16){
    text = "Text too long";
  }

  for (int i = text.length(); i < 16; i++){
    text += " ";
  }

  lcd.setCursor(0, cursorLine);
  lcd.print(text);

  if (cursorLine == 0){
    cursorLine = 1;
  }
  else{
    cursorLine = 0;
  }

 
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.setTimeout(10);
  lcd.begin(16,2);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0){
    String text = Serial.readString();
    printUserTextOnDisplay(text);
  }
}

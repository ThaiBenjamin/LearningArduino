#define RED_PIN 12
#define YELLOW_PIN 11
#define GREEN_PIN 10
int delayTime = 500;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.setTimeout(10);

  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);

  digitalWrite(RED_PIN, LOW);
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
}

void loop() {
  if (Serial.available() > 0){
    int data = Serial.parseInt(); 
    if (data >= 100 and data <= 1000){
      delayTime = data;
    }
  }
  
  digitalWrite(RED_PIN, HIGH);
  delay(delayTime);
  digitalWrite(RED_PIN, LOW);
  digitalWrite(YELLOW_PIN, HIGH);
  delay(delayTime);
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
  delay(delayTime);
  digitalWrite(GREEN_PIN, LOW);
}

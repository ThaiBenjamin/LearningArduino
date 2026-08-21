#define PHOTORESISTOR_PIN A0

#define LUMINOSITY_SAMPLES_SIZE 100

int luminositySamples[LUMINOSITY_SAMPLES_SIZE] = { 0 };
int indexCounter = 0;

unsigned long photoStartTime = millis();
unsigned long photoDelay = 50;

int computeAverageLuminosity(){
  long sum = 0;
  for (int i = 0; i < LUMINOSITY_SAMPLES_SIZE; i++){
    sum += luminositySamples[i];
  } 

  return sum/LUMINOSITY_SAMPLES_SIZE;
}

void printAverageLuminosity(){
  int average = computeAverageLuminosity();
  Serial.println("");
  Serial.print("Average luminosity for ");
  Serial.print(LUMINOSITY_SAMPLES_SIZE);
  Serial.print(" samples, taken every ");
  Serial.print(photoDelay);
  Serial.print(" milliseconds: ");
  Serial.print(average);
  Serial.println("");
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long timeNow = millis();
  
  if (timeNow - photoStartTime > photoDelay) {
    photoStartTime += photoDelay;
    if (indexCounter == LUMINOSITY_SAMPLES_SIZE) {
      indexCounter = 0;
      printAverageLuminosity();
    }
    luminositySamples[indexCounter] = analogRead(PHOTORESISTOR_PIN);
    indexCounter++;
    Serial.print(".");
  }
}

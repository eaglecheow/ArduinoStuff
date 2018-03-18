int ledPin = 41;

long previousTime = 0;
int ledState = LOW;

void setup() 
{
  Serial.begin(9600);
  previousTime = millis();
  pinMode(ledPin, OUTPUT);
}

void loop() 
{
  long currentTime = millis();
  if ((currentTime - previousTime) > 1000)
  {
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
    Serial.println((ledState == LOW)?"LED is OFF": "LED is ON");
    previousTime = currentTime;
  }
}

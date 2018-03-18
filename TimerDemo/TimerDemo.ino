class Blink
{
  int LedPin;
  float BlinkFrequency;
  int LedState;
  unsigned long CurrentTime;
  unsigned long PreviousTime;

  public:
  Blink(int ledPin, int blinkFrequency)
  {
    LedPin = ledPin;
    pinMode(LedPin, OUTPUT);
    BlinkFrequency = blinkFrequency;
    LedState = LOW;
    PreviousTime = millis();
  }

  void Update()
  {
    CurrentTime = millis();
    float blinkPeriod = ((float)(1/BlinkFrequency))*1000;
    if ((CurrentTime - PreviousTime) > blinkPeriod)
    {
      LedState = !LedState;
      digitalWrite(LedPin, LedState);
      PreviousTime = CurrentTime;
    }
  }
};

Blink* ledOne = new Blink(31,5);
Blink* ledTwo = new Blink(41, 50);

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  ledOne->Update();
  ledTwo->Update();
}

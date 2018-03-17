bool isOn = false;
bool toggle = false;

int ledPin = 35;
int buzzerPin = 31;
int sensorInput = A0;
int switchPin = A1;

void setup() 
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() 
{
  if (SwitchCode() == true)
  {
    SensorCode();
  }
}

bool SwitchCode()
{
  if (analogRead(switchPin) > 1000 && toggle == false)
  {
    isOn = !isOn;
    toggle = true;
    Serial.println(isOn?"Sensor is turned ON": "Sensor is turned OFF");
  }
  else if (analogRead(switchPin) <= 1000 && toggle == true)
  {
    toggle = false;
  }

  if (isOn == true)
  {
    return true;
  }
  return false;
}

void SensorCode()
{
  int sensorValue = analogRead(sensorInput);
  if (sensorValue < 1000)
  {
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
  }
  else 
  {
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
  }
}


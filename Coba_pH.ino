const int pHSensorPin = A0;

const float avgAnalogValueBase = 257.5;   
const float avgAnalogValueNeutral = 321.7;   
const float avgAnalogValueAcid = 402.9;  

const float pHBase = 9.18;    
const float pHNeutral = 6.86;  
const float pHAcid = 4.0;     

float slope;
float intercept;

void setup() {
  Serial.begin(9600);
  slope = ( (pHBase - pHNeutral) / (avgAnalogValueBase - avgAnalogValueNeutral) + (pHNeutral - pHAcid) / (avgAnalogValueNeutral - avgAnalogValueAcid) ) / 2;
  intercept = pHNeutral - (slope * avgAnalogValueNeutral);
}

void loop() {
  int analogValue = analogRead(pHSensorPin);
  float pHValue = (analogValue * slope) + intercept;
  Serial.print("Analog Value: ");
  Serial.print(analogValue);
  Serial.print(" -> pH Value: ");
  Serial.println(pHValue);
  delay(1000);
}
int sensorPin = A0;
int relayPin = 7;

void setup() {
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);

  // Relay OFF
  digitalWrite(relayPin, HIGH);
}

void loop() {
  int moistureValue = analogRead(sensorPin);

  Serial.print("Moisture: ");
  Serial.print(moistureValue);

  if (moistureValue < 450) {
    digitalWrite(relayPin, HIGH);
    Serial.println(" -> WET | RELAY OFF");
  } 
  else {
    digitalWrite(relayPin, LOW);
    Serial.println(" -> DRY | RELAY ON");
  }

  delay(3000);
}
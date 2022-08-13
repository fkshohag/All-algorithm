int pin9 = 9;

void setup() {
  pinMode(pin9, OUTPUT);
}

void loop() {
  digitalWrite(pin9, HIGH);
  delay(1000);
  digitalWrite(pin9, LOW);
  delay(1000);
}
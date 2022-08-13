int pin9 = 9, pin8 = 8, pin10 = 10;

void setup() {
  pinMode(pin8, OUTPUT);
  pinMode(pin9, OUTPUT);
  pinMode(pin10, OUTPUT);
}

void loop() {

  digitalWrite(pin8, HIGH);
  delay(1000);
  digitalWrite(pin8, LOW);
  delay(1000);

  digitalWrite(pin9, HIGH);
  delay(1000);
  digitalWrite(pin9, LOW);
  delay(1000);

  digitalWrite(pin10, HIGH);
  delay(1000);
  digitalWrite(pin10, LOW);
  delay(1000);
}
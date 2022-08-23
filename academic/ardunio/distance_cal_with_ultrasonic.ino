int trigPin = 8, echoPin = 9;
float distance, duration;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delay(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.03518) / 2;
  Serial.print("The distance is : ");
  Serial.print(distance);
  Serial.println("cm");
  delay(500);
}

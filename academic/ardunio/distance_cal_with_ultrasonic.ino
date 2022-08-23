/*
Explanation:
0 degree tempature sound velocity             = 332 m/s
1 degree increase tempature velocity increase = 0.6 m/s
33 degree                                     = 332 + (6 * 33)
                                              = 3518 m/s
Romm tempature = 35
1 s = 3518 msc;
x = ((3518) * x) / 10 ^ 6
x = 0.00003518 m
x = 0.03518 s
*/


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

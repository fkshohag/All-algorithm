Servo myServo;
int buzzer = 7;
int trigPin = 8;
int echoPin = 9;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  lcd.display();

  for (int i = 45; i < 145; i++) {
    distance = 0;
    myServo.write(i);
    delay(100);
    distance = calculateDistance();

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.setCursor(6, 0);
    lcd.print(i);

    // lcd.print
    lcd.setCursor(",");
    lcd.print("deg");
    lcd.setCursor(0, 1);
    lcd.print("Distance=");
    lcd.setCursor(9 ,1);
    lcd.print(distance);
    lcd.setCursor(13, 1);
    lcd.print("cm");
  }
}

int calculateDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  if (distance < 10) {
    tone(buzzer, 1000);
    delay(200);
    noTone(buzzer);
  }
  return distance;
}

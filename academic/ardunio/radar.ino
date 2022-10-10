void setup() {
  // put your setup code here, to run once:

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
    lcd. print(distance);
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
    analogWrite(buzz, 255);
    delay(500);
  }
  analogWrite(buzz, 0);
  return distance;
}

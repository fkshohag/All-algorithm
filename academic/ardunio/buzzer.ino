int trigPin8 = 8;
int echoPin9 = 9;
int buzzer7 = 7;


/*
Explanation:
0 degree tempature sound velocity             = 332 m/s
1 degree increase tempature velocity increase = 0.6 m/s
33 degree                                     = 332 + (6 * 33)
                                              = 3518 m/s
Romm tempature = 33
1 s = 3518 msc;
x = ((3518) * x) / 10 ^ 6
x = 0.00003518 m
x = 0.03518 s
*/
float velocity_of_sound = 0.03518;

void setup() {
  pinMode(trigPin8, OUTPUT);
  pinMode(echoPin9, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin8, LOW);
  delay(5);
  digitalWrite(trigPin8, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin8, LOW);

  float duration = pulseIn(echoPin9, HIGH);
  float distance = (duration * velocity_of_sound) / 2;
  Serial.print("The distance is : ");
  Serial.print(distance);
  Serial.print("cm");


  if (distance < 10) {
    tone(buzzer7, 1000);
    delay(200);
    noTone(buzzer7);
  }
  else if (distance > 10 && distance < 20) {
    for (int i = 0; i < 2; i++) {
      tone(buzzer7, 1000);
      delay(200);
      noTone(buzzer7);
    }
  }
  else {
    for (int i = 0; i < 3; i++) {
      tone(buzzer7, 1000);
      delay(200);
      noTone(buzzer7);
    }
  }
}

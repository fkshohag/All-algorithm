#include <Servo.h>
Servo servo;
int pos;

void setup() {
  servo.attach(9);
}

void loop() {
  for (pos = 0; pos <= 180; pos++){
    servo.write(pos);
    delay(20);
  }
  delay(1000);
  for (pos = 180; pos >= 90; pos--) {
    servo.write(pos);
    delay(20);
  }
  delay(10000);
  for (pos = 90; pos <= 180; pos++) {
    servo.write(pos);
    delay(20);
  }
  delay(1000);
}

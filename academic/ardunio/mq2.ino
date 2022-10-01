#include <MQ2.h>
int input = A0;
int lpg, co, smoke;
int buzzer7 = 7;

MQ2 mq2(input);

void setup() {
  Serial.begin(9600);
  mq2.begin();

}

void loop() {
  float * arr = mq2.read(true);
  lpg = mq2.readLPG();
  co = mq2.readCO();
  smoke = mq2.readSmoke();

  Serial.print("lpg amount");
  Serial.println(lpg);

  Serial.print("co amount");
  Serial.print(smoke);

  if(smoke > 20) {
    tone(buzzer7, 3000);
    delay(200);
    noTone(buzzer7);
  }
  delay(2000);
}

#include <dht.h>
dth DTH;

int pin7 = 7;


void setup() {
  Serial.begin(9600);
}

void loop() {
  int variable = DTH.read11(pin7);
  int temperature = DTH.temperature;
  int humidity = DTH.humidity;

  Serial.print("Temperature");
  Serial.print(temperature);
  Serial.println("");

  if (temperature < 25) {
    Serial.print("Cold temperature:");
    Serial.println(humidity);

    Serial.print("Room temperature: ");
    Serial.println(temperature);
    Serial.print("Current humidity is : ");
  }
  else if (temperature == 25){
    Serial.print("Normal temperature:");
    Serial.println(humidity);

    Serial.print("Room temperature: ");
    Serial.println(temperature);
    Serial.print("Current humidity is : ");
  }
  else {
    Serial.print("Cold temperature:");
    Serial.println(humidity);

    Serial.print("Room temperature: ");
    Serial.println(temperature);
    Serial.print("Current humidity is : ");
  }
}

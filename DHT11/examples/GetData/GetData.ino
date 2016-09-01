#include "DHT11.h"
DHT11 dht11(2);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  dht11.requestData();
  Serial.println("Temperture : " + String(dht11.getTemperature()) + "C , Humidity : " + String(dht11.getHumidity()) + "%");
  delay(10*1000);
}

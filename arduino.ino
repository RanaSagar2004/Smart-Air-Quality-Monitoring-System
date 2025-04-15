
// Smart Air Quality Monitoring System - Arduino Code (ESP8266)
#include <MQ135.h>
#include <MQ7.h>
#include <DHT.h>

#define DHTPIN D4
#define DHTTYPE DHT11

MQ135 mq135_sensor(A0);
MQ7 mq7_sensor(A0);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  float co2 = mq135_sensor.getPPM();
  float co = mq7_sensor.readPpm();

  Serial.print("Temp: "); Serial.print(temperature);
  Serial.print("C, Humidity: "); Serial.print(humidity);
  Serial.print("%, CO2: "); Serial.print(co2);
  Serial.print(" ppm, CO: "); Serial.println(co);

  delay(2000);
}

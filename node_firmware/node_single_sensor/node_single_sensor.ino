#include <DHT.h>

#define DHT_PIN 15
#define DHT_TYPE DHT22

DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println();
  Serial.println("================================");
  Serial.println("HeatTrace Node 1");
  Serial.println("DHT22 Sensor Test");
  Serial.println("================================");

  dht.begin();
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("N1 | DHT22 read failed");
  } else {
    Serial.print("N1 | Temp: ");
    Serial.print(temperature, 2);
    Serial.print(" C | Humidity: ");
    Serial.print(humidity, 2);
    Serial.println(" %");
  }

  delay(2000);
}

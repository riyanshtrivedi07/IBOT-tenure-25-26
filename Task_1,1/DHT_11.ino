#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float humidity =  dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)){
    Serial.println("Failed to read temperature and humidity");
    return
  }
  Serial.println("Temperature : ");
  Serial.println(temperature);
  Serial.println(" C");

  Serial.println("Humidity : ");
  Serial.println(humidity);
  Serial.println(" %");
}

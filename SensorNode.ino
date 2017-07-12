#include <Adafruit_Sensor.h>
#include <DHT.h>

#define DHTPIN 7       // what pin we're connected to
#define DHTTYPE DHT22  // DHT 22  (AM2302)

DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor for normal 16mhz Arduino

float temp;
float hum;
int sensorID = 2;
String message;

void setup() {
    Serial.begin(9600);    
}

float convertCelciusToFahrenheit(float c) {
  return c * 1.8 + 32; 
}

String buildMessage(int sensorId, float temperature, float humidity, String delimiter = "/") {
  return String(sensorId) + delimiter + String(temperature) + delimiter + String(humidity);
}

void loop() {
  temp = convertCelciusToFahrenheit(dht.readTemperature());
  hum = dht.readHumidity();

  message = buildMessage(sensorID, temp, hum);
  Serial.println(message);
}

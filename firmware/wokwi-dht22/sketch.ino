#include <DHT.h>

const int LED_PIN = 13;    // LED on GPIO 13
const int DHT_PIN = 15;    // DHT22 data pin on GPIO 15
#define DHT_TYPE DHT22     // Sensor model

DHT dht(DHT_PIN, DHT_TYPE);   // Create the sensor object

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  dht.begin();                // Start the sensor
  Serial.println("DHT22 test started");
}

void loop() {
  float temperature = dht.readTemperature();   // Celsius
  float humidity = dht.readHumidity();         // Percent

  // Check that the reading worked
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT22");
  } else {
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" C  |  Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");
  }

  // Blink the LED once per reading
  digitalWrite(LED_PIN, HIGH);
  delay(100);
  digitalWrite(LED_PIN, LOW);

  delay(2000);   // DHT22 needs about 2 seconds between readings
}

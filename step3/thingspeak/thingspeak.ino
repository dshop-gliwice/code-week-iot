#include <DHT.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>


#define DHTPIN            D4         // Pin which is connected to the DHT sensor.
#define DHTTYPE           DHT11

DHT dht(DHTPIN, DHTTYPE);

uint32_t delayMS = 20000;
const char* ssid = "SSID"; // your WIFI SSID
const char* password = "PASS"; // your WIFI password
String API_KEY = "ABCDEF0123456"; // Write API Key from ThingSpeak.com

void updateChannel(float t, float h) {
  HTTPClient client;
  client.begin("https://api.thingspeak.com/update?api_key="
               + API_KEY + "&field1=" + String(t) + "&field2=" + String(h),
               "78 60 18 44 81 35 BF DF 77 84 D4 0A 22 0D 9B 4E 6C DC 57 2C"); // SHA-1 Fingerprint
  int httpCode = client.GET();
  Serial.println("Request sent");

  if (httpCode == 200) {
    Serial.print("Reqeuest response: ");
    Serial.println(client.getString());
  } else {
    Serial.printf("Request failed, error: %s\n", client.errorToString(httpCode).c_str());
  }
  Serial.flush();
  client.end();
}

void setup() {
  Serial.begin(115200);
  Serial.println("Init DHT");
  dht.begin();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  Serial.flush();
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(250);
    Serial.print(".");
  }
  Serial.println();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
  } else {
    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.println("%");

    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.println(" *C");
    updateChannel(t, h);
  }

  delay(delayMS);
}

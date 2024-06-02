#include "DHT.h"
#define DHTPIN 2     // Which pin the Data pin will be connected to


//selecting the sensor to be used
#define DHTTYPE DHT11   // DHT 11 
//#define DHTTYPE DHT22   // DHT 22  (AM2302)
//#define DHTTYPE DHT21   // DHT 21 (AM2301)


//sensor initialization
DHT dht(DHTPIN, DHTTYPE);


void setup() {
  Serial.begin(9600); 
  dht.begin();
}


void loop() {
  // reading temperature and humidity will take approximately 250 milliseconds
  int h = dht.readHumidity();
  int t = dht.readTemperature();

  // check if the data is correct
  if (isnan(t) || isnan(h)) {
    Serial.println("Error reading from DHT");
  } else {
    delay (2000);
    Serial.print("Humidity: "); 
    Serial.print(h);
    Serial.print("%");
    Serial.print(" Temperature: "); 
    Serial.print(t);
    Serial.println(" *C");
  }
}




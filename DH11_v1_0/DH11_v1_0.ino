#include <DHT.h>


#define DHTPIN 2     // what pin we're connected to

#define DHTTYPE DHT11   // DHT 11 
//#define DHTTYPE DHT22   // DHT 22  (AM2302)
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600); 
  //Serial.println("Sensors Activated");
  pinMode(13, OUTPUT);
  dht.begin();
}

void loop() {

  
  digitalWrite(13, LOW);
  delay(2500);
  digitalWrite(13, HIGH);   // set the LED on

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old'
  float h = dht.readHumidity();
  // Read temperature as Celsius
  float t = dht.readTemperature();
  
  // Read temperature as Fahrenheit
  float f = dht.readTemperature(true);
  
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Compute heat index
  // Must send in temp in Fahrenheit!
  float hi = dht.computeHeatIndex(f, h);

  
  Serial.print("Humidity: "); 
  Serial.print(h);
  Serial.print(" %\t");

  Serial.print("Temperature: "); 
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(" \t");
  //Serial.print(f);
  //Serial.print(" *F\t");
  Serial.print(" \t");
  
  Serial.print("Heat index: ");
  Serial.print(hi);
  Serial.println(" *F");
}

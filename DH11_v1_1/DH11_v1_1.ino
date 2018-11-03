#include <DHT.h>

// what pin on sheild connected to
#define DHTPIN 2

// DHT 11 sensor 
#define DHTTYPE DHT11   

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600); 
  //Serial.println("Sensors Activated");
  pinMode(13, OUTPUT);
  dht.begin();
}
  



void loop() {
  
  //loop to count the amount of readings
  for(int i=1; i > 0; i++){
  
    //Turn off led for 1.5 sec
    digitalWrite(13, LOW);
    delay(1500);
  
  
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

    //print the count, amount of readings taken
    Serial.print(i);
    Serial.print(" \t");
    
    //print Humidity
    Serial.print("Humidity: "); 
    Serial.print(h);
    Serial.print(" %\t");
    
    //print the temperature in degrees celsius
    Serial.print("Temperature: "); 
    Serial.print(t);
    Serial.print(" *C ");
    Serial.print(" \t");
    
    //print the temperature in degrees fahrenheit
    //Serial.print(f);
    //Serial.print(" *F\t");
    //Serial.print(" \t");
    
    
    //print the heat index
    Serial.print("Heat index: ");
    Serial.print(hi);
    Serial.println(" *F");
    
    //turn on led for 1 second
    digitalWrite(13, HIGH);
    delay(1000);
  }
}

#include <dht.h>
#define dht_apin A0 
dht DHT;
float h;
float t;


void setup(){
  Serial.begin(9600);
  Serial.println("DHT11 Humidity & temperature Sensor");
}
 
void loop(){
    DHT.read11(dht_apin);
    h = DHT.humidity;
    t = DHT.temperature;
    Serial.print("Current humidity = ");
    Serial.print(h);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(t); 
    Serial.println("*C  ");
    delay(5000);
}

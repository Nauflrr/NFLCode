#include <DHT.h>
#define DHTTYPE DHT11

const int DHTPin = 2; //bisa diganti dengan pin digital input lain
DHT dht(DHTPin, DHTTYPE);
int relay = 8;
  
void setup(){
  Serial.begin(9600);
  dht.begin();
  pinMode(relay,OUTPUT);
}
void loop(){
  float t = dht.readTemperature(); //untuk suhu dalam bentuk celcius

  Serial.print("Suhu      : ");
  Serial.print(t);
  Serial.println(" °C ");
  Serial.print ("========== ");
  delay(2000);
  
  if(t < 28){
  digitalWrite(relay,LOW);
  Serial.println(" Lampu Menyala");
  }
  if(t > 30){
  digitalWrite(relay,HIGH);
  Serial.println(" Lampu Mati");
    }
}
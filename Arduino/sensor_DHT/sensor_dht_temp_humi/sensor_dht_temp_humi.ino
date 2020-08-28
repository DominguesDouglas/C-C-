
#include <Adafruit_Sensor.h> // Biblioteca DHT Sensor Adafruit
#include <DHT.h>
#include <DHT_U.h>
#define DHTTYPE DHT11 // Sensor DHT11
#define DHTPIN 2 // Pino do Arduino no Sensor (Data)

DHT_Unified dht(DHTPIN, DHTTYPE); // configurando o Sensor DHT - pino e tipo

uint32_t delayMS = 1500; // variável para atraso 

void setup()
{
Serial.begin(9600); // monitor serial 9600 bps
dht.begin(); // inicializa a função
Serial.println("Usando o Sensor DHT");
sensor_t sensor;
}

void loop()
{
  delay(delayMS); // atraso entre as medições
  
  sensors_event_t event; // inicializa o evento da Temperatura
  
  dht.temperature().getEvent(&event); // faz a leitura da Temperatura
  
  if (isnan(event.temperature)) // se algum erro na leitura
  {
    Serial.println("Erro na leitura da Temperatura!");
  }
  else 
  {
    Serial.print("Temperatura: "); 
    Serial.print(event.temperature);
    Serial.println(" *C");
  }
  
  dht.humidity().getEvent(&event); // faz a leitura de umidade
  
  if (isnan(event.relative_humidity)) // se algum erro na leitura
  {
    Serial.println("Erro na leitura da Umidade!");
  }
  else 
  {
    Serial.print("Umidade: "); // imprime a Umidade
    Serial.print(event.relative_humidity);
    Serial.println("%");
  }
}

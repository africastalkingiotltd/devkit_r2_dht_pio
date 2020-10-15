#include <DHT.h>

#define SerialMon Serial

void getTemperature(void);
void getHumidity(void);


#define DHT_PIN PB0
#define LED_PIN PC13

#define DHTTYPE DHT11

DHT dht(DHT_PIN, DHTTYPE);
char buffer[100];
void setup()
{
  SerialMon.begin(115200);
  delay(100);
  while (!SerialMon)
  {
    ;
  }

  pinMode(LED_PIN, OUTPUT);
  pinMode(DHT_PIN, INPUT);
  delay(100);
  dht.begin();
}

void loop()
{

  getTemperature();
  getHumidity();
  delay(1500);
}


void getHumidity(void)
{
  delay(2000);
  float humidity = dht.readHumidity();
  dtostrf(humidity, 3, 2, buffer);
  SerialMon.print("Humidity: ");
  SerialMon.println(buffer);
  if(humidity > 50)
  {
      digitalWrite(LED_PIN, !(digitalRead(LED_PIN)));
      delay(1000);
  }
}

void getTemperature(void)
{
  delay(2000);
  float temperature = dht.readTemperature();
  dtostrf(temperature, 3, 2, buffer);
  SerialMon.print("Temperature: ");
  SerialMon.println(buffer);
}
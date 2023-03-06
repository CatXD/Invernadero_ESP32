#include "def_pines.h"

#include "interfaz_hm.h"
#include <ESP32Time.h>
#include "DHT.h"
#define DHT_TYPE DHT22

ESP32Time rtc;

TaskHandle_t _tarea2;

  DHT dht{DHT_PIN, DHT_TYPE};

Interfaz_hm interfaz;

char buffer [40];





void setup ()
{
  Serial.begin(115200);

   pinMode(ACT_RES14, OUTPUT);   
   pinMode(ACT_RES16, OUTPUT);   
   pinMode(ACT_LUZ, OUTPUT);
  digitalWrite(ACT_RES16, 1);

  interfaz.DisplayInit();
  

  // //Lanzo segunda tarea en el otro nucleo para interfaz HM
  
      
   interfaz.DisplayClear();
   interfaz.display.setCursor(0,0);

dht.begin();

}
float Temperatura;
float Humedad;
bool a = false;
char  aa[50];

void loop(  ) //Control
{
  a = !a;
  digitalWrite(ACT_RES16, a);
 Humedad = dht.readHumidity();
  delay(2000);//wait ls to refresh
Temperatura = dht.readTemperature();

sprintf(aa, "T: %f\nH:%f", Temperatura, Humedad);
 
 interfaz.DisplayClear();
 interfaz.DisplayPrint(aa, 0,0 );
Serial.println( aa);
  delay(2000);//wait ls to refresh


}

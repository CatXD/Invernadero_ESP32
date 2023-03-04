#include "control.h"



void Control::Init ()
{
    dht.begin();
    mutex = xSemaphoreCreateMutex();
}

void Control::EjecutarCicloControl(Tiempo_t time)
{
  float humedad, temp;

  //Adquisicion
  xSemaphoreTake( mutex, portMAX_DELAY );
  Humedad = dht.readHumidity();
  Temp = dht.readTemperature();

  humedad = Humedad;
  temp = Temp;
  xSemaphoreGive( mutex );

  //Ejecucion control Luz

  //Ejecucion control Temperatura
  


}
void Control::HabilitarLuz(bool en)
{
  xSemaphoreTake( mutex, portMAX_DELAY );
  LuzHabilitada = en;
  xSemaphoreGive( mutex );
}


float Control::GetTemp()
{
  xSemaphoreTake( mutex, portMAX_DELAY );
  float aux = Temp;
  xSemaphoreGive( mutex );
  return aux;
}
float Control::GetHumedad ()
{
  xSemaphoreTake( mutex, portMAX_DELAY );
  float aux = Humedad;
  xSemaphoreGive( mutex );
  return aux;
}
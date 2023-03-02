#include "control.h"

Control::Control ()
{
  
}

int Control::Init ()
{
    dht.begin();
    mutex = xSemaphoreCreateMutex();
}

int Control::Ciclo_control()
{
  xSemaphoreTake( mutex, portMAX_DELAY );
  Hume = dht.readHumidity();
  Temp = dht.readTemperature();
  xSemaphoreGive( mutex );
}

float Control::getTemp ()
{}
float Control::getHume ()
{}
void Control::MideTempYHume ()
{}
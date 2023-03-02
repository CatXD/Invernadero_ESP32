#ifndef CONTROL_H
#define CONTROL_H

#include "def_pines.h"
#include "DHT.h"

#define DHT_TYPE DHT22


class Control 
{
  public:
  float getTemp ();
  float getHume ();

  Control();

  int Init();
  int Ciclo_control();
  
  protected:
  DHT dht{12, DHT_TYPE};
  float Temp;
  float Hume;

  SemaphoreHandle_t mutex;

  void MideTempYHume ();

};




#endif

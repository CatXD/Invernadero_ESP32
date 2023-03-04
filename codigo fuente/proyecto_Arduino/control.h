#ifndef CONTROL_H
#define CONTROL_H

#include "def_pines.h"
#include "DHT.h"
#include "curvasLuz.h"

#define DHT_TYPE DHT22


class Control 
{
public:
  void Init ();

  void EjecutarCicloControl(Tiempo_t time);
  void HabilitarLuz(bool en);

  // bool   GetEstadoR1();
  // bool   GetEstadoR2();
  // bool   GetEstadoLuz();
  // bool   GetAlarmaHumedad();
  // bool   GetNocheDia();
  // int    GetValorSensor();



  //DHT22
  float GetTemp ();
  float GetHumedad ();


  


protected:
  SemaphoreHandle_t mutex;

  bool LuzHabilitada = 1;

  //DHT22
  DHT dht{DHT_PIN, DHT_TYPE};
  float Temp;
  float Humedad;



};




#endif

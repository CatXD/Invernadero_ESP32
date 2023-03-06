#ifndef CONTROL_TEMP_H
#define CONTROL_TEMP_H

#include "DHT.h"
#include "resistencia.h"
#include "def_pines.h"

#define DHT_TYPE DHT22 

struct Ctrl_temp_estado_st
{
  float Temperatura;
  float Humedad;
  bool BloqueoR2;
};
typedef Ctrl_temp_estado_st Ctrl_temp_estado_t;

class Control_Temp
{
  public:
  void Init();
  Ctrl_temp_estado_t Ejecuta_Control (bool DiaNoche);

  void BloqueoR2 (bool bloqueo); //Impide que R2 se encienda

  protected:
  DHT dht{DHT_PIN, DHT_TYPE};
  Resistencia R1, R2;


  //Consignas y parametros control:
  float Histeresis_R1 = 2;
  float Histeresis_R2 = 5;
  float Consigna_noche = 15;
  float Consigna_dia = 25;
  float Consigna_actual;

  //Medidas
  float Temperatura;
  float Humedad;

};

#endif

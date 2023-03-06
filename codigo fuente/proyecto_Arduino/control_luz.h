#ifndef CONTROL_LUZ_H
#define CONTROL_LUZ_H

#include <Arduino.h>
#include <sdkconfig.h>
#include <esp_system.h>
#include "luz.h"
#include "def_pines.h"
#include "control_temp.h"

struct Ctrl_luz_estado_st
{
  float LuzMedida = 0;
  bool LuzHabilitada;
};
typedef Ctrl_luz_estado_st Ctrl_luz_estado_t;

struct Ctrl_luzMasTemp_estado_st
{
  Ctrl_luz_estado_t estado_ctrl_luz;
  Ctrl_temp_estado_t estado_ctrl_temp;  
};
typedef Ctrl_luzMasTemp_estado_st Ctrl_luzMasTemp_estado_t;

class Control_Luz
{
public:
  void Init();
  Ctrl_luzMasTemp_estado_st Ejecuta_Control (bool DiaNoche);
  void SetLuzHabilitada (bool habilitada);
  bool GetLuzHabilitada ();

protected:
  bool DiaNoche;
  Luz Luz1;
  bool LuzHabilitada;

  Control_Temp ctrl_temp;
};


#endif

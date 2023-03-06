#ifndef CONTROL_LUZ_H
#define CONTROL_LUZ_H

#include <Arduino.h>
#include <sdkconfig.h>
#include <esp_system.h>
#include "luz.h"
#include "def_pines.h"

struct Ctrl_luz_estado_st
{
  float LuzMedida = 0;
  bool LuzHabilitada;
};
typedef Ctrl_luz_estado_st Ctrl_luz_estado_t;

class Control_Luz
{
public:
  void Init();
  Ctrl_luz_estado_t Ejecuta_Control (bool DiaNoche);
  void SetLuzHabilitada (bool habilitada);
  bool GetLuzHabilitada ();
  void SetFuncionLimitarPotencia (  void (*fun_limitarPotencia) (bool));

protected:
  bool DiaNoche;
  Luz Luz1;
  bool LuzHabilitada;

    void (*fun_limitarPotencia) (bool);
};


#endif

#ifndef CONTROL_H
#define CONTROL_H

#include "def_pines.h"
#include "control_temp.h"
#include "control_luz.h"
#include "curvasLuz.h"

struct EstadoControl_st 
{
  Ctrl_temp_estado_t Estado_Temp;
  Ctrl_luz_estado_t Estado_Luz;
  bool DiaNoche;
  Tiempo_t Fecha;
};
typedef EstadoControl_st EstadoControl_t;

class Control 
{
public:
  void Init ();

  EstadoControl_t EjecutarCicloControl(Tiempo_t time);
  void HabilitarLuz(bool en);

  bool  GetHabilitacionLuz();

  EstadoControl_t  GetEstado();
  void  SetEstado(EstadoControl_t estado);


protected:
  Control_Temp ctrl_temp;
  Control_Luz ctrl_luz;


  SemaphoreHandle_t mutexEstado;
  SemaphoreHandle_t mutexCtrl;
  EstadoControl_t  Estado;
};




#endif

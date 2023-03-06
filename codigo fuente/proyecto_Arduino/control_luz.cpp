#include "control_luz.h"

void Control_Luz::Init()
{
  Luz1.SetPin(ACT_LUZ);
}

Ctrl_luz_estado_t Control_Luz::Ejecuta_Control (bool DiaNoche)
{
  Ctrl_luz_estado_t reporte;
  bool presalida_Luz;
  //Adquisicion

  //Ejecucion control
  if (DiaNoche)
    presalida_Luz = false;
  else
    presalida_Luz = true;

  //Compruebo habilitacion
  if (!LuzHabilitada)
    presalida_Luz = false;

  //Salidas
  Luz1.SetOnOff(presalida_Luz);

  //Reporte de estado
  reporte.LuzHabilitada = LuzHabilitada;
  reporte.LuzMedida = 0;
  return reporte;
}

void  Control_Luz::SetLuzHabilitada (bool habilitada)
{
  LuzHabilitada = habilitada;
  if (!habilitada)
    Luz1.SetOnOff(false);
}

  bool Control_Luz::GetLuzHabilitada ()
  {
    return LuzHabilitada;
  }
  void Control_Luz::SetFuncionLimitarPotencia (  void (*fun_bloqueoR2) (bool))
  {
    fun_limitarPotencia = fun_bloqueoR2;
  }

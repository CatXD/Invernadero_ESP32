#include "control_luz.h"

void Control_Luz::Init()
{
  Luz1.SetPin(ACT_LUZ);
  ctrl_temp.Init();
}

Ctrl_luzMasTemp_estado_t Control_Luz::Ejecuta_Control (bool DiaNoche)
{
  Ctrl_temp_estado_t reporte_temp;
  Ctrl_luz_estado_t reporte_luz;
  Ctrl_luzMasTemp_estado_t reporte_final;

  bool presalida_Luz;
  //Adquisicion

  //Ejecucion control
  if (DiaNoche)
    presalida_Luz = true;
  else
    presalida_Luz = false;

  //Compruebo habilitacion
  if (!LuzHabilitada)
    presalida_Luz = false;

  //Salidas
  Luz1.SetOnOff(presalida_Luz);

  //Activo bloqueo de R2 si la luz esta encendida
  ctrl_temp.BloqueoR2 (presalida_Luz);

  //Ejecuto Control de temperatura
  reporte_temp = ctrl_temp.Ejecuta_Control (DiaNoche);

  //Reporte de estado del control de luz
  reporte_luz.LuzHabilitada = LuzHabilitada;
  reporte_luz.LuzMedida = 0;

  //Monto el reporte final
  reporte_final.estado_ctrl_luz = reporte_luz;
  reporte_final.estado_ctrl_temp = reporte_temp;
  return reporte_final;
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

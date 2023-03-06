#include "control.h"

void Control::Init ()
{
  ctrl_luz.Init();

  mutexEstado = xSemaphoreCreateMutex();
  mutexCtrl = xSemaphoreCreateMutex();
}

EstadoControl_t Control::EjecutarCicloControl(Tiempo_t tiempo)
{
  Ctrl_luzMasTemp_estado_t reporte_luzMasTemp;

  EstadoControl_t nuevo_estado;
  bool esDeDia;
  //Calculo si es de dia o de noche
  esDeDia = EsDeDia (tiempo);

  xSemaphoreTake( mutexCtrl, portMAX_DELAY );

  //Ejecucion control Luz
  reporte_luzMasTemp = ctrl_luz.Ejecuta_Control(esDeDia);



  xSemaphoreGive( mutexCtrl );
  
  nuevo_estado.Estado_Temp = reporte_luzMasTemp.estado_ctrl_temp;
  nuevo_estado.Estado_Luz = reporte_luzMasTemp.estado_ctrl_luz;
  nuevo_estado.Fecha = tiempo;
  SetEstado(nuevo_estado);
  return nuevo_estado;
}

void Control::HabilitarLuz(bool en)
{
  ctrl_luz.SetLuzHabilitada(en);
}

bool Control::GetHabilitacionLuz()
{
return ctrl_luz.GetLuzHabilitada();  
}

EstadoControl_t  Control::GetEstado()
{
  EstadoControl_t estado;
  xSemaphoreTake( mutexEstado, portMAX_DELAY );
  estado = Estado;
  xSemaphoreGive( mutexEstado );
  return estado;
}
void  Control::SetEstado(EstadoControl_t estado)
{
  xSemaphoreTake( mutexEstado, portMAX_DELAY );
  Estado = estado;
  xSemaphoreGive( mutexEstado );
}

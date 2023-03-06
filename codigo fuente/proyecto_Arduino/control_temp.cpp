#include "control_temp.h"

void Control_Temp::Init()
{
  dht.begin();
  R1.SetPin(ACT_RES16);
  R2.SetPin(ACT_RES14);
}

Ctrl_temp_estado_t Control_Temp::Ejecuta_Control (bool DiaNoche)
{
  float error;
  bool preR1, preR2;
  Ctrl_temp_estado_t reporte;

  //Adquisicion
  Humedad = dht.readHumidity();
  Temperatura = dht.readTemperature();

  //Consigna
  if (DiaNoche)
    Consigna_actual = Consigna_dia;
  else
    Consigna_actual = Consigna_noche;

  //Ejecucion control Temperatura
  error = Consigna_actual - Temperatura;

  //Histeresis R1:
  if (R1.GetOnOff())
  {
    preR1 = error > Histeresis_R1;
  }
  else
  {
    preR1 = error < 0;
  }

  //Histeresis R2:
  if (R2.GetOnOff())
  {
    preR2 = error > Histeresis_R2;
  }
  else
  {
    preR2 = error < 0;
  }

  //Salidas
  R1.SetOnOff(preR1);

  if (R2.GetBloqueo())
    R2.SetOnOff(false);
  else
    R2.SetOnOff(preR2);

  //Reporte
  reporte.Humedad = Humedad;
  reporte.Temperatura = Temperatura;
  reporte.BloqueoR2 = R2.GetBloqueo();
  return reporte;

}

void Control_Temp::BloqueoR2 (bool bloqueo)
{
  R2.SetBloqueo(bloqueo);
}


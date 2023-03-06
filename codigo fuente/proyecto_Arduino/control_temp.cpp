#include "control_temp.h"

void Control_Temp::Init()
{
  dht.begin();
  R1.SetPin(ACT_RES16);
  R2.SetPin(ACT_RES14);
}

Ctrl_temp_estado_t Control_Temp::Ejecuta_Control (bool DiaNoche)
{
  float consigna_R2;
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

  consigna_R2 = CalcConsignaR2 (Consigna_actual);

  //Histeresis R1:
  if (R1.GetOnOff())
  {
    preR1 = Temperatura < Consigna_actual;
  }
  else
  {
    preR1 = Temperatura < Consigna_actual - Histeresis;
  }

  //Histeresis R2:
  if (R2.GetOnOff())
  {
    preR2 = Temperatura < consigna_R2;
  }
  else
  {
    preR2 = Temperatura < consigna_R2 - Histeresis;
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
  reporte.Consigna = Consigna_actual;
  reporte.BloqueoR2 = R2.GetBloqueo();
  return reporte;

}

void Control_Temp::BloqueoR2 (bool bloqueo)
{
  R2.SetBloqueo(bloqueo);
}

float Control_Temp::CalcConsignaR2 (float consignaTemp)
{
  return consignaTemp - Diff_ConsignaR1_ConsignaR2;
}

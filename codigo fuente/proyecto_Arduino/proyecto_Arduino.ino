/****************************************
Autor: Diego Carro Fernandez


***************************************/
#include "def_pines.h"
#include "control.h"
#include "interfaz_hm.h"
#include <ESP32Time.h>

ESP32Time rtc;

TaskHandle_t _tarea2;

Interfaz_hm interfaz;
Control control;
char buffer [40];

EstadoControl_t estadoControl;



void setup ()
{
  Serial.begin(115200);

  // pinMode(ACT_RES14, OUTPUT);   
  // pinMode(ACT_RES16, OUTPUT);   
  // pinMode(ACT_LUZ, OUTPUT);

  control.Init();
  estadoControl = control.GetEstado();

  interfaz.DisplayInit();
  

  //Lanzo segunda tarea en el otro nucleo para interfaz HM
  int coreLoop = xPortGetCoreID();
  int coreTask2;
  if (coreLoop == 1)
    coreTask2 = 0;
  else
    coreTask2 = 1;

  xTaskCreatePinnedToCore(
      Tarea2, // Function to implement the task 
      "Task2", // Name of the task 
      10000,  // Stack size in words 
      NULL,  // Task input parameter 
      0,  //Priority of the task 
      &_tarea2,  // Task handle. 
      0); // Core where the task should run 
      //coreTask2); // Core where the task should run 
      
  interfaz.DisplayClear();
  interfaz.display.setCursor(0,0);

  //MENU CONFIGURACION DE FECHA Y HORA
  Tiempo_t ahora;
  ahora = interfaz.MenuGetTiempo (ahora);
  rtc.setTime(0, ahora.min, ahora.hora, ahora.dia, ahora.mes, ahora.ano);

  //MENU CONFIGURACION HABILITACION LUZ
  bool habilitacionLuz = interfaz.MenuHabilitacionLuz (control.GetHabilitacionLuz());
  control.HabilitarLuz(habilitacionLuz);

}


void loop(  ) //Control
{
  Tiempo_t tiempo;
  tm tiempo_kk;
  tiempo_kk = rtc.getTimeStruct();
  tiempo.ano = tiempo_kk.tm_year + 1900;
  tiempo.mes = tiempo_kk.tm_mon + 1;
  tiempo.dia = tiempo_kk.tm_mday;
  tiempo.hora = tiempo_kk.tm_hour;
  tiempo.min = tiempo_kk.tm_min;
  tiempo.sec = tiempo_kk.tm_sec;

  estadoControl = control.EjecutarCicloControl(tiempo );

  interfaz.DisplayControlEstado(estadoControl);

  delay(5000);//wait ls to refresh


}



void Tarea2 (void*)
{
  while (1)
  {

  }
}
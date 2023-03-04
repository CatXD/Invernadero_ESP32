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

int contador = 0;
char buffer [20];
    bool a=0;
void setup ()
{
  Serial.begin(115200);

  pinMode(ACT_Res14, OUTPUT);   
  pinMode(ACT_Res16, OUTPUT);   
  pinMode(ACT_Luz, OUTPUT);   

      
  interfaz.DisplayInit();




    sprintf ( buffer, "%d", contador);
    interfaz.DisplayClear();
    interfaz.DisplayPrint(buffer, 0,0);


  pinMode(ACT_Res14, OUTPUT);   


  // interfaz.DisplayClear();
  // interfaz.DisplayPrint ("SE HA ACABADO", 0, 0);
}
  tecla_t tecla = TECLA_NINGUNA;
bool b = false;
void loop(  )
{

    digitalWrite(ACT_Res14, 1);
    tecla =TECLA_NINGUNA;
    while (tecla == TECLA_NINGUNA)
      tecla = interfaz.botonera.MuestrearBotonera();
    digitalWrite(ACT_Res14, 0);

    if (tecla == TECLA_MAS)
      contador++;
    if (tecla == TECLA_MENOS)
      contador--;

    if (ACT_Res14,tecla != TECLA_NINGUNA )
    {
       b = !b;
      digitalWrite(ACT_Res14, b);
    }


    sprintf ( buffer, "%d", contador);
    interfaz.DisplayClear();
    interfaz.DisplayPrint(buffer, 0,0);
    delay(10);

}

/*

void setup ()
{
  Serial.begin(115200);

  rtc.setTime(0,0,0, 24,2,2023);

  pinMode(ACT_Res14, OUTPUT);   
  pinMode(ACT_Res16, OUTPUT);   
  pinMode(ACT_Luz, OUTPUT);   



  
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
      
  interfaz.DisplayInit();
  interfaz.DisplayPrint ("AAAAAAA");

  pinMode ( LCD_LIGHT, OUTPUT);

  Tiempo_t ahora;
  ahora.ano = 2000;
  interfaz.MenuGetTiempo (ahora);

  interfaz.DisplayClear();
  interfaz.DisplayPrint ("SE HA ACABADO", 0, 0);
}
  bool a=0, a2=0;
char  stringBuffer[20];
String aaa;

void loop(  )
{
 a2 = !a2;
 digitalWrite ( ACT_Luz, a2);

    delay(1000);//wait ls to refresh


}


void loop2 ()
{
 a = !a;
 digitalWrite ( ACT_Res16, a);

delay(1000);//wait ls to refresh
}

void Tarea2 (void*)
{

  while (1)
  {
    loop2();
  }
}

*/
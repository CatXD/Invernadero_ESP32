/****************************************
Autor: Diego Carro Fernandez




***************************************/
#include "def_pines.h"
#include "control.h"
#include "interfaz_hm.h"

#include <ESP32Time.h>

ESP32Time rtc;


TaskHandle_t _tarea2;



Adafruit_PCD8544 display = Adafruit_PCD8544(LCD_CLK,LCD_DIN,LCD_DC,LCD_CE,LCD_RST);
void displayInit( )
 {

 }

void setup ()
{
  Serial.begin(115200);

  rtc.setTime(0,0,0, 24,2,2023);

  pinMode(ACT_Res14, OUTPUT);   
  pinMode(ACT_Res16, OUTPUT);   
  pinMode(ACT_Luz, OUTPUT);   

  display.begin();
  display.setContrast(60); //setContrast(50);

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(BLACK);




  
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
      

    display.clearDisplay();
    display.setTextSize(1); 
    display.setTextColor(BLACK);
    display.setCursor(10,10);
    display.println("Hola!");
    display.display();

}
  bool a, a2;

void loop(  )
{
 a2 = !a2;
 digitalWrite ( ACT_Luz, a2);
    delay(1000);//wait ls to refresh
  digitalWrite(LCD_LIGHT, 1);
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

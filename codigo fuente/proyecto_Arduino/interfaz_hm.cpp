#include "interfaz_hm.h"




void Interfaz_hm::DisplayInit()
 {
  

  display.begin();
  display.setContrast(60); //setContrast(50);

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(BLACK);
 }

  void Interfaz_hm::DisplayClear ( )
  {
    display.clearDisplay();
  }

  void Interfaz_hm::DisplayCursor ( int x, int y )
  {

  }


void Interfaz_hm::DisplayPrint (char* cadena)
{
    display.clearDisplay();
    display.setTextSize(1); 
    display.setCursor(10,10);
    display.println(cadena);
    display.display();
}

 bool teclaPulsada (tecla_t tecla)
{
  bool pulsada = 0;
  while (digitalRead(tecla))
  {
    pulsada = 1;
    delay(5);
  }
  while (!digitalRead(tecla))
  {
    delay(5);
  }
  return pulsada;
}
#include "interfaz_hm.h"


void Interfaz_hm::DisplayInit()
 {
  display.begin();
  display.setContrast(60); //setContrast(50);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  DisplayLuzFondo(false);
 }

  void Interfaz_hm::DisplayClear ( )
  {
    display.clearDisplay();
  }

void Interfaz_hm::DisplayPrint (char* cadena)
{
    display.setTextSize(1); 
    display.println(cadena);
    display.display();
    DisplayLuzFondo(true);
}

void Interfaz_hm::DisplayPrint (char* cadena, int x, int y)
{
    display.setCursor(x,y);
    display.println(cadena);
    display.display();
    DisplayLuzFondo(true);
}

void Interfaz_hm::DisplayPrint (String cadena)
{
    display.setTextSize(1); 
    display.println(cadena);
    display.display();
    DisplayLuzFondo(true);
}

void Interfaz_hm::DisplayPrint (String cadena, int x, int y)
{
    display.setCursor(x,y);
    display.println(cadena);
    display.display();
    DisplayLuzFondo(true);
}

void Interfaz_hm::DisplayLuzFondo(bool OnOff)
{
  if (OnOff)
    pinMode (LCD_LIGHT, INPUT);
  else
    pinMode (LCD_LIGHT, OUTPUT);
}

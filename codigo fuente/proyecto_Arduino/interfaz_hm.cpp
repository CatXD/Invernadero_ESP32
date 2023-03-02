#include "interfaz_hm.h"

/*void displayInit(Adafruit_PCD8544 * display)
 {
  display->begin();
  display->setContrast(60); //setContrast(50);

  display->clearDisplay();
  display->setTextSize(1);
  display->setTextColor(BLACK);

  pinMode(LCD_LIGHT, OUTPUT);   
  digitalWrite(LCD_LIGHT, 1);
 }*/

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
#ifndef INTERFAZHM_H
#define INTERFAZHM_H

#include "def_pines.h"
#include "curvasLuz.h"

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include "botonera.h"

class Interfaz_hm 
{
  public:
    //Display LCD
  Adafruit_PCD8544 display = Adafruit_PCD8544(LCD_CLK,LCD_DIN,LCD_DC,LCD_CE,LCD_RST);
  void DisplayInit();
  void DisplayClear ( );
  void DisplayCursor ( int x, int y );
  void DisplayPrint ( char* cadena );
  void DisplayPrint (char* cadena, int x, int y);
  void DisplayPrint ( String cadena);
  void DisplayPrint (String cadena, int x, int y);
  void DisplayLuzFondo (bool OnOff);
  void DisplayApagar();

  void Espera10ms ();
  void Espera1s ();

  void DisplayFechaYHora (Tiempo_t fecha);
  void DisplayFechaYHora (int dia, int mes, int ano, int hora, int min, int sec);


  //Botonera
  Botonera botonera;

  //Configurar Hora
  Tiempo_t MenuGetTiempo (Tiempo_t ahora);




};





/*
void mostrarInfo ()
{
  digitalWrite(LCD_LIGHT, 1);

    display.clearDisplay();
    display.setCursor(0,0);

  float humedad = dht.readHumidity();
  float temp = dht.readTemperature();
  sprintf(lcdBuffer,"Temp: %.1f  Hum: %.1f", temp, humedad);
  display.println(lcdBuffer);

  delay (5000);
  display.clearDisplay();
  digitalWrite(LCD_LIGHT, 0);
}
*/

#endif


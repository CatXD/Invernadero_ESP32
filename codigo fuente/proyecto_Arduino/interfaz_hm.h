#ifndef INTERFAZHM_H
#define INTERFAZHM_H

#include "def_pines.h"

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>



//void displayInit(Adafruit_PCD8544 * );

struct estadosTeclas_t
{
  bool Aceptar = 0;
  bool Cancelar = 0;
  bool Mas = 0;
  bool Menos = 0;
};

bool teclaPulsada (tecla_t );

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


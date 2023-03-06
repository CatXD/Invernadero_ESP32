#include "interfaz_hm.h"


void Interfaz_hm::DisplayInit()
 {
  display.begin();
  display.setContrast(60); //setContrast(50);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  pinMode (LCD_LIGHT, INPUT);
 }

  void Interfaz_hm::DisplayClear ( )
  {
    display.clearDisplay();
  }

void Interfaz_hm::DisplayPrint (char* cadena)
{
    display.setTextSize(1); 
    display.print(cadena);
    display.display();
    pinMode (LCD_LIGHT, OUTPUT);
}

void Interfaz_hm::DisplayPrint (char* cadena, int x, int y)
{
    display.setCursor(x,y);
    display.print(cadena);
    display.display();
    pinMode (LCD_LIGHT, OUTPUT);
}

void Interfaz_hm::DisplayPrint (String cadena)
{
    display.setTextSize(1); 
    display.print(cadena);
    display.display();
    pinMode (LCD_LIGHT, OUTPUT);
}

void Interfaz_hm::DisplayPrint (String cadena, int x, int y)
{
    display.setCursor(x,y);
    display.print(cadena);
    display.display();
    pinMode (LCD_LIGHT, OUTPUT);
}

void Interfaz_hm::DisplayLuzFondo(bool OnOff)
{
  if (OnOff)
    pinMode (LCD_LIGHT, OUTPUT);
  else
    pinMode (LCD_LIGHT, INPUT);
}

void Interfaz_hm::DisplayApagar()
{
  display.clearDisplay();
  display.display();
  pinMode (LCD_LIGHT, INPUT);
}

void  Interfaz_hm::Espera10ms ()
{
  delay(10);
}
void  Interfaz_hm::Espera1s ()
{
  delay(1000);
}

void Interfaz_hm::DisplayFechaYHora (int dia, int mes, int ano, int hora, int min, int sec)
{
  char buffer[20];  //string buffer
  sprintf(buffer, "%02d-%02d-%04d\n%02d:%02d:%02d", dia, mes, ano, hora, min, sec);
  display.print(buffer);
  display.display();
  pinMode (LCD_LIGHT, OUTPUT);
}


void Interfaz_hm::DisplayFechaYHora (Tiempo_t fecha)
{
  char buffer[20];  //string buffer
  sprintf(buffer, "%02d-%02d-%04d\n%02d:%02d:%02d", fecha.dia, fecha.mes, fecha.ano, fecha.hora, fecha.min, fecha.sec);
  display.print(buffer);
  display.display();
  pinMode (LCD_LIGHT, OUTPUT);
}

enum FechaParams_t {FP_NONE = -1, FP_DIA = 0, FP_MES = 1, FP_ANO, FP_HORA, FP_MIN, FP_COUNT};

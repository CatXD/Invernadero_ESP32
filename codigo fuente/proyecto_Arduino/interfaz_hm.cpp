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
    display.println(cadena);
    display.display();
    pinMode (LCD_LIGHT, OUTPUT);
}

void Interfaz_hm::DisplayPrint (char* cadena, int x, int y)
{
    display.setCursor(x,y);
    display.println(cadena);
    display.display();
    pinMode (LCD_LIGHT, OUTPUT);
}

void Interfaz_hm::DisplayPrint (String cadena)
{
    display.setTextSize(1); 
    display.println(cadena);
    display.display();
    pinMode (LCD_LIGHT, OUTPUT);
}

void Interfaz_hm::DisplayPrint (String cadena, int x, int y)
{
    display.setCursor(x,y);
    display.println(cadena);
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
  char buffer[6];  //string buffer
  sprintf(buffer, "%2d-%2d-%4d\n%2d:%2d:%2d", dia, mes, ano, hora, min, sec);
  display.println(buffer);
  display.display();
  pinMode (LCD_LIGHT, OUTPUT);
}


void Interfaz_hm::DisplayFechaYHora (Tiempo_t fecha)
{
  char buffer[6];  //string buffer
  sprintf(buffer, "%2d-%2d-%4d\n%2d:%2d:%2d", fecha.dia, fecha.mes, fecha.ano, fecha.hora, fecha.min, fecha.sec);
  display.println(buffer);
  display.display();
  pinMode (LCD_LIGHT, OUTPUT);
}

enum FechaParams_t {FP_NONE = -1, FP_DIA = 0, FP_MES = 1, FP_ANO, FP_HORA, FP_MIN, FP_COUNT};

Tiempo_t Interfaz_hm::MenuGetTiempo (Tiempo_t ahora)
{
  int paramConfigurando = FP_DIA; //Parametro que estoy configurando
  int configurado[FP_COUNT];  //Copia de la configuracion actual sobre la que escribo y leo

  tecla_t teclaPulsada; //Tecla actual pulsada
  Tiempo_t resultado; //Presalida de la funcion


  configurado[FP_DIA] = ahora.dia;
  configurado[FP_MES] = ahora.mes;
  configurado[FP_ANO] = ahora.ano;  
  configurado[FP_HORA] = ahora.hora;
  configurado[FP_MIN] = ahora.min;
  

  while ( paramConfigurando < FP_COUNT )
  {
    DisplayClear ();
    DisplayPrint ("Configurando, 0, 0");
    switch (paramConfigurando)
    {
      case FP_DIA:
        DisplayPrint ("Dia:\n");
      case FP_MES:
        DisplayPrint ("Mes:\n");
      case FP_ANO:
        DisplayPrint ("Ano:\n");
      case FP_HORA:
        DisplayPrint ("Hora:\n");
      case FP_MIN:
        DisplayPrint ("Minuto:\n");
      break;
      default:
        DisplayPrint ("Error");
    }

    DisplayFechaYHora (configurado[FP_DIA], configurado[FP_MES], configurado[FP_ANO], configurado[FP_HORA], configurado[FP_MIN], 0);

    while (teclaPulsada == TECLA_NINGUNA)
    {
      teclaPulsada = botonera.MuestrearBotonera();
    }

    switch(teclaPulsada)
    {
      case TECLA_MAS:
        configurado[paramConfigurando] = configurado[paramConfigurando] + 1;
        break;
      case TECLA_MENOS:
        if (configurado[paramConfigurando] > 1)
          configurado[paramConfigurando]= configurado[paramConfigurando] - 1 ;
        break;
      case TECLA_ACEPTAR:
          paramConfigurando = paramConfigurando + 1;
        break;
      case TECLA_CANCELAR:
        if (paramConfigurando > FP_DIA)
          paramConfigurando = paramConfigurando - 1;
        break;
    }
  }
  resultado.dia = configurado[FP_DIA];
  resultado.mes = configurado[FP_MES];
  resultado.ano = configurado[FP_ANO];
  resultado.hora = configurado[FP_HORA];
  resultado.min = configurado[FP_MIN];
  resultado.sec = 0;

  display.clearDisplay();
  display.setCursor(0, 0);
  DisplayFechaYHora (configurado[FP_DIA], configurado[FP_MES], configurado[FP_ANO], configurado[FP_HORA], configurado[FP_MIN], 0);
  Espera1s(); Espera1s(); Espera1s();
  DisplayApagar();

  return resultado;
  
}



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

Tiempo_t Interfaz_hm::MenuGetTiempo (Tiempo_t ahora)
{
  int paramConfigurando = FP_DIA; //Parametro que estoy configurando
  int configurado[FP_COUNT];  //Copia de la configuracion actual sobre la que escribo y leo

  tecla_t teclaPulsada = TECLA_NINGUNA; //Tecla actual pulsada
  Tiempo_t resultado; //Presalida de la funcion


  configurado[FP_DIA] = ahora.dia;
  configurado[FP_MES] = ahora.mes;
  configurado[FP_ANO] = ahora.ano;  
  configurado[FP_HORA] = ahora.hora;
  configurado[FP_MIN] = ahora.min;
  

  while ( paramConfigurando < FP_COUNT )
  {
    DisplayClear ();
    DisplayPrint ("Configurando ", 0, 0);
    display.display();
    switch (paramConfigurando)
    {
      case FP_DIA:
        DisplayPrint ("Dia:\n");
        break;
      case FP_MES:
        DisplayPrint ("Mes:\n");
        break;
      case FP_ANO:
        DisplayPrint ("Ano:\n");
        break;
      case FP_HORA:
        DisplayPrint ("Hora:\n");
        break;
      case FP_MIN:
        DisplayPrint ("Minuto:\n");
      break;
      default:
        DisplayPrint ("Error");
    }

    DisplayFechaYHora (configurado[FP_DIA], configurado[FP_MES], configurado[FP_ANO], configurado[FP_HORA], configurado[FP_MIN], 0);
    
    teclaPulsada = TECLA_NINGUNA;
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

bool Interfaz_hm::MenuHabilitacionLuz (bool estado)
{
  tecla_t teclaPulsada = TECLA_NINGUNA; //Tecla actual pulsada

  while ( teclaPulsada != TECLA_ACEPTAR )
  {
    DisplayClear ();
    DisplayPrint ("Luz habilitada: ", 0, 0);
    if (estado)
      DisplayPrint ("Si");
    else
      DisplayPrint ("No");


    teclaPulsada = TECLA_NINGUNA;
    while (teclaPulsada == TECLA_NINGUNA)
    {
      teclaPulsada = botonera.MuestrearBotonera();
    }

    switch(teclaPulsada)
    {
      case TECLA_MAS:
        estado = !estado;
        break;
      case TECLA_MENOS:
        estado = !estado;
        break;
    }
  }

  Espera1s(); Espera1s(); Espera1s();
  DisplayApagar();
  return estado;
}

void Interfaz_hm::DisplayControlEstado(EstadoControl_t estado)
{
  char buffer[30];
  char c_diaNoche;

  if (estado.DiaNoche)
    c_diaNoche = 'D';
  else
    c_diaNoche = 'N';


  display.clearDisplay();
  display.setCursor(0, 0);
  sprintf (buffer, "%2d-%2d-%2d%c%2d:%2d\n", estado.Fecha.ano%2000, estado.Fecha.mes, estado.Fecha.dia, c_diaNoche, estado.Fecha.hora, estado.Fecha.min);
  display.print(buffer);
  display.display();

  sprintf (buffer, "T: %2.1f H: %2.1f\n", estado.Estado_Temp.Temperatura, estado.Estado_Temp.Humedad);
  display.print(buffer);
  display.display();

  
  pinMode (LCD_LIGHT, OUTPUT);  
}

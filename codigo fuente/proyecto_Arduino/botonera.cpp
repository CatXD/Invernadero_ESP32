#include "botonera.h"

 bool Botonera::ComprobarBotonPosXY (int x, int y)
 {
  int gpio_x, gpio_y; 

  bool estado;

  gpio_y = pines_fila [y];
  gpio_x = pines_colu [x];

  pinMode(gpio_y, OUTPUT);
  pinMode(gpio_x, INPUT);
  digitalWrite(gpio_x, 1);
  delay(1);

  estado = digitalRead(gpio_y);

  digitalWrite(gpio_x, 0);
  pinMode(gpio_y, INPUT);
  pinMode(gpio_x, INPUT);

  return estado;
 }


//Si encuentra una tecla pulsada, devuelve su identificar. Si no, -1.

 tecla_t Botonera::MuestrearBotonera()
 {
  tecla_t id_tecla;
   for (int i = 0; i < TECLADO_NUM_FILAS; i++)
   {
     for (int j = 0; j < TECLADO_NUM_COLUM; j++)
     {
       if (ComprobarBotonPosXY (i, j))
       {
        id_tecla = tecla_t (i * TECLADO_NUM_FILAS + j);
        TeclaPulsada = id_tecla;
        return id_tecla;
       }
     }
   }
   id_tecla = TECLA_NINGUNA;
   return TECLA_NINGUNA;
 }


  tecla_t Botonera::GetTeclaPulsada()
  {
    return TeclaPulsada;
  }
#include "botonera.h"

 bool Botonera::ComprobarBotonPosXY (int x, int y)
 {
  int gpio_x, gpio_y; 

  bool estado;

  gpio_y = pines_fila [y];
  gpio_x = pines_colu [x];

  pinMode(gpio_y, OUTPUT);
  pinMode(gpio_x, INPUT);
  digitalWrite(gpio_y, 1);
  delay(10);

  estado = digitalRead(gpio_x);

  digitalWrite(gpio_x, 0);
  pinMode(gpio_y, INPUT);
  pinMode(gpio_x, INPUT);

  return estado;
 }


//Si encuentra una tecla pulsada, devuelve su identificar. Si no, -1.
 tecla_t Botonera::MuestrearBotonera()
 {
  tecla_t preteclaPulsada;
  tecla_t id_tecla;
  bool encontrado = false;

  int i = 0;

  while ( i < TECLADO_NUM_FILAS*TECLADO_NUM_COLUM && ! encontrado)
  {
    encontrado = ComprobarBotonPosXY (i/TECLADO_NUM_FILAS, i%TECLADO_NUM_FILAS);
    if (!encontrado)
      i++;
  }
  
  if ( i == TECLADO_NUM_FILAS*TECLADO_NUM_COLUM)
  {
    TeclaEstadoAns = TECLA_NINGUNA;
    return TECLA_NINGUNA;
  }

  id_tecla = tecla_t(i);
  if (TeclaEstadoAns != id_tecla) //Detecto cambio
  {
    TeclaEstadoAns = id_tecla;
    return id_tecla;
  }

  TeclaEstadoAns = id_tecla;
  return TECLA_NINGUNA;
 }
    


#ifndef BOTONERA_H
#define BOTONERA_H

#include "def_pines.h"



enum tecla_t { TECLA_NINGUNA = -1, TECLA_ACEPTAR = 0, TECLA_CANCELAR, TECLA_MAS, TECLA_MENOS, TECLA_COUNT }; //Identificadores de tecla


class Botonera 
{
  public:
    tecla_t MuestrearBotonera();

    bool ComprobarBotonPosXY (int x, int y);
  protected:
    int pines_fila [2] = { TECLADO_F1, TECLADO_F2 }; //Para el muestreo
    int pines_colu [2] = { TECLADO_C1, TECLADO_C2 }; //Para el muestreo
    tecla_t TeclaEstadoAns = TECLA_NINGUNA;
};


#endif


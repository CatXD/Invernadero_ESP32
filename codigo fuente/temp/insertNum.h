#ifndef INSERTNUM_H
#define INSERTNUM_H

#include "DefPines.h"




struct INDialogResultado
{
  int resultado; 
  TeclaDeSalida tecla;
}

class INDialog
{
protected:
  int valor;
  estadosTeclas_t teclas_ans;
  tecla leerTeclas ();

  Adafruit_PCD8544 * Lcd;

public:
  void Init (Adafruit_PCD8544 * lcd);


  INDialogResultado lanzar(int cursorX, int cursorY, int val_max, int val_min, int valorInicial);
  INDialogResultado lanzar (int cursorX, int cursorY, int val_max, int val_min);

}
#endif


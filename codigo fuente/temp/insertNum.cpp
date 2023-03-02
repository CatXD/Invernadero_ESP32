#include "insertNum.h"
  
tecla INDialog:: leerTeclas ()
{
  estadosTeclas_t teclas_act;

  teclas_act.Aceptar = digitalRead(TECLA_ACEPTAR);
  teclas_act.Cancelar = digitalRead(TECLA_CANCELAR);
  teclas_act.Mas = digitalRead(TECLA_MAS);
  teclas_act.Menos = digitalRead(TECLA_MENOS);

  if ( teclas_act.Aceptar != teclas_ans.Aceptar )
  {
    teclas_ans.Aceptar = teclas_act.Aceptar
    if(teclas_act.Aceptar)
      return Aceptar;
  }

  if ( teclas_act.Cancelar != teclas_ans.Cancelar )
  {
    teclas_ans.Cancelar = teclas_act.Cancelar
    if(teclas_act.Cancelar)
      return Cancelar;
  }

  if ( teclas_act.Mas != teclas_ans.Mas )
  {
    teclas_ans.Mas = teclas_act.Mas
    if(teclas_act.Mas)
      return Mas;
  }

  if ( teclas_act.Menos != teclas_ans.Menos )
  {
    teclas_ans.Menos = teclas_act.Menos
    if(teclas_act.Menos)
      return Menos;
  }
}


INDialogResultado INDialog::lanzar(int valorInicial){}
INDialogResultado INDialog::lanzar (){}

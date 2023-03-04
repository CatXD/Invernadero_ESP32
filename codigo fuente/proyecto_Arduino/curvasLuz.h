#ifndef CURVASLUZ_H
#define CURVASLUZ_H

struct tiempo_t
{
  int sec = 0;
  int min = 0;
  int hora = 0;

  int dia = 0;
  int mes = 0;
  int ano = 0;
};
typedef tiempo_t Tiempo_t;


bool EsDeDia (Tiempo_t tiempo);
float CalcHoraAmanecer (int mes, int dia);
float CalcHoraAnochecer (int mes, int dia);


#endif
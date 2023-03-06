#ifndef CURVASLUZ_H
#define CURVASLUZ_H

struct tiempo_t
{
  int sec = 0;
  int min = 0;
  int hora = 0;

  int dia = 1;
  int mes = 1;
  int ano = 2020;
};
typedef tiempo_t Tiempo_t;


bool EsDeDia (Tiempo_t tiempo);
float CalcHoraAmanecer (int mes, int dia);
float CalcHoraAnochecer (int mes, int dia);


#endif
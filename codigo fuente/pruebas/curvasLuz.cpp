#include "CurvasLuz.h"


bool EsDeDia (Tiempo_t tiempo)
{
  float hora_amanecer = CalcHoraAmanecer(tiempo.mes, tiempo.dia);
  float hora_anochecer = CalcHoraAnochecer(tiempo.mes, tiempo.dia);


return tiempo.hora > hora_amanecer && tiempo.hora < hora_anochecer;

}


//Calculo de hora de amanecer
float CalcHoraAmanecer (int mes, int dia)
{
//amanecer - primavera: y = -0,0258x + 0,3843
//anochecer - primavera: y = 0,0217x + 0,7404
//amanecer - otono: y = 0,0214 (x + 6) + 0,2241
//anochecer - otono: y = -0,0264 (x + 6) + 0,8899

mes = mes + dia / 30.0;

float hora, hora_norm;

if (mes < 7)
    hora_norm = -0.0258 * mes + 0.3843;
else
    hora_norm = 0.0214 *(mes + 6) + 0.2241;

hora = hora_norm * 24;
return hora;
}


//Calculo de hora de anochecer
float CalcHoraAnochecer (int mes, int dia)
{
//amanecer - primavera: y = -0,0258x + 0,3843
//anochecer - primavera: y = 0,0217x + 0,7404
//amanecer - otono: y = 0,0214 (x + 6) + 0,2241
//anochecer - otono: y = -0,0264 (x + 6) + 0,8899

mes = mes + dia / 30.0;

float hora, hora_norm;

if (mes < 7)
    hora_norm = 0.0217 * mes + 0.7404;
else
    hora_norm = -0.0264 *(mes + 6) + 0.8899;

hora = hora_norm * 24;
return hora;
}

#include "resistencia.h"

void Resistencia::SetPin(int pin)
{
  Pin = pin;
  pinMode(pin, OUTPUT);
  Encendida = 0;
  digitalWrite(Pin, 0);
}


void Resistencia::SetBloqueo (bool bloqueo)
{
  Bloqueo = bloqueo;
  if (!Bloqueo)
  {
    digitalWrite(Pin, Encendida);
  }
  else
  {
    digitalWrite(Pin, false);
  }
}

void Resistencia::SetOnOff (bool on)
{
  if (!Bloqueo)
  {
    digitalWrite(Pin, on);
    Encendida = on;
  }
  else
  {
    Encendida = false;
    digitalWrite(Pin, false);
  }
}

bool Resistencia::GetBloqueo ()
{
  return Bloqueo;
}

bool Resistencia::GetOnOff ()
{
  return Encendida;
}

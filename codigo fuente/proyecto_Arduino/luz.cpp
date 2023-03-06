#include "luz.h"

void Luz::SetOnOff (bool on)
{
  digitalWrite(Pin, on);
  Encendida = on;
}

void Luz::SetPin(int pin)
{
  Pin = pin;
  pinMode(Pin, OUTPUT);
  Encendida = 0;
  digitalWrite(Pin, 0);
}

bool Luz::GetOnOff ()
{
  return Encendida;
}
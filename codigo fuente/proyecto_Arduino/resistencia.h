#ifndef RESISTENCIA_H
#define RESISTENCIA_H

#include <Arduino.h>
#include <sdkconfig.h>
#include <esp_system.h>

class Resistencia
{
public:
void SetBloqueo (bool bloqueo);
void SetOnOff (bool on);
void SetPin(int pin);

bool GetBloqueo ();
bool GetOnOff ();

protected:
  bool Encendida;
  bool Bloqueo;
  int Pin;
};


#endif

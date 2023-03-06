#ifndef LUZ_H
#define LUZ_H

#include <Arduino.h>
#include <sdkconfig.h>
#include <esp_system.h>

class Luz
{
public:
void SetOnOff (bool on);
void SetPin(int pin);

bool GetOnOff ();

protected:
  bool Encendida;
  int Pin;
};

#endif

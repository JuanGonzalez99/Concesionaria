#include "Motor.h"
#include <iostream>

Motor::Motor()
{
    setEncendido(false);
}

bool Motor::getEncendido()
{
    return encendido;
}

void Motor::setEncendido(bool b)
{
    encendido=b;
}

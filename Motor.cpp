#include "Motor.h"

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

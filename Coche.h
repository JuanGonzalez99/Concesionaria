#ifndef COCHE_H
#define COCHE_H

#include "Motor.h"

class Coche
{
public:
    Coche(char marca[], char color[], char patente[]);
    char* getMarca();
    char* getColor();
    char* getPatente();
    int getNafta();
    bool getMotor();
    void setNafta(int);
    void setMotor(bool);

protected:
    void setMarca(char[]);
    void setColor(char[]);
    void setPatente(char[]);

private:
    char marca[30];
    char color[20];
    char patente[10];
    int nafta;
    Motor motor;
};

#endif // COCHE_H

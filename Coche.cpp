#include "Coche.h"
#include <string.h>

Coche::Coche(char m[], char c[], char p[])
{
    setMarca(m);
    setColor(c);
    setPatente(p);
    nafta=0;
}

void Coche::setMarca(char m[]){
    strcpy(marca, m);
}

void Coche::setColor(char c[]){
    strcpy(color, c);
}

void Coche::setPatente(char p[]){
    strcpy(patente, p);
}

char* Coche::getMarca(){
    return marca;
}

char* Coche::getColor(){
    return color;
}

char* Coche::getPatente(){
    return patente;
}

int Coche::getNafta(){
    return nafta;
}

void Coche::setNafta(int c)
{
    nafta+=c;
}






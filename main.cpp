//*****************************************************************************
//                       CONFIGURACION MULTIPLATAFORMA
//=============================================================================
// COMPILACION EN WINDOWS
//-----------------------------------------------------------------------------
// Si este programa se va a compilar en Windows, descomente las tres lineas
// siguientes, y comente las tres lineas de "COMPILACION EN LINUX".
//-----------------------------------------------------------------------------
#ifndef _WIN32
  # define _WIN32
#endif

//=============================================================================
// COMPILACION EN LINUX
//-----------------------------------------------------------------------------
// Si este programa se va a compilar en Linux, descomente las tres lineas
// siguientes, y comente las tres lineas de "COMPILACION EN WINDOWS".
//-----------------------------------------------------------------------------
//#ifndef _LINUX
//  # define _LINUX
//#endif

//*****************************************************************************
//                             INCLUSIONES ESTANDAR
//=============================================================================
#include <iostream> // Libreria de flujos de  Entrada/Salida  que contiene  los
                    // objetos cin, cout y endl.

#include <cstdlib>  // Libreria estandar que contiene la funcion exit().

#include <fstream>

const char DIR_ARCHIVO[]="autos.dat";

void pedirEnter();
void strToUpper(char*);
int strToInt(char*);
void menuPrincipal();
bool validarEntero(char*);


//*****************************************************************************
//                             INCLUSIONES PERSONALES
//=============================================================================
#include "CSYSTEM/csystem.h" // Libreria para multiplataforma.
#include "Coche.h"
#include "registro.h"
#include "submenu.h"
#include "menu.h"


//==============================================================================
// DECLARACION DEL ESPACIO DE NOMBRES POR DEFECTO
//------------------------------------------------------------------------------
using namespace std;


int main()
{
    menuPrincipal();
    return 0;
}

void pedirEnter()
{
    char enter[1];
    cout << "\n\n\n(Presione enter para continuar)";
    sys::getline(enter, 1);
}

void strToUpper(char* c)
{
    for(int i=0;c[i]!='\0';i++)
    {
        if(c[i]>='a' && c[i]<='z')
            c[i] = c[i]-32;
    }
}

bool validarEntero(char* c)
{
    int x=0;
    do
    {
        if( c[x] < '0' || c[x] > '9' )
        {
            return false;
        }

    }while(c[++x]!='\0');

    return true;
}

int strToInt(char* c)
{
    int longitud=0, cadenaInt=0, base10=1, aux, x;

    while( c[longitud]!='\0' )
    {
        longitud++;
    }

    for( x=longitud-1; x>=0 ; x-- )
    {
        aux=((int)c[x])-48;
        cadenaInt+=aux*base10;
        base10*=10;
    }
    return cadenaInt;
}

void menuPrincipal()
{
    bool salir=false;
    while(!salir)
    {
        sys::cls();
        cout << "#============================#" << endl;
        cout << "|                            |" << endl;
        cout << "|    A.  Crear auto          |" << endl;
        cout << "|    B.  Listar autos        |" << endl;
        cout << "|    C.  Eliminar auto       |" << endl;
        cout << "|    D.  Seleccionar auto    |" << endl;
        cout << "|                            |" << endl;
        cout << "|         S. Salir           |" << endl;
        cout << "|                            |" << endl;
        cout << "*----------------------------*" << endl;
        cout << endl;
        cout << "Ingrese una opcion: ";
        char opcion[2];
        sys::getline(opcion, 2);
        strToUpper(opcion);
        while(strlen(opcion)!=1 || opcion[0]<'A' || (opcion[0]>'D' && opcion[0]!='S'))
        {
            cout << "No te hagas el loco: ";
            sys::getline(opcion, 2);
            strToUpper(opcion);
        }

        sys::cls();

        switch(opcion[0])
        {
        case 'A': menuCrear();
            break;
        case 'B': menuListar();
            break;
        case 'C': menuEliminar();
            break;
        case 'D': menuSeleccionar();
            break;
        case 'S':
            cout << "Nos vemos gaturro" << endl;
            salir=true;
        }
        pedirEnter();
    }
}

//=============================================================================
//                            FIN DE ARCHIVO
//#############################################################################


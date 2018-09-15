//*****************************************************************************
//                       CONFIGURACION MULTIPLATAFORMA
//=============================================================================
#ifndef _WIN32
    #define _LINUX
#endif


//*****************************************************************************
//                             INCLUSIONES ESTANDAR
//=============================================================================
#include <iostream> // Libreria de flujos de  Entrada/Salida  que contiene  los
                    // objetos cin, cout y endl.

#include <cstdlib>  // Libreria estandar que contiene la funcion exit().

#include <fstream>  // Libreria para el manejo de archivos.

//*****************************************************************************
//                            DECLARACIONES GLOBALES
//=============================================================================
const char DIR_ARCHIVO[] = "autos.dat";
const char TEXTO_ERROR[] = "Algo salio mal";

//*****************************************************************************
//                             INCLUSIONES PERSONALES
//=============================================================================
#include "CSYSTEM/csystem.h" // Libreria para multiplataforma.
#include "auxiliares.h"
#include "Coche.h"
#include "registro.h"
#include "menu.h"

//==============================================================================
// DECLARACION DEL ESPACIO DE NOMBRES POR DEFECTO
//------------------------------------------------------------------------------


int main()
{
    menuPrincipal();
    return 0;
}

//=============================================================================
//                            FIN DE ARCHIVO
//#############################################################################


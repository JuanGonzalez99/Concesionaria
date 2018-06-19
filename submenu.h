#ifndef SUBMENU_H_INCLUDED
#define SUBMENU_H_INCLUDED

#include "menu.h"

void subMenuMostrar();
void subMenuEncender();
void subMenuCargarNafta();
void subMenuViaje();
void subMenuModificar();
void subMenuEliminar();

void subMenu()
{
    bool salir=false;
    while(!salir)
    {
        sys::cls();
        cout << "#============================#" << endl;
        cout << "|                            |" << endl;
        cout << "|     A.  Mostrar            |" << endl;
        cout << "|     B.  Encender           |" << endl;
        cout << "|     C.  Cargar nafta       |" << endl;
        cout << "|     D.  Realizar viaje     |" << endl;
        cout << "|     E.  Modificar          |" << endl;
        cout << "|     F.  Eliminar           |" << endl;
        cout << "|                            |" << endl;
        cout << "|         V. Volver          |" << endl;
        cout << "|                            |" << endl;
        cout << "*----------------------------*" << endl;
        cout << endl;
        cout << "Ingrese una opcion: ";
        char opcion[2];
        sys::getline(opcion, 2);
        strToUpper(opcion);
        while(strlen(opcion)!=1 || opcion[0]<'A' || (opcion[0]>'F' && opcion[0]!='V'))
        {
            cout << "No te hagas el loco: ";
            sys::getline(opcion, 2);
            strToUpper(opcion);
        }

        sys::cls();

        switch(opcion[0])
        {
        case 'A':
            {
                cout << "En construccion"; //subMenuMostrar();
            }break;
        case 'B':
            {
                cout << "En construccion"; //subMenuEncender();
            }break;
        case 'C':
            {
                cout << "En construccion"; //subMenuCargarNafta();
            }break;
        case 'D':
            {
                cout << "En construccion"; //subMenuViaje();
            }break;
        case 'E':
            {
                cout << "En construccion"; //subMenuModificar();
            }break;
        case 'F':
            {
                cout << "En construccion"; //subMenuEliminar():
            }break;
        case 'V':
            {
                salir=true;
                continue;
            }break;
            default: cout << "Algo salio mal" << endl;
        }//FIN SWITCH

        pedirEnter();

    }//FIN WHILE

}

#endif // SUBMENU_H_INCLUDED

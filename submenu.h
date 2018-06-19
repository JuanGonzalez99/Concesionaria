#ifndef SUBMENU_H_INCLUDED
#define SUBMENU_H_INCLUDED

#include "menu.h"

void subMenuMostrar(char*);
void subMenuEncender(char*);
void subMenuCargarNafta(char*);
void subMenuViaje(char*);
void subMenuModificar(char*);
bool subMenuEliminar(char*);

void subMenu(char* patente)
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
            subMenuMostrar(patente);
        }break;
        case 'B':
        {
            cout << "En construccion"; //subMenuEncender(patente);
        }break;
        case 'C':
        {
            cout << "En construccion"; //subMenuCargarNafta(patente);
        }break;
        case 'D':
        {
            cout << "En construccion"; //subMenuViaje(patente);
        }break;
        case 'E':
        {
            cout << "En construccion"; //subMenuModificar(patente);
        }break;
        case 'F':
        {
            if(!subMenuEliminar(patente))
            {
                break;
            }
        }
        case 'V':
        {
            salir=true;
            continue;
        }break;
        default:
            cout << "Algo salio mal" << endl;
        }//FIN SWITCH

        pedirEnter();

    }//FIN WHILE

}

void subMenuMostrar(char* patente)
{
    mostrarCoche(buscarCoche(patente));
}

bool subMenuEliminar(char* patente)
{
    cout << "Esta seguro que desea eliminar este auto?" << endl;
    cout << endl;
    mostrarCoche(buscarCoche(patente));
    cout << "Si -> S"<< endl;
    cout << "No -> N"<< endl << endl;
    char opcion[2];
    sys::getline(opcion, 2);
    char op=opcion[0];
    while(strlen(opcion)!=1 || (op!='s' && op!='S' && op!='n' && op!='N'))
    {
        if(strlen(opcion)!=1)
            cout << "Ingrese un caracter: ";
        else
            cout << "No le he entendido, podria repetirme? ";
        sys::getline(opcion, 2);
        op=opcion[0];
    }
    switch(op)
    {
    case 's':
    case 'S':
    {
        eliminarCoche(patente);
        cout << endl;
        cout << "Registro eliminado exitosamente" << endl;
        return true;
    }
    break;
    case 'n':
    case 'N':
        return false;
        break;
    default:
        cout << "Algo salio mal";
        return false;
    }
}

#endif // SUBMENU_H_INCLUDED

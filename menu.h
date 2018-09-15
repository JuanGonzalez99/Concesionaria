#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "submenu.h"

void menuCrear();
void menuListar();
void menuEliminar();
void menuSeleccionar();

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
            cout << "Opcion incorrecta, intente nuevamente: ";
            sys::getline(opcion, 2);
            strToUpper(opcion);
        }

        sys::cls();

        switch(opcion[0])
        {
        case 'A':
            {
                menuCrear();
            }
            break;
        case 'B':
            {
                menuListar();
            }
            break;
        case 'C':
            {
                menuEliminar();
            }
            break;
        case 'D':
            {
                menuSeleccionar();
            }
            break;
        case 'S':
            {
                cout << "Hasta la proxima" << endl;
                salir=true;
            }

        }//Fin switch

        pedirEnter();

    }//Fin while
}

void menuCrear()
{
    cout << "CREACION DE NUEVO AUTO" << endl << endl;
    Coche nuevo = leerCoche();
    cout << endl;
    if( existeCoche(nuevo.getPatente()) )
        cout << "Patente ya existente" << endl;
    else
    {
        agregarCoche(nuevo);
        if( existeCoche(nuevo.getPatente()) )
            cout << "Coche creado exitosamente" << endl;
        else
            cout << TEXTO_ERROR << endl;
    }
}

void menuListar()
{
    cout << "LISTA DE AUTOS" << endl << endl;
    listarCoches();
}

void menuEliminar()
{
    cout << "ELIMINACION DE AUTO" << endl << endl;
    char patente[10];
    cout << "Ingrese la patente: ";
    sys::getline(patente, 10);
    if(existeCoche(patente))
    {
        sys::cls();
        mostrarCoche(buscarCoche(patente));

        if( confirmar("\n\nEsta seguro que desea eliminar este auto?(s/n) ") )
        {
            eliminarCoche(patente);
            cout << endl;
            if(!existeCoche(patente))
                cout << "Registro eliminado exitosamente" << endl;
            else
                cout << TEXTO_ERROR << endl;
        }
    }
    else
        cout << "\nCoche inexistente" << endl;
}

void menuSeleccionar()
{
    cout << "SELECCION DE AUTO" << endl << endl;
    cout << "Ingrese la patente: ";
    char patente[10];
    sys::getline(patente, 10);
    if(existeCoche(patente))
        subMenu(patente);
    else
        cout << "\nPatente no registrada" << endl;
}

#endif // MENU_H_INCLUDED

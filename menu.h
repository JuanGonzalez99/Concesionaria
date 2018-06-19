#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

void menuCrear()
{
    cout << "CREACION DE NUEVO AUTO" << endl << endl;
    Coche nuevo = leerCoche();
    if(existeCoche(nuevo.getPatente()))
        cout << "Patente ya existente" << endl;
    else
        ingresarCoche(nuevo);
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
    cout << "Patente: ";
    sys::getline(patente, 10);
    if(existeCoche(patente))
    {
        sys::cls();
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
        }
        break;
        case 'n':
        case 'N':
            break;
        default:
            cout << "Algo salio mal";
        }
    }// FIN DE IF
    else
        cout << "Coche inexistente" << endl;
}

void subMenu(char*);

void menuSeleccionar()
{
    cout << "SELECCION DE AUTO" << endl << endl;
    cout << "Patente: ";
    char patente[10];
    sys::getline(patente, 10);
    if(existeCoche(patente))
        subMenu(patente);
    else
        cout << "\nPatente no registrada" << endl;
}

#endif // MENU_H_INCLUDED

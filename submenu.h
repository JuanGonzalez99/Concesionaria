#ifndef SUBMENU_H_INCLUDED
#define SUBMENU_H_INCLUDED

#include "menu.h"

void subMenuMostrar(char*);
void subMenuEncenderApagar(Coche);
void subMenuCargarNafta(Coche);
void subMenuViaje(Coche);
void subMenuModificar(Coche);
bool subMenuEliminar(char*);

void subMenu(char* patente)
{
    bool salir=false;
    while(!salir)
    {
        Coche seleccionado = buscarCoche(patente);
        sys::cls();
        cout << "#============================#" << endl;
        cout << "|                            |" << endl;
        cout << "|     A.  Mostrar            |" << endl; if(buscarCoche(patente).getMotor())
        cout << "|     B.  Apagar             |" << endl; else cout << "|     B.  Encender           |" << endl;
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
            subMenuEncenderApagar(seleccionado);
        }break;
        case 'C':
        {
            subMenuCargarNafta(seleccionado);
        }break;
        case 'D':
        {
            subMenuViaje(seleccionado);
        }break;
        case 'E':
        {
            subMenuModificar(seleccionado);
        }break;
        case 'F':
        {
            if(!subMenuEliminar(patente))
                break;
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

void subMenuEncenderApagar(Coche c)
{
    if(c.getMotor())
    {
        c.setMotor(false);
        cout << "Motor apagado" << endl;
    }
    else
    {
        c.setMotor(true);
        cout << "Motor encendido" << endl;
    }
    guardarCambios(c);
}

void subMenuCargarNafta(Coche c)
{
    char cadCantidad[11];
    cout << "Cuanto desea cargar? ";
    sys::getline(cadCantidad, 11);
    while(!validarEntero(cadCantidad) || strlen(cadCantidad)>9)
    {
        if(!validarEntero(cadCantidad))
            cout << "No te hagas el loco: ";
        else
            cout << "Por favor, ingrese un numero de no mas de 9 digitos: ";
        sys::getline(cadCantidad, 11);
    }

    int cantidad = strToInt(cadCantidad);
    cout << endl;
    if((cantidad+c.getNafta())>999999999)
    {
        cout << "El tanque tiene una capacidad maxima de 999.999.999, lo 100to" << endl;
    }
    else
    {
        c.setNafta(cantidad);
        cout << "Nafta restante: " << c.getNafta() << endl;
        guardarCambios(c);
    }
}

void subMenuViaje(Coche c)
{
    if(!c.getMotor())
    {
        cout << "No encendiste el auto capo" << endl;
        return;
    }
    if(c.getNafta()==0)
    {
        cout << "Tanque vacio!" << endl;
        return;
    }
    char cadConsumo[11];
    cout << "Cuanto vas a gastar de Gasoil hermano? ";
    sys::getline(cadConsumo, 11);
    while(!validarEntero(cadConsumo) || strlen(cadConsumo)>9)
    {
        if(!validarEntero(cadConsumo))
            cout << "No te hagas el loco: ";
        else
            cout << "Por favor, ingrese un numero de no mas de 9 digitos: ";
        sys::getline(cadConsumo, 11);
    }

    int consumo = strToInt(cadConsumo);
    cout << endl;
    if((c.getNafta()-consumo)<0)
    {
        cout << "No llegas ni empujando el auto papu, anda a la Shell o tomate un bondi" << endl;
        return;
    }
    consumo *= -1;
    c.setNafta(consumo);
    if(c.getNafta()==0)
        cout << "No dejaste ni una gota de combustible, suerte para volver" << endl;
    else
        cout << "Te queda " << c.getNafta() << " de nafta capo" << endl;
    guardarCambios(c);
}

void subMenuModificar(Coche c)
{
    guardarCambios(cambiarCoche(c));
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

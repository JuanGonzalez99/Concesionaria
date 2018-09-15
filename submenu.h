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
            cout << "Opcion incorrecta, intente nuevamente: ";
            sys::getline(opcion, 2);
            strToUpper(opcion);
        }

        sys::cls();

        switch(opcion[0])
        {
        case 'A':
            {
                subMenuMostrar(patente);
            }
            break;
        case 'B':
            {
                subMenuEncenderApagar(seleccionado);
            }
            break;
        case 'C':
            {
                subMenuCargarNafta(seleccionado);
            }
        break;
        case 'D':
            {
                subMenuViaje(seleccionado);
            }
        break;
        case 'E':
            {
                subMenuModificar(seleccionado);
            }
        break;
        case 'F':
            {
                if(!subMenuEliminar(patente))
                    break;
            }
        case 'V':
            {
                salir=true;
                continue;
            }
        break;
        default:
            cout << TEXTO_ERROR << endl;

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
    c.setMotor(!c.getMotor());

    if(!c.getMotor())
        cout << "Motor apagado" << endl;

    else
        cout << "Motor encendido" << endl;

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
            cout << "Ingrese solo numeros enteros: ";
        else
            cout << "Por favor, ingrese un numero de no mas de 9 digitos: ";
        sys::getline(cadCantidad, 11);
    }

    int cantidad = strToInt(cadCantidad);
    cout << endl;
    if((cantidad+c.getNafta())>999999999)
    {
        cout << "El tanque tiene una capacidad maxima de 999.999.999, lo siento" << endl;
    }
    else
    {
        c.cargarNafta(cantidad);
        cout << "Nafta restante: " << c.getNafta() << endl;
        guardarCambios(c);
    }
}

void subMenuViaje(Coche c)
{
    if(!c.getMotor())
    {
        cout << "El motor no esta encendido" << endl;
        return;
    }
    if(c.getNafta()==0)
    {
        cout << "Tanque vacio!" << endl;
        return;
    }

    char cadConsumo[11];
    cout << "Cuanto desea gastar de nafta? ";
    sys::getline(cadConsumo, 11);
    while(!validarEntero(cadConsumo) || strlen(cadConsumo)>9)
    {
        if(!validarEntero(cadConsumo))
            cout << "Ingrese solo numeros enteros: ";
        else
            cout << "Por favor, ingrese un numero de no mas de 9 digitos: ";

        sys::getline(cadConsumo, 11);
    }

    int consumo = strToInt(cadConsumo);
    cout << endl;
    if((c.getNafta()-consumo)<0)
    {
        cout << "Nafta insuficiente" << endl;
        return;
    }
    c.gastarNafta(consumo);
    cout << "Te queda " << c.getNafta() << " de nafta" << endl;
    guardarCambios(c);
}

void subMenuModificar(Coche c)
{
    guardarCambios(cambiarCoche(c));
}

bool subMenuEliminar(char* patente)
{
    mostrarCoche(buscarCoche(patente));
    if( confirmar("\n\nEsta seguro que desea eliminar este auto?(s/n) ") )
    {
        eliminarCoche(patente);
        cout << endl;
        if( !existeCoche(patente) )
        {
            cout << "Registro eliminado exitosamente" << endl;
            return true;
        }
        else
            cout << TEXTO_ERROR << endl;
    }
    return false;
}

#endif // SUBMENU_H_INCLUDED

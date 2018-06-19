#ifndef REGISTRO_H_INCLUDED
#define REGISTRO_H_INCLUDED

using namespace std;

void ingresarCoche(Coche c)
{
    ofstream salida;
    salida.open(DIR_ARCHIVO, ios::binary | ios::app);
    salida.write((char*)&c, sizeof(Coche));
    salida.close();
}

Coche leerCoche()
{
    char marca[30], color[20], patente[10];
    cout << "Marca: ";
    sys::getline(marca, 30);
    cout << "Color: ";
    sys::getline(color, 20);
    cout << "Patente: ";
    sys::getline(patente, 10);
    Coche c(marca, color, patente);
    return c;
}

bool existeCoche(char patente[])
{
    char a[30]="a", b[20]="b", d[10]="d";
    Coche c(a, b, d);
    ifstream entrada;
    entrada.open(DIR_ARCHIVO, ios::binary);
    if(entrada.good())
    {
        while(entrada.read((char*)&c, sizeof(Coche)))
        {
            if(strcmp(patente, c.getPatente())==0)
            {
                entrada.close();
                return true;
            }
        }
    }
    else
    {
        cout << "No se puede leer el archivo";
    }
    entrada.close();
    return false;
}

Coche buscarCoche(char patente[])
{
    char a[30]="a", b[20]="b", d[10]="d";
    Coche c(a, b, d);
    ifstream entrada;
    entrada.open(DIR_ARCHIVO, ios::binary);
    while(entrada.read((char*)&c, sizeof(Coche)))
    {
        if(strcmp(patente, c.getPatente())==0)
        {
            entrada.close();
            return c;
        }
    }
    return c; // NO ES NECESARIO PERO LO PONGO PORQUE ME LA BANCO
}

void mostrarCoche(Coche c)
{
    cout << "Marca: " << c.getMarca() << endl;
    cout << "Color: " << c.getColor() << endl;
    cout << "Patente: " << c.getPatente() << endl;
    cout << "Nafta: " << c.getNafta() << endl;
    cout << endl;
}

void listarCoches()
{
    ifstream entrada;
    entrada.open(DIR_ARCHIVO, ios::binary);
    char a[30]="a", b[20]="b", d[10]="d";
    Coche c(a, b, d);
    if(entrada.good())
    {
        while(entrada.read((char*)&c, sizeof(Coche)))
        {
            mostrarCoche(c);
        }
    }
    else
    {
        cout << "No se puede leer el archivo";
    }
    entrada.close();
}

void eliminarCoche(char patente[])
{
    ifstream entrada;
    ofstream temporal;
    entrada.open(DIR_ARCHIVO, ios::binary);
    temporal.open("temp.dat", ios::binary);
    char a[30]="a", b[20]="b", d[10]="d";
    Coche c(a, b, d);
    while(entrada.read((char*)&c, sizeof(Coche)))
    {
        if(strcmp(patente, c.getPatente())!=0)
        {
            temporal.write((char*)&c, sizeof(Coche));
        }
    }
    entrada.close();
    temporal.close();
    remove(DIR_ARCHIVO);
    rename("temp.dat", DIR_ARCHIVO);
}

#endif // REGISTRO_H_INCLUDED

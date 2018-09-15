#ifndef AUXILIARES_H_INCLUDED
#define AUXILIARES_H_INCLUDED

void pedirEnter(const char* texto = "\n\n\n(Presione enter para continuar)")
{
    char enter[2];
    std::cout << texto;
    sys::getline(enter, 2);
}

bool confirmar(const char* texto = "Esta seguro?(s/n) ")
{
    char op[2];
    std::cout << texto;
    sys::getline(op, 2);
    if( op[0] == 's' || op[0] == 'S' )
        return true;
    else
        return false;
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
            return false;

    }while(c[++x]!='\0');

    return true;
}

int strToInt(char* c)
{
    int longitud=0, cadenaInt=0, base10=1, aux, x;

    while( c[longitud]!='\0' )
        longitud++;

    for( x=longitud-1; x>=0 ; x-- )
    {
        aux=((int)c[x])-48;
        cadenaInt+=aux*base10;
        base10*=10;
    }
    return cadenaInt;
}

#endif // AUXILIARES_H_INCLUDED

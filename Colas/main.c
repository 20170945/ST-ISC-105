#include <stdio.h>
#include <stdlib.h>
#include "colas.h"
#include "conio.h"

#define CANTIDAD 5

typedef enum
{
    Arriba,
    Abajo,
    Izquierda,
    Derecha,
    Ninguno,
    Enter
} flechas;

int seleccion()
{
    if(getch()!=224)
        return Ninguno;
    switch(getch())
    {
    case 72:
        return Arriba;
    case 80:
        return Abajo;
    case 75:
        return Izquierda;
    case 77:
        return Derecha;
    default:
        return Ninguno;
    }
}

int main()
{
    //while(1)
    //{
    //printf("%d\n",getch());
    //  printf("%d\n",seleccion());
    //}
    Cola* nuevaCola = Inicializar();

    printf("1) Agregar valor.\n2) Mostrar valor.\n3) Mostrar todos los valores.\n0) Salir.\n");
    int valor=1;
    while(1)
    {
        valor=seleccion();
        if(valor==Arriba)
        {
            gotoxy(1,wherey()-1);
        }
        else if(valor==Abajo)
        {
            gotoxy(1,wherey()+1);
        }
    }




    return 0;
}

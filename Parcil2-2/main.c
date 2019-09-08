#include <stdio.h>
#include <stdlib.h>

typedef struct nodod
{
    int valor;
    struct nodod* anterior;
} Nodo;

typedef struct pilad
{
    int cantidad;
    struct pilad* pilaAnterior;
    Nodo* cabeza;
} Pila;

typedef struct
{
    int cantidad;
    int Limite;
    Pila* pilas;
} ConjuntoPila;

ConjuntoPila* InicializarConjuntoPila()
{
    ConjuntoPila* nuevoConjuntoPila = (ConjuntoPila*)malloc(sizeof(ConjuntoPila));
    nuevoConjuntoPila->Limite = 10;
    nuevoConjuntoPila->cantidad = 0;
}

void Push(ConjuntoPila* Paquete, int valor);
int Pop(ConjuntoPila* Paquete);


int main()
{
    int seleccion;
    ConjuntoPila* mConjuntoPilas = InicializarConjuntoPila();
    while(seleccion!=-1)
    {
        printf("Input:");
        scanf("%d",&seleccion);
        if(seleccion>0)
        {
            Push(mConjuntoPilas,seleccion);
        }
        else
        {
            printf("%d\n",Pop(mConjuntoPilas));
        }
    }
    return 0;
}

void Push(ConjuntoPila* Paquete, int valor)
{
    Pila* nuevaPila;
    Nodo* nuevoNodo;

    if(Paquete->cantidad==0)
    {
        Paquete->pilas = (Pila*)malloc(sizeof(Pila));
        Paquete->pilas->cantidad = 0;
        Paquete->pilas->pilaAnterior = NULL;
        Paquete->pilas->cabeza = NULL;
        Paquete->cantidad++;
    }

    if(Paquete->pilas->cantidad == Paquete->Limite)
    {
        nuevaPila = (Pila*)malloc(sizeof(Pila));
        nuevaPila->pilaAnterior = Paquete->pilas;
        nuevaPila->cabeza = NULL;
        nuevaPila->cantidad = 0;
        Paquete->pilas = nuevaPila;
        Paquete->cantidad++;
    }

    if(Paquete->pilas->cabeza == NULL)
    {
        Paquete->pilas->cabeza = (Nodo*)malloc(sizeof(Nodo));
        Paquete->pilas->cabeza->valor = valor;
        Paquete->pilas->cabeza->anterior = NULL;
        Paquete->pilas->cantidad=1;
    }
    else
    {
        nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
        nuevoNodo->valor = valor;
        nuevoNodo->anterior = Paquete->pilas->cabeza;
        Paquete->pilas->cabeza = nuevoNodo;
        Paquete->pilas->cantidad++;
    }
}

int Pop(ConjuntoPila* Paquete)
{
    if(Paquete->cantidad==0)
    {
        return -1;
    }

    int valor = Paquete->pilas->cabeza->valor;

    Paquete->pilas->cantidad--;
    Paquete->pilas->cabeza = Paquete->pilas->cabeza->anterior;
    if(Paquete->pilas->cantidad==0)
    {
        Paquete->cantidad--;
        Paquete->pilas = Paquete->pilas->pilaAnterior;
    }
    return valor;
}

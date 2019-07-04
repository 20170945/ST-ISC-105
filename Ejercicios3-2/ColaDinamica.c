#include <stdio.h>
#include <stdlib.h>
#include "ColaDinamica.h"
//20170945

Cola* Inicializar()
{
    Cola* nuevaCola = (Cola*)malloc(sizeof(Cola));
    nuevaCola->Tamano = 0;
    nuevaCola->Inicio = NULL;
    nuevaCola->Fin = NULL;
    return nuevaCola;
}

Nodo* Crear(float x)
{
    Nodo* p;
    p = (Nodo*)malloc(sizeof(Nodo));
    p->valor = x;
    p->siguiente = NULL;
    return p;
}

void push(Cola* cola, float dato)
{
    Nodo* target;
    if(cola->Inicio==NULL)
    {
        cola->Inicio = Crear(dato);
        cola->Fin = cola->Inicio;
    }
    else
    {
        cola->Fin->siguiente = Crear(dato);
        cola->Fin = cola->Fin->siguiente;
    }
    cola->Tamano++;
}

float pop(Cola* cola)
{
    float valor = cola->Inicio->valor;
    Nodo* fuera = cola->Inicio;
    cola->Inicio = fuera->siguiente;
    cola->Tamano--;
    free(fuera);
    return valor;
}

short isEmpty(Cola* cola)
{
    return cola->Tamano == 0;
}

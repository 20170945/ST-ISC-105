#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PilaDinamica.h"
//20170945
Pila* IniciaPila(Pila *nuevaPila)
{
    nuevaPila = (Pila*)malloc(sizeof(Pila));
    nuevaPila->TamanoPila = 0;
    nuevaPila->Top = NULL;
    return nuevaPila;
}

Nodo* enlazar(float x, Nodo* enlace)
{
    Nodo* p;
    p = (Nodo*)malloc(sizeof(Nodo));
    p->valor = x;
    p->anterior = enlace;
    return p;
}

void Push(Pila *pila, float dato)
{
    pila->Top = enlazar(dato, pila->Top);
    pila->TamanoPila++;

    return pila;
}

float Pop(Pila *pila)
{
    Nodo* fuera = pila->Top;
    float valor = pila->Top->valor;
    if(pila->Top->anterior != NULL)
        pila->Top = fuera->anterior;
    free(fuera);
    pila->TamanoPila--;
    return valor;
}

int Size(Pila *pila)
{
    return pila->TamanoPila;
}

float Peek(Pila *pila)
{
    float valor = Pop(pila);
    Push(pila,valor);
    return valor;
}

short isEmpty(Pila *pila)
{
    return pila->TamanoPila == 0;
}

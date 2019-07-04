#include <stdio.h>
//20170945
#ifndef _PilaEstatica
#define _PilaEstatica
int PosicionActual;

typedef struct ELEMENTO{
    float valor;
    struct ELEMENTO* anterior;
} Nodo;

typedef struct
{
    Nodo* Top;
    int TamanoPila;
}Pila;

Pila* IniciaPila(Pila*);
Nodo* enlazar(float, Nodo*);
void Push(Pila*, float);
float Pop(Pila*);
int Size(Pila*);
short isEmpty(Pila*);
float Peek(Pila*);
#endif //_PilaEstatica

#include <stdio.h>

#ifndef _PilaEstatica
#define _PilaEstatica
int PosicionActual;

typedef struct
{
    int PosicionActual;
    float* Pila;
    int TamanoPila;
}Pila;

Pila* IniciaPila(Pila*);
void VerificarEspacio(Pila*);
void Push(Pila*, float);
float Pop(Pila*);
int Size(Pila*);
short isEmpty(Pila*);
float Peek(Pila*);
#endif //_PilaEstatica

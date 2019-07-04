#include <stdlib.h>
#include "triplepila.h"

const int TAMANOINICIAL=9;

PilaTriple* IniciarPilaTriple()
{
    PilaTriple* nuevaPila = (PilaTriple*)malloc(sizeof(PilaTriple));
    nuevaPila->tamanoPila = TAMANOINICIAL;
    nuevaPila->PilaTriple = (float*)calloc(TAMANOINICIAL,sizeof(float));
    nuevaPila->PosicionesPilas[0] = 0;
    nuevaPila->PosicionesPilas[1] = TAMANOINICIAL/3;
    nuevaPila->PosicionesPilas[2] = (2*TAMANOINICIAL)/3;
    return nuevaPila;
}


void Push(PilaTriple* pilatriple,int numeroPila,float elemento)
{
    VerificarEspacio(pila, numeroPila);
    *(pilatriple->PilaTriple + (pilatriple->PosicionesPilas[numeroPila])) = elemento;
    pilatriple->PosicionesPilas[numeroPila]++;
}

void VerificarEspacio(PilaTriple* pilatriple, int numeroPila)
{

}

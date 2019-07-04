#include <stdio.h>
#include <stdlib.h>

#ifndef _pilatriple
#define _pilatriple

typedef struct {
    int tamanoPila;
    float *PilaTriple;
    int PosicionesPilas[3];
} PilaTriple;

PilaTriple* IniciarPilaTriple();
void Push(PilaTriple*,int,float);
void VerificarEspacio(PilaTriple*, int);


#endif // _pilatriple

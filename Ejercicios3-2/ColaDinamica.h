#include <stdio.h>
//20170945
#ifndef _ColaDinamica
#define _ColaDinamica

typedef struct ELEMENTO{
    float valor;
    struct ELEMENTO* siguiente;
} Nodo;

typedef struct
{
    Nodo* Inicio;
    Nodo* Fin;
    int Tamano;
}Cola;

Cola* Inicializar();
Nodo* Crear(float);
void push(Cola*, float);
float pop(Cola*);
short isEmpty(Cola*);

#endif //_ColaDinamica


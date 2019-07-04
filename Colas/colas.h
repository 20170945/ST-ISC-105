#include <stdlib.h>
#ifndef _Colash
#define _Colash

typedef struct
{
    float* elementos;
    int tamano;
    unsigned int primerIndice;
    unsigned int ultimoIndice;
    int cantidad;
}Cola;

Cola* Inicializar();
int TamanoCola(Cola*);
void enqueue(Cola*,float);
short isEmpty(Cola*);
float getFront(Cola*);
float dequeue(Cola*);
void VerificarEspacio(Cola*);

#endif // _Colash

#include <stdlib.h>
#include "colas.h"

Cola* Inicializar()
{
    const int TAM = 100;
    Cola* nuevaCola = (Cola*)malloc(sizeof(Cola));
    nuevaCola->tamano = TAM;
    nuevaCola->primerIndice = 0;
    nuevaCola->ultimoIndice = 0;
    nuevaCola->elementos = (float*)calloc(TAM,sizeof(float));
    nuevaCola->cantidad = 0;
    return nuevaCola;
}

int TamanoCola(Cola* cola)
{
    return cola->cantidad;
}

void VerificarEspacio(Cola* cola)
{
    int i;
    if(TamanoCola(cola) < cola->tamano)
        return;
    float* nuevoEspacio = (float*)malloc(cola->tamano * 2);
    i = cola->primerIndice;
    while(i!=cola->ultimoIndice)
    {
        *(nuevoEspacio+i) = *(cola->elementos+i++);

        if(i == cola->tamano)
        {
            i=0;
        }
    }
    cola->primerIndice = 0;
    cola->ultimoIndice = cola->cantidad - 1;
    cola->tamano = cola->tamano * 2;
}

void enqueue(Cola* cola,float elemento)
{
    VerificarEspacio(cola);
    cola->ultimoIndice++;
    if(cola->ultimoIndice >= cola->tamano || cola->cantidad==0)
        cola->ultimoIndice = 0;

    *(cola->elementos+cola->ultimoIndice) = elemento;
    cola->cantidad++;
}

float dequeue(Cola* cola)
{
    if(isEmpty(cola))
        return 0;

    float respuesta = *(cola->elementos+cola->primerIndice);
    cola->primerIndice++;
    if(cola->primerIndice >= cola->tamano)
        cola->primerIndice = 0;
    return respuesta;

    cola->cantidad--;
    return respuesta;
}

short isEmpty(Cola* cola)
{
    return cola->cantidad == 0;
}

float getFront(Cola* cola)
{
    return *(cola->elementos+cola->primerIndice);
}




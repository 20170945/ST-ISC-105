#include <stdio.h>
#include <stdlib.h>
#include "ListaDobleCircular.h"


Lista* InicializarLista()
{
    Lista* nuevaLista = (Lista*)malloc(sizeof(Lista));
    nuevaLista->Cantidad = 0;
    return nuevaLista;
}

void Agregar(Lista* Listado,Pelicula elemento)
{
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->data = elemento;

    if(Listado->Cabeza == NULL)
    {
        Listado->Cabeza = nuevoNodo;
        Listado->Cabeza->anterior = Listado->Cabeza;
        Listado->Cabeza->siguiente = Listado->Cabeza;
        return;
    }

    nuevoNodo->siguiente = Listado->Cabeza;
    nuevoNodo->anterior = Listado->Cabeza->anterior;
    Listado->Cabeza->anterior->siguiente = nuevoNodo;
    Listado->Cabeza->anterior = nuevoNodo;
}

void Eliminar(Lista*, int);
void Insertar(Lista*, Pelicula, int);
Nodo Buscar(Lista*,int);
Lista* Ordenar(Lista*);

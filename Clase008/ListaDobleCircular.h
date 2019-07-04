#include <stdio.h>
#include <stdlib.h>
#ifndef _LISTANODOCIRCULAR
#define _LISTANODOCIRCULAR

typedef struct
{
    unsigned int id;
    char *Titulo;
    unsigned short ano;
    char *Clasificacion;
    float Calificacion;
    float Duracion;
    char **Generos;
    char *Sinopsis;
}Pelicula;

typedef struct sNodo
{
    Pelicula data;
    struct sNodo *anterior;
    struct sNodo *siguiente;
}Nodo;

typedef struct
{
    Nodo *Cabeza;
    unsigned int Cantidad;
}Lista;

Lista* InicializarLista();

void Agregar(Lista*,Pelicula);
void Eliminar(Lista*, int);
void Insertar(Lista*, Pelicula, int);
Nodo Buscar(Lista*,int);
Lista* Ordenar(Lista*);

#endif // _LISTANODOCIRCULAR

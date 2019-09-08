#include <stdio.h>
#include <stdlib.h>

typedef struct nodod
{
    int valor;
    struct nodod* siguente;
    struct nodod* anterior;
}Nodo;

typedef struct
{
    Nodo* pivote;
}lista;

lista* Inicializar()
{
    lista* nuevaLista = (lista*)malloc(sizeof(lista));
    return nuevaLista;
}

Nodo* Crear(int valor)
{
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->valor = valor;
    nuevoNodo->anterior = NULL;
    nuevoNodo->siguente = NULL;
    return nuevoNodo;
}

void Imprimir(lista* listado)
{
    Nodo* interactivo = listado->pivote;
    while(interactivo->anterior!=NULL)
    {
        interactivo = interactivo->anterior;
    }
    while(interactivo!=NULL)
    {
        printf("%d ", interactivo->valor);
        interactivo = interactivo->siguente;
    }
}

void OrdenarInput(int* numeros, int x, int n);
void AgregarElemento(lista* listado, int valor, int x);

int main()
{
    int x, n, i;
    scanf("%d %d",&x,&n);
    int* numeros = (int*)malloc(n*sizeof(int));

    for(i=0;i<n;i++)
    {
        scanf("%d",(numeros+i));
    }

    lista* ListaEnlazada = Inicializar();
    ListaEnlazada->pivote = Crear(*(numeros+x-1));

    for(i=0;i<n;i++)
    {
        if(i!=x-1)
        {
            AgregarElemento(ListaEnlazada, *(numeros+i),x);
        }
    }

    Imprimir(ListaEnlazada);

    return 0;
}

void OrdenarInput(int* numeros, int x, int n)
{
    int i, j, indmenor, temporal;
    for(i=0;i<x-1;i++)
    {
        indmenor = i;
        for(j=i;j<x;j++)
        {
            if(*(numeros+indmenor)>*(numeros+j))
            {
                indmenor=j;
            }
        }
        if(indmenor!=i)
        {
            temporal = *(numeros+i);
            *(numeros+i)=*(numeros+indmenor);
            *(numeros+indmenor) = temporal;
        }
    }

    for(i=x;i<n;i++)
    {
        indmenor = i;
        for(j=i;j<n;j++)
        {
            if(*(numeros+indmenor)>*(numeros+j))
            {
                indmenor=j;
            }
        }
        if(indmenor!=i)
        {
            temporal = *(numeros+i);
            *(numeros+i)=*(numeros+indmenor);
            *(numeros+indmenor) = temporal;
        }
    }
}

void AgregarElemento(lista* listado, int valor, int x)
{
    Nodo* target = Crear(valor);
    Nodo* interactivo;
    if(valor<x)
    {
        target->siguente = listado->pivote;
        if(listado->pivote->anterior != NULL)
        {
            target->anterior = listado->pivote->anterior;
            listado->pivote->anterior->siguente = target;
        }
        listado->pivote->anterior = target;
    }
    else
    {
        if(listado->pivote->siguente==NULL)
        {
            target->anterior = listado->pivote;
            listado->pivote->siguente = target;
            return;
        }
        interactivo = listado->pivote->siguente;
        while(interactivo->siguente!=NULL)
        {
            interactivo = interactivo->siguente;
        }
        target->anterior = interactivo;
        interactivo->siguente = target;
    }
}











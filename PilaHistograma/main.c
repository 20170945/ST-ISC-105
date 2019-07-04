#include <stdio.h>
#include <stdlib.h>

#define FULL 219
#define HALF 221
//20170945

int siono()//función hecha por mi en IntroAlgoritmia
{
    int seleccion;
    while(seleccion!=115 && seleccion!=83 && seleccion!=110 && seleccion!=78)
    {
        seleccion=getch();
    }
    if(seleccion==110 || seleccion==78)
    {
        seleccion=0;
    }
    return seleccion;
}

void printbarra(float valor)
{
    for(;valor>0;)
    {
        if(valor-->0.5)
        {
            printf("%c", FULL);
        }
        else
        {
            printf("%c", HALF);
        }
    }
}

void capturar(float* pila, int* cant_pila);
void printvaciar(float* pila, int* cant_pila);

int main()
{
    float* pila = (float*) malloc(sizeof(float));
    int* cant_pila = (int*) malloc(sizeof(int));

    capturar(pila,cant_pila);
    printvaciar(pila, cant_pila);

    free(pila);
    free(cant_pila);
    return 0;
}
void capturar(float* pila, int* cant_pila)
{
    *cant_pila = 0;
    printf("Introduzca valores a guardar en la pila:\n");
    while(1)
    {
        printf("Valor %d:",(*cant_pila)+1);
        scanf("%f",(pila+(*cant_pila)++));
        printf("%cDeseas a%cadir otro valor m%cs? (S/N)\n",168,164,160);
        if(siono())
        {
            pila = realloc(pila,(*cant_pila)*sizeof(float));
        }
        else
        {
            break;
        }
    }
}

void printvaciar(float* pila, int* cant_pila)
{
    printf("Imprimiendo datos de la pila.\n");
    for(;--(*cant_pila)>=0;)
    {
        printbarra(*(pila+(*cant_pila)));
        printf("%.2f\n",*(pila+(*cant_pila)));
        if(*cant_pila>0)
        {
            pila = realloc(pila,(*cant_pila)*sizeof(float));
        }
    }
}

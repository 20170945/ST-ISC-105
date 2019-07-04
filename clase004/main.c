#include <stdio.h>
#include <stdlib.h>
//20170945

void defsizearray(int* tam);
void fillarray(int* array, int* tam);
void OrdernarInsercion(int *array,int *tam);
void printarray(int* array, int* tam)
{
    for(int i=0;i<*tam;i++)
    {
        printf("%d",*(array+i));
        if(i+1!=*tam)
        {
            printf(",");
        }
    }
}

int main()
{
    int* tam = calloc(1,sizeof(int));
    defsizearray(tam);
    int* array = calloc(*tam,sizeof(int));
    fillarray(array,tam);
    printarray(array,tam);
    OrdernarInsercion(array,tam);
    printf("\n");
    printarray(array,tam);
    return 0;
}

void defsizearray(int* tam)
{
    do
    {
        printf("Defina el tama%co del arreglo:",164);
        scanf("%d",tam);
    }
    while(*tam<=0);
}

void fillarray(int* array, int* tam)
{
    for(int i=0; i<*tam; i++)
    {
        do
        {
            printf("Valor %d:",i+1);
            scanf("%d",array+i);
        }
        while(*(array+i)<=0);
    }
}

void OrdernarInsercion(int *array,int *tam)
{
    int i, j, ValorActual;

    for(i=1;i<*tam;i++)
    {
        ValorActual=*(array+i);
        j=i-1;
        while(j>=0 && *(array+j) > ValorActual)
        {
            *(array+j+1) = *(array+j);
            j--;
        }
        *(array+j+1) = ValorActual;
    }
}

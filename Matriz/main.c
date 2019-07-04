#include <stdio.h>
#include <stdlib.h>
//20170945

int intlen(int valor)
{
    int dig = 0;
    while(valor>=1)
    {
        valor/=10;
        dig++;
    }
    return dig;
}

void capturar(int **matriz, int *fil, int *col, int *intsize);

void printmatriz(int **matriz, int *fil, int *col, int *intsize)
{
    int i,j;
    for(i=0; i<*fil; i++)
    {
        for(j=0; j<*col; j++)
        {
            if(*(*(matriz+i)+j)>=0)
            {
                printf("  %*d", *intsize, *(*(matriz+i)+j));
            }
            else
            {
                printf(" %*d", *intsize, *(*(matriz+i)+j));
            }
        }
        printf("\n");
    }
}

void inversa(int **matriz, int *fil, int *col, int *intsize)
{
    int i,j;
    printf("Inversa:\n");
    for(j=0; j<*col; j++)
    {
        for(i=0; i<*fil; i++)
        {
            if(*(*(matriz+i)+j)>=0)
            {
                printf("  %*d", *intsize, *(*(matriz+i)+j));
            }
            else
            {
                printf(" %*d", *intsize, *(*(matriz+i)+j));
            }
        }
        printf("\n");
    }
}

int main()
{
    int *fil = (int)malloc(sizeof(int));
    int *col = (int)malloc(sizeof(int));
    int *intsize = (int)malloc(sizeof(int));

    printf("Indique la cantidad de filas:");
    scanf("%d",fil);
    printf("Indique la cantidad de columnas:");
    scanf("%d",col);

    int **matriz = calloc(*fil,sizeof(int*));
    for(int i=0; i<*fil; i++)
    {
        *(matriz+i) = calloc(*col,sizeof(int));
    }
    capturar(matriz,fil,col,intsize);
    printmatriz(matriz,fil,col,intsize);
    inversa(matriz,fil,col,intsize);
    return 0;
}

void capturar(int **matriz, int *fil, int *col, int *intsize)
{
    int i,j;
    int absmax = 0;
    for(i=0; i<*fil; i++)
    {
        for(j=0; j<*col; j++)
        {
            printf("Introduzca el elemento %d de la fila %d:",j+1,i+1);
            scanf("%d", (*(matriz+i)+j));
            if(abs(*(*(matriz+i)+j))>absmax)
            {
                absmax = abs(*(*(matriz+i)+j));
            }
        }
    }
    *intsize = intlen(absmax);
}

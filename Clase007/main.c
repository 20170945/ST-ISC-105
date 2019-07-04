#include <stdio.h>
#include <stdlib.h>

int main()
{
    long contador = 0;
    int *puntero;

    while((puntero = (int*)malloc(sizeof(int)))!=NULL)
    {
        contador++;
    }

    printf("%d MB\n", (contador*sizeof(int))/1048576);
    return 0;
}

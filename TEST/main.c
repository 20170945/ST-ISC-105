#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int FIL = 8, COL = 8;
    int **tablero = calloc(FIL,sizeof(int*));
    int i, j, filaReina, columnaReina;
    printf("Introduzca la coordenadas:");
    scanf("%d %d", &filaReina, &columnaReina);

    for(i=0; i<FIL; i++)
    {
        *(tablero+i) = calloc(COL,sizeof(int));
        for(j=0; j<COL; j++)
        {
            if(i == filaReina || j==columnaReina)
            {
                *(*(tablero+i)+j)='*';
            }
            else if(i-j == filaReina - columnaReina || i+j == filaReina + columnaReina)
            {
                *(*(tablero+i)+j)='*';
            }
            else
            {
                *(*(tablero+i)+j)='#';
            }
        }
    }
    *(*(tablero+filaReina)+columnaReina)='R';
    for(i=0; i<COL; i++)
    {
        for(j=0; j<FIL; j++)
        {
            printf("%c ", *(*(tablero+i)+j));
        }
        printf("\n");
    }
    return 0;
}

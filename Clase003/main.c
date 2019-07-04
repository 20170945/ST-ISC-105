#include <stdio.h>
#include <stdlib.h>
#define TABLASIZE 8

int main()
{
    int tablero[TABLASIZE][TABLASIZE]=
    {
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0}
    };
    int x, y;
    for(int i=0;i<TABLASIZE;i++)
    {
        for(int j=0;j<TABLASIZE;j++)
        {
            if(*(*(tablero+i)+j)==1)
            {
                printf("h");
                x=j;
                y=i;
            }
            printf("%d ",*(*(tablero+i)+j));
        }
        printf("\n");
    }

    return 0;
}

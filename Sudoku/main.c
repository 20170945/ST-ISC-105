#include <stdio.h>
#include <stdlib.h>
#include "conio.h"

const int DIM = 9;

void MostrarSudoku(short Sudoku[DIM][DIM])
{
    short i, j;
    for(i=0; i<DIM; i++)
    {
        for(j=0; j<DIM; j++)
        {
            printf("%d",Sudoku[i][j]);
            if(j==2 || j==5)
            {
                printf("%c",186);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
        if(i==2 || i==5)
        {
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",205,205,205,205,205,206,205,205,205,205,205,206,205,205,205,205,205);
        }
    }
}

void CapturarMatriz(short Sudoku[DIM][DIM]);
short resolverSudokuBT(short Sudoku[DIM][DIM], short x, short y);
short resolverSudoku(short Sudoku[DIM][DIM]);
short esValido(short Sudoku[DIM][DIM], short x, short y);

int main()
{
    srand(time(NULL));
    //short Sudoku[9][9]= {0};
    short Sudoku[9][9]=
    {
        {0,7,9,0,4,6,3,5,8},
        {0,0,6,5,0,0,0,7,4},
        {4,2,0,3,7,8,0,1,6},
        {2,0,8,7,0,0,4,3,0},
        {5,0,7,4,8,3,0,0,1},
        {6,3,0,0,0,0,8,0,0},
        {0,6,0,9,3,0,0,0,2},
        {0,0,0,6,0,2,0,0,9},
        {0,4,0,8,5,7,1,0,3}
    };
    //CapturarMatriz(Sudoku);
    system("cls");
    MostrarSudoku(Sudoku);
    if(resolverSudoku(Sudoku))
    {
        printf("\nSudoku Resuelto:\n");
        MostrarSudoku(Sudoku);
    }
    else
    {
        printf("\nNo hay soluci%cn.\n",162);
        MostrarSudoku(Sudoku);
    }
    return 0;
}

void CapturarMatriz(short Sudoku[DIM][DIM])
{
    short x=wherex();
    short y=wherey();
    short i=0;
    short j=0;
    MostrarSudoku(Sudoku);
    short seleccion;
    do
    {
        gotoxy(x,y);
        seleccion=getch();
        if(seleccion==224)
        {
            switch(getch())
            {
            case 72://up
                if(y>1)
                {
                    if(y==5 || y==9)
                    {
                        y--;
                    }
                    y--;
                    i--;
                }
                break;
            case 80://down
                if(y<11)
                {
                    if(y==3 || y==7)
                    {
                        y++;
                    }
                    y++;
                    i++;
                }
                break;
            case 75://left
                if(x>1)
                {
                    x-=2;
                    j--;
                }
                break;
            case 77://right
                if(x<16)
                {
                    x+=2;
                    j++;
                }
                break;
            default:
                break;
            }
        }
        else if(seleccion!=13)
        {
            seleccion=seleccion-48;
            if(seleccion>=0 && seleccion<=9)
            {
                printf("%d",seleccion);
                Sudoku[i][j]=seleccion;
            }
        }
    }
    while(seleccion!=13);
}

short resolverSudokuBT(short Sudoku[DIM][DIM], short x, short y)
{
    short suma=0;
    short random;
    if(y>=DIM)
    {
        return 1;
    }
    if(x>=DIM)
    {
        return resolverSudokuBT(Sudoku, 0, y+1);
    }
    if(Sudoku[y][x]!=0)
    {
        return resolverSudokuBT(Sudoku, x+1, y);
    }

    do
    {
        random=100;
        while(random+suma>45)
        {
            random=rand()%9+1;
        }
        suma+=random;
        Sudoku[y][x] = random;
        if(esValido(Sudoku,x,y))
        {
            if(resolverSudokuBT(Sudoku,x+1,y))
            {
                return 1;
            }
        }
    }while(suma<45);
    return 0;
}

short resolverSudoku(short Sudoku[DIM][DIM])
{
    return resolverSudokuBT(Sudoku,0,0);
}

short esValido(short matrizSudoku[DIM][DIM], short x, short y)
{
    short i, j;
    short encontrado=0;
    short suma=0;

    for (i = 0; i < DIM; i++)
    {
        suma+=matrizSudoku[y][i];
        if(matrizSudoku[y][i] == matrizSudoku[y][x])
        {
            encontrado++;
        }
    }

    if (encontrado > 1 || suma>45)
    {
        return 0;
    }

    encontrado = 0;
    suma=0;
    for (i = 0; i < DIM; i++)
    {
        suma+=matrizSudoku[y][i];
        if(matrizSudoku[i][x] == matrizSudoku[y][x])
        {
            encontrado++;
        }
    }

    if (encontrado > 1 || suma>45)
    {
        return 0;
    }

    encontrado = 0;
    suma=0;
    for (i = y - (y % 3); i < (y - (y % 3) + 3); i++)
    {
        for (j = x - (x % 3); j < (x - (x % 3) + 3); j++)
        {
            suma+=matrizSudoku[i][j];
            if(matrizSudoku[i][j] == matrizSudoku[y][x])
            {
                encontrado++;
            }
        }
    }
    if (encontrado > 1 || suma>45)
    {
        return 0;
    }
    return 1;
}

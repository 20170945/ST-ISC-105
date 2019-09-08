#include <stdio.h>
#include <stdlib.h>
#include "conio.h"
#include "CustomInputs.h"

void hello()
{
    while(1)
    {
        printf("%d\n",getch());
    }
}

unsigned short lenuint(unsigned int valor)
{
    unsigned short len=0;
    while(valor>0)
    {
        len++;
        valor=valor/10;
    }
    return len;
}

unsigned int uintinput(int size, unsigned int valor)
{
    unsigned short input;
    unsigned short cantc = lenuint(valor);

    if(valor!=0)
    {
        printf("%u",valor);
    }

    do
    {
        input=getch();
        if(input==8 && cantc>0)
        {
            printf("\b \b");
            valor=valor/10;
            cantc--;
        }
        else if(input-48<=9 && input-48>=0 && cantc<size)
        {
            printf("%c",input);
            valor=valor*10+input-48;
            cantc++;
        }
    }
    while(input!=13);
    printf("\n");
    return valor;
}

char* chartiempo(unsigned int total)
{
    char* tiempo = (char*)malloc(6*sizeof(char));
    *(tiempo)=total/36000+48;
    total=total%36000;
    *(tiempo+1)=total/3600+48;
    total=total%3600;
    *(tiempo+2)=total/600+48;
    total=total%600;
    *(tiempo+3)=total/60+48;
    total=total%60;
    *(tiempo+4)=total/10+48;
    total=total%10;
    *(tiempo+5)=total+48;
    return tiempo;
}

unsigned int inputtiempo(unsigned int total)
{
    char* tiempo = chartiempo(total);
    unsigned short x,y,i,j,seleccion;
    i=0;
    x=wherex();
    y=wherey();
    printf("%c%c:%c%c:%c%c",*(tiempo),*(tiempo+1),*(tiempo+2),*(tiempo+3),*(tiempo+4),*(tiempo+5));
    do
    {
        if(i<2)
        {
            j=0;
        }
        else if(i<4)
        {
            j=1;
        }
        else
        {
            j=2;
        }
        gotoxy(x+i+j,y);
        seleccion=getch();
        if(seleccion>=48 && seleccion<=57 && i<6)
        {
            *(tiempo+i)=seleccion;
            printf("%c",*(tiempo+i));
            i++;
        }
        else if(seleccion==8)
        {
            i--;
        }
    }
    while(seleccion!=13);
    total=(*(tiempo)-48)*36000+(*(tiempo+1)-48)*3600+(*(tiempo+2)-48)*600+(*(tiempo+3)-48)*60+(*(tiempo+4)-48)*10+(*(tiempo+5)-48);
    free(tiempo);
    return total;
}

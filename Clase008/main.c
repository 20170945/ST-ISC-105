#include <stdio.h>
#include <stdlib.h>
#include "conio.h"
#include "ListaDobleCircular.h"


typedef enum
{
    Salir,
    Agregars,
    Modificars,
    Eliminars,
    Insertars,
    Explorars,
    Ordenars,
    Buscars
} eSeleccionMenu;


void MostrarMarco()
{
    system("cls");
    int i;
    printf("%c",201);
    for(i=0; i<63; i++)
    {
        printf("%c",205);
    }
    printf("%c\n",187);

    for(i=0; i<15; i++)
    {
        printf("%c\t\t\t\t\t\t\t\t%c\n",186,186);
    }

    printf("%c",200);
    for(i=0; i<63; i++)
    {
        printf("%c",205);
    }
    printf("%c\n",188);
}
eSeleccionMenu MostrarMenu();

void AgregarNuevaPelicula(Lista *listado);

int main()
{
    Lista* Peliculas = InicializarLista();
    unsigned short opcionActual;
    do
    {
        opcionActual=MostrarMenu();
        switch(opcionActual)
        {
        case Agregars:
            AgregarNuevaPelicula(Peliculas);
            break;
        case Modificars:
            break;
        case Eliminars:
            break;
        case Insertars:
            break;
        case Explorars:
            break;
        case Ordenars:
            break;
        case Buscars:
            break;
        case Salir:
            break;
        }
    }
    while(opcionActual!=0);

    return 0;
}

eSeleccionMenu MostrarMenu()
{
    int i;
    unsigned short seleccion;
    char Opciones[8][10]= {"Agregar","Modificar","Eliminar","Insertar","Explorar","Ordenar","Buscar","Salir"};
    do
    {
        MostrarMarco();
        gotoxy(2,2);
        printf("Gesti%cn de Pel%cculas",162,161);
        gotoxy(2,3);
        for(i=0; i<63; i++)
        {
            printf("%c",205);
        }
        for(i=0; i<7; i++)
        {
            gotoxy(2,4+i);
            printf("%d: %s",i+1,Opciones[i]);
            if(i<5 || i==6)
            {
                printf(" una pel%ccula",161);
            }
            else
            {
                printf(" las pel%cculas",161);
            }

            if(i==3 || i==5)
            {
                printf(" por a%co.",164);
            }
            else
            {
                printf(".");
            }
        }
        gotoxy(2,4+i);
        printf("0: %s",Opciones[i]);
        printf("\e[?25l");
        fflush(stdin);
        seleccion=getch()-48;
    }
    while(seleccion>8);
    return seleccion;
}

void AgregarNuevaPelicula(Lista *listado)
{
    int i;
    system("cls");
    printf("\e[?25h");
    Pelicula nuevaPelicula;
    printf("ID: ");
    scanf("%d", &(nuevaPelicula.id));
    printf("T%ctulo: ",161);
    nuevaPelicula.Titulo = (char*)malloc(100*sizeof(char));
    fflush(stdin);
    fgets(nuevaPelicula.Titulo,100,stdin);
    fflush(stdin);
    printf("A%co: ",164);
    fflush(stdin);
    scanf("%d",&(nuevaPelicula.ano));
    nuevaPelicula.Clasificacion = (char*)malloc(6*sizeof(char));
    printf("Clasificaci%cn:\n1) G\n2) PG\n3) PG-13\n4) R\n5) NC-17",162);
    do
    {
        i=getch()-48;
        switch(i)
        {
        case 1:
            nuevaPelicula.Clasificacion = "G";
            break;
        case 2:
            nuevaPelicula.Clasificacion = "PG";
            break;
        case 3:
            nuevaPelicula.Clasificacion = "PG-13";
            break;
        case 4:
            nuevaPelicula.Clasificacion = "R";
            break;
        case 5:
            nuevaPelicula.Clasificacion = "NC-17";
            break;
        default:
            i=0;
        }
    }while(i==0);
    for(i=5;i<8;i++)
    {
        gotoxy(1,i);
        delline();
    }
    gotoxy(16,4);
    printf("%s\nCalificaci%cn: ",nuevaPelicula.Clasificacion,162);
    fflush(stdin);
    scanf("%f",&nuevaPelicula.Calificacion);
    printf("Duraci%cn: ",162);
    scanf("%f",&nuevaPelicula.Duracion);
    getch();

}

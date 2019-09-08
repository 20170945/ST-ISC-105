#include <stdio.h>
#include <stdlib.h>
#include "conio.h"
#include "ListaDobleCircular.h"
#include "CustomInputs.h"

char Generos[9][16]=
{
    {'A','c','c','i',162,'n',NULL},
    "Adventura",
    "Comedia",
    "Drama",
    "Terror",
    "Musical",
    {'C','i','e','n','c','i','a',' ','F','i','c','c','i',162,'n',NULL},
    {'S','u','s','p','e','n','c','i',162,'n',NULL},
    "Infantil"
};

char* SelectClasificacion()
{
    printf("\e[?25l");
    int i;
    char* nuevaString = (char*)malloc(6*sizeof(char));
    printf("Clasificaci%cn:\n1) G\n2) PG\n3) PG-13\n4) R\n5) NC-17",162);
    do
    {
        i=getch()-48;
        switch(i)
        {
        case 1:
            nuevaString = "G";
            break;
        case 2:
            nuevaString = "PG";
            break;
        case 3:
            nuevaString = "PG-13";
            break;
        case 4:
            nuevaString = "R";
            break;
        case 5:
            nuevaString = "NC-17";
            break;
        default:
            i=0;
        }
    }
    while(i==0);
    return nuevaString;
}

unsigned short selectGeneros(unsigned short valor, unsigned int y)
{
    printf("\e[?25l");
    int i, j;
    printf("Generos:");
    gotoxy(1,y+9);
    printf("0) Continuar");
    do
    {
        gotoxy(1,y);
        for(j=0; j<9; j++)
        {
            if(valor & (1<<8-j))
            {
                textbackground(LIGHTGRAY);
                textcolor(BLACK);
            }
            else
            {
                textbackground(BLACK);
                textcolor(LIGHTGRAY);
            }
            printf("%d) %s\n",j+1,Generos[j]);
        }
        i=getch()-48;
        if(i>0 && i<10)
        {
            valor = valor ^ (1<<9-i);
        }
    }
    while(i!=0);
    textbackground(BLACK);
    textcolor(LIGHTGRAY);
    return valor;
}

void printGeneros(unsigned short valor)
{
    short i, j;
    for(i=8,j=0; i>=0; i--)
    {
        if(valor & (1<<i))
        {
            if(j!=0)
            {
                printf(",");
            }
            if(j==3)
            {
                printf("\n\t");
                j=0;
            }
            printf(" %s",Generos[8-i]);
            j++;
        }
    }
    printf(".");
}

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

typedef enum
{
    Nada,
    PorID,
    PorAno
} ModoDeBusqueda;


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

void DatosEnExplorar(Pelicula Datos, unsigned int x)
{
    unsigned short y=2;
    unsigned short i,j;
    char* tiempo = chartiempo(Datos.Duracion);
    gotoxy(x,y++);
    printf("ID: %d",Datos.id);
    gotoxy(x,y++);
    printf("T%ctulo:",161);
    gotoxy(x,y++);
    printf(" %s",Datos.Titulo);
    gotoxy(x,y++);
    printf("A%co: %u",164,Datos.ano);
    gotoxy(x,y++);
    printf("Clasificaci%cn: %s",162,Datos.Clasificacion);
    gotoxy(x,y++);
    printf("Calificaci%cn: %.2f",162,Datos.Calificacion);
    gotoxy(x,y++);
    printf("Duraci%cn: %c%c:%c%c:%c%c",162,*(tiempo),*(tiempo+1),*(tiempo+2),*(tiempo+3),*(tiempo+4),*(tiempo+5));
    free(tiempo);
    gotoxy(x,y++);
    printf("Generos: ");
    for(i=0,j=1;i<9;i++)
    {
        if(Datos.Generos & (1<<8-i))
        {
            if(j>1 || i==6)
            {
                gotoxy(x,y++);
                j=0;
            }
            printf("%s ",Generos[i]);
            j++;
            if(i==6)
            {
                gotoxy(x,y++);
                j=0;
            }
        }
    }
}

void ExplorarPeliculas(Lista *listado, unsigned int num, ModoDeBusqueda modo)
{
    Nodo* Actual;
    int i, j;
    system("cls");
    if(listado->Cabeza==NULL)
    {
        printf("No hay elementos en la lista. Presione ENTER para continuar.");
        while(getch()!=13);
        return;
    }
    if(modo==PorID || modo==PorAno)
    {

    }
    else
    {
        Actual = listado->Cabeza;
    }

    printf("%c",201);
    for(j=0; j<3; j++)
    {
        for(i=0; i<25; i++)
        {
            printf("%c",205);
        }
        if(j==2)
        {
            continue;
        }
        printf("%c",203);
    }
    printf("%c\n",187);

    for(i=2;i<21;i++)
    {
        for(j=1;j<85;j+=25)
        {
            gotoxy(j,i);
            printf("%c",186);
            j++;
        }
    }

    printf("\n%c",200);
    for(j=0; j<3; j++)
    {
        for(i=0; i<25; i++)
        {
            printf("%c",205);
        }
        if(j==2)
        {
            continue;
        }
        printf("%c",202);
    }
    printf("%c",188);

    DatosEnExplorar(Actual->anterior->data,2);
    DatosEnExplorar(Actual->data,28);
    DatosEnExplorar(Actual->siguiente->data,54);

    while(getch()!=13);
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
            ExplorarPeliculas(Peliculas,0,Nada);
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

            if(i==3 || i==6)
            {
                printf(" por a%co.",164);
            }
            else if(i>0 && i<3)
            {
                printf(" dado ID.");
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
    int i,j;
    system("cls");
    printf("\e[?25h");
    Pelicula nuevaPelicula;
    printf("ID: ");
    nuevaPelicula.id = uintinput(9,0);
    //printf("%u",nuevaPelicula.id);
    printf("T%ctulo: ",161);
    nuevaPelicula.Titulo = (char*)malloc(50*sizeof(char));
    fflush(stdin);
    fgets(nuevaPelicula.Titulo,50,stdin);
    fflush(stdin);
    printf("A%co: ",164);
    fflush(stdin);
    nuevaPelicula.ano = uintinput(4,0);
    //printf("%u",nuevaPelicula.ano);
    nuevaPelicula.Clasificacion = SelectClasificacion();

    for(i=5; i<8; i++)
    {
        gotoxy(1,i);
        delline();
    }
    gotoxy(16,4);

    printf("\e[?25h");
    printf("%s\nCalificaci%cn: ",nuevaPelicula.Clasificacion,162);
    fflush(stdin);
    scanf("%f",&nuevaPelicula.Calificacion);
    printf("Duraci%cn: ",162);
    nuevaPelicula.Duracion = inputtiempo(0);
    printf("\n");
    fflush(stdin);
    nuevaPelicula.Generos = selectGeneros(0,8);
    for(i=8; i<17; i++)
    {
        gotoxy(1,i);
        printf("                  ");
        gotoxy(1,i);
        delline();
    }
    gotoxy(9,7);
    printGeneros(nuevaPelicula.Generos);

    nuevaPelicula.Sinopsis = (char*)malloc(200*sizeof(char));
    printf("\e[?25h");
    printf("\nSinopsis: \n");
    scanf("%s", nuevaPelicula.Sinopsis);

    Agregar(listado, nuevaPelicula);
    printf("Presione ENTER para continuar.");
    while(getch()!=13);
}

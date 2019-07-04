#include <stdlib.h>

#ifndef _trespila
#define _trespila

typedef struct
{
    float* elementos;
    int tamano;
    int IndiceUno;
    int StartUno;
    int tamUno;
    int IndiceDos;
    int StartDos;
    int tamDos;
    int IndiceTres;
    int StartTres;
    int tamTres;
} trespila;

trespila* Inicializar();
void Copiar(float* fuente, float* objetivo,int inifuente, int endfuente, int iniobjetivo, int tam);
void VerificarEspacio(trespila*);
void push(trespila*,int,float);
float pop(trespila*,int);


#endif // _trespila

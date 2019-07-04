#include <stdlib.h>
#include "trespila.h"

trespila* Inicializar()
{
    const int TAM = 90;
    trespila* NuevaTriplePila = (trespila*)malloc(sizeof(trespila));
    NuevaTriplePila->elementos = (float*)calloc(TAM,sizeof(float));
    NuevaTriplePila->tamano = TAM;
    NuevaTriplePila->StartUno = 0;
    NuevaTriplePila->IndiceUno = NuevaTriplePila->StartUno;
    NuevaTriplePila->StartDos = TAM/3-1;
    NuevaTriplePila->IndiceDos = NuevaTriplePila->StartDos;
    NuevaTriplePila->StartTres = 2*TAM/3-1;
    NuevaTriplePila->IndiceTres = NuevaTriplePila->StartTres;
    NuevaTriplePila->tamUno = 0;
    NuevaTriplePila->tamDos = 0;
    NuevaTriplePila->tamTres = 0;
    return NuevaTriplePila;
}

void Copiar(float* fuente, float* objetivo,int inifuente, int endfuente, int iniobjetivo, int tamfuente)
{
    int i,j;
    for(i=inifuente,j=iniobjetivo; i!=endfuente; i++,j++)
    {
        if(i==tamfuente)
        {
            i=0;
        }
        *(objetivo+j) = *(fuente+i);
    }
}

void VerificarEspacio(trespila* triplepila)
{
    if(triplepila->IndiceUno != triplepila->StartDos ||
            triplepila->IndiceDos != triplepila->StartTres ||
            triplepila->IndiceTres != triplepila->tamano)
    {
        return;
    }
    triplepila->tamano = triplepila->tamano * 2;
    const int TAM = triplepila->tamano;
    float* nuevaPila = (float*)calloc(TAM,sizeof(float));
    Copiar(triplepila->elementos,nuevaPila,triplepila->StartUno,triplepila->IndiceUno,0,TAM);
    Copiar(triplepila->elementos,nuevaPila,triplepila->StartDos,triplepila->IndiceDos,TAM/3-1,TAM);
    Copiar(triplepila->elementos,nuevaPila,triplepila->StartTres,triplepila->IndiceTres,2*TAM/3-1,TAM);
    triplepila->StartUno = 0;
    triplepila->IndiceUno = triplepila->StartUno + triplepila->tamUno;
    triplepila->StartDos = triplepila->tamano/3-1;
    triplepila->IndiceDos = triplepila->StartDos + triplepila->tamDos;
    triplepila->StartTres = 2*triplepila->tamano/3-1;
    triplepila->IndiceTres = triplepila->StartTres + triplepila->tamTres;
    triplepila->elementos = (float*)realloc(triplepila,TAM*sizeof(float));
    for(int i = 0; i<TAM; i++)
    {
        *(triplepila->elementos+i) = *(nuevaPila+i);
    }
}

void push(trespila* triplepila,int pila,float elemento)
{
    if(pila<1 || pila>3)
    {
        return;
    }
    VerificarEspacio(triplepila);
    int espacioUno, espacioDos, espacioTres, i, temp;
    espacioUno = triplepila->StartDos - triplepila->IndiceUno;
    espacioDos = triplepila->StartTres - triplepila->IndiceDos;
    espacioTres = triplepila->tamano - triplepila->IndiceTres;
    if(pila==1)
    {
        if(espacioUno==0)
        {
            if(espacioDos==0)
            {
                temp = triplepila->StartDos;
                for(i=triplepila->IndiceTres-1; i>=temp; i--)
                {
                    *(triplepila->elementos+i+1)=*(triplepila->elementos+i);
                }
                triplepila->StartTres++;
                triplepila->IndiceTres++;
            }
            else
            {
                temp = triplepila->StartDos;
                for(i=triplepila->IndiceDos-1; i>=temp; i--)
                {
                    *(triplepila->elementos+i+1)=*(triplepila->elementos+i);
                }
            }
            triplepila->StartDos++;
            triplepila->IndiceDos++;
        }
        *(triplepila->elementos+triplepila->IndiceUno)=elemento;
        triplepila->IndiceUno++;
        triplepila->tamUno++;
    }
    else if(pila==2)
    {
        if(espacioDos==0)
        {
            if(espacioUno==0)
            {
                temp = triplepila->StartTres;
                for(i=triplepila->IndiceTres-1; i>=temp; i--)
                {
                    *(triplepila->elementos+i+1)=*(triplepila->elementos+i);
                }
                triplepila->StartTres++;
                triplepila->IndiceTres++;
            }
            else
            {
                temp = triplepila->IndiceDos;
                for(i=triplepila->StartDos; i<temp; i++)
                {
                    *(triplepila->elementos-1+i)=*(triplepila->elementos+i);
                }
                triplepila->IndiceDos--;
                triplepila->StartDos--;
            }
        }
        *(triplepila->elementos+triplepila->IndiceDos)=elemento;
        triplepila->IndiceDos++;
        triplepila->tamDos++;
    }
    else if(pila==3)
    {
        if(espacioTres==0)
        {
            if(espacioUno==0)
            {
                temp = triplepila->IndiceTres;
                for(i=triplepila->StartTres; i<temp; i++)
                {
                    *(triplepila->elementos-1+i)=*(triplepila->elementos+i);
                }

            }
            else
            {
                temp = triplepila->IndiceTres;
                for(i=triplepila->StartDos; i<temp; i++)
                {
                    *(triplepila->elementos-1+i)=*(triplepila->elementos+i);
                }
                triplepila->IndiceDos--;
                triplepila->StartDos--;
            }
            triplepila->IndiceTres--;
            triplepila->StartTres--;
        }
        *(triplepila->elementos+triplepila->IndiceTres)=elemento;
        triplepila->IndiceTres++;
        triplepila->tamTres++;
    }
}

float pop(trespila* triplepila,int pila)
{
    if(pila<1 || pila>3)
    {
        return 0;
    }
    float dato=0;
    if(pila==1 && triplepila->tamUno>0)
    {
        dato=*(triplepila->elementos+triplepila->IndiceUno);
        triplepila->tamUno--;
        triplepila->IndiceUno--;
    }
    else if(pila==2 && triplepila->tamDos>0)
    {
        dato=*(triplepila->elementos+triplepila->IndiceDos);
        triplepila->tamDos--;
        triplepila->IndiceDos--;
    }
    else if(pila==3 && triplepila->tamTres>0)
    {
        dato=*(triplepila->elementos+triplepila->IndiceTres);
        triplepila->tamTres--;
        triplepila->IndiceTres--;
    }
    return dato;
}

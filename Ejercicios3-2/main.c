#include <stdio.h>
#include <stdlib.h>
#include "ColaDinamica.h"
//20170945
int main()
{
    Cola* miCola = Inicializar();
    float nuevoValor;
    do
    {
        printf("Digite un valor (-1 para quitar y 0 para terminar): ");
        scanf("%f", &nuevoValor);
        if(nuevoValor>0)
        {
            push(miCola, nuevoValor);
        }
        else if(nuevoValor<0)
        {
            if(miCola->Tamano == 0)
            {
                continue;
            }
            nuevoValor = pop(miCola);
            printf("Quitado: %f\n",nuevoValor);
        }
    }
    while(nuevoValor!=0);

    printf("Elementos sobrantes en la lista:\n");
    while(!isEmpty(miCola))
    {
        nuevoValor = pop(miCola);
        printf("%f\n",nuevoValor);
    }
    return 0;
}

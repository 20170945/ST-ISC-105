#include <stdio.h>
#include <stdlib.h>

void MostrarValores(int arreglo[],int n)
{
    int i;
    printf("Valores: ");
    for(i=0; i<n; i++)
    {
        printf("%d ",arreglo[i]);
    }
}

int BusquedaLinealRecursiva(int arreglo[],int n,int valor, int pos)
{
    if(pos >= n)
    {
        return -1;
    }

    return arreglo[pos] == valor ? pos : BusquedaLinealRecursiva(arreglo,n,valor,pos+1);
}

int BusquedaLineal(int arreglo[], int n, int valor)
{
    return BusquedaLinealRecursiva(arreglo,n,valor,0);
}

int BusquedaBinariaRecursiva(int arreglo[], int valor, int inf, int sup)
{
    int centro = inf+((sup-inf)/2);
    if(arreglo[centro]==valor)
    {
        return centro;
    }
    else if(sup-inf==1)
    {
        return -1;
    }
    else if(arreglo[centro]>valor)
    {
        return BusquedaBinariaRecursiva(arreglo, valor, inf, centro);
    }
    else
    {
        return BusquedaBinariaRecursiva(arreglo, valor, centro+1,sup);
    }
}

int BusquedaBinaria(int arreglo[], int n, int valor)
{
    return BusquedaBinariaRecursiva(arreglo,valor,0,n);
}

void CapturarValores(int[],int);
long GenerarValoresRecursivo(int[],int,int,int,int);
void GenerarValores(int[], int);
void MergeSort(int[],int);
void MergeSortRecursivo(int[],int,int);
void QuickSort(int[],int);
void QuickSortRecursivo(int[],int,int);

int main()
{
    srand(time(NULL));
    int n;
    int k;
    int p;
    printf("Digite el tama%co del arreglo: ",164);
    scanf("%d", &n);
    int arreglo[n];

    //CapturarValores(arreglo,n);
    GenerarValores(arreglo,n);
    MostrarValores(arreglo,n);

    printf("\nSort:\n");
    //MergeSort(arreglo,n);
    QuickSort(arreglo,n);
    MostrarValores(arreglo,n);

    printf("\nN%cmero a buscar: ",163);
    scanf("%d",&k);
    p = BusquedaLineal(arreglo,n,k);
    printf("Busqueda Lineal: ");
    if(p!=-1)
    {
        printf("%d",arreglo[p]);
    }
    p = BusquedaBinaria(arreglo,n,k);
    printf("\nBusqueda Binaria: ");
    if(p!=-1)
    {
        printf("%d\n",arreglo[p]);
    }
    return 0;
}

CapturarValores(int arreglo[],int n)
{
    int i;
    printf("Capturar: ");
    for(i=0; i<n; i++)
    {
        scanf("%d", &arreglo[i]);
    }
}

long GenerarValoresRecursivo(int arreglo[],int n,int p,int inf,int sup)
{
    if(p >= n)
    {
        return 0;
    }

    arreglo[p]=rand() % (sup-inf) + inf;

    return arreglo[p] + GenerarValoresRecursivo(arreglo,n,p+1,inf,sup);
}

void GenerarValores(int arreglo[], int n)
{
    long sumatoria = GenerarValoresRecursivo(arreglo, n, 0,1,100);
    printf("La sumatoria de los aleatorios es: %ld\n", sumatoria);
}

void MergeSortRecursivo(int arreglo[], int inf, int sup)
{
    int tamano = sup-inf;
    if(tamano==1)
    {
        return;
    }
    int i,j,k;
    int centro = inf+(tamano/2);
    MergeSortRecursivo(arreglo,inf,centro);
    MergeSortRecursivo(arreglo,centro,sup);
    int valores[tamano];
    for(i=0,j=inf,k=centro; i<tamano; i++)
    {
        if(j<centro)
        {
            if((arreglo[j]<arreglo[k] && k<sup) || k>=sup)
            {
                valores[i]=arreglo[j];
                j++;
                continue;
            }
        }
        valores[i]=arreglo[k];
        k++;
    }
    for(i=0; i<tamano; i++)
    {
        arreglo[inf+i]=valores[i];
    }
}

void MergeSort(int arreglo[],int n)
{
    MergeSortRecursivo(arreglo,0,n);
}

void QuickSortRecursivo(int arreglo[],int inf,int sup)
{
    if(sup-inf<=1)
    {
        return;
    }
    int pivote = sup-1;
    int i,j,temp;
    for(i=inf,j=inf; i<pivote; i++)
    {
        if(arreglo[i]<arreglo[pivote] && i>j)
        {
            temp=arreglo[i];
            arreglo[i]=arreglo[j];
            arreglo[j]=temp;
        }
        while(arreglo[j]<arreglo[pivote])
        {
            j++;
        }
        if(i<=j)
        {
            i=j+1;
        }
    }
    temp=arreglo[j];
    arreglo[j]=arreglo[pivote];
    arreglo[pivote]=temp;
    QuickSortRecursivo(arreglo,inf,j);
    QuickSortRecursivo(arreglo,j+1,sup);
}

void QuickSort(int arreglo[],int n)
{
    return QuickSortRecursivo(arreglo,0,n);
}

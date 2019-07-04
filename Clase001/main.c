#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, cant=0;
    float sum=0;
    while(1)
    {
        scanf("%d",&num);
        if(num!=99999)
        {
            sum+=num;
            cant++;
        }
        else
        {
            break;
        }
    }
    printf("%.2f",sum/cant);
    return 0;
}

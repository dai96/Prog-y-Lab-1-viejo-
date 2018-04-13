#include <stdio.h>
#include <stdlib.h>


void pideEntero(void);
{
    int edad;
    int listaEdades[5];
    int i;

    for (i=0;i<5;i++)
    {
        printf("\n ingrese el numero",i);
        scanf("%d",&listaEdades[i]);
    }
    for (i=0;i<5;i++)
    {
        printf("\n %d : %d", i, listaEdades [i] );
    }

}

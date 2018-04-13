
#include <stdio.h>
#include <stdlib.h>
#include "funcionesvectres.h"

void ejemploCargaSecuencial (void)
{
    int edad;
    float precio;
    int listaEdades[5];
    float listaPrecios[5];
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


#include <stdio.h>
#include <stdlib.h>



int main()
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


    for (i=0;i<5;i++)

    {
        printf("\n ingrese el numero",i);
        scanf("%f",&listaPrecios[i]);
    }



    for (i=0;i<5;i++)

    {
        printf("\n %d : %f", i, listaPrecios [i] );
    }

    //edad=66;

    //printf("%d\n", edad);
    //printf("%d\n", &edad);

    //printf("\ndireccion de memoria %d",&listaEdades);
    //printf("\ndirecion de memoria %d",listaEdades);
    //printf("\nprimer vector %d", listaEdades[0]);
    //printf("\nmemoria del primer vector %d", &listaEdades[0]);
    //printf("\ncuarto vertor %d", listaEdades[4]);
    //printf("\nbasura %d", listaEdades[5]);



    return 0;
}

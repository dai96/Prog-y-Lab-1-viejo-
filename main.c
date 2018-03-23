#include <stdio.h>
#include <stdlib.h>

int main()
{
   /*int n;
   char l;


    printf("Ingrese un numero: ");
    scanf("%d", &n);

    printf("Ingrese un caracter: ");
    fflush(stdin);
    scanf("%c", &l);


    printf ("%d--%c", n, l);*/


    //Se ingresan numeros (ser distintos de 0)no se saben cuantos.
    //se pide mostrar:
        //*cantidad de pares e impares
        //*porcentaje de nuemros positivips y negativos
        //*maximo y minimo
        //*maximo numero par
        //*cantidad de sdfsdnumeros comprendidos entre 125 y 236


        int numero;
        char respuesta='s';
        int pares=0;
        int impares=0;
        int interacciones=0;
        int guardaPosis=0;
        float finalposis;
        int guardaNegas=0;
        float finalnegas;
        int flag;
        int min;
        int max;



        while (respuesta!='n')
        {
            interacciones++;
            printf("\nIngrese un numero: ");
            scanf("%d", &numero);
            while (numero==0)
                {
                    printf("\n reingrese un numero: ");
                    scanf("%d", &numero);
                }
            printf("\nSi quiere salir ingrese n ");
           respuesta=getche();

           if (numero%2==0)
           {
               pares++;
           }
           if (!(numero%2==0))
           {
               impares++;
           }

            if (numero>0)
            {
                guardaPosis++;
            }
            else
            {
                guardaNegas++;
            }

            /*if (flag==0)
            {
                max=numero;
                min=numero;
                flag=1;
            }
            else
            {
                    if (numero<min)
                    {
                        min=numero;
                    }
                    if (numero>max)
                    {
                        max=numero;

                    }
            }*/
            if (flag==0 || numero > max)
            {

                max=numero;
            }
            if (flag==0 || numero > min)
            {
                min=numero;
                flag=1;
            }

        }
        finalposis=(float)(guardaPosis*100)/interacciones;
        finalnegas=(float)(guardaNegas*100)/interacciones;//100-finalposis;

        printf("\nLa cantidad de pares es %d ", pares);
        printf("\nLa cantidad de impares %d ", impares);
        printf("\nponcentaje de posis es %f ", finalposis);
        printf("\nporcentaje de negas es %f", finalnegas);
        printf("\nel maximo es %d ", max);
        printf("\nel minimo es %d ", min);



















    return 0;
}

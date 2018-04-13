#include <stdio.h>
#include <stdlib.h>

int contarPares(int [],int);
int buscarChar (char[], int, char);

int main()
{
    int vector [5]={5,2,9,6,5};
   char letras [5]={'f', 'g', 's', 'm', 'q'};
    int indexletra;
    int cantidad;
    cantidad=contarpares(vector, 5);
    indexletra=buscarChar(letras, 5, 'a');
    if(indexletra==-1)
    {
        printf("No se encuetra el caracter");

    }
    else
        {
            printf("El caracter se encuenta en el array");
        }


    printf ("\nCantidad de pares: %d", cantidad);
}

int contarpares (int array[], int cantidad)
{
    int contPares=0;
    int i;
    for (i=0; i<=cantidad; i++)
    {
        if (array [i]%2==0)
        {
            contPares++;
        }
    }
    return contPares;*
}



int buscarChar(char array[],int cantidad,char caracter)
{
    int index=-1;
    int i;
    for (i=0; i<cantidad; i++)
    {
        if(array[i]==caracter)
        {
            index=i;
            break;
        }
    }
    return index;
}

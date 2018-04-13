#include <stdio.h>
#include <stdlib.h>

float dividir (float numeroUno , float numeroDos);
int main()
    {
    float numero;
    numero=dividir(124,3);
    printf ("%f" ,numero);
    return 0;


    }
float dividir (float numeroUno, float numeroDos)
    {
    float resultado=0;

    resultado=(float) numeroUno/numeroDos;

    return resultado;
    }

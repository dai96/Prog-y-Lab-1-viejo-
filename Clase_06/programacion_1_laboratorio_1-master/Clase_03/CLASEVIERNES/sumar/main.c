#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
void sumarUno(void);



int main()
{
    sumarUno ();
    return 0;
}

void sumarUno (void)
{
    int numeroUno;

    int numeroDos;

    int suma;

   numeroUno= pedirEntero("Ingrese un numero" , 1, 1000);
   numeroDos= pedirEntero("Ingrese otro numero", 1 ,1000);

   suma = numeroUno+ numeroDos;

    printf("La suma es: %d", suma);




}

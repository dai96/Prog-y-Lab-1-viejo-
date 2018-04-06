#include <stdio.h>
#include <stdlib.h>
/** \brief calcula el factorial de los numeros
 *
 * \param un numero
 * \param
 * \return
 *
 */
int factorial(int numero);

int main()
{
    int numero = 5;
    int factor;
    factor= factorial (numero);




    //for (1=numero; 1>=1; i--)
    //for (1=numero; 1>=1; i--)
    //{

      //  factor = factor*1;
    //}

    printf ("El factorial es: %d", factor);
 // tambien asi  for (1=1; 1<=5; 1++)



}


int factorial (int numero)
{
    int respuesta;
    if (numero == 0)
    {
        respuesta = 1;

    }
    else
    {
        respuesta= numero * factorial (numero-1);
    }

    return respuesta;
}

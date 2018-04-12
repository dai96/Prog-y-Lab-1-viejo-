#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/** \brief suma dos datos
*
* \param float operandoUno
* \param float operandoDos
* \return resultado de operacion
*
*/

void sumar(float operandoUno, float operandoDos)
{
    float resultadoSumar;
    resultadoSumar=operandoUno+operandoDos;
    printf("Su suma dio %f ", resultadoSumar);

}
/** \brief resta dos datos
*
* \param float operandoUno
* \param float operandoDos
* \return resultado de operacion
*
*/
void restar (float operandoUno, float operandoDos)
{
    float resultadoRestar;
    resultadoRestar=operandoUno-operandoDos;
    printf("Su resta dio %f ", resultadoRestar);
}
/** \brief divide dos datos
*
* \param float operandoUno
* \param float operandoDos
* \return resultado de operacion
*
*/
void dividir(float operandoUno, float operandoDos)
{
    float resultadoDividir;
    resultadoDividir=operandoUno/operandoDos;
    printf("Su division dio %f ", resultadoDividir);
}
/** \brief multiplica dos datos
*
* \param float operandoUno
* \param float operandoDos
* \return resultado de operacion
*
*/
void multiplicar (float operandoUno, float operandoDos)
{
    float resultadoMultiplicar;
    resultadoMultiplicar=operandoUno*operandoDos;
    printf("Su multiplicacion dio %f ", resultadoMultiplicar);
}
/** \brief saca el factorial de un numero
*
* \param float operandoUno
*
* \return resultado de operacion
*
*/
void factorial(float operandoUno)
{
     int i=1;

     int fact=1;

     while (i<=operandoUno)
     {

         fact=fact*i;
         i++;
     }

     printf ("El factorial da %d", fact);

     return 0;



}

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


float operandoUno=1;
float operandoDos=1;

int main()
{
    char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {

        printf("1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);
        fflush(stdin);

        switch(opcion)
        {
            case 1:
                printf("Ingrese 1er operando ");
                scanf("%f",&operandoUno);
                fflush(stdin);
                printf(" el valor es %f \n", operandoUno);
                break;
            case 2:
                printf("Ingrese 2do operando ");
                scanf("%f",&operandoDos);
                fflush(stdin);
                printf(" el valor es %f \n", operandoDos);
                break;
            case 3:
                sumar(operandoUno,operandoDos);

                break;
            case 4:
                restar(operandoUno, operandoDos);

                break;
            case 5:
                dividir(operandoUno, operandoDos);
                break;
            case 6:
                multiplicar(operandoUno, operandoDos);
                break;
            case 7:
                factorial(operandoUno);
                break;
            case 8:
                sumar(operandoUno,operandoDos);
                restar(operandoUno,operandoDos);
                dividir(operandoUno,operandoDos);
                multiplicar(operandoUno,operandoDos);
                factorial(operandoUno);

                break;
            case 9:
                seguir = 'n';
                break;
        }

    }
    return 0;

}

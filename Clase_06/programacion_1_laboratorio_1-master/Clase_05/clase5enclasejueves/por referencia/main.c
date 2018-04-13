#include <stdio.h>
#include <stdlib.h>
#define cantidad 5

void cambiarEntero(int numero);
void cambiarVector(int listadoDeNumeros[]);
void cagarVectorConMenosUno (int listado[]);




int main()
{
    int edad=22;
    int edades[3];
    cambiarEntero(edad);
    printf("La edad es %d ",edad );
    cambiarVector(edades);
    printf("La edad es %d ", edades[0]);//si me dice que no defini la array es xq no puse [] co nmuero adentro
    cargarVectorConMenosUno(edades);


}

void cambiarEntero(int numero)
{
    numero=666;
}

void cambiarVector(int listadoDeNumeros[])
{
    listadoDeNumeros[0]=666;
}

void cagarVectorConMenosUno (int listado[])
{
    int i;
    int tamanioArray=sizeof listado;
    printf("El tamanio de la array es %d",tamanioArray);
    for (i=0;i<tamanioArray;i++)
    {
    listado [i]=-1;
    }
}

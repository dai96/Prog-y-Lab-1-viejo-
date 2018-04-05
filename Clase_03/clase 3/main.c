#include <stdio.h>
#include <stdlib.h>
//(1) prototipo y firma

void saludar (void);
//(2) invocar a la funcion
int main ()
{
    printf("hola mundo");
    saludar ();
    return 0;
}
//(3) definir la funcionalidad
void saludar (void)
{
    printf("hola mundo");
}

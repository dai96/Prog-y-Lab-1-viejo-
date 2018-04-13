#include <stdio.h>
#include <stdlib.h>

int main()
{
    char palabraUno[15];//="hola";//soloacà
    char palabraDos[15];
    char buffer[1024];
    int i;
    int cant;
    int comp;

    printf("ingrese una palabra: ");
    fflush(stdin);
    gets(buffer);

    while (strlen(buffer)>14)
    {
        printf("Reingrese una palabra: ");
        fflush(stdin);
        gets(buffer);

    }
    //scanf("%s", palabra);//&palabra tmb,scanf toma espacio como barra 0

    //cant= strlen(buffer);//validadr queno ponga cantidad de caracteres superior

    //strcpy(palabraUno, buffer);//destino, origen

    //strcpy(palabraDos, palabraUno);

    strupr(palabraUno);
    strwr(palabraDos);

    strcat



    comp=strcmp(palabraUno, palabraDos);//compara, devuelve 0 si es igual, 1 si es C -1 si es A mi letra es B

    printf("resultado de la comparacion: %d", comp);


    //palabra="hola" no se puede hacer
    printf("la cantidad de caracteres de la palabraUno es: %d\n", cant);
    printf("palabraUno: %s \npalabraDos: %s",palabraUno, palabraDos);
    return 0;
}

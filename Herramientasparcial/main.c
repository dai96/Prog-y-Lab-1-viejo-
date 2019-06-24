#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#include "Controller.h"
#include "stuct.h"
#include "funciones.h"
#include "parserr.h"
int main()
{
    int opcion;

    //inicializo ll con new ll.
    LinkedList* alumnos =ll_newLinkedList();
    do
    {
        opcion=menuDeOpciones("1-Cargar txt \n2-mostrar listado \n3-ordenar listado \n4-calcular nota final\n5-guardar datos \n6-Agregar alumno \n7-borrar \n8-Cargar bin \n9-Guardar en bin \n\n10-salir \n\n");
        switch(opcion)
        {
        case 1:
            controller_loadFromText("data.csv",alumnos);
            break;
        case 2:
            controller_ListAlumno(alumnos);
            break;
        case 3:
            controller_sortAlumno(alumnos);
            break;
        case 4:
            controller_notaFinal(alumnos);
            break;
        case 5:
            controller_saveAsText("data.csv",alumnos);
            break;
        case 6:
            controller_addAlumno(alumnos);
            break;
        case 7:
            controller_removeAlumno(alumnos);
            break;
        case 8:
            controller_loadFromBinary("data.bin",alumnos);
            break;
        case 9:
            controller_saveAsBinary("data.bin",alumnos);
            break;
        default:
            if (opcion!=10)
            {
                printf("Error, elija una opcion del 1 al 10");
            }
            break;
        }
        system("pause");
        system("cls");
    }
    while(opcion!=10);

    return 1;

}

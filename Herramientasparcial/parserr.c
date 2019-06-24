#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"
#include "stuct.h"
#include "parserr.h"


int parser_AlumnoFromText(FILE* pFile, LinkedList* pArrayListAlumno)
{
    Alumno* this;
    char auxId[20],auxNombre[20],auxNota1[20],auxNota2[20],auxFin[20];
    int r;

    if(pFile!=NULL && pArrayListAlumno!=NULL)
    {

        fscanf(pFile,"%[^,] , %[^,] , %[^,] , %[^,] , %[^\n]",auxId,auxNombre,auxNota1,auxNota2,auxFin);

        do
        {
            r=fscanf(pFile,"%[^,] , %[^,] , %[^,] , %[^,] , %[^\n]",auxId,auxNombre,auxNota1,auxNota2,auxFin);
            this=Alumno_newParametros(auxId,auxNombre,auxNota1,auxNota2,auxFin);
            if(this!=NULL && r==5)
            {
                ll_add(pArrayListAlumno,this);
            }

        }
        while(!feof(pFile));

        printf("\nCarga exitosa\n\n");
    }
    else
    {
        printf("\nEl archivo no existe\n\n");
    }

    return 1;
}

int parser_AlumnoFromBinary(FILE* pFile, LinkedList* pArrayListAlumno)
{
    Alumno* this;
    int leidos;
    while(!feof(pFile))
    {
        this = Alumno_new();
        leidos =fread(this, sizeof(Alumno), 1, pFile);
        if(leidos == 1 && this != NULL)
        {
            ll_add(pArrayListAlumno, this);
        }
        else if(leidos != 1)
        {
            if(!feof(pFile))
            {
                printf("\nError al leer el ultimo dato");
                break;
            }
            else
            {
                printf("\nCarga exitosa\n\n");
            }
        }
    }
    fclose(pFile);
    return 1;

}

#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#include "stuct.h"
#include "parserr.h"



int controller_loadFromText(char* path, LinkedList* pArrayListAlumno)
{
    FILE* pFile;
    int retorno=-1;

    pFile=fopen(path,"r");

    if(pFile!=NULL && pArrayListAlumno!=NULL)
    {
        retorno=1;
        parser_AlumnoFromText(pFile,pArrayListAlumno);
    }

    fclose(pFile);

    return retorno;
}

int controller_loadFromBinary(char* path, LinkedList* pArrayListAlumno)
{
    int retorno = -1;
    FILE* pArchivo;
    if (pArrayListAlumno!=NULL)
    {
        pArchivo = fopen(path, "rb");
        if (pArchivo != NULL)
        {
            parser_AlumnoFromBinary(pArchivo,pArrayListAlumno);
            retorno = 1;
        }
        fclose(pArchivo);
        return retorno;
    }


}

int controller_addAlumno(LinkedList* pArrayListAlumno)
{
    Alumno* this;
    char id[20],nombre[20],nota1[20],nota2[20],x[20];
    int retorno=-1,auxId;

    if (this!=NULL && pArrayListAlumno!=NULL)
    {
        retorno=1;
        auxId=returnID(pArrayListAlumno);
        itoa(auxId,id,10);
        getNombres("nombre",nombre,10);
        getNumeros("primera nota",nota1,4);
        getNumeros("segunda nota",nota2,8);
        this=Alumno_newParametros(id,nombre,nota1,nota2,"0");
        ll_add(pArrayListAlumno,this);

    }
    return retorno;
}


int controller_editAlumno(LinkedList* pArrayListAlumno)
{
    Alumno* this;
    int retorno=-1,horas,sueldo,i,len,returnedId;
    char nombre[20];
    int auxId;

    if (pArrayListAlumno!=NULL && this!=NULL)
    {
        len=ll_len(pArrayListAlumno);
        auxId=getInt("numero de id");

        for (i=0; i<len; i++)
        {
            this=ll_get(pArrayListAlumno,i);
            Alumno_getId(this,&returnedId);

            if (auxId==returnedId)
            {
                retorno=1;
                getNombres("nombre",nombre,20);
                strcpy(this->nombre,nombre);

                horas=getInt("horas trabajadas");
//                this->horasTrabajadas=horas;

                sueldo=getInt("sueldo");
                //              this->sueldo=sueldo;

                printf("Modificacion realizada\n");
                break;

            }

        }
    }

    return retorno;
}

int controller_removeAlumno(LinkedList* pArrayListAlumno)
{
    Alumno* this;
    int retorno=-1,auxId,i,len,returnedId;
    char opcion;

    len=ll_len(pArrayListAlumno);
    auxId=getInt("numero de id");

    if (pArrayListAlumno!=NULL && this!=NULL)
    {
        for (i=0; i<len; i++)
        {
            this=ll_get(pArrayListAlumno,i);
            Alumno_getId(this,&returnedId);

            if (auxId==returnedId)
            {
                printf("Esta seguro que desea borrar el siguiente dato?");
                printf("\n\n  ID \t\t   Nombre \t\t  nota1 \t\t  nota2 \t\t  notaFinal \n\n");
                printf("%4d  %20s %20d %20d %20d\n",this->id,this->nombre,this->nota1,this->nota2,this->notaFinal);
                opcion=son();
                if (opcion=='S')
                {
                    ll_remove(pArrayListAlumno,i);
                    Alumno_delete(this);
                    printf("Dato borrado\n");
                    break;
                }
                else
                {
                    printf("Dato no borrado\n");
                }
            }

        }

    }


    return retorno;
}

int controller_ListAlumno(LinkedList* pArrayListAlumno)
{
    int retorno=-1,i,auxId,auxNota1,auxNota2,auxF,len;
    char auxNombre[20];

    Alumno* this;

    if(pArrayListAlumno!=NULL && this!=NULL)
    {
        retorno=1;
        len=ll_len(pArrayListAlumno);
        printf("\n\n  ID \t\t   Nombre \t\t  nota 1 \t\t  nota2 \t\t  nota final \n\n");

        for(i=0; i<len; i++)
        {
            this=ll_get(pArrayListAlumno,i);

            Alumno_getId(this,&auxId);
            Alumno_getNombre(this,auxNombre);
            Alumno_getnota1(this,&auxNota1);
            Alumno_getnora2(this,&auxNota2);
            Alumno_getnotaF(this,&auxF);

            printf("%4d  %20s %20d %20d  %20d \n",auxId,auxNombre,auxNota1,auxNota2,auxF);
        }
    }

    return retorno;

}

int ordenarId (void* AlumnoUno, void* AlumnoDos)
{
    int retorno=-2;
    Alumno* empleadoUno;
    Alumno* empleadoDos;

    if(AlumnoUno!=NULL && AlumnoDos!=NULL)
    {
        empleadoUno=(Alumno*)AlumnoUno;
        empleadoDos=(Alumno*)AlumnoDos;
        if((empleadoUno->id) < (empleadoDos->id))
        {
            retorno=1 ;
        }
        else if((empleadoUno->id) == (empleadoDos->id))
        {
            retorno=0;
        }
        else if((empleadoUno->id) > (empleadoDos->id))
        {
            retorno=-1 ;
        }
    }

    return retorno;
}

int ordenarNombre (void* AlumnoUno, void* AlumnoDos)
{
    int retorno = -2;

    Alumno* empleadoUno;
    Alumno* empleadoDos;

    if(AlumnoUno!=NULL && AlumnoDos!=NULL)
    {
        empleadoUno=(Alumno*)AlumnoUno;
        empleadoDos=(Alumno*)AlumnoDos;
        retorno=stricmp(empleadoUno->nombre,empleadoDos->nombre);
    }

    return retorno;
}

int controller_sortAlumno(LinkedList* pArrayListAlumno)
{
    int retorno=-1,opcion;

    if(pArrayListAlumno!=NULL)
    {
        printf("\n1-ID ascendente\n2-ID descendente\n3-Nombre ascendente\n4-Nombre descendente\n");
        opcion=getInt("opcion");
        switch(opcion)
        {
        case 1:
            ll_sort(pArrayListAlumno,ordenarId, 0);
            controller_ListAlumno(pArrayListAlumno);
            break;
        case 2:
            ll_sort(pArrayListAlumno,ordenarId, 1);
            controller_ListAlumno(pArrayListAlumno);
            break;
        case 3:
            ll_sort(pArrayListAlumno,ordenarNombre, 0);
            controller_ListAlumno(pArrayListAlumno);
            break;
        case 4:
            ll_sort(pArrayListAlumno,ordenarNombre, 1);
            controller_ListAlumno(pArrayListAlumno);
            break;
        default:
            printf("Error, selecione un numero del 1 al 4");
            break;
        }
        retorno =1;
    }

    return retorno;
}


int controller_saveAsText(char* path, LinkedList* pArrayListAlumno)
{

    FILE* pFile;
    Alumno* this;

    int retorno=-1,i,auxId,auxNota1,auxNota2,auxF,len;
    char auxNombre[20];

    if(pArrayListAlumno!=NULL && path!=NULL)
    {
        retorno=1;
        len=ll_len(pArrayListAlumno);
        pFile=fopen(path,"w");
        fprintf(pFile,"id,nombre,nota1,nota2,notaFinal\n");

        for(i=0; i<len; i++)
        {
            this=(Alumno*)ll_get(pArrayListAlumno,i);

            Alumno_getId(this,&auxId);
            Alumno_getNombre(this,auxNombre);
            Alumno_getnota1(this,&auxNota1);
            Alumno_getnora2(this,&auxNota2);
            Alumno_getnotaF(this,&auxF);

            fprintf(pFile,"%d,%s,%d,%d,%d\n",auxId,auxNombre,auxNota1,auxNota2,auxF);
            //printf("\n\n\n%d,%s,%d,%d,%d\n",auxId,auxNombre,auxNota1,auxNota2,auxF); COMPROBACION
        }
        printf("Exito al guardar\n");
        fclose(pFile);
    }
    return retorno;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListAlumno)
{
    int retorno = 0;
    int len= ll_len(pArrayListAlumno);
    Alumno* pA;
    FILE* fp = fopen(path, "wb");
    int i;
    if(fp==NULL)
    {
        printf("Error al guardar\n");
        return retorno;
    }
    if(pArrayListAlumno!=NULL)
    {
        for(i = 0; i < len; i++)
        {
            pA = (Alumno*)ll_get(pArrayListAlumno, i);
            fwrite(pA, sizeof(Alumno), 1, fp);
        }
        printf("Exito al guardar\n");
        retorno = 1;
    }
    fclose(fp);
    return retorno;
}


int controller_notaFinal(LinkedList* this)
{
    Alumno* pAlumno;
    int aux1,aux2,calculo,i;

    for (i=0; i<ll_len(this); i++)
    {
        pAlumno=ll_get(this,i);
        aux1=pAlumno->nota1;
        aux2=pAlumno->nota2;
        calculo=aux1+aux2;
        calculo=calculo/2;
        //printf("el calculo dio %d",calculo);COMPROBACION
        Alumno_setnotaF(pAlumno,calculo);
    }
}


int returnID (LinkedList* alumnos)
{
    Alumno* pAlumno;
    int i,aux,len,max=-1;

    len=ll_len(alumnos);

    for (i=0; i<len; i++)
    {
        pAlumno=ll_get(alumnos,i);
        aux=pAlumno->id;
        if (aux>max)
        {
            max=aux;
        }
    }
    max++;

    return max;
}


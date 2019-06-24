#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"
#include "stuct.h"

Alumno* Alumno_new()
{
    Alumno* pAlumno;

    pAlumno=(Alumno*)malloc(sizeof(Alumno));

    if(pAlumno!=NULL)
    {
        return pAlumno;
    }
}

Alumno* Alumno_newParametros(char* idStr,char* nombreStr,char* nota1str,char* nota2str,char* notafin)
{
    Alumno* pAlumno;
    int auxId,auxnota1,auxnora2,auxnotaF,auxNombre;
    pAlumno=Alumno_new();

    if(pAlumno!=NULL)
    {
        auxId=atoi(idStr);
        auxnota1=atoi(nota1str);
        auxnora2=atoi(nota2str);
        auxnotaF=atoi(notafin);
        Alumno_setId(pAlumno,auxId);
        Alumno_setNombre(pAlumno,nombreStr);
        Alumno_setnota1(pAlumno,auxnota1);
        Alumno_setnora2(pAlumno,auxnora2);
        Alumno_setnotaF(pAlumno,auxnotaF);

        return pAlumno;
    }
}
void Alumno_delete(Alumno* this)
{
    free(this);
}

int Alumno_setId(Alumno* this,int id)
{
    if (this!=NULL)
    {
        this->id=id;
    }
    return 1;
}
int Alumno_getId(Alumno* this,int* id)
{
    if (this!=NULL)
    {
        *id=this->id;
    }
    return 1;
}
int Alumno_setNombre(Alumno* this,char* nombre)
{
    if (this!=NULL)
    {
        strcpy(this->nombre,nombre);
    }

    return 1;
}

int Alumno_getNombre(Alumno* this,char* nombre)
{
    if (this!=NULL)
    {
        strcpy(nombre,this->nombre);
    }

    return 1;
}

int Alumno_setnota1(Alumno* this,int nota1)//set para poner
{
    if (this!=NULL)
    {
        this->nota1=nota1;
    }

    return 1;
}
int Alumno_getnota1(Alumno* this,int* nota1)//get para guardar
{
    if (this!=NULL)
    {
        *nota1=this->nota1;
    }
    return 1;
}
int Alumno_setnora2(Alumno* this,int nora2)
{
    if (this!=NULL)
    {
        this->nota2=nora2;
    }
    return 1;
}
int Alumno_getnora2(Alumno* this,int* nora2)
{
    if (this!=NULL)
    {
        *nora2=this->nota2;
    }
    return 1;
}
int Alumno_setnotaF(Alumno* this,int notaF)
{
    if (this!=NULL)
    {
        this->notaFinal=notaF;
    }
    return 1;
}
int Alumno_getnotaF(Alumno* this,int* notaF)
{
    if (this!=NULL)
    {
        *notaF=this->notaFinal;
    }
    return 1;
}
